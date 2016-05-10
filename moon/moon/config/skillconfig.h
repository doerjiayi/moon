#pragma once

//
//技能配置数据结构头文件
//

//技能招式等级学习条件
struct CFSkillTrainCondition
{
	int level;//所需等级
	int coin;//所需银两
	int gold;//所需元宝
};

//技能使用条件
struct CFSkillSpellCondition
{
	int mp;//所需蓝量
	int hp;//所需血量
};

//技能属性值
union CFSkillValue
{
	int n;
	float d;
	struct {
		short w1;
		short w2;
	};
	struct {
		unsigned char s1;
		unsigned char s2;
		unsigned char s3;
		unsigned char s4;
	};
};

//技能时间点
struct CFSkillTimePoint
{
	enum ActionType
	{
		aNone,					//类型			别名		值1类型和意义			值2类型和意义
		aWGAttack = 1,			//外功攻击		WG		n:攻击输出附加值		d:攻击输出倍率
		aNGAttack = 2,			//内功攻击		NG		n:攻击输出附加值		d:攻击输出倍率
		aUpturn = 3,			//打飞			UT		d:像素距离			无
		aPull = 4,				//击退			PL		d:像素距离			无
		aKnockDown = 5,			//击倒			KD		无					无
		aSprint = 6,			//向前冲刺		SP		d:像素距离			n:遇碰撞是否停止
		aRecoil = 7,			//后退			RC		d:像素距离			n:遇碰撞是否停止
		aSelfOutOfControl = 8,	//施加自身硬直		OC		d:时间
		aTargetOutOfControl = 9,//施加目标硬直		OT		d:时间
		aShake = 30,			//屏幕震动		SK		无					n:是否其他玩家也一起震
	};
	unsigned short postureId;//所属招式ID
	unsigned char level;//所属招式等级
	unsigned char index;//在所属招式等级的时间列表中的索引
	unsigned short time;//触发时间，单位为毫秒（最大间隔为65.535秒）
	unsigned char reserve2[2];
	unsigned char repeat;//重复次数
	unsigned char actType;//行为类型
	unsigned short interval;//重复间隔，单位为毫秒（最大间隔为65.535秒）
	CFSkillValue actValue1;//行为值1，依据不同的行为类型具备不同意义
	CFSkillValue actValue2;//行为值2，依据不同的行为类型具备不同意义
	short left;//范围左距
	short top;//范围顶距
	short right;//范围右距
	short bottom;//范围底距
};


//技能招式时间线
struct CFSkillPostureLevel
{
	unsigned short postureId;//所属招式ID
	unsigned char level;//等级
	unsigned char numTimePoints;//招式作用时间点
	unsigned char actionIndex;//攻击动作编号
	unsigned char ___reserve[3];
	unsigned short time;//招式施展时间，单位为毫秒
	unsigned short oaTime;//招式施展硬直时间，单位为毫秒
	unsigned short omTime;//招式施展移动硬直时间，单位为毫秒
	unsigned short prepareTime;//招式起手时间，单位为毫秒
	CFSkillTrainCondition trainCond;//招式学习条件表
	CFSkillSpellCondition spellCond;//招式使用条件表
	CFSkillTimePoint** timePoints;//招式作用时间表
	const char* desc;//等级描述内容
};


//技能招式
struct CFSkillPosture
{
	unsigned short id;//招式ID
	unsigned short icon;//招式图标
	const char* name;//招式名称
	unsigned short skillId;//所属技能ID
	unsigned char pos;//所在技能位置
	unsigned char numLevels;//等级数量
	CFSkillPostureLevel** levels;//等级配置表
};

//技能等级
struct CFSkillLevel
{
	unsigned short skillId;//所属技能ID
	unsigned char level;//等级
	char __reserve[1];
	CFSkillTrainCondition trainCond;//升级条件表
	CFSkillSpellCondition spellCond;//施放条件表
	const char* desc;//等级描述
};

//技能配置
struct CFSkill
{
public:
	int id;//技能ID
	const char* name;//技能名称
	unsigned short icon;//技能图标
	unsigned char job;//技能所属职业
	unsigned char numPostures;//技能招式数量
	unsigned char numLevels;//技能等级数量
	char ___reserve[3];
	CFSkillPosture** postures;//技能招式表
	CFSkillLevel** levels;//技能招式表
};
