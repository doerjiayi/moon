#include "StdAfx.h"
#include "questManager.h"


QuestAccessor::QuestAccessor()
{
}

QuestAccessor::~QuestAccessor()
{
	for (int i = 0; i < m_questTalkList.count(); ++i)
	{
		m_questTalkList.get(i).~TalkStruct();
	}	
}

bool QuestAccessor::loadConfig()
{
#if 0
	CSVDocument doc;

#define LOAD_DOC(name, fn)	{\
	if (!CConfigManager::LoadCSVDocument(doc, "./config/quest/"name".csv"))\
	return false;\
	fn(doc);	}

	LOAD_DOC("Quest", readQuests);
	LOAD_DOC("Quest_Target", readQuestTargetConfig);			//读取任务步骤表
	LOAD_DOC("Quest_Condition", readQuestConditionConfig);		//读取任务完成条件配置表
	LOAD_DOC("Quest_Award", readAwardlistConfig);				//读取任务奖励表
	LOAD_DOC("Quest_Talk", readTalkConfig);						//读取任务对话
#endif
	return true;
}
#if 0
bool QuestManager::readQuestTargetConfig(CSVDocument& doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE4\xBB\xBB\xE5\x8A\xA1\x49\x44"));//任务ID
	int cTargetType = doc.getColumnIndex(UTF8String("\xE7\x9B\xAE\xE6\xA0\x87\xE7\xB1\xBB\xE5\x9E\x8B"));//目标类型
	int cTargetID = doc.getColumnIndex(UTF8String("\x49\x44"));//ID
	int cTargetNum = doc.getColumnIndex(UTF8String("\xE6\x95\xB0\xE9\x87\x8F"));//数量

	//确定要分配的内存大小
	int maxId = 0;
	const int totalCount = (int)doc.numRows();
	for (int i = 0; i < totalCount; ++i)
	{
		unsigned short questID = doc.getValue(i, cId);
		QuestConfig *pQuest = m_Quest[questID];
		pQuest->Target.nCount++;
		//防止任务配置目标个数超出范围
		assert(pQuest->Target.nCount <= 4);
	}
	//分配内存
	size_t nCount = m_Quest.length();
	QuestConfig **ppQList = m_Quest.own_ptr();
	for (int i = 0; i < nCount; ++i)
	{
		if (NULL == ppQList[i]) continue;
		ppQList[i]->Target.pTargetList = m_Allocator.Alloc<QuestConfig::QUESTTARGET>(ppQList[i]->Target.nCount);
		ppQList[i]->Target.nCount = 0;
	}
	//赋值
	for (int i = 0; i < totalCount; ++i)
	{
		unsigned short questID = doc.getValue(i, cId);
		QuestConfig *pQuest = ppQList[questID];
		if (NULL == pQuest) continue;
		QuestConfig::PQUESTTARGETLIST pTarget = &pQuest->Target;
		pTarget->pTargetList[pTarget->nCount].nType = doc.getValue(i, cTargetType);
		pTarget->pTargetList[pTarget->nCount].nId = doc.getValue(i, cTargetID);
		pTarget->pTargetList[pTarget->nCount].nCount = doc.getValue(i, cTargetNum);
		pTarget->nCount++;
	}
	return true;
}

bool QuestManager::readQuestConditionConfig(CSVDocument& doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE4\xBB\xBB\xE5\x8A\xA1\x49\x44"));//任务ID
	//int cConditId = doc.getColumnIndex(UTF8String("");//条件ID
	int cType = doc.getColumnIndex(UTF8String("\xE7\xB1\xBB\xE5\x9E\x8B"));//类型
	int cTypeId = doc.getColumnIndex(UTF8String("\x49\x44"));//ID
	int cNum = doc.getColumnIndex(UTF8String("\xE6\x95\xB0\xE9\x87\x8F"));//数量

	//确定要分配的内存大小
	int maxId = 0;
	const int totalCount = (int)doc.numRows();
	for (int i = 0; i < totalCount; ++i)
	{
		unsigned short questID = doc.getValue(i, cId);
		QuestConfig *pQuest = m_Quest[questID];
		pQuest->Condition.nCount++;
	}
	//分配内存
	INT_PTR nCount = m_Quest.length();
	QuestConfig **ppQList = m_Quest.own_ptr();
	for (int i = 0; i < nCount; ++i)
	{
		if (NULL == ppQList[i]) continue;
		ppQList[i]->Condition.pConditionList = m_Allocator.Alloc<QuestConfig::CONDITION>(ppQList[i]->Condition.nCount);
		ppQList[i]->Condition.nCount = 0;
	}
	//赋值
	for (int i = 0; i < totalCount; ++i)
	{
		unsigned short questID = doc.getValue(i, cId);
		QuestConfig *pQuest = ppQList[questID];
		pQuest->Condition.pConditionList[pQuest->Condition.nCount].nType = doc.getValue(i, cType);
		pQuest->Condition.pConditionList[pQuest->Condition.nCount].nId = doc.getValue(i, cTypeId);
		pQuest->Condition.pConditionList[pQuest->Condition.nCount].nCount = doc.getValue(i, cNum);
		pQuest->Condition.nCount++;
	}
	return true;
}

bool QuestManager::readAwardlistConfig(CSVDocument& doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE4\xBB\xBB\xE5\x8A\xA1\x49\x44"));//任务ID
	int cAType = doc.getColumnIndex(UTF8String("\xE5\xA5\x96\xE5\x8A\xB1\xE7\xB1\xBB\xE5\x9E\x8B"));//奖励类型
	int cAId = doc.getColumnIndex(UTF8String("\xE5\xA5\x96\xE5\x8A\xB1\x49\x44"));//奖励ID
	int cANum = doc.getColumnIndex(UTF8String("\xE6\x95\xB0\xE9\x87\x8F"));//数量
	//int cACondit = doc.getColumnIndex(UTF8String("\xE6\x9D\xA1\xE4\xBB\xB6"));//条件	职业,男女,等等,未定

	//确定要分配的内存大小
	int maxId = 0;
	const int totalCount = (int)doc.numRows();
	for (int i = 0; i < totalCount; ++i)
	{
		unsigned short questID = doc.getValue(i, cId);
		QuestConfig *pQuest = m_Quest[questID];
		pQuest->AwardList.nCount++;
	}

	INT_PTR nCount = m_Quest.length();
	QuestConfig **ppQList = m_Quest.own_ptr();
	//分配内存
	for (int i = 0; i < nCount; ++i)
	{
		if (NULL == ppQList[i]) continue;
		ppQList[i]->AwardList.pAwardList = m_Allocator.Alloc<QuestConfig::AWARD>(ppQList[i]->AwardList.nCount);
		ppQList[i]->AwardList.nCount = 0;
	}
	//赋值
	for (int i = 0; i < totalCount; ++i)
	{
		unsigned short questID = doc.getValue(i, cId);
		QuestConfig *pQuest = ppQList[questID];
		int n = pQuest->AwardList.nCount;
		QuestConfig::AWARD *pAward = &pQuest->AwardList.pAwardList[n];
		pAward->nType = doc.getValue(i, cAType);
		pAward->nId = doc.getValue(i, cAId);
		pAward->nCount = doc.getValue(i, cANum);
		pQuest->AwardList.nCount++;
		//pAward->
	}
	return true;
}

bool QuestManager::readTalkConfig(CSVDocument& doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE4\xBB\xBB\xE5\x8A\xA1\x49\x44"));//任务ID
	int cType = doc.getColumnIndex(UTF8String("\xE5\xAF\xB9\xE8\xAF\x9D\xE7\xB1\xBB\xE5\x9E\x8B"));//对话类型
	int cTalk = doc.getColumnIndex(UTF8String("\xE5\xAF\xB9\xE8\xAF\x9D\xE5\x86\x85\xE5\xAE\xB9"));//对话内容
	int cReply = doc.getColumnIndex(UTF8String("\xE5\x9B\x9E\xE5\xA4\x8D\xE5\x86\x85\xE5\xAE\xB9"));//回复内容

	int maxId = 0; 
	const int  totalCount = (int)doc.numRows();
	for (int i = 0; i < totalCount; ++i)
	{
		unsigned short questID = doc.getValue(i, cId);
		maxId = max(maxId, questID);
	}
	
	m_questTalkList.reserve(maxId+1);
	ZeroMemory(m_questTalkList, sizeof(TalkStruct)*m_questTalkList.maxCount());

	TalkStruct *pTalkList = m_Allocator.Alloc<TalkStruct>(totalCount);
	for (int i = 0; i < totalCount; ++i)
	{
		unsigned short questID = doc.getValue(i, cId);
		TalkStruct *pTalkStruct = &m_questTalkList[questID];
		m_questTalkList.trunc(questID+1);
		if (1 == int(doc.getValue(i, cType)))
		{
			pTalkStruct->accept.talkList.push_back(doc.getValue(i, cTalk).s.ptr());

			if (0 == doc.getValue(i, cReply).s.ptr())
				pTalkStruct->accept.replyList.push_back("\xE6\x8E\xA5\xE5\x8F\x97\xE4\xBB\xBB\xE5\x8A\xA1");//回复内容为空则默认填"接受任务"
			else
				pTalkStruct->accept.replyList.push_back(doc.getValue(i, cReply).s.ptr());

			pTalkStruct->accept.nCount++;
		}
		if (2 == int(doc.getValue(i, cType)))
		{
			pTalkStruct->complete.talkList.push_back(doc.getValue(i, cTalk).s.ptr());

			if (0 == doc.getValue(i, cReply).s.ptr())
				pTalkStruct->complete.replyList.push_back("\xE6\x8F\x90\xE4\xBA\xA4\xE4\xBB\xBB\xE5\x8A\xA1");//回复内容为空则默认填"提交任务"
			else
				pTalkStruct->complete.replyList.push_back(doc.getValue(i, cReply).s.ptr());

			pTalkStruct->complete.nCount++;
		}
	}
	return true;
}

void QuestManager::readQuests(CSVDocument& doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE4\xBB\xBB\xE5\x8A\xA1\x49\x44"));//任务ID
	int cName = doc.getColumnIndex(UTF8String("\xE5\x90\x8D\xE7\xA7\xB0"));//名称
	int cType = doc.getColumnIndex(UTF8String("\xE7\xB1\xBB\xE5\x9E\x8B"));//类型
	int cLevel = doc.getColumnIndex(UTF8String("\xE6\x8E\xA5\xE4\xBB\xBB\xE5\x8A\xA1\xE7\xAD\x89\xE7\xBA\xA7"));//接任务等级
	int cStart = doc.getColumnIndex(UTF8String("\xE6\x8E\xA5\x4E\x50\x43"));//接NPC
	int cEnd = doc.getColumnIndex(UTF8String("\xE4\xBA\xA4\x4E\x50\x43"));//交NPC
	int cParent = doc.getColumnIndex(UTF8String("\xE7\x88\xB6\xE4\xBB\xBB\xE5\x8A\xA1"));//父任务
	int cCanGiveUp = doc.getColumnIndex(UTF8String("\xE5\x8F\xAF\xE5\x90\xA6\xE6\x94\xBE\xE5\xBC\x83"));//可否放弃
	int cRandomTarget = doc.getColumnIndex(UTF8String("\xE9\x9A\x8F\xE6\x9C\xBA"));//随机
	int cTimeLimit = doc.getColumnIndex(UTF8String("\xE6\x97\xB6\xE9\x97\xB4\xE9\x99\x90\xE5\x88\xB6"));//时间限制
	int cInterval = doc.getColumnIndex(UTF8String("\xE5\x91\xA8\xE6\x9C\x9F"));//周期
	int cMaxCount = doc.getColumnIndex(UTF8String("\xE5\x91\xA8\xE6\x9C\x9F\xE6\xAC\xA1\xE6\x95\xB0"));//周期次数
	int cForbid = doc.getColumnIndex(UTF8String("\xE7\xA6\x81\xE7\x94\xA8"));//禁用
	
	int maxId = 0;
	const int totalCount = (int)doc.numRows();
	QuestConfig* questConfigList = m_Allocator.Alloc<QuestConfig>(totalCount);
	for (int i = 0; i < totalCount; ++i)
	{
		QuestConfig* questConfig = &questConfigList[i];
		questConfig->nQid			= doc.getValue(i, cId);							//任务ID
		questConfig->sName			= m_Allocator.AllocStr(doc.getValue(i, cName));	//名称
		questConfig->nType  		= doc.getValue(i, cType);				//类型
		questConfig->nLevel			= doc.getValue(i, cLevel);				//接任务等级
		questConfig->nStartNpc		= doc.getValue(i, cStart);				//接NPC
		questConfig->nEndNpc		= doc.getValue(i, cEnd);				//交NPC
		questConfig->nParentId		= doc.getValue(i, cParent);				//父任务
		questConfig->boCanGiveUp	= doc.getValue(i, cCanGiveUp).d != 0;			//可否放弃
		//questConfig->boRandomTarget	= doc.getValue(i, cRandomTarget).b;		//随机
		questConfig->nTimeLimit		= doc.getValue(i, cTimeLimit);			//时间
		questConfig->nInterval		= doc.getValue(i, cInterval);			//周期
		questConfig->nMaxCount		= doc.getValue(i, cMaxCount);			//周期次
		questConfig->boForbid		= doc.getValue(i, cForbid).d != 0;		//禁用
		maxId = max(maxId, questConfig->nQid);
	}

	m_Quest.setLength(maxId+1);
	memset(m_Quest.own_ptr(), 0, sizeof(m_Quest.ptr()[0]) * (maxId+1));
	QuestConfig** ppQuestList = m_Quest.own_ptr();
	for (int i = 0; i < totalCount; ++i)
	{
		QuestConfig* quest = &questConfigList[i];
		ppQuestList[quest->nQid] = quest;
	}

	//生成子任务列表,预分配好内存空间
	for (int iParent = 0; iParent <= totalCount; ++iParent)
	{
		QuestConfig* pQParent = ppQuestList[iParent];
		if (NULL == pQParent) continue;
		QuestConfig::PQUESTIDLIST pSubQuest = &pQParent->m_vSubQuest;
		for (int iSon = 0; iSon <= totalCount; ++iSon)
		{
			if (NULL == ppQuestList[iSon]) continue;
			if (pQParent->nQid == ppQuestList[iSon]->nParentId)
				pSubQuest->nCount++;
		}
		pSubQuest->pQuest = m_Allocator.Alloc<QuestConfig*>(pSubQuest->nCount);
		pSubQuest->nCount = 0;
	}
	//生成子任务列表
	for (int i = 0; i <= totalCount; ++i)
	{
		if (NULL == ppQuestList[i]) continue;
		int parentID = ppQuestList[i]->nParentId;
		if (-1 != parentID)
		{
			QuestConfig::PQUESTIDLIST pSubQuest = &ppQuestList[parentID]->m_vSubQuest;
			pSubQuest->pQuest[pSubQuest->nCount] = ppQuestList[i];
			pSubQuest->nCount++;
		}
	}
	//生成无父任务列表
	for (int i = 0; i < totalCount; ++i)
	{
		if (NULL == ppQuestList[i]) continue;
		if (-1 == ppQuestList[i]->nParentId)
		{
			m_questNoParentList.add(i);
		}
	}
}
#endif

const QuestConfig* QuestAccessor::getQuest( unsigned int index )
{
	if (index < m_Quest.length())
		return m_Quest[index];
	else
		return NULL;
}

QuestConfig** QuestAccessor::getQuestList()
{
	return m_Quest.own_ptr();
}

const QuestConfig::QUESTTARGETLIST *QuestAccessor::getQuestTargetList(unsigned short index)
{
	if (index < m_Quest.length())
		return &m_Quest[index]->Target;
	else
		return NULL;
}

//获取任务奖励列表
const QuestConfig::AWARDLIST * QuestAccessor::getQuestAwardList( unsigned short index )
{
	if (index < m_Quest.length())
		return &m_Quest[index]->AwardList;
	else
		return NULL;
}

/*
[questId] = { 
	name = "任务名",
	acceptTalk = { "111", "222", "333" }, 
	acceptReply = {"11", "22", "33"},
	completeTalk = { "aaa", "bbb", "ccc" },
	completeReply = {"aa", "bb", "cc"},
}
*/
void QuestAccessor::pushToQuestData(lua_State* L, QuestConfig *quest)
{
	lua_newtable(L);
	lua_pushvalue(L, -1);
	lua_rawseti(L, -3, quest->nQid);

	//name = "quest-name"
	lua_pushstring(L, quest->sName);
	lua_setfield(L, -2, "name");

	const QuestAccessor::TalkStruct* pTalkStruct =  &(m_questTalkList.get(quest->nQid));
	if (NULL != pTalkStruct)
	{
		if (pTalkStruct->accept.nCount > 0)
		{
			lua_newtable(L);
			lua_pushvalue(L, -1);
			lua_setfield(L, -3, "acceptTalk");
			for (int i = 0; i < pTalkStruct->accept.nCount; ++i)
			{
				lua_pushstring(L, pTalkStruct->accept.talkList[i].c_str());
				lua_rawseti(L, -2, i + 1);
			}
			lua_pop(L, 1);

			lua_newtable(L);
			lua_pushvalue(L, -1);
			lua_setfield(L, -3, "acceptReply");
			for (int i = 0; i < pTalkStruct->accept.nCount; ++i)
			{
				lua_pushstring(L, pTalkStruct->accept.replyList[i].c_str());
				lua_rawseti(L, -2, i+1);
			}
			lua_pop(L, 1);
			
		}
		if (pTalkStruct->complete.nCount > 0)
		{
			lua_newtable(L);
			lua_pushvalue(L, -1);
			lua_setfield(L, -3, "completeTalk");
			for (int i = 0; i < pTalkStruct->complete.nCount; ++i)
			{
				lua_pushstring(L, pTalkStruct->complete.talkList[i].c_str());
				lua_rawseti(L, -2, i + 1);
			}
			lua_pop(L, 1);

			lua_newtable(L);
			lua_pushvalue(L, -1);
			lua_setfield(L, -3, "completeReply");
			for (int i = 0; i < pTalkStruct->complete.nCount; ++i)
			{
				lua_pushstring(L, pTalkStruct->complete.replyList[i].c_str());
				lua_rawseti(L, -2, i+1);
			}
			lua_pop(L, 1);
		}
	}
	lua_pop(L, 1);
}

void QuestAccessor::makeScriptQuestData()
{
	QuestConfig** ppQuestList = m_Quest.own_ptr();
	INT_PTR nCount = m_Quest.length();
	lua_State* L = g_Script->getLuaState();
	lua_newtable(L);
	for (INT_PTR i = 1; i < nCount; ++i)
	{
		pushToQuestData(L, ppQuestList[i]);
	}
	lua_setglobal(L, "QuestData");
}

/*
[npcId] = {
	accepts = { 1, 2, 3, },
	completes = { 100, 101, 102, },
},
*/
void QuestAccessor::pushToNPCQuestAccepts(lua_State* L, int NpcId, unsigned short questID)
{
	size_t tLen = 0;
	//打开NPCID为下标的表
	lua_rawgeti(L, -1, NpcId);
	if (!lua_istable(L, -1))
	{
		lua_pop(L, 1);
		lua_newtable(L);
		lua_pushvalue(L, -1);
		lua_rawseti(L, -3, NpcId);
	}

	//向accept表添加可接任务ID
	lua_getfield(L, -1, "accepts");
	if (!lua_istable(L, -1))
	{
		lua_pop(L, 1);
		lua_newtable(L);
		lua_pushvalue(L, -1);
		lua_setfield(L, -3, "accepts");
	}
	tLen = lua_objlen(L, -1);
	lua_pushinteger(L, questID);
	lua_rawseti(L, -2, int(tLen + 1));
	lua_pop(L, 1);

	//关闭NPCID为下标的表
	lua_pop(L, 1);
}

void QuestAccessor::pushToNPCQuestCompletes(lua_State* L, int NpcId, unsigned short questID)
{
	size_t tLen = 0;
	//打开NPCID为下标的表
	lua_rawgeti(L, -1, NpcId);
	if (!lua_istable(L, -1))
	{
		lua_pop(L, 1);
		lua_newtable(L);
		lua_pushvalue(L, -1);
		lua_rawseti(L, -3, NpcId);
	}

	//向completes表添加可接任务ID
	lua_getfield(L, -1, "completes");
	if (!lua_istable(L, -1))
	{
		lua_pop(L, 1);
		lua_newtable(L);
		lua_pushvalue(L, -1);
		lua_setfield(L, -3, "completes");
	}
	tLen = lua_objlen(L, -1);
	lua_pushinteger(L, questID);
	lua_rawseti(L, -2, int(tLen + 1));
	lua_pop(L, 1);

	//关闭NPCID为下标的表
	lua_pop(L, 1);
}

void QuestAccessor::makeNPCQuestData()
{
	QuestConfig **ppQuestList = m_Quest.own_ptr();
	INT_PTR nCount = m_Quest.length();
	lua_State* L = g_Script->getLuaState();
	lua_newtable(L);
	for (INT_PTR i = 1; i < nCount; ++i)
	{
		if (ppQuestList[i]->nStartNpc != -1)
			pushToNPCQuestAccepts(L, ppQuestList[i]->nStartNpc, ppQuestList[i]->nQid);
	}
	for (INT_PTR i = 1; i < nCount; ++i)
	{
		if (ppQuestList[i]->nEndNpc != -1)
			pushToNPCQuestCompletes(L, ppQuestList[i]->nEndNpc, ppQuestList[i]->nQid);
	}
	
	lua_setglobal(L, "NPCQuest");
}
