#include "StdAfx.h"

CLogicEventDispatcher::CLogicEventDispatcher()
{

}

CLogicEventDispatcher::~CLogicEventDispatcher()
{
	int i;
	for (i = (int)m_EventTypeList.size() - 1;i > -1;i--)
	{
		SafeDelete(m_EventTypeList.start[i]);
	}
	m_EventTypeList.clear();
}

void CLogicEventDispatcher::addEventListener(const int EventId, LogicEventHandler lpEventHandler)
{
	EventHandlerStruct handler;
	handler.lpEventHandler = lpEventHandler;

	if (EventId >=(int) m_EventTypeList.size())
	{
		int Count = (EventId + 1024) & (~1023);
		m_EventTypeList.insert(m_EventTypeList.size(), Count - m_EventTypeList.size(), true);
	}

	EventHandlerList *pHandlerList = m_EventTypeList.start[EventId];
	if (!pHandlerList)
	{
		m_EventTypeList.start[EventId] = pHandlerList = new EventHandlerList();
	}
	pHandlerList->add(handler);
}

void CLogicEventDispatcher::removeEventListener(const int EventId, LogicEventHandler lpEventHandler)
{
	if (EventId >=(int) m_EventTypeList.size())
		return ;
	EventHandlerList *pHandlerList = m_EventTypeList.start[EventId];
	if (pHandlerList)
	{
		for (int i=(int)pHandlerList->size()-1; i>-1; --i)
		{
			if (pHandlerList->start[i].lpEventHandler == lpEventHandler)
			{
				pHandlerList->remove(i, 1);
			}
		}
	}
}

void CLogicEventDispatcher::dispatchEvent(LogicEvent &event)
{
	if (event.eventId >= (int)m_EventTypeList.size())
		return ;
	EventHandlerList *pHandlerList = m_EventTypeList[event.eventId];
	if (pHandlerList)
	{
		EventHandlerStruct *handlers = pHandlerList->start;
		for (int i=(int)pHandlerList->size()-1; i>-1; --i)
		{
			handlers[i].lpEventHandler(&event);//注册过哪些函数就派发到哪些函数上处理
		}
	}
}

void CLogicEventDispatcher::testLogicEventDispatcher()
{
	if (!g_LogicEngine)return;
	static long nCount = 0;
	printf("test logic event dispatch,Counter (%ld)\n",++nCount);
	CPlayer* player = new CPlayer();
	player->m_EntityId.llid = 100;
	strcpy(player->m_sName ,"playerName");

	LogicEvent loginEvent(leLogin,player);
	g_LogicEngine->dispatchLogicEvent(loginEvent);

	LogicEvent enterGameEvent(leEnterGamer,player); 
	g_LogicEngine->dispatchLogicEvent(enterGameEvent);

	LogicEvent leaveGameEvent(leOffline,player);
	g_LogicEngine->dispatchLogicEvent(leaveGameEvent);
	moon::OS::osSleep(1000);
}
