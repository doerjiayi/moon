#include "StdAfx.h"

enum EVIEW_STATE
{
	VIEW_STATE_LEAVE			=	0,
	VIEW_STATE_STAY				=	1,
	VIEW_STATE_ENTER			=	2,
};

CDoer::CDoer()
	:super()
{
	m_btType = eNormalMonster;
	m_dwNextUpdateViewTime = 0;
	m_nViewArea = 1900 / 128 + 2;
	m_pFirstMsg = m_pLastMsg = NULL;
	m_nLevel = 0;
	m_btVipLevel = 0;
	m_btAttackType = apOuter;
	m_wMonId = 0;
	m_nExp = m_nExpMax = 0;
	m_nMonExp = 0;
	m_wMoveSpeed = 500;
	m_wAttackTime = 300;
	m_wAttackInterval = 1000;
	m_dwLastRunTick = 0;
	m_nBornX = -1;
	m_nBornY = -1;
}

CDoer::~CDoer()
{
	while(m_pFirstMsg)
	{
		DoerMsg *nextMsg = m_pFirstMsg->next;
		CGlobalLogicObjAlloc::freeDoerMsg(m_pFirstMsg);
		m_pFirstMsg = nextMsg;
	}
	m_pLastMsg = NULL;
}

void CDoer::run(TickTime dwCurrTick)
{
	//处理消息列表
	if (m_pFirstMsg)
	{
		do
		{
			DoerMsg *currMsg = m_pFirstMsg;
			m_pFirstMsg = currMsg->next;
			if (currMsg->sysId != 0)
			{
				CDoerUnit *module = getModule(currMsg->sysId);
				if (module)
					module->dispatchMsg(currMsg);
			}
			else dispatchMsg(currMsg);
			CGlobalLogicObjAlloc::freeDoerMsg(currMsg);
			if (!m_pFirstMsg)
			{
				m_pLastMsg = NULL;
				break;
			}
		}
		while(true);
	}
	//更新可视列表
	if (dwCurrTick > m_dwNextUpdateViewTime)
	{
		updateViewList();
	}
	//更新战斗系统
	m_Battle.run(dwCurrTick);
	super::run(dwCurrTick);
}

bool CDoer::initialize()
{
#define ____init_module(m, n) if (m.init())\
	{ m.m_pActor = this; }\
	else { logError("初始化角色%s模块失败！", n); return false; }

	____init_module(m_Abil, "属性");
	____init_module(m_Battle, "战场");

	return true;
}

void CDoer::updateViewList()
{
	if (!m_pScene)
		return ;
	CMapGrid* mapGrid = m_pScene->m_pMapGrid;
	if (!mapGrid)
		return ;

	//重置更新时间
	m_dwNextUpdateViewTime = g_LogicEngine->getTickCount() + 500;
	bool changeFlag = false;

	//遍历entity对象的可视列表,设置列表中所有对象的mask为0离开视野
	ViewStruct *vList = m_ViewList;
	for (INT_PTR i = m_ViewList.count()-1; i > -1; --i)
	{
		if (vList[i].mask == VIEW_STATE_LEAVE)
		{
			if (m_btType == ePlayer)
				sendMsg(PM_ACTOR_DISAPPEAR, 0, vList[i].pEntity->m_EntityId.llid, 0, 0, 0);
			m_ViewList.remove(i);
		}
		else vList[i].mask = VIEW_STATE_LEAVE;
	}

	//遍历可视范围中所有块的所有对象,把每个对象都与当前可视列表对比,
	//已存在则设置mask为已存在,不存在则设置mask为进入视野并添加进当前可视列表中
	CBList<CEntity*> eList;

	int l = GX(m_nX) - m_nViewArea / 2;
	int t = GY(m_nY) - m_nViewArea / 2;
	int r = l + m_nViewArea;
	int b = t + m_nViewArea;

	if (mapGrid->getEntityList(l, r, t, b, eList, this) > 0)
	{
		int nViewIdx = -1;
		CEntity** pEList = eList;
		for (INT_PTR nEList = eList.count()-1; nEList > -1; --nEList)
		{
			nViewIdx = getViewIndex( pEList[nEList]);
			if (-1 != nViewIdx)
			{
				vList[nViewIdx].mask = VIEW_STATE_STAY;
			}
			else
			{
				ViewStruct view;
				view.mask = VIEW_STATE_ENTER;
				view.pEntity = pEList[nEList];
				m_ViewList.add(view);
				vList = m_ViewList;//防止m_ViewList元素增加导致内存地址改变
				changeFlag = true;
			}
		}
	}

	//发送新加入可视列表的对象
	if (changeFlag && m_btType == ePlayer)
	{
		ViewStruct *vList = m_ViewList;
		for (INT_PTR i = m_ViewList.count()-1; i > -1; --i)
		{
			if (vList[i].mask == VIEW_STATE_ENTER)
			{
				vList[i].mask = VIEW_STATE_STAY;
				sendMsg(PM_ACTOR_APPEAR, 0, (INT_PTR)vList[i].pEntity, 0, 0, 0);
			}
		}
	}
}

//查找是否在当前对象的可视列表中,存在则返回所在的索引,不存在则返回-1
int CDoer::getViewIndex(CEntity* pObject)
{
	ViewStruct* vList = m_ViewList;
	for (INT_PTR i = m_ViewList.count()-1; i > -1; --i)
	{
		if (pObject == vList[i].pEntity)
		{
			return (int)i;
		}
	}
	return -1;
}

void CDoer::disappear()
{
	if (!m_boDisappeared)
	{
		super::disappear();
	}
}

CDoerUnit* CDoer::getModule(const int nSysId)
{
	switch(nSysId)
	{
	case common::SystemId::sysAbil:	return &m_Abil;
	case common::SystemId::sysBattle: return &m_Battle;
	default: return NULL;
	}
}

void CDoer::sendMsg(int ident, int sysId, INT_PTR p1, INT_PTR p2, INT_PTR p3, INT_PTR p4)
{
	DoerMsg *msg = CGlobalLogicObjAlloc::allocDoerMsg();
	msg->ident = ident;
	msg->sysId = sysId;
	msg->param1 = p1;
	msg->param2 = p2;
	msg->param3 = p3;
	msg->param4 = p4;
	msg->next = NULL;
	if (m_pLastMsg)
		m_pLastMsg->next = msg;
	m_pLastMsg = msg;
	if (!m_pFirstMsg)
		m_pFirstMsg = msg;
}

void CDoer::broadcastMsg(int ident, int sysId, INT_PTR p1, INT_PTR p2, INT_PTR p3, INT_PTR p4)
{
	CDoer::ViewStruct *viewList = m_ViewList;
	for (INT_PTR i=m_ViewList.count()-1; i>-1; --i)
	{
		if (viewList->pEntity->m_btType >= eActor)
		{
			((CDoer*)viewList->pEntity)->sendMsg(ident, sysId, p1, p2, p3, p4);
		}
		viewList++;
	}
}

void CDoer::broadcastPlayerMsg(int ident, int sysId, INT_PTR p1, INT_PTR p2, INT_PTR p3, INT_PTR p4)
{
	if (m_btType == ePlayer)
	{
		sendMsg(ident, sysId, p1, p2, p3, p4);
	}
	CDoer::ViewStruct *viewList = m_ViewList;
	for (INT_PTR i=m_ViewList.count()-1; i>-1; --i)
	{
		if (viewList->pEntity->m_btType == ePlayer)
		{
			((CDoer*)viewList->pEntity)->sendMsg(ident, sysId, p1, p2, p3, p4);
		}
		viewList++;
	}
}

void CDoer::gainExp(int exp)
{
	winExp(exp);
}

void CDoer::winExp(int exp)
{
#if 0
	assert(exp > 0);
	m_nExp += exp;

	if (m_nExp >= m_nExpMax)
	{
		do
		{
			m_nExp -= m_nExpMax;
			m_nLevel++;
			m_nExpMax = g_ConfigManager->playerLevelDataProvider.getLevel(m_nLevel)->expMax;
		}
		while (m_nExp >= m_nExpMax);
		m_dwStateMasks |= esDescDirty;//标记刷新角色描述
		m_Abil.recalcAbility();
		m_Abil.sendAbility();
		broadcastPlayerMsg(PM_LEVEL_CHANGE, 0, (INT_PTR)this, m_nLevel, 0, 0);
		broadcastPlayerMsg(PM_ACTOR_DESC_CHANGE, 0, (INT_PTR)this, 0, 0, 0);
		//分派升级事件
		LogicEvent event(leLevelChange, this);
		g_LogicEngine->dispatchLogicEvent(event);
	}

	if (m_btType == ePlayer)
	{
		CGateSendPacket &pack = ((CPlayer*)this)->allocSendPacket();
		pack.writeCmd(sysAbil, sExpChange);
		pack << (int)m_nExp;
		pack << (int)m_nExpMax;
	}
#endif
}

void CDoer::dispatchMsg(DoerMsg *msg)
{
	switch(msg->ident)
	{
	case PM_SECNECHANGED:
		updateViewList();
		break;
	}
}

void CDoer::sceneChanged(Scene *oldScene, int ox, int oy)
{
	if (m_nBornX == -1)
	{
		m_nBornX = m_nX;
		m_nBornY = m_nY;
	}
}

void CDoer::positionChanged(int ox, int oy)
{
	if (GX(ox) != GX(m_nX) || GY(oy) != GY(m_nY))
	{
		sendMsg(PM_SECNECHANGED, 0, 0, 0, 0, 0);
	}
}

void CDoer::updateEntityDescription()
{
	m_EntityDesc.race = m_btType;
	m_EntityDesc.body = m_wEntityBody;
	m_EntityDesc.level = m_nLevel;
	m_EntityDesc.hitSpeedRate = 0;
}


