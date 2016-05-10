#include "StdAfx.h"

const TCHAR szExceptionDumpFile[] = _T("./moonServer.dmp");



int main(int argc, char** argv)
{
	init_args(argc,argv);
	initDefMsgOut();
	initOutputMsgFn();	
	initMemoryLeakfunc();
#ifdef WINDOWS
	SetConsoleTitle("月亮游戏服务器");
#endif
	randValueInitSeed((unsigned int)::time(NULL));
	CGameServer* gameServer = new CGameServer();
	if (!gameServer->runGameServer())
	{
		logError("启动逻辑错误");
		assert(false);
		SafeDelete(gameServer);
		uninitDefMsgOut();
		return -1;
	}
	
	getchar();
	logInfo("服务器结束\n");
	SafeDelete(gameServer);
	uninitDefMsgOut();
	return 0;
}





