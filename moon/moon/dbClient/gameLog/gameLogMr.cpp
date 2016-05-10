#include "StdAfx.h"
#include "gameLogMr.h"

CGameLogManager::CGameLogManager()
	:super(TRUE)
{
	m_dwReconnectTick = 0;
	m_GameLogWriteIndex = 0;
	m_createTableTime = 0;
	m_timeStamp = 0;
	m_ServerId = 0;
	memset(m_tableName,0,sizeof(m_tableName));
	m_boAddedListeners = false;
	m_boStarted = FALSE;
	InitializeCriticalSection(&m_GameLogWriteLock);
	m_pGameLogAppendList = &m_GameLogRecvLists[0];
	m_pGameLogWriteWaitList = &m_GameLogRecvLists[1];
	resume();
}

CGameLogManager::~CGameLogManager()
{
	stopManager();
	terminate();
	waitFor();
	DeleteCriticalSection( &m_GameLogWriteLock);
}

void CGameLogManager::setDBHost(const char *sHost, int nPort)
{
	m_GameLogSQL.SetServerHost(sHost);
	m_GameLogSQL.SetServerPort(nPort);
}

void CGameLogManager::setDBName(const char *sDBName)
{
	m_GameLogSQL.SetDataBaseName(sDBName);
}

void CGameLogManager::setDBUser(const char *sUser, const char *sPswd)
{
	m_GameLogSQL.SetUserName(sUser);
	m_GameLogSQL.SetPassWord(sPswd);
}

bool CGameLogManager::startManager()
{
	if (false == m_boAddedListeners)
	{
		addGameLogListeners(CGameLogManager::handleDispatchedGameLog);
		m_boAddedListeners = true;
	}

	if(!m_boStarted)
	{
		m_boStarted = TRUE;
	}
	return true;
}

void CGameLogManager::stopManager()
{
	if (m_boAddedListeners)
	{
		removeGameLogListeners(CGameLogManager::handleDispatchedGameLog);
		m_boAddedListeners = false;
	}

	if (m_boStarted)
	{
		m_boStarted = FALSE;
	}
}

bool CGameLogManager::ConnectSQL()
{
	if (m_GameLogSQL.Connected())
		return true;

	TICKCOUNT dwCurTick = _getTickCount();
	if (dwCurTick >= m_dwReconnectTick)
	{
		m_dwReconnectTick = dwCurTick + 5000;
		if (m_GameLogSQL.Connect() != FALSE)
		{
			return true;
		}
	}

	return false;
}

void CGameLogManager::OnRountine()
{
	while (!terminated())
	{
		if (m_boStarted)
		{
			ConnectSQL();
			CreateGameLogTable();
			ProcessGameLog();
		}
		moon::OS::osSleep(1);
	}
	flushLogLists();
}

void CGameLogManager::ProcessGameLog()
{
	if(!m_GameLogSQL.Connected())//数据库未就绪
		return;

	while (m_GameLogWriteIndex <10)
	{
		m_GameLogWriteIndex++;
		bool boLeftWaitWrite = RealWriteGameLog();
		if (false == boLeftWaitWrite)//没有需要写的游戏日志
			break;
	}
	m_GameLogWriteIndex = 0;
}

bool CGameLogManager::RealWriteGameLog()
{
	if (0 == m_createTableTime)//表未创建
		return false;
	static char sqlStr[102400];
	sprintf(sqlStr,"insert into %s values ",m_tableName);
	const static int sqlStartLen = (int)strlen(sqlStr);//初始长度不变

	const static char splitStr[] = ",";//分隔符
	const char *pSplitStrUsed = splitStr;
	//每次最大写入记录数
	//sqlStr 长度为102400字节，一条记录长度最大是一千字节左右,每次最多写入100个日志记录
	const static int maxReocrdWrite = 100;

	if (0 == m_pGameLogWriteWaitList->count())//没有要写的游戏日志
	{
		//没有待写事件日志列表,才更换添加事件日志列表
		ChangeGameLogList();//没有要写的游戏日志
		if (0 == m_pGameLogWriteWaitList->count())
			return false;
	}
	INT_PTR waitWriteIndex = m_pGameLogWriteWaitList->count() - 1;
	LogicEvent* eventLogList = *m_pGameLogWriteWaitList;
	int writedCount = 0;//记录计数
	char *ptr = sqlStr + sqlStartLen;//记位置指针
	for (;waitWriteIndex>-1&& writedCount++ < maxReocrdWrite;waitWriteIndex--)
	{
		LogicEvent& logicEvent = eventLogList[waitWriteIndex];
		assert(logicEvent.sender);
		CPlayer* player = (CPlayer*)logicEvent.sender;
		if (maxReocrdWrite == writedCount || 0 == waitWriteIndex)pSplitStrUsed = "";//分隔符,末尾不需要
		switch (logicEvent.eventId)
		{
			//sql字段  事件号 角色id 角色名 对方id 对方名 参数1 参数2 参数3 参数4 参数5 参数6 时间
			/* 玩家基本事件定义 */
		case leLogin ://玩家登陆
			{
				ptr += sprintf(ptr,"(%d,%llu,'%s',%d,'%s','%s','%s','%s','%s','%s','%s','%ld')%s",
					logicEvent.eventId,player->m_EntityId.llid,player->m_sName, 0,"",
					"","","","","","",logicEvent.tm,pSplitStrUsed);
			}break;
		case leEnterGamer://玩家进入游戏
			{
				ptr += sprintf(ptr,"(%d,%llu,'%s',%d,'%s','%s','%s','%s','%s','%s','%s','%ld')%s",
					logicEvent.eventId,player->m_EntityId.llid,player->m_sName, 0,"",
					"","","","","","",logicEvent.tm,pSplitStrUsed);
			}break;
		case leOffline://玩家离线
			{
				ptr += sprintf(ptr,"(%d,%llu,'%s',%d,'%s','%s','%s','%s','%s','%s','%s','%ld')%s",
					logicEvent.eventId,player->m_EntityId.llid,player->m_sName, 0,"",
					"","","","","","",logicEvent.tm,pSplitStrUsed);
			}break;
		case leAddItem://添加道具
			{
				ptr += sprintf(ptr,"(%d,%llu,'%s',%d,'%s','%s','%s','%s','%s','%s','%s','%ld')%s",
					logicEvent.eventId, player->m_EntityId.llid, player->m_sName,   
					0,"",logicEvent.s1.c_str(), logicEvent.s2.c_str(), "","","","",logicEvent.tm,pSplitStrUsed);
			}break;
		case leDelItem:
			{
				ptr += sprintf(ptr,"(%d,%llu,'%s',%d,'%s','%s','%s','%s','%s','%s','%s','%ld')%s",
					logicEvent.eventId, player->m_EntityId.llid, player->m_sName,   
					0,"",logicEvent.s1.c_str(), logicEvent.s2.c_str(), "","","","",logicEvent.tm,pSplitStrUsed);
			}break;
//#pragma __CPMSG__(TODO: miros :  需要根据消息体来添加具体消息的sql语句)
		default:
			assert(0);
			break;
		}
	}
	ptr[0] = 0;
	size_t sqlStrLen = ptr-sqlStr;
	if (0 == m_GameLogSQL.RealExec(sqlStr,sqlStrLen))
	{
		//数据库写入成功
		m_GameLogSQL.ResetQuery();
		m_pGameLogWriteWaitList->trunc(waitWriteIndex+1);
		if (-1 == waitWriteIndex)
			return false;//没有要写的游戏日志
	}
	else
	{
		logError("try to write game log error\n");
	}
	return true;//还有没写完的游戏日志
}

void CGameLogManager::ChangeGameLogList()
{
	EnterCriticalSection(&m_GameLogWriteLock);
	//交换待处理游戏日志列表与添加游戏日志列表
	CEventLogList pTempList = m_pGameLogWriteWaitList;
	m_pGameLogWriteWaitList = m_pGameLogAppendList;
	m_pGameLogAppendList = pTempList;

	LeaveCriticalSection(&m_GameLogWriteLock);
}

void CGameLogManager::handleDispatchedGameLog( LogicEvent *logEvent )
{
	if (g_GameLogManager)
	{
		EnterCriticalSection(&g_GameLogManager->m_GameLogWriteLock);
		g_GameLogManager->m_pGameLogAppendList->add(*logEvent);
		LeaveCriticalSection(&g_GameLogManager->m_GameLogWriteLock);
	}
	else logError("CEventLogManager add CLogicEvent error\n");  
}

void CGameLogManager::addGameLogListeners(LogicEventHandler lpEventHandler)
{
	int i;
	//注册所有事件日志
	/* 玩家基本事件定义 */
	for (i = leActorEventEnd-1;i >=leActorEventBegin;i--)
	{
		g_LogicEngine->addLogicEventListener(i,lpEventHandler);
	}
	/* 玩家物品事件定义 */
	for (i = leActorItemEventEnd-1;i >=leActorItemEventBegin;i--)
	{
		g_LogicEngine->addLogicEventListener(i,lpEventHandler);
	}
}

void CGameLogManager::removeGameLogListeners( LogicEventHandler lpEventHandler )
{
	int i;
	//注销所有事件日志
	/* 玩家基本事件定义 */
	for (i = leActorEventEnd-1;i >leActorEventBegin;i--)
	{
		g_LogicEngine->removeLogicEventListener(i,lpEventHandler);
	}
	/* 玩家物品事件定义 */
	for (i = leActorItemEventEnd-1;i >=leActorItemEventBegin;i--)
	{
		g_LogicEngine->removeLogicEventListener(i,lpEventHandler);
	}
}

void CGameLogManager::CreateGameLogTable()
{
	if (!m_GameLogSQL.Connected())//数据库未就绪
		return ;
	::time(&m_timeStamp);
	const static int oneDayTime = 86400;
	//判断是否大于一天且大于每晚12点 否则不创建表
	if ((int)(m_timeStamp/oneDayTime) == (int)(m_createTableTime/oneDayTime))
		return ;

	SYSTEMTIME sysTime;
	GetLocalTime(&sysTime);
	static char tmpTableName[32];
	sprintf(tmpTableName,"gamelog_%03d_%d%02d%02d",m_ServerId,sysTime.wYear,sysTime.wMonth,sysTime.wDay);

	static char dropTableSql[64];
	sprintf(dropTableSql,"DROP TABLE IF EXISTS `%s`",tmpTableName);
	const static int  dropSqlStrLen = (int)strlen(dropTableSql);////删除表sql长度不变
	if (0 == m_GameLogSQL.RealExec(dropTableSql,dropSqlStrLen))
	{
		m_GameLogSQL.ResetQuery();
	}
	else
	{
		logError("try to drop table %s error\n",tmpTableName);  
		return ;
	}
	static char createTableSql[1024]; 
	//字符串必须顶格 否者会变长
	sprintf(createTableSql,"CREATE TABLE `%s` (\
						   `eventId` bigint(20) NOT NULL,\
						   `playerId` bigint(20) NOT NULL,\
						   `playerName` varchar(48) NOT NULL,\
						   `targetId` bigint(20) DEFAULT NULL,\
						   `targetName` varchar(48) DEFAULT NULL,\
						   `field1` varchar(128) DEFAULT NULL,\
						   `field2` varchar(128) DEFAULT NULL,\
						   `field3` varchar(128) DEFAULT NULL,\
						   `field4` varchar(128) DEFAULT NULL,\
						   `field5` varchar(128) DEFAULT NULL,\
						   `field6` varchar(128) DEFAULT NULL,\
						   `time` bigint(20) DEFAULT NULL,\
						   KEY `eventlog` (`eventId`,`playerId`) USING BTREE\
						   ) ENGINE=MyISAM DEFAULT CHARSET=utf8",tmpTableName);//eventId,playerId 索引
	const static int  createSqlStrLen = (int)strlen(createTableSql);//创建表sql长度不变

	if (0 == m_GameLogSQL.RealExec(createTableSql,createSqlStrLen))
	{
		m_GameLogSQL.ResetQuery();
	}
	else
	{
		logError("try to create table %s error\n",tmpTableName);  
		return ;
	}
	memcpy(m_tableName,tmpTableName,sizeof(m_tableName));//创建成功才记录新表名
	m_createTableTime = m_timeStamp;			//创建成功才记录新时间
}

void CGameLogManager::setServerId( int serverId )
{
	assert(serverId >0);
	m_ServerId = serverId;
}

void CGameLogManager::flushLogLists()
{
	while (m_GameLogSQL.Connected())
	{
		if (0 == m_pGameLogAppendList->count()&&0 == m_pGameLogWriteWaitList->count())break;
		ProcessGameLog();
	} 
	m_pGameLogAppendList->empty();
	m_pGameLogWriteWaitList->empty();
}





