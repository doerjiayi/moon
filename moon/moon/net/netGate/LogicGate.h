#ifndef __LOGIC_GATE_H__
#define __LOGIC_GATE_H__

/******************************************************
 网关用户向逻辑引擎转发的数据报结构
*****************************************************/
typedef struct tagGateRecvPlayerPacket
{
	int nVerifyIndex;
	int nPlayerIndex;
	CPlayer *pPlayer;
	CNetPacket *pPacket;
}GATERECVPLAYERPACKET, *PGATERECVPLAYERPACKET;


#define USE_EPOLL (1)

/******************************************************
* 逻辑网关类
* 实现用户消息处理和转发功能
*****************************************************/
class CLogicGate : 
	public ExecSockDataMgr,
	public CLogicGateSynergy,
	public CBaseObject
{
	friend class CGateManager;

public:
	typedef ExecSockDataMgr super;

public:
	CLogicGate();
	~CLogicGate();

public:
	//启动网关
	bool startGate();
	//停止网关
	void stopGate();

public:
	//设置网关名称
	VOID SetGateName(LPCSTR sName);
	//获取网关名称
	inline LPCSTR GetGateName() { return m_sGateName; }
	//设置网关服务绑定地址
	inline VOID SetBindAddress(LPCSTR sAddress) { m_SocketProcessor.SetBindAddress(sAddress); }
	//获取网关服务绑定地址
	inline LPCSTR GetBindAddress() { return m_SocketProcessor.GetBindAddress(); }
	//设置网关服务绑定端口
	inline VOID	SetBindPort(INT nPort) { m_SocketProcessor.SetBindPort(nPort); }
	//获取网关服务绑定端口
	inline INT GetBindPort() { return m_SocketProcessor.GetBindPort(); }
	//网关是否已开启
	inline BOOL GetStarted() { return m_boStarted; }
	//获取峰值用户数量
	inline INT GetMaxUserCount() { return GetSessionCount(); }
	//获取网关编号
	inline INT GetGateIndex(){ return m_nGateIndex; }
	//提取本次收到的待处理的用户数据包列表
	INT PeekPlayerRecvPackets(CBList<GATERECVPLAYERPACKET> *pPacketList);

protected:
	//设置网关编号
	inline VOID SetGateIndex(const int nIndex) { m_nGateIndex = nIndex; }
	//覆盖CDataProcessor例行执行函数
	VOID OnRecvThreadSingleRun(TICKCOUNT dwCurrTick);
	//覆盖CDataProcessor分派用户消息函数
	VOID DispatchUserRecvPacket(PRUNGATEUSERSESSION pSession, char *pBuffer, uint32 nBufferSize);
	//覆盖CDataProcessor向引擎发送关闭用户的消息函数
	VOID PostEngineClosePlayer(PRUNGATEUSERSESSION pSession);
	//覆盖CLogicGateSynergy处理协同数据函数
	VOID HandleSynergyData(SynergyData *pData);
	//处理SynergyData数据内容
	VOID DispatchSynergyData(SynergyData *pData);
	//销毁SynergyData对象
	VOID DestroySynergyData(SynergyData *pData);
	//销毁所有待处理的用户数据包列表
	VOID FreePostPlayerPackets();

private:
	VOID HandleUserRequestKey(PRUNGATEUSERSESSION pSession);
	VOID HandleUserLogin(PRUNGATEUSERSESSION pSession, CDataPacketReader &inPacket);
	VOID HandleUserQueryChar(PRUNGATEUSERSESSION pSession);
	VOID HandleUserCreateChar(PRUNGATEUSERSESSION pSession, CDataPacketReader &inPacket);
	VOID HandleUserDeleteChar(PRUNGATEUSERSESSION pSession, CDataPacketReader &inPacket);
	VOID HandleUserEnterGame(PRUNGATEUSERSESSION pSession, CDataPacketReader &inPacket);

private:
#if USE_EPOLL
	CEpollRunSockProcesser m_SocketProcessor;
#else
	CSelectRunSockProcesser	m_SocketProcessor;
#endif
	CHAR					m_sGateName[48];//网关名称
	BOOL					m_boStarted;//网关是否已开启
	INT						m_nGateIndex;//网关编号
	CNetPacketPool			m_ProcPacketPool;//接受数据包对象池
	RTL_CRITICAL_SECTION	m_PostPlayerPackLock;
	CBList<GATERECVPLAYERPACKET> m_PostPlayerPackQueue[2];//接收并待处理的用户数据包缓冲列表
	CBList<GATERECVPLAYERPACKET>*m_pPostPlayerPackAppendList;//当前追加用户接收数据包列表
	CBList<GATERECVPLAYERPACKET>*m_pPostPlayerPackWaitList;//当前待处理用户接收数据包列表
};

#endif
