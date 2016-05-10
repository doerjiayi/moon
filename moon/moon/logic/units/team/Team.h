#ifndef _TEAM_H_
#define _TEAM_H_

using namespace lib::container;
//队伍

class CTeam
{
	static const int sMaxSize = 3;			//队伍最大人数
	friend class CTeamManager;
public:
	CTeam();
	~CTeam();	

	//初始化:默认由创建的玩家做队长
	void create( CPlayer* pPlayer);
	//加入队伍
	bool joinTeam(CPlayer* pPlayer);
	//踢出队伍
	bool kickPlayer( CPlayer* pLeader, CPlayer* pTarget);
	//退出队伍
	bool quitTeam(CPlayer* pPlayer);

	//获取队伍人数
	inline int getTeamCount(){return int(m_playerList.count());}
private:
	CBList<CPlayer*>		m_playerList;	//该队伍玩家列表
	CPlayer*				m_pTeamLeader;	//队长
};


#endif
