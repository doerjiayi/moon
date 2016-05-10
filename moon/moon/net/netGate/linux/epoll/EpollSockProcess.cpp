#include "StdAfx.h"

#ifdef WINDOWS
VOID CEpollRunSockProcesser::EpollThreadRoutine(CEpollRunSockProcesser *pRunSock)
#else
void *CEpollRunSockProcesser::EpollThreadRoutine(CEpollRunSockProcesser *pRunSock)
#endif
{
	int nLoop = 0;

	while ( !pRunSock->m_boStoping )
	{
		pRunSock->EpollSessions();

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
VOID CEpollRunSockProcesser::AcceptThreadRoutine(CEpollRunSockProcesser *pRunSock)
#else
void *CEpollRunSockProcesser::AcceptThreadRoutine(CEpollRunSockProcesser *pRunSock)
#endif
{
	while ( !pRunSock->m_boStoping )
	{
		pRunSock->NewSession();
	}
	ExitThread( 0 );
}

CEpollRunSockProcesser::CEpollRunSockProcesser():ExecSockMgr()
{
	m_RunSockType	= eExecSockEpoll;
	m_hEpollThread = 0;
	m_hAcceptThread = 0;
	m_curfds = 0;
	m_kdpfd = 0;
}

CEpollRunSockProcesser::~CEpollRunSockProcesser()
{
	Stop();
}

BOOL CEpollRunSockProcesser::InitAcceptSocket()
{
	if(!INHERITED::InitAcceptSocket())
	{
		logError("InitAcceptSocket error");
		return FALSE;
	}
	struct epoll_event ev;
	// 创建 epoll 句柄，把监听 socket 加入到 epoll 集合里
	m_kdpfd = epoll_create(MAXEPOLLSIZE);
	ev.events = EPOLLIN | EPOLLET;//边缘触发
	ev.data.fd = m_ListenSocket;
	m_curfds = 1;
	if (epoll_ctl(m_kdpfd, EPOLL_CTL_ADD, m_ListenSocket, &ev) < 0)
	{
		fprintf(stderr, "epoll set insertion error: fd=%d\n", m_ListenSocket);
		return FALSE;
	}
	return TRUE;
}

VOID CEpollRunSockProcesser::UninitAcceptSocket()
{
	struct epoll_event ev;
	ev.events = EPOLLIN | EPOLLET;
	ev.data.fd = m_ListenSocket;
	epoll_ctl(m_kdpfd, EPOLL_CTL_DEL, m_ListenSocket,&ev);
	INHERITED::UninitAcceptSocket();
}

VOID CEpollRunSockProcesser::NewSession()
{
	SOCKET nSocket;
	PRUNGATEUSERSESSION pSession;
	SOCKADDRIN sRemote;
	socklen_t nRemoteSize = sizeof(sRemote);
	u_long uBlock;
	struct epoll_event events[MAXEPOLLSIZE];
	struct epoll_event ev;
	timeval tv;
	tv.tv_sec = 0;
	tv.tv_usec = 10;

	int nfds,n;

	// 等待有事件发生
	nfds = epoll_wait(m_kdpfd, events, m_curfds, 10);
	if (nfds == -1)
	{
//		perror("epoll_wait");
//		SocklogError( __FUNCTION__,strerror(errno), errno );
		return;
	}
	if ( m_boStoping )//服务器是否还在运行
	{
		return;
	}
	// 处理所有事件
	for (n = 0; n < nfds; n++)
	{
		struct epoll_event event = events[n];
		if (event.data.fd == m_ListenSocket)//监听有事件就接受socket
		{
			nSocket = accept( m_ListenSocket, (sockaddr*)&sRemote, &nRemoteSize );
			if ( nSocket == INVALID_SOCKET )
			{
				SocklogError( __FUNCTION__, "accept", WSAGetLastError() );
				return;
			}

			if (m_curfds >= MAXEPOLLSIZE)
			{
				fprintf(stderr, "too many connection, more than %d\n", MAXEPOLLSIZE);
				close(nSocket);
				return;
			}
			uBlock = 1;
			//设置非阻塞
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

			//投递连接事件
			ev.events = EPOLLIN | EPOLLET;
			ev.data.fd = nSocket;
			if (epoll_ctl(m_kdpfd, EPOLL_CTL_ADD, nSocket, &ev) < 0)
			{
				fprintf(stderr, "add socket '%d' to epoll failed: %s\n", nSocket, strerror(errno));
				return;
			}
			m_curfds++;
			if ( !(pSession = m_pExecSockDataMgr->NewSession( nSocket, sRemote )) )//新会话
			{
				closesocket( nSocket );
				SocklogError( __FUNCTION__, "用户队列已经满了。", ERROR_SUCCESS );
				m_SessionFullTick = GetTickCount() + 10 * 1000;
				return;
			}
		}
		else//处理数据的socket 的事件
		{
			if (event.events&EPOLLIN)//等其他线程来处理读取事件
			{
				m_pExecSockDataMgr->setRecvSession(event.data.fd);
			}
			ev.events = EPOLLIN | EPOLLET;
			ev.data.fd = event.data.fd;
			epoll_ctl(m_kdpfd, EPOLL_CTL_DEL, event.data.fd,&ev);
			if (m_curfds>1)m_curfds--;
		}
	}
}

INT CEpollRunSockProcesser::EpollSessions()
{
	const int RecvBufSize = 1024;
	char sRecvBuf[RecvBufSize];
	INT_PTR nSessionCount = m_pExecSockDataMgr->GetSessionCount();
	PRUNGATEUSERSESSION*pSessionList = m_pExecSockDataMgr->GetSessionList();
	PRUNGATEUSERSESSION pEpollSessionList[MAXEPOLLSIZE];//获取合法的有数据的socket
	PRUNGATEUSERSESSION pSession;
	int nErr, nFdSSCount, nResult;

	nFdSSCount = 0;
	nResult = 0;

	while ( nFdSSCount < MAXEPOLLSIZE )
	{
		if (m_nSessionIndex >= nSessionCount)
		{
			m_nSessionIndex = 0;
			break;
		}

		pSession = pSessionList[m_nSessionIndex];
		m_nSessionIndex++;
		if ( pSession && pSession->nSocket != INVALID_SOCKET && \
				!pSession->boMarkToClose && !pSession->boRemoteClosed &&pSession->boRecvAvaliable)
		{
			pEpollSessionList[nFdSSCount++] = pSession;
			nResult++;//有数据的会话的个数
		}
	}
	if ( nFdSSCount > 0 )
	{
		// 等待有事件发生
		//需要检查错误
		while ( nFdSSCount > 0 )
		{
			nFdSSCount--;
			pSession = pEpollSessionList[nFdSSCount];
			nErr = recv( pSession->nSocket, sRecvBuf, RecvBufSize, 0 );
			pSession->boRecvAvaliable = false;//接完数据
			if ( nErr > 0 )
			{
				//添加到数据包
				m_pExecSockDataMgr->AddRecvBuf( pSession, pSession->nVerifyIdx, sRecvBuf, nErr );
			}
			else
			{
				pSession->boRemoteClosed = true;
				m_pExecSockDataMgr->CloseSession( pSession );
			}
		}
	}
	else if ( nErr == SOCKET_ERROR )
	{
		SocklogError( __FUNCTION__, "epoll_wait", WSAGetLastError() );
	}

	return nResult;
}

BOOL CEpollRunSockProcesser::StartEpollThreads()
{
#ifdef WINDOWS
	m_hEpollThread = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)EpollThreadRoutine, this, 0, NULL );
	if ( !m_hEpollThread )
	{
		SocklogError( __FUNCTION__, "CreateThread", GetLastError() );
		return FALSE;
	}

	m_hAcceptThread = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)AcceptThreadRoutine, this, 0, NULL );
	if ( !m_hEpollThread )
	{
		SocklogError( __FUNCTION__, "CreateThread", GetLastError() );
		return FALSE;
	}
#else
	if(0 != pthread_create(&m_hEpollThread, 0, (LPTHREAD_START_ROUTINE)(&EpollThreadRoutine), this))
	{
		SocklogError( __FUNCTION__, "CreateThread", errno );
		return false;
	}

	if(0 != pthread_create(&m_hEpollThread, 0, (LPTHREAD_START_ROUTINE)(&AcceptThreadRoutine), this))
		{
			SocklogError( __FUNCTION__, "CreateThread", errno );
			return false;
		}
#endif

	return true;
}

VOID CEpollRunSockProcesser::StopEpollThreads()
{
	CloseThread( m_hAcceptThread );
	CloseThread( m_hEpollThread );
}

BOOL CEpollRunSockProcesser::Start()
{
	if ( !INHERITED::Start() )
		return FALSE;
	m_nSessionIndex = 0;
	return InitAcceptSocket() && StartEpollThreads();
}

VOID CEpollRunSockProcesser::Stop()
{
	INHERITED::Stop();
	UninitAcceptSocket();
	StopEpollThreads();
}

