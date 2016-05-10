#include "StdAfx.h"
#include "LogicEngine.h"

//初始化监听事件
void CLogicEngine::initEventListener()
{
	m_EventDispatcher.addEventListener(leAddItem, &CPlayerQuest::addItem);
	m_EventDispatcher.addEventListener(leDelItem, &CPlayerQuest::delItem);
	m_EventDispatcher.addEventListener(leActorDie, &CPlayerQuest::actorDie);
}
//释放监听事件
void CLogicEngine::releaseEventListener()
{
	m_EventDispatcher.removeEventListener(leAddItem, &CPlayerQuest::addItem);
	m_EventDispatcher.removeEventListener(leDelItem, &CPlayerQuest::delItem);
	m_EventDispatcher.removeEventListener(leActorDie, &CPlayerQuest::actorDie);
}

CLogicEngine::CLogicEngine()
	:super(TRUE)//, CBaseObject()
{
	m_boStoped = FALSE;
	m_OpenPlayerList.setLock(&m_OpenPlayerLock);
	m_nProcOpenPlayerIndex = 0;
	m_nProcPlayerIndex = 0;
	m_dwNextRemoveExpiredDropItemTick = 0;
	//初始化监听事件
	initEventListener();
}

CLogicEngine::~CLogicEngine()
{
	//释放监听事件
	releaseEventListener();
	stopEngine();
}

void CLogicEngine::OnRountine()
{
	while (!terminated())
	{
		if (m_boStoped && m_PlayerList.getPlayerCount() <= 0)
			break;
		m_dwCurrentTick = _getTickCount();
		GetLocalTime(&m_SysTime);
		m_nDateTime.encode(m_SysTime);

		//主要逻辑处理
		{
			CSafeLock sl(&m_LoginRunLock);
			ProcessOpenPlayers(4);				//处理新玩家进入数据
			DispatchPlayerRecvPackets();		//提取并分派所有玩家收到的数据包
			ProcessPlayers(16);					//处理所有在线玩家
			FreeWaitFreeGateRecvPackets();		//释放所有待释放的玩家已处理数据包列表
			m_MonsterEngine.run(32);			//处理怪物
			//移除过期的掉落物品
			if (m_dwCurrentTick >= m_dwNextRemoveExpiredDropItemTick)
			{
				m_dwNextRemoveExpiredDropItemTick = m_dwCurrentTick + 60 * 1000;
				removeExpiredDropItems();
			}

			//删除过期副本
			if (m_dwCurrentTick >= m_dwNextRemoveExpiredDuplicateTick)
			{
				m_dwNextRemoveExpiredDuplicateTick = m_dwCurrentTick + 30 * 1000;
				g_DuplicateManager->OnRoutine();
			}

		}

		moon::OS::osSleep(4);
	}
	m_MonsterEngine.clearMonsters();
	clearDropItems();
}

bool CLogicEngine::startEngine()
{
	resume();
	m_boStoped = FALSE;
	return true;
}

void CLogicEngine::stopEngine()
{
	if (!m_boStoped)
	{
		m_boStoped = TRUE;
		resume();
		waitFor();
		DestroyInvalidPlayers();
	}
}

common::STDGUID CLogicEngine::allocId()
{
	if (m_nAllocIdTime.tv < m_nDateTime.tv)
	{
		m_nAllocIdTime.tv = m_nDateTime.tv;
		m_nAllocIdSeries = 1;
	}
	else
	{
		m_nAllocIdSeries++;
		if (m_nAllocIdSeries >= 0xFFFF)
		{
			m_nAllocIdSeries = 1;
			m_nAllocIdTime.tv++;
		}
	}
	common::STDGUID id;
	id.server = (unsigned short)g_LogicServer->getServerId();
	id.series = (unsigned short)m_nAllocIdSeries;
	id.time = m_nAllocIdTime.tv;
	return id;
}

DropItemData* CLogicEngine::allocDropItem()
{
	DropItemData *dropItem = CGlobalLogicObjAlloc::allocDropItem();
	if (m_FreeDropItemIndexList.count() > 0)
	{
		dropItem->serverIdent = (int)m_FreeDropItemIndexList.pop();
		m_DropItemList[dropItem->serverIdent] = dropItem;
	}
	else
	{
		dropItem->serverIdent = (int)m_DropItemList.add(dropItem);
	}
	dropItem->series = allocId();
	dropItem->expireTime = m_nDateTime.tv + 3 * 60;//默认3分钟的过期时间
	return dropItem;
}

DropItemData* CLogicEngine::getDropItem(int ident, ItemSeries series)
{
	if (ident < 0 || ident >= m_DropItemList.count())
		return NULL;
	DropItemData *dropItem = m_DropItemList[ident];
	if (!dropItem || dropItem->series.llid != series.llid)
		return NULL;
	return dropItem;
}

void CLogicEngine::removeDropItem(int ident, ItemSeries series)
{
	if (ident < 0 || ident >= m_DropItemList.count())
		return ;
	DropItemData *dropItem = m_DropItemList[ident];
	if (!dropItem || dropItem->series.llid != series.llid)
		return ;
	m_DropItemList[ident] = NULL;
	m_FreeDropItemIndexList.add(ident);
	CGlobalLogicObjAlloc::freeDropItem(dropItem);
}

void CLogicEngine::openPlayer(EnterGameStruct *pEnterStruct, bool boIsNewPlayer, CPoolDataPacket *pDataPacket)
{
	CSafeLock sl(&m_OpenPlayerLock);
	OpenPlayerStruct *pOpenStruct = m_OpenPlayerDataAllocator.allocObject();
	pOpenStruct->enter = *pEnterStruct;
	pOpenStruct->boIsNewPlayer = boIsNewPlayer;
	pOpenStruct->dataPack = pDataPacket;
	m_OpenPlayerList.append(pOpenStruct);
}

void CLogicEngine::ProcessOpenPlayers(DWORD dwTimeLimit)
{
	TICKCOUNT dwProcEndTick = _getTickCount() + dwTimeLimit;
	const INT_PTR nCount = m_OpenPlayerList.count();
	OpenPlayerStruct *pStruct, **pStructList = m_OpenPlayerList;
	CGateManager *pGateManager = g_GateManager;

	while (m_nProcOpenPlayerIndex < nCount)
	{
		pStruct = pStructList[m_nProcOpenPlayerIndex];
		m_nProcOpenPlayerIndex++;

		CLogicGate *pGate = pGateManager->getGate(pStruct->enter.userHandle.wGateIndex);
		if (!pGate || (pGate->GetSessionList()[pStruct->enter.userHandle.wUserIndex])->PlayerId.llid != pStruct->enter.charId.llid)
		{
			continue;
		}

		CPlayer *pPlayer = new CPlayer();

		if (!pPlayer->initialize())
		{
			SafeDelete(pPlayer);
		}
		else
		{
			//读取角色数据
			pPlayer->setIdentity(&pStruct->enter, pStruct->boIsNewPlayer);
			if (!pPlayer->m_pGate)
			{
				SafeDelete(pPlayer);
			}
			else
			{
				//OutDebugLog("玩家加入玩家列表charName:%s|charId:%ld", pPlayer->m_sAccount, pPlayer->m_nAccountId);
				m_PlayerList.addPlayer(pPlayer);
				pStruct->dataPack->setPosition(0);
				if (pPlayer->loadData(*pStruct->dataPack) 
					&& pPlayer->m_pGate->SetSessionPlayer(&pStruct->enter.userHandle, pPlayer, pPlayer->m_nPlayerIndex))
				{
					pPlayer->readyForRun();
				}
				else
				{
					m_PlayerList.removePlayer(pPlayer);
					SafeDelete(pPlayer);
				}
			}
		}

		if (!pPlayer)
		{
//#pragma __CPMSG__(TODO: miros : 通过用户句柄关闭网关连接)
		}

		//限制处理时间
		if (_getTickCount() >= dwProcEndTick)
			break;
	}
	if (m_nProcOpenPlayerIndex >= nCount)
	{
		CSafeLock sl(&m_OpenPlayerLock);
		for (INT_PTR i=0; i<nCount; ++i)
		{
			pStruct = pStructList[i];
			if (pStruct->dataPack)
				pStruct->dataPack->freeBack();
			m_OpenPlayerDataAllocator.freeObject(pStruct);
		}
		m_OpenPlayerList.trunc(0);
		m_OpenPlayerList.flush();
		m_nProcOpenPlayerIndex = 0;
	}
}

void CLogicEngine::ProcessPlayers(DWORD dwTimeLimit)
{
	TICKCOUNT dwProcEndTick = _getTickCount() + dwTimeLimit;
	CPlayer *pPlayer;
	TICKCOUNT dwCurrTick = m_dwCurrentTick;
	INT_PTR i;

	/***** 处理在线玩家 ******/
	while (m_nProcPlayerIndex < m_PlayerList.getPlayerCount()/*不能使用中间变量，因为过程中会删除数据*/)
	{
		pPlayer = m_PlayerList.getPlayerAtIndex(m_nProcPlayerIndex);
		m_nProcPlayerIndex++;
		//例行更新角色
		if (dwCurrTick - pPlayer->m_dwLastRunTick >= 50)
		{
			pPlayer->m_dwLastRunTick = dwCurrTick;
			pPlayer->run(dwCurrTick);
			//定时保存玩家数据
			if (dwCurrTick >= pPlayer->m_dwNextSaveDataTick)
			{
				savePlayer(pPlayer);
			}
		}
		//角色已无效，则将角色加入到无效角色列表中
		if (!pPlayer->m_boValid)
		{
			m_PlayerList.removePlayer(pPlayer);
			m_InvalidPlayerList.add(pPlayer);
			m_nProcPlayerIndex--;
			//角色离线时保存角色数据
			savePlayer(pPlayer);
		}
		//限制处理时间
		if (_getTickCount() >= dwProcEndTick)
			break;
	}
	if (m_nProcPlayerIndex >= m_PlayerList.getPlayerCount())
	{
		m_nProcPlayerIndex = 0;
	}

	/**** 处理失效玩家 ****/
	for (i=m_InvalidPlayerList.count()-1; i>-1; --i)
	{
		pPlayer = m_InvalidPlayerList[i];
		if (dwCurrTick - pPlayer->m_dwInvalidTick >= 5 * 60 * 1000)
		{
			m_InvalidPlayerList.remove(i);
			//OutDebugLog("踢掉一个玩家  charName:%s|charId:%d", pPlayer->m_sAccount, pPlayer->m_nAccountId);
			delete pPlayer;
		}
	}
}

void CLogicEngine::DispatchPlayerRecvPackets()
{
	CLogicGate *pGate;
	CPlayer *pPlayer;

	for (int nGateIdx=g_GateManager->getGateCount()-1; nGateIdx>-1; --nGateIdx)
	{
		pGate = g_GateManager->getGate(nGateIdx);

		//从网关提取客户端发送的数据包列表
		m_PlayerRecvPacketList.trunc(0);
		pGate->PeekPlayerRecvPackets(&m_PlayerRecvPacketList);
		INT_PTR nCount = m_PlayerRecvPacketList.count();
		GATERECVPLAYERPACKET *pPacketList = m_PlayerRecvPacketList;
		//将数据包列表分派到每个对应的玩家消息列表中
		for (INT_PTR j=0; j<nCount; ++j)
		{
			const GATERECVPLAYERPACKET &recvPack = pPacketList[j];
			pPlayer = m_PlayerList.getPlayerByPlayerIndex(recvPack.nPlayerIndex);
			if (pPlayer && pPlayer->m_boValid && pPlayer == recvPack.pPlayer && pPlayer->m_nGateIndex == nGateIdx 
				&& pPlayer->m_nGateVerify == recvPack.nVerifyIndex)
			{
				pPlayer->m_NetMsgs.add(recvPack.pPacket);
			}
			else
			{
				freeBackPlayerRecvPacket(nGateIdx, recvPack.pPacket);
			}
		}
	}
}

void CLogicEngine::DestroyInvalidPlayers()
{
	CPlayer *pPlayer;

	for (INT_PTR i=m_InvalidPlayerList.count()-1; i>-1; --i)
	{
		pPlayer = m_InvalidPlayerList[i];
		delete pPlayer;
	}
	m_InvalidPlayerList.clear();
}

void CLogicEngine::FreeWaitFreeGateRecvPackets()
{
	for (int i=g_GateManager->getGateCount()-1; i>-1; --i)
	{
		CBList<CNetPacket*> *pFreePacketList = &m_WaitFreeGateRecvPackets[i];
		INT_PTR nCount = pFreePacketList->count();
		if (nCount > 0)
		{
			CNetPacketPool *pPool = (*pFreePacketList)[0]->getPool();
			pPool->freePacketList(*pFreePacketList, (INT)nCount);
			pFreePacketList->trunc(0);
		}
	}
}

void CLogicEngine::savePlayer(CPlayer *pPlayer)
{
	CPoolDataPacket *pPacket = g_DBManager->requestPoolDataPacket();
	pPlayer->saveData(*pPacket);
	g_DBManager->requestSaveCharData(pPlayer->m_EntityId, pPlayer->m_nPlayerIndex, pPacket);
}

void CLogicEngine::clearDropItems()
{
	DropItemData **dropList = m_DropItemList;
	for (INT_PTR i=m_DropItemList.count()-1; i>-1; --i)
	{
		if (dropList[i])
			CGlobalLogicObjAlloc::freeDropItem(dropList[i]);
	}
	m_DropItemList.clear();
	m_FreeDropItemIndexList.clear();
}

void CLogicEngine::removeExpiredDropItems()
{
	const unsigned int dateTime = m_nDateTime;
	DropItemData **dropList = m_DropItemList;
	for (INT_PTR i=m_DropItemList.count()-1; i>-1; --i)
	{
		DropItemData *dropItem = dropList[i];
		if (dropItem && dateTime >= dropItem->expireTime)
		{
			dropList[i] = NULL;
			m_FreeDropItemIndexList.add(i);
			CGlobalLogicObjAlloc::freeDropItem(dropItem);
		}
	}
}

