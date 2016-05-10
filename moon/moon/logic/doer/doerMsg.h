#ifndef DOER_MSG_H__
#define DOER_MSG_H__

struct DoerMsg
{
	int ident;
	int sysId;
	INT_PTR param1;
	INT_PTR param2;
	INT_PTR param3;
	INT_PTR param4;
	DoerMsg* next;
};

#define PM_SECNECHANGED					10000 //角色场景改变
#define PM_ACTOR_APPEAR					10001 //角色出现
#define PM_ACTOR_DISAPPEAR				10002 //角色消失
#define PM_REF_NPC_QUEST_STATE			10003 //刷新任务状态
#define PM_SELF_DIE						10005 //角色自己死亡
#define PM_LEVEL_CHANGE					10006 //角色等级改变
#define PM_ACTOR_DESC_CHANGE			10007 //角色描述改变


#endif
