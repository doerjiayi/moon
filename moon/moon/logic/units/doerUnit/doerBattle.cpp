#include "StdAfx.h"

CDoerBattle::CDoerBattle()
	:super()
{
	m_dwRunStartTick = 0;
	m_dwRunEndTick = 0;
	m_nRunStartX = 0;
	m_nRunStartY = 0;
	m_nRunSpeedX = 0;
	m_nRunSpeedY = 0;
	m_nRunAccelerateTime = 0;
	m_dwClientRunStartTick = 0;
	m_dwMonFlags = 0;
	m_nTargetX = -1;
	m_nTargetY = -1;
	m_boReturning = false;
	m_pTargetActor = NULL;
	m_pLastHiter = NULL;
	m_dwLastHiterTimeOut = 0;
	m_dwNextSearchTargetTick = 0;
	m_dwMonNormalAttackPrepareEndTick = 0;
	m_dwMonNormalAttackTakeEffectTick = 0;

	memset(m_CurrPostures, 0, sizeof(m_CurrPostures));
	m_pCurrPosture = 0;
	m_wCurrPostureCount = 0;
	m_wCurrPostureIndex = 0;
	m_dwCurrPostureStartTime = 0;
	m_dwCurrPostureEndTime = 0;
	m_dwOutOfMoveEndTime = 0;
	m_dwOutOfAttackEndTime = 0;
}

CDoerBattle::~CDoerBattle()
{

}

bool CDoerBattle::init()
{
	return true;
}

bool CDoerBattle::loadData(CDataPacketReader &data)
{
	return true;
}

void CDoerBattle::startMove(short speedX, short speedY, unsigned short accTime /* = 0 */)
{
	m_dwRunStartTick = g_LogicEngine->getTickCount();
	m_dwRunEndTick = 0;
	m_nRunStartX = m_pActor->m_nX;
	m_nRunStartY = m_pActor->m_nY;
	m_nRunSpeedX = speedX;
	m_nRunSpeedY = speedY;
	m_nRunAccelerateTime = accTime;
	if (speedX > 0)
		m_pActor->m_btDirection = 1;
	else if (speedX < 0)
		m_pActor->m_btDirection = 0;
	broadcastStartRun(m_pActor->m_nX, m_pActor->m_nY, speedX, speedY, accTime);
}

void CDoerBattle::startAttack(const CFSkillPostureLevel*const * postureList, uint32 postureCount, int dir)
{
	assert(postureList && postureCount);
	stopAttack();
	if (postureCount > ARRAY_LEN(m_CurrPostures))
		postureCount = ARRAY_LEN(m_CurrPostures);
	for (uint32 i=0; i<postureCount; ++i)
	{
		assert(postureList[i]);
		m_CurrPostures[i] = postureList[i];
	}
	m_wCurrPostureCount = postureCount;
	m_wCurrPostureIndex = 0;
	m_pActor->m_btDirection = dir;
	launchPosture(postureList[0], dir);
}

void CDoerBattle::stopAttack()
{
	if (m_dwCurrPostureStartTime)
	{
		m_dwCurrPostureStartTime = 0;
		m_wCurrPostureCount = 0;
		m_wCurrPostureIndex = 0;
	}
	m_dwMonNormalAttackPrepareEndTick = 0;
	m_dwMonNormalAttackTakeEffectTick = 0;
}


void CDoerBattle::stopMove(bool broadcast)
{
	if (m_dwRunStartTick)
	{
		m_dwRunStartTick = 0;
		if (broadcast)
		{
			broadcastStopRun(m_pActor->m_nX, m_pActor->m_nY);
		}
	}
}

void CDoerBattle::dispatchMsg(DoerMsg *msg)
{
	switch(msg->ident)
	{
	case PM_SELF_DIE:
		die((CDoer*)msg->param1);
		break;
	}
}

void CDoerBattle::offline()
{
}

void CDoerBattle::run(TickTime dwCurrTick)
{
	//上次被攻击时间距离现在超过一定时间则解除对攻击对象记录
	if (m_pLastHiter && dwCurrTick >= m_dwLastHiterTimeOut)
		setLastHiter(NULL);
	//处理移动
	if (m_dwRunStartTick && m_pActor->m_pScene)
		updateRunState(dwCurrTick);
	//运行怪物AI运算
	if (!m_pPlayer)
		runAI(dwCurrTick);
	//处理攻击
	if (m_dwCurrPostureStartTime)
		processPostures(dwCurrTick);
	//处理怪物普通攻击
	if (m_dwMonNormalAttackTakeEffectTick && dwCurrTick >= m_dwMonNormalAttackTakeEffectTick)
		takeMonNormalAttackEffect();

	//更新技能作用时间线
	updateSkillTimePoints(dwCurrTick);
}

void CDoerBattle::damageHP(CDoer *sponsor, int damage)
{
	//无敌模式不可受到攻击
	if (m_pActor->m_boGodMode)
		return;

	assert(damage > 0);
	if (sponsor) 
		setLastHiter(sponsor);
	if (m_pActor->m_Abil.m_nHP >= damage)
	{
		m_pActor->m_Abil.m_nHP -= damage;
	}
	else
	{
		stopMove();
		m_pActor->m_Abil.m_nHP = 0;
		m_pActor->sendMsg(PM_SELF_DIE, sysBattle, (INT_PTR)sponsor, 0, 0, 0);
	}
}

void CDoerBattle::die(CDoer *killer)
{
	if (m_pActor->m_boDead)
		return;
	m_pActor->m_Abil.m_nHP = 0;
	m_pActor->m_boDead = true;
	m_pActor->m_dwDieTick = g_LogicEngine->getTickCount();
	stopMove();
	stopAttack();
	broadcastDie();
	//死亡后移动一定距离
	m_pActor->setXY(m_pActor->m_nX + (m_pActor->m_btDirection == 1 ? -120 : 120), m_pActor->m_nY);
	//怪物死亡处理
	if (!m_pPlayer)
	{
		if (killer)
		{
			killer->gainExp(m_pActor->m_nMonExp);
			scatterMonItems(killer);
		}
	}
	//分派死亡事件
	LogicEvent event(leActorDie, m_pActor);
	event.n1 = (INT_PTR)killer;
	g_LogicEngine->dispatchLogicEvent(event);
}

void CDoerBattle::reviviscent()
{
	if (!m_pActor->m_boDead)
		return;
	m_pActor->m_boDead = false;
	m_pActor->m_Abil.m_nHP = m_pActor->m_Abil.qiXue;
	m_pActor->m_Abil.m_nMP = m_pActor->m_Abil.neiLi;
	broadcastReviviscent();
	//分派复活事件
	LogicEvent event(leActorRevivicent, m_pActor);
	g_LogicEngine->dispatchLogicEvent(event);
}

void CDoerBattle::outOfControl(int moveTime, int attackTime)
{
	const TickTime dwCurrTick = g_LogicEngine->getTickCount();
	TickTime newTick; 
	if (moveTime != 0)
	{
		newTick = dwCurrTick + moveTime;
		if (newTick > m_dwOutOfMoveEndTime)
			m_dwOutOfMoveEndTime = newTick;
	}
	if (attackTime != 0)
	{
		newTick = dwCurrTick + attackTime;
		if (newTick > m_dwOutOfAttackEndTime)
			m_dwOutOfAttackEndTime = newTick;
	}
}

void CDoerBattle::collapse(int layTime)
{
	stopMove(false);
	stopAttack();
	outOfControl(layTime, layTime);
}

void CDoerBattle::struck(CDoer *sponsor, AttackPowerType pwrType, int power, double rate)
{
#if 1
	//无敌模式不可受到攻击
	if (m_pActor->m_boGodMode)
		return ;

	const double dmRate = decideDamageType(sponsor, pwrType);

	//闪避
	if (dmRate == 0)
	{
		return;
	}
	
	int damage = (int)(calcDamageValue(sponsor, pwrType, power) * rate * dmRate);
	if (damage > 0)
	{
		const TickTime dwCurrTick = g_LogicEngine->getTickCount();

		//怪物被攻击需要停止移动
		if (!m_pPlayer)
		{
			stopMove();
		}
		damageHP(sponsor, damage);
		broadcastStruck(sponsor, damage);
		//outOfControl(200, 200);
		outOfControl(250, 250);
		//当前处于普通攻击起手状态，则终止普通攻击
		if (dwCurrTick < m_dwMonNormalAttackPrepareEndTick)
		{
			m_dwMonNormalAttackTakeEffectTick = 0;
		}
		//当前处于出招起手状态，则打断当前招式
		if (m_pCurrPosture && m_pCurrPosture->prepareTime > 0 
			&& dwCurrTick - m_dwCurrPostureStartTime < m_pCurrPosture->prepareTime)
		{
			breakPosture(m_pCurrPosture);
		}
	}
#endif
}

struct ShanBiBaoJiConfig
{
	double low;
	double high;
	double levelValue1;
	double levelValue2;
};

static const ShanBiBaoJiConfig g_ShanBiConfig = { 100, 7500, 100, 1500, };
static const ShanBiBaoJiConfig g_BaoJiConfig[2] = {
	{ 100, 5000, 100, 10000 },
	{ 100, 5000, 100, 10000 },
};

double CDoerBattle::decideDamageType(CDoer *sponsor, AttackPowerType pwrType)
{
	/* 闪避率=Min(闪避上限，Max(闪避下限，(10000×(防方闪避-攻方命中))/(防方闪避-攻方命中+等级系数×防方等级+等级参数))) */
	double shanBi = (m_pActor->m_Abil.shanBi - sponsor->m_Abil.mingZhong);
	shanBi = (10000 * shanBi) / (shanBi + g_ShanBiConfig.levelValue1 * m_pActor->m_nLevel + g_ShanBiConfig.levelValue2);
	shanBi = min(g_ShanBiConfig.high, max(g_ShanBiConfig.low, shanBi));
	/* 暴击率=Min(暴击上限，Max(暴击下限，(10000×(攻方暴击-防方暴抗))/(攻方暴击-防方暴抗+等级系数×攻方等级+等级参数))) */
	const ShanBiBaoJiConfig &bjConf = g_BaoJiConfig[pwrType];
	double baoJi = (pwrType == apOuter) ? (sponsor->m_Abil.waiBao - m_pActor->m_Abil.kangWaiBao) : (sponsor->m_Abil.neiBao - m_pActor->m_Abil.kangNeiBao);
	baoJi = (10000 * baoJi) / (baoJi + bjConf.levelValue1 * sponsor->m_nLevel + bjConf.levelValue2);
	baoJi = min(bjConf.high, max(bjConf.low, baoJi));

	//圆桌推算闪避、暴击或普通伤害
	double r = randValue((int)(g_ShanBiConfig.high + bjConf.high));
	//闪避
	if (r <= shanBi)
		return 0;
	//暴击
	else if (r >= g_ShanBiConfig.high  && r <= g_ShanBiConfig.high + baoJi)
		return 1.5;
	//普通
	return 1;
}

struct MianShangConfig
{
	double low;
	double high;
	double decremence;
	double levelValue;
};

static const MianShangConfig g_MianShang[2] = {
	{ 0.75, 0.01, 100, 5000 },
	{ 0.75, 0.01, 100, 5000 },
};

int CDoerBattle::calcDamageValue(CDoer *sponsor, AttackPowerType pwrType, int power)
{
	const DoerAbilData &abil = m_pActor->m_Abil;
	const double level = m_pActor->m_nLevel;
	const double defence = pwrType == apOuter ? abil.waiFang : abil.neiFang;
	const double defenceCT = pwrType == apOuter ? sponsor->m_Abil.waiFangCT : sponsor->m_Abil.neiFangCT;
	/* 免伤率=Min(免伤上限，Max(免伤下限，(防方防御-攻方防御穿透)/(防方防御-攻方防御穿透+等级衰减系数×防方等级+等级系数))) */
	const MianShangConfig &msConf = g_MianShang[pwrType];
	double mianShang = defence - defenceCT;
	mianShang = mianShang/(mianShang + msConf.decremence * m_pActor->m_nLevel + msConf.decremence);
	mianShang = min(msConf.high, max(msConf.low, mianShang));
	/* 防方福缘率=防方福缘值/(防方福缘值+等级*100+5000) */
	double fuYuan = abil.fuYuan / (abil.fuYuan + level * 100 + 5000);
	/* 攻击力=攻方攻击×(1-防方免伤率)×(1-防方福缘率)×r */
	double dmPower = power * (1 - mianShang) * (1 - fuYuan) * (0.75 + randValue(2500)*0.0001);
	/* 伤害=攻击力×技能伤害系数×暴击伤害系数 */
	return (int)dmPower;
}

bool CDoerBattle::calcNewPositionAtTime(TickTime dwTick, int &nNewX, int &nNewY)
{
	int newX = m_nRunStartX, newY = m_nRunStartY;
	int timeElapased = (int)(dwTick - m_dwRunStartTick);

	if (timeElapased > 0)
	{
		//加速度状态位置计算
		if (m_nRunAccelerateTime)
		{
			double secTime = (double)m_nRunAccelerateTime/1000.0;
			const double ax = (double)m_nRunSpeedX / secTime;
			const double ay = (double)m_nRunSpeedY / secTime;

			const int accTE = (timeElapased < m_nRunAccelerateTime) ? timeElapased : m_nRunAccelerateTime;
			timeElapased -= accTE;

			//t方
			secTime = (double)accTE / 1000.0;
			secTime = secTime * secTime;

			//加速度位置计算公式：l = at2/2
			newX += int(ax * secTime / 2);
			newY += int(ay * secTime / 2);

			//加速度时间结束，重新设置起跑时间并保存起跑位置
			if (accTE >= m_nRunAccelerateTime)
			{
				SkillUtil::fixMovePoint(m_pActor->m_pScene, m_nRunStartX, m_nRunStartY, newX, newY);
				m_dwRunStartTick += m_nRunAccelerateTime;
				m_dwClientRunStartTick += m_nRunAccelerateTime;
				m_nRunAccelerateTime = 0;
				m_nRunStartX = newX;
				m_nRunStartY = newY;
			}
		}

		//常规移动计算
		newX += (m_nRunSpeedX * timeElapased) / 1000;
		newY += (m_nRunSpeedY * timeElapased) / 1000;

		if (newX < 0) newX = 0;
		if (newX >= m_pActor->m_pScene->m_nMapWidth) newX = m_pActor->m_pScene->m_nMapWidth - 1;
		if (newY < 0) newY = 0;
		if (newY >= m_pActor->m_pScene->m_nMapHeight) newY = m_pActor->m_pScene->m_nMapHeight - 1;
	}

	bool result = SkillUtil::fixMovePoint(m_pActor->m_pScene, m_pActor->m_nX, m_pActor->m_nY, newX, newY);
	nNewX = newX;
	nNewY = newY;
	return result;
}

bool CDoerBattle::isAttackableActor(CDoer *target)
{
	if (!target)
		return false;
	if (target->m_pScene != m_pActor->m_pScene)
		return false;
	if (target->m_boDead || target->m_boDisappeared)
		return false;
	/*if (!FightUtil::isEnemyActor(m_pActor, target))
		return false;*/
	return true;
}

void CDoerBattle::setLastHiter(CDoer *sponsor)
{
	m_pLastHiter = sponsor;
	if (sponsor)
		m_dwLastHiterTimeOut = g_LogicEngine->getTickCount() + 30 * 1000;
	else m_dwLastHiterTimeOut = 0;
}

void CDoerBattle::setTargetActor(CDoer *target)
{
	if (m_pTargetActor != target)
	{
		m_pTargetActor = target;
	}
}

void CDoerBattle::setMoveTarget(int tx, int ty)
{
	if (tx != m_nTargetX || ty != m_nTargetY)
	{
		if (tx > -1 && ty > -1)
		{
			m_nTargetX = tx;
			m_nTargetY = ty;
		}
		else if (m_dwRunStartTick)
		{
			stopMove();
		}
	}
}

bool CDoerBattle::isAcceptablePositionFaultBit(int tx, int ty)
{
	return abs(tx - m_pActor->m_nX) <= 100 && abs(ty - m_pActor->m_nY) <= 100;
}

void CDoerBattle::updateRunState(TickTime dwCurrTick)
{
	int newX, newY;
	bool canMove = calcNewPositionAtTime(dwCurrTick, newX, newY);
	m_pActor->setXY(newX, newY);
	//如果前方不能移动则终止移动
	if (!canMove)
		stopMove();
}

void CDoerBattle::updateSkillTimePoints(TickTime currTime)
{
	const int count = (int)m_SkillTimeList.size();
	SkillTimePointState *timeStatus = m_SkillTimeList.start;
	for (int i=0; i<count; ++i)
	{
		SkillTimePointState &timeState = timeStatus[i];
		if (currTime >= timeState.nextTime)
		{
			SkillUtil::takeSkillTimePointEffect(m_pActor, timeState.timePoint);
			timeState.remainTwice--;
			if (timeState.remainTwice > 0)
			timeState.nextTime += timeState.timePoint->interval;
			else m_SkillTimeList.remove(i, 1);
		}
	}
}

void CDoerBattle::processPostures(TickTime currTime)
{
	const CFSkillPostureLevel *posture = m_pCurrPosture;
	if (posture)
	{
		if (currTime >= m_dwCurrPostureEndTime)
		{
			completePosture(posture);
			m_pCurrPosture = NULL;
		}
	}
	else if (currTime >= m_dwOutOfAttackEndTime)
	{
		m_wCurrPostureIndex ++ ;
		if (m_wCurrPostureIndex >= m_wCurrPostureCount)
		{
			completeAttack();
			stopAttack();
		}
		else
		{
			posture = m_CurrPostures[m_wCurrPostureIndex];
			launchPosture(posture, m_pActor->m_btDirection);
		}
	}

}

void CDoerBattle::launchPosture(const CFSkillPostureLevel *posture, int dir)
{
	m_dwCurrPostureStartTime = g_LogicEngine->getTickCount();
	int count = posture->numTimePoints;
	for (int i=0; i<count; ++i)
	{
		const CFSkillTimePoint *timePoint = posture->timePoints[i];
		SkillTimePointState *timeState = m_SkillTimeList.insert(m_SkillTimeList.size(), 1, false);
		timeState->timePoint = timePoint;
		timeState->nextTime = m_dwCurrPostureStartTime + timePoint->time;
		timeState->remainTwice = timePoint->repeat + 1;
	}

	int postureTime = posture->time;
	if (postureTime <= 0) postureTime = 240;
	m_dwCurrPostureEndTime = m_dwCurrPostureStartTime + postureTime;
	m_pCurrPosture = posture;
}

void CDoerBattle::breakPosture(const CFSkillPostureLevel *posture)
{
	const int postureId = posture->postureId;
	for (int i=(int)m_SkillTimeList.size()-1; i>-1; --i)
	{
		if (m_SkillTimeList[i].timePoint->postureId == postureId)
			m_SkillTimeList.remove(i, 1);
	}
}

void CDoerBattle::completePosture(const CFSkillPostureLevel *posture)
{
	m_pCurrPosture = NULL;
}

void CDoerBattle::completeAttack()
{
	
}

void CDoerBattle::takeMonNormalAttackEffect()
{
	m_dwMonNormalAttackPrepareEndTick = 0;
	m_dwMonNormalAttackTakeEffectTick = 0;

	const monsterStruct* pStdMon = g_ConfigManager->monsterDataAccessor.getMonsterById(m_pActor->m_wMonId);
	GRect rect;
	rect.y = m_pActor->m_nY + pStdMon->paTop;
	rect.height = pStdMon->paBottom - pStdMon->paTop;
	if (m_pActor->m_btDirection == 1)
		rect.x = m_pActor->m_nX + pStdMon->paLeft;
	else rect.x = m_pActor->m_nX - pStdMon->paRight;
	rect.width = pStdMon->paRight - pStdMon->paLeft;

	SkillUtil::takePowerAttackEffect(m_pActor, rect, (AttackPowerType)m_pActor->m_btAttackType, m_pActor->m_Abil.neiGong, 1);
}

 
