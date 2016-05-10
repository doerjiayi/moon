#include "StdAfx.h"

#if defined(WINDOWS)

static WsaData g_wsaData;
static bool g_wsaStarted = false;
WsaData::WsaData()
{

}

WsaData::~WsaData()
{
	if (g_wsaStarted)
	{
		dastroyWsaData();
	}
	g_wsaStarted = false;
}

bool WsaData::initWsaData()
{
	WSADATA wsaData;
	int err;
	// 初始化
	err = WSAStartup(0x0202, &wsaData);
	if(err != 0)
	{
		printf("WSAStartup fail!\n");
		WSACleanup();
		assert(false);
		return false;
	}
	if((wsaData.wVersion & 0xFFFF) != 0x0202)
	{
		printf("Wrong version\n");
		WSACleanup();
		assert(false);
		return false;
	}
	g_wsaStarted = true;
	return true;
}

void WsaData::dastroyWsaData()
{
	WSACleanup();
}

bool InitWinNet()
{
	
	if (!g_wsaData.initWsaData())
	{
		printf("init win net error\n");
		return false;
	}
	return true;
}


#endif
