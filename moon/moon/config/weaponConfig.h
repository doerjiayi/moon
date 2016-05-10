#pragma once

//
//武器系统配置数据结构头文件
//

//武器等级
struct CFWeaponLevel
{
	unsigned char id;//武器ID
	unsigned char level;//武器等级
	unsigned char basicAttriType;//基础属性类型
	unsigned char reserve;//保留
	int basicAttriValue;//基础属性值
	unsigned short soulEater;//噬魂值
	unsigned short figure;//外形编号
	unsigned int eternalMax;//最大武魂值
	unsigned int eternalUpgrade;//升级武魂值
	const char* name;//名字
	const char* desc;//描述
};

//武器孔
struct CFWeaponHole
{
	unsigned char id;//武器ID
	unsigned char holeId;//孔ID
	unsigned char openLevel;//孔开启等级
	unsigned char itemCost;//孔激活消耗物品数量
	unsigned short itemId;//孔激活消耗物品I
	unsigned int activeCost;//孔激活消耗货币数量
	unsigned char activeType;//孔激活消耗货币类型
	unsigned char addAttriType;//孔加成属性类型
	unsigned short addAttriRate;//孔加成属性比例
	const char* name;//孔名字
};

//武器
struct CFWeapon
{
	unsigned char id;//武器ID
	unsigned char job;//职业
	unsigned char wtype;//武器类型
	unsigned char numHoles;//武器孔数 固定为7
	unsigned char numLevels;//武器等级数
	unsigned char reserve[3];//保留
	CFWeaponHole** holes;//武器孔表
	CFWeaponLevel** levels;//武器等级表
};

//灵珠等级
struct CFBeadLevel
{
	unsigned short id;//灵珠ID
	unsigned char level;//灵珠等级
	unsigned char baseAttriType;//基础属性类型
	int minBaseValue;//基础属性最小值
	int maxBaseValue;//基础属性最大值
	unsigned int upgradeExp;//升级经验
};

//灵珠
struct CFBead
{
	unsigned short id;//灵珠ID
	unsigned char btype;//灵珠类型
	unsigned char activeAttrLevel;//附加属性激活等级
	unsigned char attrQulity;//附加属性品质
	unsigned char numLevels;//等级数
	unsigned char eleAttriType;//元素伤害类型
	unsigned char reserve[3];//保留
	unsigned int minEleRatio;//元素系数最小值
	unsigned int maxEleRatio;//元素系数最大值
	const char* name;//名字
	const char* desc;//描述
	CFBeadLevel** levels;//灵珠等级表
};

//灵珠附加属性
struct CFBeadAttr
{
	unsigned char attrQuality;//属性品质
	unsigned char attrType;//属性类型
	unsigned char reserve[2];//保留
	int minValue;//最小值
	int maxValue;//最大值
};

//灵珠附加属性品质
#define MAX_RANDOM_ATTR 32
struct StdBeadQuality
{
	unsigned char attrQuality;//属性品质
	unsigned char numAttrs;//属性数量
	unsigned char randomMax;//随机最大值
	CFBeadAttr** attrs;//属性列表
	unsigned char attrArray[MAX_RANDOM_ATTR];//属性随机数组，通过此数组可获得属性列表内容
};
