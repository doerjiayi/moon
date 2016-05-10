#include "StdAfx.h"

CAccountManager::CAccountManager()
	:super(TRUE)
{
	m_dwReconnectTick = 0;
	m_LoginRequestIndex = 0;
	m_boStarted = FALSE;
	m_LoginRequestList.setLock(&m_LoginRequestLock);
	resume();
}

CAccountManager::~CAccountManager()
{
	stopManager();
	terminate();
	waitFor();
}

void CAccountManager::setDBHost(const char *sHost, int nPort)
{
	m_AccountSQL.SetServerHost(sHost);
	m_AccountSQL.SetServerPort(nPort);
}

void CAccountManager::setDBName(const char *sDBName)
{
	m_AccountSQL.SetDataBaseName(sDBName);
}

void CAccountManager::setDBUser(const char *sUser, const char *sPswd)
{
	m_AccountSQL.SetUserName(sUser);
	m_AccountSQL.SetPassWord(sPswd);
}

bool CAccountManager::startManager()
{
	if (!m_boStarted)
	{
		m_boStarted = TRUE;
	}
	return true;
}

void CAccountManager::stopManager()
{
	if (m_boStarted)
	{
		m_boStarted = FALSE;
	}
}

bool CAccountManager::ConnectSQL()
{
	if (m_AccountSQL.Connected())
		return true;

 	TICKCOUNT dwCurTick = _getTickCount();
	if (dwCurTick >= m_dwReconnectTick)
	{
		m_dwReconnectTick = dwCurTick + 5000;
		if (m_AccountSQL.Connect() != FALSE)
		{
			return true;
		}
	}

	return false;
}

void CAccountManager::OnRountine()
{
	while (!terminated())
	{
		if (m_boStarted)
		{
			ConnectSQL();
			ProcessLoginRequest();
		}
		moon::OS::osSleep(1);
	}
}

void CAccountManager::requestLogin(common::PSERVERUSERHANDLE pUserHandle, const char *sAccount, const char *sPasswd)
{
	LoginRequest request;
	request.userHandle = *pUserHandle;
	_asncpytA(request.sAccount, sAccount);
	_asncpytA(request.sPasswd, sPasswd);
	m_LoginRequestList.append(request);
}

void CAccountManager::ProcessLoginRequest()
{
	int nProcessCount = 0;
	INT_PTR nCount = m_LoginRequestList.count();
	while (m_LoginRequestIndex < nCount)
	{
		const LoginRequest &request = m_LoginRequestList[m_LoginRequestIndex];
		ValidateLoginRequest(&request);
		m_LoginRequestIndex++;
		nProcessCount++;
		if (nProcessCount >= 10)
			break;
	}
	if (m_LoginRequestIndex >= nCount)
	{
		m_LoginRequestList.clear();
		m_LoginRequestList.flush();
		m_LoginRequestIndex = 0;
	}
}

void CAccountManager::ValidateLoginRequest(const LoginRequest *pRequest)
{
	//数据库未就绪
	if (!m_AccountSQL.Connected())
	{
		ResultLoginRequest(pRequest, -1, 0);
		return;
	}

	//数据库查询错误（1）
	if (m_AccountSQL.Query("call proc_validateuserlogin(\"%s\", \"%s\")", pRequest->sAccount, pRequest->sPasswd))
	{
		ResultLoginRequest(pRequest, -2, 0);
		return;
	}

	do
	{
		//数据库查询错误（2）
		MYSQL_ROW pRow = m_AccountSQL.CurrentRow();
		if (!pRow || m_AccountSQL.GetFieldCount() < 2)
		{
			ResultLoginRequest(pRequest, -3, 0);
			break;
		}

		int nErrorCode = -100;
		int nUserId = 0;
		sscanf(pRow[0], "%d", &nErrorCode);
		sscanf(pRow[1], "%d", &nUserId);

		if (nErrorCode != 0 || nUserId == 0)
		{
			//用户不存在
			if (nErrorCode == 1)
			{
				ResultLoginRequest(pRequest, -4, 0);
				break;
			}
			//密码错误
			if (nErrorCode == 2)
			{
				ResultLoginRequest(pRequest, -5, 0);
				break;
			}
			//未知的数据库错误码
			ResultLoginRequest(pRequest, -6, 0);
		}
		ResultLoginRequest(pRequest, 0, nUserId);
	}
	while (0);
	m_AccountSQL.ResetQuery();
}

void CAccountManager::ResultLoginRequest(const LoginRequest *pRequest, int nErrorCode, int nUserId)
{
	CLogicGate *pGate = g_GateManager->getGate(pRequest->userHandle.wGateIndex);
	if (pGate)
	{
		pGate->resultUserLogin(&pRequest->userHandle, nErrorCode, nUserId);
	}
}


