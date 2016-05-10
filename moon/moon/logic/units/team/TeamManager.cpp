#include "StdAfx.h"
#include "TeamManager.h"

CTeamManager::CTeamManager()
{

}

CTeamManager::~CTeamManager()
{

}

//创建队伍
bool CTeamManager::createTeam(CPlayer* pPlayer)
{
	assert(pPlayer);
	if (NULL == pPlayer) return false;
	
	CTeam* pTeam = CGlobalLogicObjAlloc::allocTeam();
	if (NULL == pTeam) return false;

	pTeam->create(pPlayer);
	TeamInfo team;
	team.pTeam = pTeam;
	team.duplicateId = 0;
	m_waitTeamList.add(team);
	return true;
}

//加入队伍
bool CTeamManager::joinTeam(CPlayer* pLeader, CPlayer* pPlayerJoin)
{
	assert(pLeader);
	assert(pPlayerJoin);
	if (NULL == pLeader || NULL == pPlayerJoin) return false;

	TeamInfo* pList = m_waitTeamList;
	for (INT_PTR iList = m_waitTeamList.count()-1; iList > -1; --iList)
	{
		if (pList[iList].pTeam->m_pTeamLeader == pLeader)
			return pList[iList].pTeam->joinTeam(pPlayerJoin);
	}
	return false;
}

//踢出退伍
bool CTeamManager::kickTeamPlayer( CPlayer* pLeader, CPlayer* pPlayerKick)
{
	TeamInfo* pList = m_waitTeamList;
	for (INT_PTR iList = m_waitTeamList.count()-1; iList > -1; --iList)
	{
		if (pList[iList].pTeam->m_pTeamLeader == pLeader)
			return pList[iList].pTeam->kickPlayer(pLeader, pPlayerKick);
	}
	return false;
}

//获取副本等待组队的队伍列表
void CTeamManager::getWaitTeamList( CBList<TeamInfo>& waitList, int dupId)
{
	waitList.clear();
	//dupId为0时表示搜索当前副本模块的所有等待队伍
	if (0 == dupId)
	{
		waitList.addList(m_waitTeamList);
		return;
	}
	TeamInfo* pList = m_waitTeamList;
	for (INT_PTR iList = m_waitTeamList.count()-1; iList > -1; --iList)
	{
		TeamInfo* pTeamInfo = &pList[iList];
		if (pTeamInfo->duplicateId == dupId)
		{
			waitList.add(*pTeamInfo);
		}
	}
}
