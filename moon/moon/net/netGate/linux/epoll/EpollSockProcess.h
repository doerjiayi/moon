#ifndef	_EPOLL_SOCK_PROCESS_H_
#define	_EPOLL_SOCK_PROCESS_H_
#include "moonLib/os/Platform.h"
/*	epoll 模型的RunSock	*/
class CEpollRunSockProcesser : public ExecSockMgr
{
	typedef ExecSockMgr INHERITED;
private:
#ifdef WINDOWS
	HANDLE				m_hEpollThread;
	HANDLE				m_hAcceptThread;
#else
	pthread_t m_hEpollThread;//选择已连接socket并接受数据
	pthread_t m_hAcceptThread;//接受socket并产生session到队列
#endif
	INT_PTR				m_nSessionIndex;
	volatile	int 		m_curfds;//当前的socket文件描述符的数量
	int 						m_kdpfd;//epoll 句柄
#ifdef WINDOWS
	static VOID EpollThreadRoutine(CEpollRunSockProcesser *pRunSock);
	static VOID AcceptThreadRoutine(CEpollRunSockProcesser *pRunSock);
#else
	static void *EpollThreadRoutine(CEpollRunSockProcesser *pRunSock);
	static void *AcceptThreadRoutine(CEpollRunSockProcesser *pRunSock);
#endif
	//重载初始化监听socket
	BOOL InitAcceptSocket();
	VOID UninitAcceptSocket();
	VOID NewSession();//重载实现接受新会话
	INT  EpollSessions();

	BOOL StartEpollThreads();
	VOID StopEpollThreads();
public:
	CEpollRunSockProcesser();
	~CEpollRunSockProcesser();

	BOOL Start();
	VOID Stop();
};


#endif

