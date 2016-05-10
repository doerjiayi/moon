#ifndef _PLAYER_TEAM_H
#define _PLAYER_TEAM_H

/************************************************************************/
/* 玩家组队模块                                                         */
/************************************************************************/

class CTeam;

class CPlayerTeam 
	:public CDoerUnit
{
public:
	CPlayerTeam();
	~CPlayerTeam();

	//初始化
	virtual bool init();
	//收到的消息分派
	virtual void dispatchRecvPacket(int btCmd, CDataPacketReader &inPacket);

private:
	//创建队伍
	void handlePlayerCreateTeam(CDataPacketReader &inPacket);
	//搜索队伍
	void handlePlayerSearchTeam(CDataPacketReader &inPacket);
	//加入队伍
	void handlePlayerJoinTeam(CDataPacketReader &inPacket);
	//邀请组队
	void handlePlayerTeamInvite(CDataPacketReader &inPacket);
	//退出队伍
	void handlePlayerQuitTeam(CDataPacketReader &inPacket);
	//踢出队伍
	void handlePlayerTeamKick(CDataPacketReader &inPacket);

public:
	CTeam*		m_pTeam;
};


#endif
