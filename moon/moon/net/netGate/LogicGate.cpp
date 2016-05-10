#include "StdAfx.h"

CLogicGate::CLogicGate()
	:super()
{
	m_sGateName[0] = 0;
	m_boStarted = FALSE;
	m_nGateIndex = -1;
	m_SocketProcessor.SetDataProcesser(this);

	InitializeCriticalSection(&m_PostPlayerPackLock);
	m_pPostPlayerPackAppendList = &m_PostPlayerPackQueue[0];
	m_pPostPlayerPackWaitList = &m_PostPlayerPackQueue[1];
}

CLogicGate::~CLogicGate()
{
	stopGate();
	DeleteCriticalSection( &m_PostPlayerPackLock );
}

VOID CLogicGate::SetGateName(LPCSTR sName)
{
	ZeroMemory( m_sGateName, sizeof(m_sGateName) );
	strncpy( m_sGateName, sName, __min(sizeof(m_sGateName)-1, strlen(sName)) );
}

bool CLogicGate::startGate()
{
	if (super::Start() && m_SocketProcessor.Start())
	{
		m_boStarted = TRUE;
		return true;
	}
	return false;
}

void CLogicGate::stopGate()
{
	if (m_boStarted)
	{
		m_SocketProcessor.Stop();
		super::Stop();
		FreePostPlayerPackets();
		m_boStarted = FALSE;
	}
}

INT CLogicGate::PeekPlayerRecvPackets(CBList<GATERECVPLAYERPACKET> *pPacketList)
{
	EnterCriticalSection(&m_PostPlayerPackLock);

	//当等待处理的数据包列表存储到pPacketList中
	INT nCount = (INT)m_pPostPlayerPackWaitList->count();
	pPacketList->addList(*m_pPostPlayerPackWaitList);
	m_pPostPlayerPackWaitList->trunc(0);

	//交换待处理数据包与添加数据包列表
	CBList<GATERECVPLAYERPACKET> *pTempList = m_pPostPlayerPackWaitList;
	m_pPostPlayerPackWaitList = m_pPostPlayerPackAppendList;
	m_pPostPlayerPackAppendList = pTempList;

	LeaveCriticalSection(&m_PostPlayerPackLock);

	return nCount;
}

VOID CLogicGate::OnRecvThreadSingleRun(TICKCOUNT dwCurrTick)
{
	super::OnRecvThreadSingleRun(dwCurrTick);
	ProcessSynergyList();
}

void CLogicGate::HandleSynergyData(SynergyData *pData)
{
	DispatchSynergyData(pData);
	DestroySynergyData(pData);
}

void CLogicGate::DispatchSynergyData(SynergyData *pData)
{
	PRUNGATEUSERSESSION pSession;

	//检查用户有效性，确保用户未过期
	if (pData->userHandle.wUserIndex >= m_SessionList.count())
		return;
	pSession = m_SessionList[pData->userHandle.wUserIndex];
	if (!pSession || pSession->nSocket != (int)pData->userHandle.llSocket\
			|| pSession->nVerifyIdx != pData->userHandle.nVerify)
		return;

	switch(pData->opType)
	{
	case SynergyData::aorLogin:
		{
			CGateSendPacket &packet = AllocSendPacket(pSession->nIndex);
			packet.writeCmd(common::SystemId::sysLogin, common::NetCmd::sLoginRet);
			packet << pData->login.nErrorCode;
			packet << pData->login.nUserId;
			packet.flush();

			if (!pData->login.nErrorCode)
			{
				pSession->btUserState = eGUSSelChar;
				pSession->nAccountId = pData->login.nUserId;
			}
			else
			{
				pSession->btUserState = eGUSWaitLogin;
			}
		}
		break;
	case SynergyData::aorQueryCharList:
		{
			CGateSendPacket &packet = AllocSendPacket(pSession->nIndex);
			packet.writeCmd(common::SystemId::sysLogin, common::NetCmd::sSendCharList);
			packet << pData->querychar.nCharCount;
			packet.writeBuf(pData->querychar.pPacket->getMemoryPtr(), pData->querychar.pPacket->getLength());
			pData->createchar.pPacket->freeBack();
			packet.flush();
		}
		break;
	case SynergyData::aorCreateChar:
		{
			CGateSendPacket &packet = AllocSendPacket(pSession->nIndex);
			packet.writeCmd(common::SystemId::sysLogin, common::NetCmd::sCreateCharRet);
			packet << pData->createchar.nErrorCode;
			packet.writeBuf(pData->createchar.pPacket->getMemoryPtr(), pData->createchar.pPacket->getLength());
			packet.flush();
			pData->createchar.pPacket->freeBack();
			pSession->btUserState = eGUSSelChar;
		}
		break;
	case SynergyData::aorDeleteChar:
		{
			CGateSendPacket &packet = AllocSendPacket(pSession->nIndex);
			packet.writeCmd(common::SystemId::sysLogin, common::NetCmd::sDeleteCharRet);
			packet << pData->deletechar.nErrorCode;
			packet.flush();
			pSession->btUserState = eGUSSelChar;
		}
		break;
	case SynergyData::aorEnterGame:
		{
			CGateSendPacket &packet = AllocSendPacket(pSession->nIndex);
			packet.writeCmd(common::SystemId::sysLogin, common::NetCmd::sEnterGameRet);
			packet << pData->enterGame.nErrorCode;
			packet.flush();
			if (pSession->btUserState == eGUSWaitEnterGame)
				pSession->btUserState = eGUSSelChar;
		}
		break;
	}
}

void CLogicGate::DestroySynergyData(SynergyData *pData)
{
}

VOID CLogicGate::FreePostPlayerPackets()
{
	EnterCriticalSection(&m_PostPlayerPackLock);
	INT_PTR i;
	GATERECVPLAYERPACKET *pPackList;

	pPackList = *m_pPostPlayerPackAppendList;
	for (i=m_pPostPlayerPackAppendList->count()-1; i>-1; --i)
	{
		pPackList[i].pPacket->freeBack();
	}
	m_pPostPlayerPackAppendList->empty();

	pPackList = *m_pPostPlayerPackWaitList;
	for (i=m_pPostPlayerPackWaitList->count()-1; i>-1; --i)
	{
		pPackList[i].pPacket->freeBack();
	}
	m_pPostPlayerPackWaitList->empty();

	LeaveCriticalSection(&m_PostPlayerPackLock);
}

VOID CLogicGate::DispatchUserRecvPacket(PRUNGATEUSERSESSION pSession, char *pBuffer, uint32 nBufferSize)
{
	//会话第一次通信，请求数据包验证KEY
	if (pSession->btUserState == eGUSWaitRequestKey)
	{
		HandleUserRequestKey(pSession);
		return;
	}

	//检查数据包间隔，客户端每秒发送超过10个数据包则关闭连接！
	pSession->nIntervalMsgCount++;
	if (pSession->nIntervalMsgCount >= 10)
	{
		common::time::TICKCOUNT dwCurrTick = _getTickCount();
		if (dwCurrTick < pSession->dwMsgIntervalTick)
		{
			logWarn("[Gate] close client(%s) send too much packets(%d) in %dms", 
				inet_ntoa(pSession->SockAddr.sin_addr), pSession->nIntervalMsgCount, (1000 - (pSession->dwMsgIntervalTick - dwCurrTick)));
			CloseSession(pSession);
			return;
		}
		else
		{
			pSession->nIntervalMsgCount = 1;
			pSession->dwMsgIntervalTick = dwCurrTick + 1000;
		}
	}

	//读取消息头
	NetPacketMessage msg;
	if (nBufferSize < sizeof(msg))
	{
		logWarn("[Gate] drop client(%s) packet does not contain msg header", inet_ntoa(pSession->SockAddr.sin_addr));
		return;
	}
	msg = *((NetPacketMessage*)pBuffer);
	
	//游戏系统消息
	if (msg.btSysId != common::SystemId::sysLogin)
	{
		if (pSession->btUserState == eGUSInGame)
		{
			CNetPacket *pPacket = m_ProcPacketPool.allocPacket();
			pPacket->writeBuf(pBuffer, nBufferSize);
			pPacket->setPosition(0);

			EnterCriticalSection(&m_PostPlayerPackLock);
			INT_PTR nCount = m_pPostPlayerPackAppendList->count();
			if (nCount >= m_pPostPlayerPackAppendList->maxCount())
				m_pPostPlayerPackAppendList->reserve(__max(256, m_pPostPlayerPackAppendList->maxCount()) * 2);
			GATERECVPLAYERPACKET *pRecvPack = &((*m_pPostPlayerPackAppendList)[nCount]);
			m_pPostPlayerPackAppendList->trunc(nCount + 1);
			pRecvPack->nVerifyIndex = pSession->nVerifyIdx;
			pRecvPack->nPlayerIndex = pSession->nPlayerIndex;
			pRecvPack->pPlayer = pSession->pPlayer;
			pRecvPack->pPacket = pPacket;
			LeaveCriticalSection(&m_PostPlayerPackLock);
		}
		return;
	}

	//登陆相关消息
	pBuffer += sizeof(msg);
	nBufferSize -= sizeof(msg);
	CDataPacketReader dataPacketReader = CDataPacketReader(pBuffer, nBufferSize);
	switch (msg.btCmd)
	{
	case common::NetCmd::cRequestLogin:
		{
			if (pSession->btUserState != eGUSWaitLogin)
				return;
			HandleUserLogin(pSession,dataPacketReader);
		}
		break;
	case common::NetCmd::cQueryCharList:
		{
			if (pSession->btUserState != eGUSSelChar)
				return;
			HandleUserQueryChar(pSession);
		}
		break;
	case common::NetCmd::cCreateChar:
		{
			if (pSession->btUserState != eGUSSelChar)
				return;
			HandleUserCreateChar(pSession, dataPacketReader);
		}
		break;
	case common::NetCmd::cDeleteChar:
		{
			if (pSession->btUserState != eGUSSelChar)
				return;
			HandleUserDeleteChar(pSession, dataPacketReader);
		}
		break;
	case common::NetCmd::cEnterGame:
		{
			if (pSession->btUserState != eGUSSelChar)
				return;
			HandleUserEnterGame(pSession, dataPacketReader);
		}
		break;
	}
}

VOID CLogicGate::PostEngineClosePlayer(PRUNGATEUSERSESSION pSession)
{
	if (pSession->pPlayer && pSession->nPlayerIndex > -1)
	{
		//为保证数据安全，必需再取一遍角色指针进行验证
		CPlayer *pPlayer = g_LogicEngine->getPlayerList().getPlayerByPlayerIndex(pSession->nPlayerIndex);
		if (pPlayer && pPlayer == pSession->pPlayer && pPlayer->m_nGateUserIndex == pSession->nIndex)
		{
			pPlayer->close(true);
			pSession->pPlayer = NULL;
			pSession->nPlayerIndex = -1;
		}
	}
}

VOID CLogicGate::HandleUserRequestKey(PRUNGATEUSERSESSION pSession)
{
	//生成随机的数据包验证KEY
	unsigned char keyBuf[128];
	for (int i=0; i<(int)ArrayCount(keyBuf); ++i)
	{
		keyBuf[i] = (unsigned char)randValue();
	}
	keyBuf[0] = (unsigned char)randValue(126);
	keyBuf[1] = (unsigned char)randValue(126);
	//保存通信数据包验证KEY
	pSession->wPacketVerifyKey = keyBuf[2 + keyBuf[0]] | (keyBuf[2 + keyBuf[1]] << 8);
// 	printf("GEN KEY:%X(%d) %d:%d %X%X\n",
// 			pSession->wPacketVerifyKey, pSession->wPacketVerifyKey,
// 			keyBuf[0], keyBuf[1], keyBuf[2 + keyBuf[1]], keyBuf[2 + keyBuf[0]]);
	//发送通信数据包验证KEY
	CGateSendPacket &pack = AllocSendPacket(pSession->nIndex);
	pack.writeBuf(keyBuf, sizeof(keyBuf));
	pack.flush();
	pSession->btUserState = eGUSWaitLogin;//调整到等待登陆状态
}

VOID CLogicGate::HandleUserLogin(PRUNGATEUSERSESSION pSession, CDataPacketReader &inPacket)
{
	const char *sAccount, *sPassword;
	inPacket >> sAccount;
	inPacket >> sPassword;
	if (!sAccount || !sAccount[0] || !sPassword || !sPassword[0])
	{
		CloseSession(pSession);
		return;
	}
	common::SERVERUSERHANDLE UsrHdl;
	UsrHdl.llSocket = pSession->nSocket;
	UsrHdl.wUserIndex = pSession->nIndex;
	UsrHdl.nVerify = pSession->nVerifyIdx;
	UsrHdl.wGateIndex = m_nGateIndex;
	g_AccountManager->requestLogin(&UsrHdl, sAccount, sPassword);

	_asncpytA(pSession->sAccount, sAccount);
	pSession->btUserState = eGUSLoginInProgress;
}

VOID CLogicGate::HandleUserQueryChar(PRUNGATEUSERSESSION pSession)
{
	common::SERVERUSERHANDLE UsrHdl;
	UsrHdl.llSocket = pSession->nSocket;
	UsrHdl.wUserIndex = pSession->nIndex;
	UsrHdl.nVerify = pSession->nVerifyIdx;
	UsrHdl.wGateIndex = m_nGateIndex;

	//g_DBManager->requestQueryChar(&UsrHdl, pSession->nAccountId);
}

VOID CLogicGate::HandleUserCreateChar(PRUNGATEUSERSESSION pSession, CDataPacketReader &inPacket)
{
	common::SERVERUSERHANDLE UsrHdl;
	UsrHdl.llSocket = pSession->nSocket;
	UsrHdl.wUserIndex = pSession->nIndex;
	UsrHdl.nVerify = pSession->nVerifyIdx;
	UsrHdl.wGateIndex = m_nGateIndex;

	char sCharName[48];
	BYTE btGender = 0;
	BYTE btJob = 0;

	sCharName[ArrayCount(sCharName) - 1] = 0;
	inPacket.readString(sCharName, ArrayCount(sCharName) - 1);
	inPacket >> btJob;
	inPacket >> btGender;

	if ( btJob > 2 ||btGender > 1)
		return;

	//g_DBManager->requestCreateChar(&UsrHdl, pSession->nAccountId, pSession->sAccount, sCharName, btJob, btGender);
	pSession->btUserState = eGUSCreateChar;
}

VOID CLogicGate::HandleUserDeleteChar(PRUNGATEUSERSESSION pSession, CDataPacketReader &inPacket)
{
	common::SERVERUSERHANDLE UsrHdl;
	UsrHdl.llSocket = pSession->nSocket;
	UsrHdl.wUserIndex = pSession->nIndex;
	UsrHdl.nVerify = pSession->nVerifyIdx;
	UsrHdl.wGateIndex = m_nGateIndex;

	common::PlayerId charId;
	inPacket >> charId;

	//g_DBManager->requestDeleteChar(&UsrHdl, pSession->nAccountId, charId);
	pSession->btUserState = eGUSDeleteChar;
}

VOID CLogicGate::HandleUserEnterGame(PRUNGATEUSERSESSION pSession, CDataPacketReader &inPacket)
{
// 需要实现将在线的同一账号顶掉)
	inPacket >> pSession->PlayerId;
	pSession->sCharName[ArrayCount(pSession->sCharName)-1] = 0;
	inPacket.readString(pSession->sCharName, ArrayCount(pSession->sCharName) - 1);

	EnterGameStruct enter;
	enter.nAccountId = pSession->nAccountId;
	_asncpytA(enter.sAccount, pSession->sAccount);
	enter.charId = pSession->PlayerId;
	_asncpytA(enter.sCharName, pSession->sCharName);
#ifdef WINDOWS
	enter.nClientAddr = pSession->SockAddr.sin_addr.S_un.S_addr;
#else
	enter.nClientAddr = pSession->SockAddr.sin_addr.s_addr;
#endif
	enter.userHandle.llSocket = pSession->nSocket;
	enter.userHandle.nVerify = pSession->nVerifyIdx;
	enter.userHandle.wGateIndex = m_nGateIndex;
	enter.userHandle.wUserIndex = pSession->nIndex;
	g_DBManager->requestEnterGame(&enter);
	pSession->btUserState = eGUSWaitEnterGame;
}

