#ifndef __PLAYER_WEAPON_H_
#define __PLAYER_WEAPON_H_


/*********************************
* 玩家武器系统模块
*********************************/


class CPlayerWeapon: public CDoerUnit
{
public:
	typedef CDoerUnit super;

public:
	CPlayerWeapon();
	~CPlayerWeapon();

public:
	virtual bool init();
	virtual bool loadData(CDataPacketReader &data);
	virtual void saveData(CDataPacket& data);
	virtual void dispatchRecvPacket(int btCmd, CDataPacketReader &inPacket);
	virtual void dispatchMsg(DoerMsg *msg);
	virtual void offline();

public:
	//增加一个灵珠
	void addBead(unsigned short beadId, unsigned char level);
	//删除一个灵珠
	void delBead(BeadSeries serires);
	//查找一个灵珠
	Bead* findBead(BeadSeries serires);
	//清空武器信息
	void clearWeaponInfo();
	//清空灵珠列表
	void clearBeadList();

	void sendWeaponFullInfo();
	void sendWeaponInfo();
	void sendAddBead(Bead* pBead);
	void sendDelBead(BeadSeries series);
	void sendBeadEat(Bead* pMainBead, std::vector<BeadSeries> attachSerieses);
	void sendWeaponOperateRes(unsigned char op, unsigned char res);

private:
	//武器升级处理
	void handlePlayerWeaponUpdate(CDataPacketReader &inPacket);
	//装备灵珠处理
	void handlePlayerWeaponEquipBead(CDataPacketReader &inPacket);
	//脱下灵珠处理
	void handlePlayerWeaponUnEquipBead(CDataPacketReader &inPacket);
	//灵珠吞噬处理
	void handlePlayerWeaponBeadEater(CDataPacketReader &inPacket);
	//激活武器孔处理
	void handlePlayerWeaponHoleActive(CDataPacketReader &inPacket);

	void updateWeapon();
	void reloadWeaponBasicInfo();

	bool checkHaveBead(BeadSeries series);
	int checkBeadHole(BeadSeries series);
	BlowHoleState getHoleState(unsigned char hole);

	void equipBead(unsigned char hole, BeadSeries series);
	void unequipBead(unsigned char hole);
	void activeHole(unsigned char hole);
	void eatBead(Bead* mainBead, Bead* attachBead);
	int consumeActiveHoleCost(unsigned char hole, bool tryFlag);

	void getWeaponInfo(CGateSendPacket &packet);
	void getBeadInfo(Bead* pBead, CGateSendPacket &packet);
	unsigned char getBeadAttrFlag(Bead* pBead);

public:
	Weapon m_Weapon;//武器
	CBList<Bead*> m_BeadList;//灵珠列表
};

#endif
