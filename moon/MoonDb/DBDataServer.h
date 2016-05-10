#ifndef _DB_DATA_SERVER_H_
#define _DB_DATA_SERVER_H_

#include <os/Platform.h>

#include "gameDb/SQLDB.h"



class CDBEngine;
class CDBDataClient;

class CDBDataServer : 
	public CCustomServerSocket
{
public:
	typedef CCustomServerSocket super;

private:
	CDBEngine*						m_pDBEngine;		//所属数据引擎管理器
	CLocalDB						m_LocalDB;			//本地数据库
	CSQLDB							m_SQLDB;			//SQL数据库
	CBList<CDBDataClient*>		m_CloseClientList;	//已经关闭的数据客户端列表
	CGameDataBufferPool				m_GDBufferPool;		//游戏数据缓冲池
	CCSLock							m_ItnMsgLock;		//内部线程消息锁
	TICKCOUNT 					m_dwDeleteOutDataTick;//删除过期日志
protected:
	//覆盖创建连接对象的函数
	CCustomServerClientSocket* CreateClientSocket(SOCKET nSocket, PSOCKADDR_IN pAddrIn);
	//覆盖销毁一个已经建立的客户端对象
	VOID DestroyClientSocket(CCustomServerClientSocket *pClientSocket);
	//覆盖父类处理客户端连接的函数
	VOID ProcessClients();
	//覆盖当客户端连接处理线程启动时的调用函数
	VOID OnSocketDataThreadStart();
	//覆盖当客户端连接处理线程停止前调用函数
	VOID OnSocketDataThreadStop();
	//覆盖父类例行执行函数
	VOID SingleRun();
	//覆盖父类调用例行RUN的函数
	VOID OnRun();

	//向数据客户端投递内部消息，如果nServerId为0，则向所有数据客户端投递消息
	//函数返回向多少个数据客户端投递了消息
	INT PostClientInternalMessages(const int nServerId, UINT uMsg, UINT_PTR uParam1, UINT_PTR uParam2, UINT_PTR uParam3);
private:
	//处理已经关闭的数据客户端对象
	VOID ProcessClosedClients();
	//判断是否所有数据数据均已处理完毕以便安全的停止服务
	BOOL AllDataProcessed();
	//强制释放所有客户端连接占用的内存（销毁连接对象）
	VOID FreeAllClient();

public:
	CDBDataServer(CDBEngine* lpDBEngine);
	~CDBDataServer();

	//获取所属DB引擎
	inline CDBEngine* GetDBEngine(){ return m_pDBEngine; }
	//获取本地数据库对象
	inline CLocalDB* GetLocalDB(){ return &m_LocalDB; }
	//获取SQL数据库对象
	inline CSQLDB* GetSQLDB(){ return &m_SQLDB; }
	//获取指定ID的数据客户端数量，如果nServerId参数为0则返回总的已连接的数据客户端数量
	INT GetAvailableDataClientCount(const int nServerId);
	//申请一个GameDataBuffer
	inline CGameDataBuffer* AllocGameDataBuffer(){ return m_GDBufferPool.AllocDataBuffer(); }
	//获取内部线程消息锁
	inline CCSLock* getItnMsgLock(){ return &m_ItnMsgLock; }
};

#endif

