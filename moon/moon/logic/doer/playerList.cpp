#include "StdAfx.h"

void CPlayerList::addPlayer(CPlayer *pPlayer)
{
	m_PlayerList.push_back(pPlayer);
	m_PlayerNameList[std::string(pPlayer->m_sName)] = pPlayer;
	m_PlayerIdList[pPlayer->m_EntityId.llid] = pPlayer;
	pPlayer->m_nPlayerIndex = putPlayerToIndex(pPlayer);
	pPlayer->retain();
}

void CPlayerList::removePlayer(CPlayer *pPlayer)
{
	PlayerList::iterator vit = std::find(m_PlayerList.begin(), m_PlayerList.end(), pPlayer);
	if (vit != m_PlayerList.end())
		m_PlayerList.erase(vit);

	PlayerNameList::iterator nit = m_PlayerNameList.find(std::string(pPlayer->m_sName));
	if (nit != m_PlayerNameList.end())
		m_PlayerNameList.erase(nit);

	PlayerIdList::iterator iit = m_PlayerIdList.find(pPlayer->m_EntityId.llid);
	if (iit != m_PlayerIdList.end())
		m_PlayerIdList.erase(iit);

	if (pPlayer->m_nPlayerIndex > -1 && pPlayer->m_nPlayerIndex < m_PlayerIndexList.count())
		m_PlayerIndexList[pPlayer->m_nPlayerIndex] = NULL;

	pPlayer->release();
}

int CPlayerList::putPlayerToIndex(CPlayer *pPlayer)
{
	CPlayer **ppPlayerList = m_PlayerIndexList;

	for (INT_PTR i=m_PlayerIndexList.count()-1; i>-1; --i)
	{
		if (!ppPlayerList[i])
		{
			ppPlayerList[i] = pPlayer;
			return (INT)i;
		}
	}
	return (INT)m_PlayerIndexList.add(pPlayer);
}
