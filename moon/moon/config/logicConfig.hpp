#ifndef __LOGIC_CONFIG_H__
#define __LOGIC_CONFIG_H__

class CLogicConfig : public CCustomLuaConfig
{
public:
	unsigned int			nServerId;//??????ID
	char		sServerName[48];//??????????

	char		sACDBHost[32];//??????????
	int			nACDBPort;//??????????
	char		sACDBName[32];//????????????
	char		sACDBUser[32];//??????????????
	char		sACDBPswd[64];//??????????????

	//???????????
	char		sGLDBHost[32];//?????????????
	int			nGLDBPort;//?????????????
	char		sGLDBName[32];//???????????????
	char		sGLDBUser[32];//?????????????????
	char		sGLDBPswd[64];//?????????????????

	//DB??????
	char		sDBHost[32];//DB?????????
	int			nDBPort;//DB?????????

	int			nGateCount;//????????
	CGateManager::GateConfig *pGateConfigs;//?????????

public:
	CLogicConfig()
	{
		pGateConfigs = NULL;
	}
	~CLogicConfig()
	{
		SafeDeleteArray(pGateConfigs);
	}
	bool loadConfig(LPCTSTR sPath)
	{
		bool boResult = false;
		logInfo("loading logic server config...");
		lib::base::CMemoryStream ms;

		try
		{
			if (ms.loadFromFile(sPath) <= 0)
			{
				showErrorFormat(_T("unable load server config file : %s"), sPath);
				return false;
			}
			if (!setScript((LPCSTR)ms.getMemory()))
			{
				showError(_T("unable read config"));
				return false;
			}
			boResult = readConfig();
		}
		catch(RefString s)
		{
			logError("%s",s.rawStr());
		}
		return boResult;
	}

protected:
	void showError(LPCTSTR sError)
	{
		m_sLastErrDesc = sError;
		RefString sErr = _T("[LogicServer Config]");
		sErr += sError;
		throw sErr;
	}

	bool readConfig()
	{
		//???????
		if (!openGlobalTable("moonServer"))
			return false;
		//?????????????
		if (openFieldTable("server"))
		{
			nServerId = getFieldInt("id");
			getFieldStringBuffer("name", sServerName, ArrayCount(sServerName));
			closeTable();
		}
		else return false;
		//???????????????
		if (openFieldTable("accountdb"))
		{
			getFieldStringBuffer("host", sACDBHost, ArrayCount(sACDBHost));
			nACDBPort = getFieldInt("port");
			getFieldStringBuffer("dbname", sACDBName, ArrayCount(sACDBName));
			getFieldStringBuffer("user", sACDBUser, ArrayCount(sACDBUser));
			getFieldStringBuffer("passwd", sACDBPswd, ArrayCount(sACDBPswd));
			//static const char szACDBEncryptKey[] = "__F_SHGASJDNJS_";
			//DecryptPassword(sACDBUser, ArrayCount(sACDBUser), sACDBUser, szACDBEncryptKey);
			//DecryptPassword(sACDBPswd, ArrayCount(sACDBPswd), sACDBPswd, szACDBEncryptKey);
			closeTable();
		}
		else return false;
		//??????????????????
		if (openFieldTable("gamelogdb"))
		{
			getFieldStringBuffer("host", sGLDBHost, ArrayCount(sGLDBHost));
			nGLDBPort = getFieldInt("port");
			getFieldStringBuffer("dbname", sGLDBName, ArrayCount(sGLDBName));
			getFieldStringBuffer("user", sGLDBUser, ArrayCount(sGLDBUser));
			getFieldStringBuffer("passwd", sGLDBPswd, ArrayCount(sGLDBPswd));
			closeTable();
		}
		else return false;
		//???DB????
		if (openFieldTable("dbclient"))
		{
			getFieldStringBuffer("host", sDBHost, ArrayCount(sDBHost));
			nDBPort = getFieldInt("port");
			closeTable();
		}
		else return false;
		//???????????
		if (openFieldTable("gate"))
		{
			int nCount = (int)lua_objlen(m_pLua, -1);

			if (enumTableFirst())
			{
				nGateCount = 0;
				pGateConfigs = new CGateManager::GateConfig[nCount];
				CGateManager::GateConfig *pConfig = pGateConfigs;
				do
				{
					if (lua_istable(m_pLua, -1))
					{
						getFieldStringBuffer("address", pConfig->sAddress, ArrayCount(pConfig->sAddress));
						pConfig->nPort = getFieldInt("port");
						pConfig->nSendThreadCount = getFieldInt("send");
						getFieldStringBuffer("name", pConfig->sName, ArrayCount(pConfig->sName));
						pConfig++;
						nGateCount++;
					}
				}
				while (enumTableNext());
			}
			closeTable();
		}
		else return false;

		closeTable();
		return true;
	}
};

#endif
