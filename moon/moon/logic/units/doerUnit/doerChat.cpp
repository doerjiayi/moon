#include "StdAfx.h"
using namespace common::SystemId;
int CPlayerChat::m_maxLen = 512;

bool CPlayerChat::init()
{
	m_tick = 0;
	return true;	
}

bool CPlayerChat::loadData(CDataPacketReader &data)
{
	return true;
}

void CPlayerChat::saveData(CDataPacket& data)
{

}

void CPlayerChat::offline()
{

}

void CPlayerChat::dispatchRecvPacket(int btCmd, CDataPacketReader &inPacket)
{
	TickTime tick = m_tick;
	m_tick = _getTickCount();
	if(m_tick - tick < 500)
	{
		logWarn( "发言的时间过短!");
		return;
	}

	unsigned char chanetCmd = 0;
	inPacket >> chanetCmd;
	//第一个字符为@表示执行命令
	if (*((char*)(inPacket.getOffsetPtr() + 2)) == '@')
	{
		const char *msg;
		inPacket >> msg;
		assert(msg != NULL);
		executeCommand(msg + 1);
	}
	else if(eChannelIdenWhish == chanetCmd)
	{
		whisperChat(inPacket);
	}
	else if (eChannelIdenNear == chanetCmd || eChannelIdenSny == chanetCmd)
	{
		broadcastChatToNear(inPacket);
	}
	else if(eChannelIdenSys == chanetCmd)
	{
		sysMsg(inPacket);
	}
	else
	{
		//TODO：这是怎么回事？？？没有任何消息内容的聊天数据包你往服务器发了干嘛？
		assert(TRUE);
	}
}

void CPlayerChat::sysMsg(CDataPacketReader &inPacket)
{
	const char * pData = 0;
	inPacket >> pData;
	if(!pData)
	{
		return;
	}
	CPlayerList& playerList = (CPlayerList&)(g_LogicEngine->getPlayerList());
	for(int i = playerList.getPlayerCount() - 1; i >= 0 ; --i)
	{
		CPlayer *pPlayer = playerList.getPlayerAtIndex(i);
		if(!pPlayer)
		{
			continue;
		}
		CGateSendPacket &pack = pPlayer->allocSendPacket();
		pack.writeCmd(sysChat, 0);
		pack << (unsigned char)(eChannelIdenSys);
		pack << pData;
		pack.flush();
	}
}

void CPlayerChat::broadcastChatToNear(CDataPacketReader &inPacket)
{
	const char *pData = 0;
	inPacket >> pData;
	if(!pData)
	{
		return;
	}
	
	CBList<CEntity::ViewStruct> & viewPlayers =m_pActor->m_ViewList;
	CEntity::ViewStruct *pViewS = viewPlayers;
	CPlayer *pPlayer = 0;
	for(int i = (int)viewPlayers.count() - 1; i >= 0; --i )
	{
		if(ePlayer != pViewS[i].pEntity->m_btType)
		{
			continue;
		}
		pPlayer = (CPlayer*)(pViewS[i].pEntity);
		CGateSendPacket &pack = pPlayer->allocSendPacket();
		pack.writeCmd(sysChat, 0);
		pack << (unsigned char)(eChannelIdenNear);
		///广播的玩家名字
		pack << (const char*)(m_pActor->m_sName);
		///广播内容
		pack << pData;
		pack.flush();
	}
}

void CPlayerChat::whisperChat(CDataPacketReader &inPacket)
{
	///读取接受消息的玩家姓名
	const char *pContent = 0;
	inPacket >> pContent;
	const char *pRecvName = 0;
	inPacket >> pRecvName;
	
	if(!pRecvName || !pContent)
	{
		return;
	}
	CPlayerList &playerList = (CPlayerList&)(g_LogicEngine->getPlayerList());
	std::string strName = pRecvName;
	CPlayer * pPlayer = playerList.getPlayerByName(strName);
	if(pPlayer)
	{
		CGateSendPacket &pack = pPlayer->allocSendPacket();
		pack.writeCmd(sysChat, 0);
		pack << (unsigned char)(eChannelIdenWhish);
		///序列化发送者的名字
		pack << pContent;
		pack << m_pActor->m_sName;
		pack.flush();
	}
}

void CPlayerChat::executeCommand(const char* msg)
{
	uint32 nParamCount = 0;
	char buffer[256];
	char* sCmd = NULL, *sParam[8], *str;

	//解析命令与参数
	_asncpytA(buffer, msg);
	str = buffer;
	while (nParamCount < ARRAY_LEN(sParam))
	{
		char* ptr = strchr(str, ' ');
		if (ptr) *ptr = 0;
		if (sCmd)
		{
			sParam[nParamCount] = str;
			nParamCount++;
		}
		else sCmd = str;
		if (!ptr)
			break;
		str = ptr + 1;
	}

	//处理命令
	g_GameCommander->dispatchCmd(m_pPlayer, sCmd, &sParam[0], nParamCount);
}
