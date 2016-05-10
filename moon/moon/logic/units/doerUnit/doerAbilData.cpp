#include "StdAfx.h"

DoerAbilData::DoerAbilData()
{
	reset();
}

void DoerAbilData::reset()
{
	memset(this, 0, sizeof(*this));
}

DoerAbilData& DoerAbilData::operator+=(const DoerAbilData& abil)
{
	for (int i=1; i<AttributeCount; ++i)
	{
		AttributeValue &a = this->operator[](i);
		const AttributeValue &b = abil.operator[](i);
		a += b;
	}
	return *this;
}

DoerAbilData& DoerAbilData::operator+=(const UserItem& item)
{
	const CFItem *itemStruct = g_ConfigManager->itemDataAccessor.getItem(item.wItemId);
	//1、将stdItem的静态属性表中的所有属性添加到属性集中
	calculateItemAttribute(itemStruct->m_StaticAttrs[0]);
	//2、依据物品的品质等级(item.btQuality)将stdItem中对应的品质属性添加到属性集中
	if (itemStruct->m_QualityAttrs != NULL)
	{
		calculateItemAttribute(itemStruct->m_QualityAttrs[item.btStrong]);
	}	
	//3、依据物品的强化等级(item.btStrong)将stdItem中对应的强化属性添加到属性集中
	if (itemStruct->m_StrongAttrs != NULL)
	{
		calculateItemAttribute(itemStruct->m_StrongAttrs[item.btQuality]);
	}
	return *this;
}

void DoerAbilData::calculateItemAttribute(const ItemAttributeGroup *itemAttr)
{
	for (int i=itemAttr->count-1; i>-1; --i)
	{
		Attribute *attrs = &itemAttr->attrs[i];
		switch (attrs->type)
		{
		case aBiLi:
			biLi += attrs->value;
			break;
		case aLingQiao:
			lingQiao += attrs->value;
			break;
		case aTiPo:
			tiPo += attrs->value;
			break;
		case aNeiXi:
			neiXi += attrs->value;
			break;
		case aGangQi:
			gangQi += attrs->value;
			break;
		case aWaiGong:
			waiGong += attrs->value;
			break;
		case aNeiGong:
			neiGong += attrs->value;
			break;
		case aWaiFang:
			waiFang += attrs->value;
			break;
		case aNeiFang:
			neiFang += attrs->value;
			break;
		case aWaiFangCT:
			waiFangCT += attrs->value;
			break;
		case aNeiFangCT:
			neiFangCT += attrs->value;
			break;
		case aQiXue:
			qiXue += attrs->value;
			break;
		case aNeiLi:
			neiLi += attrs->value;
			break;
		case aWaiBao:
			waiBao += attrs->value;
			break;
		case aNeiBao:
			neiBao += attrs->value;
			break;
		case aKangWaiBao:
			kangWaiBao += attrs->value;
			break;
		case aKangNeiBao:
			kangNeiBao += attrs->value;
			break;
		case aMingZhong:
			mingZhong += attrs->value;
			break;
		case aShanBi:
			shanBi += attrs->value;
			break;
		case aHitSpeed:
			hitSpeed += attrs->value;
			break;
		case aMoveSpeed:
			moveSpeed += attrs->value;
			break;
		case aQiXueHuiFu:
			qiXueHuiFu += attrs->value;
			break;
		case aNeiLiHuiFu:
			neiLiHuiFu += attrs->value;
			break;
		case aFuYuan:
			fuYuan += attrs->value;
			break;
		}
	}
}

AttributeValue& DoerAbilData::operator[](unsigned int attrType)
{
	switch(attrType)
	{
	case aBiLi: return biLi;
	case aLingQiao: return lingQiao;
	case aTiPo: return tiPo;
	case aNeiXi: return neiXi;
	case aGangQi: return gangQi;
	case aWaiGong: return waiGong;
	case aNeiGong: return neiGong;
	case aWaiFang: return waiFang;
	case aNeiFang: return neiFang;
	case aWaiFangCT: return waiFangCT;
	case aNeiFangCT: return neiFangCT;
	case aQiXue: return qiXue;
	case aNeiLi: return neiLi;
	case aWaiBao: return waiBao;
	case aNeiBao: return neiBao;
	case aKangWaiBao: return kangWaiBao;
	case aKangNeiBao: return kangNeiBao;
	case aMingZhong: return mingZhong;
	case aShanBi: return shanBi;
	case aHitSpeed: return hitSpeed;
	case aMoveSpeed: return moveSpeed;
	case aQiXueHuiFu: return qiXueHuiFu;
	case aNeiLiHuiFu: return neiLiHuiFu;
	case aFuYuan: return fuYuan;
	default: return *((AttributeValue*)NULL);
	}
}

const AttributeValue& DoerAbilData::operator[](unsigned int attrType) const
{
	DoerAbilData &abil = *((DoerAbilData*)this);
	return (abil.operator[](attrType));
}

