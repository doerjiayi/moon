#include "StdAfx.h"
#include <new>
#include <os/Platform.h>

using namespace moon::OS;

using namespace GameDBType;

BOOL CheckIfCreateDirectory(LPCTSTR szDirPath)
{
#ifdef WINDOWS
	DWORD dwAttr = ::GetFileAttributes(szDirPath);
	BOOL bRet = (dwAttr != INVALID_FILE_ATTRIBUTES) && (FILE_ATTRIBUTE_DIRECTORY & dwAttr);
	if (!bRet)
		bRet = ::CreateDirectory(szDirPath, NULL);
	if (!bRet)
		logError("检查创建目录 %s 失败！", szDirPath);
	return bRet;
#else
	return false;
#endif
}

BOOL CopyFDBFiles(LPCTSTR szSrcPath, LPCTSTR szDstPath)
{
#ifdef WINDOWS
	if ((NULL == szSrcPath) || (NULL == szDstPath))
		return FALSE;
	BOOL bRet = FALSE;
	TCHAR szFindFile[MAX_PATH];
	TCHAR szSrcFilePath[MAX_PATH];
	TCHAR szDstFilePath[MAX_PATH]; 

	WIN32_FIND_DATA fd;
    ZeroMemory(&fd, sizeof(WIN32_FIND_DATA));

	_tcscpy(szFindFile, szSrcPath);
	_tcscat(szFindFile, _T("/*"));

	HANDLE hFind  = ::FindFirstFile(szFindFile, &fd);

	if (hFind == INVALID_HANDLE_VALUE)
		return FALSE;

	while(::FindNextFile(hFind, &fd))
	{
		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			continue;

		_tcscpy(szSrcFilePath, szSrcPath); 
		_tcscat(szSrcFilePath, _T("/"));
		_tcscat(szSrcFilePath, fd.cFileName);
		_tcscpy(szDstFilePath, szDstPath); 
		_tcscat(szDstFilePath, _T("/"));
		_tcscat(szDstFilePath, fd.cFileName);
		bRet = ::CopyFile(szSrcFilePath, szDstFilePath, FALSE);
		if (!bRet)
			break;
	}
	FindClose(hFind);
	return bRet;

#else
	return false;
#endif
}

CLocalDB::CLocalDB():Inherited(TRUE)
{
	m_boOpened = FALSE;
	m_CharDescUpdateList.setLock(&m_CharDescUpdateLock);
	m_nBackupInterval = 0;
#ifdef WINDOWS
	resume();
#endif
}

CLocalDB::~CLocalDB()
{
	terminate();
	CloseDB();
}

BOOL CLocalDB::OpenDB(LPCSTR sDBPath)
{
	static const TCHAR szCharDescDBName[] = _T("CharDesc");//角色描述数据库名
	static const TCHAR szCharDataDBName[] = _T("CharData");//角色数据数据库名
	static const TCHAR szGuildDataDBName[] = _T("GuildData");//帮会数据数据库名

	TCHAR sDBName[1024];
	sDBName[ArrayCount(sDBName) - 1] = 0;
	//关闭当前打开的数据库
	CloseDB();

	_tcscpy(m_szDBPath, sDBPath);

	
	//打开角色描述数据库
	_sntprintf(sDBName, ArrayCount(sDBName) - 1, _T("%s/%s"), sDBPath, szCharDescDBName);
	if (!m_CharDescDB.open(sDBName) && !m_CharDescDB.create(sDBName))
	{
		logError("无法读取或创建角色描述数据库");
		return FALSE;
	}
	m_CharDescDB.setChunkSize(64);
	//读取角色描述数据库
	if (!LoadAllCharDesc())
		return FALSE;

	//打开角色数据数据库
	_sntprintf(sDBName, ArrayCount(sDBName) - 1, _T("%s/%s"), sDBPath, szCharDataDBName);
	if (!m_CharDataDB.open(sDBName) && !m_CharDataDB.create(sDBName))
	{
		logError("无法读取或创建角色数据存储数据库");
		return FALSE;
	}
	m_CharDataDB.setChunkSize(2048);

	//打开帮会数据数据库
	_sntprintf(sDBName, ArrayCount(sDBName) - 1, _T("%s/%s"), sDBPath, szGuildDataDBName);
	if (!m_GuildDataDB.open(sDBName) && !m_GuildDataDB.create(sDBName))
	{
		logError("无法读取或创建角色数据存储数据库");
		return FALSE;
	}
	m_GuildDataDB.setChunkSize(1024);

	m_boOpened = TRUE;
	return TRUE;
}

VOID CLocalDB::CloseDB()
{
	//如果有数据存储尚未完成是要进行额外的处理，不能直接关闭数据库的！
	Assert(IsAllUpdateComplete());

	m_boOpened = FALSE;
	m_CharDescDB.close();
	m_CharDataDB.close();
	m_GuildDataDB.close();
	m_CharIdSortList.trunc(0);
	m_CharNameSortList.trunc(0);
	m_UserIdSortList.trunc(0);
	m_CharDescAllocator.~CharDescAllocator();
	new (&m_CharDescAllocator) CharDescAllocator();
}

VOID CLocalDB::SetBackupInterval(int nBackupIntervalMinute)//
{
	m_nBackupInterval = nBackupIntervalMinute * 60 * 1000;//分钟转毫秒
}

VOID CLocalDB::SetBackupPath(LPCSTR sBackupPath)
{
	_tcscpy(m_szBackupPath, sBackupPath);
	m_ZipBackup.SetBackupPath(sBackupPath);
}

VOID CLocalDB::SetBackupArchiveDuration(int nBackupArchiveDuration)
{
	m_ZipBackup.SetBackupArchiveDuration(nBackupArchiveDuration);
}

BOOL CLocalDB::BackupFDBFiles()
{
	TCHAR szBakTmpPath[MAX_PATH];
	strcpy(szBakTmpPath, m_szBackupPath);
	strcat(szBakTmpPath, _T("/FDB"));

	return CheckIfCreateDirectory(m_szBackupPath) && CheckIfCreateDirectory(szBakTmpPath) && CopyFDBFiles(m_szDBPath, szBakTmpPath);

}

BOOL CLocalDB::IsAllUpdateComplete()
{
	INT_PTR nUpdateCount = m_CharDescUpdateList.count() + m_CharDescUpdateList.appendCount()
		+ m_CharDataUpdateList.count() + m_CharDataUpdateList.appendCount()
		+ m_GuildDataUpdateList.count() + m_GuildDataUpdateList.appendCount();
	return nUpdateCount == 0;
}

GameDBType::CharDesc* CLocalDB::GetCharDesc(INT64 nCharId) const
{
	INT_PTR nIdx = m_CharIdSortList.search(nCharId);
	if (nIdx < 0)
		return NULL;
	return m_CharIdSortList[nIdx].pCharDesc;
}

GameDBType::CharDesc* CLocalDB::GetCharDesc(LPCSTR sCharName) const
{
	INT_PTR nIdx = m_CharNameSortList.search(sCharName);
	if (nIdx < 0)
		return NULL;
	return m_CharNameSortList[nIdx].pCharDesc;
}

INT CLocalDB::GetUserCharDescList(INT64 nUserId, INT nServerId, GameDBType::CharDesc **pList, 
	INT nMaxCount, BOOL boAllowDeleted, BOOL boAllowDisabled) const
{
	//static const INT STATE_NOT_AVALIABLE = CHARSTATE_DELETED | CHARSTATE_DISABLED;

	INT_PTR nCount, nListCount;
	INT_PTR nIdx, nIdx2;
	
	nIdx = m_UserIdSortList.search(nUserId);
	if (nIdx < 0)
		return 0;

	CharDesc *pCharDesc;
	UserIdSortedDesc *pDescList = m_UserIdSortList;
	nListCount = m_UserIdSortList.count();
	nCount = 0;

	//向前面开始找
	for (nIdx2 = nIdx; nIdx2 >= 0; --nIdx2)
	{
		pCharDesc = pDescList[nIdx2].pCharDesc;
		if (pCharDesc->nUserId != nUserId)
			break;
		if (!boAllowDeleted && (pCharDesc->wState & CHARSTATE_DELETED))
			continue;
		if (!boAllowDisabled && (pCharDesc->wState & CHARSTATE_DISABLED))
			continue;
		if (nServerId && nServerId != pCharDesc->wServerId)
			continue;
		if (!nMaxCount)
		{
			nCount++;
		}
		else
		{
			pList[nCount] = pCharDesc;
			nCount++;
			if (nCount >= nMaxCount)
				return (INT)nCount;
		}
	}
	//向后面开始找
	for (nIdx2 = nIdx + 1; nIdx2 < nListCount; ++nIdx2)
	{
		pCharDesc = pDescList[nIdx2].pCharDesc;
		if (pCharDesc->nUserId != nUserId)
			break;
		if (!boAllowDeleted && (pCharDesc->wState & CHARSTATE_DELETED))
			continue;
		if (!boAllowDisabled && (pCharDesc->wState & CHARSTATE_DISABLED))
			continue;
		if (nServerId && nServerId != pCharDesc->wServerId)
			continue;
		if (!nMaxCount)
		{
			nCount++;
		}
		else
		{
			pList[nCount] = pCharDesc;
			nCount++;
			if (nCount >= nMaxCount)
				return (INT)nCount;
		}
	}
	return (INT)nCount;
}

BOOL CLocalDB::RenameChar(INT64 nCharId, LPCSTR sCharName)
{
	CharNameSortedDesc nameDesc;
	
	nameDesc.pCharDesc = GetCharDesc(nCharId);
	if (!nameDesc.pCharDesc || GetCharDesc(sCharName))
		return FALSE;
	INT_PTR nNameListIdx = m_CharNameSortList.search(nameDesc.pCharDesc->sCharName);
	m_CharNameSortList.remove(nNameListIdx);
	strncpy((LPSTR)nameDesc.pCharDesc->sCharName, sCharName, ArrayCount(nameDesc.pCharDesc->sCharName)-1);
	((LPSTR)nameDesc.pCharDesc->sCharName)[ArrayCount(nameDesc.pCharDesc->sCharName)-1] = 0;
	m_CharNameSortList.add(nameDesc);
	PostUpdateCharDesc(nameDesc.pCharDesc);
	return TRUE;
}

GameDBType::CharDesc* CLocalDB::SetCharState(LPCSTR sCharName, BYTE bState)
{
	if (NULL == sCharName)
		return FALSE;
	GameDBType::CharDesc* pCharDesc = GetCharDesc(sCharName);

	if (NULL == pCharDesc)
		return NULL;

	bool bNeedUpdate = false;

	switch (bState)
	{
	case 0://正常
		{
			if ((pCharDesc->wState & CHARSTATE_DISABLED) == CHARSTATE_DISABLED)
			{
				pCharDesc->wState ^= CHARSTATE_DISABLED;
				bNeedUpdate = true;
			}
			if ((pCharDesc->wState & CHARSTATE_DELETED) == CHARSTATE_DELETED)
			{
				pCharDesc->wState ^= CHARSTATE_DELETED;
				bNeedUpdate = true;
			}
		}
		break;
	case 1://禁用
		{
			if ((pCharDesc->wState & CHARSTATE_DISABLED) != CHARSTATE_DISABLED)
			{
				pCharDesc->wState |= CHARSTATE_DISABLED;
				bNeedUpdate = true;
			}
		}
		break;
	case 2://删除
		{
			if ((pCharDesc->wState & CHARSTATE_DELETED) != CHARSTATE_DELETED)
			{
				pCharDesc->wState |= CHARSTATE_DELETED;
				bNeedUpdate = true;
			}
		}
		break;
	default:
		break;
	}
	if (bNeedUpdate)
	{
		PostUpdateCharDesc(pCharDesc);
		return pCharDesc;
	}
	else
		return NULL;
}

//先查内存再查数据文件
//在等待写入磁盘中的队列数据中获取角色数据，防止客户端快速重
//新登陆时因队列中的数据尚未保存而直接获取老的磁盘文件数据而产生的回档现象。
//返回 0表示队列中没有数据
DWORD CLocalDB::GetCharDataInUpdateList(INT64 nCharId, CDataPacket& pack)
{
	INT_PTR nListCount = 0;
	DWORD dwDataSize = 0;
	CGameDataBufferReader *pGDBReader;

	m_CharDataUpdateList.lock(); //必须加锁，否则得到的指针很可能会因为写数据的线程操作移除后而失效！

	m_CharDataUpdateList.flush(); //将附加队列进行整合，然后统一查找角色ID
	nListCount = m_CharDataUpdateList.count();

	for (INT_PTR i=nListCount-1; i>-1; --i) //从后往前找才会遇到最新的数据
	{
		pGDBReader = m_CharDataUpdateList[i];
		if (nCharId == pGDBReader->GetDataId())
		{
			//填充角色数据到发送包
			dwDataSize = (DWORD)pGDBReader->getLength();
			pack.reserve(pack.getLength() + dwDataSize);
			pack.writeBuf(pGDBReader->getMemoryPtr(), dwDataSize);//写入二进制数据
			break;
		}
	}

	m_CharDataUpdateList.unlock();

	return dwDataSize;
}

VOID CLocalDB::PostUpdateCharData(CGameDataBuffer *pGameDataBuffer)
{
	//将角色数据添加到到更新请求队列中
	CGameDataBufferReader *pGDBReader = m_GDBReaderPool.AllocBufferReader();
	pGDBReader->SetDataBuffer(pGameDataBuffer);
	m_CharDataUpdateList.append(pGDBReader);
}

VOID CLocalDB::PostUpdateGuildData(CGameDataBuffer *pGameDataBuffer)
{
	//将帮会数据添加到到更新请求队列中
	CGameDataBufferReader *pGDBReader = m_GDBReaderPool.AllocBufferReader();
	pGDBReader->SetDataBuffer(pGameDataBuffer);
	m_GuildDataUpdateList.append(pGDBReader);
}

GameDBType::CharDesc* CLocalDB::AddChar(INT nServerId, INT64 nUserId, LPCSTR sAccount, 
	LPCSTR sCharName, INT nJob, INT nGender)
{
	CharDesc *pCharDesc = GetCharDesc(sCharName);
	if (pCharDesc)
		return NULL;

	//构造角色描述数据
	pCharDesc = m_CharDescAllocator.allocObjects(1);
	ZeroMemory(pCharDesc, sizeof(*pCharDesc));
	*((PINT64)&pCharDesc->nCharId) = GameDBType::makeCharId((WORD)nServerId).llid;
	*((PINT64)&pCharDesc->nUserId) = nUserId;
	strncpy((LPSTR)pCharDesc->sCharName, sCharName, ArrayCount(pCharDesc->sCharName)-1);
	((LPSTR)pCharDesc->sCharName)[ArrayCount(pCharDesc->sCharName)-1] = 0;
	strncpy((LPSTR)pCharDesc->sAccount, sAccount, ArrayCount(pCharDesc->sAccount)-1);
	((LPSTR)pCharDesc->sAccount)[ArrayCount(pCharDesc->sAccount)-1] = 0;
	pCharDesc->btJob = nJob;
	pCharDesc->btGender = nGender;
	pCharDesc->nCreateTime = CMiniDateTime::now();
	*((PWORD)&pCharDesc->wServerId) = nServerId;

	//将新的角色描述数据投递到角色描述更新列表中
	PostUpdateCharDesc(pCharDesc);

	//向各个角色排序列表中添加角色描述数据
	CharIdSortedDesc idDesc;
	CharNameSortedDesc nameDesc;
	UserIdSortedDesc uidDesc;

	idDesc.pCharDesc = pCharDesc;
	nameDesc.pCharDesc = pCharDesc;
	uidDesc.pCharDesc = pCharDesc;
	m_CharIdSortList.add(idDesc);
	m_CharNameSortList.add(nameDesc);
	m_UserIdSortList.add(uidDesc);

	return pCharDesc;
}

VOID CLocalDB::OnRountine()
{
	TICKCOUNT dwStartTick;
	TICKCOUNT dwBackupTick = 0;
	while (!terminated())
	{
		if (!m_boOpened)
		{
			osSleep(16);
			continue;
		}

		dwStartTick = _getTickCount();
		if ((m_nBackupInterval) && (0 == dwBackupTick))
			dwBackupTick = _getTickCount();
		//处理角色描述更新请求
		m_CharDescUpdateList.flush();
		if (m_CharDescUpdateList.count() > 0)
		{
			ProcessCharDescUpdate(4);
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

		if ((m_nBackupInterval) && ((INT)(_getTickCount() - dwBackupTick) >= m_nBackupInterval))
		{
			BackupFDBFiles();
			m_ZipBackup.StartZipBackup();
			dwBackupTick = 0;
		}

		osSleep(4);
	}
}

BOOL CLocalDB::LoadAllCharDesc()
{
	INT_PTR i;
	INT64 nDataId, nDataSize;
	INT_PTR nCharCount = (INT_PTR)m_CharDescDB.getDataCount();
	CharDesc *pCharDesc = m_CharDescAllocator.allocObjects(nCharCount);

	//保留列表内存空间并暂时关闭排序功能，在所有数据被读取并添加到列表后再排序可以提升效率
	m_CharIdSortList.setSorted(FALSE);
	m_CharIdSortList.reserve(nCharCount);
	m_CharNameSortList.setSorted(FALSE);
	m_CharNameSortList.reserve(nCharCount);
	m_UserIdSortList.setSorted(FALSE);
	m_UserIdSortList.reserve(nCharCount);

	for (i=0; i<nCharCount; ++i)
	{
		nDataId = m_CharDescDB.getId(i);
		nDataSize = m_CharDescDB.get(nDataId, pCharDesc, sizeof(*pCharDesc));
		if (nDataSize < (INT64)sizeof(*pCharDesc))
		{
			logError("角色描述数据库中ID为%lld的数据异常，读取字节为%lld", nDataId, nDataSize);
			return FALSE;
		}
		m_CharIdSortList[i].pCharDesc = pCharDesc;
		m_CharNameSortList[i].pCharDesc = pCharDesc;
		m_UserIdSortList[i].pCharDesc = pCharDesc;
		pCharDesc++;
	}
	//读取完成后重新对列表开启排序
	m_CharIdSortList.trunc(nCharCount);
	m_CharIdSortList.setSorted(TRUE);
	m_CharNameSortList.trunc(nCharCount);
	m_CharNameSortList.setSorted(TRUE);
	m_UserIdSortList.trunc(nCharCount);
	m_UserIdSortList.setSorted(TRUE);
	return TRUE;
}

VOID CLocalDB::ProcessCharDescUpdate(TICKCOUNT dwTimeLimit)
{
	CharDesc *pCharDesc;

	TICKCOUNT dwTimeOver = _getTickCount() + dwTimeLimit;
	INT_PTR nCount = m_CharDescUpdateList.count();
	do 
	{
		pCharDesc = m_CharDescUpdateList.pop();
		//m_CharDescDB 是角色描述数据库，也是数据文件处理对象，文件处理管理类，用于把角色数据写入到角色数据文件
		if (!m_CharDescDB.put(pCharDesc->nCharId, pCharDesc, sizeof(*pCharDesc)))
		{
			logError("无法向角色描述库更新角色(%lld)的描述信息", pCharDesc->nCharId);
		}
		nCount--;
	}
	while (nCount > 0 && _getTickCount() < dwTimeOver);
}

VOID CLocalDB::ProcessCharDataUpdate(TICKCOUNT dwTimeLimit)
{
	CGameDataBufferReader *pGDBReader;

	TICKCOUNT dwTimeOver = _getTickCount() + dwTimeLimit;
	INT_PTR nCount = m_CharDataUpdateList.count();
	INT64 nCharId;
	do 
	{
		pGDBReader = m_CharDataUpdateList.pop();
		nCharId = pGDBReader->GetDataId();
		if (!m_CharDataDB.put(nCharId, pGDBReader->getMemoryPtr(), pGDBReader->getLength()))
		{
			logError("无法向角色数据库更新角色(%lld)的数据", nCharId);
		}
		pGDBReader->SetDataBuffer(NULL);
		m_GDBReaderPool.FreeBufferReader(pGDBReader);
		nCount--;
	}
	while (nCount > 0 && _getTickCount() < dwTimeOver);
}

VOID CLocalDB::ProcessGuildDataUpdate(TICKCOUNT dwTimeLimit)
{
	CGameDataBufferReader *pGDBReader;

	TICKCOUNT dwTimeOver = _getTickCount() + dwTimeLimit;
	INT_PTR nCount = m_GuildDataUpdateList.count();
	INT64 nGuildId;
	do 
	{
		pGDBReader = m_GuildDataUpdateList.pop();
		nGuildId = pGDBReader->GetDataId();
		size_t nLen = pGDBReader->getLength();

		if (0 == nLen )
		{
			//删除家族数据
			if (!m_GuildDataDB.remove(nGuildId))
				logError("无法删除帮会数据库的帮会(%lld)的数据", nGuildId);
		}
		else if (!m_GuildDataDB.put(nGuildId, pGDBReader->getMemoryPtr(), nLen))
		{
			logError("无法向帮会数据库更新帮会(%lld)的数据", nGuildId);
		}
		pGDBReader->SetDataBuffer(NULL);
		m_GDBReaderPool.FreeBufferReader(pGDBReader);
		nCount--;
	}
	while (nCount > 0 && _getTickCount() < dwTimeOver);
}

