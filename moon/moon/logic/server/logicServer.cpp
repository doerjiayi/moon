#include "StdAfx.h"

CGameServer*		g_LogicServer = NULL;//全局逻辑服务器
CLogicEngine*		g_LogicEngine = NULL;//全局逻辑引擎
CAccountManager*	g_AccountManager = NULL;//全局账号管理器
CConfigManager*		g_ConfigManager = NULL;//配置管理器
CGateManager*		g_GateManager = NULL;//网关管理器
ScriptSystem*		g_Script = NULL;//脚本系统
CDBManager*			g_DBManager = NULL;// db 管理器
SceneManager*		g_staticSceneManager = NULL;//静态场景管理器
MapArchiverManager* g_MapArchiverManager = NULL;//地图文件管理器
GameCommander*		g_GameCommander = NULL;//GM命令处理器
DuplicateManager*   g_DuplicateManager = NULL;//副本管理器
CGameLogManager*	g_GameLogManager = NULL;//事件日志管理器

CGameServer::CGameServer()
{
	g_LogicServer = this;
	g_LogicEngine = &m_LogicEngine;
	g_AccountManager = &m_AccounManager;
	g_ConfigManager = &m_ConfigManager;
	g_GateManager = &m_GateManager;
	g_DBManager	= &m_DBManager;
	g_GameLogManager = &m_GameLogManager;
	m_bStarted = TRUE;
}

CGameServer::~CGameServer()
{

}

bool CGameServer::loadServerConfig()
{
	static const char szConfigPath[] = "./config/server/ServerConfig.txt";
	CLogicConfig conf;
	if (!conf.loadConfig(szConfigPath))
		return false;

	//如果服务器ID配置为0则使用本机IP的末位作为服务器ID
	if (conf.nServerId == 0)
	{
		char sHostName[128];
		gethostname(sHostName, sizeof(sHostName));
		struct hostent *phe = gethostbyname(sHostName);
		struct in_addr *paddr = (struct in_addr*)(phe->h_addr_list[0]);
		conf.nServerId = paddr->s_addr;
	}

	//应用服务器配置
	m_nServerId = conf.nServerId;
	_asncpytA(m_sServerName, conf.sServerName);

	//应用账号数据库配置
	m_AccounManager.setDBHost(conf.sACDBHost, conf.nACDBPort);
	m_AccounManager.setDBName(conf.sACDBName);
	m_AccounManager.setDBUser(conf.sACDBUser, conf.sACDBPswd);

	//事件日志管理配置
	m_GameLogManager.setServerId(conf.nServerId);
	m_GameLogManager.setDBHost(conf.sGLDBHost, conf.nGLDBPort);
	m_GameLogManager.setDBName(conf.sGLDBName);
	m_GameLogManager.setDBUser(conf.sGLDBUser, conf.sGLDBPswd);

	//应用DBManager配置
	m_DBManager.SetServerHost(conf.sDBHost);
	m_DBManager.SetServerPort(conf.nDBPort);

	//按配置添加网关
	for (int i = 0; i<conf.nGateCount; ++i)
	{
		m_GateManager.addGate(&conf.pGateConfigs[i]);
	}
	return true;
}
 

bool CGameServer::loadDataConfig()
{
	return true;
}

bool CGameServer::startServer()
{
	if (m_bStarted)
	{
		logInfo(" 逻辑服务器 已经启动");
		return true;
	}
	m_bStarted = TRUE;

	if (!ExecSockMgr::InitBase())
	{
		logError("初始化 执行socket管理者 错误");
		return false;
	}
	logInfo("启动逻辑引擎...");
	if (!m_LogicEngine.startEngine())
	{
		logError("启动逻辑引擎 错误");
		return false;
	}
	logInfo("启动账号管理器...");
	if (!m_AccounManager.startManager())
	{
		logError("启动账号管理器 错误");
		return false;
	}
	logInfo("启动db管理器...");
	if (!m_DBManager.startManager())
	{
		logError("启动db管理器 错误");
		return false;
	}
	logInfo("启动网关管理器...");
	if (!m_GateManager.startGateManager())
	{
		logError("启动网关管理器 错误");
		return false;
	}
	logInfo("启动游戏日志管理器...");
	if (!m_GameLogManager.startManager())
	{
		logError("启动游戏日志管理器 错误");
		return false;
	}
	m_GameCommander.init();

	return true;
}

BOOL CGameServer::runGameServer()
{
	m_bStarted = FALSE;
	//加载配置并启动（服务器配置表、全局表数据、静态表数据、启动服务器）
	if (loadServerConfig() && loadGlobalDataConfig() && loadDataConfig() && startServer())
	{
		m_bStarted = TRUE;
		TCHAR sCmdBuf[64];
		while (1)
		{
			fgets(sCmdBuf, 20, stdin);
			if (strncmp(sCmdBuf, "reload", 6) == 0)//重载配置
			{
				const char* szBegin = sCmdBuf;
				const char* szBlank = strchr(szBegin, ' ');//跳过空格(获取配置的名称)
				m_LogicEngine.lockLogic();
				if (szBlank)
				{
					this->reloadDataConfig(szBlank+1);
				}
				else
				{
					logError("配置为空");
				}
				m_LogicEngine.unlockLogic();
			}
			else
			{
				logError("命令不合法");
			}
			moon::OS::osSleep(1);//休眠1毫秒
		}
	}
	return m_bStarted;
}

bool CGameServer::loadGlobalDataConfig()
{
	return true;
}

void CGameServer::reloadDataConfig(const char* param)
{
	if (strncmp(param, "mission", 7) == 0)//任务
	{		
		if (!m_ConfigManager.missionDataProvider.loadConfig())
		{
			logError("quest config load suc!");
			return;
		}
	}
	if (strncmp(param, "monster", 7) == 0)//怪物
	{		
		if (!m_ConfigManager.monsterDataAccessor.loadConfig())
		{
			logError("monster config load suc!");
			return ;
		}
	}
	if (strncmp(param,"item", 4) == 0)//物品
	{		
		if (!m_ConfigManager.itemDataAccessor.loadConfig())
		{
			logError("stdItem config load suc!");
			return;
		}
	}
	if (strncmp(param, "skill", 5) == 0)//技能
	{		
		if (!m_ConfigManager.skillDataAccessor.loadConfig())
		{
			logError("skill config load suc!");
			return;
		}
	}
	if (strncmp(param, "player", 6) == 0)//人物等级配置
	{		
		if (!m_ConfigManager.playerDataProvider.loadConfig())
		{
			logError("player data config load suc!");
			return ;
		}
	}
}
