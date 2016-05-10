#ifndef	EXEC_SOCK_DATA_MANAGER_H__
#define	EXEC_SOCK_DATA_MANAGER_H__

#define	RUNDATA_MAX_SENDTHREAD	8

//////////////////////////////////////////////////////////////////////////
//管理网络会话，管理网络数据包接收队列、连接相关数据，管理发送线程数量
//////////////////////////////////////////////////////////////////////////


using namespace lib::container;
class ExecSockDataMgr
{
protected:
	int						m_nActiveUser;			//活动连接数
	BOOL					m_boStoping;			//是否正在停止服务
	BOOL					m_boStarted;			//是否已经启动服务
	CHAR					m_sGateName[64];		//网关名称
	int						m_nSendThreadCount;		//发送线程数量
#ifdef WINDOWS
	HANDLE					m_hProcRecvThread;
#else
	pthread_t m_hProcRecvThread;
#endif
	EXECDATASENDTHREAD		m_SendThreads[RUNDATA_MAX_SENDTHREAD];

	RTL_CRITICAL_SECTION	m_SessionLock;
	CBList<PRUNGATEUSERSESSION>			   m_SessionList;	//用户会话队列
	CListAllocator<RUNGATEUSERSESSION> m_SessionAllocator;

	CNetPacketPool			m_RecvPacketPool;
	RTL_CRITICAL_SECTION	m_RecvQueueLock;
	CBList<CNetPacket*>	m_RecvQueue[2];
	CBList<CNetPacket*>*	m_pRecvAppendList;
	CBList<CNetPacket*>*	m_pRecvProcList;
	int						m_nUserVerify;
#ifdef WINDOWS
	static VOID STDCALL RecvDataProcessRoutine(ExecSockDataMgr *pRunData);
	static VOID STDCALL SendDataProcessRoutine(PEXECDATASENDTHREAD pRunThread);
#else
	static void* RecvDataProcessRoutine(ExecSockDataMgr *pRunData);
	static void* SendDataProcessRoutine(PEXECDATASENDTHREAD pRunThread);
#endif

	VOID InitSessions();
	VOID UninitSessions();
	VOID FreeRecvBuffers();
	VOID FreeSendBuffers(PEXECDATASENDTHREAD pSendThread);
	VOID FreeSession(PRUNGATEUSERSESSION pSession);
	BOOL CopyWaitSendBuffers(PEXECDATASENDTHREAD pSendThread, BOOL boForceCopy);
	VOID GotError(LPCSTR sErrFn, LPCSTR sErrApi, int nErr);
	VOID InitSendThreadData();
	VOID UninitSendThreadData();
	VOID CloseAllSessions(BOOL boForceClose);
	VOID CancelRemainSendSessionBuffers();
	BOOL CheckCloseSessions(BOOL boForceCheck);
	VOID CheckSendSessionBuffers(PEXECDATASENDTHREAD pSendThread);
	VOID ProcessUserRecvPacket(PRUNGATEUSERSESSION pSession, char *pBuffer, int nBufferSize);
	BOOL ValidateUserRecvPacket(PRUNGATEUSERSESSION pSession, char *pBuffer, int nBufferSize, unsigned short wVerification);

protected:
	virtual VOID OnRecvThreadSingleRun(TICKCOUNT dwCurrTick);
	virtual VOID DispatchUserRecvPacket(PRUNGATEUSERSESSION pSession, char *pBuffer, int nBufferSize);
	virtual VOID PostEngineClosePlayer(PRUNGATEUSERSESSION pSession);

public:
	ExecSockDataMgr();
	virtual ~ExecSockDataMgr();

	DWORD		m_dwProcessRecvSize;		//处理客户端接收数据大小
	DWORD		m_dwWaitSendUserSize;		//待发送给用户的数据包大小
	DWORD		m_dwWaitSendQueueSize;		//待发给用户的数据包队列大小
	DWORD		m_dwRecvSeverSize;			//接收服务器数据大小
	DWORD		m_dwSendUserSize;			//发送用户数据大小
	TICKCOUNT	m_dwLastProcUsrMsgTime;		//上次处理用户数据时间
	TICKCOUNT	m_dwLastProcSrvMsgTime;		//上次处理服务器数据时间
	TICKCOUNT	m_dwLastRecvSrvMsgTime;		//上次接收服务器数据时间
	TICKCOUNT	m_dwProcSrvThreadSleep;		//处理服务器数据线程休眠时间
	DWORD		m_dwSendQueueSize;			//待发数据队列数据包大小

	INT		GetActiveUserCount();
	INT		GetSendThreadCount();
	VOID	SetSendThreadCount(INT ThreadCount);
	PEXECDATASENDTHREAD	GetSendThreadInfo(INT ThreadIdx);
	inline PRUNGATEUSERSESSION* GetSessionList(){ return m_SessionList; }
	inline INT GetSessionCount(){ return (INT)m_SessionList.count(); }

	BOOL Start();
	VOID Stop();

	PRUNGATEUSERSESSION NewSession(SOCKET nSocket, SOCKADDRIN RemoteAddr);
	PRUNGATEUSERSESSION setRecvSession(SOCKET nSocket);
	VOID AddRecvBuf(PRUNGATEUSERSESSION pSession, ULONG_PTR nVerify, char *pBuffer, int BufferSize);
	VOID CloseSession(PRUNGATEUSERSESSION pSession, BOOL boClosedByServer = FALSE);
	VOID ClosePlayer(int nUserIndex, int nUserVerify, CPlayer *pPlayer, int nPlayerIndex);//此函数只设计为逻辑线程调用
	CGateSendPacket& AllocSendPacket(const int nUserIndex);
	BOOL SetSessionPlayer(common::SERVERUSERHANDLE *pUserHandle, CPlayer *pPlayer, int pPlayerIndex);
};

#endif
