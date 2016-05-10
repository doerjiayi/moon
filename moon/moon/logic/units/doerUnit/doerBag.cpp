#include "StdAfx.h"

using namespace moon;
using namespace common::NetCmd;

CPlayerBag::CPlayerBag()
	:super()
{

}

CPlayerBag::~CPlayerBag()
{
	ClearItems();
}

bool CPlayerBag::init()
{
	m_btBagCurSize = (unsigned char)DefaultBagSize;
	return true;
}

void CPlayerBag::ClearItems()
{
	UserItem **ppItemList = m_ItemList;
	for (INT_PTR i=m_ItemList.count()-1; i>-1; --i)
	{
		CGlobalLogicObjAlloc::freeUserItem(ppItemList[i]);
	}
	m_ItemList.clear();
}

bool CPlayerBag::loadData(CDataPacketReader &data)
{
	common::DBType::DataSectionHeader *pSecHdr;

	if (data.getAvaliableLength() < sizeof(*pSecHdr))
		return false;
	pSecHdr = (common::DBType::DataSectionHeader*)data.getOffsetPtr();
	data.adjustOffset(sizeof(*pSecHdr));
	if (pSecHdr->wDataType != common::SystemId::sysBag)
	{
		logError("角色(%lld:%s)数据的背包数据错误", 
			m_pPlayer->m_EntityId.llid, m_pPlayer->m_sName);
		return false;
	}

	ClearItems();
	m_ItemList.reserve(pSecHdr->wDataCount);

	UserItem *pUserItem;
	for (int i=pSecHdr->wDataCount-1; i>-1; --i)
	{
		if (data.getAvaliableLength() < sizeof(*pUserItem))
		{
			logError("角色(%lld:%s)数据的背包数据(%d)错误，数据长度不足", 
				m_pPlayer->m_EntityId.llid, m_pPlayer->m_sName, i);
			return false;
		}
		pUserItem = CGlobalLogicObjAlloc::allocUserItem();
		data >> *pUserItem;
		m_ItemList.add(pUserItem);
	}
	return true;
}

void CPlayerBag::saveData(CDataPacket &data)
{
	UserItem **ppItemList = m_ItemList;
	INT_PTR nCount = m_ItemList.count();
	common::DBType::DataSectionHeader SecHdr;
	//写入数据域头部
	SecHdr.wDataType = common::SystemId::sysBag;
	SecHdr.wDataVersion = common::DBType::BagDataVersion;
	SecHdr.wStructSize = sizeof(*(m_ItemList[0]));
	SecHdr.wDataCount = (unsigned short)nCount;
	data << SecHdr;

	//写入背包物品数据
	for (INT_PTR i=0; i<nCount; ++i)
	{
		data << *(ppItemList[i]);
	}
}

UserItem* CPlayerBag::getItem(const common::ItemSeries series, int *pIndex)
{
	UserItem **pItemList = m_ItemList;
	for (INT_PTR i=m_ItemList.count()-1; i>-1; --i)
	{
		if (pItemList[i]->series.llid == series.llid)
		{
			if (pIndex)
				*pIndex = (int)i;
			return pItemList[i];
		}
	}
	return NULL;
}

UserItem* CPlayerBag::getItem(const int wItemId, int *pIndex /* = NULL */)
{
	UserItem **pItemList = m_ItemList;
	for (INT_PTR i=m_ItemList.count()-1; i>-1; --i)
	{
		if (pItemList[i]->wItemId == wItemId)
		{
			if (pIndex)
				*pIndex = (int)i;
			return pItemList[i];
		}
	}
	return NULL;
}

int CPlayerBag::getItemCount(const int wItemId)
{
	int nCount = 0;
	UserItem **pItemList = m_ItemList;
	for (INT_PTR i=m_ItemList.count()-1; i>-1; --i)
	{
		if (pItemList[i]->wItemId == wItemId)
		{
			nCount += pItemList[i]->btCount;
		}
	}
	return nCount;
}

int CPlayerBag::addItem(const int wItemId, int nCount, int nQuality, int nStrong, int nUseTime, 
	const bool boBind, int nLogID, const char *sGiver)
{
	const CFItem *pStdItem = g_ConfigManager->itemDataAccessor.getItem(wItemId);
	if (!pStdItem)
		return 0;
	CLogicEngine *pLogicEngine = g_LogicEngine;

	int nResult = 0;
	int nDupCount = pStdItem->m_btDupCount;
	int nRemCount;
	int nExpireTime = nUseTime ? pLogicEngine->getDateTime() + nUseTime : 0;
	UserItem *pUserItem = NULL;
	bool boNoneOverlap = false;

	while (nCount > 0)
	{
		if (!boNoneOverlap && nDupCount > 0)
		{
			pUserItem = getCanOverlapItem(wItemId, nExpireTime, boBind);
			if (pUserItem)
			{
				nRemCount = nDupCount - pUserItem->btCount;
				if (nRemCount > nCount) 
					nRemCount = nCount;
				pUserItem->btCount += nRemCount;
				nCount -= nRemCount;
				nResult += nRemCount;
				SendItemCountChange(pUserItem);
//#pragma __CPMSG__(TODO: miros : 记录获得物品日志！)
 				LogicEvent event(leAddItem, m_pPlayer);
 				event.n1 = wItemId;
 				event.n2 = nRemCount;
 				g_LogicEngine->dispatchLogicEvent(event);
				continue;
			}
			else boNoneOverlap = true;
		}

		//先判断背包是否已满，已满则不能获得物品
		if (m_ItemList.count() >= m_btBagCurSize)
			break;

		nRemCount = __min(nDupCount, nCount);
		nRemCount = __max(1, nRemCount);//safety
		pUserItem = CGlobalLogicObjAlloc::allocUserItem();
		ZeroMemory(pUserItem, sizeof(*pUserItem));
		initUserItemFromStdItem(pUserItem, pStdItem, nRemCount, nQuality, nStrong, nExpireTime, boBind);
		pUserItem->series = pLogicEngine->allocId();
		m_ItemList.add(pUserItem);
		nCount -= nRemCount;
		nResult += nRemCount;
		SendAddItem(pUserItem);
//#pragma __CPMSG__(TODO: miros : 记录获得物品日志！)
 		LogicEvent event(leAddItem, m_pPlayer);
 		event.n1 = wItemId;
 		event.n2 = nRemCount;
 		g_LogicEngine->dispatchLogicEvent(event);
	}

	return nResult;
}

int CPlayerBag::delItem(const int wItemId, int nCount, int nLogId, const char *sGiver)
{
	int nResult = 0;
	int nSingleCount, nIndex;
	UserItem *pUserItem;

	while (nCount > 0)
	{
		pUserItem = getItem(wItemId, &nIndex);
		if (!pUserItem)
			break;
		nSingleCount = __max(1, pUserItem->btCount);//safety
		if (nSingleCount > nCount)
		{
			nSingleCount = nCount;
			pUserItem->btCount -= nSingleCount;
			nResult += nSingleCount;
			nCount = 0;
			SendItemCountChange(pUserItem);
//#pragma __CPMSG__(TODO: miros : 记录删除物品日志！)
//#pragma __CPMSG__(TODO: miros : 使用EventDispatcher分派删除物品事件)
		}
		else
		{
			nResult += nSingleCount;
			nCount -= nSingleCount;
			m_ItemList.remove(nIndex);
			SendDelItem(pUserItem);
//#pragma __CPMSG__(TODO: miros : 记录删除物品日志！)
//#pragma __CPMSG__(TODO: miros : 使用EventDispatcher分派删除物品事件)
			CGlobalLogicObjAlloc::freeUserItem(pUserItem);
		}

		LogicEvent event(leDelItem, m_pPlayer);
		event.n1 = wItemId;
		event.n2 = nResult;
		g_LogicEngine->dispatchLogicEvent(event);
	}

	return nResult;
}

void CPlayerBag::addItem(UserItem *pUserItem, int nLogID, const char *sGiver)
{
	//先判断背包是否已满，已满则不能获得物品
	if (m_ItemList.count() >= m_btBagCurSize)
		return;
	m_ItemList.add(pUserItem);
	SendAddItem(pUserItem);
//#pragma __CPMSG__(TODO: miros : 记录获得物品日志)
}

void CPlayerBag::delItem(const int nItemListIndex, int nLogId, const char *sGiver)
{
	assert(nItemListIndex < m_ItemList.count());
	UserItem *pUserItem = m_ItemList[nItemListIndex];
	m_ItemList.remove(nItemListIndex);
	SendDelItem(pUserItem);
//#pragma __CPMSG__(TODO: miros : 记录删除物品日志)
}

bool CPlayerBag::getCanAddItemCount(const int wItemId, int nCount, int nExpireTime, const bool boBind)
{
	const CFItem *pStdItem = g_ConfigManager->itemDataAccessor.getItem(wItemId);
	if (!pStdItem)
		return false;

	UserItem *pUserItem = NULL;
	int nDupCount = pStdItem->m_btDupCount;//能堆叠数量
	bool boNoneOverlap = false;//是否没有可堆叠
	int itemListNum = (int)m_ItemList.count();
	while (nCount > 0)
	{
		if (!boNoneOverlap && nDupCount > 0)
		{
			pUserItem = getCanOverlapItem(wItemId, nExpireTime, boBind);
			if (pUserItem)
			{
				int canDupCount = nDupCount - pUserItem->btCount;
				nCount -= canDupCount;
				continue;
			}
			else
			{
				boNoneOverlap = true;
			}
		}
		
		if (itemListNum == m_btBagCurSize)break;
		itemListNum++;
		nCount -= nDupCount;
	}

	if (nCount > 0)
	{
		return false;
	}
	return true;
}

UserItem* CPlayerBag::getCanOverlapItem(const int wItemId, int nExpireTime, const bool boBind)
{
	INT_PTR i;
	const CFItem *pStdItem = g_ConfigManager->itemDataAccessor.getItem(wItemId);
	if (!pStdItem)
		return NULL;
	int nDupCount = pStdItem->m_btDupCount;
	UserItem *pUserItem, **pItemList = m_ItemList;
	for (i=m_ItemList.count()-1; i>-1; --i)
	{
		pUserItem = pItemList[i];
		if (pUserItem->wItemId == wItemId && pUserItem->btCount < nDupCount && pUserItem->nExpireTime == nExpireTime)
		{
			return pUserItem;
		}
	}
	return NULL;
}

void CPlayerBag::initUserItemFromStdItem(UserItem* pUserItem, const CFItem *pStdItem, int nCount, int nQuality, int nStrong, int nExpireTime, bool boBind)
{
	pUserItem->wItemId = pStdItem->m_nItemId;
	pUserItem->btCount = nCount;
	pUserItem->btQuality = nQuality;
	pUserItem->btStrong = nStrong;
	pUserItem->nExpireTime = nExpireTime;
	pUserItem->setBind(boBind);
}

//////////////////////////////////////////////////////////////////////////
//发送网络协议包
void CPlayerBag::sendBagItems()
{
	INT_PTR nCount = m_ItemList.count();
	if (nCount > 0)
	{
		UserItem *pUserItem, **pItemList = m_ItemList;

		CGateSendPacket &pack = m_pPlayer->allocSendPacket();
		pack.writeCmd(common::SystemId::sysBag, NetCmd::sSendBagItems);
		size_t size = pack.getLength();
		pack << (int)nCount;
		size = pack.getLength();
		for (INT_PTR i=nCount-1; i>-1; --i)
		{
			pUserItem = pItemList[i];
			pack << *pUserItem;
			size = pack.getLength();
		}
		size = pack.getLength();
		pack.flush();
	}
}

void CPlayerBag::SendAddItem(UserItem *pUserItem)
{
	CGateSendPacket &pack = m_pPlayer->allocSendPacket();
	pack.writeCmd(sysBag, sAddBagItem);
	pack << *pUserItem;
	pack.flush();
}

void CPlayerBag::SendDelItem(UserItem *pUserItem)
{
	CGateSendPacket &pack = m_pPlayer->allocSendPacket();
	pack.writeCmd(sysBag, sDelBagItem);
	pack << pUserItem->series;
	pack.flush();
}

void CPlayerBag::SendItemCountChange(UserItem *pUserItem)
{
	CGateSendPacket &pack = m_pPlayer->allocSendPacket();
	pack.writeCmd(sysBag, sUpdateBagItemCount);
	pack << pUserItem->series;
	pack << pUserItem->btCount;
	pack.flush();
}

void CPlayerBag::SendUpdateItem(UserItem *pUserItem)
{
	CGateSendPacket &pack = m_pPlayer->allocSendPacket();
	pack.writeCmd(sysBag, sUpdateBagItem);
	pack << *pUserItem;
	pack.flush();
}
//发包处理
//////////////////////////////////////////////////////////////////////////
