#include "StdAfx.h"
#include "doerEquip.h"

using namespace moon;
using namespace common::NetCmd;

CPlayerEquip::CPlayerEquip()
	:super()
{
	ZeroMemory(m_ItemList, sizeof(m_ItemList));
}

CPlayerEquip::~CPlayerEquip()
{

}

bool CPlayerEquip::init()
{
	return true;
}

bool CPlayerEquip::loadData(CDataPacketReader &data)
{
	common::DBType::DataSectionHeader *pSecHdr;

	if (data.getAvaliableLength() < sizeof(*pSecHdr))
		return false;
	pSecHdr = (common::DBType::DataSectionHeader*)data.getOffsetPtr();
	data.adjustOffset(sizeof(*pSecHdr));
	if (pSecHdr->wDataType != common::SystemId::sysEquip)
	{
		logError( "角色(%lld:%s)数据的装备数据错误", 
			m_pPlayer->m_EntityId.llid, m_pPlayer->m_sName);
		return false;
	}

	assert(pSecHdr->wDataCount < EquipCount);
	BYTE btItemPos;
	UserItem *pUserItem;
	for (int i=pSecHdr->wDataCount-1; i>-1; --i)
	{
		if (data.getAvaliableLength() < sizeof(btItemPos) + sizeof(m_ItemList[0]))
		{
			logError("角色(%lld:%s)数据的装备数据(%d)错误，数据长度不足", 
				m_pPlayer->m_EntityId.llid, m_pPlayer->m_sName, i);
			return false;
		}
		data >> btItemPos;
		if (btItemPos >= EquipCount)
		{
			logError("角色(%lld:%s)数据的装备数据(%d)错误，装备索引(%d)越界", 
				m_pPlayer->m_EntityId.llid, m_pPlayer->m_sName, i, btItemPos);
			return false;
		}
		pUserItem = CGlobalLogicObjAlloc::allocUserItem();
		data >> *pUserItem;
		m_ItemList[btItemPos] = pUserItem;
	}
	return true;
}

void CPlayerEquip::saveData(CDataPacket &data)
{
	int i, nItemCount = 0;
	for (i=0; i<EquipCount; ++i)
	{
		if (m_ItemList[i])
		{
			nItemCount++;
		}
	}

	common::DBType::DataSectionHeader SecHdr;
	//写入数据域头部
	SecHdr.wDataType = common::SystemId::sysEquip;
	SecHdr.wDataVersion = common::DBType::EquipDataVersion;
	SecHdr.wStructSize = sizeof(*(m_ItemList[0]))+1;//多了一个字节，位置
	SecHdr.wDataCount = nItemCount;
	data << SecHdr;

	//写入装备物品数据
	for (i=0; i<EquipCount; ++i)
	{
		if (m_ItemList[i])
		{
			data << (BYTE)i;
			data << *(m_ItemList[i]);
		}
	}
}

void CPlayerEquip::dispatchRecvPacket(int btCmd, CDataPacketReader &inPacket)
{
	switch(btCmd)
	{
		case cTakeOnItem:
		{
			HandleTakeOnItem(inPacket);
			break;
		}
		case cTakeOffItem:
		{
			HandleTakeOffItem(inPacket);
			break;	
		}
	}
}

int CPlayerEquip::getEquipPos(int btItemType)
{
	switch(btItemType)
	{
	case iHat://头盔
		return epHat;
	case iDress://衣服
		return epDress;
	case iPants://裤子
		return epPants;
	case iBoot://靴子
		return epBoot;

	//非装备返回-1
	default:
		return -1;
	}
}

int CPlayerEquip::findEquipItem(common::ItemSeries series)
{
	for (int i=0; i<EquipCount; ++i)
	{
		if (m_ItemList[i] && m_ItemList[i]->series.llid == series.llid)
		{
			return i;
		}
	}
	return -1;
}

void CPlayerEquip::sendEquipItems()
{
	int i, nItemCount = 0;
	for (i=0; i<EquipCount; ++i)
	{
		if (m_ItemList[i])
		{
			nItemCount++;
		}
	}

	if (nItemCount > 0)
	{
		CGateSendPacket &pack = m_pPlayer->allocSendPacket();
		pack.writeCmd(common::SystemId::sysEquip, sSendEquipItems);
		pack << (BYTE)nItemCount;
		for (i=0; i<EquipCount; ++i)
		{
			if (m_ItemList[i])
			{
				pack << (BYTE)i;
				pack << *(m_ItemList[i]);
			}
		}
		pack.flush();
	}
}

void CPlayerEquip::HandleTakeOnItem(CDataPacketReader &inPacket)
{
	ItemSeries series;
	inPacket >> series;

	//在背包中找到物品
	int nBagIndex;
	UserItem *pUserItem = m_pPlayer->m_Bag.getItem(series, &nBagIndex);
	if (!pUserItem)
		return;
	const CFItem *pStdItem = g_ConfigManager->itemDataAccessor.getItem(pUserItem->wItemId);
	if (!pStdItem)
		return;
	int nEquipPos = getEquipPos(pStdItem->m_btType);
	if (nEquipPos < 0)
		return;
	//如果目标位置有装备，则换下此装备
	if (m_ItemList[nEquipPos])
	{
		TakeOffItem(nEquipPos);
	}
	//将物品复制到装备物品位置并从背包中移除物品
	m_ItemList[nEquipPos] = pUserItem;
	m_pPlayer->m_Bag.delItem(nBagIndex, 0, NULL);
	//发送改变装备物品
	CGateSendPacket &pack = m_pPlayer->allocSendPacket();
	pack.writeCmd(common::SystemId::sysEquip, sSetEquipItem);
	pack << (BYTE)nEquipPos;
	pack << *pUserItem;
	pack.flush();

	//重新计算角色属性和形象
	m_pPlayer->m_Abil.recalcAbility();
	m_pPlayer->m_Abil.sendAbility();
//#pragma __CPMSG__(TODO: miros : 记录穿装备日志)
}

void CPlayerEquip::HandleTakeOffItem(CDataPacketReader &inPacket)
{
	ItemSeries series;
	inPacket >> series;

	int nEquipPos = findEquipItem(series);
	if (nEquipPos < 0 || m_ItemList[nEquipPos] < 0)
		return;

	TakeOffItem(nEquipPos);

	//重新计算角色属性和形象
	m_pPlayer->m_Abil.recalcAbility();
	m_pPlayer->m_Abil.sendAbility();
}

void CPlayerEquip::TakeOffItem(int nEquipPos)
{
	UserItem *pTakeOffItem = m_ItemList[nEquipPos];
	m_pPlayer->m_Bag.addItem(pTakeOffItem, 0, NULL);
	m_ItemList[nEquipPos] = NULL;
//#pragma __CPMSG__(TODO: miros : 记录脱装备日志)
	//发送改变装备物品
	CGateSendPacket &pack = m_pPlayer->allocSendPacket();
	pack.writeCmd(common::SystemId::sysEquip, sSetEquipItem);
	pack << (BYTE)nEquipPos;
	pack.flush();
}

