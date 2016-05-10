#include "StdAfx.h"
#include "Team.h"

CTeam::CTeam()
{

}

CTeam::~CTeam()
{

}

void CTeam::create( CPlayer* pPlayer)
{
#if 0
	m_pTeamLeader = pPlayer;
	m_playerList.add(pPlayer);
	pPlayer->m_team.m_pTeam = this;
#endif
}

bool CTeam::joinTeam( CPlayer* pPlayer )
{
#if 0
	assert(pPlayer);
	if (NULL == pPlayer) return false;

	#pragma __CPMSG__(TODO: ray: 能否进入的组队判断)
	//等级,职业等其它判断
	//人满
	if (m_playerList.count() >= sMaxSize)
		return false;
	//判断重复
	CPlayer** ppList = m_playerList;
	for (INT_PTR i = m_playerList.count()-1; i > -1; --i)
	{
		if (ppList[i] == pPlayer)
			return false;
	}

	m_playerList.add(pPlayer);
	pPlayer->m_team.m_pTeam = this;
#endif

	return true;
}

bool CTeam::kickPlayer( CPlayer* pLeader, CPlayer* pTarget)
{
	assert(pLeader);
	assert(pTarget);
	if (NULL == pLeader || NULL == pTarget)	return false;

	//检查pPlayer是否是队长
	if (pLeader != m_pTeamLeader) return false;
	//进入退出队伍处理
	return quitTeam(pTarget);
}

bool CTeam::quitTeam( CPlayer* pPlayer )
{
#if 0
	assert(pPlayer);
	//查找是否在队伍中
	CPlayer** ppList = m_playerList;
	for(INT_PTR i = m_playerList.count(); i > -1; --i)
	{
		if (ppList[i] == pPlayer)
		{
			m_playerList.remove(i);
			pPlayer->m_team.m_pTeam = NULL;
			return true;
		}
	}
#endif
	return false;
}
