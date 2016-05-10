#pragma once

class CNpc;
#include <list>
#include <vector>

static const int QUESTBTYE = 1000;//这个尽量不要修改，如果修改的话，对应的数据服务器部分也要修改
static const int MAXQUESTBYTE = 8 * QUESTBTYE;

#pragma pack (push, 1)
class QuestConfig
{
public:
	QuestConfig()
	{
		m_vSubQuest.nCount = 0;
		m_vSubQuest.pQuest = NULL;
	}
public:
	//typedef struct tagNpc
	//{
	//	int nType;	//任务的接受和提交类型，0表示从NPC上接任务；1表示满足接受条件时自动接受；2表示由脚本系统动态发布 
	//	int nSceneId;
	//	int nPosX;
	//	int nPosY;
	//	char sSceneName[128];
	//	char sNpcName[128];
	//};


	enum ENUM_QUEST_TARGET
	{
 		EQUEST_TARGET_TALK			=	0,//对话
 		EQUEST_TARGET_KILL			=	1,//杀怪
 		EQUEST_TARGET_USE_ITEM		=	2,//使用道具
 		EQUEST_TARGET_GET_ITEM		=	3,//收集道具
 		EQUEST_TARGET_ENTER_SCENE	=	4,//进入地图
 		EQUEST_TARGET_JIGUAN		=	5,//触发机关
 		EQUEST_TARGET_CAIJI			=	6,//采集(捕捉)
 		EQUEST_TARGET_HUSONG		=	7,//护送
 		EQUEST_TARGET_FUBEN			=	8,//副本通关
	};

 	enum ENUM_QUEST_AWARD
 	{
		EQUEST_AWARD_EXP		=	0,//经验
		EQUEST_AWARD_ITEM		=	1,//道具
		EQUEST_AWARD_ATTRIB		=	2,//属性
		EQUEST_AWARD_SKILL		=	3,//技能
		EQUEST_AWARD_BUFF		=	4,//BUFF
		EQUEST_AWARD_CHENGHAO	=	5,//称号
		EQUEST_AWARD_MONEY		=	6,//金币
 	};

	//任务目标
	typedef struct tagQuestTarget
	{
		int			nType;	//类型
		int			nId;
		int			nCount;
		int			nRewardIdx;		//关联任务奖励索引
		//char*		sData;//自定义类型
	}QUESTTARGET,*PQUESTTARGET;

	//任务完成列表
	typedef struct tagQuestTargetList
	{
		int nCount;
		QUESTTARGET* pTargetList;
	}QUESTTARGETLIST,*PQUESTTARGETLIST;

	//奖励配置表
	typedef struct	tagAward
	{
		int nType;
		int nId;
		int nCount;		
		bool boBind;
		unsigned char job;	//等于0表示不限制
		char sex;//小于0表示不限制		
		unsigned char nGroup;	//
		//char*	sDesc;		//这个是自定义奖励才有
		unsigned char nStrong;
		unsigned char nQuality;
		float fLevelRate;
		float fRingRate;
		/* Comments:判断职业是否符合这个奖励的规定*/
		bool isJob(unsigned char myjob) const
		{
			if (job == 0) return true;//不限制职业
			else return myjob == job;
		}
		/*Comments:判断性别是否符合这个奖励的规定*/
		bool isSex(int mysex) const
		{
			if (sex < 0) return true;//不限制性别
			else return mysex == sex;
		}
	}AWARD,*PAWARD;

	//奖励物品列表
	typedef struct tagAwardList
	{
		int nCount;
		int nSelCount;//	可选的数量
		AWARD*	pAwardList;
	}AWARDLIST,*PAWARDLIST;

	//任务所需条件
	typedef struct	tagCondition
	{
		int nType;
		int nId;
		int	nCount;
	}CONDITION,*PCONDITION;

	// 任务条件列表
	typedef struct tagConditionList
	{
		int nCount;
		CONDITION*	pConditionList;
	}CONDITIONLIST,*PCONDITIONLIST;

	//typedef struct tagQuestDetail
	//{
	//	unsigned short nQid;
	//	QuestConfig*	pQuestConfig;
	//}QuestDetail;

	//任务ID列表
	typedef struct tagQuestIDList
	{
		int nCount;
		QuestConfig**	pQuest;	//子任务id
	}QUESTIDLIST,*PQUESTIDLIST;

public:
	unsigned short			nQid;					//任务Id
	const char				*sName;				//任务名称
	int						nParentId;				//父任务ID，如果值为-1则表示没有父任务，否则必须在做完父任务后才能接此任务 
	int						nType;					//0是主线任务，1是支线任务，2是环线任务，等等
	int						nLevel;					//达到一定等级才让接任务
	//unsigned short			nEntrust;				//委托
	//unsigned char			bStar;					//刷星最高等级
	bool					boCanGiveUp;			//可否放弃
	char					sContent[500];			//任务描述
	int						nStartNpc;				//接任务的npc
	int						nEndNpc;				//结束（完成任务）npc
	bool					boRandomTarget;			//随机目标
	//tagNpc					StartNpc;				//起始NPC
	//tagNpc					EndNpc;					//结束NPC
	QUESTTARGETLIST			Target;					//当前任务需要完成的步骤列表
	AWARDLIST				AwardList;					//奖励列表
	CONDITIONLIST			Condition;				//任务条件列表

	int nTimeLimit;								//任务时间限制，单位是秒钟，从接任务后开始计时，必须在时间归零前完成任务，否则任务自动注销，0表示不限制时间； 
	int nInterval;								//任务周期，单位是秒。0表示不限制。任务周期表示从当天0点开始，进行任务后的多长时间后才能再次接任务。
	int nMaxCount;								//每个任务周期内，可以做多少次，0表示不限制； 
	bool boExcludeTree;							//如果接了此任务的子任务，则不能再接此任务； 
	bool boForbid;								//禁用此任务
	QUESTIDLIST	m_vSubQuest;					//保存这个任务的子任务列表，如果有的话
	//bool boAutoMount;							//是否接任务后自动上坐骑
	CNpc*	pEndNpc;							//完成任务需要交接的NPC，主要用于放弃任务时候，需要执行这个npc的脚本
public:
	inline bool IsRootQuest() {return (this->nParentId <= 0);}
	inline bool IsMainQuest() {return nQid < MAXQUESTBYTE;}
	//这个判断 不是主任务（只能做一次），且又nInterval设置了0的，这种也是只能做一次的
	inline bool IsInterval() { return !IsMainQuest() && nInterval == 0;}
};
#pragma pack(pop)
