#ifndef __DOER_ABILITY_H__
#define __DOER_ABILITY_H__

class CDoerAbility : 
	public CDoerUnit, 
	public DoerAbilData
{
public:
	typedef CDoerUnit super;

public:
	CDoerAbility();
	~CDoerAbility();

	//重新计算属性
	void recalcAbility();
	//向客户端发送属性数据
	void sendAbility();

protected:
	//重置属性
	void resetAbility();
	//计算等级属性
	void calcLevelAbility();
	//计算装备属性
	void calcEquipAbility();

public:
	int m_nHP;//气血值
	int m_nMP;//内力值
	unsigned short m_wBody;//衣服编号
	unsigned short m_wWeapon;//武器编号
	unsigned short m_wMount;//坐骑编号
};

#endif
