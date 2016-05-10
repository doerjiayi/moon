#ifndef __PLAYER_NPC_TALK_H
#define __PLAYER_NPC_TALK_H


/***************************************
* 玩家与NPC交互模块
***************************************/


class CPlayerNpcTalk: public CDoerUnit
{
public:
	CPlayerNpcTalk();
	~CPlayerNpcTalk();

	//初始化
	virtual bool init();
	//加载npc交互数据
	virtual bool loadData(CDataPacketReader &data);
	//保存npc交互数据
	virtual void saveData(CDataPacket& data);
	//收到的消息分派
	virtual void dispatchRecvPacket(int btCmd, CDataPacketReader &inPacket);
	//发送关闭对话框消息
	void sendCloseTalk();

private:
	//与npc对话
	void HandleTalkNpc(CDataPacketReader &inPacket);
	//获取在可视范围内的NPC对象
	CNpc* getVisibleNPC(uint32 npcId);

public:

	int		m_nTalkNpcID;
	char	m_npcName[48];
};

#endif
