#pragma once

struct MonDropData;
struct MonDropItem;

//怪物配置数据结构
struct monsterStruct
{
	//怪物伤害输出类型
	enum MonsterDamageType
	{
		mdNG = 1,//内功
		mdWG = 2,//外攻 
	};

	//怪物行为标志类型
	enum MonsterFlags
	{
		mfInitiative		= 0x00000001,//主动攻击
		mfNoStickBack		= 0x00000002,//不还手
		mfCanNotBeAttack	= 0x00000004,//不可被攻击
		mfHideName			= 0x00000008,//隐藏名字
		mfSteady			= 0x00000010,//稳如泰山， 不可被打飞、打退或打到
		mfNeverStrick		= 0x00000020,//霸体
	};

	int monId;//怪物ID
	const char* name;//怪物名称
	unsigned char race;//怪物类型，与EntityType一致
	unsigned char damageType;//伤害类型
	char __reserver[2];
	unsigned short body;//怪物外形id
	unsigned short level;//怪物初始等级
	int exp;//怪物经验值
	int hp;//怪物血量
	int mp;//怪物内力
	int power;//攻击力
	int innerDefence;//内功防御
	int outerDefence;//内功防御
	int accurate;//命中
	int evasion;//闪避
	int innerDefenceCT;//内防穿透
	int outerDefenceCT;//外防穿透
	int baoji;//暴击值
	int kangNeiBao;//抗内暴
	int kangWaiBao;//抗外暴
	short moveSpeed;//移动速度
	short attackSpeed;//攻击速度
	short attackInterval;//攻击间隔
	short sickRange;//追击距离
	unsigned int flags;//怪物行为标志，MonsterFlags标志位的集合
	unsigned short skills[4];//怪物技能表
	short paLeft;//普通攻击左距离
	short paTop;//普通攻击顶距离
	short paRight;//普通攻击右距离
	short paBottom;//普通攻击底距离
	short paPrepareTime;//普通攻击起手时间
	short paActTime;//普通攻击生效时间
	int dropId;//掉落配置ID
	MonDropData* dropData;//掉落配置
};

//怪物掉落物品配置
struct MonDropData
{
	int numItems;//掉落项数量
	MonDropItem **items;//掉落物品表
};

//怪物掉落物品项
struct MonDropItem
{
	int dropId;//掉落配置ID
	unsigned short itemId;//掉落物品ID，0表示掉落银两
	unsigned short group;//掉落组，相同组的物品只掉落一个
	int minCount;//最低掉落数量
	int randCount;//随机掉落数量
	unsigned char minQuality;//物品最低品质等级
	unsigned char randQuality;//随机品质等级
	unsigned char minStrong;//物品最低强化等级
	unsigned char randStrong;//随机强化等级
	int rate;//掉落率
	int base;//掉落基数，if (random(rate) < base)则掉落
};
