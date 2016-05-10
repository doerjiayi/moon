#include "StdAfx.h"
#include "doerWeapon.h"

CPlayerWeapon::CPlayerWeapon()
{

}

CPlayerWeapon::~CPlayerWeapon()
{
	clearWeaponInfo();
	clearBeadList();
}

bool CPlayerWeapon::init()
{
	//TODO:初始化武器系统信息
	clearWeaponInfo();
	m_Weapon.weaponId = 1;
	m_Weapon.level = 1;
	/*
	switch(m_pPlayer->m_btJob)
	{
	case 1:
		m_Weapon.weaponId = 1;
		break;
	case 2:
		m_Weapon.weaponId = 2;
		break;
	case 3:
		m_Weapon.weaponId = 3;
		break;
	default:
		m_Weapon.weaponId = 1;
		break;
	}*/
	reloadWeaponBasicInfo();

	return true;
}

bool CPlayerWeapon::loadData(CDataPacketReader &data)
{
	common::DBType::DataSectionHeader *pSecHdr;
	if (data.getAvaliableLength() < sizeof (*pSecHdr))
		return false;

	pSecHdr = (common::DBType::DataSectionHeader*)data.getOffsetPtr();
	if (pSecHdr->wDataType != common::SystemId::sysWeapon)
	{
		logError( "角色(%lld:%s)数据的武器数据错误",
			m_pPlayer->m_EntityId.llid, m_pPlayer->m_sName);
		return false;
	}

	data.adjustOffset(sizeof(*pSecHdr));

	unsigned short nBeadCount = 0;
	data >> nBeadCount;

	//加载灵珠列表信息
	clearBeadList();
	m_BeadList.reserve(nBeadCount);
	Bead* pBead;
	for (unsigned short i = 0; i < nBeadCount; ++i)
	{
		if (data.getAvaliableLength() < sizeof(*pBead))
		{
			logError("角色(%lld:%s)数据的武器数据(%d)错误，灵珠数据长度不足",
				m_pPlayer->m_EntityId.llid, m_pPlayer->m_sName, i);
			return false;
		}

		pBead = CGlobalLogicObjAlloc::allocWeaponBead();
		data >> *pBead;
		m_BeadList.add(pBead);
	}

	//加载武器信息
	clearWeaponInfo();
	if (data.getAvaliableLength() < sizeof(m_Weapon))
	{
		logError( "角色(%lld:%s)数据的武器数据错误，武器数据长度不足",
			m_pPlayer->m_EntityId.llid, m_pPlayer->m_sName);
		return false;
	}
	data >> m_Weapon;

	return true;
}

void CPlayerWeapon::saveData(CDataPacket& data)
{
	size_t hdrPos = data.getPosition();
	common::DBType::DataSectionHeader *secHdr;
	data.adjustOffset(sizeof(*secHdr));

	//保存灵珠列表信息
	size_t beadDataPos = data.getPosition();
	unsigned short nBeadCount = 0;
	data.adjustOffset(sizeof(nBeadCount));
	Bead** ppBeadList = m_BeadList;
	for (unsigned short i = 0; i < nBeadCount; ++i)
	{
		data << *(ppBeadList[i]);
	}

	//保存武器信息
	data << m_Weapon;

	//写入数据头部
	secHdr = (DataSectionHeader*)data.getPositionPtr(hdrPos);
	secHdr->wDataType = common::SystemId::sysWeapon;
	secHdr->wDataVersion = common::DBType::WeaponDataVersion;
	secHdr->wDataCount = (unsigned short)1;	
	secHdr->wStructSize = (unsigned short)(data.getPosition()-beadDataPos);

	//写入灵珠列表长度
	unsigned short* pBeadCount = (unsigned short*)data.getPositionPtr(beadDataPos);
	*pBeadCount = (unsigned short)nBeadCount;
}

void CPlayerWeapon::dispatchRecvPacket(int btCmd, CDataPacketReader &inPacket)
{
	switch(btCmd)
	{
	case common::NetCmd::cUpgradeWeapon:
		handlePlayerWeaponUpdate(inPacket);
		break;
	case common::NetCmd::cActiveWeaponHole:
		handlePlayerWeaponHoleActive(inPacket);
		break;
	case common::NetCmd::cEquipBead:
		handlePlayerWeaponEquipBead(inPacket);
		break;
	case common::NetCmd::cUnEquipBead:
		handlePlayerWeaponUnEquipBead(inPacket);
		break;
	case common::NetCmd::cBeadEat:
		handlePlayerWeaponBeadEater(inPacket);
		break;
	}
}

void CPlayerWeapon::dispatchMsg(DoerMsg *msg)
{
}

void CPlayerWeapon::offline()
{
}

//增加一个灵珠
void CPlayerWeapon::addBead(unsigned short beadId, unsigned char level)
{
	Bead* pBead = CGlobalLogicObjAlloc::allocWeaponBead();
	pBead->beadId = beadId;
	pBead->level = level;

	CLogicEngine *pLogicEngine = g_LogicEngine;
	pBead->series = pLogicEngine->allocId();

	pBead->addSoulEater = 0;
	pBead->exp = 0;
	pBead->elementRatio = 0;

	Attribute attr;
	attr.type = aNull;
	attr.value = 0;
	pBead->baseAttr = attr;//读取基本配置
	pBead->addAttr = attr;//如何设置为没有？

	m_BeadList.add(pBead);
}

//删除一个灵珠
void CPlayerWeapon::delBead(BeadSeries series)
{
	Bead** ppBeadList = m_BeadList;
	for (INT_PTR i = m_BeadList.count()-1; i > -1; --i)
	{
		Bead* pBead = ppBeadList[i];
		if (pBead->series.llid == series.llid)
		{
			m_BeadList.remove(i);
			//sendRemove
			CGlobalLogicObjAlloc::freeWeaponBead(pBead);
		}
	}
}

//查找一个灵珠
Bead* CPlayerWeapon::findBead(BeadSeries series)
{
	Bead** ppBeadList = m_BeadList;
	for (INT_PTR i = m_BeadList.count()-1; i > -1; --i)
	{
		Bead* pBead = ppBeadList[i];
		if (pBead->series.llid == series.llid)
		{
			return pBead;
		}
	}

	return NULL;
}

//清空武器信息
void CPlayerWeapon::clearWeaponInfo()
{
	memset(&m_Weapon, 0, sizeof(m_Weapon));
	//m_Weapon.level = 1;
	//reloadWeaponBasicInfo();
}

//清空灵珠列表
void CPlayerWeapon::clearBeadList()
{
	Bead **ppBeadList = m_BeadList;
	for (INT_PTR i = m_BeadList.count()-1; i > -1; --i)
	{
		CGlobalLogicObjAlloc::freeWeaponBead(ppBeadList[i]);
	}
	m_BeadList.clear();
}

void CPlayerWeapon::getWeaponInfo(CGateSendPacket &packet)
{
	packet << m_Weapon.weaponId;
	packet << m_Weapon.level;
	packet << m_Weapon.soulEater;
	packet << m_Weapon.eternalValue;
	packet << m_Weapon.baseAttr.type;
	packet << m_Weapon.baseAttr.value;
	for (unsigned char i = 0; i < MAX_WEAPON_HOLES; ++i)
	{
		packet << m_Weapon.holeState[i];
	}
	for (unsigned char i = 0; i < MAX_WEAPON_HOLES; ++i)
	{
		packet << m_Weapon.holeBeads[i];
	}
}

void CPlayerWeapon::getBeadInfo(Bead* pBead, CGateSendPacket &packet)
{
	packet << pBead->series;
	packet << pBead->beadId;
	packet << pBead->level;
	packet << pBead->exp;
	unsigned char beadAttrFlag = getBeadAttrFlag(pBead);
	packet << beadAttrFlag;
	if (beadAttrFlag & 1)
	{
		packet << pBead->baseAttr.type;
		packet << pBead->baseAttr.value;
	}
	if (beadAttrFlag & 2)
	{
		packet << pBead->addAttr.type;
		packet << pBead->addAttr.value;
	}
	if (beadAttrFlag & 4)
	{
		packet << pBead->elementRatio;
	}
	if (beadAttrFlag & 8)
	{
		packet << pBead->addSoulEater;
	}
}

unsigned char CPlayerWeapon::getBeadAttrFlag(Bead* pBead)
{
	unsigned char beadAttrFlag = 0;
	if (pBead->baseAttr.type != aNull && pBead->baseAttr.value != 0)
	{
		beadAttrFlag = beadAttrFlag | 1;
	}
	if (pBead->addAttr.type != aNull && pBead->addAttr.value != 0)
	{
		beadAttrFlag = beadAttrFlag | 2;
	}
	if (pBead->elementRatio != 0)
	{
		beadAttrFlag = beadAttrFlag | 4;
	}
	if (pBead->addSoulEater != 0)
	{
		beadAttrFlag = beadAttrFlag | 8;
	}
	return beadAttrFlag;
}

void CPlayerWeapon::sendWeaponFullInfo()
{
	CGateSendPacket &packet = m_pPlayer->allocSendPacket();
	packet.writeCmd(common::SystemId::sysWeapon, NetCmd::sWeaponFullInfo);

	//灵珠信息
	Bead** ppBeadList = m_BeadList;
	unsigned short nCount = (unsigned short)m_BeadList.count();
	packet << nCount;
	for (INT_PTR i =nCount-1; i > -1; --i)
	{
		Bead* pBead = ppBeadList[i];
		getBeadInfo(pBead, packet);
	}

	//武器信息
	getWeaponInfo(packet);

	packet.flush();
}

void CPlayerWeapon::sendWeaponInfo()
{
	CGateSendPacket &packet = m_pPlayer->allocSendPacket();
	packet.writeCmd(common::SystemId::sysWeapon, NetCmd::sWeaponInfo);

	//武器信息
	getWeaponInfo(packet);
	
	packet.flush();
}

void CPlayerWeapon::sendAddBead(Bead* pBead)
{
	CGateSendPacket &packet = m_pPlayer->allocSendPacket();
	packet.writeCmd(common::SystemId::sysWeapon, NetCmd::sAddBead);

	getBeadInfo(pBead, packet);

	packet.flush();
}

void CPlayerWeapon::sendDelBead(BeadSeries series)
{
	CGateSendPacket &packet = m_pPlayer->allocSendPacket();
	packet.writeCmd(common::SystemId::sysWeapon, NetCmd::sDelBead);

	packet << series;

	packet.flush();
}

void CPlayerWeapon::sendBeadEat(Bead* pMainBead, std::vector<BeadSeries> attachSerieses)
{
	CGateSendPacket &packet = m_pPlayer->allocSendPacket();
	packet.writeCmd(common::SystemId::sysWeapon, NetCmd::sBeadEat);

	getBeadInfo(pMainBead, packet);
	
	packet << attachSerieses.size();

	for (size_t i = 0; i < attachSerieses.size(); ++i)
	{
		packet << attachSerieses[i];
	}

	packet.flush();
}

void CPlayerWeapon::sendWeaponOperateRes(unsigned char op, unsigned char res)
{
	CGateSendPacket &packet = m_pPlayer->allocSendPacket();
	packet.writeCmd(common::SystemId::sysWeapon, NetCmd::sWeaponOpRes);

	packet << op;
	packet << res;

	packet.flush();
}

//武器升级处理
void CPlayerWeapon::handlePlayerWeaponUpdate(CDataPacketReader &inPacket)
{
	/*
	//检查是否超过玩家等级
	//检查是否已到武器最高级
	//检查武魂值是否已达到要求
	//检查消耗是否足够
	//消耗
	//武器等级+1
	//刷新武器 武器孔、属性
	//刷新人物属性
	//通知武器信息
	*/

	if (m_Weapon.level >= m_pPlayer->m_nLevel)
	{
		return;
	}

	const CFWeapon* weapon = g_ConfigManager->weaponDataProvider.getWeaponById(m_Weapon.weaponId);
	if (m_Weapon.level >= weapon->numLevels)
	{
		return;
	}

	if (!weapon->levels[m_Weapon.level] || m_Weapon.eternalValue < weapon->levels[m_Weapon.level]->eternalUpgrade)
	{
		return;
	}

	m_Weapon.eternalValue = m_Weapon.eternalValue - weapon->levels[m_Weapon.level]->eternalUpgrade;

	updateWeapon();
	//m_Weapon.level = m_Weapon.level + 1;

	//reloadWeaponBasicInfo();

	sendWeaponInfo();
}

//装备灵珠处理
void CPlayerWeapon::handlePlayerWeaponEquipBead(CDataPacketReader &inPacket)
{
	/*
	//读取灵珠系列号
	//读取武器孔号
	//检查是否有此灵珠
	//检查此灵珠是否已装备在别的武器孔
	//检查武器孔状态是否已激活
	//卸下此孔中已装备的灵珠
	//装备上此灵珠
	//刷新武器属性
	//刷新人物属性
	//通知
	*/

	BeadSeries series;
	unsigned char hole;
	inPacket >> series;
	inPacket >> hole;

	if (checkHaveBead(series) == false)
	{
		return;
	}

	if (checkBeadHole(series) != -1)
	{
		return;
	}

	BlowHoleState holeState = getHoleState(hole);
	if (holeState < bhsOpen)
	{
		return;
	}

	if (holeState == bhsNest)
	{
		unequipBead(hole);
	}

	equipBead(hole, series);

	//notify
}

//脱下灵珠处理
void CPlayerWeapon::handlePlayerWeaponUnEquipBead(CDataPacketReader &inPacket)
{
	/*
	//读取武器孔号
	//检查此孔是否有灵珠
	//卸下灵珠
	//刷新武器属性
	//刷新人物属性
	//通知
	*/

	unsigned char hole;
	inPacket >> hole;

	BlowHoleState holeState = getHoleState(hole);
	if (holeState == bhsNest)
	{
		unequipBead(hole);
	}

	//notify
}

//灵珠吞噬处理
void CPlayerWeapon::handlePlayerWeaponBeadEater(CDataPacketReader &inPacket)
{
	/*
	//读取主灵珠系列号
	//读取次灵珠数量
	//读取次灵珠系列号
	//检查主灵珠有效性
	//检查次灵珠有效性
	//处理吞噬
	//检查主灵珠是否装备中
	//刷新武器属性
	//刷新人物属性
	//通知
	*/

	BeadSeries mainSeries;
	unsigned char beadNum; 
	inPacket >> mainSeries;
	inPacket >> beadNum;

	Bead* mainBead = findBead(mainSeries);

	if (!mainBead)
	{
		return;
	}

	size_t attachPos = inPacket.getPosition();

	BeadSeries attachSeries;
	for (unsigned char i = 0; i < beadNum; ++i)
	{
		inPacket >> attachSeries;

		if (checkHaveBead(attachSeries) == false)
		{
			return;
		}

		if (checkBeadHole(attachSeries) != -1)
		{
			return;
		}
	}

	inPacket.setPosition(attachPos);

	Bead* attachBead;
	for (unsigned char i = 0; i < beadNum; ++i)
	{
		inPacket >> attachSeries;
		
		attachBead = findBead(attachSeries);
		
		if (attachBead)
			eatBead(mainBead, attachBead);
	}

	if (checkBeadHole(mainSeries) != -1)
	{
		//
	}

	//notify
}

//激活武器孔处理
void CPlayerWeapon::handlePlayerWeaponHoleActive(CDataPacketReader &inPacket)
{
	/*
	//读取武器孔
	//检查武器孔是否合法
	//检查武器孔状态是否可激活
	//检查消耗是否足够
	//消耗
	//更新武器孔状态
	//通知
	*/

	unsigned char hole;
	inPacket >> hole;

	BlowHoleState holeState = getHoleState(hole);
	if (holeState != bhsUnLock)
	{
		return;
	}

	int error = consumeActiveHoleCost(hole, true);
	if (error != 0)
	{
		return;
	}

	consumeActiveHoleCost(hole, false);

	activeHole(hole);

	//notify
}

void CPlayerWeapon::updateWeapon()
{
	m_Weapon.level = m_Weapon.level + 1;
	reloadWeaponBasicInfo();
}

void CPlayerWeapon::reloadWeaponBasicInfo()
{
	const CFWeapon* weapon = g_ConfigManager->weaponDataProvider.getWeaponById(m_Weapon.weaponId);

	CFWeaponLevel* weaponLvl = weapon->levels[m_Weapon.level];
	if (!weaponLvl)
	{
		return;
	}

	m_Weapon.baseAttr.type = weaponLvl->basicAttriType;
	m_Weapon.baseAttr.value = weaponLvl->basicAttriValue;
	m_Weapon.eternalValue = m_Weapon.eternalValue < 0 ? 0 : m_Weapon.eternalValue;
	m_Weapon.soulEater = weaponLvl->soulEater;
	m_Weapon.maxEternalValue = weaponLvl->eternalMax;

	for (unsigned char i = 0; i < weapon->numHoles && i < MAX_WEAPON_HOLES; ++i)
	{
		if (m_Weapon.holeState[i] == bhsNone)
		{
			m_Weapon.holeState[i] = bhsLock;
		}

		if (weapon->holes[i] && weapon->holes[i]->openLevel <= m_Weapon.level && m_Weapon.holeState[i] == bhsLock)
		{
			m_Weapon.holeState[i] = bhsUnLock;
		}
	}
}

bool CPlayerWeapon::checkHaveBead(BeadSeries series)
{
	Bead** ppBeadList = m_BeadList;
	for (INT_PTR i = m_BeadList.count()-1; i > -1; --i)
	{
		Bead* pBead = ppBeadList[i];
		if (pBead->series.llid == series.llid)
		{
			return true;
		}
	}
	return false;
}

int CPlayerWeapon::checkBeadHole(BeadSeries series)
{
	for (int i = 0; i < MAX_WEAPON_HOLES; ++i)
	{
		if (m_Weapon.holeBeads[i].llid == series.llid)
			return i;
	}
	return -1;
}

BlowHoleState CPlayerWeapon::getHoleState(unsigned char hole)
{
	if (hole >= MAX_WEAPON_HOLES)
		return bhsNone;

	return (BlowHoleState)m_Weapon.holeState[hole];
}

void CPlayerWeapon::equipBead(unsigned char hole, BeadSeries series)
{
	if (hole >= MAX_WEAPON_HOLES)
		return;
	if (m_Weapon.holeState[hole] != bhsOpen)
		return;

	m_Weapon.holeState[hole] = bhsNest;
	m_Weapon.holeBeads[hole] = series;
}

void CPlayerWeapon::unequipBead(unsigned char hole)
{
	if (hole >= MAX_WEAPON_HOLES)
		return;
	if (m_Weapon.holeState[hole] != bhsNest)
		return;

	m_Weapon.holeState[hole] = bhsOpen;
	m_Weapon.holeBeads[hole].llid = 0;
}

void CPlayerWeapon::activeHole(unsigned char hole)
{
	if (hole >= MAX_WEAPON_HOLES)
		return;
	if (m_Weapon.holeState[hole] != bhsUnLock)
		return;

	m_Weapon.holeState[hole] = bhsOpen;
	m_Weapon.holeBeads[hole].llid = 0;
}

void CPlayerWeapon::eatBead(Bead* mainBead, Bead* attachBead)
{
	if (!mainBead || !attachBead)
		return;

	const CFBead* stdMainBead = g_ConfigManager->weaponDataProvider.getBeadById(mainBead->beadId);
//	const CFBead* stdAttachBead = g_ConfigManager->weaponDataProvider.getBeadById(attachBead->beadId);

	//根据某个算法，从attachBead中获取增长经验
	unsigned int addExp = 0;
	
	mainBead->exp += addExp;

	unsigned char level = mainBead->level;

	if (!stdMainBead->levels[mainBead->level])
		return;

	unsigned int maxExp = stdMainBead->levels[level]->upgradeExp;
	while(maxExp > 0 && mainBead->exp >= maxExp)
	{
		mainBead->exp -= maxExp;
		mainBead->level += 1;
		
		//TODO:重新计算基本属性

		if (!stdMainBead->levels[mainBead->level])
			break;

		maxExp = stdMainBead->levels[mainBead->level]->upgradeExp;
	}

	if (maxExp <= 0)
	{
		mainBead->exp = 0;
	}

	//TODO:如果被吞噬珠子有属性，计算元素属性
	if (mainBead->elementRatio == 0)
	{

	}

	delBead(attachBead->series);
}

int CPlayerWeapon::consumeActiveHoleCost(unsigned char hole, bool tryFlag)
{
	const CFWeapon* weapon = g_ConfigManager->weaponDataProvider.getWeaponById(m_Weapon.weaponId);
	CFWeaponHole* weaponHole = weapon->holes[hole];

	if (!weaponHole)
	{
		return 1;
	}

	//TODO:激活武器孔消耗
	switch(weaponHole->activeType)
	{
	case 1:
		{
			//weaponHole->activeCost
		}
		break;
	case 2:
	case 3:
		break;
	}

	if (weaponHole->itemId != 0)
	{
		//weaponHole->itemCost
		if (tryFlag == true)
		{
			
		}
		else
		{

		}
	}

	return 0;
}
