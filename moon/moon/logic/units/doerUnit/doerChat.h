#pragma once

///和客户端的对应
enum ChannelType
{
	eNonChannelIden		=		0,
	eChannelIdenWhish	=		'/',//私聊
	eChannelIdenNear	=		eChannelIdenWhish + 1,
	eChannelIdenSys		=		eChannelIdenNear + 1,
	eChannelIdenSny		=		eChannelIdenSys + 1
};


class CPlayerChat : public CDoerUnit
{
public:
	//初始化模块
	virtual bool init();
	//读取模块数据
	virtual bool loadData(CDataPacketReader &data);
	//保存模块数据
	virtual void saveData(CDataPacket& data);
	//分派网络消息
	virtual void dispatchRecvPacket(int btCmd, CDataPacketReader &inPacket);
	//玩家离线
	virtual void offline();
private:
	void sysMsg(CDataPacketReader &inPacket);
	void broadcastChatToNear(CDataPacketReader &inPacket);
	void whisperChat(CDataPacketReader &inPacket);
	void executeCommand(const char* msg);

private:
	static int m_maxLen; //能够处理聊天内容的最大长度
	TickTime m_tick;//发言时间间隔
};
