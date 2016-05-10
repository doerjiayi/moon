#include "StdAfx.h"
#include "scriptSystem.h"

ScriptSystem::ScriptSystem()
{
	m_pLua = lua_open();
	luaL_openlibs(m_pLua);
}

ScriptSystem::~ScriptSystem()
{
	if (m_pLua)
	{
		lua_close(m_pLua);
		m_pLua = NULL;
	}
}


bool ScriptSystem::loadScript( const char* buffer )
{
	if (!buffer)
	{
		logError("buffer为空");
		return false;
	}
	if(!m_pLua)
	{
		logError("lua虚拟机为空");
		return false;
	}

	int err = luaL_dostring(m_pLua,buffer);
	
	if (!err)return true;

	const char* result = lua_tostring(m_pLua, -1);
	logError("loadScript result:%s\n",result);
	return false;
}

bool ScriptSystem::loadScriptFromFile( const char* fileName )
{
	if (!fileName)
	{
		logError("文件名为空");
		return false;
	}
	if(!m_pLua)
	{
		logError("lua虚拟机为空");
		return false;
	}
	int err = lua_dofile(m_pLua,fileName);
	if (!err)return true;

	const char* result = lua_tostring(m_pLua, -1);
	logError("loadScriptFromFile error result:(%s)",result);
	return false;
}

void ScriptSystem::clear()
{
	if(m_pLua)
	{
		lua_close(m_pLua);
		m_pLua = NULL;
	}
}

bool ScriptSystem::exec(const char* fname, const ScriptValueList* args, ScriptValueList *results )
{
	int i;
	int args_count = 0;
	if (args)args_count = args->count;
	
	lua_getglobal(m_pLua,fname);

	//压入参数
	for (i = 0;i < args_count;i++)
	{
		ScriptValue scriptValue = args->values[i];
		if (ScriptValue::vNumber == scriptValue.type)
		{
			lua_pushnumber(m_pLua,scriptValue.data.d);
		}
		else if (ScriptValue::vInterger == scriptValue.type)
		{
			lua_pushinteger(m_pLua,scriptValue.data.i);
		}
		else if (ScriptValue::vString == scriptValue.type)
		{
			lua_pushstring(m_pLua,scriptValue.data.str);
		}
		else if (ScriptValue::vBool == scriptValue.type)
		{
			lua_pushboolean(m_pLua,scriptValue.data.i);
		}
		else if (ScriptValue::vPointer == scriptValue.type)
		{
			lua_pushlightuserdata(m_pLua,scriptValue.data.ptr);
		}
		else if (ScriptValue::vBaseObject == scriptValue.type)
		{
			tolua_pushusertype(m_pLua,scriptValue.data.ptr,"CBaseObject");
		}
		else if (ScriptValue::vEntity == scriptValue.type)
		{
			tolua_pushusertype(m_pLua,scriptValue.data.ptr,"CEntity");
		}
		else if (ScriptValue::vActor == scriptValue.type)
		{
			tolua_pushusertype(m_pLua,scriptValue.data.ptr,"CDoer");
		}
		else if (ScriptValue::vPlayer == scriptValue.type)
		{
			tolua_pushusertype(m_pLua,scriptValue.data.ptr,"CPlayer");
		}
		else
		{
			lua_pushnil(m_pLua);
		}
	}
	
	if (!results)//不需要返回值
	{
		int err = lua_pcall(m_pLua,args_count,0,0);
		if (err)
		{
			const char* result = lua_tostring(m_pLua, -1);
			logInfo("lua_pcall result:%s\n",result);
//			return false;
		}
	}
	else
	{
		int err = lua_pcall(m_pLua,args_count,1,0);
		const char* result = lua_tostring(m_pLua, -1);
		if (err)
		{
			logInfo("lua_pcall result:%s\n",result);
			//return false;
		}
		if (result)
		{
			logDebug("lua_pcall result:%s\n",result);
			results->push(result);
		}
	}
	//清除堆栈
	int stackNum = lua_gettop(m_pLua);
	if (stackNum)
	{
		lua_pop(m_pLua,stackNum);
	}
	return true;
}

bool ScriptSystem::loadServerInterface()
{
	if (!m_pLua)
	{
		printf("loadServerInterface m_pLua is null\n");
		return false;	
	}
	//注册lua与c++交互接口
	luaopen_serverLuaInterface(m_pLua);
	return true;
}

bool ScriptSystemLoad::init()
{
	if (!initNPCScript())
	{
		printf("initNPCScript error\n");
		return false;
	}
	bool res = loadLuaServerInterface();
	if (!res)
	{
		printf("loadLuaServerInterface error\n");
		return false;
	}

	//testScriptSystemLoad();
	return true;
}

bool ScriptSystemLoad::loadNPCScript( unsigned long long npcId, const char* npcName, const char* fileName )
{
	char sBuffer[1024];
	char *ptr = sBuffer;

	if (npcId < 0 || !npcName || !fileName)
		return false;

	//NPC脚本文件读取后，将内容包装为一个向npcTable中的此
	//npcId下标的值进行赋值的语句，并调用g_NPCScript->loadScript
	//加载到脚本中虚拟机中
	ptr += sprintf(ptr, 
		"local temp = require(\"scripts/npc/%s\") \r\n"
		"temp.npcId = %llu \r\n"
		"temp.npcName = \"%s\" \r\n"
		"npcTable[%llu] = temp \r\n "
		, fileName, npcId, npcName, npcId);

	ptr[0] = 0;
	
	bool res = g_Script->loadScript(sBuffer);
	if (false == res)
	{
		printf("g_NPCScript loadScript error\n");
		return false;
	}
	return true;
}

ScriptSystemLoad::ScriptSystemLoad()
{

}

ScriptSystemLoad::~ScriptSystemLoad()
{
	if (g_Script)g_Script->release();
}

bool ScriptSystemLoad::initNPCScript()
{
	if(!g_Script)
	{
		//加载NPCEntry脚本
		g_Script = new ScriptSystem();
		bool res = g_Script->loadScriptFromFile("./scripts/npc/NPCEntry.lua");
		if (!res)
		{
			printf("g_NPCScript loadScriptFromFile error\n");
			return false;
		}
	}
	//加载各个npc的脚本
	int i;
	lib::container::Array<PSceneNpc>* pSceneNpcList = g_ConfigManager->sceneDataAccessor.getScenePeopleList();
	for (i = (int)pSceneNpcList->length() -1;i >-1;i--)
	{
		SceneNpc* sceneNpc = (*pSceneNpcList)[i];
		if (sceneNpc)
		{
			bool loadNpcRes = loadNPCScript(sceneNpc->npcId,sceneNpc->name,sceneNpc->script);
			if (!loadNpcRes)
			{
				printf("load npc script error\n");
				return false;
			}
		}
	}
	g_ConfigManager->missionDataProvider.makeNPCQuestData();
	g_ConfigManager->missionDataProvider.makeScriptQuestData();
	g_ConfigManager->sceneDataAccessor.makeNpcDefaultTalkData();
	return true;
}

bool ScriptSystemLoad::loadLuaServerInterface()
{
	if (!g_Script)
	{
		printf("loadLuaServerInterface:g_NPCScript is null\n");
		return false;
	}
	bool res =  g_Script->loadServerInterface();
	if (!res)
	{
		printf("loadServerInterface error\n");
		return false;
	}
	return true;
}

void ScriptSystemLoad::testScriptSystemLoad()
{
	//ScriptSystemLoad::instance()->init();
	//ScriptSystemLoad::instance()->loadNPCScript(1,"npc1","./scripts/npc/npc1");//require npc1.txt脚本
	//ScriptSystemLoad::instance()->loadNPCScript(2,"npc2","./scripts/npc/npc2");//require npc2.txt脚本
	ScriptValueList args;
	ScriptValueList results;

	CPlayer* player = new CPlayer();
	strcpy(player->m_sName,"playerName");
	player->m_nAccountId = 100;
	player->m_nX = 200;
	player->m_nY = 300;
	//player->m_NpcTalk.setNpcID(1);

 	args.clear();
	args.push(player);
 	g_Script->exec("testSceneManager",&args, &results );

	//args.clear();
	//args.push(2);//npcId 
	//args.push(player);
	//args.push("QC.acceptQuestStep");
	//args.push(1);//npcID
	//args.push(1);//questID
	//args.push(1);//talkIdx
	//g_NPCScript->exec("talkNPC",&args,&results);
	//player->release();

	//args.clear();
	//args.push(2);//npcId 
	//args.push(NULL);
	//args.push("QC.completeQuestStep");
	//args.push(1);//npcID
	//args.push(1);//questID
	//args.push(1);//talkIdx
	//g_NPCScript->exec("talkNPC",&args,&results);


	//args.clear();
	//args.push(2);//npcId 
	//args.push(NULL);
	//args.push("QC.acceptQuestStep");
	//args.push(1);//npcID
	//args.push(1);//questID
	//args.push(1);//talkIdx
	//g_NPCScript->exec("talkNPC",&args,&results);
}
















