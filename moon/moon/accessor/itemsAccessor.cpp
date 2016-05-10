#include "StdAfx.h"
#ifdef WINDOWS
#pragma warning(disable:4267)
#endif

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

ItemAccessor::ItemAccessor()
{

}

ItemAccessor::~ItemAccessor()
{

}

bool ItemAccessor::loadConfig()
{
	/*CSVDocument doc;

	#define DCL(name, fn) {\
	if (!CConfigManager::LoadCSVDocument(doc, "./config/"name))\
	return false;\
	fn(doc); }

	DCL("stdItem/useCondition.csv", readUseCondition);
	DCL("stdItem/existScenes.csv", readExitScene);
	DCL("stdItem/stdItem.csv", readStdItem);
	DCL("stdItem/staticAttribute.csv", readAttrBase);
	DCL("stdItem/qualityAttribute.csv", readQualityAttr);
	DCL("stdItem/strongAttribute.csv", readStrongAttr);
	*/
	return true;
}
////
////void ItemAccessor::readStdItem(CSVDocument &doc)
////{
////	int cId = doc.getColumnIndex(UTF8String("\xE7\x89\xA9\xE5\x93\x81ID"));
////	int cName = doc.getColumnIndex(UTF8String("\xE7\x89\xA9\xE5\x93\x81\xE5\x90\x8D\xE7\xA7\xB0"));
////	int cIcon = doc.getColumnIndex(UTF8String("\xE7\x89\xA9\xE5\x93\x81\xE5\x9B\xBE\xE5\xBD\xA2\xE7\xBC\x96\xE5\x8F\xB7"));
////	int cShape = doc.getColumnIndex(UTF8String("\xE7\x89\xA9\xE5\x93\x81\xE5\xA4\x96\xE5\xBD\xA2\xE7\xBC\x96\xE5\x8F\xB7"));
////	int cType = doc.getColumnIndex(UTF8String("\xE7\x89\xA9\xE5\x93\x81\xE7\xB1\xBB\xE5\x9E\x8B"));
////	int cDupCount = doc.getColumnIndex(UTF8String("\xE5\x85\x81\xE8\xAE\xB8\xE5\x8F\xA0\xE5\x8A\xA0\xE4\xB8\x8A\xE9\x99\x90"));
////	int cColGroup = doc.getColumnIndex(UTF8String("\xE7\x89\xA9\xE5\x93\x81\xE5\x86\xB7\xE5\x8D\xB4\xE7\xBB\x84"));
////	int cDealType = doc.getColumnIndex(UTF8String("\xE9\x87\x91\xE9\x92\xB1\xE7\xB1\xBB\xE5\x9E\x8B"));
////	int cPrice = doc.getColumnIndex(UTF8String("\xE8\xB4\xAD\xE4\xB9\xB0\xE4\xBB\xB7\xE6\xA0\xBC"));
////	int cDura = doc.getColumnIndex(UTF8String("\xE8\x80\x90\xE4\xB9\x85\xE5\xBA\xA6"));
////	int cSmithId = doc.getColumnIndex(UTF8String("\xE7\xB2\xBE\xE9\x94\xBBID"));
////	int cSuitID = doc.getColumnIndex(UTF8String("\xE5\xA5\x97\xE8\xA3\x85ID"));
////	int cValidFbId = doc.getColumnIndex(UTF8String("\xE6\x9C\x89\xE6\x95\x88\xE5\x89\xAF\xE6\x9C\xACID"));
////	int cValidSceneId = doc.getColumnIndex(UTF8String("\xE6\x9C\x89\xE6\x95\x88\xE5\x9C\xBA\xE6\x99\xAFID"));
////	int cBreakId = doc.getColumnIndex(UTF8String("\xE7\x89\xA9\xE5\x93\x81\xE5\x88\x86\xE8\xA7\xA3ID"));
////	int cQuality = doc.getColumnIndex(UTF8String("\xE7\x89\xA9\xE5\x93\x81\xE5\x93\x81\xE8\xB4\xA8"));
////
////	int maxId = 0;
////	const int totalCount = doc.numRows();
////	ItemStruct *itemList = m_Allocator.Alloc<ItemStruct>(totalCount);
////	for (int i=0; i<totalCount; ++i)
////	{
////		ItemStruct *tmpItem = &itemList[i];
////
////		tmpItem->m_nItemId = doc.getValue(i, cId);
////		tmpItem->sName = m_Allocator.AllocStr(doc.getValue(i,cName));
////		tmpItem->m_wIcon = doc.getValue(i, cIcon);
////		tmpItem->m_wShape = doc.getValue(i, cShape);
////		tmpItem->m_btType = doc.getValue(i, cType);
////		tmpItem->m_btDupCount = doc.getValue(i, cDupCount);
////		tmpItem->m_btColGroup = doc.getValue(i, cColGroup);
////		tmpItem->m_btDealType = doc.getValue(i, cDealType);
////		tmpItem->m_nPrice = doc.getValue(i, cPrice);
////		tmpItem->m_dwDura = doc.getValue(i, cDura);
////		tmpItem->m_btSmithId = doc.getValue(i, cSmithId);
////		tmpItem->m_wSuitID = doc.getValue(i, cSuitID);
////		tmpItem->m_nValidFbId = doc.getValue(i, cValidFbId);
////		tmpItem->m_nValidSceneId = doc.getValue(i, cValidSceneId);
////		tmpItem->b_btBreakId = doc.getValue(i, cBreakId);
////		tmpItem->b_showQuality = doc.getValue(i, cQuality);
////
////		tmpItem->m_NumQualityAttr = 0;
////		tmpItem->m_NumStrongAttr = 0;
////		
////		//初始化使用条件表
////		if (tmpItem->m_nItemId < m_UseCondition.length())
////		{
////			ItemUseCondTable *condi = m_UseCondition[tmpItem->m_nItemId];
////			tmpItem->m_Conditions.nCount = condi->nCount;
////			tmpItem->m_Conditions.itemId = condi->itemId;
////			tmpItem->m_Conditions.condi = condi->condi;
////		}
////		
////		//初始化物品能存在场景表
////		if (tmpItem->m_nItemId < m_ExistScenes.length())
////		{
////			ExistScenes *scenes = m_ExistScenes[tmpItem->m_nItemId];
////			tmpItem->m_ExistScenes.nCount = scenes->nCount;
////			tmpItem->m_ExistScenes.nItemId = scenes->nItemId;
////			tmpItem->m_ExistScenes.pSceneId = scenes->pSceneId;
////		}
////
////		maxId = max(maxId, tmpItem->m_nItemId);
////	}
////
////	m_ItemList.setLength(maxId + 1);
////	memset(m_ItemList.own_ptr(), 0, sizeof(m_ItemList.ptr()[0]) * (maxId + 1));
////	ItemStruct **itemPointerList = m_ItemList.own_ptr();
////	for (int i=0; i<totalCount; ++i)
////	{
////		ItemStruct *item = &itemList[i];
////		itemPointerList[item->m_nItemId] = item;
////	}
////}
////
////void ItemAccessor::readAttributeGrop(CSVDocument &doc, ItemAttributeGroup &attrs, int gropGount, int langBeginIndex, int langEndIndex)
////{
////	static MemoryBlock<Attribute, 128> attrBuffer;
////	attrBuffer.remove(0, attrBuffer.size());
////
////	attrs.count = 0;
////
////	static const UTF8String str1("\xE8\x87\x82\xE5\x8A\x9B");
////	static const UTF8String str2("\xE7\x81\xB5\xE5\xB7\xA7");
////	static const UTF8String str3("\xE4\xBD\x93\xE9\xAD\x84");
////	static const UTF8String str4("\xE5\x86\x85\xE6\x81\xAF");
////	static const UTF8String str5("\xE7\xBD\xA1\xE6\xB0\x94");
////	static const UTF8String str6("\xE5\xA4\x96\xE6\x94\xBB");
////	static const UTF8String str7("\xE5\x86\x85\xE6\x94\xBB");
////	static const UTF8String str8("\xE5\xA4\x96\xE9\x98\xB2");
////	static const UTF8String str9("\xE5\x86\x85\xE9\x98\xB2");
////	static const UTF8String str10("\xE5\xA4\x96\xE9\x98\xB2\xE7\xA9\xBF\xE9\x80\x8F");
////	static const UTF8String str11("\xE5\x86\x85\xE9\x98\xB2\xE7\xA9\xBF\xE9\x80\x8F");
////	static const UTF8String str12("\xE6\xB0\x94\xE8\xA1\x80\xE5\x80\xBC");
////	static const UTF8String str13("\xE5\x86\x85\xE5\x8A\x9B\xE5\x80\xBC");
////	static const UTF8String str14("\xE5\xA4\x96\xE6\x9A\xB4");
////	static const UTF8String str15("\xE5\x86\x85\xE6\x9A\xB4");
////	static const UTF8String str16("\xE5\xA4\x96\xE6\x94\xBB\xE6\x8A\x97\xE6\x9A\xB4");
////	static const UTF8String str17("\xE5\x86\x85\xE6\x94\xBB\xE6\x8A\x97\xE6\x9A\xB4");
////	static const UTF8String str18("\xE5\x91\xBD\xE4\xB8\xAD");
////	static const UTF8String str19("\xE9\x97\xAA\xE9\x81\xBF");
////	static const UTF8String str20("\xE6\x94\xBB\xE5\x87\xBB\xE9\x80\x9F\xE5\xBA\xA6");
////	static const UTF8String str21("\xE7\xA7\xBB\xE5\x8A\xA8\xE9\x80\x9F\xE5\xBA\xA6");
////	static const UTF8String str22("\xE6\xB0\x94\xE8\xA1\x80\xE6\x81\xA2\xE5\xA4\x8D\xE9\x80\x9F\xE5\xBA\xA6");
////	static const UTF8String str23("\xE5\x86\x85\xE5\x8A\x9B\xE6\x81\xA2\xE5\xA4\x8D\xE9\x80\x9F\xE5\xBA\xA6");
////	static const UTF8String str24("\xE7\xA6\x8F\xE7\xBC\x98");
////
////	unsigned int num = langEndIndex - langBeginIndex + 1;
////	StringList strList;
////	strList.add(str1);
////	strList.add(str2);
////	strList.add(str3);
////	strList.add(str4);
////	strList.add(str5);
////	strList.add(str6);
////	strList.add(str7);
////	strList.add(str8);
////	strList.add(str9);
////	strList.add(str10);
////	strList.add(str11);
////	strList.add(str12);
////	strList.add(str13);
////	strList.add(str14);
////	strList.add(str15);
////	strList.add(str16);
////	strList.add(str17);
////	strList.add(str18);
////	strList.add(str19);
////	strList.add(str20);
////	strList.add(str21);
////	strList.add(str22);
////	strList.add(str23);
////	strList.add(str24);
////
////	for (unsigned int j=0; j<num; ++j)
////	{
////		int attr = doc.getColumnIndex(strList[j]);
////		int tmpValue = doc.getValue(gropGount, attr);
////		if (tmpValue != 0)
////		{
////			Attribute *attr = attrBuffer.insert(attrs.count, 1, false);
////			attrs.count++;
////			attr->type = j+1;//AttributeType从1开始
////			attr->value = tmpValue;
////		}
////	}
////
////	attrs.attrs = m_Allocator.Alloc<Attribute>(attrs.count);
////	memcpy(attrs.attrs, attrBuffer.start, sizeof(attrBuffer.start[0]) * attrs.count);
////}
////
////void ItemAccessor::readAttrBase(CSVDocument &doc)
////{
////	int cId = doc.getColumnIndex(UTF8String("\xE7\x89\xA9\xE5\x93\x81ID"));
////	int clevel = doc.getColumnIndex(UTF8String("\xE7\xAD\x89\xE7\xBA\xA7"));
////	const int totalCount = doc.numRows();
////	const int maxItemId = m_ItemList.length() - 1;
////	ItemStruct **itemList = m_ItemList.own_ptr();
////	ItemAttributeGroup *attrGroup = m_Allocator.Alloc<ItemAttributeGroup>(totalCount);
////
////	int levelValue = 0;
////	for (int i=0; i<totalCount; ++i)
////	{
////		ItemAttributeGroup *tmpAttr = &attrGroup[i];
////		tmpAttr->itemId = doc.getValue(i, cId);
////		if (tmpAttr->itemId <= maxItemId && itemList[tmpAttr->itemId])
////		{
////			levelValue = 0;
////			if (clevel>-1)
////			{
////				levelValue = doc.getValue(i, clevel);
////			}
////			tmpAttr->level = levelValue;
////			readAttributeGrop(doc, attrGroup[i], i, 35, 58);
////		}
////		else
////		{
////			tmpAttr->itemId = 0;
////		}
////	}
////
////	//将基本属性加入到物品对象中
////	for (int j=0; j<totalCount; ++j)
////	{
////		ItemAttributeGroup *attr = &attrGroup[j];
////		if (attr->itemId > 0)
////		{
////			ItemStruct *item = itemList[attr->itemId];
////			if (!item->m_StaticAttrs) item->m_StaticAttrs = m_Allocator.Alloc<ItemAttributeGroup*>(1);
////			item->m_StaticAttrs[attr->level] = attr;
////		}
////	}
////}
////
////void ItemAccessor::readQualityAttr(CSVDocument &doc)
////{
////	int cId = doc.getColumnIndex(UTF8String("\xE7\x89\xA9\xE5\x93\x81ID"));
////	int clevel = doc.getColumnIndex(UTF8String("\xE7\xAD\x89\xE7\xBA\xA7"));
////	const int totalCount = doc.numRows();
////	const int maxItemId = m_ItemList.length() - 1;
////	ItemStruct **itemList = m_ItemList.own_ptr();
////	ItemAttributeGroup *attrGroup = m_Allocator.Alloc<ItemAttributeGroup>(totalCount);
////
////	int levelValue = 0;
////	for (int i=0; i<totalCount; ++i)
////	{
////		ItemAttributeGroup *tmpAttr = &attrGroup[i];
////		tmpAttr->itemId = doc.getValue(i, cId);
////		if (tmpAttr->itemId <= maxItemId && itemList[tmpAttr->itemId])
////		{
////			levelValue = 0;
////			if (clevel>-1)
////			{
////				levelValue = doc.getValue(i, clevel);
////			}
////			tmpAttr->level = levelValue;
////			int numLevel = itemList[tmpAttr->itemId]->m_NumQualityAttr;
////			itemList[tmpAttr->itemId]->m_NumQualityAttr = max(numLevel, tmpAttr->level + 1);
////			readAttributeGrop(doc, attrGroup[i], i, 35, 58);
////		}
////		else
////		{
////			tmpAttr->itemId = 0;
////		}
////	}
////
////	//将品质属性加入到物品对象中
////	for (int j=0; j<totalCount; ++j)
////	{
////		ItemAttributeGroup *attr = &attrGroup[j];
////		if (attr->itemId > 0)
////		{
////			ItemStruct *item = itemList[attr->itemId];
////			if (!item->m_QualityAttrs) item->m_QualityAttrs = m_Allocator.Alloc<ItemAttributeGroup*>(item->m_NumQualityAttr);
////			item->m_QualityAttrs[attr->level] = attr;
////		}
////	}
////}
////
////void ItemAccessor::readStrongAttr(CSVDocument &doc)
////{
////	int cId = doc.getColumnIndex(UTF8String("\xE7\x89\xA9\xE5\x93\x81ID"));
////	int clevel = doc.getColumnIndex(UTF8String("\xE7\xAD\x89\xE7\xBA\xA7"));
////	const int totalCount = doc.numRows();
////	const int maxItemId = m_ItemList.length() - 1;
////	ItemStruct **itemList = m_ItemList.own_ptr();
////	ItemAttributeGroup *attrGroup = m_Allocator.Alloc<ItemAttributeGroup>(totalCount);
////
////	int levelValue = 0;
////	for (int i=0; i<totalCount; ++i)
////	{
////		ItemAttributeGroup *tmpAttr = &attrGroup[i];
////		tmpAttr->itemId = doc.getValue(i, cId);
////		if (tmpAttr->itemId <= maxItemId && itemList[tmpAttr->itemId])
////		{
////			levelValue = 0;
////			if (clevel>-1)
////			{
////				levelValue = doc.getValue(i, clevel);
////			}
////			tmpAttr->level = levelValue;
////			int numLevel = itemList[tmpAttr->itemId]->m_NumStrongAttr;
////			itemList[tmpAttr->itemId]->m_NumStrongAttr = max(numLevel, tmpAttr->level + 1);
////			readAttributeGrop(doc, attrGroup[i], i, 35, 58);
////		}
////		else
////		{
////			tmpAttr->itemId = 0;
////		}
////	}
////
////	//将品质属性加入到物品对象中
////	for (int j=0; j<totalCount; ++j)
////	{
////		ItemAttributeGroup *attr = &attrGroup[j];
////		if (attr->itemId > 0)
////		{
////			ItemStruct *item = itemList[attr->itemId];
////			if (!item->m_StrongAttrs) item->m_StrongAttrs = m_Allocator.Alloc<ItemAttributeGroup*>(item->m_NumStrongAttr);
////			item->m_StrongAttrs[attr->level] = attr;
////		}
////	}
////}
////
////void ItemAccessor::readCondition(CSVDocument &doc, ItemUseCondTable &condi, int gropGount, int langBeginIndex, int langEndIndex)
////{
////	static MemoryBlock<ItemUseCondition, 128> memBuffer;
////	memBuffer.remove(0, memBuffer.size());
////
////	int cId = doc.getColumnIndex(UTF8String("\xE7\x89\xA9\xE5\x93\x81ID"));
////	condi.itemId = doc.getValue(gropGount, cId);
////	condi.nCount = 0;
////
////	unsigned int num = langEndIndex - langBeginIndex + 1;
////	StringList strList;
////	static const UTF8String str1("\xE4\xBA\xBA\xE7\x89\xA9\xE7\xAD\x89\xE7\xBA\xA7");
////	static const UTF8String str2("\xE6\x80\xA7\xE5\x88\xAB");
////	static const UTF8String str3("\xE8\x81\x8C\xE4\xB8\x9A");
////	static const UTF8String str4("\xE7\xBB\x93\xE5\xA9\x9A");
////	static const UTF8String str5("\xE9\xAA\x91\xE6\x9C\xAF\xE7\xAD\x89\xE7\xBA\xA7");
////	static const UTF8String str6("\xE9\x98\xB5\xE8\x90\xA5\xE5\xAE\x98\xE8\x81\x8C");
////	static const UTF8String str7("\xE8\xBD\xAC\xE7\x94\x9F\xE6\xAC\xA1\xE6\x95\xB0");
////	strList.add(str1);
////	strList.add(str2);
////	strList.add(str3);
////	strList.add(str4);
////	strList.add(str5);
////	strList.add(str6);
////	strList.add(str7);
////	for (unsigned int j=0; j<num; ++j)
////	{
////		int name = doc.getColumnIndex(strList[j]);
////		int tmpValue = doc.getValue(gropGount, name);
////		if (tmpValue != 0)
////		{
////			ItemUseCondition *tmp = memBuffer.insert(condi.nCount, 1, false);
////			condi.nCount++;
////			tmp->btCond = j+1;
////			tmp->nValue = tmpValue;
////		}
////	}
////	condi.condi = m_Allocator.Alloc<ItemUseCondition>(condi.nCount);
////	memcpy(condi.condi, memBuffer.start, sizeof(memBuffer[0]) * condi.nCount);
////}
////
////void ItemAccessor::readUseCondition(CSVDocument &doc)
////{
////	const int totalCount = doc.numRows();
////	ItemUseCondTable *condition = m_Allocator.Alloc<ItemUseCondTable>(totalCount);
////	for (int i=0; i<totalCount; ++i)
////	{
////		readCondition(doc, condition[i], i, 24, 30);
////	}
////
////	m_UseCondition.setLength(totalCount+1);
////	memset(m_UseCondition.own_ptr(), 0, sizeof(m_UseCondition.ptr()[0]) * (totalCount + 1));
////	ItemUseCondTable **tmpCond = m_UseCondition.own_ptr();
////	for (int i=0; i<totalCount; ++i)
////	{
////		ItemUseCondTable *con = &condition[i];
////		tmpCond[con->itemId] = con;
////	}
////}
////
////bool ItemAccessor::findOrInsertItemId(int itemId, int sceneId)
////{
////	bool flag = false;
////	for (int i=m_SceneIdVec.size()-1; i>-1; --i)
////	{
////		if (m_SceneIdVec[i].nItemId == itemId)
////		{
////			flag = true;
////			break;
////		}	
////	}
////	m_SceneIdVec.push_back(ItemScene(itemId, sceneId));
////	return flag;
////}
////
//void ItemAccessor::readExitScene(CSVDocument &doc)
//{
//	int cId = doc.getColumnIndex(UTF8String("\xE7\x89\xA9\xE5\x93\x81ID"));
//	int cValidSceneId = doc.getColumnIndex(UTF8String("\xE6\x9C\x89\xE6\x95\x88\xE5\x9C\xBA\xE6\x99\xAFID"));
//
//	std::vector<int> tmpItemIdVec;
//	tmpItemIdVec.clear();
//	m_SceneIdVec.clear();
//	int totalCount = 0;
//	const int numCount = doc.numRows();
//	for (int i=0; i<numCount; ++i)
//	{
//		int id = doc.getValue(i, cId);
//		int value = doc.getValue(i, cValidSceneId);
//		if (!findOrInsertItemId(id, value))
//		{
//			tmpItemIdVec.push_back(id);
//			totalCount++;
//		}
//	}
//
//	ExistScenes *scenes = m_Allocator.Alloc<ExistScenes>(totalCount);
//	for (int j=0; j<totalCount; ++j)
//	{
//		ExistScenes *tmpScene = &scenes[j];
//
//		tmpScene->nItemId = tmpItemIdVec[j];
//		tmpScene->nCount = 0;
//		tmpScene->pSceneId = m_Allocator.Alloc<int>(0);
//		for (int k=m_SceneIdVec.size()-1; k>-1; --k)
//		{
//			if (m_SceneIdVec[k].nItemId == tmpItemIdVec[j])
//			{
//				tmpScene->nCount++;
//				int *tmp = m_Allocator.Alloc<int>(1);
//				*tmp = m_SceneIdVec[k].nSceneId;
//			}
//		}
//	}
//
//	m_ExistScenes.setLength(totalCount+1);
//	memset(m_ExistScenes.own_ptr(), 0, sizeof(m_ExistScenes.ptr()[0]) * (totalCount + 1));
//	ExistScenes **tmpScenes = m_ExistScenes.own_ptr();
//	for (int i=0; i<totalCount; ++i)
//	{
//		ExistScenes *tmp = &scenes[i];
//		tmpScenes[tmp->nItemId] = tmp;
//	}
//}	

const CFItem* ItemAccessor::getItem(uint32 itemId) const
{
	if (itemId >= m_ItemList.length())return NULL;
	const CFItem *tmpItem = m_ItemList[itemId];
	if (NULL == tmpItem)
	{
		printf("get config error item id:%d \n",itemId);
		return NULL;
	}
	return tmpItem;
}

const CFItem* ItemAccessor::getItemByName(const char* sName) const
{
	for (int i=m_ItemList.length()-1; i>0; --i)
	{
		const CFItem *tmpItem = m_ItemList[i];
		int ret = strcmp(tmpItem->sName, sName);
		if (ret == 0)
		{
			return tmpItem;
		}
	}
	return NULL;
}

