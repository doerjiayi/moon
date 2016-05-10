#include "StdAfx.h"
#include "GateSynergy.h"

CLogicGateSynergy::CLogicGateSynergy()
{
	m_SynergyDataList.setLock(&m_SynergyDataLock);
}

CLogicGateSynergy::~CLogicGateSynergy()
{

}

void CLogicGateSynergy::ProcessSynergyList()
{
	m_SynergyDataList.flush();

	INT_PTR i, nCount = m_SynergyDataList.count();
	for (i=0; i<nCount; ++i)
	{
		HandleSynergyData(&m_SynergyDataList[i]);
	}
	m_SynergyDataList.clear();
}

void CLogicGateSynergy::resultUserLogin(const common::SERVERUSERHANDLE *pUserHandle, int nErrorCode, int nUserId)
{
	SynergyData data;

	data.userHandle = *pUserHandle;
	data.opType = SynergyData::aorLogin;
	data.login.nErrorCode = nErrorCode;
	data.login.nUserId = nUserId;
	m_SynergyDataList.append(data);
}

void CLogicGateSynergy::resultUserQueryCharList(const common::SERVERUSERHANDLE *pUserHandle, int nCharCount, CPoolDataPacket *pPacket)
{
	SynergyData data;

	data.userHandle = *pUserHandle;
	data.opType = SynergyData::aorQueryCharList;
	data.querychar.nCharCount = nCharCount;
	data.querychar.pPacket = pPacket;
	m_SynergyDataList.append(data);
}

void CLogicGateSynergy::resultUserCreateChar(const common::SERVERUSERHANDLE *pUserHandle, int nErrorCode, CPoolDataPacket *pPacket)
{
	SynergyData data;

	data.userHandle = *pUserHandle;
	data.opType = SynergyData::aorCreateChar;
	data.createchar.nErrorCode = nErrorCode;
	data.createchar.pPacket = pPacket;
	m_SynergyDataList.append(data);
}

void CLogicGateSynergy::resultUserDeleteChar(const common::SERVERUSERHANDLE *pUserHandle, int nErrorCode)
{
	SynergyData data;

	data.userHandle = *pUserHandle;
	data.opType = SynergyData::aorDeleteChar;
	data.deletechar.nErrorCode = nErrorCode;
	m_SynergyDataList.append(data);
}

void CLogicGateSynergy::resultEnterGame(const common::SERVERUSERHANDLE *pUserHandle, int nErrorCode)
{
	SynergyData data;
	data.userHandle = *pUserHandle;
	data.opType = SynergyData::aorEnterGame;
	data.enterGame.nErrorCode = nErrorCode;
	m_SynergyDataList.append(data);
}
