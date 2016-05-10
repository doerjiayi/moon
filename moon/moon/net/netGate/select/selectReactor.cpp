#include "StdAfx.h"
#include "../moonLib/os/Platform.h"

#ifdef WINDOWS

DWORD WINAPI CSelectReactor::SelectThread(LPVOID lpThreadParameter)
{
	CSelectReactor *pSelectReactor = (CSelectReactor *)lpThreadParameter;
	fd_set fdread;
	timeval delayTv = {1, 0};
	char buf[9172] = {0};
	static int nNumber;
	while(1)
	{
		FD_ZERO(&fdread);
		nNumber = InterlockedExchange((long *)&pSelectReactor->selectSocketNumber,pSelectReactor->selectSocketNumber);
		for(int i=nNumber-1; i>-1; i--)// 必须降序
		{
			FD_SET(pSelectReactor->selectClientSockets[i], &fdread);
		}

		int err = select(0, &fdread, NULL, NULL, &delayTv);
		if(err == SOCKET_ERROR)
		{
			//error
			err = WSAGetLastError();
			logError("[Select] Select fail! Error code: %d,%s\n", err,strerror(err));
			continue;
		}
		else if(err == 0)
		{
			// time out
			logError("[Select] Select time out!\n");
			continue;
		}
		else
		{
			// read event
			for(int i=nNumber -1; i > -1; i--)
			{
				if(FD_ISSET(pSelectReactor->selectClientSockets[i], &fdread)) // 如果可读
				{
					memset(buf, 0, 256);
					err = recv(pSelectReactor->selectClientSockets[i], buf, 256, 0);
					if(err == SOCKET_ERROR)
					{
						err = WSAGetLastError();
						if(err == WSAECONNABORTED || err == WSAECONNRESET || err == WSAENOTCONN)
						{
							closesocket(pSelectReactor->selectClientSockets[i]);
							printf("close socket %d\n",pSelectReactor->selectClientSockets[i]);
							EnterCriticalSection(&pSelectReactor->m_selectCriticalSection);
							if(i < pSelectReactor->selectSocketNumber - 1)//去掉关闭的socket
							{
								pSelectReactor->selectClientSockets[i] = pSelectReactor->selectClientSockets[--pSelectReactor->selectSocketNumber];
							}
							else if(i == pSelectReactor->selectSocketNumber - 1)
							{
								pSelectReactor->selectClientSockets[--pSelectReactor->selectSocketNumber] = INVALID_SOCKET;
							}
							LeaveCriticalSection(&pSelectReactor->m_selectCriticalSection);

						}
					}
					else
					{
						SOCKADDR_IN addr;
						socklen_t len = sizeof(SOCKADDR_IN);//SOCKADDR
						err = getsockname(pSelectReactor->selectClientSockets[i], (SOCKADDR*)&addr, &len);
						if(err == SOCKET_ERROR)
						{
							err = WSAGetLastError();
							logError("[Select] 获取客户端地址失败!错误号: %d\n", err);
						}
						else
						{
							logError("[Select] 地址：% \n", inet_ntoa(addr.sin_addr));
						}
						logError("Receive info: %s", buf);
						/*err = send(g_ClientSockets[i], tmp, static_cast<int>(strlen(tmp)), 0);
						if(err == SOCKET_ERROR)
						{
						err = WSAGetLastError();
						closesocket(g_ClientSockets[i]);
						printf("[Select] Send info fail! Error code: %d\n", err);
						}
						else if (err == 0)
						{
						closesocket(g_ClientSockets[i]);
						printf("send error ,peer closed\n");
						}*/

					}
				}
			}
		}
	}
}

DWORD WINAPI CSelectReactor::runThread(LPVOID lpThreadParameter)
{
	CSelectReactor *pSelectReactor = (CSelectReactor *) lpThreadParameter;
	int port = pSelectReactor->m_port;
	const char* address = pSelectReactor->m_address;
	int err;
	// 绑定，并监听服务
	SOCKET ServiceSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(ServiceSocket == INVALID_SOCKET)
	{
		err = WSAGetLastError();
		printf("[Select] Create service socket fail! Error code: %d.", err);
		return -1;
	}

	SOCKADDR_IN SocketAddr;
	SocketAddr.sin_family = AF_INET;
	if (!strncmp(address,"127.0.0.1",MAX_ADDRESS))
	{
#ifdef WINDOWS
		SocketAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
#else
		SocketAddr.sin_addr.s_addr = htonl(INADDR_ANY);
#endif
	}
	else
	{
#ifdef WINDOWS
		SocketAddr.sin_addr.S_un.S_addr = inet_addr(address);
#else
		SocketAddr.sin_addr.s_addr = inet_addr(address);
#endif
	}
	
	SocketAddr.sin_port = htons(port);
	err = bind(ServiceSocket, (SOCKADDR*)&SocketAddr, sizeof(SOCKADDR));
	if(err != 0)
	{
		err = WSAGetLastError(); 
		logError("[Select] Service socket bind fail! Error code: %d.\n", err);
		return -1;
	}

	err = listen(ServiceSocket, SOMAXCONN);
	if(err != 0)
	{
		err = WSAGetLastError();
		logError("[Select] Service socket listen fail! Error code: %d. \n", err);
		return -1;
	}
	logInfo("[Select] Server socket listening...");

	// select线程
	DWORD thid;
	HANDLE handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)CSelectReactor::SelectThread, pSelectReactor, 0, &thid);

	// 等待连接，获得链接之后让工作线程去处理
	SOCKADDR_IN clientAddr;
	int addrlen = sizeof(SOCKADDR);
	while(1)
	{
		SOCKET clientSocket = accept(ServiceSocket, (SOCKADDR*)&clientAddr, &addrlen);
		if(clientSocket == INVALID_SOCKET)
		{
			err = WSAGetLastError();
			logError("[Select] Accept client socket fail! Error code: %d. ", err);
			continue;
		}
		else
		{
			static const int sizeBuff = 8096;
			if (!adjustSocketSendBufSize(clientSocket,sizeBuff))
				continue;

			EnterCriticalSection(&pSelectReactor->m_selectCriticalSection);
			pSelectReactor->selectClientSockets[pSelectReactor->selectSocketNumber++] = clientSocket;
			LeaveCriticalSection(&pSelectReactor->m_selectCriticalSection);
			printf("[Select] Socket connect success!\n");
		}
	}
	WaitForSingleObject(handle,INFINITE);
	CloseHandle(handle);
}

CSelectReactor::CSelectReactor()
{
	InitializeCriticalSection(&m_selectCriticalSection);
}

CSelectReactor::~CSelectReactor()
{
	DeleteCriticalSection(&m_selectCriticalSection);
}

void CSelectReactor::runRector()
{
	DWORD thid;
	HANDLE handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)runThread, 0, 0, &thid);
	WaitForSingleObject(handle,INFINITE);
	CloseHandle(handle);
}

#endif
