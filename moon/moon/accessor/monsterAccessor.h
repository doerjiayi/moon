#pragma once

class MonsterAccessor : public Object
{
public:
	typedef Object super;

protected:
	lib::container::Array<monsterStruct*>		m_MonsterList;//怪物列表，ID为下标
	lib::container::Array<MonDropData*>		m_MonDropList;//怪物掉落配置表
	lib::memory::CConfigAllocator			m_Allocator;//对象内存分配器

public:
	monsterStruct*		getMonsterById(int monId);
	monsterStruct*		getMonsterByName(const char* monName);
	MonDropData*	getMonDropById(int dropId);

	bool loadConfig();

protected:
#if 0
	void readStdMonsters(CSVDocument &doc);
	void readMonDrops(CSVDocument &doc);
	void linkMonsterDrops();
#endif
};
