#include "StdAfx.h"
#include "doerTeam.h"

CPlayerTeam::CPlayerTeam()
{
	m_pTeam = NULL;
}

CPlayerTeam::~CPlayerTeam()
{

}

bool CPlayerTeam::init()
{
	return true;
}

void CPlayerTeam::dispatchRecvPacket( int btCmd, CDataPacketReader &inPacket )
{
	switch(btCmd)
	{
	case common::NetCmd::cCreatTeam://创建队伍
		handlePlayerCreateTeam(inPacket);
		break;
	case common::NetCmd::cSearchTeam://搜索队伍
		handlePlayerSearchTeam(inPacket);
		break;
	case common::NetCmd::cJoinTem://加入队伍
		handlePlayerJoinTeam(inPacket);
		break;
	case common::NetCmd::cTeamInvite://邀请组队
		handlePlayerTeamInvite(inPacket);
		break;
	case common::NetCmd::cQuitTeam://退出队伍
		handlePlayerQuitTeam(inPacket);
		break;
	case common::NetCmd::cTeamKick://踢出队伍
		handlePlayerTeamKick(inPacket);
		break;
	}
}

//创建队伍
void CPlayerTeam::handlePlayerCreateTeam(CDataPacketReader &inPacket)
{
	int dupId = 0;
	inPacket >> dupId;
	g_LogicEngine->teamManager().createTeam(m_pPlayer);
}

//搜索队伍
void CPlayerTeam::handlePlayerSearchTeam(CDataPacketReader &inPacket)
{
}

//加入队伍
void CPlayerTeam::handlePlayerJoinTeam(CDataPacketReader &inPacket)
{
}

//邀请组队
void CPlayerTeam::handlePlayerTeamInvite(CDataPacketReader &inPacket)
{
}

//退出队伍
void CPlayerTeam::handlePlayerQuitTeam(CDataPacketReader &inPacket)
{
}

//踢出队伍
void CPlayerTeam::handlePlayerTeamKick(CDataPacketReader &inPacket)
{
}
