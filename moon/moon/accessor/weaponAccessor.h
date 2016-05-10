#pragma once

using namespace lib::container;

//武器配置数据提供器
class WeaponAccessor : public lib::memory::Object
{
public:
	typedef Object super;

protected:
	lib::container::Array<CFWeapon*> m_WeaponList;//武器列表，ID为下标
	lib::container::Array<CFBead*> m_BeadList;//灵珠列表,ID为下标
	lib::container::Array<StdBeadQuality*> m_BeadAttriList;//灵珠附加属性列表，属性品质下标
	CConfigAllocator m_Allocator;//对象内存分配器
public:
	WeaponAccessor();
	~WeaponAccessor();

	const CFBead* getBeadById(uint32 id) const;
	const CFWeapon* getWeaponById(uint8 id) const;
	const StdBeadQuality* getBeadQuality(uint8 quality) const;

	bool loadConfig();

private:
#if 0
	void readStdWeapon(SG2DEX::CSVDocument &doc);
	void readWeaponLevels(SG2DEX::CSVDocument &doc);
	void readWeaponHoles(SG2DEX::CSVDocument &doc);
	void readStdBead(SG2DEX::CSVDocument &doc);
	void readBeadLevels(SG2DEX::CSVDocument &doc);
	void readBeadAttributes(SG2DEX::CSVDocument &doc);
#endif

};

