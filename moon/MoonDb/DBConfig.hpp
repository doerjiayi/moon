#ifndef __DB_CONFIG_H__
#define __DB_CONFIG_H__

#include <container/stream/stream.h>

using namespace lib::base;

class CDbConfigAccessor :
	protected CCustomLuaConfig
{
public:
	bool loadConfig(CDBEngine *lpDBEngine, LPCTSTR sPath)
	{
		bool boResult = false;
		logInfo( _T("正在读取数据服务配置..."));
		CMemoryStream ms;

		try
		{
			if (ms.loadFromFile(sPath) <= 0)
			{
				showErrorFormat(_T("读取服务配置文件错误，找不到配置文件 : %s"), sPath);
				return false;
			}
			if (!setScript((LPCSTR)ms.getMemory()))
			{
				showError(_T("读取配置文件出错"));
				return false;
			}
			boResult = readConfig(lpDBEngine);
		}
		catch(RefString s)
		{
			logError("数据服务读取配置出错 %s", s.rawStr());
		}
		return boResult;
	}

protected:
	void showError(LPCTSTR sError)
	{
		m_sLastErrDesc = sError;
		RefString sErr = _T("[数据服务配置]");
		sErr += sError;
		throw sErr;
	}

	bool readConfig(CDBEngine *lpDBEngine)
	{
		if (!openGlobalTable("DBConfig"))
			return false;
		lpDBEngine->SetServerName(getFieldString("serverName"));
		lpDBEngine->SetEnableCreateCharcater(getFieldBoolean("enableNewChar"));
		//读取数据服务器配置
		if (openFieldTable("dataServer"))
		{
			lpDBEngine->SetDataServiceAddress( getFieldString("address"), getFieldInt("port") );
			closeTable();
		}
		else return false;
		//读取MySQL数据库连接配置
		if (openFieldTable("sqlClient"))
		{
			//char sDBUser[128], sDBPass[128];
			//getFieldStringBuffer("user", sDBUser, ArrayCount(sDBUser));
			//getFieldStringBuffer("passwd", sDBPass, ArrayCount(sDBPass));
			//static const char szDBPassKey[] = "___SST_DB_KEY_sjhr7etrhfj";
			//DecryptPassword(sDBUser, ArrayCount(sDBUser), sDBUser, szDBPassKey);
			//DecryptPassword(sDBPass, ArrayCount(sDBPass), sDBPass, szDBPassKey);
			//lpDBEngine->SetSQLConfig( getFieldString("host"), getFieldInt("port"), getFieldString("dbname"), sDBUser, sDBPass );
			lpDBEngine->SetSQLConfig( getFieldString("host"), getFieldInt("port"), getFieldString("dbname"), getFieldString("user"), getFieldString("passwd") );
			closeTable();
		}
		else return false;
		//读取本地数据库配置
		if (openFieldTable("localDB"))
		{
			lpDBEngine->SetLocalDBPath(getFieldString("path"));
			lpDBEngine->SetBackupPath(getFieldString("backupPath"));
			lpDBEngine->SetBackupInterval(getFieldInt("backupInterval"));
			lpDBEngine->SetBackupArchiveDuration(getFieldInt("backupDuration"));
			closeTable();
		}
		else return false;
		closeTable();
		return true;
	}
};

inline BOOL SetupDBEngineConfig(CDBEngine *lpDBEngine)
{
	CDbConfigAccessor conf;
	return conf.loadConfig(lpDBEngine, "./moonDB.txt");
}


#endif


