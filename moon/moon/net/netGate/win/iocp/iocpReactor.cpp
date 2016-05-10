#include "StdAfx.h"
#include "iocpReactor.h"

#if defined (WINDOWS)


DWORD CALLBACK CIocp::WorkThread( LPVOID Param )
{
	CIocp *pthis = (CIocp *)Param;

	PPER_HANDLE_DATA pPerHandle;
	PPER_IO_DATA pPerIO;
	DWORD		dwTrans;
	BOOL		ret;
	while (pthis->m_started)
	{
		ret = GetQueuedCompletionStatus(pthis->m_hIocp,&dwTrans,(PULONG_PTR)&pPerHandle,(LPOVERLAPPED *)&pPerIO,INFINITE);
		if (!ret)
		{
			::closesocket(pPerHandle->socket);
			::GlobalFree(pPerHandle);
			::GlobalFree(pPerIO);
			continue;
		}
		if(dwTrans == 0 &&				// 套节字被对方关闭
			(pPerIO->nOperationType == OP_READ || pPerIO->nOperationType == OP_WRITE))	

		{
			::closesocket(pPerHandle->socket);
			::GlobalFree(pPerHandle);
			::GlobalFree(pPerIO);
			continue;
		}
		switch(pPerIO->nOperationType)	// 通过per-I/O数据中的nOperationType域查看什么I/O请求完成了
		{
		case OP_READ:	// 完成一个接收请求
			{
				pPerIO->wbuf.buf[dwTrans] = '\0';
				printf(pPerIO->wbuf.buf);

				// 继续投递接收I/O请求
				WSABUF buf;
				buf.buf = pPerIO->wbuf.buf ;
				buf.len = BUFFER_SIZE;
				pPerIO->nOperationType = OP_READ;

				DWORD nFlags = 0;
				::WSARecv(pPerHandle->socket, &pPerIO->wbuf, 1, &dwTrans, &nFlags, &pPerIO->ol, NULL);
			}
			break;
		case OP_WRITE: // 本例中没有投递这些类型的I/O请求
		case OP_ACCEPT:
			break;
		}
	}
	return 0;
}

DWORD CALLBACK CIocp::AcceptThread( LPVOID Param )
{
	CIocp *pthis = (CIocp *)Param;
	int nPort = pthis->m_port;
	HANDLE hCompletion = pthis->m_hIocp;
	int coreNum = pthis->m_coreNumber;
	if (!hCompletion ||nPort<=0 ||coreNum<=0)
	{
		printf("complation error or port error\n");
		return -1;
	}
	// 创建监听套节字，绑定到本地地址，开始监听
	SOCKET sListen = ::socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN si;
	si.sin_family = AF_INET;
	si.sin_port = ::ntohs(nPort);
	si.sin_addr.S_un.S_addr = INADDR_ANY;
	::bind(sListen, (sockaddr*)&si, sizeof(si));
	::listen(sListen, 5);

	// 循环处理到来的连接
	while(pthis->m_started)
	{
		// 等待接受未决的连接请求
		SOCKADDR_IN saRemote;
		int nRemoteLen = sizeof(saRemote);
		SOCKET acceptSocket = ::accept(sListen, (sockaddr*)&saRemote, &nRemoteLen);

		// 接受到新连接之后，为它创建一个per-handle数据，并将它们关联到完成端口对象。
		PPER_HANDLE_DATA pPerHandle = (PPER_HANDLE_DATA)::GlobalAlloc(GPTR, sizeof(PER_HANDLE_DATA));
		pPerHandle->socket = acceptSocket;
		memcpy(&pPerHandle->addr, &saRemote, nRemoteLen);
		if ((::CreateIoCompletionPort((HANDLE)pPerHandle->socket, hCompletion, (DWORD)pPerHandle, coreNum*2)) == NULL)//判断创建句柄
			continue;

		// 投递一个接收请求
		PPER_IO_DATA pPerIO = (PPER_IO_DATA)::GlobalAlloc(GPTR, sizeof(PER_IO_DATA));
		pPerIO->nOperationType = OP_READ;
		WSABUF buf;
		buf.buf = pPerIO->wbuf.buf;
		buf.len = BUFFER_SIZE;	
		DWORD dwRecv;
		DWORD dwFlags = 0;
		::WSARecv(pPerHandle->socket, &buf, 1, &dwRecv, &dwFlags, &pPerIO->ol, NULL);
	}
	return 0;
}

CIocp::CIocp(void)
{
	SYSTEM_INFO si;  
	GetSystemInfo(&si);  
	m_coreNumber = si.dwNumberOfProcessors;  
	m_port = 0;
	m_hIocp = NULL;
}

CIocp::CIocp( const char* address,int port )
{
	assert(address && port > 0);
	SYSTEM_INFO si;  
	GetSystemInfo(&si);  
	m_coreNumber = si.dwNumberOfProcessors;  
	m_port = 0;
	m_hIocp = NULL;
	init(address,port);
}

CIocp::~CIocp(void)
{
	m_started = END_CIOCP;
}

 

bool CIocp::iocpListen(void)
{
	if (m_started == END_CIOCP)
	{
		printf("还没有启动iocp");
		return false;
	}
	m_sSocket = socket(AF_INET,SOCK_STREAM,0);
	if (m_sSocket == INVALID_SOCKET)
	{
		return false;
	}

	//SOCKADDR_IN addr
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(m_port);
	serverAddr.sin_addr.S_un.S_addr = inet_addr(m_address);

	if (bind(m_sSocket,(sockaddr *)&serverAddr,sizeof(serverAddr)) == SOCKET_ERROR)
		return false;
	if (listen(m_sSocket,10) == SOCKET_ERROR)
		return false;

	//创建完成端口句柄
	if ((m_hIocp = CreateIoCompletionPort(INVALID_HANDLE_VALUE,NULL,NULL,0)) == NULL)
		return false;

	m_started = START_CIOCP;
	//创建连接线程，用来接受客户端的连接的
	m_aThread = CreateThread(NULL,0,AcceptThread,(LPVOID)this,0,&m_athreadID);

	//创建工作线程，用来处理完成端口消息的
	m_aThread = CreateThread(NULL,0,WorkThread,(LPVOID)this,0,&m_wthreadID);

	return true;
}

bool CIocp::iocpConnect(void)
{
	SOCKADDR_IN clientAddr;
	m_sSocket=socket(AF_INET,SOCK_STREAM,0);                    //创建socket
	clientAddr.sin_family=AF_INET;
	clientAddr.sin_port=htons(m_port);
	clientAddr.sin_addr.S_un.S_addr=inet_addr(m_address);

	if (connect(m_sSocket,(SOCKADDR*)&clientAddr,sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		printf("connect error\n");
		return false;
	}

	//创建完成端口的句柄
	if ((m_hIocp = CreateIoCompletionPort(INVALID_HANDLE_VALUE,NULL,NULL,0)) == NULL)
		return false;

	m_started = START_CIOCP;
	//创建工作线程，用来处理完成端口的消息
	m_wThread = CreateThread(NULL,0,WorkThread,(LPVOID)this,0,&m_wthreadID);

	return true;
}

int CIocp::iocpSend(const char *buf,int len)
{
	return send(m_sSocket,buf,len,0);
}

bool CIocp::init( const char* address,int port )
{
	strncpy_s(m_address,address,ADDRESS_LEN);
	m_port = port;
	return true;
}

void CIocp::runRector( int port,int address )
{
	iocpListen();
}

#endif
