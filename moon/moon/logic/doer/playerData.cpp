#include "StdAfx.h"

using namespace moon;
using namespace common::SystemId;

bool CPlayer::loadData(CDataPacketReader &data)
{
	if (m_boIsNewPlayer)
	{
		PlayerId charId;
		LPCSTR sCharName;
		WORD wLevel;
		BYTE btGender;
		data >> charId;
		data >> sCharName;
		data >> wLevel;
		data >> m_btJob;
		data >> btGender;
		
		m_nCreateTime = g_LogicEngine->getDateTime();
		m_btGender = btGender;
		m_nLevel = 1;
		m_nExp = 0;
		m_Abil.m_nHP = INT_MAX - 1;//在重新计算属性时会设置正确值
		m_Abil.m_nMP = INT_MAX - 1;//在重新计算属性时会设置正确值
		
		gotoBornScene();//出生场景ID坐标

		return true;
	}

	common::DBType::DataSectionHeader *pSecHdr;
	common::DBType::PlayerBasicData *pBaseData;
	
	//读取角色基本数据
	if (data.getAvaliableLength() < sizeof(*pSecHdr) + sizeof(*pBaseData))
		return false;
	pSecHdr = (common::DBType::DataSectionHeader*)data.getOffsetPtr();
	data.adjustOffset(sizeof(*pSecHdr));
	if (pSecHdr->wDataType != common::SystemId::sysPlayer)
	{
		logError( "角色(%lld:%s)数据的起始数据类型错误", m_EntityId.llid, m_sName);
		return false;
	}
	pBaseData = (common::DBType::PlayerBasicData*)data.getOffsetPtr();
	data.adjustOffset(sizeof(*pBaseData));
	m_nCreateTime = pBaseData->nCreateDateTime;
	m_nLevel = pBaseData->wLevel;
	m_nExp = pBaseData->nExp;
	m_GuildId = pBaseData->guildId;
	m_nCoin = pBaseData->nCoin;
	m_nGameGold = pBaseData->nGameGold;
	m_DearId = pBaseData->dearId;
	m_btGender = pBaseData->btGender;
	m_btJob = pBaseData->btJob;
	m_Abil.m_nHP = pBaseData->nHP;
	m_Abil.m_nMP = pBaseData->nMP;
	m_Bag.m_btBagCurSize = pBaseData->btCurBagSize;
	_asncpytA(m_sDearName, pBaseData->sDearName);

	//初始化放入地图
	Scene *scene = g_staticSceneManager->getSceneByID(pBaseData->m_StaticPosition.nSceneId);
	if (scene)
		setScene(scene, pBaseData->m_StaticPosition.nMapX,pBaseData->m_StaticPosition.nMapY);
	else gotoBornScene();

	//读取各系统数据
	CDoerUnit *pActorModule;
	while (data.getAvaliableLength() > 0)
	{
		if (data.getAvaliableLength() < sizeof(*pSecHdr))
			return false;
		pSecHdr = (common::DBType::DataSectionHeader*)data.getOffsetPtr();
		size_t dwSecEndPos = data.getPosition() + sizeof(*pSecHdr) + pSecHdr->wDataCount * pSecHdr->wStructSize;
		pActorModule = getModule(pSecHdr->wDataType);
		if (pActorModule)
		{
			if (!pActorModule->loadData(data))
				return false;
			assert(dwSecEndPos == data.getPosition());
		}
		else
		{
			logError( "角色(%lld:%s)数据中的数据类型%d为未知类型", m_EntityId.llid, m_sName, pSecHdr->wDataType);
			return false;
		}
	}

	return true;
}

void CPlayer::saveData(CDataPacket &data)
{
	//记录玩家动态副本位置
	recordDynamicScenePosition();

	/**** 保存角色基本数据 ****/
	common::DBType::DataSectionHeader *pSecHdr;
	common::DBType::PlayerBasicData *pBaseData;

	//保留基本数据空间
	data.reserve(data.getPosition() + sizeof(*pSecHdr) + sizeof(*pBaseData));
	//写入角色基础数据头
	pSecHdr = (common::DBType::DataSectionHeader*)data.getOffsetPtr();
	data.adjustOffset(sizeof(*pSecHdr));
	pSecHdr->wDataType = common::SystemId::sysPlayer;
	pSecHdr->wDataVersion = common::DBType::PlayerDataVersion;
	pSecHdr->wStructSize = sizeof(*pBaseData);
	pSecHdr->wDataCount = 1;
	//写入角色基础数据
	pBaseData = (common::DBType::PlayerBasicData*)data.getOffsetPtr();
	data.adjustOffset(sizeof(*pBaseData));
	ZeroMemory(pBaseData, sizeof(*pBaseData));
	pBaseData->charId = m_EntityId;
	_asncpytA(pBaseData->sCharName, m_sName);
	pBaseData->nAccountId = m_nAccountId;
	_asncpytA(pBaseData->sAccount, m_sAccount);
	pBaseData->nCreateDateTime = m_nCreateTime;
	pBaseData->wLevel = m_nLevel;
	pBaseData->nExp = m_nExp;
	pBaseData->nCoin = m_nCoin;
	pBaseData->nGameGold = m_nGameGold;
	pBaseData->guildId = m_GuildId;
	pBaseData->dearId = m_DearId;
	_asncpytA(pBaseData->sDearName, m_sDearName);
	pBaseData->btJob = m_btJob;
	pBaseData->btGender = m_btGender;
	pBaseData->m_StaticPosition = m_StaticPosition;
	pBaseData->m_DynamicPosition = m_DynamicPosition;
	pBaseData->nHP = m_Abil.m_nHP;
	pBaseData->nMP = m_Abil.m_nMP;
	pBaseData->btCurBagSize = m_Bag.m_btBagCurSize;

	//写入各系统数据
	CDoerUnit *pActorModule;
	for (int i=1; i<sysCount; ++i)
	{
		pActorModule = getModule(i);
		if (pActorModule)
		{
			pActorModule->saveData(data);
		}
	}
}
