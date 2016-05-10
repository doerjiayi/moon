#ifndef SERVER_INIT_H
#define SERVER_INIT_H

inline void init_daemon(void)
{
#ifdef LINUX
	int pid;
	if((pid=fork()))exit(0);//是父进程，结束父进程
	else if(pid< 0)
	{
		printf("fork失败，退出");
		exit(1);//fork失败，退出
	}

	//是第一子进程，后台继续执行
	setsid();//第一子进程成为新的会话组长和进程组长，并与控制终端分离
	if((pid=fork()))exit(0);//是第一子进程，结束第一子进程
	else if(pid< 0)
	{
		printf("fork失败，退出");
		exit(1);//fork失败，退出
	}
	//是第二子进程，继续
	//第二子进程不再是会话组长
	chdir("./");//改变工作目录到./
	umask(0);//重设文件创建掩模
	printf("RUN AS DAEMON. ");
#endif
	return;
}


inline void init_args(int argc,char*const* argv)
{
	char ch;
	int d = 0;

	//处理argv
	while( ( ch = getopt( argc, argv, "d?" ) ) != EOF )
	{
		switch(ch)
		{
			case 'd':
				d = 1;
				break;
			case '?':
				logInfo("Useage: -d (RUN AS DAEMON.)\n");
				exit(1);
				break;
			default:
				logInfo("Not support option :%c\n",ch);
				exit(2);
		}
	}

	if(d == 1)init_daemon();
}


inline void initMemoryLeakfunc()
{
#if defined(WIN32) && defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_DEBUG );
	_CrtSetReportHook(&MemoryLeakLog);
	//_CrtSetBreakAlloc(9886);
#endif
}




#endif//SERVER_INIT_H


