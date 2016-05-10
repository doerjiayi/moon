#include "StdAfx.h"

CMonsterEngine::CMonsterEngine():super()
{
	m_nProcessMonIndex = 0;
	m_nNewMonserId = 0;
}

CMonsterEngine::~CMonsterEngine()
{
	clearMonsters();
}

CDoer* CMonsterEngine::makeMonster(const int monId, Scene* pScene, const int px, const int py)
{
	if (!pScene || (px < 0) || (px >= pScene->m_nMapWidth) || (py < 0)
			|| (py >= pScene->m_nMapHeight))
		return NULL;

	const monsterStruct *pStdMon = g_ConfigManager->monsterDataAccessor.getMonsterById(monId);
	if (!pStdMon)
		return NULL;

	m_nNewMonserId++;
	CDoer *pActor = new CDoer();
	if (!pActor->initialize())
	{
		pActor->release();
		return NULL;
	}

	pActor->m_EntityId.server = 0;
	pActor->m_EntityId.series = monId;
	pActor->m_EntityId.time = m_nNewMonserId;
	_asncpytA(pActor->m_sName, pStdMon->name);
	pActor->m_wMonId = monId;
	pActor->m_nLevel = pStdMon->level;
	pActor->m_wEntityBody = pStdMon->body;
	pActor->m_nMonExp = pStdMon->exp;
	pActor->m_Battle.m_dwMonFlags = pStdMon->flags;
	pActor->m_Abil.recalcAbility();
	pActor->m_Abil.m_nHP = pActor->m_Abil.qiXue;
	pActor->m_Abil.m_nMP = pActor->m_Abil.neiLi;
	pActor->setScene(pScene, px, py);

	if (m_FreeMonIndexList.count() > 0)
		m_MonList[m_FreeMonIndexList.pop()] = pActor;
	else m_MonList.add(pActor);
	return pActor;
}

void CMonsterEngine::clearMonsters()
{
	CDoer **monList = m_MonList;
	for (INT_PTR i=m_MonList.count()-1; i>-1; --i)
	{
		CDoer *pMonster = monList[i];
		if (pMonster)
		{
			pMonster->disappear();
			pMonster->release();
		}
	}
	m_MonList.clear();
	m_FreeMonIndexList.clear();
}

void CMonsterEngine::run(uint32 nTickLimit)
{
	const TickTime dwCurrTick = g_LogicEngine->getTickCount();
	const INT_PTR nMaxCount = m_MonList.count();
	TickTime dwStartTick = GetTickCount();
	CDoer **monList = m_MonList;
	//例行处理怪物
	while (true)
	{
		if (m_nProcessMonIndex >= nMaxCount)
		{
			m_nProcessMonIndex = 0;
			break;
		}
		const INT_PTR nCurrIndex = m_nProcessMonIndex;
		m_nProcessMonIndex++;
		CDoer *pMonster = monList[nCurrIndex];
		if (!pMonster)
			continue;
		if (pMonster->m_boDisappeared && dwCurrTick - pMonster->m_dwDisappearTick >= 3 * 60 * 1000)
		{
			pMonster->release();
			monList[nCurrIndex] = NULL;
			m_FreeMonIndexList.add(nCurrIndex);
		}
		else
		{
			if (dwCurrTick - pMonster->m_dwLastRunTick >= 200)
			{
				pMonster->m_dwLastRunTick = dwCurrTick;
				pMonster->run(dwCurrTick);
			}
		}
		if (GetTickCount() - dwStartTick >= nTickLimit)
			break;
	}
	//刷新怪物
}
