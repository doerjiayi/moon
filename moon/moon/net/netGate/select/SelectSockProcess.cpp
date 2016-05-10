#include "StdAfx.h"

#ifdef WINDOWS
VOID CSelectRunSockProcesser::SelectThreadRoutine(CSelectRunSockProcesser *pRunSock)
#else
void *CSelectRunSockProcesser::SelectThreadRoutine(CSelectRunSockProcesser *pRunSock)
#endif
{
	int nLoop = 0;

	while ( !pRunSock->m_boStoping )
	{
		pRunSock->SelectSessions();

		nLoop++;
		if ( nLoop > 32 )
		{
			moon::OS::osSleep( 1 );
			nLoop = 0;
		}
	}
	ExitThread( 0 );
}
#ifdef WINDOWS
VOID CSelectRunSockProcesser::AcceptThreadRoutine(CSelectRunSockProcesser *pRunSock)
#else
void *CSelectRunSockProcesser::AcceptThreadRoutine(CSelectRunSockProcesser *pRunSock)
#endif
{
	while ( !pRunSock->m_boStoping )
	{
		pRunSock->NewSession();
	}
	ExitThread( 0 );
}

CSelectRunSockProcesser::CSelectRunSockProcesser():ExecSockMgr()
{
	m_RunSockType	= eExecSockSelect;
	m_hSelectThread = 0;
	m_hAcceptThread = 0;
}

CSelectRunSockProcesser::~CSelectRunSockProcesser()
{
	Stop();
}


INT CSelectRunSockProcesser::SelectSessions()
{
	INT_PTR nSessionCount = m_pExecSockDataMgr->GetSessionCount();
	PRUNGATEUSERSESSION*pSessionList = m_pExecSockDataMgr->GetSessionList();
	PRUNGATEUSERSESSION pSelectSessionList[FD_SETSIZE];
	PRUNGATEUSERSESSION pSession;
	fd_set readfds, errfds;
	timeval tv;
	int nErr, nFdSSCount, nResult;
	const int RecvBufSize = 1024;
	char sRecvBuf[RecvBufSize];

	FD_ZERO( &readfds );
	FD_ZERO( &errfds );

	tv.tv_sec = 0;
	tv.tv_usec = 10;
	nFdSSCount = 0;
	nResult = 0;
	SOCKET maxFD = 0;

	while ( nFdSSCount < FD_SETSIZE )
	{
		if (m_nSessionIndex >= nSessionCount)
		{
			m_nSessionIndex = 0;
			break;
		}

		pSession = pSessionList[m_nSessionIndex];
		m_nSessionIndex++;
		if ( pSession && pSession->nSocket != INVALID_SOCKET && !pSession->boMarkToClose && !pSession->boRemoteClosed )
		{
			FD_SET( pSession->nSocket, &readfds );
			maxFD = max(maxFD, pSession->nSocket);
			pSelectSessionList[nFdSSCount] = pSession;//找到会话空位
			nFdSSCount++;
			nResult++;
		}
	}

	if ( nFdSSCount > 0 )
	{
		nErr = select( int(maxFD + 1), &readfds, NULL, &errfds, &tv );
		if ( nErr > 0 )
		{
			while ( nFdSSCount > 0 )
			{
				nFdSSCount--;
				pSession = pSelectSessionList[nFdSSCount];
				if ( FD_ISSET( pSession->nSocket, &errfds ) )
				{
					pSession->boRemoteClosed = true;
					m_pExecSockDataMgr->CloseSession( pSession );
				}
				else if ( FD_ISSET( pSession->nSocket, &readfds ) )
				{
					nErr = recv( pSession->nSocket, sRecvBuf, RecvBufSize, 0 );
					if ( nErr > 0 )
					{
						m_pExecSockDataMgr->AddRecvBuf( pSession, pSession->nVerifyIdx, sRecvBuf, nErr );
					}
					else
					{
						pSession->boRemoteClosed = true;
						m_pExecSockDataMgr->CloseSession( pSession );
					}
				}
			}
		}
		else if ( nErr == SOCKET_ERROR )
		{
			SocklogError( __FUNCTION__, "select", WSAGetLastError() );
		}
	}

	return nResult;
}

BOOL CSelectRunSockProcesser::StartSelectThreads()
{
#ifdef WINDOWS
	m_hSelectThread = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)SelectThreadRoutine, this, 0, NULL );
	if ( !m_hSelectThread )
	{
		SocklogError( __FUNCTION__, "CreateThread", GetLastError() );
		return FALSE;
	}

	m_hAcceptThread = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)AcceptThreadRoutine, this, 0, NULL );
	if ( !m_hSelectThread )
	{
		SocklogError( __FUNCTION__, "CreateThread", GetLastError() );
		return FALSE;
	}
#else
	if(0 != pthread_create(&m_hSelectThread, 0, (LPTHREAD_START_ROUTINE)(&SelectThreadRoutine), this))
	{
		SocklogError( __FUNCTION__, "CreateThread", errno );
		return false;
	}

	if(0 != pthread_create(&m_hSelectThread, 0, (LPTHREAD_START_ROUTINE)(&AcceptThreadRoutine), this))
		{
			SocklogError( __FUNCTION__, "CreateThread", errno );
			return false;
		}
#endif

	return true;
}

VOID CSelectRunSockProcesser::StopSelectThreads()
{
	CloseThread( m_hAcceptThread );
	CloseThread( m_hSelectThread );
}

BOOL CSelectRunSockProcesser::Start()
{
	if ( !INHERITED::Start() )
		return FALSE;
	m_nSessionIndex = 0;
	return InitAcceptSocket() && StartSelectThreads();
}

VOID CSelectRunSockProcesser::Stop()
{
	INHERITED::Stop();
	UninitAcceptSocket();
	StopSelectThreads();
}

