#include "StdAfx.h"
#include "DBDataServer.h"

using namespace moon::OS;


CDBDataServer::CDBDataServer(CDBEngine* lpDBEngine)
{
	m_pDBEngine = lpDBEngine;
	SetServiceName("数据");
	m_SQLDB.m_pDataServer = this;
	m_dwDeleteOutDataTick = 0;
}

CDBDataServer::~CDBDataServer()
{

}

CCustomServerClientSocket* CDBDataServer::CreateClientSocket(SOCKET nSocket, PSOCKADDR_IN pAddrIn)
{
	return new CDBDataClient(this, nSocket, pAddrIn);
}

VOID CDBDataServer::DestroyClientSocket(CCustomServerClientSocket *pClientSocket)
{
	m_CloseClientList.add((CDBDataClient*)pClientSocket);
}

VOID CDBDataServer::ProcessClients()
{
	super::ProcessClients();
	ProcessClosedClients();
}
//CDBDataServer作为数据逻辑引擎的成员在其初始化时会启动
//CDBDataServer 是服务器自定义socket封装类  ，在其数据处理线程（ServerSocketDataThreadRoutine）
//启动时会调用OnSocketDataThreadStart() 这样文件数据库线程和mysql处理线程也就跟着启动了
VOID CDBDataServer::OnSocketDataThreadStart()
{
	//mysql处理线程，数据也会写到mysql，主要用于网站查询统计，需要删除过期的数据，
	//文件数据库是用于游戏逻辑数据处理，游戏的数据读写是由文件数据库线程来处理
	m_LocalDB.SetBackupInterval(m_pDBEngine->GetBackupInterval());
	m_LocalDB.SetBackupPath(m_pDBEngine->GetBackupPath());
	m_LocalDB.SetBackupArchiveDuration(m_pDBEngine->GetBackupArchiveDuration());
	if (m_LocalDB.OpenDB(m_pDBEngine->getLocalDBPath()))
		logInfo( _T("LocalDB数据库已经打开！"));
	else logError( _T("LocalDB数据库无法打开！"));
	m_SQLDB.Start();
}

VOID CDBDataServer::OnSocketDataThreadStop()
{
	super::OnSocketDataThreadStop();//调用父类的处理函数以便关闭所有连接

	logInfo( _T("正在等待所有数据客户端的数据处理完毕……"));
	do 
	{
		SingleRun();
		osSleep(10);
	}
	while ( !AllDataProcessed() );

	//强制释放所有客户端连接占用的内存（销毁连接对象）
	FreeAllClient();
	m_SQLDB.Stop();
	m_LocalDB.CloseDB();
	logInfo( _T("所有数据客户端的数据已处理完毕！"));
}

VOID CDBDataServer::SingleRun()
{
//	TICKCOUNT dwCurTick = _getTickCount();
	super::SingleRun();
}

#define DELETE_OUT_DATE_DATE 1

VOID CDBDataServer::OnRun()
{
	TICKCOUNT dwCurTick = _getTickCount();
	//每分钟从数据库中删除一次过期数据，过期数据在保存角色数据的时候将角色对应的
	//物品、技能、任务等数据的charid字段更新为了0（将多次零散的SQL delete操作合并
	//为多次update，一次delete以提高数据库操作性能）。
#if DELETE_OUT_DATE_DATE
	if (m_SQLDB.m_SQL.Connected() && dwCurTick >= m_dwDeleteOutDataTick )
	{
		m_dwDeleteOutDataTick = dwCurTick + 60 * 1000;
		//删除过期背包物品
		m_SQLDB.m_SQL.Exec( "delete from charbag where charid = 0;" );
		m_SQLDB.m_SQL.ResetQuery();
		//删除过期装备物品
		m_SQLDB.m_SQL.Exec( "delete from charequip where charid = 0;" );
		m_SQLDB.m_SQL.ResetQuery();
		//删除过期仓库物品
		m_SQLDB.m_SQL.Exec( "delete from charstorage where charid = 0;" );
		m_SQLDB.m_SQL.ResetQuery();
		//删除过期技能
		m_SQLDB.m_SQL.Exec( "delete from charmagic where charid = 0;" );
		m_SQLDB.m_SQL.ResetQuery();
		//删除过期任务进度
		m_SQLDB.m_SQL.Exec( "delete from charroleitem where charid = 0;" );
		m_SQLDB.m_SQL.ResetQuery();
		//删除过期完成任务数据
		m_SQLDB.m_SQL.Exec( "delete from charfinishrole where charid = 0;" );
		m_SQLDB.m_SQL.ResetQuery();
		//删除过期的法宝数据
		m_SQLDB.m_SQL.Exec( "delete from chartalisman where charid = 0;" );
		m_SQLDB.m_SQL.ResetQuery();
		//删除过期的宠物数据
		m_SQLDB.m_SQL.Exec( "delete from charmonster where charid = 0;" );
		m_SQLDB.m_SQL.ResetQuery();
		//删除过期的宠物装备数据
		m_SQLDB.m_SQL.Exec( "delete from charmonsterequip where charid = 0;" );
		m_SQLDB.m_SQL.ResetQuery();
	}
#endif
}

INT CDBDataServer::PostClientInternalMessages(const int nServerId, UINT uMsg, UINT_PTR uParam1, UINT_PTR uParam2, UINT_PTR uParam3)
{
	INT_PTR i, nResult = 0;
	CDBDataClient *pClient;

	for (i=m_ClientList.count()-1; i>-1; --i)
	{
		pClient = (CDBDataClient*)m_ClientList[i];
		if ( pClient->registed() )
		{
			if ( !nServerId || pClient->m_nServerId == nServerId )
			{
				pClient->PostMsg(uMsg, uParam1, uParam2, uParam3);
				nResult++;
			}
		}
	}
	return (INT)nResult;
}

VOID CDBDataServer::ProcessClosedClients()
{
	INT_PTR i;
	CDBDataClient *pClient;
	TICKCOUNT dwCurTick = _getTickCount();

	//必须降序循环，因为连接可能在循环中被移除
	for ( i=m_CloseClientList.count()-1; i>-1; --i )
	{
		pClient = m_CloseClientList[i];
		//连接被关闭后依然要调用Run函数，因为可能有重要的网络数据或逻辑数据没有处理完
		pClient->Run();
		//连接关闭5分钟后再释放连接对象
		if ( dwCurTick - pClient->m_dwClosedTick >= 5 * 60 * 1000 )
		{
			m_CloseClientList.remove(i);
			delete pClient;
		}
	}
}

BOOL CDBDataServer::AllDataProcessed()
{
	INT_PTR i;
	CDBDataClient *pClient;

	//本地数据库仍有未提交的数据则仍需继续处理
	if ( !m_LocalDB.IsAllUpdateComplete() )
		return FALSE;

	//SQL数据库仍有未提交的数据则仍需继续处理
	if ( !m_SQLDB.IsAllUpdateComplete() )
		return FALSE;

	//判断数据客户端的数据是否处理完毕
	for ( i=m_ClientList.count()-1; i>-1; --i )
	{
		pClient = (CDBDataClient*)m_ClientList[i];
		if ( !pClient->registed() )
			continue;
		if ( pClient->HasRemainData() )
			return FALSE;
	}
	for ( i=m_CloseClientList.count()-1; i>-1; --i )
	{
		pClient = m_CloseClientList[i];
		if ( !pClient->registed() )
			continue;
		if ( pClient->HasRemainData() )
			return FALSE;
	}
	return TRUE;
}

VOID CDBDataServer::FreeAllClient()
{
	INT_PTR i;
	CDBDataClient *pClient;

	//关闭所有客户端
	CloseAllClients();

	//销毁所有连接
	for ( i=m_CloseClientList.count()-1; i>-1; --i )
	{
		pClient = m_CloseClientList[i];
		delete pClient;
	}
	m_CloseClientList.clear();
}

INT CDBDataServer::GetAvailableDataClientCount(const int nServerId)
{
	if ( nServerId == 0 )
	{
		return (INT)m_ClientList.count();
	}

	INT_PTR i, nResult = 0;
	CDBDataClient *pClient;

	m_ClientList.lock();
	for ( i=m_ClientList.count() - 1; i > - 1; --i )
	{
		pClient = (CDBDataClient*)m_ClientList[i];
		if ( pClient->connected() && pClient->m_nServerId == nServerId )
		{
			nResult++;
		}
	}
	m_ClientList.unlock();
	return (INT)nResult;
}
