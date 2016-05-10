#pragma once
#include "thread/Thread.h"
#include "ZipBackup.h"

class CLocalDB :
	public lib::thread::CBaseThread
{
public:
	typedef lib::thread::CBaseThread Inherited;

public:
	typedef lib::container::CQueueList<GameDBType::CharDesc*>	CharDescUpdateQueue;
	typedef CBaseObjAllocator<GameDBType::CharDesc>				CharDescAllocator;

private:
	CCustomFileDB					m_CharDescDB;	//角色描述数据库
	lib::sync::CCSLock		m_CharDescDBLock;
	CCustomFileDB					m_CharDataDB;	//角色数据库
	lib::sync::CCSLock		m_CharDataDBLock;
	CCustomFileDB					m_GuildDataDB;	//帮会数据库
	lib::sync::CCSLock		m_GuildDataDBLock;
	BOOL							m_boOpened;

	CharDescAllocator				m_CharDescAllocator;//角色描述对象内存申请器
	lib::sync::CCSLock		m_CharDescLock;		//角色描述列表锁
	GameDBType::CharIdSortList		m_CharIdSortList;	//基于角色ID排序的角色描述列表，主要用于通过ID找到角色描述数据
	GameDBType::CharNameSortList	m_CharNameSortList;	//基于角色名称排序的角色描述列表，主要用于判断角色名称是否存在或通过角色名称找到ID
	GameDBType::UserIdSortList		m_UserIdSortList;	//基于账号ID排序的角色描述列表，主要用于查询账号所属角色列表

	lib::sync::CCSLock		m_CharDescUpdateLock;	//角色描述更新队列锁
	CharDescUpdateQueue				m_CharDescUpdateList;	//角色描述更新队列
	CGameDataBufferReaderPool		m_GDBReaderPool;		//游戏数据更新包读取对象池
	CGameDataBufferReaderQueue		m_CharDataUpdateList;	//角色数据更新数据队列
	CGameDataBufferReaderQueue		m_GuildDataUpdateList;	//帮会数据更新数据队列
	CZipBackup						m_ZipBackup;//压缩备份文件对象
	TCHAR							m_szDBPath[MAX_PATH]; //数据库目录
	TCHAR							m_szBackupPath[MAX_PATH]; //数据库备份目录
	int								m_nBackupInterval; //备份间隔毫秒
public:
	CLocalDB();
	~CLocalDB();

	//打开数据库
	BOOL OpenDB(LPCSTR sDBPath);
	//关闭当前打开的数据库
	VOID CloseDB();
	//是否所有的更新操作均已完成
	BOOL IsAllUpdateComplete();

	//通过角色ID获取角色描述
	GameDBType::CharDesc* GetCharDesc(INT64 nCharId) const;
	//通过角色名称获取角色描述
	GameDBType::CharDesc* GetCharDesc(LPCSTR sCharName) const;
	//通过用户ID获取角色描述列表。
	//参数pList是用于存储角色描述指针的列表，nMaxCount表示pList列表最多可以存储多少个描述数据。
	//参数nServerId指定获取哪个服务器ID下的角色列表，如果未0则表示获取任何服务器的角。
	//参数boAvaliableOnly表示是否仅获取没有被删除和禁用的角色。
	//函数返回实际向pList填充了多少个角色描述指针。如果nMaxCount为0则返回此ID共有多少个角色描述
	//且不会向pList中填充内容。
	INT GetUserCharDescList(INT64 nUserId, INT nServerId, GameDBType::CharDesc **pList, INT nMaxCount, 
		BOOL boAllowDeleted, BOOL boAllowDisabled) const;



	//获取用户ID下的可用（未删除和禁用的）角色数量
	inline INT GetUserAvaliableCharCount(INT64 nUserId, INT nServerId)
	{ return GetUserCharDescList(nUserId, nServerId, NULL, 0, FALSE, FALSE); }
	//获取角色数量
	inline INT GetCharCount(){ return (INT)m_CharDescDB.getDataCount(); }
	//获取帮会数量
	inline INT GetGuildCount(){ return (INT)m_GuildDataDB.getDataCount(); }
	//获取角色数据，如果dwBufferSize为0则仅查询数据长度
	inline DWORD GetCharData(INT64 nCharId, LPVOID lpBuffer, DWORD dwBufferSize)
	{
		return (DWORD)m_CharDataDB.get(nCharId, lpBuffer, dwBufferSize);
		return 0;
	}
	//获取帮会ID列表
	//参数nIndex表示从第几个ID开始填充pIdList列表并且最多填充dwListCount个
	//函数返回值表示实际向pIdList中填充的ID数量，返回值可能比dwListCount小。
	inline DWORD GetGuildIdList(DWORD nIndex, PINT64 pIdList, DWORD dwListCount)
	{
		return (DWORD)m_GuildDataDB.getIdList(nIndex, pIdList, dwListCount);
	}
	//获取帮会数据，如果dwBufferSize为0则仅查询数据长度
	inline DWORD GetGuildData(INT64 nGuildId, LPVOID lpBuffer, DWORD dwBufferSize)
	{
		return (DWORD)m_GuildDataDB.get(nGuildId, lpBuffer, dwBufferSize);
		return 0;
	}

	//重命名角色
	BOOL RenameChar(INT64 nCharId, LPCSTR sCharName);
	//设置角色状态（角色状态 正常0,已禁用1,已删除2 要和数据库一致）
	GameDBType::CharDesc* SetCharState(LPCSTR sCharName, BYTE bState);
	//在等待写入磁盘中的队列数据中获取角色数据，防止客户端快速重
	//新登陆时因队列中的数据尚未保存而直接获取老的磁盘文件数据而产生的回档现象。2012-5-15 谭建冲  
	DWORD GetCharDataInUpdateList(INT64 nCharId, CDataPacket& pack);

public:
	//更新角色描述
	inline VOID PostUpdateCharDesc(GameDBType::CharDesc *pCharDesc)
	{ m_CharDescUpdateList.append(pCharDesc); }
	//更新角色数据
	VOID PostUpdateCharData(CGameDataBuffer *pGameDataBuffer);
	//更新帮会数据
	VOID PostUpdateGuildData(CGameDataBuffer *pGameDataBuffer);
	//创建角色
	GameDBType::CharDesc* AddChar(INT nServerId, INT64 nUserId, LPCSTR sAccount, LPCSTR sCharName, INT nJob, INT nGender);	
	VOID SetBackupInterval(int nBackupIntervalMinute);
	VOID SetBackupPath(LPCSTR sBackupPath);
	//设置备份存档存在时间(传入是小时)
	VOID SetBackupArchiveDuration(int nBackupArchiveDuration);
protected:
	//覆盖线程例行执行函数
	VOID OnRountine();

private:
	//Zip 打包处理类
	//从CharDesc数据库中读取所有角色描述
	BOOL LoadAllCharDesc();
	//申请DataPacket对象
	CDataPacket* AllocDataPacket();
	//处理角色描述更新请求
	VOID ProcessCharDescUpdate(TICKCOUNT dwTimeLimit);
	//处理角色数据更新请求
	VOID ProcessCharDataUpdate(TICKCOUNT dwTimeLimit);
	//处理帮会数据更新请求
	VOID ProcessGuildDataUpdate(TICKCOUNT dwTimeLimit);
	//把数据文件复制备份
	BOOL BackupFDBFiles();
};

