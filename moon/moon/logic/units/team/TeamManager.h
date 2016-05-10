#ifndef _TEAM_MANAGER_H_
#define _TEAM_MANAGER_H_

using namespace lib::container;
//组队管理器
class CTeamManager
{
	struct TeamInfo
	{
		CTeam*			pTeam;			//队伍
		int				duplicateId;	//副本ID
	};
public:
	CTeamManager();
	~CTeamManager();

	//创建队伍
	bool createTeam(CPlayer* pPlayer);
	//加入队伍
	bool joinTeam(CPlayer* pLeader, CPlayer* pPlayerJoin);
	//踢出退伍
	bool kickTeamPlayer(CPlayer* pLeader, CPlayer* pPlayerKick);

	//获取副本等待组队的队伍列表
	void getWaitTeamList(CBList<TeamInfo>& waitList, int dupId);
private:
	CBList<TeamInfo>		m_waitTeamList;		//等待中的队伍列表
	CBList<TeamInfo>		m_fightTeamList;	//开始副本的队伍列表
};



#endif
