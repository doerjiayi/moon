#include "StdAfx.h"
#include "skillUtil.h"

namespace SkillUtil
{
	static CBList<CDoer*> ActorList1;

	void takeSkillTimePointEffect(CDoer *sponser, const CFSkillTimePoint *timePoint)
	{
		switch(timePoint->actType)
		{
		case CFSkillTimePoint::aWGAttack: takeSkillWGAttackEffect(sponser, timePoint); break;
		case CFSkillTimePoint::aNGAttack: takeSkillNGAttackEffect(sponser, timePoint); break;
		case CFSkillTimePoint::aUpturn: takeSkillUpturnEffect(sponser, timePoint); break;
		case CFSkillTimePoint::aPull: takeSkillPullEffect(sponser, timePoint); break;
		case CFSkillTimePoint::aKnockDown: takeSkillKnockDownEffect(sponser, timePoint); break;
		case CFSkillTimePoint::aSprint: takeSkillSprintDownEffect(sponser, timePoint); break;
		case CFSkillTimePoint::aRecoil: takeSkillRecoilEffect(sponser, timePoint); break;
		case CFSkillTimePoint::aSelfOutOfControl: takeSkillSelfOutOfControlEffect(sponser, timePoint); break;
		case CFSkillTimePoint::aTargetOutOfControl: takeSkillTargetOutOfControlEffect(sponser, timePoint); break;
		case CFSkillTimePoint::aShake: takeSkillShakeEffect(sponser, timePoint); break;
		}
	}

	void takePowerAttackEffect(CDoer *sponsor, const GRect &rect, AttackPowerType type, const int power, double rate)
	{
		const int count = getRangeActors(ActorList1, sponsor, rect, afEnemy);
		CDoer **actorList = ActorList1;
		for (int i=0; i<count; ++i)
		{
			CDoer *actor = actorList[i];
			if (actor->m_boDead)
				continue;
			actor->m_Battle.struck(sponsor, type, power, rate);
		}
		ActorList1.trunc(0);
	}

	void takeSkillWGAttackEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center)
	{
		GRect rect;
		timeRect2GameRect(rect, sponsor, center ? center : (GPoint*)&sponsor->m_nX, timePoint);
		const int power = sponsor->m_Abil.waiGong + timePoint->actValue1.n;
		takePowerAttackEffect(sponsor, rect, apOuter, power, timePoint->actValue2.d);
	}

	void takeSkillNGAttackEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center)
	{
		GRect rect;
		timeRect2GameRect(rect, sponsor, center ? center : (GPoint*)&sponsor->m_nX, timePoint);
		const int power = sponsor->m_Abil.neiGong + timePoint->actValue1.n;
		takePowerAttackEffect(sponsor, rect, apInner, power, timePoint->actValue2.d);
	}

	void takeSkillUpturnEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center)
	{

	}

	void takeSkillPullEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center)
	{

	}

	void takeSkillKnockDownEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center)
	{
		GRect rect;
		timeRect2GameRect(rect, sponsor, center ? center : (GPoint*)&sponsor->m_nX, timePoint);
		const int count = getRangeActors(ActorList1, sponsor, rect, afEnemy);
		CDoer **actorList = ActorList1;
		for (int i=0; i<count; ++i)
		{
			CDoer *actor = actorList[i];
			if (actor->m_boDead)
				continue;
			actor->m_Battle.collapse(timePoint->actValue1.n);
		}
		ActorList1.trunc(0);
	}

	void takeSkillSprintDownEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center)
	{

	}

	void takeSkillRecoilEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center)
	{

	}

	void takeSkillSelfOutOfControlEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center)
	{
		sponsor->m_Battle.outOfControl(timePoint->actValue1.n, timePoint->actValue2.n);
	}

	void takeSkillTargetOutOfControlEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center)
	{
		static CBList<CDoer*> list;

		GRect rect;
		timeRect2GameRect(rect, sponsor, center ? center : (GPoint*)&sponsor->m_nX, timePoint);

		const int count = getRangeActors(list, sponsor, rect, afEnemy);
		CDoer **actorList = list;
		for (int i=0; i<count; ++i)
		{
			CDoer *actor = actorList[i];
			if (actor == sponsor || actor->m_boDead)
				continue;
			actor->m_Battle.outOfControl(timePoint->actValue1.n, timePoint->actValue2.n);
		}
		list.trunc(0);
	}

	void takeSkillShakeEffect(CDoer *sponsor, const CFSkillTimePoint *timePoint, const GPoint *center)
	{

	}
}
