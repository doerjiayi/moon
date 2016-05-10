#include "StdAfx.h"
#include <os/Platform.h>
#include <file/MBCSDef.h>
#include "DBEngine.h"


CDBEngine::CDBEngine()
{
	m_sServerName[0] = 0;
	m_boEnableCreateCharacter = TRUE;//默认可以创建新角色
	SetSQLConfig("localhost", 3306, "gamedb", "root", "123456");
	SetLocalDBPath("./FDB");
	m_pNameFilter = NULL;
	m_nBackupArchiveDuration = 48; //默认备份存档48小时,自动删除48小时前的备份
	m_pDataServer = new CDBDataServer(this);
}

CDBEngine::~CDBEngine()
{
	Shutdown();

	SafeDelete(m_pDataServer);
}

VOID CDBEngine::FreeNameFilterWords()
{
	if ( m_pNameFilter )
	{
		FreeMBCSFilter(m_pNameFilter);
		m_pNameFilter = NULL;
	}
}

VOID CDBEngine::SetupSQLConnection(CMySQLConenction *lpConnection)
{
	lpConnection->SetServerHost(m_sSQLHost);
	lpConnection->SetServerPort(m_nSQLPort);
	lpConnection->SetDataBaseName(m_sSQLDBName);
	lpConnection->SetUserName(m_sSQLUser);
	lpConnection->SetPassWord(m_sSQLPassword);
	lpConnection->SetConnectionFlags(CLIENT_FOUND_ROWS | CLIENT_MULTI_RESULTS);
}

LPCSTR CDBEngine::LowerCaseNameStr(LPSTR sNameStr)
{
	LPCSTR sResult = sNameStr;
	while ( *sNameStr )
	{
		/* 为了支持UTF8 取消此判断
		if ( (unsigned int)*sNameStr >= 0x7F )
		{
			sNameStr+=2;
			continue;
		}
		*/

		if ( *sNameStr >= 'A' && *sNameStr <= 'Z' )
		{
			*sNameStr |= 0x20;
		}
		sNameStr++;
	}
	return sResult;
}

BOOL CDBEngine::CheckNameStr(LPCSTR sNameStr)
{
	//检查是否包含控制字符以及英文标点符号，这些字符是不被允许的
	LPCSTR sptr;
	unsigned int ch;

	for ( sptr = sNameStr; *sptr; ++sptr )
	{
		//此处允许中文
		ch = (unsigned int)*sptr;
		//检测到多字节字符
		if ( ch >= 0x7F )
		{
			continue;
		}
		
		//此处允许a-z
		if ( ch >= 'a' && ch <= 'z' )
			continue;
		//此处允许A-Z
		if ( ch >= 'A' && ch <= 'Z' )
			continue;
		//此处允许0-9
		if ( ch >= '0' && ch <= '9' )
			continue;
		return FALSE;
	}

	//从名称过滤表中进行屏蔽字检查
	m_NameFilterLock.Lock();
	if ( m_pNameFilter )
		sptr = MatchMBCSFilterWord(m_pNameFilter, sNameStr, NULL);
	else sptr = NULL;
	m_NameFilterLock.Unlock();

	return sptr == NULL;
}

INT CDBEngine::LoadNameFilterWords()
{
	static const TCHAR szNameFilterList[] = _T("./ForbiddenNames.txt");

	int Result = 0;
	PFT_MBCS_CHAR pFilterWords;

	lib::base::CMemoryStream ms;
	LPSTR sLineStart, sLineEnd, sNewLine;

	if (ms.loadFromFile(szNameFilterList) > 0)
	{
		pFilterWords = CreateMBCSFilter(NULL);
		sLineStart = (LPSTR)ms.getMemory();
		//检测并跳过UTF-8 BOM（EF BB BF)
		if ( ((*((PINT)sLineStart)) & 0x00FFFFFF) == 0xBFBBEF )
			sLineStart += 3;

		while (*sLineStart)
		{
			//跳过行首的不可见字符
			while (*sLineStart && (unsigned char)*sLineStart <= 0x20) sLineStart++;
			//查找新行符
			sNewLine = strchr(sLineStart, '\n');
			if (sNewLine)
			{
				sLineEnd = sNewLine;
				sNewLine++;
			}
			else
			{
				sNewLine = sLineStart + strlen(sLineStart);
				sLineEnd = sNewLine - 1;
			}
			//跳过行尾的不可见字符
			while (*sLineEnd && (unsigned char)*sLineEnd <= 0x20) sLineEnd--;
			sLineEnd++;
			//终止当前行
			if (sLineEnd > sLineStart)
			{
				sLineEnd[0] = 0;
				AddMBCSFilterStrToTable( pFilterWords, sLineStart );
				Result++;
			}
			sLineStart = sNewLine;
		}

		PFT_MBCS_CHAR pOldFilter = m_pNameFilter;
		//将新加载的屏蔽词列表保存到类中
		m_NameFilterLock.Lock();
		m_pNameFilter = pFilterWords;
		m_NameFilterLock.Unlock();

		//释放老的屏蔽词列表
		if ( pOldFilter )
			FreeMBCSFilter(pOldFilter);
	}

	return Result;
}

VOID CDBEngine::SetServerName(LPCSTR sSrvName)
{
	_asncpytA(m_sServerName, sSrvName);
}

VOID CDBEngine::SetSQLConfig(LPCSTR sHost, const int nPort, LPCSTR sDBName, LPCSTR sDBUser, LPCSTR sUserPassword)
{
	_asncpytA(m_sSQLHost, sHost);
	m_nSQLPort = nPort;
	_asncpytA(m_sSQLDBName, sDBName);
	_asncpytA(m_sSQLUser, sDBUser);
	_asncpytA(m_sSQLPassword, sUserPassword);
}

VOID CDBEngine::SetLocalDBPath(LPCSTR sPath)
{
	_asncpytA(m_sLocalDBDir, sPath);
}

VOID CDBEngine::SetBackupPath(LPCSTR sPath)
{
	_asncpytA(m_sBackupPath, sPath);
}

VOID CDBEngine::SetDataServiceAddress(LPCTSTR sBindHost, const int nBindPort)
{
	m_pDataServer->SetServiceHost(sBindHost);
	m_pDataServer->SetServicePort(nBindPort);
}

VOID CDBEngine::SetEnableCreateCharcater(BOOL enable)
{
	m_boEnableCreateCharacter = enable;
}

//设置备份时间毫秒
VOID CDBEngine::SetBackupInterval(int nBackupInterval)
{
	m_nBackupInterval = nBackupInterval;
}

//设置备份存档存在时间(小时)
VOID CDBEngine::SetBackupArchiveDuration(int nBackupArchiveDuration)
{
	m_nBackupArchiveDuration = nBackupArchiveDuration;
}

BOOL CDBEngine::Startup()
{
	int nError;

	//初始化网络套接字
	nError = m_pDataServer->InitSocketLib();
	if ( nError )
	{
		OutputError( nError, _T(__FUNCTION__),_T("初始化网络库失败 "));
		return FALSE;
	}
	//加载屏蔽词列表
	LoadNameFilterWords();

	//启动数据服务器
	if ( !m_pDataServer->Startup() )
		return FALSE;

	return TRUE;
}

VOID CDBEngine::Shutdown()
{
	//停止数据服务器
	m_pDataServer->Stop();
	//释放屏蔽词列表
	FreeNameFilterWords();
	//卸载网络库
	m_pDataServer->UnintSocketLib();
}
