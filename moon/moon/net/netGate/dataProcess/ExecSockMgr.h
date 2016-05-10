#ifndef	EXEC_SOCK_MGR_H__
#define	EXEC_SOCK_MGR_H__
typedef enum eExecSockType
{
	eExecSockUndefined = 0,
	eExecSockSelect,		//select 模型
	eExecSockIocp,			//IOCP 模型
	eExecSockEpoll,			//Epoll 模型
}EXECSOCKTYPE;

class ExecSockDataMgr;

//////////////////////////////////////////////////////////////////////////
//socket 管理（初始化、设置）
//////////////////////////////////////////////////////////////////////////

class ExecSockMgr
{
protected:
	EXECSOCKTYPE			m_RunSockType;
	BOOL				m_boStoping;
	SOCKET				m_ListenSocket;		//监听连接的套接字句柄
	SOCKADDRIN			m_BindAddr;			//服务监听绑定地址（网关地址）
	ExecSockDataMgr	*m_pExecSockDataMgr;//socket 数据执行管理者，管理用户会话和接受数据队列
	DWORD				m_SessionFullTick;	
	static VOID SocklogError(LPCSTR sErrorFn, LPCSTR sErrAPI, const INT nErrorCode);

	//监听socket
	virtual BOOL InitAcceptSocket();
	virtual VOID UninitAcceptSocket();
	//接受新的socket到（成员）socket数据管理者 的队列里
	//epoll执行socket管理器需要重载
	virtual VOID NewSession();
	//tcp发送缓冲区大小调整
	BOOL AdjustSocketSendBufSize(SOCKET s, INT nSize);
public:
	ExecSockMgr();
	virtual ~ExecSockMgr();
	//网关地址和端口
	VOID	SetBindAddress(LPCSTR sAddress);
	VOID	SetBindPort(INT nPort);
	LPCSTR	GetBindAddress();
	INT		GetBindPort();
	EXECSOCKTYPE	GetRunSockType();
	ExecSockDataMgr*	GetDataProcesser();
	ExecSockDataMgr*	SetDataProcesser(ExecSockDataMgr *pDataProcesser);

	static BOOL InitBase();
	static VOID UninitBase();

	virtual BOOL Start();
	virtual VOID Stop();
};


#endif
