#ifndef __GLOBAL_OBJ_ALLOC_H__
#define __GLOBAL_OBJ_ALLOC_H__


class CGlobalLogicObjAlloc
{
public:
	static bool init();
	static void destory();

	//道具
	static UserItem* allocUserItem();
	static void freeUserItem(UserItem* pUserItem);

	//角色消息
	static DoerMsg* allocDoerMsg();
	static void freeDoerMsg(DoerMsg *msg);

	//已接任务
	static PlayerQuestData* allocPlayerQuestData();
	static void freePlayerQuestData(PlayerQuestData* pQuestData);

	//已完成任务
	static PlayerDoneQuestData* allocPlayerDoneQuestData();
	static void freePlayerDoneQuestData(PlayerDoneQuestData* pQDData);

	//武器灵珠
	static Bead* allocWeaponBead();
	static void freeWeaponBead(Bead* pBead);

	static DropItemData* allocDropItem();
	static void freeDropItem(DropItemData *dropItemdata);

	static CTeam* allocTeam();
	static void freeTeam(CTeam* pTeam);
};


#endif
