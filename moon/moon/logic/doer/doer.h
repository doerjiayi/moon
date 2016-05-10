#ifndef __DOER_H__
#define __DOER_H__

using namespace common;

class CDoer : public CEntity
{
public:
	typedef CEntity super;

public:
	CDoer();
	virtual ~CDoer();

	//例行逻辑处理
	virtual void run(TickTime dwCurrTick);
	//初始化角色
	virtual bool initialize();
	virtual void disappear();

	void setViewArea(int val){m_nViewArea = val;}
	//查找是否在当前对象的可视列表中,存在则返回所在的索引,不存在则返回-1
	int getViewIndex(CEntity* pEntity);
	//通过系统ID获取系统模块对象
	virtual CDoerUnit* getModule(const int nSysId);
	//发送消息到角色消息队列
	void sendMsg(int ident, int sysId, INT_PTR p1, INT_PTR p2, INT_PTR p3, INT_PTR p4);
	//向可视列表的所有角色发送消息
	void broadcastMsg(int ident, int sysId, INT_PTR p1, INT_PTR p2, INT_PTR p3, INT_PTR p4);
	//向可视列表的所有玩家发送消息，如果自己是玩家，则也会向自己发送
	void broadcastPlayerMsg(int ident, int sysId, INT_PTR p1, INT_PTR p2, INT_PTR p3, INT_PTR p4);
	//分配经验值，如果已组队则进行队伍分配
	void gainExp(int exp);
	//直接获得经验值
	void winExp(int exp);

protected:
	virtual void dispatchMsg(DoerMsg *msg);
	virtual void sceneChanged(Scene *oldScene, int ox, int oy);
	virtual void positionChanged(int ox, int oy);
	virtual void updateEntityDescription();

	void updateViewList();
	void updateRunState(TickTime dwCurrTick);

public:
	char			m_sName[48];//角色名称
	int				m_nLevel;//玩家等级
	unsigned char	m_btAttackType;//怪物攻击伤害类型，为AttackPowerType的枚举值
	unsigned char	m_btVipLevel;//VIP等级
	unsigned short	m_wMonId;//怪物ID
	long long		m_nExp;//玩家经验值
	long long		m_nExpMax;//经验值上限
	int				m_nMonExp;//怪物经验值
	unsigned short  m_wMoveSpeed;//移动速度
	unsigned short  m_wAttackInterval;//怪物攻击间隔
	unsigned short  m_wAttackTime;//怪物攻击时间
	unsigned char	_____reserve[2];
	int				m_nBornX;//怪物出生地X
	int				m_nBornY;//怪物出生地Y
	CDoerAbility	m_Abil;//角色属性
	CDoerBattle	m_Battle;//战斗系统
	CBList<ViewStruct>	m_ViewList;
	DoerMsg*		m_pFirstMsg;//角色消息列表头
	DoerMsg*		m_pLastMsg;//角色消息列表尾
	TickTime		m_dwNextUpdateViewTime;//上次更新玩家场景可视列表的时间
	TickTime		m_dwLastRunTick;//上次调用run的时间

private:
	//怪物的视野必须与人物视野一样大，如果怪物视野小于人物视野，
	//则怪物广播数据包时将无法正确的向超出视野的人物广播，而人
	//物依然能看到怪物，将会出现客户端看到的怪物没有被更新状态
	//（例如移动到停止的状态更新）。
	int				m_nViewArea;//可视范围（网格范围）
};

#endif
