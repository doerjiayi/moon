#include "StdAfx.h"

void CDoerBattle::dispatchRecvPacket(int btCmd, CDataPacketReader &inPacket)
{
	switch(btCmd)
	{
	case common::NetCmd::cStartRun://起跑
		clientStartRunHandler(inPacket);
		break;
	case common::NetCmd::cStopRun://停跑
		clientStopRunHandler(inPacket);
		break;
	case common::NetCmd::cNormalAttack://普通攻击
		clientNormalAttackhandler(inPacket);
		break;
	case common::NetCmd::cEnterGate://进入传送门
		clientEnterGateHandler(inPacket);
		break;
	case common::NetCmd::cPickDropItem://拾取掉落物品
		clientPickDropItem(inPacket);
		break;
	}
}

void CDoerBattle::sendSceneInfo()
{
	SceneStruct* sceneStruce = m_pActor->m_pScene->m_pSceneStruct;
	if (!sceneStruce)
		return ;
	CGateSendPacket &pack = m_pPlayer->allocSendPacket();
	pack.writeCmd(common::SystemId::sysBattle, NetCmd::sSwitchScene);

	pack << sceneStruce->id;//场景ID
	pack << sceneStruce->name;//场景名称
	pack << sceneStruce->mapFileName;//场景地图文件名称
	pack << (int)0;//副本ID
	pack << m_pPlayer->m_nX;//X坐标
	pack << m_pPlayer->m_nY;//Y坐标
	pack.flush();
}

void CDoerBattle::sendSyncPositionTo(CPlayer *target)
{
	CGateSendPacket &pack = target->allocSendPacket();
	pack.writeCmd(common::SystemId::sysBattle, NetCmd::sSetPosition);

	pack << m_pActor->m_EntityId.llid;
	pack << m_pActor->m_nX;
	pack << m_pActor->m_nY;
	pack.flush();
}

void CDoerBattle::sendStartRunTo(CPlayer *target)
{
	CGateSendPacket &pack = target->allocSendPacket();
	pack.writeCmd(common::SystemId::sysBattle, NetCmd::sStartRun);

	pack << m_pActor->m_EntityId.llid;
	pack << m_pActor->m_nX;
	pack << m_pActor->m_nY;
	pack << (short)m_nRunSpeedX;
	pack << (short)m_nRunSpeedY;

	//重新确定加速度时间
	unsigned short accTime = 0;
	if (m_nRunAccelerateTime != 0)
	{
		TickTime dwCurrTick = g_LogicEngine->getTickCount();
		int accRemain = (int)(dwCurrTick - m_dwRunStartTick - m_nRunAccelerateTime);
		if (accRemain >= 50)
			accTime = accRemain;
		else m_nRunAccelerateTime = 0;
	}
	pack << accTime;
	pack.flush();
}

#pragma pack(push, 1)
struct __BCStartRunData{
	PlayerId playerId;
	int x, y;
	short sx, sy;
	unsigned short accTime;
};
#pragma pack(pop)

void CDoerBattle::broadcastStartRun(int x, int y, int sx, int sy, int accTime)
{
	//如果这里的消息数据结构修改了，记得修改：CDoerBattle::sendStartRunTo函数内的消息构造
	__BCStartRunData data;

	data.playerId = m_pActor->m_EntityId;
	data.x = x;
	data.y = y;
	data.sx = sx;
	data.sy = sy;
	data.accTime = accTime;

	CDoer::ViewStruct *viewList = m_pActor->m_ViewList;
	for (INT_PTR i=m_pActor->m_ViewList.count()-1; i>-1; --i)
	{
		if (viewList->pEntity->m_btType == ePlayer)
		{
			CGateSendPacket &pack = ((CPlayer*)viewList->pEntity)->allocSendPacket();
			pack.writeCmd(sysBattle, sStartRun);
			pack << data;
			pack.flush();
		}
		viewList++;
	}
}

#pragma pack(push, 1)
struct __BCStopRunData{
	PlayerId playerId;
	int x, y;
};
#pragma pack(pop)

void CDoerBattle::broadcastStopRun(int x, int y)
{
	__BCStopRunData data;

	data.playerId = m_pActor->m_EntityId;
	data.x = x;
	data.y = y;

	CDoer::ViewStruct *viewList = m_pActor->m_ViewList;
	for (INT_PTR i=m_pActor->m_ViewList.count()-1; i>-1; --i)
	{
		if (viewList->pEntity->m_btType == ePlayer)
		{
			CGateSendPacket &pack = ((CPlayer*)viewList->pEntity)->allocSendPacket();
			pack.writeCmd(sysBattle, sStopRun);
			pack << data;
			pack.flush();
		}
		viewList++;
	}
}

#pragma pack(push, 1)
struct __BCNormalAttackData{
	PlayerId playerId;
	char dir, actionIdx;
};
#pragma pack(pop)

void CDoerBattle::broadcastNormalAttack(int dir, int actionIdx)
{
	__BCNormalAttackData data;

	data.playerId = m_pActor->m_EntityId;
	data.dir = dir;
	data.actionIdx = actionIdx;

	CDoer::ViewStruct *viewList = m_pActor->m_ViewList;
	for (INT_PTR i=m_pActor->m_ViewList.count()-1; i>-1; --i)
	{
		if (viewList->pEntity->m_btType == ePlayer)
		{
			CGateSendPacket &pack = ((CPlayer*)viewList->pEntity)->allocSendPacket();
			pack.writeCmd(sysBattle, sNormalAttack);
			pack << data;
			pack.flush();
		}
		viewList++;
	}
}

#pragma pack(push, 1)
struct __BCStruckData{
	PlayerId playerId;
	PlayerId sponserId;
	int hp;
	int hpMax;
};
#pragma pack(pop)

void CDoerBattle::broadcastStruck(CDoer *sponser, int damage)
{
	__BCStruckData data;

	data.playerId = m_pActor->m_EntityId;
	data.sponserId.llid = sponser ? sponser->m_EntityId.llid : 0;
	data.hp = m_pActor->m_Abil.m_nHP;
	data.hpMax = m_pActor->m_Abil.qiXue;

	CDoer::ViewStruct *viewList = m_pActor->m_ViewList;
	for (INT_PTR i=m_pActor->m_ViewList.count()-1; i>-1; --i)
	{
		if (viewList->pEntity->m_btType == ePlayer)
		{
			CGateSendPacket &pack = ((CPlayer*)viewList->pEntity)->allocSendPacket();
			pack.writeCmd(sysBattle, sStruck);
			pack << data;
			pack.flush();
		}
		viewList++;
	}
	//同时向自己发送受击的消息
	if (m_pPlayer)
	{
		CGateSendPacket &pack = m_pPlayer->allocSendPacket();
		pack.writeCmd(sysBattle, sStruck);
		pack << data;
		pack.flush();
	}
}

#pragma pack(push, 1)
struct __BCDieData{
	PlayerId playerId;
};
#pragma pack(pop)

void CDoerBattle::broadcastDie()
{
	__BCDieData data;

	data.playerId = m_pActor->m_EntityId;

	CDoer::ViewStruct *viewList = m_pActor->m_ViewList;
	for (INT_PTR i=m_pActor->m_ViewList.count()-1; i>-1; --i)
	{
		if (viewList->pEntity->m_btType == ePlayer)
		{
			CGateSendPacket &pack = ((CPlayer*)viewList->pEntity)->allocSendPacket();
			pack.writeCmd(sysBattle, sDie);
			pack << data;
			pack.flush();
		}
		viewList++;
	}
	//同时向自己发送死亡的消息
	if (m_pPlayer)
	{
		CGateSendPacket &pack = m_pPlayer->allocSendPacket();
		pack.writeCmd(sysBattle, sDie);
		pack << data;
		pack.flush();
	}
}

#pragma pack(push, 1)
struct __BCReviviscentData{
	PlayerId playerId;
};
#pragma pack(pop)

void CDoerBattle::broadcastReviviscent()
{
	__BCReviviscentData data;

	data.playerId = m_pActor->m_EntityId;

	CDoer::ViewStruct *viewList = m_pActor->m_ViewList;
	for (INT_PTR i=m_pActor->m_ViewList.count()-1; i>-1; --i)
	{
		if (viewList->pEntity->m_btType == ePlayer)
		{
			CGateSendPacket &pack = ((CPlayer*)viewList->pEntity)->allocSendPacket();
			pack.writeCmd(sysBattle, sReviviscent);
			pack << data;
			pack.flush();
		}
		viewList++;
	}
	//同时向自己发送复活的消息
	if (m_pPlayer)
	{
		CGateSendPacket &pack = m_pPlayer->allocSendPacket();
		pack.writeCmd(sysBattle, sReviviscent);
		pack << data;
		pack.flush();
	}
}

void CDoerBattle::clientStartRunHandler(CDataPacketReader &inPacket)
{
	if (m_pActor->m_boDead)
		return;
	int mx, my;
	short sx, sy;
	unsigned short accTime;
	unsigned int clientTick;
	inPacket >> mx >> my >> sx >> sy >> accTime >> clientTick;

	//客户端提供的时间值必须大于起始时间值
	if (clientTick < m_dwClientRunStartTick)
	{
		sendSyncPositionTo(m_pPlayer);
		return;
	}
	if (mx < 0 || my < 0 || mx >= m_pPlayer->m_pScene->m_nMapWidth || my >= m_pPlayer->m_pScene->m_nMapHeight)
	{
		sendSyncPositionTo(m_pPlayer);
		return;
	}

//#pragma __CPMSG__(TODO: miros : 效验移动速度值是否合法.........................)

	//正在移动则先更新移动后的新位置
	if (m_dwRunStartTick)
		updateRunState(m_dwRunStartTick + clientTick - m_dwClientRunStartTick);

	//客户端与服务器坐标误差在一定范围内，则以客户端坐标为准
	if (!isAcceptablePositionFaultBit(mx, my))
	{
		mx = m_pActor->m_nX;
		my = m_pActor->m_nY;
		sendSyncPositionTo(m_pPlayer);
	}
	else 
	{
		m_pActor->setXY(mx, my);
	}
	m_pActor->m_nX = mx;
	m_pActor->m_nY = my;
	m_dwClientRunStartTick = clientTick;
	startMove(sx, sy, accTime);
}

void CDoerBattle::clientStopRunHandler(CDataPacketReader &inPacket)
{
	if (!m_dwRunStartTick)
	{
		sendSyncPositionTo(m_pPlayer);
		return;
	}

	int mx, my;
	unsigned int clientTick;
	inPacket >> mx >> my >> clientTick;

	//客户端提交的时间比起跑时提交的时间小，则视为非法数据，强制使用服务器计算的值
	if (clientTick < m_dwClientRunStartTick || mx < 0 || my < 0 || mx > m_pPlayer->m_pScene->m_nMapWidth || my >= m_pPlayer->m_pScene->m_nMapHeight)
	{
		updateRunState(g_LogicEngine->getTickCount());
		sendSyncPositionTo(m_pPlayer);
		m_dwClientRunStartTick = 0;
		stopMove();
		return;
	}

	//正在移动则先更新移动后的新位置
	if (m_dwRunStartTick)
		updateRunState(m_dwRunStartTick + clientTick - m_dwClientRunStartTick);

	//客户端与服务器坐标误差在一定范围内，则以客户端坐标为准
	if (!isAcceptablePositionFaultBit(mx, my))
	{
		mx = m_pActor->m_nX;
		my = m_pActor->m_nY;
		sendSyncPositionTo(m_pPlayer);
	}
	m_pActor->setXY(mx, my);
	m_dwClientRunStartTick = 0;
	stopMove();
}

void CDoerBattle::clientNormalAttackhandler(CDataPacketReader &inPacket)
{
	if (m_pActor->m_boDead)
		return;
	char dir, postureIndex;
	inPacket >> dir >> postureIndex;
	broadcastNormalAttack(dir, postureIndex);

	const CFSkillPostureLevel* posture = SkillUtil::getNormalAttackPosture(m_pPlayer->m_btJob, postureIndex);
	m_pActor->m_btDirection = dir;
	startAttack(&posture, 1, dir);
}

void CDoerBattle::clientEnterGateHandler(CDataPacketReader &inPacket)
{
	if (!m_pActor->m_pScene)
	{
		logError("场景为空");
		return;
	}

	int nGateId;
	inPacket >> nGateId;

	const SceneGate* pGate = g_ConfigManager->sceneDataAccessor.getSceneGate(nGateId);
	if (!pGate || pGate->sceneId != m_pActor->m_pScene->m_nSceneId)
		return;

	//如果正在移动，则更新位置
	if (m_dwRunStartTick)
	{
		updateRunState(g_LogicEngine->getTickCount());
	}

	if (::abs(pGate->x - m_pActor->m_nX) <= 200 && ::abs(pGate->y - m_pActor->m_nY) <= 200)
	{
		//从当前场景管理器（副本）中查找目标场景
		Scene *pNewScene = m_pActor->m_pScene->m_pSceneManager->getSceneByID(pGate->targetId);
		//当前副本不存在目标场景则从静态场景中查找
		if (!pNewScene) pNewScene = g_staticSceneManager->getSceneByID(pGate->targetId);
		if (!pNewScene)return;
		stopMove();
		m_pActor->setScene(pNewScene, pGate->targetX, pGate->targetY);
		if (m_pPlayer) sendSyncPositionTo(m_pPlayer);
	}
}

void CDoerBattle::clientPickDropItem(CDataPacketReader &inPacket)
{
	int ident;
	ItemSeries series;
	inPacket >> ident;
	inPacket >> series;

	DropItemData *dropItem = g_LogicEngine->getDropItem(ident, series);
	if (dropItem)
	{
		if (dropItem->itemId > 0)
		{
			m_pPlayer->m_Bag.addItem(dropItem->itemId, dropItem->itemCount, dropItem->quality, dropItem->strong, 0, false, 0, NULL);
		}
		else if (dropItem->itemId == 0)
		{
			m_pPlayer->addCoin(dropItem->itemCount);
		}
	}

	CGateSendPacket &sendPack = m_pPlayer->allocSendPacket();
	sendPack.writeCmd(sysBattle, sDropItemDisappear);
	sendPack << series;
	sendPack.flush();
}
