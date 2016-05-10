#ifndef __ACCOUNT_MANAGER_H__
#define __ACCOUNT_MANAGER_H__
using namespace common::time;
using namespace lib::container;

class CAccountManager :
	public lib::thread::CBaseThread
{
public:
	typedef lib::thread::CBaseThread super;

public:
	CAccountManager();
	~CAccountManager();

	//添加用户登陆请求
	void requestLogin(common::PSERVERUSERHANDLE pUserHandle, const char *sAccount, const char *sPasswd);

	//设置数据库连接地址和端口
	void setDBHost(const char *sHost, int nPort);
	//设置数据库名称
	void setDBName(const char *sDBName);
	//设置数据库登陆用户
	void setDBUser(const char *sUser, const char *sPswd);
	//启动账号管理器
	bool startManager();
	//停止账号管理器
	void stopManager();

protected:
	virtual VOID OnRountine();

private:
	/* 用户登陆请求 */
	struct LoginRequest
	{
		common::SERVERUSERHANDLE userHandle;
		char sAccount[64];
		char sPasswd[48];
	};
	typedef CQueueList<LoginRequest> LoginRequestList;

private:
	bool ConnectSQL();
	void ProcessLoginRequest();
	void ValidateLoginRequest(const LoginRequest *pRequest);
	void ResultLoginRequest(const LoginRequest *pRequest, int nErrorCode, int nUserId);

private:
	CMySQLConenction	m_AccountSQL;
	TICKCOUNT			m_dwReconnectTick;
	LoginRequestList	m_LoginRequestList;
	CCSLock				m_LoginRequestLock;	
	INT_PTR				m_LoginRequestIndex;
	BOOL				m_boStarted;
};

#endif
