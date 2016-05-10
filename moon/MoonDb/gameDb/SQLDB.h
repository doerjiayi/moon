#pragma once

//#include "DBDataServer.h"
#include <thread/Thread.h>
#include <container/queueList.h>

using namespace lib::thread;
using namespace lib::container;

class CDBDataServer;

class CSQLDB : 
	public lib::thread::CBaseThread
{
	friend class CDBDataServer;
public:
	typedef lib::thread::CBaseThread Inherited;
	typedef lib::container::CQueueList<GameDBType::CharDesc*>	CharDescUpdateQueue;

private:
	CDBDataServer*				m_pDataServer;
	BOOL						m_boStarted;
	CMySQLConenction			m_SQL;					//SQL数据库连接对象
	TICKCOUNT					m_ReconenctSQLTick;		//重新连接SQL数据库的时间
	lib::sync::CCSLock	m_NewCharLock;			//新角色列表锁
	CharDescUpdateQueue			m_NewCharList;			//新角色列表
	lib::sync::CCSLock	m_UpdateCharDescLock;	//角色描述更新列表锁
	CharDescUpdateQueue			m_UpdateCharDescList;	//角色描述更新列表
	CGameDataBufferReaderPool	m_GDBReaderPool;		//游戏数据更新包读取对象池
	CGameDataBufferReaderQueue	m_CharDataUpdateList;	//角色数据更新数据队列
	CGameDataBufferReaderQueue	m_GuildDataUpdateList;	//帮会数据更新数据队列
public:
	CSQLDB();
	~CSQLDB();

public:
	//添加新角色
	inline VOID PostAddNewChar(GameDBType::CharDesc *pCharDesc)
	{
		m_NewCharList.append(pCharDesc);
	}
	//更新角色描述数据
	inline VOID PostUpdateCharDesc(GameDBType::CharDesc *pCharDesc)
	{
		m_UpdateCharDescList.append(pCharDesc);
	}
	//更新角色数据
	inline VOID PostUpdateCharData(CGameDataBuffer *pBuffer)
	{
		CGameDataBufferReader *pGDBReader = m_GDBReaderPool.AllocBufferReader();
		pGDBReader->SetDataBuffer(pBuffer);
		m_CharDataUpdateList.append(pGDBReader);
	}
	//更新帮会数据
	inline VOID PostUpdateGuildData(CGameDataBuffer *pBuffer)
	{
		CGameDataBufferReader *pGDBReader = m_GDBReaderPool.AllocBufferReader();
		pGDBReader->SetDataBuffer(pBuffer);
		m_GuildDataUpdateList.append(pGDBReader);
	}

public:
	//设置数据库主机
	VOID SetDBHost(LPCTSTR sHost, INT nPort);
	//设置数据库名称
	VOID SetDBName(LPCTSTR sName);
	//设置数据库用户名密码
	VOID SetDBUser(LPCTSTR sUser, LPCTSTR sPassword);
	//启动
	VOID Start();
	//停止
	VOID Stop();
	//是否所有的更新操作均已完成
	BOOL IsAllUpdateComplete();

protected:
	//覆盖线程例行执行函数
	VOID OnRountine();
	//处理新加角色更新请求
	VOID ProcessAddNewChars(TICKCOUNT dwTimeLimit);
	//处理角色数据更新请求
	VOID ProcessCharDataUpdate(TICKCOUNT dwTimeLimit);
	//处理帮会数据更新请求
	VOID ProcessGuildDataUpdate(TICKCOUNT dwTimeLimit);
	//处理角色描述更新请求
	VOID ProcessUpdateCharDescs(TICKCOUNT dwTimeLimit);
private:
	//连接SQL数据库
	BOOL ConnectSQLDB();
	//向SQL数据库添加新角色
	VOID AddNewCharToDB(GameDBType::CharDesc *pCharDesc);
	//向SQL数据库更新角色数据
	VOID UpdateCharDataToDB(CGameDataBufferReader *pBufferReader);
	//向SQL数据库更新帮会数据
	VOID UpdateGuildDataToDB(CGameDataBufferReader *pBufferReader);
	
	//更新角色描述数据到SQL 数据库
	void UpdateCharDescDataToDB(CGameDataBufferReader *pBufferReader, INT64* pCharId);
	//更新帮会基本信息到 SQL 数据库
	void UpdateGuildBaseDataToDB(CGameDataBufferReader *pBufferReader, INT64* pGuildId);
};
