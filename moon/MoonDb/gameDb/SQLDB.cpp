#include "StdAfx.h"
#include <os/Platform.h>

using namespace GameDBType;

#pragma pack(push, 1)
struct DBGuildBaseData
{
	INT64 nGuildId;
	char strGuildName[64];
	char strCreatorName[32];
	char strCreateDate[16];
	INT32 nCountryId;
	INT32 nGuildFunds;
};
#pragma pack(pop)


void MiniDateTimeToString(int nMiniDateTime, char* strDateTimeString)
{
	if (NULL == strDateTimeString)
		return;
	CMiniDateTime mdt((unsigned int)nMiniDateTime);
	SYSTEMTIME st;
	mdt.decode(st);
	char dtFmt[] = "%d-%d-%d %d:%d:%d";
	sprintf(strDateTimeString, dtFmt, st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
}

CSQLDB::CSQLDB():Inherited(TRUE)
{
	m_pDataServer = NULL;
	m_boStarted = FALSE;
	m_ReconenctSQLTick = 0;
	m_NewCharList.setLock(&m_NewCharLock);
	m_UpdateCharDescList.setLock(&m_UpdateCharDescLock);
#ifdef WINDOWS
	resume();
#endif
}

CSQLDB::~CSQLDB()
{
	terminate();
}

VOID CSQLDB::SetDBHost(LPCTSTR sHost, INT nPort)
{
	if (!m_SQL.Connected())
	{
		m_SQL.SetServerHost(sHost);
		m_SQL.SetServerPort(nPort);
	}
	else logError("Can not set SQL Host after connected.");
}

VOID CSQLDB::SetDBName(LPCTSTR sName)
{
	if (!m_SQL.Connected())
	{
		m_SQL.SetDataBaseName(sName);
	}
	else
	{
		if (m_SQL.Exec(_T("uses %s"), sName) == 0)
		{
			m_SQL.ResetQuery();
		}
	}
}

VOID CSQLDB::SetDBUser(LPCTSTR sUser, LPCTSTR sPassword)
{
	if (!m_SQL.Connected())
	{
		m_SQL.SetUserName(sUser);
		m_SQL.SetPassWord(sPassword);
	}
	else logError("Can not set SQL User/Password after connected.");
}

BOOL CSQLDB::IsAllUpdateComplete()
{
	INT_PTR nUpdateCount = m_NewCharList.count() + m_NewCharList.appendCount()
		+ m_CharDataUpdateList.count() + m_CharDataUpdateList.appendCount()
		+ m_GuildDataUpdateList.count() + m_GuildDataUpdateList.appendCount();
	return nUpdateCount == 0;
}

VOID CSQLDB::Start()
{
	m_boStarted = TRUE;
}

VOID CSQLDB::Stop()
{
	m_boStarted = FALSE;
}

VOID CSQLDB::OnRountine()
{
	TICKCOUNT dwStartTick;
	while (!terminated())
	{
		if (!m_boStarted)
		{
			moon::OS::osSleep(16);
			continue;
		}
		//连接SQL数据库
		if (!ConnectSQLDB())
		{
			moon::OS::osSleep(16);
			continue;
		}
		dwStartTick = _getTickCount();
		//处理角色描述更新请求
		m_NewCharList.flush();
		if (m_NewCharList.count() > 0)
		{
			ProcessAddNewChars(4);
		}
		m_UpdateCharDescList.flush();
		if (m_UpdateCharDescList.count() > 0)
		{
			ProcessUpdateCharDescs(4);
		}
		//处理角色数据更新请求
		m_CharDataUpdateList.flush();
		if (m_CharDataUpdateList.count() > 0)
		{
			ProcessCharDataUpdate(4);
		}
		//处理帮会数据更新请求
		m_GuildDataUpdateList.flush();
		if (m_GuildDataUpdateList.count() > 0)
		{
			ProcessGuildDataUpdate(4);
		}
		moon::OS::osSleep(4);
	}
}

VOID CSQLDB::ProcessAddNewChars(TICKCOUNT dwTimeLimit)
{
	CharDesc *pCharDesc;

	TICKCOUNT dwTimeOver = _getTickCount() + dwTimeLimit;
	INT_PTR nCount = m_NewCharList.count();
	do 
	{
		pCharDesc = m_NewCharList.pop();
		AddNewCharToDB(pCharDesc);
		nCount--;
	}
	while (nCount > 0 && _getTickCount() < dwTimeOver);
}

VOID CSQLDB::ProcessUpdateCharDescs(TICKCOUNT dwTimeLimit)
{
	CharDesc *pCharDesc;


	TICKCOUNT dwTimeOver = _getTickCount() + dwTimeLimit;
	INT_PTR nCount = m_UpdateCharDescList.count();
	do 
	{
		pCharDesc = m_UpdateCharDescList.pop();

		if (NULL != pCharDesc)
		{
			char strSQL[1024];
			char strSqlFmt[] = {"Update chardesc Set charstate = %hd, updatetime='%s' Where charid=%lld"};
			char strUpdateTime[20];
			MiniDateTimeToString(pCharDesc->nUpdateTime, strUpdateTime);
			BYTE bState = 0;
			if ((pCharDesc->wState & CHARSTATE_DISABLED) == CHARSTATE_DISABLED)
				bState = 1;
			if ((pCharDesc->wState & CHARSTATE_DELETED) == CHARSTATE_DELETED)
				bState = 2;

//			sprintf_s(strSQL, sizeof(strSQL), strSqlFmt, bState, strUpdateTime, pCharDesc->nCharId);
			sprintf(strSQL,strSqlFmt, bState, strUpdateTime, pCharDesc->nCharId);
				if (0 == m_SQL.RealExec(strSQL, strlen(strSQL)))
					m_SQL.ResetQuery();
		}
		nCount--;
	}
	while (nCount > 0 && _getTickCount() < dwTimeOver);
}

VOID CSQLDB::ProcessCharDataUpdate(TICKCOUNT dwTimeLimit)
{
	CGameDataBufferReader *pGDBReader;

	TICKCOUNT dwTimeOver = _getTickCount() + dwTimeLimit;
	INT_PTR nCount = m_CharDataUpdateList.count();
	INT64 nCharId;
	do 
	{
		pGDBReader = m_CharDataUpdateList.pop();
		nCharId = pGDBReader->GetDataId();
		UpdateCharDataToDB(pGDBReader);
		pGDBReader->SetDataBuffer(NULL);
		m_GDBReaderPool.FreeBufferReader(pGDBReader);
		nCount--;
	}
	while (nCount > 0 && _getTickCount() < dwTimeOver);
}

VOID CSQLDB::ProcessGuildDataUpdate(TICKCOUNT dwTimeLimit)
{
	CGameDataBufferReader *pGDBReader;

	TICKCOUNT dwTimeOver = _getTickCount() + dwTimeLimit;
	INT_PTR nCount = m_GuildDataUpdateList.count();
	INT64 nGuildId;
	do 
	{
		pGDBReader = m_GuildDataUpdateList.pop();
		nGuildId = pGDBReader->GetDataId();
		UpdateGuildDataToDB(pGDBReader);
		pGDBReader->SetDataBuffer(NULL);
		m_GDBReaderPool.FreeBufferReader(pGDBReader);
		nCount--;
	}
	while (nCount > 0 && _getTickCount() < dwTimeOver);
}

BOOL CSQLDB::ConnectSQLDB()
{
	if (m_SQL.Connected())
		return TRUE;
	TICKCOUNT dwTick = _getTickCount();
	if (dwTick >= m_ReconenctSQLTick)
	{
		m_ReconenctSQLTick= dwTick + 10 * 1000;
		m_pDataServer->GetDBEngine()->SetupSQLConnection(&m_SQL);

		return m_SQL.Connect();
	}
	return FALSE;
}

VOID CSQLDB::AddNewCharToDB(GameDBType::CharDesc *pCharDesc)
{
#if 1
	//TODO: 请实现此函数，向SQL数据库添加新角色。
	if (NULL == pCharDesc)
		return;
	char strSQL[2048];
	char strCreateTime[20];
	char strUpdateTime[20];
	char strAccount[128];
	char strCharName[128];
	MiniDateTimeToString(pCharDesc->nCreateTime, strCreateTime);
	MiniDateTimeToString(pCharDesc->nUpdateTime, strUpdateTime);	
	strAccount[mysql_real_escape_string(m_SQL.GetMySql(), strAccount, pCharDesc->sAccount, (unsigned int)strlen(pCharDesc->sAccount))] = '\0';
	strCharName[mysql_real_escape_string(m_SQL.GetMySql(), strCharName, pCharDesc->sCharName, (unsigned int)strlen(pCharDesc->sCharName))] = '\0';

	char strSqlFmt[] = {"INSERT INTO chardesc("
		"charid,userid,account,charname,serverid,createtime,chargender"
		") VALUES ("
		"%lld,%lld,'%s','%s',%d,'%s',%d"
		") ON DUPLICATE KEY UPDATE "
		"serverid=%d,updatetime='%s',loginip=%d,charstate=%d,charlevel=%d"
	};
//	sprintf_s(strSQL, sizeof(strSQL), strSqlFmt,
//		pCharDesc->nCharId, pCharDesc->nUserId, strAccount, strCharName, pCharDesc->wServerId, strCreateTime, pCharDesc->btGender,
//		pCharDesc->wServerId, strUpdateTime, pCharDesc->nLoginIP, pCharDesc->wState, pCharDesc->wLevel);
	sprintf(strSQL, strSqlFmt,
		pCharDesc->nCharId, pCharDesc->nUserId, strAccount, strCharName, pCharDesc->wServerId, strCreateTime, pCharDesc->btGender,
		pCharDesc->wServerId, strUpdateTime, pCharDesc->nLoginIP, pCharDesc->wState, pCharDesc->wLevel);
	if (0 == m_SQL.RealExec(strSQL, strlen(strSQL)))
		m_SQL.ResetQuery();
#endif
}

void CSQLDB::UpdateCharDescDataToDB(CGameDataBufferReader *pBufferReader, INT64* pCharId)
{
#if 1
	common::DBType::PlayerBasicData *pBaseData;

	pBaseData = (common::DBType::PlayerBasicData *)pBufferReader->getPositionPtr(sizeof(common::DBType::DataSectionHeader));

	if (NULL != pCharId)
		*pCharId = pBaseData->charId.llid;

	char strSQL[4096];
	char strSqlFmt[] = "update chardesc set "
		"charlevel=%d, chargender=%d, gold=%d, gamegold=%d, charexp=%lld, guildid=%lld"
		" where charid=%lld";
//	int nLen = sprintf_s(strSQL, sizeof(strSQL), strSqlFmt,
//		pBaseData->wLevel, pBaseData->btGender, pBaseData->nGold, pBaseData->nGameGold, pBaseData->nExp, pBaseData->guildId.llid,
//		pBaseData->charId.llid
//		);

	int nLen = sprintf(strSQL,strSqlFmt,
			pBaseData->wLevel, pBaseData->btGender, pBaseData->nCoin, pBaseData->nGameGold, pBaseData->nExp, pBaseData->guildId.llid,
			pBaseData->charId.llid
			);
	if (0 == m_SQL.RealExec(strSQL, nLen))
		m_SQL.ResetQuery();
#endif
}

VOID CSQLDB::UpdateCharDataToDB(CGameDataBufferReader *pBufferReader)
{
	if (NULL == pBufferReader)
		return;
	UpdateCharDescDataToDB(pBufferReader, NULL);
}

void CSQLDB::UpdateGuildBaseDataToDB(CGameDataBufferReader *pBufferReader, INT64* pGuildId)
{
/*
	char strSQL[1024];
	
	BYTE btNameLength;
	WORD wDataItemSize, wDataSizeLeft;
	int nCreateDate;

	char strGuildName[64] = {0};
	char strCreatorName[64] = {0};

	DBGuildBaseData gbd;

	wDataSizeLeft = wDataItemSize;
	*pBufferReader >> gbd.nGuildId;
	wDataSizeLeft -= 8;

	if (NULL != pGuildId)
		*pGuildId = gbd.nGuildId;

	pBufferReader->adjustOffset(4);
	wDataSizeLeft -= 4;
	*pBufferReader >> gbd.nGuildFunds;
	wDataSizeLeft -= 4;

	pBufferReader->adjustOffset(4 * 6);
	wDataSizeLeft -= 4 * 6;

	*pBufferReader >> gbd.nCountryId;
	wDataSizeLeft -= 4;

	//GuildName
	*pBufferReader >> btNameLength;
	wDataSizeLeft --;
	if (btNameLength > sizeof(gbd.strGuildName)-1)
		btNameLength = sizeof(gbd.strGuildName)-1;
	pBufferReader->readBuf(&gbd.strGuildName[0], btNameLength);
	gbd.strGuildName[btNameLength] = '\0';
	strGuildName[mysql_real_escape_string(m_SQL.GetMySql(), strGuildName, gbd.strGuildName, btNameLength)] = '\0';
	wDataSizeLeft -= btNameLength;

	//CreatorName
	*pBufferReader >> btNameLength;
	wDataSizeLeft --;
	if (btNameLength > sizeof(gbd.strCreatorName)-1)
		btNameLength = sizeof(gbd.strCreatorName)-1;
	pBufferReader->readBuf(&gbd.strCreatorName[0], btNameLength);
	gbd.strCreatorName[btNameLength] = '\0';
	strCreatorName[mysql_real_escape_string(m_SQL.GetMySql(), strCreatorName, gbd.strCreatorName, btNameLength)] = '\0';
	wDataSizeLeft -= btNameLength;

	//CreateDate
	*pBufferReader >> nCreateDate;
	wDataSizeLeft -= 4;

	MiniDateTimeToString(nCreateDate, gbd.strCreateDate);
	

	char strSqlFmt[] ={"INSERT INTO guildbase(guildid,guildname,creator,createdate,countryid,guildfunds) "
		"VALUES (%lld,'%s','%s','%s',%d,%d) ON DUPLICATE KEY UPDATE guildname='%s',creator='%s',createdate='%s',countryid=%d,guildfunds=%d"};	
	
	sprintf_s(strSQL, sizeof(strSQL), strSqlFmt, gbd.nGuildId, strGuildName, strCreatorName, gbd.strCreateDate, gbd.nCountryId,
		gbd.nGuildFunds, strGuildName, strCreatorName, gbd.strCreateDate, gbd.nCountryId, gbd.nGuildFunds);
	//OutputMsgError strSQL);
	if (0 == m_SQL.RealExec(strSQL, strlen(strSQL)))
		m_SQL.ResetQuery();
*/
}

VOID CSQLDB::UpdateGuildDataToDB(CGameDataBufferReader *pBufferReader)
{

	if (NULL == pBufferReader)
		return;

	INT64 nGuildId = 0;
	UpdateGuildBaseDataToDB(pBufferReader, &nGuildId);
}
