#pragma once

class CGameLogManager :
	public lib::thread::CBaseThread
{
public:
	typedef lib::thread::CBaseThread super;
	typedef CBList<LogicEvent>* CEventLogList;
	CGameLogManager();
	~CGameLogManager();
	//设置数据库连接地址和端口
	void setDBHost(const char *sHost, int nPort);
	//设置数据库名称
	void setDBName(const char *sDBName);
	//设置数据库登陆用户
	void setDBUser(const char *sUser, const char *sPswd);
	//设置服务器id
	void setServerId(int serverId);
	//启动事件日志管理器
	bool startManager();
	//停止事件日志管理器
	void stopManager();
	//处理被分派的日志事件
	static void handleDispatchedGameLog(LogicEvent *logEvent);
	//添加游戏日志监听器
	void addGameLogListeners(LogicEventHandler lpEventHandler);
	//移除游戏日志监听器
	void removeGameLogListeners(LogicEventHandler lpEventHandler);
protected:
	virtual void OnRountine();
private:
	bool ConnectSQL();
	//处理事件日志
	void ProcessGameLog();
	//写入事件日志到数据库
	bool RealWriteGameLog();
	//必须先处理完待写事件日志列表 ,才能调用ChangeEventLogList
	void ChangeGameLogList();
	//创建游戏日志表,每天晚上十二点创建
	void CreateGameLogTable();
	void flushLogLists();
	int					    m_ServerId;//服务器ID
	RTL_CRITICAL_SECTION	m_GameLogWriteLock;//日志列表写锁
	CMySQLConenction		m_GameLogSQL;//CGameLogManager数据库连接
	TICKCOUNT				m_dwReconnectTick;//数据库连接时间
	BOOL					m_boStarted;//启动标识
	CBList<LogicEvent>   m_GameLogRecvLists[2];//派送并待处理的事件日志列表，
	CEventLogList			m_pGameLogAppendList;//当前追加的事件日志列表
	CEventLogList			m_pGameLogWriteWaitList;//待写入的事件日志列表
	int						m_GameLogWriteIndex;//写表计数
	bool					m_boAddedListeners;//注册事件日志标记
	time_t					m_createTableTime;//记录表创建时间
	char					m_tableName[32];//记录表名
	time_t					m_timeStamp;//记录时间戳

};
