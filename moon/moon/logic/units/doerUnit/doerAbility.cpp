#include "StdAfx.h"

using namespace common;

CDoerAbility::CDoerAbility()
	:super(), DoerAbilData()
{
	resetAbility();
	m_nHP = 100;
	m_nMP = 100;
	//qiXue = 100;
	//neiLi = 100;
}

CDoerAbility::~CDoerAbility()
{
}

void CDoerAbility::resetAbility()
{
	DoerAbilData::reset();
	m_wBody = 0;//衣服编号
	m_wWeapon = 0;//武器编号
	m_wMount = 0;//坐骑编号
}

void CDoerAbility::recalcAbility()
{
	resetAbility();
	calcLevelAbility();
	if (m_pPlayer)
	{
		calcEquipAbility();
	}
	if (m_nHP > qiXue)
		m_nHP = qiXue;
	if (m_nMP > neiLi)
		m_nMP = neiLi;
}

void CDoerAbility::calcLevelAbility()
{
#if 0
	int nLevel = m_pActor->m_nLevel;
	if (m_pPlayer)
	{
		const StdPlayerLevel* levelData = g_ConfigManager->playerLevelDataProvider.getLevel(nLevel);
		m_pPlayer->m_nExpMax = levelData->expMax;
		*this += levelData->jobAbils[m_pPlayer->m_btJob];
	}
	else if (m_pActor->m_btType >= eNormalMonster && m_pActor->m_btType < eNPC)
	{
		const monsterStruct *pMon = g_ConfigManager->monsterDataProvider.getMonsterById(m_pActor->m_wMonId);
		if (pMon)
		{
			qiXue = pMon->hp;
			neiLi = pMon->mp;
			waiGong = pMon->power;
			neiGong = pMon->power;
			waiFang = pMon->outerDefence;
			neiFang = pMon->innerDefence;
			mingZhong = pMon->accurate;
			shanBi = pMon->evasion;
			waiFangCT = pMon->outerDefenceCT;
			neiFangCT = pMon->innerDefenceCT;
			waiBao = pMon->baoji;
			neiBao = pMon->baoji;
			kangWaiBao = pMon->kangWaiBao;
			kangNeiBao = pMon->kangNeiBao;
			m_pActor->m_wMoveSpeed = pMon->moveSpeed;
			m_pActor->m_wAttackTime = pMon->attackSpeed;
			m_pActor->m_wAttackInterval = pMon->attackInterval;
			m_pActor->m_btAttackType = pMon->damageType;
		}
	}
#endif
}

void CDoerAbility::calcEquipAbility()
{
#if 0
	int i;
	const UserItem *pUserItem;
	const CStdItem *pStdItem;
	CPlayerEquip *pEquip = &m_pPlayer->m_Equip;
	int nCurTime = g_LogicEngine->getDateTime();
	const ItemAccessor &itemAccessor = g_ConfigManager->itemAccessor;

	for (i=0; i<CPlayerEquip::EquipCount; ++i)
	{
		pUserItem = pEquip->m_ItemList[i];
		//物品不存在或到期则不计算
		if (!pUserItem || (pUserItem->nExpireTime != 0 && pUserItem->nExpireTime < nCurTime))
			continue;

		//计算装备物品属性
		pStdItem = itemAccessor.getItem(pUserItem->wItemId);
		if (!pStdItem)
			continue;
		*this += *pUserItem;

		//计算装备外观
		if (i == iDress)
			m_wBody = pStdItem->m_wShape;
	}
#endif
}

void CDoerAbility::sendAbility()
{
	const DoerAbilData &abil = *this;
	CGateSendPacket &pack = m_pPlayer->allocSendPacket();
	pack.writeCmd(sysAbil, sSendAbility);
	pack << (unsigned short)m_pActor->m_nLevel;
	pack << (unsigned char)m_pPlayer->m_btJob;
	pack << (unsigned char)m_pPlayer->m_btGender;
	pack << (long long)m_pPlayer->m_nExp;
	pack << (long long)m_pPlayer->m_nExpMax;
	pack << (int)m_nHP;
	pack << (int)m_nMP;
	pack << abil;
	pack.flush();
}
