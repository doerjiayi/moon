#pragma once

using namespace common;

struct ItemAttributeGroup;
//角色属性类
class DoerAbilData
{
public:
	AttributeValue biLi;//臂力			BL
	AttributeValue lingQiao;//灵巧			LQ
	AttributeValue tiPo;//体魄			TP
	AttributeValue neiXi;//内息			NX
	AttributeValue gangQi;//罡气			GQ
	AttributeValue waiGong;//外功			WG
	AttributeValue neiGong;//内功			NG
	AttributeValue waiFang;//外防			WF
	AttributeValue neiFang;//外防			NF
	AttributeValue waiFangCT;//外防穿透		WT
	AttributeValue neiFangCT;//内防穿透		NT
	AttributeValue qiXue;//气血			QX
	AttributeValue neiLi;//内力			NL
	AttributeValue waiBao;//外暴击			WB
	AttributeValue neiBao;//内暴击			NB
	AttributeValue kangWaiBao;//抗外暴			KW
	AttributeValue kangNeiBao;//抗内暴			KN
	AttributeValue mingZhong;//命中			MZ
	AttributeValue shanBi;//闪避			SB
	AttributeValue hitSpeed;//攻击速度		HS
	AttributeValue moveSpeed;//移动速度		MS
	AttributeValue qiXueHuiFu;//气血恢复速度	QH
	AttributeValue neiLiHuiFu;//内力恢复速度	NH
	AttributeValue fuYuan;//福缘			FY

public:
	DoerAbilData();

	//清空所有属性
	void reset();

	//追加一个属性
	inline DoerAbilData& operator += (const Attribute &attr)
	{
		AttributeValue &value = operator[](attr.type);
		value += attr.value;
		return *this;
	}

	//追加一个属性类
	DoerAbilData& operator += (const DoerAbilData &abil);

	//追加一个物品的属性
	DoerAbilData& operator += (const UserItem& item);

	//根据属性类型获取属性值对象
	//参数attrType必须是Attribute::AttributeType中的枚举类型
	AttributeValue& operator [] (unsigned int attrType);
	const AttributeValue& operator [] (unsigned int attrType) const;

	void calculateItemAttribute(const ItemAttributeGroup *itemAttr);
};
