#ifndef __ACTOR_BATTLE_H__
#define __ACTOR_BATTLE_H__
class CDataPacketReader;
class CDataPacket;

/*******************************************
* 角色战斗模块
******************************************/

class CDoerBattle :
	public CDoerUnit
{
public:
	typedef CDoerUnit super;

public:
	CDoerBattle();
	~CDoerBattle();

public:
	inline bool isRunning() const { return m_dwRunStartTick != 0; }
	void startMove(short speedX, short speedY, unsigned short accTime = 0);
	void stopMove(bool broadcast = true);
	void startAttack(const CFSkillPostureLevel*const * postureList, uint32 postureCount, int dir);
	void stopAttack();
	void sendSceneInfo();
	void sendSyncPositionTo(CPlayer *target);
	void sendStartRunTo(CPlayer *target);
	void run(TickTime dwCurrTick);

	//直接掉血
	void damageHP(CDoer *sponsor, int damage);
	//被攻击，函数会计算闪避防御等并最终确定是否掉血
	void struck(CDoer *sponsor, AttackPowerType pwrType, int power, double rate = 1);
	//角色死亡
	void die(CDoer *killer);
	//复活角色
	void reviviscent();
	//施加硬直时间
	void outOfControl(int moveTime, int attackTime);
	//角色倒地
	void collapse(int layTime);

	//确定伤害倍率值，返回0表示闪避，<=1表示普通伤害，>1表示暴击伤害
	double decideDamageType(CDoer *sponsor, AttackPowerType);
	//计算伤害承受值，会计算防御减伤等属性并返回最终掉血值
	int calcDamageValue(CDoer *sponsor, AttackPowerType pwrType, int power);
	//计算移动状态下指定时间点的新位置
	bool calcNewPositionAtTime(TickTime dwTick, int &nNewX, int &nNewY);
	//判断目标是否可以被攻击
	bool isAttackableActor(CDoer *target);

	//设置最后攻击者
	void setLastHiter(CDoer *sponsor);
	//设置攻击目标
	void setTargetActor(CDoer *target);
	//设置怪物移动目标位置
	void setMoveTarget(int tx, int ty);

public:
	virtual bool init();
	virtual bool loadData(CDataPacketReader &data);
	virtual void dispatchRecvPacket(int btCmd, CDataPacketReader &inPacket);
	virtual void dispatchMsg(DoerMsg *msg);
	virtual void offline();

private:
	//技能作用时间点状态
	struct SkillTimePointState
	{
		const CFSkillTimePoint *timePoint;
		TickTime nextTime;
		int remainTwice;
	};
	MemoryBlock<SkillTimePointState, 4> m_SkillTimeList;//技能作用时间点状态列表
	const CFSkillPostureLevel* m_CurrPostures[4];//攻击招式列表
	const CFSkillPostureLevel* m_pCurrPosture;//当前招式
	short m_wCurrPostureCount;//攻击招式数量
	short m_wCurrPostureIndex;//当前攻击出招索引
	TickTime m_dwCurrPostureStartTime;//当前招式出招时间
	TickTime m_dwCurrPostureEndTime;//当前招式结束时间
	TickTime m_dwOutOfMoveEndTime;//移动硬直结束时间
	TickTime m_dwOutOfAttackEndTime;//攻击硬直结束时间

private:
	//---- 通用战斗状态处理函数 ----//
	void updateRunState(TickTime dwCurrTick);
	void updateSkillTimePoints(TickTime currTime);
	void processPostures(TickTime currTime);
	bool isAcceptablePositionFaultBit(int tx, int ty);
	void launchPosture(const CFSkillPostureLevel *posture, int dir);
	void breakPosture(const CFSkillPostureLevel *posture);
	void completePosture(const CFSkillPostureLevel *posture);
	void completeAttack();
	void takeMonNormalAttackEffect();

private:
	//---- 通信数据包相关处理函数 ----//
	void broadcastStartRun(int x, int y, int sx, int sy, int accTime);
	void broadcastStopRun(int x, int y);
	void broadcastNormalAttack(int dir, int actionIdx);
	void broadcastStruck(CDoer *sponser, int damage);
	void broadcastDie();
	void broadcastReviviscent();
	void clientStartRunHandler(CDataPacketReader &inPacket);
	void clientStopRunHandler(CDataPacketReader &inPacket);
	void clientNormalAttackhandler(CDataPacketReader &inPacket);
	void clientEnterGateHandler(CDataPacketReader &inPacket);
	void clientPickDropItem(CDataPacketReader &inPacket);
private:
	//---- 怪物AI相关处理函数 ----//
	void runAI(TickTime dwCurrTick);
	void searchTarget();
	void attackTargetActor();
	void moveToTarget();
	void scatterMonItems(CDoer *owner);

private:
	TickTime		m_dwRunStartTick;//起跑时间
	TickTime		m_dwRunEndTick;//跑动结束时间，为0表示永不停止
	int				m_nRunStartX;//起跑初始X位置
	int				m_nRunStartY;//起跑初始Y位置
	int				m_nRunSpeedX;//水平跑动速度
	int				m_nRunSpeedY;//垂直跑动速度
	int				m_nRunAccelerateTime;//助跑加速度时间，单位为毫秒
	unsigned int	m_dwClientRunStartTick;//客户端起跑的时间

public:
	unsigned int	m_dwMonFlags;//怪物行为标志
	int				m_nTargetX;//怪物移动目的地X
	int				m_nTargetY;//怪物移动目的地Y
	bool			m_boReturning;//怪物是否在回归出生地的途中
	char			___________reserve[3];
	CDoer*			m_pTargetActor;//怪物攻击目标
	CDoer*			m_pLastHiter;//最后一次攻击者
	TickTime		m_dwLastHiterTimeOut;//最后一次攻击者超时时间
	TickTime		m_dwNextSearchTargetTick;//下次进行目标搜索的时间
	TickTime		m_dwMonNormalAttackPrepareEndTick;//怪物普通攻击起手结束时间
	TickTime		m_dwMonNormalAttackTakeEffectTick;//怪物普通攻击作用生效时间
};

#endif
