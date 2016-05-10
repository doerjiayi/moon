#pragma once
#include <memory.h>
#include "moonLib/memory/BaseObject.h"

class CBaseObject;
class CEntity;
class CDoer;
class CPlayer;

class ScriptValue
{
public:
	//脚本值类型
	enum ValueType
	{
		vNumber = 0,
		vInterger = 1,
		vString = 2,
		vBool = 3,
		vPointer = 4,
		vBaseObject = 5,
		vEntity = 6,
		vActor = 7,
		vPlayer = 8,
	};
	~ScriptValue() { clear(); }

	inline void operator = (const int v){type = vInterger;data.i = v;}//从整数赋值
	inline void operator = (const double d){type = vNumber;data.d = d;}//从浮点数赋值
	inline void operator = (void* ptr){type = vPointer;data.ptr = ptr;}//从指针赋值
	inline void operator = (const bool b){type = vBool;data.i = b;}//从布尔赋值
	inline void operator = (const char* str){type = vString; data.str = str;}//从字符串指针赋值
	inline void operator = (CBaseObject* obj){type = vBaseObject; data.ptr = obj;}//从CBaseObject指针赋值
	inline void operator = (CEntity* obj){type = vEntity; data.ptr = obj;}//从CEntity指针赋值
	inline void operator = (CDoer* obj){type = vActor; data.ptr = obj;}//从CDoer指针赋值
	inline void operator = (CPlayer* obj){type = vPlayer; data.ptr = obj;}//从CPlayer指针赋值
	 
	inline void clear(){memset(&data,0,sizeof(data));}
public:
	ValueType type;
	union {
		double d;
		int i;
		void* ptr;
		const char* str;
	}data;
};


class ScriptValueList : public CBaseObject
{
public:
	static const int MaxValueCount = 8;//脚本值列表最多值数量
public:
	int count;
	ScriptValue values[MaxValueCount];

public:
	ScriptValueList(){ count = 0; memset(values, 0, sizeof(values)); }
	~ScriptValueList(){ clear(); }
	//添加一个整数值
	bool push(int v);
	//添加一个浮点值
	bool push(double v);
	//添加一个布尔值
	bool push(bool b);
	//添加一个字符串值
	bool push(const char* str);
	//添加一个指针值
	bool push(void* ptr);
	//添加一个CBaseObject值
	bool push(CBaseObject* ptr);
	//添加一个CEntity值
	bool push(CEntity* ptr);
	//添加一个CDoer值
	bool push(CDoer* ptr);
	//添加一个CPlayer值
	bool push(CPlayer* ptr);
	//添加一个脚本值
	bool push(const ScriptValue &v);
	//清空数据
	inline void clear()
	{
		for (int i= count-1; i>-1; --i)
		{
			values[i].clear();
		}
		count = 0;
	}
};
