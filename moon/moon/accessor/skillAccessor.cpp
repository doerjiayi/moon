#include "StdAfx.h"
#include "config/configManager.h"

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

SkillProviderAccessor::SkillProviderAccessor():super()
{

}

SkillProviderAccessor::~SkillProviderAccessor()
{

}

const CFSkill* SkillProviderAccessor::getSkillById(const int id) const
{
	return m_SkillList[id];
}

const CFSkill* SkillProviderAccessor::getSkillByName(const moon::String& name) const
{
	const moon::String::TYPE *namePtr = name.ptr();
	const CFSkill *const* skillList = m_SkillList.ptr();
	const int count = (int)m_SkillList.length();
	for (int i=0; i<count; ++i)
	{
		if (strcmp(skillList[i]->name, namePtr) == 0)
			return skillList[i];
	}
	return NULL;
}

const CFSkillPosture* SkillProviderAccessor::getPostureById(const int id) const
{
	return m_PostureList[id];
}

const CFSkillPosture* SkillProviderAccessor::getPostureByName(const moon::String& name) const
{
	const moon::String::TYPE *namePtr = name.ptr();
//	const CFSkillPosture *const* postureList = m_PostureList.ptr();
	const uint32 count = (uint32)m_PostureList.length();
	for (uint32 i=0; i<count; ++i)
	{
		if (strcmp(m_PostureList[i]->name, namePtr) == 0)
			return m_PostureList[i];
	}
	return NULL;
}

bool SkillProviderAccessor::loadConfig()
{
#if 0
	CSVDocument doc;

#define DCL(name, fn) {\
	if (!CConfigManager::LoadCSVDocument(doc, "./config/"name))\
		return false;\
	fn(doc); }

	DCL("skill/StdSkill.csv", readStdSkills);
	DCL("skill/SkillLevel.csv", readSkillLevels);
	DCL("skill/Posture.csv", readPostures);
	DCL("skill/PostureLevel.csv", readPostureLevels);
	DCL("skill/TimePoint.csv", readTimePoints);
#endif
	return true;
}
#if 0
void SkillProviderAccessor::readStdSkills(CSVDocument &doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE6\x8A\x80\xE8\x83\xBDID"));
	int cName = doc.getColumnIndex(UTF8String("\xE5\x90\x8D\xE7\xA7\xB0"));
	int cIcon = doc.getColumnIndex(UTF8String("\xE5\x9B\xBE\xE6\xA0\x87"));
	int cJob = doc.getColumnIndex(UTF8String("\xE8\x81\x8C\xE4\xB8\x9A"));

	int maxId = 0;
	const int totalCount = (int)doc.numRows();
	StdSkill *skillList = m_Allocator.Alloc<StdSkill>(totalCount);
	for (int i=0; i<totalCount; ++i)
	{
		StdSkill *skill = &skillList[i];
		skill->id = doc.getValue(i, cId);
		skill->name = m_Allocator.AllocStr(doc.getValue(i, cName));
		skill->icon = doc.getValue(i, cIcon);
		skill->job = doc.getValue(i, cJob);
		maxId = max(maxId, skill->id);
	}

	m_SkillList.setLength(maxId + 1);
	memset(m_SkillList.own_ptr(), 0, sizeof(m_SkillList.ptr()[0]) * (maxId + 1));
	StdSkill **skillPointerList = m_SkillList.own_ptr();
	for (int i=0; i<totalCount; ++i)
	{
		StdSkill *skill = &skillList[i];
		skillPointerList[skill->id] = skill;
	}
}

void SkillProviderAccessor::readSkillLevels(CSVDocument &doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE6\x8A\x80\xE8\x83\xBDID"));
	int cLevel = doc.getColumnIndex(UTF8String("\xE7\xAD\x89\xE7\xBA\xA7"));
	int cTrainLevel = doc.getColumnIndex(UTF8String("\xE5\xAD\xA6\xE4\xB9\xA0\xE7\xAD\x89\xE7\xBA\xA7"));
	int cTrainCoin = doc.getColumnIndex(UTF8String("\xE5\xAD\xA6\xE4\xB9\xA0\xE9\x93\xB6\xE4\xB8\xA4"));
	int cTrainGold = doc.getColumnIndex(UTF8String("\xE5\xAD\xA6\xE4\xB9\xA0\xE5\x85\x83\xE5\xAE\x9D"));
	int cGuildSkill = doc.getColumnIndex(UTF8String("\xE5\xB8\xAE\xE4\xBC\x9A\xE6\x8A\x80\xE8\x83\xBD"));
	int cSpellHP = doc.getColumnIndex(UTF8String("\xE4\xBD\xBF\xE7\x94\xA8\xE4\xBD\x93\xE5\x8A\x9B"));
	int cSpellMP = doc.getColumnIndex(UTF8String("\xE4\xBD\xBF\xE7\x94\xA8\xE6\xB0\x94\xE5\x8A\x9B"));
	int cDesc = doc.getColumnIndex(UTF8String("\xE6\x8F\x8F\xE8\xBF\xB0"));

	StdSkill **skillList = m_SkillList.own_ptr();
	const int maxSkillId = (int)m_SkillList.length() - 1;

	const int totalCount = (int)doc.numRows();
	StdSkillLeve *levels = m_Allocator.Alloc<StdSkillLeve>(totalCount);
	for (int i=0; i<totalCount; ++i)
	{
		StdSkillLeve *level = &levels[i];
		level->skillId = doc.getValue(i, cId);
		if (level->skillId <= maxSkillId && skillList[level->skillId])
		{
			level->level = (int)doc.getValue(i, cLevel) - 1;
			if (level->level >= 0)
			{
				level->trainCond.level = doc.getValue(i, cTrainLevel);
				level->trainCond.coin = doc.getValue(i, cTrainCoin);
				level->trainCond.gold = doc.getValue(i, cTrainGold);
				level->spellCond.mp = doc.getValue(i, cSpellHP);
				level->spellCond.hp = doc.getValue(i, cSpellMP);
				level->desc = m_Allocator.AllocStr(doc.getValue(i, cDesc).s);
				int numLevel = skillList[level->skillId]->numLevels;
				skillList[level->skillId]->numLevels = max(numLevel, level->level + 1);
			}
			else level->skillId = 0;
		}
		else level->skillId = 0;
	}

	//将技能等级添加到技能对象中
	for (int i=0; i<totalCount; ++i)
	{
		StdSkillLeve *level = &levels[i];
		if (level->skillId > 0)
		{
			StdSkill *skill = skillList[level->skillId];
			if (!skill->levels) skill->levels = m_Allocator.Alloc<StdSkillLeve*>(skill->numLevels);
			skill->levels[level->level] = level; 
		}
	}
}

void SkillProviderAccessor::readPostures(CSVDocument &doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE6\x8B\x9B\xE5\xBC\x8FID"));
	int cName = doc.getColumnIndex(UTF8String("\xE5\x90\x8D\xE7\xA7\xB0"));
	int cOwnSkill = doc.getColumnIndex(UTF8String("\xE6\x89\x80\xE5\xB1\x9E\xE6\x8A\x80\xE8\x83\xBD"));
	int cPos = doc.getColumnIndex(UTF8String("\xE6\x89\x80\xE5\x9C\xA8\xE4\xBD\x8D\xE7\xBD\xAE"));
	int cIcon = doc.getColumnIndex(UTF8String("\xE5\x9B\xBE\xE6\xA0\x87"));

	StdSkill **skillList = m_SkillList.own_ptr();
	const int maxSkillId = (int)m_SkillList.length() - 1;
	int maxPostureId = 0;

	const int totalCount = (int)doc.numRows();
	CFSkillPosture *postures = m_Allocator.Alloc<CFSkillPosture>(totalCount);
	for (int i=0; i<totalCount; ++i)
	{
		CFSkillPosture *posture = &postures[i];
		posture->skillId = doc.getValue(i, cOwnSkill);
		if (posture->skillId <= maxSkillId && skillList[posture->skillId])
		{
			posture->pos = doc.getValue(i, cPos);
			if (posture->pos > 0)
			{
				posture->id = doc.getValue(i, cId);
				posture->icon = doc.getValue(i, cIcon);
				posture->name = m_Allocator.AllocStr(doc.getValue(i, cName));
				int numPos = skillList[posture->skillId]->numPostures;
				skillList[posture->skillId]->numPostures = max(posture->pos, numPos);
				posture->pos--;
				maxPostureId = max(maxPostureId, posture->id);
			}
			else posture->skillId = 0;
		}
		else posture->skillId = 0;
	}

	//将招式添加到招式ID列表中
	m_PostureList.setLength(maxPostureId + 1);
	memset(m_PostureList.own_ptr(), 0, sizeof(m_PostureList.ptr()[0]) * (maxPostureId + 1));
	CFSkillPosture **postureList = m_PostureList.own_ptr();
	for (int i=0; i<totalCount; ++i)
	{
		CFSkillPosture *posture = &postures[i];
		postureList[posture->id] = posture;
	}

	//将招式添加到技能对象中
	for (int i=0; i<totalCount; ++i)
	{
		CFSkillPosture *posture = &postures[i];
		if (posture->skillId > 0)
		{
			StdSkill *skill = skillList[posture->skillId];
			if (!skill->postures) skill->postures = m_Allocator.Alloc<CFSkillPosture*>(skill->numPostures);
			skill->postures[posture->pos] = posture; 
		}
	}
}

void SkillProviderAccessor::readPostureLevels(CSVDocument &doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE6\x8B\x9B\xE5\xBC\x8FID"));
	int cLevel = doc.getColumnIndex(UTF8String("\xE7\xAD\x89\xE7\xBA\xA7"));
	int cAction = doc.getColumnIndex(UTF8String("\xE6\x94\xBB\xE5\x87\xBB\xE5\x8A\xA8\xE4\xBD\x9C"));
	int cTime = doc.getColumnIndex(UTF8String("\xE6\x97\xB6\xE9\x97\xB4"));
	int cOATime = doc.getColumnIndex(UTF8String("\xE6\x94\xBB\xE5\x87\xBB\xE7\xA1\xAC\xE7\x9B\xB4\xE6\x97\xB6\xE9\x97\xB4"));
	int cOMTime = doc.getColumnIndex(UTF8String("\xE7\xA7\xBB\xE5\x8A\xA8\xE7\xA1\xAC\xE7\x9B\xB4\xE6\x97\xB6\xE9\x97\xB4"));
	int cPrepareTime = doc.getColumnIndex(UTF8String("\xE8\xB5\xB7\xE6\x89\x8B\xE6\x97\xB6\xE9\x97\xB4"));
	int cTrainLevel = doc.getColumnIndex(UTF8String("\xE5\xAD\xA6\xE4\xB9\xA0\xE7\xAD\x89\xE7\xBA\xA7"));
	int cTrainCion = doc.getColumnIndex(UTF8String("\xE5\xAD\xA6\xE4\xB9\xA0\xE9\x93\xB6\xE4\xB8\xA4"));
	int cTrainGold = doc.getColumnIndex(UTF8String("\xE5\xAD\xA6\xE4\xB9\xA0\xE5\x85\x83\xE5\xAE\x9D"));
	int cSpellHP = doc.getColumnIndex(UTF8String("\xE4\xBD\xBF\xE7\x94\xA8\xE4\xBD\x93\xE5\x8A\x9B"));
	int cSpellMP = doc.getColumnIndex(UTF8String("\xE4\xBD\xBF\xE7\x94\xA8\xE6\xB0\x94\xE5\x8A\x9B"));
	int cDesc = doc.getColumnIndex(UTF8String("\xE6\x8F\x8F\xE8\xBF\xB0"));

	const int maxPostureId = (int)m_PostureList.length() - 1;
	CFSkillPosture **postureList = m_PostureList.own_ptr();

	const int totalCount = (int)doc.numRows();
	StdSkillPostureLevel *levels = m_Allocator.Alloc<StdSkillPostureLevel>(totalCount);
	for (int i=0; i<totalCount; ++i)
	{
		StdSkillPostureLevel *level = &levels[i];
		level->postureId = doc.getValue(i, cId);
		if (level->postureId <= maxPostureId && postureList[level->postureId])
		{
			level->level = (int)doc.getValue(i, cLevel) - 1;
			if (level->level >= 0)
			{
				level->actionIndex = doc.getValue(i, cAction);
				level->time = (unsigned short)((float)doc.getValue(i, cTime) * 1000);
				level->oaTime = (unsigned short)((float)doc.getValue(i, cOATime) * 1000);
				level->omTime = (unsigned short)((float)doc.getValue(i, cOMTime) * 1000);
				level->prepareTime = (unsigned short)((float)doc.getValue(i, cPrepareTime) * 1000);
				level->trainCond.level = doc.getValue(i, cTrainLevel);
				level->trainCond.coin = doc.getValue(i, cTrainCion);
				level->trainCond.gold = doc.getValue(i, cTrainGold);
				level->spellCond.hp = doc.getValue(i, cSpellHP);
				level->spellCond.mp = doc.getValue(i, cSpellMP);
				level->desc = m_Allocator.AllocStr(doc.getValue(i, cDesc).s);
				int numLevels = postureList[level->postureId]->numLevels;
				postureList[level->postureId]->numLevels = max(numLevels, level->level + 1);
			}
			else level->postureId = 0;
		}
		else level->postureId = 0;
	}

	//将招式等级应用到对应招式的等级列表中
	for (int i=0; i<totalCount; ++i)
	{
		StdSkillPostureLevel *level = &levels[i];
		if (level->postureId > 0)
		{
			CFSkillPosture *posture = postureList[level->postureId];
			if (!posture->levels) posture->levels = m_Allocator.Alloc<StdSkillPostureLevel*>(posture->numLevels);
			posture->levels[level->level] = level; 
		}
	}
}

void SkillProviderAccessor::readTimePoints(CSVDocument &doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE6\x8B\x9B\xE5\xBC\x8FID"));
	int cLevel = doc.getColumnIndex(UTF8String("\xE6\x8B\x9B\xE5\xBC\x8F\xE7\xAD\x89\xE7\xBA\xA7"));
	int cTime = doc.getColumnIndex(UTF8String("\xE6\x97\xB6\xE9\x97\xB4"));
	int cRepeat = doc.getColumnIndex(UTF8String("\xE9\x87\x8D\xE5\xA4\x8D"));
	int cInterval = doc.getColumnIndex(UTF8String("\xE9\x97\xB4\xE9\x9A\x94"));
	int cAct = doc.getColumnIndex(UTF8String("\xE4\xBD\x9C\xE7\x94\xA8"));
	int cV1 = doc.getColumnIndex(UTF8String("\xE5\x80\xBC\x31"));
	int cV2 = doc.getColumnIndex(UTF8String("\xE5\x80\xBC\x32"));
	int cLeft = doc.getColumnIndex(UTF8String("L"));
	int cRight = doc.getColumnIndex(UTF8String("R"));
	int cTop = doc.getColumnIndex(UTF8String("T"));
	int cBottom = doc.getColumnIndex(UTF8String("B"));

	const int maxPostureId = (int)m_PostureList.length() - 1;
	CFSkillPosture **postureList = m_PostureList.own_ptr();

	const int totalCount = (int)doc.numRows();
	StdSkillTimePoint *times = m_Allocator.Alloc<StdSkillTimePoint>(totalCount);
	for (int i=0; i<totalCount; ++i)
	{
		StdSkillTimePoint *time = &times[i];
		time->postureId = doc.getValue(i, cId);
		if (time->postureId <= maxPostureId && postureList[time->postureId])
		{
			time->level = (int)doc.getValue(i, cLevel) - 1;
			if (time->level >= 0 && time->level < postureList[time->postureId]->numLevels)
			{
				time->time = (unsigned short)((float)doc.getValue(i, cTime) * 1000);
				time->repeat = doc.getValue(i, cRepeat);
				time->interval = (unsigned short)((float)doc.getValue(i, cInterval) * 1000);
				const String actName = doc.getValue(i, cAct);
				const String::TYPE *sActName = actName.ptr();
				if (sActName)
				{
					if (sActName[0] == 'W' && sActName[1] == 'G')
					{
						time->actType = StdSkillTimePoint::aWGAttack;
						time->actValue1.n = doc.getValue(i, cV1);
						time->actValue2.d = doc.getValue(i, cV2);
					}
					else if (sActName[0] == 'N' && sActName[1] == 'G')
					{
						time->actType = StdSkillTimePoint::aNGAttack;
						time->actValue1.n = doc.getValue(i, cV1);
						time->actValue2.d = doc.getValue(i, cV2);
					}
					else if (sActName[0] == 'U' && sActName[1] == 'T')
					{
						time->actType = StdSkillTimePoint::aUpturn;
						time->actValue1.n = doc.getValue(i, cV1);
					}
					else if (sActName[0] == 'P' && sActName[1] == 'L')
					{
						time->actType = StdSkillTimePoint::aPull;
						time->actValue1.n = doc.getValue(i, cV1);
					}
					else if (sActName[0] == 'K' && sActName[1] == 'D')
					{
						time->actType = StdSkillTimePoint::aKnockDown;
						time->actValue1.n = (int)((double)doc.getValue(i, cV1) * 1000);
					}
					else if (sActName[0] == 'S' && sActName[1] == 'P')
					{
						time->actType = StdSkillTimePoint::aSprint;
						time->actValue1.n = doc.getValue(i, cV1);
						time->actValue2.n = doc.getValue(i, cV2);
					}
					else if (sActName[0] == 'R' && sActName[1] == 'C')
					{
						time->actType = StdSkillTimePoint::aRecoil;
						time->actValue1.d = doc.getValue(i, cV1);
						time->actValue2.n = doc.getValue(i, cV2);
					}
					else if (sActName[0] == 'O' && sActName[1] == 'C')
					{
						time->actType = StdSkillTimePoint::aSelfOutOfControl;
						time->actValue1.n = (int)((double)doc.getValue(i, cV1) * 1000);
						time->actValue2.n = (int)((double)doc.getValue(i, cV2) * 1000);
					}
					else if (sActName[0] == 'O' && sActName[1] == 'T')
					{
						time->actType = StdSkillTimePoint::aTargetOutOfControl;
						time->actValue1.n = (int)((double)doc.getValue(i, cV1) * 1000);
						time->actValue2.n = (int)((double)doc.getValue(i, cV2) * 1000);
					}
					else if (sActName[0] == 'S' && sActName[1] == 'K')
					{
						time->actType = StdSkillTimePoint::aShake;
						time->actValue2.n = doc.getValue(i, cV2);
					}
				}
				if (time->actType == 0)
				{
					time->postureId = 0;
					continue;;
				}
				time->left = doc.getValue(i, cLeft);
				time->top = doc.getValue(i, cTop);
				time->right = doc.getValue(i, cRight);
				time->bottom = doc.getValue(i, cBottom);

				StdSkillPostureLevel *level = postureList[time->postureId]->levels[time->level];
				time->index = level->numTimePoints;
				level->numTimePoints++;
			}
			else time->postureId = 0;
		}
		else time->postureId = 0;
	}

	//将招式等级应用到对应招式的等级列表中
	for (int i=0; i<totalCount; ++i)
	{
		StdSkillTimePoint *time = &times[i];
		if (time->postureId > 0)
		{
			StdSkillPostureLevel *level = postureList[time->postureId]->levels[time->level];
			if (!level->timePoints) level->timePoints = m_Allocator.Alloc<StdSkillTimePoint*>(level->numTimePoints);
			level->timePoints[time->index] = time;
		}
	}

}
#endif
