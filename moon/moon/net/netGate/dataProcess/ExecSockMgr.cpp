#include "StdAfx.h"
#include "RunGateProto.h"
#include "ExecSockDataMgr.h"
#include "ExecSockMgr.h"



ExecSockMgr::ExecSockMgr()
{
	m_RunSockType = eExecSockUndefined;
	m_boStoping = TRUE;

	m_ListenSocket			= INVALID_SOCKET;
	m_BindAddr.sin_family	= AF_INET;
	m_BindAddr.sin_addr.s_addr	= 0;
	m_BindAddr.sin_port		= 0;
	m_pExecSockDataMgr		= NULL;
	m_SessionFullTick		= 0;
}

ExecSockMgr::~ExecSockMgr()
{
	Stop();
}

VOID ExecSockMgr::SocklogError(LPCSTR sErrorFn, LPCSTR sErrAPI, const INT nErrorCode)
{
	logError("%s Error happened %d on function \"%s\"", sErrorFn, nErrorCode, sErrAPI );
}

BOOL ExecSockMgr::InitAcceptSocket()
{
	m_ListenSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_IP );
	if ( m_ListenSocket == INVALID_SOCKET )
	{
		SocklogError( __FUNCTION__, "socket", WSAGetLastError() );
		return FALSE;
	}

	if ( SOCKET_ERROR == bind( m_ListenSocket, (struct sockaddr*)&m_BindAddr, sizeof(m_BindAddr) ) )
	{
		SocklogError( __FUNCTION__, "socket", WSAGetLastError() );
		return FALSE;
	}

	if ( SOCKET_ERROR == listen( m_ListenSocket, 5 ) )
	{
		SocklogError( __FUNCTION__, "listen", WSAGetLastError() );
		return FALSE;
	}

	return TRUE;
}

VOID ExecSockMgr::UninitAcceptSocket()
{
	if ( m_ListenSocket != INVALID_SOCKET )
	{
		closesocket( m_ListenSocket );
		m_ListenSocket = INVALID_SOCKET;
	}
}

VOID ExecSockMgr::NewSession()
{
	SOCKET nSocket;
	SOCKADDRIN sRemote;
	int nErr;
	socklen_t nRemoteSize;
	u_long uBlock;
	PRUNGATEUSERSESSION pSession;

	fd_set readfds, errfds;
	timeval tv;

	FD_ZERO( &readfds );
	FD_ZERO( &errfds );
	FD_SET( m_ListenSocket, &readfds );
	tv.tv_sec = 1;
	tv.tv_usec = 0;
	//检查是否有接入的socket
	nErr = select( int(m_ListenSocket+1), &readfds, NULL, &errfds, &tv );
	if ( nErr < 0 || FD_ISSET(m_ListenSocket, &errfds) )
	{
		SocklogError( __FUNCTION__, "select", WSAGetLastError() );
		return;
	}
	if ( nErr == 0 || !FD_ISSET(m_ListenSocket, &readfds) )
	{
		return;
	}
	if ( m_boStoping )
	{
		return;
	}
	
	nRemoteSize = sizeof(sRemote);
	nSocket = accept( m_ListenSocket, (sockaddr*)&sRemote, &nRemoteSize );
	if ( nSocket == INVALID_SOCKET )
	{
		SocklogError( __FUNCTION__, "accept", WSAGetLastError() );
		return;
	}

	//用户队列满后一段时间内不接受新连接
	if ( GetTickCount() < m_SessionFullTick )
	{
		closesocket( nSocket );
		return;
	}

	uBlock = 1;
	//设置非阻塞
#ifdef WINDOWS
	nErr = ioctlsocket( nSocket, FIONBIO, &uBlock );
	if ( SOCKET_ERROR == nErr )
	{
		closesocket( nSocket );
		SocklogError( __FUNCTION__, "ioctlsocket", WSAGetLastError() );
		return;
	}
#else
	int nFlag = fcntl(nSocket, F_GETFL, 0);
	if(0 > nFlag)
	{
		closesocket(nSocket);
		SocklogError( __FUNCTION__, "fcntl", errno );
	}
	if (fcntl(nSocket, F_SETFL, nFlag|O_NONBLOCK) < 0)
	{
		closesocket(nSocket);
		SocklogError( __FUNCTION__, "fcntl", errno );
	}
#endif
	
	if ( !(pSession = m_pExecSockDataMgr->NewSession( nSocket, sRemote )) )
	{
		closesocket( nSocket );
		SocklogError( __FUNCTION__, "用户队列已经满了。", ERROR_SUCCESS );
		m_SessionFullTick = GetTickCount() + 10 * 1000;
		return;
	}

//	AdjustSocketSendBufSize( nSocket, 32 * 1024 );
}

BOOL ExecSockMgr::AdjustSocketSendBufSize(SOCKET s, INT nSize)
{
	int nOldSize, nErr;
	socklen_t nSizeLen;
	nSizeLen = sizeof(nOldSize);
	nErr = getsockopt( s, SOL_SOCKET, SO_SNDBUF, (char*)&nOldSize, &nSizeLen );
	if ( nErr != SOCKET_ERROR )
	{
		if ( nOldSize < nSize ) 
		{
			nOldSize = nSize;
			if ( setsockopt( s, SOL_SOCKET, SO_SNDBUF, (char*)&nOldSize, nSizeLen ) == SOCKET_ERROR )
			{
				SocklogError( __FUNCTION__, "getsockopt", WSAGetLastError() );
				return FALSE;
			}
		}
	}
	else 
	{
				SocklogError( __FUNCTION__, "getsockopt", WSAGetLastError() );
		return FALSE;
	}

	return TRUE;
}

VOID ExecSockMgr::SetBindAddress(LPCSTR sAddress)
{
	m_BindAddr.sin_addr.s_addr = inet_addr(sAddress);
}

VOID ExecSockMgr::SetBindPort(INT nPort)
{
	m_BindAddr.sin_port = htons(nPort);
}

LPCSTR ExecSockMgr::GetBindAddress()
{
	return inet_ntoa(m_BindAddr.sin_addr);
}

INT ExecSockMgr::GetBindPort()
{
	return htons(m_BindAddr.sin_port);
}

EXECSOCKTYPE ExecSockMgr::GetRunSockType()
{
	return m_RunSockType;
}

ExecSockDataMgr* ExecSockMgr::GetDataProcesser()
{
	return m_pExecSockDataMgr;
}

ExecSockDataMgr* ExecSockMgr::SetDataProcesser(ExecSockDataMgr *pDataProcesser)
{
	ExecSockDataMgr *pOldProcess = m_pExecSockDataMgr;
	m_pExecSockDataMgr = pDataProcesser;
	return pOldProcess;
}

BOOL ExecSockMgr::InitBase()
{
#ifdef WINDOWS
	WSADATA WSAData;
	int nErr;

	nErr = WSAStartup( MAKEWORD(2, 2), &WSAData );
	if ( nErr )
	{
		SocklogError( __FUNCTION__, "WSAStartup", nErr );
		return FALSE;
	}
#endif
	return TRUE;
}

VOID ExecSockMgr::UninitBase()
{
#ifdef WINDOWS
	WSACleanup();
#endif
}

BOOL ExecSockMgr::Start()
{
	m_boStoping = FALSE;
	m_SessionFullTick = 0;
	return TRUE;
}

VOID ExecSockMgr::Stop()
{
	m_boStoping = TRUE;
}
