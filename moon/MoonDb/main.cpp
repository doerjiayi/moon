// MoonDb.cpp : Defines the entry point for the console application.
//

#include "StdAfx.h"

const TCHAR szExceptionDumpFile[] = _T("./moonDB.dmp");


int main(int argc, _TCHAR* argv[])
{
	int nError;
	CDBEngine *pDBEngine = new CDBEngine();
	TCHAR sCmdBuf[512];
#ifdef WINDOWS
	SetUnhandledExceptionFilter( DefaultUnHandleExceptionFilter );
	SetConsoleTitle(_T("月亮之心数据服务器"));
#endif
	Assert(sizeof(GameDBType::CharDesc) == 0xC0);
	initDefMsgOut();
#ifdef WINDOWS
	setCLocalePath(); //为了实现支持UTF8编码。
	//Initializes the COM library on the current thread and identifies the concurrency model as single-thread apartment
	CoInitialize(NULL);
#endif
	if ( SetupDBEngineConfig(pDBEngine) && pDBEngine->Startup() )
	{
		snprintf(sCmdBuf,sizeof(sCmdBuf), "月亮数据服务器 - %s", pDBEngine->getServerName());
#ifdef WINDOWS
		SetConsoleTitle(sCmdBuf);
#endif
		in_addr ia;
		ia.s_addr = DBEGN_KN_VERION;
		logInfo("-------------------------------------------");
		logInfo("数据服务器启动成功，核心版本号是%s", inet_ntoa(ia) );
		logInfo("数据结构版本号是：%X", DBSDATATYPE_VERSION );
//		logInfo( _T("角色基础数据结构大小是：%d"), sizeof(CHARBASEDATA) );
		logInfo("quit命令可以停止服务并退出程序");
		logInfo("lfw 命令可以重新加载角色名称过滤表");
		logInfo("-------------------------------------------");

		while ( TRUE )
		{
			fgets(sCmdBuf, sizeof(sCmdBuf), stdin);
			//重新角色名称过滤表命令
			if ( strnicmp(sCmdBuf, "lfw", 3) == 0 )
			{
				nError = pDBEngine->LoadNameFilterWords();
				if ( nError >= 0 )
					logInfo( _T("已加载%d个名称过滤词"), nError);
				else logError( _T("加载名称过滤词数据失败"));
			}
			//退出命令
			else if ( strnicmp(sCmdBuf, "\\q", 2) == 0
				|| strnicmp(sCmdBuf, "exit", 4) == 0
				|| strnicmp(sCmdBuf, "quit", 4) == 0 )
			{
				logInfo( _T("正在停止数据服务器...") );
				break;
			}
			fflush(stdin);
			*sCmdBuf = 0;
			moon::OS::osSleep(10);
		}

		pDBEngine->Shutdown();
	}
	else
	{
		system("pause");
	}

	delete pDBEngine;
#ifdef WINDOWS
	CoUninitialize();
#endif
	uninitDefMsgOut();
#ifdef	_MLIB_DUMP_MEMORY_LEAKS_
	_CrtDumpMemoryLeaks();
#endif
	return 0;
}



