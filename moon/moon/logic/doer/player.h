#ifndef __PLAYER_H__
#define __PLAYER_H__

class CLogicGate;
class CGuild;

enum NPCQuestState
{
	ENPC_QSTATE_NONE		=	0,	//普通状态
	ENPC_QSTATE_ACCEPT		=	1,	//有任务可接
	ENPC_QSTATE_HAVE_ACCEPT	=	2,	//有任务已接
	ENPC_QSTATE_SUBMIT		=	3,	//有任务可交
};

class CPlayer : public CDoer
{
public:
	typedef CDoer super;

public:
	CPlayer();
	~CPlayer();

	//例行逻辑处理
	virtual void run(TickTime dwCurrTick);
	//初始化角色
	virtual bool initialize();
	//设置身份数据
	void setIdentity(EnterGameStruct *pEnterStruct, bool boIsNewPlayer);
	//读取角色数据
	bool loadData(CDataPacketReader &data);
	//保存角色数据
	void saveData(CDataPacket &data);
	//玩家连接断开，boRemoteClose表示是否因连接断开而被网关发起的close
	void close(bool boRemoteClose = false);
	//加载数据完成，准备运行
	void readyForRun();
	//发送初始场景信息，用于加载进入场景
	void sendSceneInfo();
	//发送银两改变
	void sendCoinCount();
	//发送元宝改变
	void sendGameGoldCount();
	//发送玩家出现信息
	void sendEntityAppear(CEntity *pEntity);
	//通过系统ID获取系统模块对象
	virtual CDoerUnit* getModule(const int nSysId);
	//申请发送数据包
	inline CGateSendPacket& allocSendPacket() { return m_pGate->AllocSendPacket(m_nGateUserIndex); }
	//回到出生地
	void gotoBornScene();
	//加银两
	void addCoin(int count);
	//消耗银两，仅当银两值满足指定数量才进行消耗，否则将返回false且不消耗
	bool decCoin(int count);
	
protected:
	//离线时调用
	void offline();
	//清空收到客户端的待处理消息列表
	void clearNetMsgs();
	//处理收到客户端的消息
	void processNetMsgs(unsigned int dwTickLimit);
	//任务状态改变,刷新可视列表内所有NPC的状态
	void updateNpcState();
	
	int getPlayerIndex(){return m_nPlayerIndex;}//重载实体的getPlayerIndex 方法来给CEntity使用

	virtual void dispatchMsg(DoerMsg *msg);
	virtual void sceneChanged(Scene *oldScene, int ox, int oy);
	virtual void updateEntityDescription();

private:
	void recordDynamicScenePosition();
public:
	int				m_nPlayerIndex;//玩家对象快速索引值 m_PlayerIndexList[m_nPlayerIndex]-->player
	char			m_sAccount[64];//玩家账号字符串
	uint32				m_nAccountId;//玩家账号ID
	uint64				m_nCreateTime;//玩家第一次登陆的时间
	CLogicGate*		m_pGate;//玩家所处网关对象
	long long		m_llSocket;//玩家连接到网关的Socket值
	int				m_nGateIndex;//玩家所处网关编号
	int				m_nGateUserIndex;//玩家所在网关用户编号  m_SessionList[m_nGateUserIndex] -->tagRunGateUserSession
	int				m_nGateVerify;//玩家所在网关用户验证值
	int				m_nClientAddr;//客户端地址
	TickTime		m_dwEnterTick;//进入游戏时间(Tick)
	int				m_nEnterGameTime;//进入游戏的日期时间
	TickTime		m_dwClosedTick;//连接关闭的时间
	TickTime		m_dwInvalidTick;//角色对象失效的时间
	TickTime		m_dwNextSaveDataTick;//下次自动保存玩家数据的时间
	bool			m_boValid;//角色对象是否保持有效
	char			_____________reserve0[3];
	bool			m_boIsNewPlayer;//是否新玩家
	unsigned char	m_btGender;//玩家性别（0男1女）
	unsigned char	m_btJob;//玩家职业
	unsigned char	m_btGMLevel;//玩家GM权限等级;
	GuildId			m_GuildId;//玩家所在帮会ID
	CGuild*			m_pGuild;//玩家所在帮会对象
	int				m_nCoin;//金币数量
	int				m_nGameGold;//元宝数量
	PlayerId		m_DearId;//伴侣角色ID
	char			m_sDearName[48];//伴侣名称
	CPlayerBag		m_Bag;//角色背包
	CPlayerEquip	m_Equip;//角色装备
	CPlayerQuest	m_Quest;//角色任务
	CPlayerNpcTalk	m_NpcTalk;//玩家与npc交互系统
	CPlayerChat		m_playerChat;//交谈系统
	CPlayerTeam		m_team;//组队系统
	CPlayerWeapon	m_Weapon;//武器系统
	lib::container::CBList<CNetPacket*> m_NetMsgs;//收到待处理的客户端数据包列表
	int				m_nNetMsgIndex;//当前处理的客户端数据包列表索引
	EntityPosition	m_StaticPosition;//静态场景位置
	EntityPosition	m_DynamicPosition;//动态场景位置
};

#endif
