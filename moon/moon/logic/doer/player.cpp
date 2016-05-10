#include "StdAfx.h"

CPlayer::CPlayer()
	:super()
{
	m_btType = ePlayer;
	m_nPlayerIndex = 0;
	m_sAccount[0] = 0;
	m_nAccountId = 0;
	m_nCreateTime = 0;
	m_pGate = NULL;
	m_llSocket = 0;
	m_nGateIndex = -1;
	m_nGateUserIndex = -1;
	m_nGateVerify = 0;
	m_nClientAddr = 0;
	m_dwEnterTick = 0;
	m_nEnterGameTime = 0;
	m_dwClosedTick = 0;
	m_dwInvalidTick = 0;
	m_dwNextSaveDataTick = g_LogicEngine->getTickCount() + 5 * 60 * 1000;
	m_boIsNewPlayer = false;
	m_btGender = 0;
	m_btJob = 0;
	m_btGMLevel = 10;
	m_GuildId.llid = 0;
	m_pGuild = NULL;
	m_nCoin = 0;
	m_nGameGold = 0;
	m_DearId.llid = 0;
	m_sDearName[0] = 0;
	m_nNetMsgIndex = 0;
	memset(&m_StaticPosition, 0, sizeof(m_StaticPosition));
	memset(&m_DynamicPosition, 0, sizeof(m_DynamicPosition));
}

CPlayer::~CPlayer()
{
	clearNetMsgs();
}

void CPlayer::run(TickTime dwCurrTick)
{
	if (m_boValid)
	{
		//离线处理
		if (m_dwClosedTick)
		{
			m_dwInvalidTick = dwCurrTick;
			m_boValid = false;
			offline();
			disappear();
		}
	}
	if (m_boValid)
	{
		//处理网络消息
		processNetMsgs(4);
		
		
	}
	super::run(dwCurrTick);
}

void CPlayer::setIdentity(EnterGameStruct *pEnterStruct, bool boIsNewPlayer)
{
	m_EntityId = pEnterStruct->charId;
	_asncpytA(m_sName, pEnterStruct->sCharName);
	_asncpytA(m_sAccount, pEnterStruct->sAccount);
	m_nAccountId = pEnterStruct->nAccountId;
	m_llSocket = pEnterStruct->userHandle.llSocket;
	m_nGateIndex = pEnterStruct->userHandle.wGateIndex;
	m_nGateUserIndex = pEnterStruct->userHandle.wUserIndex;
	m_nGateVerify = pEnterStruct->userHandle.nVerify;
	m_nClientAddr = pEnterStruct->nClientAddr;
	m_boValid = true;
	m_boIsNewPlayer = boIsNewPlayer;

	m_pGate = g_GateManager->getGate(pEnterStruct->userHandle.wGateIndex);
	CLogicEngine *pLogicEngine = g_LogicEngine;
	m_dwEnterTick = pLogicEngine->getTickCount();
	m_nEnterGameTime = pLogicEngine->getDateTime();
}

void CPlayer::gotoBornScene()
{
#if 0
	SceneBase* location = g_ConfigManager->sceneDataProvider.getBirthScene();
	if (!location)
		//应急场景ID
		location = g_ConfigManager->sceneDataProvider.getUrgentScene();

	if (!location)
		return;

	Scene *scene = g_staticSceneManager->getSceneByID(location->m_nSceneId);
	int mapX = getRandomKey(location->m_nMaxX,location->m_nMaxX);
	int mapY = getRandomKey(location->m_nMinY,location->m_nMaxY);
	setScene(scene, mapX, mapY);
#endif
}

void CPlayer::addCoin(int count)
{
	assert(count > 0);
	m_nCoin += count;
	sendCoinCount();
}

bool CPlayer::decCoin(int count)
{
	assert(count > 0);
	if (m_nCoin >= count)
	{
		m_nCoin -= count;
		sendCoinCount();
		return true;
	}
	return false;
}

bool CPlayer::initialize()
{
#if 0
	if (!super::initialize())
		return false;
	m_Abil.m_pPlayer = this;
	m_Battle.m_pPlayer = this;
	m_Quest.m_pPlayer = this;
	m_team.m_pPlayer = this;
	m_Weapon.m_pPlayer = this;

#define ____init_module(m, n) if (m.init())\
	{ m.m_pActor = this; m.m_pPlayer = this; }\
	else { logError( _T("初始化人物%s模块失败！"), n); return false; }
	
	____init_module(m_Bag, "背包");
	____init_module(m_Equip, "装备");
	____init_module(m_Quest, "任务");
	____init_module(m_NpcTalk, "NPC聊天");
	
	____init_module(m_playerChat, "聊天系统");
	____init_module(m_team, "组队系统");
	____init_module(m_Weapon, "武器系统");
#endif 
	return true;
}

void CPlayer::close(bool boRemoteClose)
{
	m_dwClosedTick = g_LogicEngine->getTickCount();
	if (!boRemoteClose)
	{
		m_pGate->ClosePlayer(m_nGateUserIndex, m_nGateVerify, this, m_nGateUserIndex);
	}
}


void CPlayer::readyForRun()
{
#if 0
	//刷新属性
	m_Abil.m_nHP = 10000000;
	m_Abil.m_nMP = 10000000;
	m_Abil.recalcAbility();
	sendCoinCount();
	sendGameGoldCount();
	//切换场景数据
	m_Battle.sendSceneInfo();
	sendEntityAppear(this);
	//发送属性数据
	m_Abil.sendAbility();
	//发送装备数据
	m_Equip.sendEquipItems();
	//发送背包数据
	m_Bag.sendBagItems();
	//发送任务列表
	m_Quest.sendQuestDatas();
	//发送武器数据
	m_Weapon.sendWeaponFullInfo();

	//分派玩家登陆事件，仍有其他数据要发送请前置
	LogicEvent event(leEnterGamer, this);
	g_LogicEngine->dispatchLogicEvent(event);
#endif 
}

CDoerUnit* CPlayer::getModule(const int nSysId)
{
#if 0
	switch(nSysId)
	{
	case common::SystemId::sysAbil:	return &m_Abil;
	case common::SystemId::sysBattle: return &m_Battle;
	case common::SystemId::sysEquip: return &m_Equip;
	case common::SystemId::sysBag: return &m_Bag;
	case common::SystemId::sysQuest: return &m_Quest;
	case common::SystemId::sysTalkNpc:return &m_NpcTalk;
	case common::SystemId::sysChat: return &m_playerChat;
	case common::SystemId::sysTeam: return &m_team;
	case common::SystemId::sysWeapon: return &m_Weapon;
	default: return NULL;
	}
#endif
	return NULL;
}

void CPlayer::sendSceneInfo()
{
	SceneStruct* sceneStruce = m_pScene->getpSceneStruct();
	if (!sceneStruce)
	{

	}
	CGateSendPacket &pack = allocSendPacket();
	pack.writeCmd(common::SystemId::sysBattle, NetCmd::sSwitchScene);

	pack << sceneStruce->id;//场景ID
	pack << sceneStruce->name;//场景名称
	pack << sceneStruce->mapFileName;//场景地图文件名称
	pack << 0;//副本ID
	pack << m_nX;//X坐标
	pack << m_nY;//Y坐标
	pack.flush();
}

void CPlayer::sendCoinCount()
{
	CGateSendPacket &pack = allocSendPacket();
	pack.writeCmd(sysBag, sCoinChange);
	pack << m_nCoin;
	pack.flush();
}

void CPlayer::sendGameGoldCount()
{
	CGateSendPacket &pack = allocSendPacket();
	pack.writeCmd(sysBag, sGameGoldChange);
	pack << m_nGameGold;
	pack.flush();
}

void CPlayer::sendEntityAppear(CEntity *pEntity)
{
	EntityDesc desc;
	CDoer *actor = (pEntity->m_btType >= eActor) ? (CDoer*)pEntity : NULL;
	const DoerAbilData &ab = actor->m_Abil;

	CGateSendPacket &pack = allocSendPacket();
	pack.writeCmd(common::SystemId::sysBattle, pEntity == this ? NetCmd::sSendMySelf : NetCmd::sActorAppear);
	pack << pEntity->m_EntityId.llid;

	if (actor)
		pack << actor->m_sName;
	else pack << "";
	pack << pEntity->m_nX;//坐标x
	pack << pEntity->m_nY;//坐标y
	pack << pEntity->getEntityDescription(desc, this);
	pack << (int)actor->m_Abil.m_nHP;
	pack << ab;
	pack.flush();

	//发送玩家移动状态
	if (actor && actor->m_Battle.isRunning())
		actor->m_Battle.sendStartRunTo(this);
}

void CPlayer::offline()
{
	//分派玩家离线，如有数据要处理请后置
	LogicEvent event(leOffline, this);
	g_LogicEngine->dispatchLogicEvent(event);

	//如果在副本中，则记录副本位置
	recordDynamicScenePosition();
	//通知各系统玩家离线
	CDoerUnit *pActorModule;
	for (int i=1; i<sysCount; ++i)
	{
		pActorModule = getModule(i);
		if (pActorModule)
			pActorModule->offline();
	}
}

void CPlayer::clearNetMsgs()
{
	INT_PTR nCount = m_NetMsgs.count();
	if (nCount > 0)
	{
		CNetPacket **pPacketList = m_NetMsgs;
		for (INT_PTR i=nCount-1; i>-1; --i)
		{
			g_LogicEngine->freeBackPlayerRecvPacket(m_nGateIndex, pPacketList[i]);
		}
		m_NetMsgs.clear();
		m_nNetMsgIndex = 0;
	}
}

void CPlayer::processNetMsgs(unsigned int dwTickLimit)
{
	const INT_PTR nCount = m_NetMsgs.count();
	if (nCount <= 0)
		return;

	common::TickTime dwStartTick = _getTickCount();
	while (m_nNetMsgIndex < nCount)
	{
		CNetPacket *pPacket = m_NetMsgs[m_nNetMsgIndex];
		m_nNetMsgIndex++;

		common::NetPacketMessage msg(0);
		*pPacket >> msg;

		CDoerUnit *pModule = getModule(msg.btSysId);
		if (pModule)
		{
			CDataPacketReader dataPacketReader = CDataPacketReader(pPacket->getOffsetPtr(), pPacket->getAvaliableLength());
			pModule->dispatchRecvPacket(msg.btCmd,dataPacketReader);
		}
		if (_getTickCount() - dwStartTick >= dwTickLimit)
			break;
	}
	if (m_nNetMsgIndex >= nCount)
	{
		clearNetMsgs();
	}
}



void CPlayer::dispatchMsg(DoerMsg *msg)
{
	switch(msg->ident)
	{
	case PM_ACTOR_APPEAR:
		{
			sendEntityAppear((CDoer*)msg->param1);
		}
		break;
	case PM_ACTOR_DISAPPEAR:
		{
			CGateSendPacket &pack = allocSendPacket();
			pack.writeCmd(common::SystemId::sysBattle, NetCmd::sActorDisappear);
			pack << msg->param1;
			pack.flush();
		}
		break;
	case PM_REF_NPC_QUEST_STATE:
		{
			//任务状态改变,刷新可视列表内所有NPC的状态
			updateNpcState();
		}
		break;
	case PM_LEVEL_CHANGE:
		{
			CDoer *pActor = (CDoer*)msg->param1;
			CGateSendPacket &pack = allocSendPacket();
			pack.writeCmd(common::SystemId::sysBattle, NetCmd::sLevelChange);
			pack << pActor->m_EntityId;
			pack << (unsigned short)pActor->m_nLevel;
			pack.flush();
		}
		break;
	case PM_ACTOR_DESC_CHANGE:
		{
			CDoer *pActor = (CDoer*)msg->param1;
			EntityDesc desc;
			pActor->getEntityDescription(desc, this);

			CGateSendPacket &pack = allocSendPacket();
			pack.writeCmd(common::SystemId::sysBattle, NetCmd::sActorDescChange);
			pack << pActor->m_EntityId;
			pack << desc;
			pack.flush();
		}
		break;
	default:
		super::dispatchMsg(msg);
		break;
	}
}

void CPlayer::sceneChanged(Scene *oldScene, int ox, int oy)
{
	//检测副本变更
	if (oldScene != m_pScene || oldScene->m_pSceneManager != m_pScene->m_pSceneManager)
	{
		if (oldScene && !oldScene->isStaticScene())
			oldScene->m_pSceneManager->delPlayer(this);
		if (m_pScene && !m_pScene->isStaticScene())
			m_pScene->m_pSceneManager->addPlayer(this);
	}
	if (m_pScene)
	{
		//切换到副本地图，保存进入副本前的静态场景位置
		if (oldScene && oldScene->isStaticScene() && !m_pScene->isStaticScene())
		{
			m_StaticPosition.nSceneId = oldScene->m_nSceneId;
			m_StaticPosition.nMapX = ox;
			m_StaticPosition.nMapY = oy;
		}
		sendSceneInfo();
		sendMsg(PM_SECNECHANGED, 0, 0, 0, 0, 0);
	}
}

void CPlayer::updateEntityDescription()
{
	m_EntityDesc.race = m_btType;
	m_EntityDesc.genob = (m_btGender << 4) | m_btJob;
	m_EntityDesc.level = m_nLevel;
	m_EntityDesc.body = m_Abil.m_wBody;
	m_EntityDesc.weapon = m_Abil.m_wWeapon;
	m_EntityDesc.wpeffect = 0;
	m_EntityDesc.mount = m_Abil.m_wMount;
	m_EntityDesc.moveSpeed = 500;
	m_EntityDesc.hitSpeedRate = 0;
	m_EntityDesc.flags = 0;
	m_EntityDesc.vipLevel = m_btVipLevel;
}

void CPlayer::recordDynamicScenePosition()
{
	if (m_pScene && !m_pScene->isStaticScene())
	{
		m_DynamicPosition.nDuplicateId = m_pScene->m_pSceneManager->m_Guid;
		m_DynamicPosition.nSceneId = m_pScene->m_nSceneId;
		m_DynamicPosition.nMapX = m_nX;
		m_DynamicPosition.nMapY = m_nY;
	}
	else
	{
		memset(&m_DynamicPosition, 0, sizeof(m_DynamicPosition));
	}
}

//任务状态改变,刷新可视列表内所有NPC的状态
void CPlayer::updateNpcState()
{
#if 0
	ViewStruct *vList = m_ViewList;
	for (INT_PTR i = m_ViewList.count()-1; i > -1; --i)
	{
		CEntity *pEntity = vList[i].pEntity;
		if (pEntity->m_btType == eNPC)
		{
			int nState = m_Quest.getNpcQuestState(pEntity->m_EntityId.llid);
			CGateSendPacket& packet = allocSendPacket();
			packet.writeCmd(common::SystemId::sysBattle, sNpcQuestState);
			packet << pEntity->m_EntityId.llid;
			packet << (char)nState;
			packet.flush();
		}
	}
#endif 
}
