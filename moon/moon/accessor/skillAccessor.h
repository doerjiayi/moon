#pragma once

//技能配置数据提供器
class SkillProviderAccessor : public lib::memory::Object
{
public:
	typedef lib::memory::Object super;

protected:
	lib::container::Array<CFSkill*>		m_SkillList;//技能列表，ID为下标
	lib::container::Array<CFSkillPosture*>	m_PostureList;//技能招式列表,ID为下标
	CConfigAllocator	m_Allocator;//对象内存分配器
public:
	SkillProviderAccessor();
	~SkillProviderAccessor();

	const CFSkill* getSkillById(const int id) const ;
	const CFSkill* getSkillByName(const moon::String& name) const ;
	const CFSkillPosture* getPostureById(const int id) const ;
	const CFSkillPosture* getPostureByName(const moon::String& name) const ;

	bool loadConfig();

private:
#if 0
	void readStdSkills(SG2DEX::CSVDocument &doc);
	void readSkillLevels(SG2DEX::CSVDocument &doc);
	void readPostures(SG2DEX::CSVDocument &doc);
	void readPostureLevels(SG2DEX::CSVDocument &doc);
	void readTimePoints(SG2DEX::CSVDocument &doc);
#endif
};

