#ifndef _DBENGINE_H_
#define _DBENGINE_H_

#include "os/Platform.h"


using namespace lib::sync;
using namespace lib::container;

class CDBGateManager;
class CDBSSClient;
class CLogClient;
class CNameSyncClient;
class CDBDataServer;



class CDBEngine
{

private:
	CHAR			m_sServerName[128];			//服务器名称
	CHAR			m_sSQLHost[128];			//数据库地址
	int				m_nSQLPort;					//数据库端口
	CHAR			m_sSQLDBName[128];			//数据库名称
	CHAR			m_sSQLUser[128];			//数据库用户名
	CHAR			m_sSQLPassword[128];		//数据库用户密码
	CHAR			m_sLocalDBDir[256];			//LocalDB目录
	CHAR			m_sBackupPath[256];			//备份目录
	BOOL            m_boEnableCreateCharacter;	//是否可以创建新角色

	CDBDataServer	*m_pDataServer;		//数据服务器
	CCSLock			m_NameFilterLock;	//屏蔽词锁
	PFT_MBCS_CHAR 	m_pNameFilter;		//名称屏蔽词表
	int             m_nBackupInterval; //备份间隔
	int				m_nBackupArchiveDuration; //备份存档存在时间
private:
	//释放屏蔽词列表
	VOID FreeNameFilterWords();

public:
	CDBEngine();
	~CDBEngine();

	inline LPCSTR getServerName(){ return m_sServerName; };
	inline CDBDataServer* getDataServer(){ return m_pDataServer; }
	inline BOOL getEnableCreateCharacter(){ return m_boEnableCreateCharacter;}
	inline LPCSTR getLocalDBPath(){ return m_sLocalDBDir; }
	inline int GetBackupInterval() {return m_nBackupInterval;} //获取备份间隔时间毫秒
	inline LPCSTR GetBackupPath() {return m_sBackupPath;} //获取备份路径
	inline int GetBackupArchiveDuration() {return m_nBackupArchiveDuration;}
	//配置数据库连接对象
	VOID SetupSQLConnection(CMySQLConenction *lpConnection);
	//将名称字符串中首个字符之后的字母全部转换为小写
	LPCSTR LowerCaseNameStr(LPSTR sNameStr);
	//检查名称字符串的合法性，包括对控制字符以及屏蔽字的检查，如果名称不合法将返回FALSE，否则返回TRUE
	BOOL CheckNameStr(LPCSTR sNameStr);
	//加载名称屏蔽词列表，返回-1表示发生错误，否则表示加载的屏蔽词数量
	INT LoadNameFilterWords();
	


	//设置服务器名称
	VOID SetServerName(LPCSTR sSrvName);
	//设置SQL数据库连接配置
	VOID SetSQLConfig(LPCSTR sHost, const int nPort, LPCSTR sDBName, LPCSTR sDBUser, LPCSTR sUserPassword);
	//设置LocalDB数据库路径
	VOID SetLocalDBPath(LPCSTR sPath);
	//设置备份路径
	VOID SetBackupPath(LPCSTR sPath);

	//设置数据服务的绑定地址和端口
	VOID SetDataServiceAddress(LPCTSTR sBindHost, const int nBindPort);
	//设置是否可以创建新角色
	VOID SetEnableCreateCharcater(BOOL enable);
	//设置备份时间毫秒
	VOID SetBackupInterval(int nBackupInterval);
	//设置备份存档存在时间
	VOID SetBackupArchiveDuration(int nBackupArchiveDuration);
	BOOL Startup();
	VOID Shutdown();
};

#endif

