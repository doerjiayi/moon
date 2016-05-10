#ifndef __PLAYER_BAG_H__
#define __PLAYER_BAG_H__

/*******************************************
* 玩家背包模块
******************************************/

struct CFItem;

class CPlayerBag :
	public CDoerUnit
{
public:
	typedef CDoerUnit super;
	//角色装备数量
	static const int EquipCount = 16;
	static const int MaxBagSize = 64;
	static const int DefaultBagSize = 16;
public:
	CPlayerBag();
	~CPlayerBag();

	virtual bool init();
	virtual bool loadData(CDataPacketReader &data);
	virtual void saveData(CDataPacket &data);

	//通过物品系列号获取物品
	UserItem* getItem(const common::ItemSeries series, int *pIndex = NULL);
	//通过物品ID获取物品
	UserItem* getItem(const int wItemId, int *pIndex = NULL);
	//获取特定物品数量
	int getItemCount(const int wItemId);
	//添加物品到包裹
	int addItem(const int wItemId, int nCount, int nQuality, int nStrong, int nUseTime, const bool boBind, int nLogID, const char *sGiver);
	//从背包删除物品
	int delItem(const int wItemId, int nCount, int nLogId, const char *sGiver);
	//添加新物品到背包
	void addItem(UserItem *pUserItem, int nLogID, const char *sGiver);
	//删除指定索引的背包物品
	void delItem(const int nItemListIndex, int nLogId, const char *sGiver);
	//判断能否插入当前物品数量
	bool getCanAddItemCount(const int wItemId, int nCount, int nExpireTime, const bool boBind);
	//获取一个可以继续叠加的物品
	UserItem* getCanOverlapItem(const int wItemId, int nExpireTime, const bool boBind);
	//初始化一个新物品
	void initUserItemFromStdItem(UserItem* pUserItem, const CFItem *pStdItem, int nCount, int nQuality, int nStrong, int nExpireTime, bool boBind);
	//向客户端发送背包物品列表
	void sendBagItems();

private:
	void ClearItems();
	void SendAddItem(UserItem *pUserItem);
	void SendDelItem(UserItem *pUserItem);
	void SendItemCountChange(UserItem *pUserItem);
	void SendUpdateItem(UserItem *pUserItem);

public:
	CBList<UserItem*> m_ItemList;
	unsigned char m_btBagCurSize;//背包当前大小
	char ______reserve[3];
};


#endif
