#include "StdAfx.h"
#include "iocpReactor.h"

#if defined (WINDOWS)  

int testIocp(int argc, char* argv[])
{
	//客户端连接
	const char sendBuf[] = "test{post.connect}";
	const char address[] = "192.168.1.106";
	//const char address[] = "127.0.0.1";

	const unsigned short port = 1234;
	CIocp iocp(address,port);
	bool res = iocp.iocpConnect();
	int sendRet;
	if (res)
	{
		while(1)
		{
			sendRet = iocp.iocpSend(sendBuf,(int)strlen(sendBuf)+1);
			if (sendRet <= 0)
				break;
			Sleep(1);
		}
	}
	getchar();
	return 0;
}
#endif

