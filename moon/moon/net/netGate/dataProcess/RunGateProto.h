#ifndef	_RUNGATE_PROTO_
#define	_RUNGATE_PROTO_

#ifndef	SCSTR
#define	SCSTR static const CHAR*
#endif

//用户接收包缓冲区默认大小
#define	SESSION_RECV_BUFSIZE			512
//用户发送包缓冲区默认大小
#define	SESSION_SEND_BUFSIZE			1024
//每用户接收处理队列最长数据大小
#define	SESSION_MAX_RECVPROC_SIZE		8192
//用户数据队列处理内存增长单位
#define	SESSION_DATAGROW_SIZE			1024
//最大用户数据包序号错误数量
#define	SESSION_PACKETERR_MAX			32
//处理服务器数据最大时间
#define	RUNGATE_PROCESS_SERVERMSG_LIMIT	32	//32毫秒
//每次向用户发送数据包限制
#define	RUNGATE_ONCESENDUSE_LIMIT		2048
//发送检查超时
#define	RUNGATE_SENDCHECK_TIMEOUT		300

typedef	struct structRunGateDataBuffer
{
public:
	char	*lpBuffer;
	int		nSize;
	int		nOffset;

	inline void appendBuffer(LPCVOID pDataBuffer, int nBufferSize)
	{
		int nRemainSize = nSize - nOffset;
		if (nRemainSize < nBufferSize)
		{
			int nGrowSize = nBufferSize - nRemainSize;
			nGrowSize = __max(nGrowSize, SESSION_RECV_BUFSIZE);
			lpBuffer = (char*)realloc(lpBuffer, nSize + nGrowSize);
		}
		memcpy(&lpBuffer[nOffset], pDataBuffer, nBufferSize);
		nOffset += nBufferSize;
	}
}EXECGATEDATABUF, *PEXECGATEDATBUF;

class CPlayer;
class CDataPacket;

//网关用户状态
#pragma pack(push, 1)
enum GateUserState
{
	eGUSWaitRequestKey = 0,//等待请求通信KEY
	eGUSWaitLogin,//等待登陆
	eGUSLoginInProgress,//正在验证登陆中
	eGUSSelChar,//等待选择角色开始游戏、创建角色、删除角色
	eGUSCreateChar,//正在创建角色
	eGUSDeleteChar,//正在删除角色
	eGUSWaitEnterGame,//等待载入数据进入游戏
	eGUSInGame,//已经进入游戏，正在游戏中
};
#pragma pack(pop)

/******************************************************
网关用户会话对象结构
****************************************************/
typedef	struct structExecGateUserSession
{
	SOCKET				nSocket;
	int					nIndex;
	int					nPlayerIndex;
	CPlayer			*	pPlayer;
	SOCKADDRIN			SockAddr;
	int					nRecvPacketCount;
	int					nSendPacketCount;
	WORD				wPacketVerifyKey;
	GateUserState		btUserState;
	bool				boSendAvaliable;
	volatile bool				boRecvAvaliable;
	bool				boMarkToClose;
	bool				boRemoteClosed;
	common::time::TICKCOUNT			dwConnectTick;
	common::time::TICKCOUNT			dwCloseTick;
	common::time::TICKCOUNT			dwSendTimeOut;
	common::time::TICKCOUNT			dwClientMsgTick;
	common::time::TICKCOUNT			dwServerMsgTick;
	common::time::TICKCOUNT			dwMsgIntervalTick;
	int					nVerifyIdx;			
	int					nIntervalMsgCount;
	EXECGATEDATABUF		RecvBuf;
	EXECGATEDATABUF		SendBuf;
	int					nAccountId;//登录账号ID
	CHAR				sAccount[64];//登陆账号
	common::PlayerId	PlayerId;//游戏角色ID
	CHAR				sCharName[32];//游戏角色名称
}RUNGATEUSERSESSION, *PRUNGATEUSERSESSION;

#define	INIT_SESSION_SEND(s)		//InitializeCriticalSection( &(s)->SendBufLock )
#define	UNINIT_SESSION_SEND(s)		//DeleteCriticalSection( &(s)->SendBufLock )
#define	LOCK_SESSION_SEND(s)		//EnterCriticalSection( &(s)->SendBufLock )
#define	TRYLOCK_SESSION_SEND(s)		TRUE//TryEnterCriticalSection( &(s)->SendBufLock )
#define	UNLOCK_SESSION_SEND(s)		//LeaveCriticalSection( &(s)->SendBufLock )


#endif
