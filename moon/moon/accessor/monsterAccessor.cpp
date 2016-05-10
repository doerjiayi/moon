#include "StdAfx.h"

using namespace moon;

monsterStruct* MonsterAccessor::getMonsterById(int monId)
{
	if (monId > 0 && monId <(int) m_MonsterList.length())
		return m_MonsterList[monId];
	else return NULL;
}

monsterStruct* MonsterAccessor::getMonsterByName(const char* monName)
{
	monsterStruct *const*ppMonList = m_MonsterList.ptr();
	for (int i=(int)m_MonsterList.length()-1; i>-1; --i)
	{
		if (_stricmp(ppMonList[i]->name, monName) == 0)
			return ppMonList[i];
	}
	return NULL;
}

MonDropData* MonsterAccessor::getMonDropById(int dropId)
{
	if (dropId > 0 && dropId < (int)m_MonDropList.length())
		return m_MonDropList[dropId];
	else return NULL;
}

bool MonsterAccessor::loadConfig()
{
#if 0
	CSVDocument doc;

#define DCL(name, fn) {\
	if (!CConfigManager::LoadCSVDocument(doc, "./config/"name))\
	return false;\
	fn(doc); }

	DCL("monster/StdMonster.csv", readStdMonsters);
	DCL("monster/MonDrop.csv", readMonDrops);
#endif
	return true;
}

int monTypeNameValue(const String& typeName)
{
	int n = 0;
	memcpy(&n, typeName.ptr(), typeName.length());
	if (n == __MAKE_FOURCC__('P', 'T', 0, 0))
		return eNormalMonster;
	
	//default
	return eNormalMonster;
}

int monDamageNameValue(const String& typeName)
{
	int n = 0;
	memcpy(&n, typeName.ptr(), typeName.length());
	if (n == __MAKE_FOURCC__('N', 'G', 0, 0))
		return monsterStruct::mdNG;
	else if (n == __MAKE_FOURCC__('W', 'G', 0, 0))
		return monsterStruct::mdWG;

	//default
	return 0;
}

#if 0
void StdMonsterProvider::readStdMonsters(CSVDocument &doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE6\x80\xAA\xE7\x89\xA9ID"));
	int cName = doc.getColumnIndex(UTF8String("\xE5\x90\x8D\xE7\xA7\xB0"));
	int cType = doc.getColumnIndex(UTF8String("\xE7\xB1\xBB\xE5\x9E\x8B"));
	int cBody = doc.getColumnIndex(UTF8String("\xE6\xA8\xA1\xE5\x9E\x8B"));
	int cLevel = doc.getColumnIndex(UTF8String("\xE7\xAD\x89\xE7\xBA\xA7"));
	int cExp = doc.getColumnIndex(UTF8String("\xE7\xBB\x8F\xE9\xAA\x8C"));
	int cHP = doc.getColumnIndex(UTF8String("\xE6\xB0\x94\xE8\xA1\x80"));
	int cMP = doc.getColumnIndex(UTF8String("\xE5\x86\x85\xE5\x8A\x9B"));
	int cDamType = doc.getColumnIndex(UTF8String("\xE4\xBC\xA4\xE5\xAE\xB3\xE7\xB1\xBB\xE5\x9E\x8B"));
	int cPower = doc.getColumnIndex(UTF8String("\xE6\x94\xBB\xE5\x87\xBB\xE5\x8A\x9B"));
	int cIDefence = doc.getColumnIndex(UTF8String("\xE5\x86\x85\xE9\x98\xB2"));
	int cODefence = doc.getColumnIndex(UTF8String("\xE5\xA4\x96\xE9\x98\xB2"));
	int cAcuur = doc.getColumnIndex(UTF8String("\xE5\x91\xBD\xE4\xB8\xAD"));
	int cEvas = doc.getColumnIndex(UTF8String("\xE9\x97\xAA\xE9\x81\xBF"));
	int cIDefCT = doc.getColumnIndex(UTF8String("\xE5\x86\x85\xE9\x98\xB2\xE7\xA9\xBF\xE9\x80\x8F"));
	int cODefCT = doc.getColumnIndex(UTF8String("\xE5\xA4\x96\xE9\x98\xB2\xE7\xA9\xBF\xE9\x80\x8F"));
	int cBaoJi = doc.getColumnIndex(UTF8String("\xE6\x9A\xB4\xE5\x87\xBB"));
	int cKangNeiBao = doc.getColumnIndex(UTF8String("\xE6\x8A\x97\xE5\x86\x85\xE6\x9A\xB4"));
	int cKangWaiBao = doc.getColumnIndex(UTF8String("\xE6\x8A\x97\xE5\xA4\x96\xE6\x9A\xB4"));
	int cMoveSpeed = doc.getColumnIndex(UTF8String("\xE7\xA7\xBB\xE5\x8A\xA8\xE9\x80\x9F\xE5\xBA\xA6"));
	int cAttackSpeed = doc.getColumnIndex(UTF8String("\xE6\x94\xBB\xE5\x87\xBB\xE9\x80\x9F\xE5\xBA\xA6"));
	int cAttackItv = doc.getColumnIndex(UTF8String("\xE6\x94\xBB\xE5\x87\xBB\xE9\x97\xB4\xE9\x9A\x94"));
	int cInitiative = doc.getColumnIndex(UTF8String("\xE4\xB8\xBB\xE5\x8A\xA8\xE6\x94\xBB\xE5\x87\xBB"));
	int cSickRange = doc.getColumnIndex(UTF8String("\xE8\xBF\xBD\xE5\x87\xBB\xE8\x8C\x83\xE5\x9B\xB4"));
	int cNoBeat = doc.getColumnIndex(UTF8String("\xE4\xB8\x8D\xE8\xBF\x98\xE6\x89\x8B"));
	int cNotAttackable = doc.getColumnIndex(UTF8String("\xE4\xB8\x8D\xE5\x8F\xAF\xE6\x94\xBB\xE5\x87\xBB"));
	int cHideName = doc.getColumnIndex(UTF8String("\xE9\x9A\x90\xE8\x97\x8F\xE5\x90\x8D\xE5\xAD\x97"));
	int cSteady = doc.getColumnIndex(UTF8String("\xE7\xA8\xB3\xE5\xA6\x82\xE6\xB3\xB0\xE5\xB1\xB1"));
	int cNeverStrik = doc.getColumnIndex(UTF8String("\xE9\x9C\xB8\xE4\xBD\x93"));
	int cPAL = doc.getColumnIndex(UTF8String("PAL"));
	int cPAT = doc.getColumnIndex(UTF8String("PAT"));
	int cPAR = doc.getColumnIndex(UTF8String("PAR"));
	int cPAB = doc.getColumnIndex(UTF8String("PAB"));
	int cPAPrepare = doc.getColumnIndex(UTF8String("\xE6\x99\xAE\xE9\x80\x9A\xE6\x94\xBB\xE5\x87\xBB\xE8\xB5\xB7\xE6\x89\x8B\xE6\x97\xB6\xE9\x97\xB4"));
	int cPAAct = doc.getColumnIndex(UTF8String("\xE6\x99\xAE\xE9\x80\x9A\xE6\x94\xBB\xE5\x87\xBB\xE4\xBC\xA4\xE5\xAE\xB3\xE6\x97\xB6\xE9\x97\xB4"));
	int cSkill1 = doc.getColumnIndex(UTF8String("\xE6\x8A\x80\xE8\x83\xBD\x31"));
	int cSkill2 = doc.getColumnIndex(UTF8String("\xE6\x8A\x80\xE8\x83\xBD\x32"));
	int cSkill3 = doc.getColumnIndex(UTF8String("\xE6\x8A\x80\xE8\x83\xBD\x33"));
	int cSkill4 = doc.getColumnIndex(UTF8String("\xE6\x8A\x80\xE8\x83\xBD\x34"));
	int cDropId = doc.getColumnIndex(UTF8String("\xE6\x8E\x89\xE8\x90\xBDID"));

	int maxId = 0;
	const int totalCount = (int)doc.numRows();
	StdMonster *monsters = m_Allocator.Alloc<StdMonster>(totalCount);
	for (int i=0; i<totalCount; ++i)
	{
		StdMonster *monster = &monsters[i];
		monster->monId = doc.getValue(i, cId);
		monster->name = m_Allocator.AllocStr(doc.getValue(i, cName));
		monster->race = monTypeNameValue(doc.getValue(i, cType));
		monster->body = doc.getValue(i, cBody);
		monster->level = doc.getValue(i, cLevel);
		monster->exp = doc.getValue(i, cExp);
		monster->hp = doc.getValue(i, cHP);
		monster->mp = doc.getValue(i, cMP);
		monster->damageType = monDamageNameValue(doc.getValue(i, cDamType));
		monster->power = doc.getValue(i, cPower);
		monster->innerDefence = doc.getValue(i, cIDefence);
		monster->outerDefence = doc.getValue(i, cODefence);
		monster->accurate = doc.getValue(i, cAcuur);
		monster->evasion = doc.getValue(i, cEvas);
		monster->innerDefenceCT = doc.getValue(i, cIDefCT);
		monster->outerDefenceCT = doc.getValue(i, cODefence);
		monster->baoji = doc.getValue(i, cBaoJi);
		monster->kangNeiBao = doc.getValue(i, cKangNeiBao);
		monster->kangWaiBao = doc.getValue(i, cKangWaiBao);
		monster->moveSpeed = doc.getValue(i, cMoveSpeed);
		monster->attackSpeed = (short)((double)doc.getValue(i, cAttackSpeed) * 1000);
		monster->attackInterval = (short)((double)doc.getValue(i, cAttackItv) * 1000);
		monster->sickRange = doc.getValue(i, cSickRange);
		unsigned int flags = 0;
		if (doc.getValue(i, cInitiative).d) flags |= StdMonster::mfInitiative;
		if (doc.getValue(i, cNoBeat).d) flags |= StdMonster::mfNoStickBack;
		if (doc.getValue(i, cNotAttackable).d) flags |= StdMonster::mfCanNotBeAttack;
		if (doc.getValue(i, cHideName).d) flags |= StdMonster::mfHideName;
		if (doc.getValue(i, cSteady).d) flags |= StdMonster::mfSteady;
		if (doc.getValue(i, cNeverStrik).d) flags |= StdMonster::mfNeverStrick;
		monster->flags = flags;
		monster->paLeft = doc.getValue(i, cPAL);
		monster->paTop = doc.getValue(i, cPAT);
		monster->paRight = doc.getValue(i, cPAR);
		monster->paBottom = doc.getValue(i, cPAB);
		monster->paPrepareTime = (short)((double)doc.getValue(i, cPAPrepare) * 1000);
		monster->paActTime = (short)((double)doc.getValue(i, cPAAct) * 1000);
		monster->skills[0] = doc.getValue(i, cSkill1);
		monster->skills[1] = doc.getValue(i, cSkill2);
		monster->skills[2] = doc.getValue(i, cSkill3);
		monster->skills[3] = doc.getValue(i, cSkill4);
		monster->dropId = doc.getValue(i, cDropId);
		maxId = max(maxId, monster->monId);
	}

	//将怪物配置保存到怪物数据列表中
	m_MonsterList.setLength(maxId + 1);
	memset(m_MonsterList.own_ptr(), 0, sizeof(m_MonsterList.ptr()[0]) * (maxId + 1));
	StdMonster **monsterList = m_MonsterList.own_ptr();
	for (int i=0; i<totalCount; ++i)
	{
		StdMonster *monster = &monsters[i];
		monsterList[monster->monId] = monster;
	}

	linkMonsterDrops();
}

void StdMonsterProvider::readMonDrops(CSVDocument &doc)
{
	int cId = doc.getColumnIndex(UTF8String("\xE6\x8E\x89\xE8\x90\xBDID"));
	int cGroup = doc.getColumnIndex(UTF8String("\xE6\x8E\x89\xE8\x90\xBD\xE7\xBB\x84"));
	int cItemId = doc.getColumnIndex(UTF8String("\xE7\x89\xA9\xE5\x93\x81ID"));
	int cMinCount = doc.getColumnIndex(UTF8String("\xE6\x9C\x80\xE4\xBD\x8E\xE6\x95\xB0\xE9\x87\x8F"));
	int cMaxCount = doc.getColumnIndex(UTF8String("\xE6\x9C\x80\xE9\xAB\x98\xE6\x95\xB0\xE9\x87\x8F"));
	int cMinQuality = doc.getColumnIndex(UTF8String("\xE6\x9C\x80\xE4\xBD\x8E\xE5\x93\x81\xE8\xB4\xA8"));
	int cMaxQuality = doc.getColumnIndex(UTF8String("\xE6\x9C\x80\xE9\xAB\x98\xE5\x93\x81\xE8\xB4\xA8"));
	int cMinStrong = doc.getColumnIndex(UTF8String("\xE6\x9C\x80\xE4\xBD\x8E\xE5\xBC\xBA\xE5\x8C\x96"));
	int cMaxStrong = doc.getColumnIndex(UTF8String("\xE6\x9C\x80\xE9\xAB\x98\xE5\xBC\xBA\xE5\x8C\x96"));
	int cRate = doc.getColumnIndex(UTF8String("\xE6\x8E\x89\xE8\x90\xBD\xE7\x8E\x87"));
	int cBase = doc.getColumnIndex(UTF8String("\xE6\x8E\x89\xE8\x90\xBD\xE5\x9F\xBA\xE6\x95\xB0"));

	int maxId = 0;
	const int totalCount = (int)doc.numRows();
	MonDropItem *dropItems = m_Allocator.Alloc<MonDropItem>(totalCount);
	Array<unsigned short> dropIdCounts(totalCount);
	unsigned short* counts = dropIdCounts.own_ptr();
	for (int i=0; i<totalCount; ++i)
	{
		MonDropItem *item = &dropItems[i];
		item->dropId = doc.getValue(i, cId);
		item->group = doc.getValue(i, cGroup);
		item->itemId = doc.getValue(i, cItemId);
		item->minCount = doc.getValue(i, cMinCount);
		item->randCount = doc.getValue(i, cMaxCount);
		item->minQuality = doc.getValue(i, cMinQuality);
		item->randQuality = doc.getValue(i, cMaxQuality);
		item->minStrong = doc.getValue(i, cMinStrong);
		item->randStrong = doc.getValue(i, cMaxStrong);
		item->rate = doc.getValue(i, cRate);
		item->base = doc.getValue(i, cBase);


		if (item->randCount > item->minCount)
			item->randCount = item->randCount - item->minCount + 1;
		else item->randCount = 0;
		if (item->randQuality > item->minQuality)
			item->randQuality = item->randQuality - item->minQuality + 1;
		else item->randQuality = 0;
		if (item->randStrong > item->minStrong)
			item->randStrong = item->randStrong - item->minStrong + 1;
		else item->randStrong = 0;
		counts[item->dropId]++;
		maxId = max(maxId, item->dropId);
	}

	//依据所有掉落物品项生成掉落数据并将掉落数据存储到掉落表中
	MonDropData *drops = m_Allocator.Alloc<MonDropData>(maxId + 1);
	m_MonDropList.setLength(maxId + 1);
	MonDropData **dropList = m_MonDropList.own_ptr();
	for (int i=0; i<totalCount; ++i)
	{
		MonDropItem *item = &dropItems[i];
		MonDropData *drop = &drops[item->dropId];
		if (!drop->items)
		{
			drop->items = m_Allocator.Alloc<MonDropItem*>(counts[item->dropId]);
			dropList[item->dropId] = drop;
		}
		drop->items[drop->numItems] = item;
		drop->numItems++;
	}

	linkMonsterDrops();
}

void StdMonsterProvider::linkMonsterDrops()
{
	const int dropCount = (int)m_MonDropList.length();
	MonDropData **dropList = m_MonDropList.own_ptr();
	if (!dropList)
		return;
	StdMonster **monsterList = m_MonsterList.own_ptr();
	for (int i=(int)m_MonsterList.length()-1; i>-1; --i)
	{
		StdMonster *monster = monsterList[i];
		if (monster && monster->dropId && monster->dropId < dropCount)
		{
			monster->dropData = dropList[monster->dropId];
		}
	}
}
#endif

