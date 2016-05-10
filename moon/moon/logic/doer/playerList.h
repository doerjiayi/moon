#ifndef __PLAYER_LIST__H__
#define __PLAYER_LIST__H__
#include <string>
#include <vector>
#include <map>

class CPlayerList
{
public:
	typedef std::vector<CPlayer*>			PlayerList;
	typedef std::map<std::string, CPlayer*> PlayerNameList;
	typedef std::map<unsigned long long, CPlayer*>	PlayerIdList;

public:
	//添加玩家对象
	void addPlayer(CPlayer *pPlayer);
	//删除玩家对象
	void removePlayer(CPlayer *pPlayer);
	//获取玩家数量
	inline int getPlayerCount()
	{
		return (int)m_PlayerList.size();
	}
	//按索引获取玩家对象
	inline CPlayer* getPlayerAtIndex(const int nIndex)
	{
		return m_PlayerList[nIndex];
	}
	//按玩家名称获取玩家对象
	inline CPlayer* getPlayerByName(const std::string &strName)
	{
		PlayerNameList::iterator it = m_PlayerNameList.find(strName);
		return it != m_PlayerNameList.end() ? it->second : NULL;
	}
	//按玩家ID获取玩家对象
	inline CPlayer* getPlayerById(const PlayerId PlayerId)
	{
		PlayerIdList::iterator it = m_PlayerIdList.find(PlayerId.llid);
		return it != m_PlayerIdList.end() ? it->second : NULL;
	}
	//按玩家快速索引获取玩家对象
	inline CPlayer* getPlayerByPlayerIndex(int nPlayerIndex)
	{
		assert(nPlayerIndex >= 0 && nPlayerIndex < m_PlayerIndexList.count());
		return m_PlayerIndexList[nPlayerIndex];
	}

private:
	//将玩家加入到快速索引列表中
	int putPlayerToIndex(CPlayer *pPlayer);
	
private:
	PlayerList			m_PlayerList;//玩家对象列表
	PlayerNameList		m_PlayerNameList;//以玩家名称为索引的玩家对象列表
	PlayerIdList		m_PlayerIdList;//以玩家ID为索引的玩家对象列表
	CBList<CPlayer*>	m_PlayerIndexList;//玩家快速索引列表
};

#endif
