#include "StdAfx.h"

CDBManager::CDBManager()
	:super()
{
	m_boStarted = FALSE;
	SetClientName(_T("DBManager"));
	m_LoadPlayerList.setLock(&m_LoadPlayerLock);
	m_SavePlayerList.setLock(&m_SavePlayerLock);
}

CDBManager::~CDBManager()
{
	stopManager();
}

bool CDBManager::startManager()
{
	if (!m_boStarted)
	{
		if (!Startup())
			return FALSE;
		m_boStarted = TRUE;
	}
	return true;
}

void CDBManager::stopManager()
{
	if (m_boStarted)
	{
		Stop();
		m_DataPacketPool.freePacketMemory();
		m_DataPacketPool.freeAllPacket();
		m_boStarted = FALSE;
	}
}

void CDBManager::requestQueryChar(common::SERVERUSERHANDLE *pUserHandle, int nAccountId)
{
	CDataPacket &packet = AllocProtoPacket(common::DBType::dcQueryCharList);
	packet << *pUserHandle;
	packet << nAccountId;
	FlushProtoPacket(packet);
}

void CDBManager::requestCreateChar(common::SERVERUSERHANDLE *pUserHandle, int nAccountId, const char *sAccount, const char *sCharName, int btJob, int btGender)
{
	CDataPacket &packet = AllocProtoPacket(common::DBType::dcCreateChar);
	packet << *pUserHandle;
	packet << nAccountId;
	packet << sAccount;
	packet << sCharName;
	packet << (BYTE)btJob;
	packet << (BYTE)btGender;
	FlushProtoPacket(packet);
}

void CDBManager::requestDeleteChar(common::SERVERUSERHANDLE *pUserHandle, int nAccountId, common::PlayerId charId)
{
	CDataPacket &packet = AllocProtoPacket(common::DBType::dcDeleteChar);
	packet << *pUserHandle;
	packet << nAccountId;
	packet << charId;
	FlushProtoPacket(packet);
}

bool CDBManager::requestEnterGame(EnterGameStruct *pEnterGameStruct)
{
	CSafeLock sl(&m_LoadPlayerLock);
	if (GetLoadPlayerStruct(pEnterGameStruct->charId))
	{
		logWarn("请求进入游戏的角色(%lld:%s)已经存在于加载列表中",
			pEnterGameStruct->charId.llid, pEnterGameStruct->sCharName);
		return false;
	}

	LoadPlayerStruct *pLoadStruct = m_LoadPlayerAllocator.allocObject();
	pLoadStruct->enterStruct = *pEnterGameStruct;
	pLoadStruct->dwLoadTimeOut = 0;
	pLoadStruct->nLoadCount = 0;
	pLoadStruct->nErrorCode = 0;
	pLoadStruct->boIsNewPlayer = false;
	pLoadStruct->pCharDataPacket = NULL;
	m_LoadPlayerList.append(pLoadStruct);
	
	//从保存列表或保存失败列表直接装载数据
	CSafeLock sl2(&m_SavePlayerLock);
	SavePlayerStruct *pSaveStruct = GetSavePlayerStruct(pEnterGameStruct->charId);
	if (!pSaveStruct) pSaveStruct = GetFailureSavePlayerStruct(pEnterGameStruct->charId);
	if (pSaveStruct)
	{
		pLoadStruct->pCharDataPacket = m_DataPacketPool.allocPacket();
		pLoadStruct->pCharDataPacket->writeBuf(pSaveStruct->pCharDataPacket->getMemoryPtr(), pSaveStruct->pCharDataPacket->getLength());
		pLoadStruct->pCharDataPacket->setPosition(0);
	}
	return true;
}

CPoolDataPacket* CDBManager::requestPoolDataPacket()
{
	return m_DataPacketPool.allocPacket();
}

void CDBManager::requestSaveCharData(common::PlayerId playerId, int nPlayerIndex, CPoolDataPacket *pPacket)
{
	SavePlayerStruct *pSaveStruct;
	INT_PTR nSaveIndex;
	CSafeLock sl(&m_SavePlayerLock);

#define ____REPLACE_SAVE_STRUCT___ 	pSaveStruct->nPlayerIndex = nPlayerIndex;\
	pSaveStruct->dwSaveTimeOut = 0;\
	pSaveStruct->nSaveCount = 0;\
	pSaveStruct->nErrorCode = 0;\
	pSaveStruct->boSuccess = false;\
	pSaveStruct->pCharDataPacket->freeBack();\
	pSaveStruct->pCharDataPacket = pPacket;

	//如果角色数据正在存储队列中，则使用新的数据替换存储队列中的数据
	if ((pSaveStruct = GetSavePlayerStruct(playerId, &nSaveIndex)))
	{
		____REPLACE_SAVE_STRUCT___;
	}
	//如果角色数据在存储失败队列中，则使用新的数据替换存储队列中的数据并尝试重新存储
	else if ((pSaveStruct = GetFailureSavePlayerStruct(playerId, &nSaveIndex)))
	{
		____REPLACE_SAVE_STRUCT___;
		m_SavePlayerFailList.remove(nSaveIndex);
		m_SavePlayerList.append(pSaveStruct);
	}
	else 
	{
		pSaveStruct = m_SavePlayerAllocator.allocObject();
		pSaveStruct->charId = playerId;
		pSaveStruct->nPlayerIndex = nPlayerIndex;
		pSaveStruct->dwSaveTimeOut = 0;
		pSaveStruct->nSaveCount = 0;
		pSaveStruct->nErrorCode = 0;
		pSaveStruct->boSuccess = false;
		pSaveStruct->pCharDataPacket = pPacket;
		m_SavePlayerList.append(pSaveStruct);
	}
}

void CDBManager::SingleRun()
{
	if (m_boStarted)
	{
		super::SingleRun();
		ProcessLoadPlayerData();//处理加载角色数据
		ProcessSavePlayerData();//处理保存角色数据
	}
}

void CDBManager::ProcessLoadPlayerData()
{
	m_LoadPlayerList.flush();

	INT_PTR nIndex = 0;
	LoadPlayerStruct **ppLoadList = m_LoadPlayerList;
	LoadPlayerStruct *pLoadStruct;
	TICKCOUNT dwCurrTick = _getTickCount();
	CLogicGate *pGate;
//	CGameServer *pLogicServer = g_LogicServer;
	CGateManager *pGateManager = g_GateManager;
	CLogicEngine *pLogicEngine = g_LogicEngine;

	while (nIndex < m_LoadPlayerList.count()/*不能使用局部变量优化，因循环中会删除数据*/)
	{
		pLoadStruct = *ppLoadList;
		//加载数据成功完成
		if (pLoadStruct->pCharDataPacket)
		{
			pLogicEngine->openPlayer(&pLoadStruct->enterStruct, pLoadStruct->boIsNewPlayer, pLoadStruct->pCharDataPacket);
			pGate = pGateManager->getGate(pLoadStruct->enterStruct.userHandle.wGateIndex);
			if (pGate)
			{
				pGate->resultEnterGame(&pLoadStruct->enterStruct.userHandle, 0);
			}
			logInfo("加载数据(%u)成功完成",pLoadStruct->enterStruct.charId);
			RemoveLoadPlayerData(nIndex);
			continue;
		}
		//加载数据失败
		if (pLoadStruct->nErrorCode)
		{
			pGate = pGateManager->getGate(pLoadStruct->enterStruct.userHandle.wGateIndex);
			if (pGate)
			{
				pGate->resultEnterGame(&pLoadStruct->enterStruct.userHandle, -1001);
			}
			RemoveLoadPlayerData(nIndex);
			continue;
		}
		//加载数据超时，尝试重新加载
		if (dwCurrTick >= pLoadStruct->dwLoadTimeOut)
		{
			pLoadStruct->nLoadCount++;
			pLoadStruct->dwLoadTimeOut = dwCurrTick + 20 * 1000;
			//加载次数超出重试次数，则放弃加载
			if (pLoadStruct->nLoadCount > 3)
			{
				logWarn("[DBManager]角色(%lld:%s)加载超时，请求将被丢弃。",
					pLoadStruct->enterStruct.charId.llid, pLoadStruct->enterStruct.sCharName);
				pGate = pGateManager->getGate(pLoadStruct->enterStruct.userHandle.wGateIndex);
				if (pGate)
				{
					pGate->resultEnterGame(&pLoadStruct->enterStruct.userHandle, -1002);
				}
				RemoveLoadPlayerData(nIndex);
				continue;
			}
			else if (connected())
			{
				CDataPacket &pack = AllocProtoPacket(common::DBType::dcLoadCharData);
				pack << (int)pLoadStruct->enterStruct.nAccountId;
				pack << pLoadStruct->enterStruct.charId;
				FlushProtoPacket(pack);
			}
		}
		//调整处理记录到下一个
		ppLoadList++;
		nIndex++;
	}
}

void CDBManager::ProcessSavePlayerData()
{
	m_SavePlayerList.flush();

	INT_PTR nIndex = 0;
	SavePlayerStruct **ppSaveList = m_SavePlayerList;
	SavePlayerStruct *pSaveStruct;
	TICKCOUNT dwCurrTick = _getTickCount();

	while (nIndex < m_SavePlayerList.count()/*不能使用局部变量优化，因循环中会删除数据*/)
	{
		pSaveStruct = *ppSaveList;
		//保存数据成功完成
		if (pSaveStruct->boSuccess)
		{
			RemoveSavePlayerData(nIndex);
			continue;
		}
		//加载数据失败
		if (pSaveStruct->nErrorCode)
		{
			logError("[DBManager]保存角色(%lld)数据失败，错误码：%d，数据将转保存到转储列表中。",
				pSaveStruct->charId.llid, pSaveStruct->nErrorCode);
			AddFailureSavePlayerStruct(nIndex);
			continue;
		}
		//加载数据超时，尝试重新加载
		if (dwCurrTick >= pSaveStruct->dwSaveTimeOut)
		{
			pSaveStruct->nSaveCount++;
			pSaveStruct->dwSaveTimeOut = dwCurrTick + 20 * 1000;
			//加载次数超出重试次数，则放弃加载
			if (pSaveStruct->nSaveCount > 3)
			{
				logWarn("[DBManager]角色(%lld)保存超时，数据将转保存到转储列表中。",
					pSaveStruct->charId.llid);
				AddFailureSavePlayerStruct(nIndex);
				continue;
			}
			else if (connected())
			{
				CDataPacket &pack = AllocProtoPacket(common::DBType::dcSaveCharData);
				pack << pSaveStruct->charId;
				pack << (DWORD)pSaveStruct->pCharDataPacket->getLength();
				pack.writeBuf(pSaveStruct->pCharDataPacket->getMemoryPtr(), pSaveStruct->pCharDataPacket->getLength());
				FlushProtoPacket(pack);
			}
		}
		//调整处理记录到下一个
		ppSaveList++;
		nIndex++;
	}
}

void CDBManager::RemoveLoadPlayerData(INT_PTR nIndex)
{
	LoadPlayerStruct *pLoadStruct;

	CSafeLock sl(&m_LoadPlayerLock);
	pLoadStruct = m_LoadPlayerList[nIndex];
	m_LoadPlayerList.remove(nIndex);
	m_LoadPlayerAllocator.freeObject(pLoadStruct);
}

void CDBManager::RemoveSavePlayerData(INT_PTR nIndex)
{
	SavePlayerStruct *pSaveStruct;

	CSafeLock sl(&m_SavePlayerLock);
	pSaveStruct = m_SavePlayerList[nIndex];
	m_SavePlayerList.remove(nIndex);
	m_SavePlayerAllocator.freeObject(pSaveStruct);
	if (pSaveStruct->pCharDataPacket)
		pSaveStruct->pCharDataPacket->freeBack();
}

CDBManager::SavePlayerStruct* CDBManager::GetFailureSavePlayerStruct(const common::PlayerId charId, INT_PTR *pIndex /* = NULL */)
{
	SavePlayerStruct *pSaveStruct, **pSaveStructList;

	CSafeLock sl(&m_SavePlayerLock);
	pSaveStructList = m_SavePlayerFailList;
	for (INT_PTR i=m_SavePlayerFailList.count()-1; i>-1; --i)
	{
		pSaveStruct = pSaveStructList[i];
		if (pSaveStruct->charId.llid == charId.llid)
		{
			if (pIndex)
				*pIndex = i;
			return pSaveStruct;
		}
	}
	return NULL;
}

void CDBManager::AddFailureSavePlayerStruct(INT_PTR nSaveListIndex)
{
	SavePlayerStruct *pSaveStruct = m_SavePlayerList[nSaveListIndex];
	m_SavePlayerList.remove(nSaveListIndex);
	m_SavePlayerFailList.add(pSaveStruct);
}

void CDBManager::OnWorkThreadStart()
{
	RestoreSavePlayerFailureList();
}

void CDBManager::OnWorkThreadStop()
{
	WaitForAllDataComplete();
	DumpSavePlayerFailureList();
}

void CDBManager::SendRegisteClient()
{
	CDataPacket &packet = AllocProtoPacket(common::DBType::dcRegistClient);
	packet << (int)g_LogicServer->getServerId();
	packet << g_LogicServer->getServerName();
	packet << DB_DATA_VERSION;
	FlushProtoPacket(packet);
}

void CDBManager::SendKeepAlive()
{
	SendRegisteClient();
}

void CDBManager::DispatchRecvPacket(CDataPacketReader &inPacket)
{
	common::NetPacketMessage msg(0);
	inPacket >> msg;

	switch(msg.wMsg)
	{
	case common::DBType::dsRegistClient:
		HandleRegistClientRet(inPacket);
		break;
	case common::DBType::dsSendCharList:
		HandleQueryCharListRet(inPacket);
		break;
	case common::DBType::dsCreateChar:
		HandleCreateCharRet(inPacket);
		break;
	case common::DBType::dsDeleteChar:
		HandleDeleteCharRet(inPacket);
		break;
	case common::DBType::dsLoadCharData:
		HandleLoadCharDataRet(inPacket);
		break;
	case common::DBType::dsSaveCharData:
		HandleSaveCharDataRet(inPacket);
		break;
	}
}

void CDBManager::HandleRegistClientRet(CDataPacketReader &inPacket)
{
	int nErrorCode = -1;
	inPacket >> nErrorCode;
	if (nErrorCode != 0)
	{
		logError("[DBClient]注册数据客户端失败，错误码：%d", nErrorCode);
		close();
	}
}

void CDBManager::HandleQueryCharListRet(CDataPacketReader &inPacket)
{
	common::SERVERUSERHANDLE userHandle;
	int nAccountId, nCharCount;
	inPacket >> userHandle;
	inPacket >> nAccountId;
	inPacket >> nCharCount;

	CLogicGate *pGate = g_GateManager->getGate(userHandle.wGateIndex);
	if (pGate)
	{
		CPoolDataPacket *pRetPack = m_DataPacketPool.allocPacket();
		pRetPack->writeBuf(inPacket.getOffsetPtr(), inPacket.getAvaliableLength());
		pGate->resultUserQueryCharList(&userHandle, nCharCount, pRetPack);
	}
}

void CDBManager::HandleCreateCharRet(CDataPacketReader &inPacket)
{
	common::SERVERUSERHANDLE userHandle;
	int nErrorCode, nAccountId;
	inPacket >> userHandle;
	inPacket >> nErrorCode;
	inPacket >> nAccountId;

	CLogicGate *pGate = g_GateManager->getGate(userHandle.wGateIndex);
	if (pGate)
	{
		CPoolDataPacket *pRetPack = m_DataPacketPool.allocPacket();
		pRetPack->writeBuf(inPacket.getOffsetPtr(), inPacket.getAvaliableLength());
		pGate->resultUserCreateChar(&userHandle, nErrorCode, pRetPack);
	}
}

void CDBManager::HandleDeleteCharRet(CDataPacketReader &inPacket)
{
	common::SERVERUSERHANDLE userHandle;
	int nErrorCode;
	inPacket >> userHandle;
	inPacket >> nErrorCode;

	CLogicGate *pGate = g_GateManager->getGate(userHandle.wGateIndex);
	if (pGate)
	{
		pGate->resultUserDeleteChar(&userHandle, nErrorCode);
	}
}

void CDBManager::HandleLoadCharDataRet(CDataPacketReader &inPacket)
{
	int nErrCode;
	PlayerId charId;
	DWORD dwSize;
	inPacket >> nErrCode;
	inPacket >> charId;
	LoadPlayerStruct *pLoadStruct = GetLoadPlayerStruct(charId);
	if (pLoadStruct)
	{
		if (nErrCode == 0)
		{
			inPacket >> dwSize;
			//如果数据长度为0，则表示此角色为新角色
			if (dwSize == 0)
			{
				pLoadStruct->boIsNewPlayer = true;
				dwSize = (DWORD)inPacket.getAvaliableLength();
			}
			CPoolDataPacket *pDataPack = m_DataPacketPool.allocPacket();
			pDataPack->writeBuf(inPacket.getOffsetPtr(), dwSize);
			pDataPack->setPosition(0);
			pLoadStruct->pCharDataPacket = pDataPack;
		}
		else
		{
			logWarn("加载角色(%lld:%s)数据失败，错误码：%d", charId.llid, pLoadStruct->enterStruct.sCharName, nErrCode);
			pLoadStruct->nErrorCode = nErrCode;
		}
	}
}

void CDBManager::HandleSaveCharDataRet(CDataPacketReader &inPacket)
{
	common::PlayerId PlayerId;
	int nErrCode;

	inPacket >> nErrCode;
	inPacket >> PlayerId;
	
	SavePlayerStruct *pSaveStruct = GetSavePlayerStruct(PlayerId);
	if (pSaveStruct)
	{
		if (nErrCode == 0)
		{
			pSaveStruct->boSuccess = true;
		}
		else
		{
			pSaveStruct->nErrorCode = nErrCode;
		}
	}
}

CDBManager::LoadPlayerStruct* CDBManager::GetLoadPlayerStruct(const common::PlayerId charId, INT_PTR *pIndex /* = NULL */)
{
	CSafeLock sl(&m_LoadPlayerLock);

	LoadPlayerStruct** ppLoadList = m_LoadPlayerList;
	for (INT_PTR i = m_LoadPlayerList.count() - 1; i>-1; --i)
	{
		if (ppLoadList[i]->enterStruct.charId.llid == charId.llid)
		{
			if (pIndex)
				*pIndex = i;
			return ppLoadList[i];
		}
	}
	return NULL;
}

CDBManager::SavePlayerStruct* CDBManager::GetSavePlayerStruct(const common::PlayerId charId, INT_PTR *pIndex /* = NULL */)
{
	CSafeLock sl(&m_SavePlayerLock);

	SavePlayerStruct** ppSaveList = m_SavePlayerList;
	for (INT_PTR i = m_SavePlayerList.count() - 1; i>-1; --i)
	{
		if (ppSaveList[i]->charId.llid == charId.llid)
		{
			if (pIndex)
				*pIndex = i;
			return ppSaveList[i];
		}
	}
	return NULL;
}

void CDBManager::WaitForAllDataComplete()
{
	while (m_SavePlayerList.count() > 0)
	{
		ProcessSavePlayerData();
		moon::OS::osSleep(2);
	}
}

static const char szDumpDirectroy[] = "./runtime/dbdump/";
static const char szCharDataDumpExt[] = "cdd";

void CDBManager::DumpSavePlayerFailureList()
{
#if 0
	using namespace lib::stream;
	TCHAR sFilePath[1024], *ptrFileName;
	DumpPlayerDataHeader DPHdr;

	_tcscpy(sFilePath, szDumpDirectroy);
	ptrFileName = sFilePath + _tcslen(sFilePath);
	if (!FileUtil::DeepCreateDirectory(sFilePath))
	{
		OutputMsgError( _T("[DBManager]无法创建数据转储目录：%s"), sFilePath);
	}
	else ptrFileName = sFilePath;
	ZeroMemory(&DPHdr, sizeof(DPHdr));

	CSafeLock sl(&m_SavePlayerLock);
	SavePlayerStruct *pSaveStruct, **pSaveList = m_SavePlayerFailList;

	for (INT_PTR i=m_SavePlayerFailList.count()-1; i>-1; --i)
	{
		pSaveStruct = pSaveList[i];

		if (pSaveStruct->pCharDataPacket)
		{
			sprintf(ptrFileName, "%lld.%s", pSaveStruct->charId.llid, szCharDataDumpExt);
			{
				CFileStream fs(sFilePath, CFileStream::faCreate | CFileStream::faShareRead, CFileStream::AlwaysCreate);
				fs.setPosition(0);
				DPHdr.charId = pSaveStruct->charId;
				DPHdr.dwDataSize = (DWORD)pSaveStruct->pCharDataPacket->getLength();
				fs.write(&DPHdr, sizeof(DPHdr));
				fs.write(pSaveStruct->pCharDataPacket->getMemoryPtr(), DPHdr.dwDataSize);
			}

			pSaveStruct->pCharDataPacket->freeBack();
			pSaveStruct->pCharDataPacket = NULL;
			m_SavePlayerFailList.remove(i);
			m_SavePlayerAllocator.freeObject(pSaveStruct);
		}
	}
#endif
}

void CDBManager::RestoreSavePlayerFailureList()
{
#if 0
	using namespace lib::stream;
	TCHAR sFilePath[1024], *ptrFileName;


#ifdef WINDOWS
	sprintf_s(sFilePath, sizeof(sFilePath) - 1, "%s/*.%s", szDumpDirectroy, szCharDataDumpExt);
	WIN32_FIND_DATA FindData;
	ZeroMemory(&FindData, sizeof(FindData));
	HANDLE hFind = FindFirstFile(sFilePath, &FindData);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		_tcscpy(sFilePath, szDumpDirectroy);
		ptrFileName = sFilePath + _tcslen(sFilePath);

		DWORD dwHeaderSize;
		DumpPlayerDataHeader DPHdr;		
		CSafeLock sl(&m_SavePlayerLock);
		do 
		{
			if ((FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
			{
				_tcscpy(ptrFileName, FindData.cFileName);
				dwHeaderSize = 0;
				CFileStream fs(sFilePath, CFileStream::faShareRead, CFileStream::OpenExistsOnly);
				if (sizeof(DPHdr) == fs.read(&DPHdr, sizeof(DPHdr)))
				{
					CPoolDataPacket *pPacket = requestPoolDataPacket();
					pPacket->reserve(DPHdr.dwDataSize);
					if (DPHdr.dwDataSize == fs.read(pPacket->getMemoryPtr(), DPHdr.dwDataSize))
					{
						requestSaveCharData(DPHdr.charId, -1, pPacket);
					}
					else logWarn( _T("[DBManager]角色转储数据中没有包含足够长度的角色数据，转储文件%s被跳过"), FindData.cFileName);
				}
				else logWarn( _T("[DBManager]角色转储数据无效，转储文件%s被跳过"), FindData.cFileName);
			}
		}
		while (FindNextFile(hFind, &FindData));
	}
		FindClose(hFind);
#else
		sprintf(sFilePath,  "%s/*.%s", szDumpDirectroy, szCharDataDumpExt);
		strcpy(sFilePath, szDumpDirectroy);
		ptrFileName = sFilePath + strlen(sFilePath);
		DumpPlayerDataHeader DPHdr;
		CSafeLock sl(&m_SavePlayerLock);

		DIR *pDir = 0;
		struct dirent *pDirent = 0;
		struct stat file;
		pDir = opendir(sFilePath);
		if(0 == pDir)
		{
			return;
		}
		do
		{
			if(0 == (pDirent = readdir(pDir)))
			{
				break;
			}
			if(-1 == stat(pDirent->d_name, &file))
			{
				continue;
			}
			if(S_ISREG(file.st_mode))
			{
				CFileStream fs(sFilePath, CFileStream::faShareRead, CFileStream::OpenExistsOnly);
				if (sizeof(DPHdr) == fs.read(&DPHdr, sizeof(DPHdr)))
				{
					CPoolDataPacket *pPacket = requestPoolDataPacket();
					pPacket->reserve(DPHdr.dwDataSize);
					if (DPHdr.dwDataSize == fs.read(pPacket->getMemoryPtr(), DPHdr.dwDataSize))
					{
						requestSaveCharData(DPHdr.charId, -1, pPacket);
					}
					else logWarn( _T("[DBManager]角色转储数据中没有包含足够长度的角色数据，转储文件%s被跳过"), pDirent->d_name);
				}
				else logWarn( _T("[DBManager]角色转储数据无效，转储文件%s被跳过"), pDirent->d_name);
			}
		}while(true);
		closedir(pDir);
#endif

#endif

}

