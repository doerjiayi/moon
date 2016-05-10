#pragma once

//人物等级配置提供器
class PlayerDataAccessor : public lib::memory::Object
{
public:
	typedef Object super;
	static const int MAX_LEVEL = 500;//最大等级数量

protected:
	lib::container::Array<CFPlayerLevel>		m_Levels;//等级配置表，等级为下标
public:
	PlayerDataAccessor();
	~PlayerDataAccessor();

	const CFPlayerLevel* getLevel(int level) const ;

	bool loadConfig();

private:
	/*void readExpConfig(SG2DEX::CSVDocument &doc);
	void readJobLevelAttrConfig(SG2DEX::CSVDocument &doc, int job);*/
};
