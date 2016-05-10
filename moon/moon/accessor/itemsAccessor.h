#ifndef __ITEMS_ACCESSOR_H__
#define __ITEMS_ACCESSOR_H__

/*
 *读取物品表接口，其中场景表和使用条件等相关连的配置表，最终读取时，赋值给CStdItem
 * */
class ItemAccessor : public Object
{
public:		
	ItemAccessor();
	~ItemAccessor();

	//读取物品基础信息配置表
	bool loadConfig();

	//获取一个物品的配置
	const CFItem* getItem(uint32 itemId) const;
	//获取一个物品配置（by name）
	const CFItem* getItemByName(const char* sName) const;

private:
	////读取物品增加的基本属性
	//void readAttrBase(CSVDocument &doc);
	////读取物品的品质属性
	//void readQualityAttr(CSVDocument &doc);
	////读取物品的强化属性
	//void readStrongAttr(CSVDocument &doc);
	////读取使用条件
	//void readUseCondition(CSVDocument &doc);
	////读取物品能存在的场景
	//void readExitScene(CSVDocument &doc);
	////读取物品主配置
	//void readStdItem(CSVDocument &doc);
	////读取一个AttributeGrop
	//void readAttributeGrop(CSVDocument &doc, ItemAttributeGroup &attrs, int gropGount, int langBeginIndex, int langEdnIndex);
	////读取一个UseCondition
	//void readCondition(CSVDocument &doc, ItemUseCondTable &condi, int gropGount, int langBeginIndex, int langEdnIndex);

	//查找是否存在该场景id
	bool findOrInsertItemId(int itemId, int sceneId);
	//
private:
	lib::container::Array<ItemUseCondTable*> m_UseCondition;	//临时存放所有物品使用条件表
	lib::container::Array<ExistScenes*> m_ExistScenes; //能存在场景表数据
	lib::container::Array<CFItem*> m_ItemList;  //物品配置数据

	CConfigAllocator	   m_Allocator;//对象内存分配器
	std::vector<ItemScene> m_SceneIdVec; //场景id缓存
};

#endif /* ITEMCONFIGLOADER_H */
