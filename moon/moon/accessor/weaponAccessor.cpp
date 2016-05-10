#include "StdAfx.h"
#include "config/configManager.h"

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

WeaponAccessor::WeaponAccessor():super()
{

}

WeaponAccessor::~WeaponAccessor()
{

}

const CFBead* WeaponAccessor::getBeadById(uint32 id) const
{
	return m_BeadList[id];
}

const CFWeapon* WeaponAccessor::getWeaponById(uint8 id) const
{
	return m_WeaponList[id];
}

const StdBeadQuality* WeaponAccessor::getBeadQuality(uint8 quality) const
{
	return m_BeadAttriList[quality];
}
#if 0
bool StdWeaponProvider::loadConfig()
{
	CSVDocument doc;

#define DCL(name, fn) {\
	if (!CConfigManager::LoadCSVDocument(doc, "./config/"name))\
	return false;\
	fn(doc); }

	DCL("weapon/StdWeapon.csv", readStdWeapon);
	DCL("weapon/WeaponLevel.csv", readWeaponLevels);
	DCL("weapon/WeaponHole.csv", readWeaponHoles);
	DCL("weapon/StdBead.csv", readStdBead);
	DCL("weapon/BeadLevel.csv", readBeadLevels);
	DCL("weapon/BeadAttribute.csv", readBeadAttributes);

	return true;
}

void StdWeaponProvider::readStdWeapon(SG2DEX::CSVDocument &doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE6\xAD\xA6\xE5\x99\xA8ID"));
	int cJob = doc.getColumnIndex(UTF8String("\xE8\x81\x8C\xE4\xB8\x9A\xE7\xB1\xBB\xE5\x9E\x8B"));
	int cType = doc.getColumnIndex(UTF8String("\xE6\xAD\xA6\xE5\x99\xA8\xE7\xB1\xBB\xE5\x9E\x8B"));

	int maxId = 0;
	const int totalCount = (int)doc.numRows();
	CFWeapon *weaponList = m_Allocator.Alloc<CFWeapon>(totalCount);
	for (int i=0; i<totalCount; ++i)
	{
		CFWeapon *weapon = &weaponList[i];
		weapon->id = doc.getValue(i, cId);
		weapon->job = doc.getValue(i, cJob);
		weapon->wtype = doc.getValue(i, cType);
		maxId = max(maxId, weapon->id);
	}

	m_WeaponList.setLength(maxId + 1);
	memset(m_WeaponList.own_ptr(), 0, sizeof(m_WeaponList.ptr()[0]) * (maxId + 1));
	CFWeapon **weaponPointerList = m_WeaponList.own_ptr();
	for (int i=0; i<totalCount; ++i)
	{
		CFWeapon *weapon = &weaponList[i];
		weaponPointerList[weapon->id] = weapon;
	}
}

void StdWeaponProvider::readWeaponLevels(SG2DEX::CSVDocument &doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE6\xAD\xA6\xE5\x99\xA8ID"));
	int cLevel = doc.getColumnIndex(UTF8String("\xE7\xAD\x89\xE7\xBA\xA7"));
	int cBaseAttrType = doc.getColumnIndex(UTF8String("\xE5\x9F\xBA\xE7\xA1\x80\xE5\xB1\x9E\xE6\x80\xA7\xE7\xB1\xBB\xE5\x9E\x8B"));
	int cBaseAttrValue = doc.getColumnIndex(UTF8String("\xE5\x9F\xBA\xE7\xA1\x80\xE5\xB1\x9E\xE6\x80\xA7\xE5\x80\xBC"));
	int cSoulEater = doc.getColumnIndex(UTF8String("\xE5\x90\x9E\xE5\x99\xAC\xE5\x80\xBC"));
	int cSoulUpgrade = doc.getColumnIndex(UTF8String("\xE5\x8D\x87\xE7\xBA\xA7\xE6\xAD\xA6\xE9\xAD\x82\xE5\x80\xBC"));
	int cSoulMax = doc.getColumnIndex(UTF8String("\xE6\x9C\x80\xE5\xA4\xA7\xE6\xAD\xA6\xE9\xAD\x82\xE5\x80\xBC"));
	int cFigure = doc.getColumnIndex(UTF8String("\xE5\xA4\x96\xE5\xBD\xA2"));
	int cName = doc.getColumnIndex(UTF8String("\xE5\x90\x8D\xE7\xA7\xB0"));
	int cDesc = doc.getColumnIndex(UTF8String("\xE6\x8F\x8F\xE8\xBF\xB0"));

	CFWeapon **weaponList = m_WeaponList.own_ptr();
	const int maxWeaponId = (int)m_WeaponList.length() - 1;

	const int totalCount = (int)doc.numRows();
	CFWeaponLevel *levels = m_Allocator.Alloc<CFWeaponLevel>(totalCount);
	for (int i=0; i<totalCount; ++i)
	{
		CFWeaponLevel *level = &levels[i];
		level->id = doc.getValue(i, cId);
		if (level->id <= maxWeaponId && weaponList[level->id])
		{
			level->level = (int)doc.getValue(i, cLevel);
			if (level->level > 0)
			{
				level->basicAttriType = doc.getValue(i, cBaseAttrType);
				level->basicAttriValue = doc.getValue(i, cBaseAttrValue);
				level->soulEater = doc.getValue(i, cSoulEater);
				level->eternalUpgrade = doc.getValue(i, cSoulUpgrade);
				level->eternalMax = doc.getValue(i, cSoulMax);
				level->figure = doc.getValue(i, cFigure);
				level->name = m_Allocator.AllocStr(doc.getValue(i, cName).s);
				level->desc = m_Allocator.AllocStr(doc.getValue(i, cDesc).s);
				int numLevel = weaponList[level->id]->numLevels;
				weaponList[level->id]->numLevels = max(numLevel, level->level + 1);
			}
			else
			{
				level->id = 0;
			}
		}
		else
		{
			level->id = 0;
		}
	}

	//将武器等级添加到武器对象中
	for (int i=0; i<totalCount; ++i)
	{
		CFWeaponLevel *level = &levels[i];
		if (level->id > 0)
		{
			CFWeapon *weapon = weaponList[level->id];
			if (!weapon->levels) weapon->levels = m_Allocator.Alloc<CFWeaponLevel*>(weapon->numLevels);
			weapon->levels[level->level] = level; 
		}
	}
}

void StdWeaponProvider::readWeaponHoles(SG2DEX::CSVDocument &doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE6\xAD\xA6\xE5\x99\xA8ID"));
	int cHoleId = doc.getColumnIndex(UTF8String("\xE6\xAD\xA6\xE5\x99\xA8\xE5\xAD\x94\xE5\x8F\xB7"));
	int cOpenLevel = doc.getColumnIndex(UTF8String("\xE5\xBC\x80\xE6\x94\xBE\xE7\xAD\x89\xE7\xBA\xA7"));
	int cActiveType = doc.getColumnIndex(UTF8String("\xE6\xBF\x80\xE6\xB4\xBB\xE9\x9C\x80\xE8\xB4\xA7\xE5\xB8\x81\xE7\xB1\xBB\xE5\x9E\x8B"));
	int cActiveCost = doc.getColumnIndex(UTF8String("\xE6\xBF\x80\xE6\xB4\xBB\xE9\x9C\x80\xE8\xB4\xA7\xE5\xB8\x81\xE5\x80\xBC"));
	int cItemId = doc.getColumnIndex(UTF8String("\xE6\xBF\x80\xE6\xB4\xBB\xE9\x9C\x80\xE7\x89\xA9\xE5\x93\x81ID"));
	int cItemNum = doc.getColumnIndex(UTF8String("\xE6\xBF\x80\xE6\xB4\xBB\xE9\x9C\x80\xE7\x89\xA9\xE5\x93\x81\xE6\x95\xB0\xE9\x87\x8F"));
	int cAddAttrType = doc.getColumnIndex(UTF8String("\xE5\x8A\xA0\xE6\x88\x90\xE7\xB1\xBB\xE5\x9E\x8B"));
	int cAddAttrRatio = doc.getColumnIndex(UTF8String("\xE5\x8A\xA0\xE6\x88\x90\xE6\xAF\x94\xE4\xBE\x8B"));
	int cName = doc.getColumnIndex(UTF8String("\xE6\xAD\xA6\xE5\x99\xA8\xE5\xAD\x94\xE5\x90\x8D"));

	CFWeapon **weaponList = m_WeaponList.own_ptr();
	const int maxWeaponId = (int)m_WeaponList.length() - 1;

	const int totalCount = (int)doc.numRows();
	CFWeaponHole *holes = m_Allocator.Alloc<CFWeaponHole>(totalCount);
	for (int i=0; i<totalCount; ++i)
	{
		CFWeaponHole *hole = &holes[i];
		hole->id = doc.getValue(i, cId);
		if (hole->id <= maxWeaponId && weaponList[hole->id])
		{
			hole->holeId = (int)doc.getValue(i, cHoleId);
			if (hole->holeId >= 0)
			{
				hole->openLevel = doc.getValue(i, cOpenLevel);
				hole->activeType = doc.getValue(i, cActiveType);
				hole->activeCost = doc.getValue(i, cActiveCost);
				hole->itemId = doc.getValue(i, cItemId);
				hole->itemCost = doc.getValue(i, cItemNum);
				hole->addAttriType = doc.getValue(i, cAddAttrType);
				hole->addAttriRate = doc.getValue(i, cAddAttrRatio);
				hole->name = m_Allocator.AllocStr(doc.getValue(i, cName).s);
				int numHole = weaponList[hole->id]->numHoles;
				weaponList[hole->id]->numHoles = max(numHole, hole->holeId + 1);
			}
			else
			{
				hole->id = 0;
			}
		}
		else
		{
			hole->id = 0;
		}

	}

	//将武器孔添加到武器对象中
	for (int i=0; i<totalCount; ++i)
	{
		CFWeaponHole *hole = &holes[i];
		if (hole->id > 0)
		{
			CFWeapon *weapon = weaponList[hole->id];
			if (!weapon->holes) weapon->holes = m_Allocator.Alloc<CFWeaponHole*>(weapon->numHoles);
			weapon->holes[hole->holeId] = hole; 
		}
	}
}

void StdWeaponProvider::readStdBead(SG2DEX::CSVDocument &doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE7\x81\xB5\xE7\x8F\xA0ID"));
	int cType = doc.getColumnIndex(UTF8String("\xE7\x81\xB5\xE7\x8F\xA0\xE7\xB1\xBB\xE5\x9E\x8B"));
	int cAddLevel = doc.getColumnIndex(UTF8String("\xE9\x99\x84\xE5\x8A\xA0\xE5\xB1\x9E\xE6\x80\xA7\xE5\xBC\x80\xE5\x90\xAF\xE7\xAD\x89\xE7\xBA\xA7"));
	int cName = doc.getColumnIndex(UTF8String("\xE7\x81\xB5\xE7\x8F\xA0\xE5\x90\x8D\xE5\xAD\x97"));
	int cDesc = doc.getColumnIndex(UTF8String("\xE6\x8F\x8F\xE8\xBF\xB0"));
	int cQuality = doc.getColumnIndex(UTF8String("\xE5\xB1\x9E\xE6\x80\xA7\xE5\x93\x81\xE8\xB4\xA8"));
	int cEleAttrType = doc.getColumnIndex(UTF8String("\xE5\x85\x83\xE7\xB4\xA0\xE4\xBC\xA4\xE5\xAE\xB3\xE7\xB1\xBB\xE5\x9E\x8B"));
	int cEleAttrMin = doc.getColumnIndex(UTF8String("\xE5\x85\x83\xE7\xB4\xA0\xE4\xBC\xA4\xE5\xAE\xB3\xE7\xB3\xBB\xE6\x95\xB0\xE4\xB8\x8B\xE9\x99\x90"));
	int cEleAttrMax = doc.getColumnIndex(UTF8String("\xE5\x85\x83\xE7\xB4\xA0\xE4\xBC\xA4\xE5\xAE\xB3\xE7\xB3\xBB\xE6\x95\xB0\xE4\xB8\x8A\xE9\x99\x90"));

	int maxId = 0;
	const int totalCount = (int)doc.numRows();
	CFBead *beadList = m_Allocator.Alloc<CFBead>(totalCount);
	for (int i=0; i<totalCount; ++i)
	{
		CFBead *bead = &beadList[i];
		bead->id = doc.getValue(i, cId);
		bead->btype = doc.getValue(i, cType);
		bead->attrQulity = doc.getValue(i, cQuality);
		bead->activeAttrLevel = doc.getValue(i, cAddLevel);
		bead->name = m_Allocator.AllocStr(doc.getValue(i, cName).s);
		bead->desc = m_Allocator.AllocStr(doc.getValue(i, cDesc).s);
		bead->eleAttriType = doc.getValue(i, cEleAttrType);
		bead->minEleRatio = doc.getValue(i, cEleAttrMin);
		bead->maxEleRatio = doc.getValue(i, cEleAttrMax);
		maxId = max(maxId, bead->id);
	}

	m_BeadList.setLength(maxId + 1);
	memset(m_BeadList.own_ptr(), 0, sizeof(m_BeadList.ptr()[0]) * (maxId + 1));
	CFBead **beadPointerList = m_BeadList.own_ptr();
	for (int i=0; i<totalCount; ++i)
	{
		CFBead *bead = &beadList[i];
		beadPointerList[bead->id] = bead;
	}
}

void StdWeaponProvider::readBeadLevels(SG2DEX::CSVDocument &doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE7\x81\xB5\xE7\x8F\xA0ID"));
	int cLevel = doc.getColumnIndex(UTF8String("\xE5\x85\x83\xE7\xB4\xA0\xE4\xBC\xA4\xE5\xAE\xB3\xE7\xB3\xBB\xE6\x95\xB0\xE4\xB8\x8B\xE9\x99\x90\xE7\xAD\x89\xE7\xBA\xA7"));
	int cBaseAttrType = doc.getColumnIndex(UTF8String("\xE5\x9F\xBA\xE7\xA1\x80\xE5\xB1\x9E\xE6\x80\xA7\xE7\xB1\xBB\xE5\x9E\x8B"));
	int cBaseAttrMin = doc.getColumnIndex(UTF8String("\xE5\x9F\xBA\xE7\xA1\x80\xE5\xB1\x9E\xE6\x80\xA7\xE5\x80\xBC\xE4\xB8\x8B\xE9\x99\x90"));
	int cBaseAttrMax = doc.getColumnIndex(UTF8String("\xE5\x9F\xBA\xE7\xA1\x80\xE5\xB1\x9E\xE6\x80\xA7\xE5\x80\xBC\xE4\xB8\x8A\xE9\x99\x90"));
	int cUpgradeExp = doc.getColumnIndex(UTF8String("\xE5\x8D\x87\xE7\xBA\xA7\xE7\xBB\x8F\xE9\xAA\x8C"));

	CFBead **beadList = m_BeadList.own_ptr();
	const int maxBeadId = (int)m_BeadList.length() - 1;

	const int totalCount = (int)doc.numRows();
	CFBeadLevel *levels = m_Allocator.Alloc<CFBeadLevel>(totalCount);
	for (int i=0; i<totalCount; ++i)
	{
		CFBeadLevel *level = &levels[i];
		level->id = doc.getValue(i, cId);
		if (level->id <= maxBeadId && beadList[level->id])
		{
			level->level = (int)doc.getValue(i, cLevel);
			if (level->level > 0)
			{
				level->baseAttriType = doc.getValue(i, cBaseAttrType);
				level->minBaseValue = doc.getValue(i, cBaseAttrMin);
				level->maxBaseValue = doc.getValue(i, cBaseAttrMax);
				level->upgradeExp = doc.getValue(i, cUpgradeExp);
				int numLevel = beadList[level->id]->numLevels;
				beadList[level->id]->numLevels = max(numLevel, level->level + 1);
			}
			else
			{
				level->id = 0;
			}
		}
		else
		{
			level->id = 0;
		}
	}

	//将灵珠等级添加到灵珠对象中
	for (int i=0; i<totalCount; ++i)
	{
		CFBeadLevel *level = &levels[i];
		if (level->id > 0)
		{
			CFBead *bead = beadList[level->id];
			if (!bead->levels) bead->levels = m_Allocator.Alloc<CFBeadLevel*>(bead->numLevels);
			bead->levels[level->level] = level; 
		}
	}
}

void StdWeaponProvider::readBeadAttributes(SG2DEX::CSVDocument &doc)
{
	int cQuality = doc.getColumnIndex(UTF8String("\xE5\xB1\x9E\xE6\x80\xA7\xE5\x93\x81\xE8\xB4\xA8"));
	int cType = doc.getColumnIndex(UTF8String("\xE5\xB1\x9E\xE6\x80\xA7\xE7\xB1\xBB\xE5\x9E\x8B"));
	int cMinValue = doc.getColumnIndex(UTF8String("\xE5\xB1\x9E\xE6\x80\xA7\xE5\x80\xBC\xE4\xB8\x8B\xE9\x99\x90"));
	int cMaxValue = doc.getColumnIndex(UTF8String("\xE5\xB1\x9E\xE6\x80\xA7\xE5\x80\xBC\xE4\xB8\x8A\xE9\x99\x90"));

	const int totalCount = max(5, (int)doc.numRows()/6);//(int)doc.numRows();
	StdBeadQuality *beadQualityList = m_Allocator.Alloc<StdBeadQuality>(totalCount);
	m_BeadAttriList.setLength(totalCount + 1);
	memset(m_BeadAttriList.own_ptr(), 0, sizeof(m_BeadAttriList.ptr()[0]) * (totalCount + 1));

	StdBeadQuality **attrPointerList = m_BeadAttriList.own_ptr();
	for (int i=0; i<totalCount; ++i)
	{
		StdBeadQuality *beadQuality = &beadQualityList[i];
		beadQuality->attrQuality = i + 1;
		attrPointerList[i+1] = beadQuality;
	}

	//读取数据
	const int maxAttrQuality = (int)m_BeadAttriList.length() - 1;
	const int numRows = (int)doc.numRows();
	CFBeadAttr *attrs = m_Allocator.Alloc<CFBeadAttr>(numRows);
	for (int i=0; i<numRows; ++i)
	{
		CFBeadAttr *attr = &attrs[i];
		attr->attrQuality = doc.getValue(i, cQuality);
		if (attr->attrQuality <= maxAttrQuality && attrPointerList[attr->attrQuality])
		{
			attr->attrType = (int)doc.getValue(i, cType);
			attr->minValue = (int)doc.getValue(i, cMinValue);
			attr->maxValue = (int)doc.getValue(i, cMaxValue);
			int numAttrs = attrPointerList[attr->attrQuality]->numAttrs;
			attrPointerList[attr->attrQuality]->numAttrs = max(numAttrs, attrs->attrType + 1);
		}
		else
		{
			attr->attrQuality = 0;
		}
	}

	//将灵珠属性数据添加到灵珠属性品质对象中
	for (int i=0; i<numRows; ++i)
	{
		CFBeadAttr *attr = &attrs[i];
		if (attr->attrQuality > 0)
		{
			StdBeadQuality *beadQuality = attrPointerList[attr->attrQuality];
			if (!beadQuality->attrs) beadQuality->attrs = m_Allocator.Alloc<CFBeadAttr*>(beadQuality->numAttrs);
			beadQuality->attrs[attr->attrType] = attr; 
		}
	}

	//检查有效属性
	for (int i=0; i<totalCount; ++i)
	{
		StdBeadQuality *beadQuality = attrPointerList[i+1];
		for (int j=0; j<beadQuality->numAttrs; ++j)
		{
			bool findFlag = false;
			CFBeadAttr *attr = beadQuality->attrs[j];
			if (!attr) continue;

			for (int k=0; k<beadQuality->randomMax; ++k)
			{
				if (beadQuality->attrArray[k] == attr->attrType)
				{
					findFlag = true;
					break;
				}
			}

			if (findFlag == false && beadQuality->randomMax < MAX_RANDOM_ATTR)
			{
				beadQuality->attrArray[beadQuality->randomMax] = attr->attrType;
				++beadQuality->randomMax;
			}
		}
	}
}

#endif
