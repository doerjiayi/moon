#pragma once
#include "moonLib/memory/BaseObject.h"
#include "scriptValue.h"

class ScriptSystem : public CBaseObject
{
protected:
	lua_State* m_pLua;//该脚本系统的脚本执行环境
public:
	ScriptSystem();
	~ScriptSystem();
	//加载脚本代码到脚本环境
	//内部使用lua_dostring加载脚本。如果加载失败则函数返回false。
	bool loadScript(const char* buffer);
	//从文件加载脚本代码到脚本环境
	//内部实现为lua_dofile加载脚本
	virtual bool loadScriptFromFile(const char* fileName);
	//清空脚本
	//内部使用lua_close关闭脚本执行环境
	virtual void clear();
	//执行脚本函数
	//参数fname为函数名称，args为脚本参数表，results为返回值表
	//执行脚本遇到错误，则函数返回false并在results的第一个值中存储错误描述字符串。
	//参数args以及results都允许传递NULL值，如果args为NULL则表示调用没有参数，
	//如果results为NULL则表示调用不接收返回值。
	virtual bool exec(const char* fname, const ScriptValueList*args, ScriptValueList *results);

	//加载lua和c++交互接口
	bool loadServerInterface();

	lua_State* getLuaState(){return m_pLua;}
};


class ScriptSystemLoad//初始化脚本
{
public:
	ScriptSystemLoad();
	//析构游戏脚本
	~ScriptSystemLoad();
	//初始化游戏脚本
	bool init();
	//测试使用
	static void testScriptSystemLoad();
protected:
	bool initNPCScript();//初始化npc脚本
	//装载npc脚本
	bool loadNPCScript(unsigned long long npcId, const char* npcName, const char* fileName);
	//加载lua和c++交互接口
	bool loadLuaServerInterface();
};



