#ifndef __LOGIC_ENGINE_H__
#define __LOGIC_ENGINE_H__

using namespace lib::container;
using namespace common;

class CLogicEngine : 
	public CBaseObject,
	public lib::thread::CBaseThread
{
public:
	typedef lib::thread::CBaseThread super;

public:
	CLogicEngine();
	virtual ~CLogicEngine();

public:
	//获取当前TickCount值
	inline TICKCOUNT getTickCount(){ return m_dwCurrentTick; }
	//获取当前MiniDateTime值
	inline int getDateTime(){ return m_nDateTime; }
	//获取当前系统时间值
	inline const SYSTEMTIME& getSysTime(){ return m_SysTime; }
	//加锁逻辑线程，在解锁之前逻辑线程将暂停运行
	//此操作仅适用于其他线程需要对逻辑数据进行更新而需要确保数据安全期间调用，例如重新读取配置。
	inline void lockLogic() { m_LoginRunLock.Lock(); }
	//解锁逻辑线程
	inline void unlockLogic() { m_LoginRunLock.Unlock(); }
	//开启玩家对象（玩家数据加载成功并进入游戏）
	void openPlayer(EnterGameStruct *pEnterStruct, bool boIsNewPlayer, CPoolDataPacket *pDataPacket);
	//申请唯一系列号
	common::STDGUID allocId();
	DropItemData *allocDropItem();
	//添加掉落物品
	DropItemData* getDropItem(int ident, ItemSeries series);
	//移除掉落物品
	void removeDropItem(int ident, ItemSeries series);
	//释放玩家接收的网络数据包对象
	inline void freeBackPlayerRecvPacket(int nGateIndex, CNetPacket *pPacket)
	{
		assert(nGateIndex <(int) ArrayCount(m_WaitFreeGateRecvPackets));
		m_WaitFreeGateRecvPackets[nGateIndex].add(pPacket);
	}
	//添加逻辑事件监听
	inline void addLogicEventListener(int nEventId, LogicEventHandler lpHandler){ m_EventDispatcher.addEventListener(nEventId, lpHandler); }
	//移除逻辑事件监听
	inline void removeLogicEventListener(int nEventId, LogicEventHandler lpHandler){ m_EventDispatcher.removeEventListener(nEventId, lpHandler); }
	//分派逻辑事件
	inline void dispatchLogicEvent(LogicEvent &event){ m_EventDispatcher.dispatchEvent(event); }

	bool startEngine();
	void stopEngine();

protected:
	//逻辑线程主函数
	virtual void OnRountine();

private:
	//处理新玩家进入数据
	void ProcessOpenPlayers(DWORD dwTimeLimit);
	//处理所有在线玩家
	void ProcessPlayers(DWORD dwTimeLimit);
	//提取并分派所有玩家收到的数据包
	void DispatchPlayerRecvPackets();
	//强制销毁所有无效角色
	void DestroyInvalidPlayers();
	//释放所有待释放的玩家已处理数据包列表
	void FreeWaitFreeGateRecvPackets();
	//发起玩家数据存储
	void savePlayer(CPlayer *pPlayer);
	//初始化监听事件
	void initEventListener();
	//释放任务监听事件
	void releaseEventListener();
	//释放所有掉落物品
	void clearDropItems();
	//释放过期的掉落物品
	void removeExpiredDropItems();
public:
	//获取玩家列表
	inline CPlayerList& getPlayerList(){ return m_PlayerList; }
	//获取怪物处理引擎
	inline CMonsterEngine& monsterEngine(){ return m_MonsterEngine; }
	//获取组队管理器
	inline CTeamManager& teamManager(){return m_teamManager;}
	
private:
	CCSLock m_LoginRunLock;//逻辑循环锁
	BOOL m_boStoped;//逻辑线程是否已停止
	SYSTEMTIME m_SysTime;//当前系统时间
	CMiniDateTime m_nDateTime;//当前系统时间（MiniDateTime)
	TICKCOUNT m_dwCurrentTick;//当前系统Tick值
	CMiniDateTime m_nAllocIdTime;//当前使用的唯一ID申请时间
	int m_nAllocIdSeries;//当前使用的唯一ID申请序列值
	CPlayerList m_PlayerList;//玩家列表
	CBList<CPlayer*> m_InvalidPlayerList;//无效玩家列表
	CQueueList<OpenPlayerStruct*> m_OpenPlayerList;//加载数据完成并等待开启的玩家列表
	CCSLock m_OpenPlayerLock;//加载数据完成并等待开启的玩家列表锁
	CListAllocator<OpenPlayerStruct> m_OpenPlayerDataAllocator;//开启玩家结构数据申请器
	int m_nProcOpenPlayerIndex;//当前处理开启玩家列表索引
	int m_nProcPlayerIndex;//当前处理在线玩家列表索引
	CLogicEventDispatcher m_EventDispatcher;//逻辑事件分派器
	CBList<GATERECVPLAYERPACKET> m_PlayerRecvPacketList;//待分派的玩家接收数据包列表
	CBList<CNetPacket*> m_WaitFreeGateRecvPackets[64];//待释放的玩家已处理接收的数据包列表，下标为网关索引
	CMonsterEngine m_MonsterEngine;//怪物处理引擎
	CTeamManager m_teamManager;//组队管理器
	CBList<DropItemData*> m_DropItemList;//掉落物品表
	CBList<INT_PTR> m_FreeDropItemIndexList;//掉落物品表空闲索引表
	TickTime m_dwNextRemoveExpiredDropItemTick;//下次清理过期掉落物品的时间
	TickTime m_dwNextRemoveExpiredDuplicateTick;//下次清理过期掉副本
};

#endif
