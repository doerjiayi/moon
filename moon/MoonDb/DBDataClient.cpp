#include "StdAfx.h"
#include "DBDataClient.h"

using namespace GameDBType;
using namespace common;
using namespace common::DBType;

CDBDataClient::CDBDataClient(CDBDataServer *lpDataServer, SOCKET nSocket, PSOCKADDR_IN pAddrIn)
	:Inherited(nSocket, pAddrIn)
{
	m_pDataServer = lpDataServer;
	m_pLocalDB = lpDataServer->GetLocalDB();
	m_pSQLDB = lpDataServer->GetSQLDB();
	m_dwClosedTick = 0;
	setMsgLock(m_pDataServer->getItnMsgLock());
}

CDBDataClient::~CDBDataClient()
{
}

VOID CDBDataClient::OnConnected()
{
	logError( _T("数据客户端（%s:%d）的已连接"),
		GetRemoteHost(), GetRemotePort());
}

VOID CDBDataClient::OnDisconnected()
{
	m_dwClosedTick = _getTickCount();
	logWarn( _T("数据客户端(%s:%d)连接已断开"), GetRemoteHost(), GetRemotePort() );
	//不能调用父类的断开连接函数，因为希望在连接断开后继续保留套接字中的数据以便处理
}

VOID CDBDataClient::OnError(INT errorCode)
{
	//输出错误消息
	OutputError( errorCode, _T("数据客户端(%s:%d)套接字发生错误"), GetRemoteHost(), GetRemotePort() );
	//断开连接
	close();
}

VOID CDBDataClient::DispatchMsg(UINT uMsg, UINT_PTR uParam1, UINT_PTR uParam2, UINT_PTR uParam3)
{
}

VOID CDBDataClient::DispatchRecvPacket(CDataPacketReader &inPacket)
{
	common::NetPacketMessage msg;
	if (inPacket.getAvaliableLength() < sizeof(msg))
	{
 		logError( _T("连接“%s:%d”发送的数据包中没有包含消息头，连接被关闭"),
 			GetRemoteHost(), GetRemotePort());
 		close();
		return;
	}
	inPacket >> msg;

	if (!registed())
	{
 		if (msg.wMsg != DBType::dcRegistClient)
 		{
 			logError( _T("连接“%s:%d”在注册服务器成功之前发送了非法的数据包，连接已被关闭"),
 				GetRemoteHost(), GetRemotePort());
 			close();
		}
		else CatchRegisterServer(inPacket);
		return;
	}

	switch(msg.wMsg)
	{
	//数据客户端查询用户角色列表
	case DBType::dcQueryCharList:
		CatchQueryCharList(inPacket);
		break;
	//数据客户端创建新角色
	case DBType::dcCreateChar:
		CatchCreateChar(inPacket);
		break;
	//数据客户端删除角色
	case DBType::dcDeleteChar:
		CatchDeleteChar(inPacket);
		break;
	//数据客户端读取角色数据
	case DBType::dcLoadCharData:
		CatchLoadCharData(inPacket);
		break;
	//数据客户端保存角色数据
	case DBType::dcSaveCharData:
		CatchSaveCharData(inPacket);
		break;
	//数据客户端读取帮会ID列表
	case DBType::dcLoadGuildIdList:
		CatchLoadGuildIdList(inPacket);
		break;
	//数据客户端读取帮会数据
	case DBType::dcLoadGuildData:
		CatchLoadGuildData(inPacket);
		break;
	//数据客户端保存帮会数据
	case DBType::dcSaveGuildData:
		CatchSaveGuildData(inPacket);
		break;
	//数据客户端查询角色描述数据
	case DBType::dcQueryCharDesc:
		CatchQueryCharDescList(inPacket);
		break;
	//数据客户端请求重命名角色
	case DBType::dcRenameChar:
		CatchRenameChar(inPacket);
		break;
/*
	//请求设置角色状态
	case DBC_SET_CHARSTATE:
		CatchSetCharState(inPacket);
		break;
	//请求新的随机角色名
	case DBC_GET_RANDCHARNAME:
		CatchGetRandCharName(inPacket);
		break;
	//请求导入角色数据
	case DBC_IMPORT_CHARDATA:
		CatchImportCharData(inPacket);
		break;
*/
	//注册服务器
	case DBType::dcRegistClient:
		//消息包作为心跳包，此处不用处理
		break;
	default:
		{
			logWarn( _T("收到“%s:%d:%s”的数据包中包含未知的消息号(%d)，数据长度为(%d)"),
				GetRemoteHost(), GetRemotePort(), m_sClientName, msg.wMsg, inPacket.getAvaliableLength());
		}
		break;
	}
}

VOID CDBDataClient::CatchRegisterServer(CDataPacketReader &inPacket)
{
	inPacket >> m_nServerId;
	m_sClientName[ArrayCount(m_sClientName)-1] = 0;
	inPacket.readString(m_sClientName, ArrayCount(m_sClientName) - 1);
	DWORD dwDataVersion;
	inPacket >> dwDataVersion;

	INT nErrorCode = 0;
	if (dwDataVersion != DBSDATATYPE_VERSION)
	{
		logError( _T("连接（%s:%d:%s）的数据版本%08X与当前数据版本%08X不匹配"),
			GetRemoteHost(), GetRemotePort(), m_sClientName, dwDataVersion, DBSDATATYPE_VERSION);
		nErrorCode = 1;
	}
	else
	{
		logError( _T("数据客户端（%s:%d:%s）注册服务器成功。"),GetRemoteHost(),
				GetRemotePort(), m_sClientName);
	}
	//回应注册结果
	CDataPacket& pack = AllocProtoPacket(DBType::dcRegistClient);
	pack << nErrorCode;
	FlushProtoPacket(pack);
}

inline void WriteCharDesc(CDataPacket& pack, const CharDesc *pDesc)
{
	pack << pDesc->nCharId;
	pack << pDesc->sCharName;
	pack << pDesc->wLevel;
	pack << pDesc->btJob;
	pack << pDesc->btGender;
}

VOID CDBDataClient::CatchQueryCharList(CDataPacketReader &inPacket)
{
	SERVERUSERHANDLE UserHandle;
	INT nUserId;

	inPacket >> UserHandle;
	inPacket >> nUserId;

	PCHARDESC pCharList[64], pDesc;
	INT nCharCount = m_pLocalDB->GetUserCharDescList(nUserId, m_nServerId, pCharList, ArrayCount(pCharList), FALSE, TRUE);
	INT nLastUseTime = 0, nLastCharIdx = -1;
	//返回角色列表
	CDataPacket &pack = AllocProtoPacket(DBType::dsSendCharList);
	pack << UserHandle;
	pack << nUserId;
	pack << nCharCount;

	for (INT_PTR i=0; i<nCharCount; ++i)
	{
		pDesc = pCharList[i];
		WriteCharDesc(pack, pDesc);
		//客户端查询角色时要知道是否被禁用
		pack << pDesc->wState;
		//确定最后一次登陆的角色ID
		if (nLastCharIdx == -1 || pDesc->nUpdateTime > nLastUseTime)
		{
			nLastUseTime = pDesc->nUpdateTime;
			nLastCharIdx = (INT)i;
		}
	}
	pack << nLastCharIdx;

	FlushProtoPacket(pack);
}

//功能描述：
//给一个指定的账号追加一个角色数据,即创建一个新的角色描述并保存角色数据，通常用于导号功能。
//目的是将一个已存在的角色数据导入到另一个账号中。
VOID CDBDataClient::CatchImportCharData(CDataPacketReader &inPacket)
{
/*	INT nUserId;
	DWORD dwDataSize;

	CHAR sAccount[64], sCharName[64];
	BYTE btJob = 0, btGender = 0, btCountry = 0xFF, btFace = 0, nError = 0;
	CharDesc *pCharDesc = NULL;

	sAccount[0] = sCharName[0] = 0;
	sAccount[ArrayCount(sAccount)-1] = 0;
	sCharName[ArrayCount(sCharName)-1] = 0;

	inPacket.readString(sAccount, ArrayCount(sAccount) - 1); //读取账号名
	inPacket.readString(sCharName, ArrayCount(sCharName) - 1);//读取角色名
	inPacket >> nUserId; //读取账号ID
	inPacket >> dwDataSize; //读取数据大小

	//-------------------------------------------------------------------------------------
	//角色名称是否已被使用
	pCharDesc = m_pLocalDB->GetCharDesc(sCharName);
	if ( NULL != pCharDesc ) 
	{
		//不同账号则尝试给角色名追加后缀，并重新创建角色描述
		if ( 0 != strcmp(pCharDesc->sAccount, sAccount) )
		{
			strcat(sCharName, "(-1)");
			pCharDesc = NULL;
		}
	}

	if (!pCharDesc)
	{
		//向LocalDB添加新角色描述
		pCharDesc = m_pLocalDB->AddChar(m_nServerId, nUserId, sAccount, sCharName, 
			btJob, btGender, btCountry, btFace);
		if (!pCharDesc)
		{
			//Error:服务器内部错误（LocalDB数据库错误）
			nError = 1;
			goto ret;
		}
		else
		{
			m_pSQLDB->PostAddNewChar(pCharDesc);

			//新创建的角色ID跟导入的是不匹配的，这里有必要时在修改一下系统生成的角色ID，
			//但产生的新问题暂时无法估计，请以后需要时在做考虑修改。
			//pDesc->nCharId = nCharId;
		}
	}

	//---------------------------------------------------------------------------------
	CGameDataBuffer *pBuffer = m_pDataServer->AllocGameDataBuffer();
	pBuffer->AddRef();
	pBuffer->SetData(pCharDesc->nCharId, inPacket.getOffsetPtr(), dwDataSize);
	//跳过角色基本数据头结构
	//{ 
	//	BaseDataIdent	: DWORD;
	//	BaseDataVersion	: Word; 
	//	BaseDataSize	: Word; 
	//}
	PCHARBASEDATA pBaseData = (PCHARBASEDATA)pBuffer->getPositionPtr(8);

	//更新角色的ID，因为有可能是新创建的角色描述
	if ( pBaseData->nCharID != pCharDesc->nCharId )
	{
		pBaseData->nCharID = pCharDesc->nCharId;
	}

	//对角色描述数据的更新
	pCharDesc->wLevel = pBaseData->Level;
	pCharDesc->btGender = pBaseData->btSex;
	pCharDesc->btJob = pBaseData->btJob;
	pCharDesc->btFace = pBaseData->btFaceIndex;
	pCharDesc->btCountry = pBaseData->btCountry;
	pCharDesc->btMilitaryRank = pBaseData->btMilitaryRank;
	pCharDesc->nCreateTime = pBaseData->nCreateDateTime; //角色的创建时间要改回导入的角色的创建时间。便于内网测试BUG
	pCharDesc->nUpdateTime = CMiniDateTime::now();
	m_pLocalDB->PostUpdateCharDesc(pCharDesc);
	m_pSQLDB->PostUpdateCharDesc(pCharDesc);

	m_pLocalDB->PostUpdateCharData(pBuffer);
	m_pSQLDB->PostUpdateCharData(pBuffer);

	pBuffer->Release();

	//---------------------------------------------------------------------------------
ret:
	CDataPacket &pack = AllocProtoPacket(DBS_RET_IMPORT_CHARDATA);
	pack << nError; //0表示成功
	FlushProtoPacket(pack);
*/
}

VOID CDBDataClient::CatchCreateChar(CDataPacketReader &inPacket)
{
	SERVERUSERHANDLE UserHandle;
	INT nUserId;
	CHAR sAccount[64], sCharName[64];
	BYTE btGender = 0, btJob = 0;
	CharDesc *pDesc;

	sAccount[0] = sCharName[0] = 0;
	sAccount[ArrayCount(sAccount)-1] = 0;
	sCharName[ArrayCount(sCharName)-1] = 0;

	inPacket >> UserHandle;
	inPacket >> nUserId;
	inPacket.readString(sAccount, ArrayCount(sAccount) - 1);
	inPacket.readString(sCharName, ArrayCount(sCharName) - 1);
	inPacket >> btJob;
	inPacket >> btGender;

	CDataPacket &pack = AllocProtoPacket(DBType::dsCreateChar);
	pack << UserHandle;
	//检查数据是否有效
	if (!sAccount || !sAccount[0] || !sCharName || !sCharName[0] 
	|| btGender > 1 || (strlen(sCharName) > 24))
	{
		//Error:无效的请求数据
		pack << (int)-1;
		pack << nUserId;
	}
	else if (!m_pDataServer->GetDBEngine()->getEnableCreateCharacter())
	{
		//Error:本服务器禁止创建角色
		pack << (int)-2;
		pack << nUserId;
	}
	else 
	{
		//将角色名称中的字母全部最小化并检查名称是否合法
		CDBEngine *pEngine = m_pDataServer->GetDBEngine();
		pEngine->LowerCaseNameStr(sCharName);
		if (!pEngine->CheckNameStr(sCharName))
		{
			//Error:角色名非法
			pack << (int)-3;
			pack << nUserId;
		}
		else
		{
			//判断是否能创建更多的角色,最多允许3个角色
			if (m_pLocalDB->GetUserAvaliableCharCount(nUserId, m_nServerId) > 2) //已经有3个角色了
			{
				//Error:无法创建更多的角色
				pack << (int)-4;
				pack << nUserId;
			}
			else
			{
				//角色名称是否已被使用
				if (m_pLocalDB->GetCharDesc(sCharName))
				{
					//Error:角色名称已被使用
					pack << (int)-5;
					pack << nUserId;
				}
				else
				{
					//向LocalDB添加角色
					pDesc = m_pLocalDB->AddChar(m_nServerId, nUserId, sAccount, sCharName, btJob, btGender);
					if (!pDesc)
					{
						//Error:服务器内部错误（LocalDB数据库错误）
						pack << (int)-6;
						pack << nUserId;
					}
					else
					{
						m_pSQLDB->PostAddNewChar(pDesc);
						//返回新创建的角色描述
						pack << (int)0;
						pack << nUserId;
						WriteCharDesc(pack, pDesc);
					}
				}
			}
		}
	}
	FlushProtoPacket(pack);
}

VOID CDBDataClient::CatchDeleteChar(CDataPacketReader &inPacket)
{
	SERVERUSERHANDLE UserHandle;
	INT nUserId;
	INT64 nCharId;
	CharDesc *pCharDesc;
	INT nErrorCode = 0;

	inPacket >> UserHandle;
	inPacket >> nUserId;
	inPacket >> nCharId;

	pCharDesc = m_pLocalDB->GetCharDesc(nCharId);
	if (!pCharDesc)
	{
		//Error: 角色不存在
		nErrorCode = -1;
	}
	else if (pCharDesc->nUserId != nUserId || pCharDesc->wServerId != m_nServerId)
	{
		//Error: 非法的删除角色请求
		nErrorCode = -2;
	}
	else if ((pCharDesc->wState & CHARSTATE_DELETED) || (pCharDesc->wState & CHARSTATE_DISABLED))
	{
		//Error: 角色早已被删除
		nErrorCode = -3;
	}
	else
	{
		nErrorCode = 0;
		pCharDesc->wState |= CHARSTATE_DELETED;
		m_pLocalDB->PostUpdateCharDesc(pCharDesc);
	}

	CDataPacket &pack = AllocProtoPacket(DBType::dsDeleteChar);
	pack << UserHandle;
	pack << nErrorCode;
	pack << nUserId;
	pack << nCharId;
	FlushProtoPacket(pack);
}

VOID CDBDataClient::CatchLoadCharData(CDataPacketReader &inPacket)
{
	INT nUserId;
	INT64 nCharId;
	DWORD dwDataSize;

	inPacket >> nUserId;
	inPacket >> nCharId;

	CDataPacket &pack = AllocProtoPacket(DBType::dsLoadCharData);

	CharDesc *pCharDesc = m_pLocalDB->GetCharDesc(nCharId);
	if (!pCharDesc || pCharDesc->nUserId != nUserId 
		|| (pCharDesc->wState & (CHARSTATE_DELETED | CHARSTATE_DISABLED))
		|| pCharDesc->wServerId != m_nServerId )
	{
		//Error: 非法的角色数据加载请求
		pack << (int)1;
		pack << nCharId;
	}
	else
	{
		dwDataSize = 0;
		pack << (int)0;//SUCCESS
		pack << nCharId;
		pack << dwDataSize;
		//优先从更新队列里面取角色数据，防止出现快速重登录导致的回档现象
		dwDataSize = m_pLocalDB->GetCharDataInUpdateList(nCharId, pack);
		if (dwDataSize != 0)
		{
			pack.adjustOffset(-(INT64)(dwDataSize + sizeof(dwDataSize)));
			pack << dwDataSize;
			pack.adjustOffset(dwDataSize);
		}
		else 
		{
			//从磁盘文件读取
			dwDataSize = (DWORD)m_pLocalDB->GetCharData(nCharId, NULL, 0);
			pack.adjustOffset(-(INT64)(sizeof(dwDataSize)));
			pack << dwDataSize;
			//如果有角色数据则直接返回角色数据，否则将返回角色描述
			if (dwDataSize > 0)
			{
				pack.reserve(pack.getLength() + dwDataSize);
				pack.adjustOffset(m_pLocalDB->GetCharData(nCharId, pack.getOffsetPtr(), dwDataSize));
			}
			else
			{
				WriteCharDesc(pack, pCharDesc);
			}
		}
	}
	FlushProtoPacket(pack);
}

VOID CDBDataClient::CatchSaveCharData(CDataPacketReader &inPacket)
{
	INT64 nCharId;
	DWORD dwDataSize;

	inPacket >> nCharId;
	inPacket >> dwDataSize;

	CGameDataBuffer *pBuffer = m_pDataServer->AllocGameDataBuffer();
	pBuffer->AddRef();
	pBuffer->SetData(nCharId, inPacket.getOffsetPtr(), dwDataSize);

	CharDesc *pCharDesc = m_pLocalDB->GetCharDesc(nCharId);
	if (pCharDesc)
	{
		//跳过角色基本数据头结构
		common::DBType::PlayerBasicData *pBaseData = (common::DBType::PlayerBasicData *)pBuffer->getPositionPtr(sizeof(common::DBType::DataSectionHeader));

		//发起对角色描述数据的更新
		pCharDesc->wLevel = pBaseData->wLevel;
		pCharDesc->btGender = pBaseData->btGender;
		pCharDesc->nUpdateTime = CMiniDateTime::now();

		m_pLocalDB->PostUpdateCharDesc(pCharDesc);
		m_pSQLDB->PostUpdateCharDesc(pCharDesc);
	}
	else logError( _T("试图更新在本地角色描述数据中找不到的角色数据(%lld)"), nCharId);

	m_pLocalDB->PostUpdateCharData(pBuffer);
	m_pSQLDB->PostUpdateCharData(pBuffer);

	pBuffer->Release();

	CDataPacket &pack = AllocProtoPacket(DBType::dsSaveCharData);
	pack << (int)0;//SUCCESS
	pack << nCharId;
	FlushProtoPacket(pack);
}

VOID CDBDataClient::CatchLoadGuildIdList(CDataPacketReader &inPacket)
{
	WORD wRequestServerId;
	inPacket >> wRequestServerId;

	int dwGuildCount = m_pLocalDB->GetGuildCount();
	PINT64 pGuildIDs = new long long[dwGuildCount];
	m_pLocalDB->GetGuildIdList(0,pGuildIDs, dwGuildCount);

	//家族所属服务器ID: 偏移:1723 头：8 大小: 2Bytes
	const int CGuildServeIndexOffset = 1723 + 8;
    char pBuffer[CGuildServeIndexOffset + 2];
    DWORD dwServerGuildCount = 0;
	for (int i=0; i<dwGuildCount; ++i)
	{
	   INT64 iGuildID = pGuildIDs[i];
	   
	   if (m_pLocalDB->GetGuildData(iGuildID, pBuffer, sizeof(pBuffer)) != sizeof(pBuffer)) continue;
	   WORD wServerId = *(WORD*)(pBuffer + CGuildServeIndexOffset);
	   if (0 == wServerId) wServerId = ((WORD*)&iGuildID)[3];//如果ServerId为0，则从家族ID中取出
	   if (wServerId != wRequestServerId)	continue;	//只返回属于请求服务器的家族
	   pGuildIDs[dwServerGuildCount] = iGuildID;
	   dwServerGuildCount++;
	}

	CDataPacket &pack = AllocProtoPacket(DBType::dsLoadGuildIdList);
	pack << (int)0;//SUCCESS
	pack << dwServerGuildCount;
	//pack.reserve(dwServerGuildCount * sizeof(INT64) + pack.getPosition());
	//m_pLocalDB->GetGuildIdList(0, (PINT64)pack.getOffsetPtr(), dwGuildCount);
	//pack.adjustOffset(dwServerGuildCount * sizeof(INT64));
	pack.writeBuf(pGuildIDs, dwServerGuildCount * sizeof(INT64));
	delete [] pGuildIDs;
	
	FlushProtoPacket(pack);
}

VOID CDBDataClient::CatchLoadGuildData(CDataPacketReader &inPacket)
{
	INT64 nGuildId;
	DWORD dwDataSize;

	inPacket >> nGuildId;

	CDataPacket &pack = AllocProtoPacket(DBType::dsLoadGuildData);
	dwDataSize = (DWORD)m_pLocalDB->GetGuildData(nGuildId, NULL, 0);
	pack << (int)0;//SUCCESS
	pack << nGuildId;
	pack << dwDataSize;
	pack.reserve(pack.getLength() + dwDataSize);
	pack.adjustOffset(m_pLocalDB->GetGuildData(nGuildId, pack.getOffsetPtr(), dwDataSize));
	FlushProtoPacket(pack);
}

VOID CDBDataClient::CatchSaveGuildData(CDataPacketReader &inPacket)
{
	INT64 nGuildId;
	DWORD dwDataSize;

	inPacket >> nGuildId;
	inPacket >> dwDataSize;

	CGameDataBuffer *pBuffer = m_pDataServer->AllocGameDataBuffer();
	pBuffer->AddRef();
	pBuffer->SetData(nGuildId, inPacket.getOffsetPtr(), dwDataSize);
	m_pLocalDB->PostUpdateGuildData(pBuffer);
	m_pSQLDB->PostUpdateGuildData(pBuffer);
	pBuffer->Release();

	CDataPacket &pack = AllocProtoPacket(DBType::dsSaveGuildData);
	pack << (int)0;//SUCCESS
	pack << nGuildId;
	FlushProtoPacket(pack);
}

VOID CDBDataClient::CatchQueryCharDescList(CDataPacketReader &inPacket)
{
	INT nCharIdCount, nCharDescCount = 0;
	INT64 nCharId;
	size_t nCountPos;
	CharDesc *pDesc;
	SERVERUSERHANDLE srvHdl;

	inPacket >> srvHdl;
	inPacket >> nCharIdCount;

	CDataPacket &pack = AllocProtoPacket(DBType::dsQueryCharDesc);
	pack << srvHdl;
	nCountPos = pack.getPosition();
	pack << (int)0;//预留数量值写入位置
	for (INT_PTR i=nCharIdCount-1; i>-1; --i)
	{
		inPacket >> nCharId;
		pDesc = m_pLocalDB->GetCharDesc(nCharId);
		if (pDesc)
		{
			WriteCharDesc(pack, pDesc);
			nCharDescCount++;
		}
	}
	*((PINT)pack.getPositionPtr(nCountPos)) = nCharDescCount;
	FlushProtoPacket(pack);
}

VOID CDBDataClient::CatchRenameChar(CDataPacketReader &inPacket)
{
	INT64 nCharId;
	char sCharName[64];

	inPacket >> nCharId;
	sCharName[0] = 0;
	inPacket.readString(sCharName, ArrayCount(sCharName) - 1);
	sCharName[ArrayCount(sCharName)-1] = 0;

	CDataPacket &pack = AllocProtoPacket(DBType::dsRenameChar);
	//检查角色名是否合法
	CDBEngine *pEngine = m_pDataServer->GetDBEngine();
	pEngine->LowerCaseNameStr(sCharName);
	if (!sCharName[0] || (strlen(sCharName) > 24) || !pEngine->CheckNameStr(sCharName))
	{
		//Error:角色名非法
		pack << (int)1;
	}
	else
	{
		if (!m_pLocalDB->RenameChar(nCharId, sCharName))
		{
			//Error:角色名已被使用
			pack << (int)2;
		}
		else
		{
			pack << (int)0;//SUCCESS
		}
	}
	pack << nCharId;
	pack << sCharName;
	FlushProtoPacket(pack);
}

VOID CDBDataClient::CatchSetCharState(CDataPacketReader &inPacket)
{
/*
	char sCharName[64];
	BYTE bState;
	GameDBType::CharDesc* pCharDesc = NULL;
	sCharName[0] = 0;
	inPacket.readString(sCharName, ArrayCount(sCharName) - 1);
	sCharName[ArrayCount(sCharName)-1] = 0;

	inPacket.readBuf(&bState, sizeof(bState));

	CDataPacket &pack = AllocProtoPacket(DBS_RET_SETCHARSTATE);
	//检查角色名是否合法
	CDBEngine *pEngine = m_pDataServer->GetDBEngine();
	pEngine->LowerCaseNameStr(sCharName);
	//if (!sCharName[0] || (strlen(sCharName) > 24) || !pEngine->CheckNameStr(sCharName))
	if (!sCharName[0])  //合区的角色名可能包含括号，属于非法字符，这里仅仅用角色名查找，不需要做检查是否非法名字
	{
		//Error:角色名非法
		pack << (int)1;
	}
	else
	{
		pCharDesc = m_pLocalDB->SetCharState(sCharName, bState);
		if (pCharDesc)
		{
			pack << (int)0;//SUCCESS
			m_pSQLDB->PostUpdateCharDesc(pCharDesc);
		}
		else
		{
			//Error:未知错误
			pack << (int)2;
		}
	}
	pack << sCharName;
	FlushProtoPacket(pack);
*/
}

BOOL CDBDataClient::HasRemainData()
{
	PDATABUFFER pBuffer;
	
	//如果消息队列非空则仍需继续处理
	if ( getMsgCount() > 0 )
		return TRUE;

	//如果网络数据包未处理完毕则返回TRUE
	pBuffer = getRecvBuffer();
	if ( pBuffer->nOffset > 0 )
	{
		return TRUE;
	}
	pBuffer = getProcRecvBuffer();
	if ( pBuffer->nOffset > 0 )
	{
		return TRUE;
	}

	return FALSE;
}
