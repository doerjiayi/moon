#include "StdAfx.h"

using namespace common::time;
using namespace lib::container;

#ifdef WINDOWS
VOID STDCALL ExecSockDataMgr::RecvDataProcessRoutine(ExecSockDataMgr *pRunData)
#else
void* ExecSockDataMgr::RecvDataProcessRoutine(ExecSockDataMgr *pRunData)
#endif
{
	LPCRITICAL_SECTION pQueueLock;
	CBList<CNetPacket*>  *pRecvList;
	CNetPacket **pPacketList, *pPacket;
	PRUNGATEUSERSESSION pSession;
	INT_PTR nBufferCount;
	TICKCOUNT dwProcStartTick, dwLockDataTick, dwLockCheckTick;
	int nSessionIndex, nVerify;

	pQueueLock = &pRunData->m_RecvQueueLock;
	pRecvList  = pRunData->m_pRecvProcList;
	dwLockDataTick = dwLockCheckTick = _getTickCount();

	while ( !pRunData->m_boStoping )
	{
		dwProcStartTick = _getTickCount();

		//检查会话关闭
		if ( dwProcStartTick - dwLockCheckTick >= 5000 )
		{
			if ( pRunData->CheckCloseSessions( dwProcStartTick - dwLockCheckTick >= 10000 ) )
			{
				dwProcStartTick = dwLockCheckTick = _getTickCount();
			}
		}

		//调用例行执行函数
		pRunData->OnRecvThreadSingleRun(dwProcStartTick);

		//如果未能获得数据队列锁则让出本次CPU时间
		if ( !TryEnterCriticalSection( pQueueLock ) )
		{
			if ( dwProcStartTick - dwLockDataTick  < 60 )
			{
				moon::OS::osSleep(1);
				continue;
			}
			else
			{
				EnterCriticalSection( pQueueLock );
				dwProcStartTick = dwLockDataTick = _getTickCount();
			}
		}
		else dwLockDataTick = dwProcStartTick;

		//交换数据处理队列
		pRecvList = pRunData->m_pRecvAppendList;
		pRunData->m_pRecvAppendList = pRunData->m_pRecvProcList;
		pRunData->m_pRecvProcList = pRecvList;
		LeaveCriticalSection( pQueueLock );

		//数据接受自网络的用户数据包
		pPacketList = *pRecvList;
		nBufferCount = pRecvList->count();
		while ( nBufferCount > 0 )
		{
			pPacket = *pPacketList;
			nBufferCount--;
			pPacketList++;
			
			pPacket->setPosition(0);
			*pPacket >> nSessionIndex;
			*pPacket >> nVerify;
			if (nSessionIndex >= 0 && nSessionIndex < pRunData->m_SessionList.count())
				pSession = pRunData->m_SessionList[nSessionIndex];
			else pSession = NULL;
			//如果会话被关闭或效验过期则不予处理
			if ( pSession &&pSession->nSocket != INVALID_SOCKET && pSession->nVerifyIdx == nVerify 
				&& !pSession->boMarkToClose && !pSession->boRemoteClosed )
			{
				pSession->dwClientMsgTick = dwProcStartTick;
				pRunData->ProcessUserRecvPacket( pSession, pPacket->getOffsetPtr(), (int)pPacket->getAvaliableLength() );
				pSession->nRecvPacketCount++;
			}
			pPacket->freeBack();
		}
		pRecvList->clear();
		pRunData->m_dwLastProcUsrMsgTime = _getTickCount() - dwProcStartTick;

		moon::OS::osSleep(1);
	}
	ExitThread( 0 );
#ifdef LINUX
	return 0;
#endif
}
#ifdef WINDOWS
VOID STDCALL ExecSockDataMgr::SendDataProcessRoutine(PEXECDATASENDTHREAD pRunThread)
#else
void *ExecSockDataMgr::SendDataProcessRoutine(PEXECDATASENDTHREAD pRunThread)
#endif
{
	TICKCOUNT dwProcStartTick;
	ExecSockDataMgr *pRunData;
	int nLockSendBufQLockFail = 0;
	pRunData = pRunThread->pRunData;


	while ( !pRunData->m_boStoping )
	{
		dwProcStartTick = _getTickCount();

		if ( pRunData->CopyWaitSendBuffers( pRunThread, TRUE ) )
			nLockSendBufQLockFail = 0;
		else nLockSendBufQLockFail ++;

		pRunData->CheckSendSessionBuffers( pRunThread );

		//循环小于指定时间则休眠一次
		pRunThread->dwProcTick = _getTickCount() - dwProcStartTick;
		//if ( pRunThread->dwProcTick < 16 )

		if ( TRUE )
		{
			dwProcStartTick = _getTickCount();
			moon::OS::osSleep( 1 );
			pRunThread->dwSleepTick = _getTickCount() - dwProcStartTick;
		}
		
		else pRunThread->dwSleepTick = 0;
	}
	ExitThread( 0 );
}

ExecSockDataMgr::ExecSockDataMgr()
{
	m_nActiveUser = 0;
	m_boStoping	  = FALSE;
	m_boStarted	  = FALSE;
	
	sprintf( m_sGateName, "游戏网关%d", int(_getTickCount() % 100) );

	m_hProcRecvThread	= 0;
	ZeroMemory( m_SendThreads, sizeof(m_SendThreads) );

	m_nSendThreadCount	= 2;
	InitializeCriticalSection( &m_SessionLock );
	InitializeCriticalSection( &m_RecvQueueLock );
	m_pRecvAppendList = &m_RecvQueue[0];
	m_pRecvProcList	  = &m_RecvQueue[1];

	m_nUserVerify		= 1;
	m_dwProcessRecvSize = 0;

	InitSendThreadData();
}

ExecSockDataMgr::~ExecSockDataMgr()
{
	Stop();
	UninitSendThreadData();
	DeleteCriticalSection( &m_RecvQueueLock );
	DeleteCriticalSection( &m_SessionLock );
}

VOID ExecSockDataMgr::InitSessions()
{
	EnterCriticalSection( &m_SessionLock );
	m_SessionList.reserve(65536);
	LeaveCriticalSection( &m_SessionLock );
}

VOID ExecSockDataMgr::UninitSessions()
{
	EnterCriticalSection( &m_SessionLock );

	PRUNGATEUSERSESSION *pSessionList = m_SessionList;
	PRUNGATEUSERSESSION pSession;
	for (INT_PTR i=m_SessionList.count()-1; i>-1; --i)
	{
		pSession = pSessionList[i];
		if (pSession)
		{
			FreeSession(pSession);
		}
	}
	m_SessionList.clear();
	m_SessionAllocator.freeAll();
	LeaveCriticalSection( &m_SessionLock );
}

VOID ExecSockDataMgr::FreeRecvBuffers()
{
	INT_PTR i;
	CNetPacket **pPacketList;
	EnterCriticalSection( &m_RecvQueueLock );

	pPacketList = *m_pRecvAppendList;
	for ( i=m_pRecvAppendList->count()-1; i>-1; --i )
	{
		pPacketList[i]->freeBack();
	}
	m_pRecvAppendList->clear();

	
	pPacketList = *m_pRecvProcList;
	for ( i=m_pRecvProcList->count()-1; i>-1; --i )
	{
		pPacketList[i]->freeBack();
	}
	m_pRecvProcList->clear();

	LeaveCriticalSection( &m_RecvQueueLock );
}

VOID ExecSockDataMgr::FreeSendBuffers(PEXECDATASENDTHREAD pSendThread)
{
	INT_PTR i;
	CGateSendPacket **pBuffers;
	EnterCriticalSection( &pSendThread->SendQueueLock );

	pBuffers = *pSendThread->pSendAppendList;
	for ( i=pSendThread->pSendAppendList->count()-1; i>-1; --i )
	{
		pBuffers[i]->freeBack();
	}
	pSendThread->pSendAppendList->clear();

	
	pBuffers = *pSendThread->pSendProcList;
	for ( i=pSendThread->pSendProcList->count()-1; i>-1; --i )
	{
		pBuffers[i]->freeBack();
	}
	pSendThread->pSendProcList->clear();

	LeaveCriticalSection( &pSendThread->SendQueueLock );
}

inline VOID ExecSockDataMgr::FreeSession(PRUNGATEUSERSESSION pSession)
{
	if ( pSession->RecvBuf.lpBuffer )
	{
		free( pSession->RecvBuf.lpBuffer );
		pSession->RecvBuf.lpBuffer = NULL;
	}
	pSession->RecvBuf.nSize = pSession->RecvBuf.nOffset = 0;
	if ( pSession->SendBuf.lpBuffer )
	{
		free( pSession->SendBuf.lpBuffer );
		pSession->SendBuf.lpBuffer = NULL;
	}
	pSession->SendBuf.nSize = pSession->SendBuf.nOffset = 0;
}

BOOL ExecSockDataMgr::CopyWaitSendBuffers(PEXECDATASENDTHREAD pSendThread, BOOL boForceCopy)
{
	CGateSendPacket *pSendPacket, **ppPacketList;
	CBList<CGateSendPacket*> *pBufferList;
	PRUNGATEUSERSESSION pSession;
	INT_PTR nCount;
	common::NetPacketHeader *pPackHdr;
	int nSize, nTotalSize, nAppendSize, nPacketSize;
	TICKCOUNT dwMsgTick;

	if ( !boForceCopy )
		boForceCopy = TryEnterCriticalSection( &pSendThread->SendQueueLock );
	else EnterCriticalSection( &pSendThread->SendQueueLock );

	if ( boForceCopy )
	{
		pBufferList = pSendThread->pSendAppendList;
		pSendThread->pSendAppendList = pSendThread->pSendProcList;
		pSendThread->pSendProcList = pBufferList;
		LeaveCriticalSection( &pSendThread->SendQueueLock );

		nCount = pBufferList->count();
		if ( nCount > 0 )
		{
			dwMsgTick = _getTickCount();
			ppPacketList = (CGateSendPacket**)*pBufferList;
			nTotalSize = 0;
			nAppendSize = 0;
			do
			{
				pSendPacket = *ppPacketList;
				ppPacketList++;
				nCount--;

				nPacketSize = (int)pSendPacket->getLength();
				if (pSendPacket->m_nUserIndex < m_SessionList.count())
					pSession = m_SessionList[pSendPacket->m_nUserIndex];
				else pSession = NULL;

				if ( pSession && pSession->nSocket != INVALID_SOCKET && !pSession->boMarkToClose 
					&& !pSession->boRemoteClosed && pSession->nVerifyIdx == pSendPacket->m_nVerify )
				{
					//检测并保留数据包空间
					nSize = pSession->SendBuf.nOffset + sizeof(*pPackHdr) + nPacketSize;
					if ( pSession->SendBuf.nSize < nSize )
					{
						nSize = (nSize / SESSION_DATAGROW_SIZE + 1) * SESSION_DATAGROW_SIZE;
						pSession->SendBuf.nSize = nSize;
						pSession->SendBuf.lpBuffer = (char*)realloc( pSession->SendBuf.lpBuffer, nSize );
					}
					//写入包头
					pPackHdr = (common::NetPacketHeader*)&pSession->SendBuf.lpBuffer[pSession->SendBuf.nOffset];
					pPackHdr->dwIdent = common::NetPacketHeader::NetPacketHeaderIdent;
					pPackHdr->wPacketSize = nPacketSize;
					pPackHdr->wVerification = 0;
					pSession->SendBuf.nOffset += sizeof(*pPackHdr);
					nAppendSize += sizeof(*pPackHdr);
					//写入包数据
					memcpy( &pSession->SendBuf.lpBuffer[pSession->SendBuf.nOffset], pSendPacket->getMemoryPtr(), nPacketSize );
					pSession->SendBuf.nOffset += nPacketSize;
					pSession->dwServerMsgTick = dwMsgTick;
					nAppendSize += nPacketSize;
				}
				nTotalSize += nPacketSize;
				pSendPacket->freeBack();
			}
			while ( nCount > 0 );
			pBufferList->clear();

			InterlockedExchangeAdd( (LONG*)&m_dwWaitSendUserSize, nAppendSize );
			InterlockedExchangeAdd( (LONG*)&m_dwWaitSendQueueSize, -nTotalSize );
		}
	}

	return boForceCopy;
}

VOID ExecSockDataMgr::GotError(LPCSTR sErrFn, LPCSTR sErrApi, int nErr)
{
	logError("%s Got Error %d on api \"%s\"", sErrFn, nErr, sErrApi );
}

VOID ExecSockDataMgr::InitSendThreadData()
{
	int i;

	for ( i=0; i<m_nSendThreadCount; ++i )
	{
		InitializeCriticalSection( &m_SendThreads[i].SendQueueLock );
		m_SendThreads[i].pRunData = this;
		m_SendThreads[i].nThreadIdx = i;
		m_SendThreads[i].boSendEWouldBlock = false;
		m_SendThreads[i].boSendFewBuffer = false;
		m_SendThreads[i].pSendAppendList = new CBList<CGateSendPacket*>();
		m_SendThreads[i].pSendProcList = new CBList<CGateSendPacket*>();
		m_SendThreads[i].pSendPacketPool = new CGateSendPacketPool();
	}
}

VOID ExecSockDataMgr::UninitSendThreadData()
{
	int i;

	for ( i=0; i<m_nSendThreadCount; ++i )
	{
		SafeDelete( m_SendThreads[i].pSendAppendList );
		SafeDelete( m_SendThreads[i].pSendProcList );
		SafeDelete( m_SendThreads[i].pSendPacketPool );
		DeleteCriticalSection( &m_SendThreads[i].SendQueueLock );
	}
}

VOID ExecSockDataMgr::CloseAllSessions(BOOL boForceClose)
{
	INT_PTR i;
	TICKCOUNT dwCurTick;
	PRUNGATEUSERSESSION pSession;

	EnterCriticalSection( &m_SessionLock );
	EnterCriticalSection( &m_RecvQueueLock );
	for ( i=0; i<m_nSendThreadCount; ++i )
	{
		EnterCriticalSection( &m_SendThreads[i].SendQueueLock );
	}
	moon::OS::osSleep( 1000 );//休眠以等待数据接收以及各发送线程被阻塞

	dwCurTick = _getTickCount();
	for ( i=m_SessionList.count()-1; i>-1; --i )
	{
		pSession = m_SessionList[i];
		if ( pSession && pSession->nSocket != INVALID_SOCKET )
		{
			if ( boForceClose )
			{
				m_SessionList[i] = NULL;

				PostEngineClosePlayer( pSession );
				closesocket( pSession->nSocket );
				pSession->boMarkToClose = true;
				pSession->boRemoteClosed = true;
				pSession->dwCloseTick = 0;
				pSession->nSocket = INVALID_SOCKET;
				pSession->nVerifyIdx = 0;
				FreeSession(pSession);
			}
			else CloseSession( pSession );
		}
	}

	for ( i=0; i<m_nSendThreadCount; ++i )
	{
		LeaveCriticalSection( &m_SendThreads[i].SendQueueLock );
	}
	LeaveCriticalSection( &m_RecvQueueLock );
	LeaveCriticalSection( &m_SessionLock );
}

VOID ExecSockDataMgr::CancelRemainSendSessionBuffers()
{
	CGateSendPacket *pSendPacket, **ppPacketList;
	CBList<CGateSendPacket*> *pBufferList;
	INT_PTR i, nCount;
	int nTotalSize;

	nTotalSize = 0;
	for ( i=0; i<m_nSendThreadCount; ++i )
	{
		EnterCriticalSection( &m_SendThreads[i].SendQueueLock );
		
		pBufferList = m_SendThreads[i].pSendProcList;
		nCount = pBufferList->count();
		if ( nCount )
		{
			ppPacketList = (CGateSendPacket**)*pBufferList;
			do
			{
				pSendPacket = *ppPacketList;
				ppPacketList++;
				nCount--;
				nTotalSize += (int)pSendPacket->getLength();
				pSendPacket->freeBack();
			}
			while ( nCount > 0 );
			pBufferList->clear();
		}

		pBufferList = m_SendThreads[i].pSendAppendList;
		nCount = pBufferList->count();
		if ( nCount )
		{
			ppPacketList = (CGateSendPacket**)(*pBufferList);
			do
			{
				pSendPacket = *ppPacketList;
				ppPacketList++;
				nCount--;
				nTotalSize += (int)pSendPacket->getLength();
				pSendPacket->freeBack();
			}
			while ( nCount > 0 );
			pBufferList->clear();
		}

		LeaveCriticalSection( &m_SendThreads[i].SendQueueLock );
	}

	InterlockedExchangeAdd( (LONG*)&m_dwWaitSendQueueSize, -nTotalSize );
}

BOOL ExecSockDataMgr::CheckCloseSessions(BOOL boForceCheck)
{
	static const DWORD dwCloseIdleSessionLong = 10 * 60 * 1000;
	BOOL boResult;
	TICKCOUNT dwCurTick;
	INT_PTR i;
	PRUNGATEUSERSESSION pSession;

	if ( boForceCheck )
	{
		EnterCriticalSection( &m_SessionLock );
		boResult = TRUE;
	}
	else  boResult = TryEnterCriticalSection( &m_SessionLock );

	if ( boResult )
	{
		dwCurTick = _getTickCount();

		for ( i=m_SessionList.count()-1; i>-1; --i )
		{
			pSession = m_SessionList[i];
			if (!pSession)
				continue;
			if ( pSession->boMarkToClose || pSession->boRemoteClosed )
			{
				//加上pSession->dwCloseTick非0判断，防止内存错误
				//可能的原因是标记pSession->boMarkToClose或pSession->boRemoteClosed为true的线程尚未来得及
				//给pSession->dwCloseTick赋值，而此线程恰好已经执行到此处对pSession的资源进行释放，从而
				//造成内存错误。
				if ( pSession->dwCloseTick && dwCurTick - pSession->dwCloseTick >= 10 * 1000 )
				{
					m_SessionList[i] = NULL;
					LOCK_SESSION_SEND( pSession );
					pSession->nSocket = INVALID_SOCKET;
					pSession->nVerifyIdx = 0;
					FreeSession(pSession);

					pSession->boMarkToClose = false;
					pSession->boRemoteClosed = false;
					pSession->dwCloseTick = 0;
					UNLOCK_SESSION_SEND( pSession );
				}
			}
			else if ( pSession->nSocket != INVALID_SOCKET )
			{
				if (  (dwCurTick > pSession->dwClientMsgTick && dwCurTick - pSession->dwClientMsgTick >= dwCloseIdleSessionLong)
					||(dwCurTick > pSession->dwServerMsgTick && dwCurTick - pSession->dwServerMsgTick >= dwCloseIdleSessionLong)
					)
				{
					logWarn("关闭了一个较长时间处于非活动状态的会话。");
					CloseSession( pSession );
				}
			}
		}
		LeaveCriticalSection( &m_SessionLock );
	}

	return boResult;
}

VOID ExecSockDataMgr::CheckSendSessionBuffers(PEXECDATASENDTHREAD pSendThread)
{
	int nErr, nRemainSize;
	char *pBuffer;
	PRUNGATEUSERSESSION *pSessionList = m_SessionList;
	PRUNGATEUSERSESSION pSession;

	pSendThread->boSendEWouldBlock = false;
	pSendThread->boSendFewBuffer = false;

	INT_PTR nCount = m_SessionList.count();
	for ( INT_PTR nIndex = pSendThread->nThreadIdx; nIndex < nCount; nIndex += m_nSendThreadCount )
	{
		pSession = pSessionList[nIndex];
		if (!pSession)
			continue;
		if ( pSession->nSocket != INVALID_SOCKET && !pSession->boMarkToClose && !pSession->boRemoteClosed )
		{
			if ( !pSession->boSendAvaliable )
			{
				if ( _getTickCount() >= pSession->dwSendTimeOut )//等到发送的时间再发送
				{
					pSession->boSendAvaliable = true;
					pSession->dwSendTimeOut = 0;
				}
				else continue;
			}

			if ( TRYLOCK_SESSION_SEND( pSession ) )//发送目前没有加锁
			{
				nRemainSize = pSession->SendBuf.nOffset;
				if ( nRemainSize > 4096 * 1024 )
				{
					CloseSession( pSession );
					nRemainSize = 0;
					logWarn("关闭了一个发送数据队列大于4MB的连接。");
				}
				if ( nRemainSize )
				{
					pBuffer = pSession->SendBuf.lpBuffer;
#ifdef LINUX
					nErr = send( pSession->nSocket, pBuffer, nRemainSize, MSG_NOSIGNAL);
#else
					nErr = send( pSession->nSocket, pBuffer, nRemainSize, 0 );
#endif
					if ( nErr > 0 )
					{
						pSession->nSendPacketCount++;
						InterlockedExchangeAdd( (LONG*)&m_dwWaitSendUserSize, -nErr );
						InterlockedExchangeAdd( (LONG*)&m_dwSendUserSize, nErr );
						if ( nErr < nRemainSize )
						{
							pSendThread->boSendFewBuffer = true;
							memcpy( pBuffer, &pBuffer[nErr], nRemainSize - nErr );
							nRemainSize -= nErr;
							pBuffer[nRemainSize] = 0;
							pSession->SendBuf.nOffset = nRemainSize;
						}
						else
						{
							pBuffer[0] = 0;
							pSession->SendBuf.nOffset = 0;
						}
					}
					else if ( !nErr || WSAGetLastError() != WSAEWOULDBLOCK )
					{
						pSession->boRemoteClosed = true;
						CloseSession( pSession );
						InterlockedExchangeAdd( (LONG*)&m_dwWaitSendUserSize, -nRemainSize );
						InterlockedExchangeAdd( (LONG*)&m_dwSendUserSize, nRemainSize );
						pBuffer[0] = 0;
						pSession->SendBuf.nOffset = 0;
					}
					else
					{
						pSession->boSendAvaliable = false;
						pSession->dwSendTimeOut = _getTickCount() + RUNGATE_SENDCHECK_TIMEOUT;
						pSendThread->boSendEWouldBlock = true;
					}
				}
				UNLOCK_SESSION_SEND( pSession );
			}
		}
		else
		{
			//会话关闭后减少待发送数据统计值
			if ( (nRemainSize = pSession->SendBuf.nOffset) )
			{
				InterlockedExchangeAdd( (LONG*)&m_dwWaitSendUserSize, -nRemainSize );
				pSession->SendBuf.nOffset = 0;
			}
		}
	}
}

VOID ExecSockDataMgr::ProcessUserRecvPacket(PRUNGATEUSERSESSION pSession, char *pBuffer, int nBufferSize)
{
	static const int PacketSizeLimit = 512;
	common::NetPacketHeader *pPackHdr;
	int nRemainSize;

	InterlockedExchangeAdd( (LONG*)&m_dwProcessRecvSize, nBufferSize );

	if (pSession->RecvBuf.lpBuffer && pSession->RecvBuf.nOffset > 0)
	{
		pPackHdr = (common::NetPacketHeader*)pSession->RecvBuf.lpBuffer;
		nRemainSize = pPackHdr->wPacketSize - (pSession->RecvBuf.nOffset - sizeof(*pPackHdr));
		if (nBufferSize >= nRemainSize)
		{
			pSession->RecvBuf.appendBuffer(pBuffer, nRemainSize);
			pBuffer += nRemainSize;
			nBufferSize -= nRemainSize;
			if (!ValidateUserRecvPacket(pSession, pSession->RecvBuf.lpBuffer + sizeof(*pPackHdr), pPackHdr->wPacketSize, pPackHdr->wVerification))
				return;
			DispatchUserRecvPacket(pSession, pSession->RecvBuf.lpBuffer + sizeof(*pPackHdr), pPackHdr->wPacketSize);
			pSession->RecvBuf.nOffset = 0;
		}
		else
		{
			pSession->RecvBuf.appendBuffer(pBuffer, nBufferSize);
			return;
		}
	}

	while (nBufferSize > 0)
	{
		pPackHdr = (common::NetPacketHeader*)pBuffer;
		//如果数据包起始位置不是有效的包头，则重新搜索包头
		if (pPackHdr->dwIdent != common::NetPacketHeader::NetPacketHeaderIdent)
		{
			logWarn("[Gate] invalid packet header, researching...");
			do 
			{
				pBuffer++;
				nBufferSize--;
				if (nBufferSize <(int)sizeof(*pPackHdr))
				{
					logWarn("[Gate] can not research packet header, packet droped");
					return;
				}
				pPackHdr = (common::NetPacketHeader*)pBuffer;
			}
			while (pPackHdr->dwIdent != common::NetPacketHeader::NetPacketHeaderIdent);
		}
		pBuffer += sizeof(*pPackHdr);
		nBufferSize -= sizeof(*pPackHdr);

		//数据包过大(512)则直接丢弃
		if (pPackHdr->wPacketSize > PacketSizeLimit)
		{
			logWarn("[Gate] drop client packet over-size(%d)", pPackHdr->wPacketSize);
			CloseSession(pSession);
			return;
		}

		if (nBufferSize >= pPackHdr->wPacketSize)
		{
			if (!ValidateUserRecvPacket(pSession, pBuffer, pPackHdr->wPacketSize, pPackHdr->wVerification))
				break;
			DispatchUserRecvPacket(pSession, pBuffer, pPackHdr->wPacketSize);
			pBuffer += pPackHdr->wPacketSize;
			nBufferSize -= pPackHdr->wPacketSize;
		}
		else
		{
			pSession->RecvBuf.appendBuffer(pPackHdr, sizeof(*pPackHdr) + nBufferSize);
			break;
		}
	}
}

BOOL ExecSockDataMgr::ValidateUserRecvPacket(PRUNGATEUSERSESSION pSession, char *pBuffer, int nBufferSize, unsigned short wVerification)
{
#if 0
	unsigned short wVerify = calcPacketDataVerify(pBuffer, nBufferSize, pSession->wPacketVerifyKey);
	if (wVerify != wVerification)
	{
		OutputMsgWarn(_T("[Gate] close client connection(%s) invalid packet verify"), inet_ntoa(pSession->SockAddr.sin_addr));
		CloseSession(pSession);
		return FALSE;
	}
#endif
	return TRUE;
}

VOID ExecSockDataMgr::PostEngineClosePlayer(PRUNGATEUSERSESSION pSession)
{
}

VOID ExecSockDataMgr::OnRecvThreadSingleRun(TICKCOUNT dwCurrTick)
{

}

VOID ExecSockDataMgr::DispatchUserRecvPacket(PRUNGATEUSERSESSION pSession, char *pBuffer, int nBufferSize)
{

}

INT ExecSockDataMgr::GetActiveUserCount()
{
	return m_nActiveUser;
}

INT ExecSockDataMgr::GetSendThreadCount()
{
	return m_nSendThreadCount;
}

VOID ExecSockDataMgr::SetSendThreadCount(INT ThreadCount)
{
	if ( !m_boStarted && ThreadCount > 0 && ThreadCount <= RUNDATA_MAX_SENDTHREAD )
	{
		m_nSendThreadCount = ThreadCount;
	}
}

PEXECDATASENDTHREAD	ExecSockDataMgr::GetSendThreadInfo(INT ThreadIdx)
{
	if ( ThreadIdx >= 0 && ThreadIdx < RUNDATA_MAX_SENDTHREAD )
	{
		if ( m_SendThreads[ThreadIdx].hThread )
			return &m_SendThreads[ThreadIdx];
	}
	return NULL;
}

BOOL ExecSockDataMgr::Start()
{
	int i;

	m_boStoping = FALSE;

	m_dwWaitSendUserSize = 0;
	m_dwWaitSendQueueSize = 0;
	m_dwLastProcUsrMsgTime = 0;
	m_dwLastProcSrvMsgTime = 0;
	m_dwLastRecvSrvMsgTime = 0;
	m_dwRecvSeverSize = 0;
	m_dwSendUserSize = 0;
	m_dwProcSrvThreadSleep = 0;
	m_dwSendQueueSize = 0;

	//初始化会话队列
	InitSessions();

#ifdef WINDOWS
	//创建用户数据处理线程
	m_hProcRecvThread = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)RecvDataProcessRoutine, this, 0, NULL );
	if ( !m_hProcRecvThread )
	{
		GotError( __FUNCTION__, "CreateThread", GetLastError() );
		return FALSE;
	}
#else
	if( 0 != pthread_create(&m_hProcRecvThread, 0, (LPTHREAD_START_ROUTINE)RecvDataProcessRoutine,  this))
	{
		GotError( __FUNCTION__, "CreateThread", errno );
		return false;
	}
#endif

	//创建用户数据发送线程
	for ( i=0; i<m_nSendThreadCount; ++i )
	{
		m_SendThreads[i].pRunData = this;
		m_SendThreads[i].nThreadIdx = i;
		m_SendThreads[i].boSendEWouldBlock = false;
		m_SendThreads[i].boSendFewBuffer = false;
#ifdef WINDOWS
		m_SendThreads[i].hThread = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)SendDataProcessRoutine, &m_SendThreads[i], 0, &m_SendThreads[i].dwThreadId );
		if ( !m_SendThreads[i].hThread )
		{
			GotError( __FUNCTION__, "CreateThread", GetLastError() );
			return FALSE;
		}
#else
		if(0 != pthread_create(&(m_SendThreads[i].hThread), 0, (LPTHREAD_START_ROUTINE)(&SendDataProcessRoutine), &m_SendThreads[i]))
		{
			GotError( __FUNCTION__, "CreateThread", errno );
			return false;
		}
#endif
	}

	m_boStarted = TRUE;
	return TRUE;
}

VOID ExecSockDataMgr::Stop()
{
	int i;
	m_boStoping = TRUE;

	CloseThread( m_hProcRecvThread );
	for ( i=0; i<m_nSendThreadCount; ++i )
	{
		if ( m_SendThreads[i].hThread )
		{
			CloseThread( m_SendThreads[i].hThread );
			FreeSendBuffers( &m_SendThreads[i] );
		}
	}

	FreeRecvBuffers();

	//FreeSendBuffers();

	CancelRemainSendSessionBuffers();

	CloseAllSessions( TRUE );

	UninitSessions();

	m_boStarted = FALSE;
}

PRUNGATEUSERSESSION ExecSockDataMgr::NewSession(SOCKET nSocket, SOCKADDRIN RemoteAddr)
{
	PRUNGATEUSERSESSION pNewSession = NULL;

	EnterCriticalSection( &m_SessionLock );
	pNewSession = m_SessionAllocator.allocObject();
	pNewSession->nSocket = INVALID_SOCKET;
	pNewSession->SendBuf.nOffset = 0;
	pNewSession->dwCloseTick = 0;
	pNewSession->boMarkToClose = false;
	pNewSession->boRemoteClosed = false;

	PRUNGATEUSERSESSION *pSessionList = m_SessionList;
	for (INT_PTR i=m_SessionList.count()-1; i>-1; --i)
	{
		if (!pSessionList[i])
		{
			pSessionList[i] = pNewSession;
			pNewSession->nIndex = (int)i;
			pSessionList = NULL;
			break;
		}
	}
	if (pSessionList)//找不到空闲的位置，就添加到最后面，需要拓展列表的长度
	{
		pNewSession->nIndex = (int)m_SessionList.add(pNewSession);
	}
	LeaveCriticalSection( &m_SessionLock );

	if ( pNewSession )//内存地址可能改变
	{
		pNewSession->SockAddr		= RemoteAddr;
		pNewSession->nPlayerIndex	= -1;
		pNewSession->pPlayer			= NULL;
		pNewSession->wPacketVerifyKey= 0;
		pNewSession->nRecvPacketCount=0;
		pNewSession->nSendPacketCount=0;
		pNewSession->btUserState		= eGUSWaitRequestKey;
		pNewSession->boMarkToClose  = false;
		pNewSession->boRemoteClosed = false;
		pNewSession->boSendAvaliable= true;
		pNewSession->boRecvAvaliable= false;//目前epoll模型的才使用
		pNewSession->dwSendTimeOut	= 0;
		pNewSession->dwCloseTick		= 0;
		pNewSession->dwConnectTick	= _getTickCount();	
		pNewSession->dwClientMsgTick= pNewSession->dwConnectTick;
		pNewSession->dwServerMsgTick= pNewSession->dwConnectTick;
		pNewSession->dwMsgIntervalTick = pNewSession->dwConnectTick;
		pNewSession->nVerifyIdx		= InterlockedIncrement( (LONG*)&m_nUserVerify ); 
		pNewSession->nIntervalMsgCount = 0;
		pNewSession->nAccountId		= 0;
		pNewSession->sAccount[0]		= 0;
		pNewSession->PlayerId.llid	= 0;
		pNewSession->sCharName[0]	= 0;
		if ( !pNewSession->RecvBuf.lpBuffer )
		{ 
			pNewSession->RecvBuf.nSize = SESSION_RECV_BUFSIZE ;
			pNewSession->RecvBuf.lpBuffer = (char*)malloc( pNewSession->RecvBuf.nSize );
		}
		pNewSession->RecvBuf.nOffset = 0;

		if ( !pNewSession->SendBuf.lpBuffer )
		{ 
			pNewSession->SendBuf.nSize = SESSION_SEND_BUFSIZE ;
			pNewSession->SendBuf.lpBuffer = (char*)malloc( pNewSession->SendBuf.nSize );
		}
		pNewSession->SendBuf.nOffset = 0;
		//最后设置会话的nSocket成员数据，
		//以防止其他线程通过nSocket != INVALID_SOCKET判断后对一个尚为初始化完毕的会话进行操作！
		pNewSession->nSocket = nSocket;

		m_nActiveUser++;	//增加活动用户计数
	}
	return pNewSession;
}

PRUNGATEUSERSESSION ExecSockDataMgr::setRecvSession(SOCKET nSocket)
{
	PRUNGATEUSERSESSION pSession = NULL;
	PRUNGATEUSERSESSION pSetSession = NULL;//设置的session
	PRUNGATEUSERSESSION *pSessionList = m_SessionList;
	for (INT_PTR i=m_SessionList.count()-1; i>-1; --i)
	{
		if ((pSession = pSessionList[i])&& (pSession->nSocket != INVALID_SOCKET && \
				!pSession->boMarkToClose && !pSession->boRemoteClosed )&&\
				(pSession->nSocket == nSocket))
		{
			pSetSession = pSession;
			pSetSession->boRecvAvaliable = true;
			break;
		}
	}
	return pSetSession;
}

VOID ExecSockDataMgr::AddRecvBuf(PRUNGATEUSERSESSION pSession, ULONG_PTR nVerify, char *pBuffer, int BufferSize)
{
	if ( pSession->nSocket == INVALID_SOCKET || pSession->boMarkToClose ||\
			pSession->boRemoteClosed || !nVerify || pSession->nVerifyIdx != (int)nVerify )
		return;

	//--pSession->boSendAvaliable = true;
	CNetPacket *pPacket = m_RecvPacketPool.allocPacket();
	*pPacket << (int)pSession->nIndex;
	*pPacket << (int)nVerify;
	pPacket->writeBuf(pBuffer, BufferSize);

	EnterCriticalSection( &m_RecvQueueLock );
	m_pRecvAppendList->add( pPacket );
	LeaveCriticalSection( &m_RecvQueueLock );
}


VOID ExecSockDataMgr::CloseSession(PRUNGATEUSERSESSION pSession, BOOL boClosedByServer)
{
	int nSocket;

	if ( !pSession->boMarkToClose && pSession->nSocket != INVALID_SOCKET )
	{
		if (!boClosedByServer)
			PostEngineClosePlayer(pSession);
		pSession->boMarkToClose = true;

		nSocket = (int)pSession->nSocket;
		pSession->nSocket = INVALID_SOCKET;
		pSession->pPlayer = NULL;
		closesocket( nSocket );

		pSession->dwCloseTick = _getTickCount();
		pSession->nVerifyIdx = 0;
		m_nActiveUser--;
	}
}

void ExecSockDataMgr::ClosePlayer(int nUserIndex, int nUserVerify, CPlayer *pPlayer, int nPlayerIndex)
{
	PRUNGATEUSERSESSION pSession = NULL;
	if (nUserIndex >= 0 && nUserIndex < m_SessionList.count())
		pSession = m_SessionList[nUserIndex];
	
	if (pSession && pSession->nVerifyIdx == nUserVerify 
		&& pSession->pPlayer == pPlayer && pSession->nPlayerIndex == nPlayerIndex)
	{
		CloseSession(pSession, TRUE);
	}
}

CGateSendPacket& ExecSockDataMgr::AllocSendPacket(const int nUserIndex)
{
	PRUNGATEUSERSESSION pSession = m_SessionList[nUserIndex];
	assert(pSession != NULL);
	PEXECDATASENDTHREAD pSendThread = &m_SendThreads[nUserIndex % m_nSendThreadCount];
	CGateSendPacket *pPacket = pSendThread->pSendPacketPool->allocPacket();
	pPacket->setSendInfo(pSendThread, nUserIndex, pSession->nVerifyIdx);
	return *pPacket;
}

BOOL ExecSockDataMgr::SetSessionPlayer(common::SERVERUSERHANDLE *pUserHandle, CPlayer *pPlayer, int pPlayerIndex)
{
	PRUNGATEUSERSESSION pSession = NULL;
	if (pUserHandle->wUserIndex < m_SessionList.count())
		pSession = m_SessionList[pUserHandle->wUserIndex];
	
	if (pSession && !pSession->boMarkToClose && !pSession->boRemoteClosed 
		&& !pSession->pPlayer
		&& pUserHandle->llSocket == (uint64)pSession->nSocket
		&& pUserHandle->nVerify == pSession->nVerifyIdx)
	{
		pSession->pPlayer = pPlayer;
		pSession->nPlayerIndex = pPlayerIndex;
		pSession->btUserState = eGUSInGame;
		return TRUE;
	}
	return FALSE;
}

