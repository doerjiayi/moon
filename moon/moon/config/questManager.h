#ifndef QUEST_MANAGER_H_
#define QUEST_MANAGER_H_

#include <map>
#include <iostream>
#include "../config/questConfig.h"
using namespace std;

class QuestAccessor
{
public:
	QuestAccessor();
	~QuestAccessor();

	//接任务对话结构
	struct AcceptTalk
	{
		int nCount;				//对话数量
		vector<string> talkList;		//对话列表
		vector<string> replyList;		//回复列表
	};
	//交任务对话
	struct CompleteTalk 
	{
		int nCount;				//对话数量
		vector<string> talkList;		//对话列表
		vector<string> replyList;		//回复列表
	};
	struct TalkStruct
	{
		AcceptTalk accept;		
		CompleteTalk complete;
	};

	//加载任务配置文件
	bool loadConfig();
	//获取任务
	const QuestConfig*	getQuest(unsigned int index);
	QuestConfig**		getQuestList();
	//获取任务目标列表
	const QuestConfig::QUESTTARGETLIST *getQuestTargetList(unsigned short index);
	//获取任务奖励列表
	const QuestConfig::AWARDLIST *getQuestAwardList(unsigned short index);
	//获取没有父任务的任务ID列表
	CBList<unsigned short> &getNoParentQuestList(){return m_questNoParentList;}
		
	//创建任务的lua数据
	void makeScriptQuestData();
	//创建任务NPC的lua数据
	void makeNPCQuestData();
private:
#if 0
	//读取任务配置
	void readQuests(CSVDocument& doc);
	//任务步骤表
	bool readQuestTargetConfig(CSVDocument& doc);	
	//读取任务完成条件配置表
	bool readQuestConditionConfig(CSVDocument& doc);
	//读取任务奖励表
	bool readAwardlistConfig(CSVDocument& doc);		
	//读取任务对话表
	bool readTalkConfig(CSVDocument& doc);	
#endif
	//
	void pushToQuestData(lua_State* L, QuestConfig *quest);
	void pushToNPCQuestAccepts(lua_State* L, int NpcId, unsigned short questID);
	void pushToNPCQuestCompletes(lua_State* L, int NpcId, unsigned short questID);
private:
	CBList<TalkStruct>						m_questTalkList;					//任务对话内容列表
	CBList<unsigned short>					m_questNoParentList;				//没有父任务的任务列表
	lib::container::Array<QuestConfig*>		m_Quest;							//任务配置表
	CConfigAllocator						m_Allocator;						//对象内存分配器
};



#endif //_QUEST_MANAGER_H
