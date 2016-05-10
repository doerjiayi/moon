#pragma once

using namespace common;
struct CUserItem;

//目前游戏中用到的物品的品质的定义
enum tagItemQuality
{
	iqItemWhite =0,   //白装
	iqItemGreen  =1,  //绿装
	iqItemBlue  =2,   //蓝装
	iqItemPurple =3,  //紫装
	iqItemOrange =4,  //橙装
	iqItemRed=5,      //红装
};

/** 定义物品的使用条件类型 **/
enum UseConditionType
{
	ucLevel = 1,			//等级必须大于等于value级
	ucGender=2,				//性别编号必须等于value，0男1女
	ucJob=3,					//职业编号必须等于value
	ucMarried=4,		//结婚与否必须等于value
	ucMountSkillLevel=5,  //骑术等级
	ucCampTitle =6,       //需要阵营的官职
	ucCircle = 7,	//转生次数
	ucMaxCount,
};

// enum tagItemAttribute
// {
// 	iaItemPhysical =0,	//体力
// 	iaItemPower =1,			//力量
// 	iaItemCrit =2,				//暴击
// 	iaItemDefense =3,		//防御
// 	iqMaxCount,
// };

/* 定义属性组数据结构，属性组将用于描述物品一个品质或强化等级的属性表 */
struct ItemAttributeGroup
{
	int count;
	int itemId;
	int level;
	Attribute *attrs;
};

/* 定义物品联合属性
	* ★联合属性指一个装备的某些属性仅在角色穿戴有其他装备的时候才出现的属性
	* ★这些具有联合关系的物品称为联合物品
	*/
struct UnitedAttributeGroup :
	public ItemAttributeGroup
{
	INT_PTR		nUnitedItemCount;	//联合物品数量
	PWORD		pUnitedItemIds;		//联合物品ID表
};
		
/* 定义联合属性表 */
struct UnitedAttributeTable
{
	INT_PTR				 nCount;	//联合属性数量
	UnitedAttributeGroup *pGroups;//联合属性表
};
		
/* 定义联合属性表 */
struct RandomAttributeTable
{
//		INT_PTR				nCount;	//随机属性数量
//		PRANDOMATTRTERM		pAttrs;	//随机属性表
};

struct ItemScene
{
	ItemScene(int itemId, int sceneId): nItemId(itemId), nSceneId(sceneId){}
	int nItemId;
	int nSceneId;
};

struct ExistScenes
{
	int	nCount;		// 可存在场景数量
	int nItemId;
	int	*pSceneId;	// 场景ID
};

/** 定义物品的标志属性结构 **/
struct ItemFlags
{
public:
	enum ItemFlagValues
	{
		sfRecordLog			= 0x00000001,	//是否记录流通日志
		sfDenyStorage		= 0x00000002,	//是否禁止存仓库
		sfAutoBindOnTake	= 0x00000004,	//是否在穿戴后自动绑定
		sfAutoStartTime		= 0x00000008,	//是否在获得时即开始计算时间，如果不具有此标志则将在装备第一次被穿戴的时候开始计时
		sfDenyDeal			= 0x00000010,	//是否禁止交易
		sfDenySell			= 0x00000020,	//是否禁止出售到商店
		sfDenyDestroy		= 0x00000040,	//是否禁止销毁
		sfDestroyOnOffline	= 0x00000080,	//是否在角色下线时自动消失
		sfDestroyOnDie		= 0x00000100,	//是否在角色死亡时自动消失
		sfDenyDropdown		= 0x00000200,	//是否禁止在死亡时爆出
		sfDieDropdown		= 0x00000400,	//是否在角色死亡时强制爆出
		sfOfflineDropdown	= 0x00000800,	//是否在角色下线时强制爆出
		sfInlayable			= 0x00001000,	//是否可打孔（打孔后才能镶嵌）
		sfHideDura			= 0x00002000,	//是否不显示耐久
		sfDenySplite		= 0x00004000,	//是否禁止在物品叠加后进行拆分（通常用于带有实现限制的物品）
		sfAsQuestItem		= 0x00008000,	//是否作为任务需求物品使用
		sfMonAlwaysDropdown	= 0x00010000,	//是否在怪物死亡爆出时不检查杀怪者等级差而均掉落
		sfHideQualityName	= 0x00020000,	//是否隐藏装备的品质前缀文字
		sfUseOnPractice		= 0x00040000,	//是否可以再操练的时候使用
	};
public:
	inline bool isFlagSet(const ItemFlagValues flag) const 
	{
		return (dwFlag & flag) != 0;
	}
	inline bool recordLog() const { return (dwFlag & sfRecordLog) != 0; }
	inline bool denyStorage() const { return (dwFlag & sfDenyStorage) != 0; }
	inline bool autoBindOnTake() const { return (dwFlag & sfAutoBindOnTake) != 0; }
	inline bool autoStartTime() const { return (dwFlag & sfAutoStartTime) != 0; }
	inline bool denyDeal() const { return (dwFlag & sfDenyDeal) != 0; }
	inline bool denySell() const { return (dwFlag & sfDenySell) != 0; }
	inline bool denyDestroy() const { return (dwFlag & sfDenyDestroy) != 0; }
	inline bool distroyOnOffline() const { return (dwFlag & sfDestroyOnOffline) != 0; }
	inline bool destroyOnDie() const { return (dwFlag & sfDestroyOnDie) != 0; }
	inline bool denyDieDropdown() const { return (dwFlag & sfDenyDropdown) != 0; }
	inline bool dropdownOnDie() const { return (dwFlag & sfDieDropdown) != 0; }
	inline bool dropdownOnOffline() const { return (dwFlag & sfOfflineDropdown) != 0; }
	inline bool denySplite() const { return (dwFlag & sfDenySplite) != 0; }
	inline bool asQuestItem() const { return (dwFlag & sfAsQuestItem) != 0; }
	inline bool monAlwaysDropdown() const { return (dwFlag & sfMonAlwaysDropdown) != 0; }
	inline bool canUseOnPractice() const { return (dwFlag & sfUseOnPractice) != 0; }
	inline bool isInlayable() const { return (dwFlag & sfInlayable) != 0; }
public:
	unsigned int dwFlag;	//标志组1
};

/** 定义物品的使用条件结构 */
struct ItemUseCondition
{
	/** 定义物品的使用条件类型 **/
	enum UseCondition
	{
		ucLevel = 1,			//等级必须大于等于value级
		ucGender=2,				//性别编号必须等于value，0男1女
		ucJob=3,					//职业编号必须等于value
		ucMarried=4,		//结婚与否必须等于value
		ucMountSkillLevel=5,  //骑术等级
		ucCampTitle =6,       //需要阵营的官职
		ucCircle = 7,	//转生次数
		ucMaxCount,
	};
	char			btCond;	//条件类型
	int				nValue;	//条件值
};

/** 物品使用条件表 **/
struct ItemUseCondTable
{
	int				nCount;		//条件数量
	int            itemId;
	ItemUseCondition	*condi;//条件表
};

/************************************************************************/
 //                     游戏物品数据描述类
/************************************************************************/
struct CFItem /*: public Counter<CStdItem>*/
{
public:
	CFItem(){}
	~CFItem()
	{
		if (m_ExistScenes.pSceneId)
		{
			SafeDeleteArray(m_ExistScenes.pSceneId);
			m_ExistScenes.pSceneId = NULL;
		}
	}

public:
	/*
	* Comments: 物品是否含有区域相关属性（是否配置了离开某个区域要删除）。
	* @Return bool:
	*/
	inline bool hasSceneProp() const
	{
		//for(int i=0; i<m_existScenes.size(); i++)
		//{
		//	if(m_existScenes[i] != -1)
		//	{
		//		return true;
		//	}
		//}
		for (INT_PTR i = 0; i < m_ExistScenes.nCount; i++)
		{
			if (m_ExistScenes.pSceneId[i] != -1)
				return true;
		}

		return false;
	}

	/*
	* Comments: 查询是否应该离开指定的场景要删除物品
	* Param int nSceneId: 场景Id
	* @Return bool:
	*/
	inline bool needDelWhenExitScene(int nSceneId) const
	{
		//for(int i=0; i<m_existScenes.size(); i++)
		//{
		//	if(m_existScenes[i] == -1 || m_existScenes[i] == nSceneId)
		//	{
		//		return false;
		//	}
		//}
		for (INT_PTR i = 0; i < m_ExistScenes.nCount; i++)
		{
			if (m_ExistScenes.pSceneId[i] == -1 || m_ExistScenes.pSceneId[i] == nSceneId)
				return false;
		}

		return true;
	}

	/*
	* Comments: 初始化一件物品
	* Param CUserItem * pUserItem:物品的指针
	* @Return void:
	*/
	static void AssignInstance(CUserItem *pUserItem,const CFItem * pItem); 

public:
	int			   m_nItemId;			//物品唯一ID
	const char*	   sName;		        //物品名称
	unsigned short m_wIcon;			    //物品图标编号
	unsigned short m_wShape;			//物品外形编号，只对具有外形的装备类物品有意义，例如衣服、武器和坐骑
	char		   m_btType;			//物品类型，值为StdItem::ItemType的枚举类型
	char 		   m_btDupCount;		//物品允许叠加的数量
	char		   m_btColGroup;		//物品冷却组，对于使用后具有冷却时间的物品来说，相同冷却组的物品将同时进入冷却恢复状态
	char		   m_btDealType;		//物品在商店中交易的货币类型，类型为eMoneyType
	int			   m_nPrice;			//物品在商店中购买的价格，购买物品的货币类型通过成员m_btDealType的值限定
	unsigned int   m_dwDura;			//物品的耐久度，1000点在客户端中显示为1
	char		   m_btSmithId;		    //物品精锻ID，0表示不可精锻
	unsigned short m_wSuitID;           //套装的ID
	int			   m_nValidFbId;		//物品有效的副本ID。物品离开此副本自动删除。-1表示任何副本都不会删除
	int			   m_nValidSceneId;	    //物品有效的场景ID。物品离开此副本自动删除。-1表示任何场景都不会删除
	char		   b_btBreakId;		    //物品的分解的配置ID
	char           b_showQuality;       //显示的品质
	
	int            m_NumQualityAttr;//品质属性等级个数
	int			   m_NumStrongAttr;//强化属性等级个数

	ItemFlags				m_Flags;		//物品标志属性
	//CMiniDateTime			m_UseTime;		//使用时限
	ItemAttributeGroup**	m_StaticAttrs;	//物品静态属性表
	ItemAttributeGroup**	m_QualityAttrs;	//物品品质属性表
	ItemAttributeGroup**	m_StrongAttrs;	//物品强化属性表
	UnitedAttributeTable	m_UnitedAttrs;	//联合属性表
	RandomAttributeTable	m_SmithAttrs;	//精锻随机属性表（不参与属性运算，仅提供数据配置，将生成属性到CUserItem）
	ItemUseCondTable		m_Conditions;	//物品使用条件表
	ExistScenes				m_ExistScenes;	// 物品可存在的场景列表集合

};

