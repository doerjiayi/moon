#pragma once

using namespace lib::memory;
using namespace lib::container;

class CMonsterEngine : public Object
{
public:
	typedef Object super;

public:
	CMonsterEngine();
	~CMonsterEngine();

	//运行怪物引擎
	void run(uint32 nTickLimit);

	//在指定的位置刷新一个怪物
	CDoer* makeMonster(const int monId, Scene* pScene, const int px, const int py);
	//清楚所有怪物，通常在退出析构时调用
	void clearMonsters();

protected:
	CBList<CDoer*>	m_MonList;//怪物列表
	CBList<INT_PTR>	m_FreeMonIndexList;//空怪物索引表
	INT_PTR m_nProcessMonIndex;//当前处理怪物索引
	unsigned int m_nNewMonserId;//新怪物ID

};
