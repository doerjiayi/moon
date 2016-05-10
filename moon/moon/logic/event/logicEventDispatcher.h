#ifndef __LOGIC_EVENT_DISPATCHER_H__
#define __LOGIC_EVENT_DISPATCHER_H__

class LogicEvent;

typedef void (*LogicEventHandler)(LogicEvent*);//事件函数

class CLogicEventDispatcher
{
public:
	struct EventHandlerStruct
	{
		LogicEventHandler lpEventHandler;
	};
	typedef MemoryBlock<EventHandlerStruct, 8> EventHandlerList;//事件句柄列表
	typedef MemoryBlock<EventHandlerList*, 2048> EventTypeList;//所有的事件的列表

public:
	CLogicEventDispatcher();
	virtual ~CLogicEventDispatcher();

	void addEventListener(const int EventId, LogicEventHandler lpEventHandler);
	void removeEventListener(const int EventId, LogicEventHandler lpEventHandler);
	void dispatchEvent(LogicEvent &event);
	static void testLogicEventDispatcher();
private:
	EventTypeList m_EventTypeList;
};

#endif
