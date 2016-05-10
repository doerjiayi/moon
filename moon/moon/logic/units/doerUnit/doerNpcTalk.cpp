#include "StdAfx.h"
#include "doerNpcTalk.h"

CPlayerNpcTalk::CPlayerNpcTalk()
{
	m_nTalkNpcID = 0;
}

CPlayerNpcTalk::~CPlayerNpcTalk()
{

}

bool CPlayerNpcTalk::init()
{
	return true;
}

void CPlayerNpcTalk::saveData( CDataPacket& data )
{

}

bool CPlayerNpcTalk::loadData( CDataPacketReader &data )
{
	return true;
}

void CPlayerNpcTalk::dispatchRecvPacket( int btCmd, CDataPacketReader &inPacket )
{
	if (btCmd == cTalkNPC)
	{
		HandleTalkNpc(inPacket);
	}
}

void CPlayerNpcTalk::HandleTalkNpc( CDataPacketReader &inPacket )
{
	if (!m_pPlayer)
	{
		logError("%s%s", __FUNCTION__, "only player can operate\n");
		return;
	}

	int npcId;
	char sTalkBuf[512];
	sTalkBuf[sizeof(sTalkBuf)-1] = 0;
	inPacket >> npcId;
	inPacket.readString(sTalkBuf, sizeof(sTalkBuf) - 1);

	CNpc *npc = getVisibleNPC(npcId);
	if (!npc)
	{
		logError( "Player talk npc with not visible (%d)", npcId);
		return;
	}
	
	ScriptValueList args;
	ScriptValueList results;
	args.clear();
	results.clear();

	args.push(npcId);
	args.push(m_pPlayer);

	if (!sTalkBuf[0])
	{
		m_nTalkNpcID = npcId;
		strcpy(m_npcName, npc->m_sName);
		bool success = g_Script->exec("clickNPC",&args, &results );
		if (!success)
		{
			logError("exec clickNPC (%d) error\n",npcId);
			return;
		}
	}
	else
	{
		if (m_nTalkNpcID != npcId)
		{
			logError( "Player talk npc id validate fail (%d & %d)", npcId, m_nTalkNpcID);
			return;
		}
		//func,1,2,3
		//func|1|2|3 (| = 0)
		char* str = sTalkBuf, *next;
		while (*str)
		{
			next = strchr(str, ',');
			if (next)
			{
				*next = 0;
				args.push(str);
				str = next + 1;
			}
			else 
			{
				args.push(str);
				break;
			}
		}

		bool success = g_Script->exec("talkNPC",&args, &results );
		if (!success)
		{
			logError("exec talkNPC (%d) error\n",m_nTalkNpcID);
			return;
		}
	}

	if (results.count > 0)
	{
		CGateSendPacket &packet = m_pPlayer->allocSendPacket();
		packet.writeCmd(common::SystemId::sysTalkNpc, NetCmd::sNPCTalkContent);
		packet << (int)m_nTalkNpcID;
		packet << npc->m_sName;
		int i;
		for (i = 0 ;i < results.count;i++)
		{
			switch(results.values[i].type)
			{
				case ScriptValue::vNumber:packet << results.values[i].data.d;break;
				case ScriptValue::vInterger:
				case ScriptValue::vBool:packet << results.values[i].data.i;break;
				case ScriptValue::vString:packet << results.values[i].data.str;break;
				case ScriptValue::vPointer:packet << results.values[i].data.ptr;break;
				default:;
			}
		}
		packet.flush();
	}
}

CNpc* CPlayerNpcTalk::getVisibleNPC(uint32 npcId)
{
	CDoer::ViewStruct *viewList = m_pActor->m_ViewList;
	for (INT_PTR i=m_pActor->m_ViewList.count()-1; i>-1; --i)
	{
		CEntity *entity = viewList[i].pEntity;
		if (entity->m_btType == eNPC && entity->m_EntityId.llid == npcId)
			return (CNpc*)entity;
	}
	return NULL;
}

//发送关闭对话框消息
void CPlayerNpcTalk::sendCloseTalk()
{
	CGateSendPacket &packet = m_pPlayer->allocSendPacket();
	packet.writeCmd(common::SystemId::sysTalkNpc, NetCmd::sNPCTalkClose);
	packet.flush();
}



