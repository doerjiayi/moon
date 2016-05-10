#ifndef _PLAYER_QUEST_H_
#define _PLAYER_QUEST_H_


/***************************************
* 玩家任务模块
***************************************/


class CPlayerQuest: public CDoerUnit
{
public:
	enum
	{
		QUEST_MASK_NOT_ALL_DONE		= 0,	//还有子任务未完成
		QUEST_MASK_ALL_DONE			= 1,	//所有子任务已完成
	};
	CPlayerQuest();
	~CPlayerQuest();

	//初始化
	virtual bool init();
	//加载任务数据
	virtual bool loadData(CDataPacketReader &data);
	//保存任务数据
	virtual void saveData(CDataPacket& data);
	//收到的消息分派
	virtual void dispatchRecvPacket(int btCmd, CDataPacketReader &inPacket);

	//发送任务列表到客户端
	void sendQuestDatas();
	//发送添加已接任务
	void sendAddAcceptQuest(PlayerQuestData* pQuestData);
	//发送添加可接任务
	void sendAddCanAcceptQuest(unsigned short questID);
	//发送更新任务状态
	void sendUpdateAcceptQuest(unsigned short questID, unsigned char idx, unsigned char count);
	//发送删除已接任务
	void sendDelAcceptQuest(unsigned short questID);
	//发送删除可接任务
	void sendDelCanAcceptQuest(unsigned short questID);

	//判断能否接任务
	bool checkCanAccept(unsigned short);
	//判断能否交该任务
	bool checkCanSubmit(unsigned short);
	//接任务
	void acceptQuest(unsigned short);
	//交任务
	void submitQuest(unsigned short);
	//检查某个NPC上的任务状态
	int getNpcQuestState(unsigned long long npcId);
	//更新任务目标进度
	void updateQuestTarget(int questID, int tarIdx, int tarAddCount);

	//通用事件处理
	void questNormalHandler(const int id, int nCount, QuestConfig::ENUM_QUEST_TARGET type);

	//获得道具事件处理
	static void addItem(LogicEvent* event);
	//删除道具事件处理
	static void delItem(LogicEvent* event);
	//死亡事件
	static void actorDie(LogicEvent* event);

	//GM命令:清除所有任务
	void clearAllQuest();
	//GM命令:接受任务
	void addQuest(unsigned short questID);
private:
	//清除已接列表
	void clearAcceptQuests();
	//清除已完成列表
	void clearDoneQuests();
	//清除可接列表
	void clearCanAcceptQuests();

	//放弃任务
	void handlePlayerQuestAbort(CDataPacketReader &inPacket);
	//保存已完成任务
	unsigned short saveDoneQuestData(CDataPacket &data);
	//保存已接任务
	unsigned short saveQuestData(CDataPacket &data);
	//加载已完成任务
	bool loadDoneQuestData(CDataPacketReader &data, unsigned short nDataCount );
	//加载已接任务
	bool loadQuestData(CDataPacketReader &data, unsigned short nDataCount );
	//检查在可接列表中是否重复
	bool checkCanAcceptRepeat(unsigned short questID);
	//获取附加的可接任务列表
	void getAdditionCanAcceptList(CBList<unsigned short> &caqList);
	//查找已接任务
	bool findAcceptQuest(PlayerQuestData **ppPQData, unsigned short questID);
	//交任务的扣物品,奖励物品等处理
	bool submitQuestProcess(unsigned short questID);
public:
	CBList<PlayerQuestData*>	m_AcceptQuestDataList;		//已接任务列表
	CBList<PlayerDoneQuestData*> m_DoneQuestDataList;	//已完成任务列表
	CBList<unsigned short> m_CanAcceptQuestList;			//玩家可接任务列表

};


#endif
