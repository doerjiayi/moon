#pragma once


namespace SkillUtil
{
	using namespace lib::graph;
	//范围角色搜索搜索过滤类型
	enum GetRangeActorFilter
	{
		afEnemy  = 0x01,//可攻击
		afFriend = 0x02,//友军
	};

	//判断角色是否可攻击
	bool isEnemyActor(CDoer *sponsor, CDoer *actor);
	//判断角色是否是友军
	bool isFriendActor(CDoer *sponsor, CDoer *actor);
	//技能时间点范围转换为游戏坐标范围
	void timeRect2GameRect(GRect &rect, CDoer *sponsor, const GPoint *center, const CFSkillTimePoint *timePoint);
	//通过移动速度计算8方向朝向
	int calcDir8OfSpeed(int sx, int sy);
	//计算两个坐标点的8方向朝向
	int calcDir8OfPosition(int cx, int cy, int tx, int ty);
	//计算并修复不可移动的坐标区域
	bool fixMovePoint(Scene *scene, int sx, int sy, int &dx, int &dy);

	//获取一定范围内角色列表
	int getRangeActors(CBList<CDoer*> &list, CDoer *sponsor, const GRect &rect, int filter = afEnemy);
	//获取各职业普通攻击技能ID
	const CFSkillPostureLevel* getNormalAttackPosture(int job, int index);

	//产生技能作用
	void takeSkillTimePointEffect(CDoer *sponser, const CFSkillTimePoint *timePoint);

	//技能作用生效函数集
	void takePowerAttackEffect(CDoer *sponsor, const GRect &rect, AttackPowerType type, const int power, double rate);
	void takeSkillWGAttackEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center = NULL);
	void takeSkillNGAttackEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center = NULL);
	void takeSkillUpturnEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center = NULL);
	void takeSkillPullEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center = NULL);
	void takeSkillKnockDownEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center = NULL);
	void takeSkillSprintDownEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center = NULL);
	void takeSkillRecoilEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center = NULL);
	void takeSkillSelfOutOfControlEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center = NULL);
	void takeSkillTargetOutOfControlEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center = NULL);
	void takeSkillShakeEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center = NULL);
}
