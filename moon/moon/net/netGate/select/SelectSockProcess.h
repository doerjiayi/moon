#ifndef	_SELECT_SOCK_PROCESS_H_
#define	_SELECT_SOCK_PROCESS_H_
#include "moonLib/os/Platform.h"
/*	select 模型的RunSock	*/
class CSelectRunSockProcesser : public ExecSockMgr
{
	typedef ExecSockMgr INHERITED;
private:
#ifdef WINDOWS
	HANDLE				m_hSelectThread;
	HANDLE				m_hAcceptThread;
#else
	pthread_t m_hSelectThread;//选择已连接socket并接受数据
	pthread_t m_hAcceptThread;//接受socket并产生session到队列
#endif
	INT_PTR				m_nSessionIndex;

#ifdef WINDOWS
	static VOID SelectThreadRoutine(CSelectRunSockProcesser *pRunSock);
	static VOID AcceptThreadRoutine(CSelectRunSockProcesser *pRunSock);
#else
	static void *SelectThreadRoutine(CSelectRunSockProcesser *pRunSock);
	static void *AcceptThreadRoutine(CSelectRunSockProcesser *pRunSock);
#endif

	INT  SelectSessions();

	BOOL StartSelectThreads();
	VOID StopSelectThreads();
public:
	CSelectRunSockProcesser();
	~CSelectRunSockProcesser();

	BOOL Start();
	VOID Stop();
};


#endif

