#ifndef __LOGIC_EVENT_H__
#define __LOGIC_EVENT_H__

/* 玩家事件类型定义 */
enum LogicEventType
{
	/* 玩家基本事件定义 */
	leActorEventBegin = 1,
	leLogin = leActorEventBegin,//玩家登陆
	leEnterGamer,//玩家进入游戏
	leOffline,//玩家离线
	leActorEventEnd,

	/* 玩家物品事件定义 */
	leActorItemEventBegin = 101,
	leAddItem = leActorItemEventBegin,//获得物品
	leDelItem,//删除物品
	leTakeOnItem,//玩家穿上装备
	leTakeOffItem,//玩家脱掉装备
	leItemExpired,//玩家物品到期
	leActorItemEventEnd,

	leActorDie	=	201,		//角色死亡,sender=死亡者，n1=击杀者指针
	leActorRevivicent,			//角色复活,sender=复活者
	leLevelChange,				//角色等级改变，sender=升级者
};

/** 事件基础类 **/
class LogicEvent
{
public:
	inline LogicEvent() 
	{ 
		eventId = 0; 
		sender = NULL;
		n1 = n2 = n3 = n4 = 0;
		::time(&tm);
	}
	inline LogicEvent(int nEventId, CBaseObject* pSender) 
	{ 
		eventId = nEventId; 
		sender = pSender;
		n1 = n2 = n3 = n4 = 0;
		::time(&tm);
	}
public:
	int eventId;//事件ID
	CBaseObject* sender;
	INT_PTR n1;
	INT_PTR n2;
	INT_PTR n3;
	INT_PTR n4;
	std::string s1;
	std::string s2;
	std::string s3;
	std::string s4;
	time_t tm;
};

#endif
