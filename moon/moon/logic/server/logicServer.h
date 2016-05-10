#ifndef LOGIC_SERVER_H__
#define LOGIC_SERVER_H__



class CGameServer
{
public:
	CGameServer();
	~CGameServer();
	BOOL runGameServer();
	//获取服务器ID
	inline INT getServerId(){ return m_nServerId; }
	//获取服务器名称
	inline LPCSTR getServerName(){ return m_sServerName; }

	//读取逻辑服务器配置
	bool loadServerConfig();
	//读取全局逻辑数据配置
	bool loadGlobalDataConfig();
	//读取逻辑数据配置
	bool loadDataConfig();

	//启动逻辑服务器
	bool startServer();
	//停止逻辑服务器
	void stopServer();
	//重新加载配置
	void reloadDataConfig(const char* param);
	//加锁逻辑线程，在解锁之前逻辑线程将暂停运行
	//此操作仅适用于其他线程需要对逻辑数据进行更新而需要确保数据安全期间调用，例如重新读取配置。
	inline void logicDoLock() { m_LogicRunningLock.Lock(); }
	//解锁逻辑线程
	inline void logicDoUnlock() { m_LogicRunningLock.Unlock(); }
private:
	BOOL				m_bStarted;
	INT					m_nServerId;
	CHAR				m_sServerName[48];
	CLogicEngine		m_LogicEngine;
	CAccountManager		m_AccounManager;
	CConfigManager		m_ConfigManager;
	CGateManager		m_GateManager;
	CGameLogManager		m_GameLogManager;
	GameCommander		m_GameCommander;
	CDBManager			m_DBManager;
	CCSLock				m_LogicRunningLock;//逻辑循环锁
};

extern CGameServer*		g_LogicServer;//全局逻辑服务器
extern CLogicEngine*		g_LogicEngine;//全局逻辑引擎
extern CAccountManager*		g_AccountManager;//全局账号管理器
extern CConfigManager*		g_ConfigManager;//配置管理器
extern CGateManager*		g_GateManager;//网关管理器
extern CDBManager*			g_DBManager;// db 管理器
extern SceneManager*		g_staticSceneManager;//静态场景管理器
extern MapArchiverManager*	g_MapArchiverManager;//地图文件管理器
extern ScriptSystem*		g_Script;//脚本系统
extern DuplicateManager*    g_DuplicateManager;//副本管理器
extern GameCommander*		g_GameCommander;//GM命令处理器
extern CGameLogManager*		g_GameLogManager;//事件日志管理器

#endif
