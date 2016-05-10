#include "StdAfx.h"
using namespace std;

SceneAccessor::SceneAccessor()
{
	m_pBirthScene = NULL;
	m_pUrgentScene = NULL;
}

SceneAccessor::~SceneAccessor()
{
	g_MapArchiverManager = NULL;
	m_pBirthScene = NULL;
	m_pUrgentScene = NULL;
	m_mapNameSceneStructList.clear();
}

bool SceneAccessor::loadConfig()
{
	/*assert(g_LogicDataConfig);
	m_pBirthScene = &g_LogicDataConfig->m_birthScene;
	m_pUrgentScene = &g_LogicDataConfig->m_urgentScene;

	 CSVDocument doc;
#define DCL(name, fn) {\
	if (!CConfigManager::LoadCSVDocument(doc, "./config/"name))\
	return false;\
	fn(doc); }

	 DCL("scene/scene.csv", readScenes);
	 DCL("scene/sceneNPC.csv", readSceneNpcs);
	 DCL("scene/sceneGates.csv",readSceneGates);
	 DCL("scene/duplicate.csv",readDuplicates);
	 g_MapArchiverManager = &m_mapArchiverManager;*/
	 return true;
}



//
//void SceneAccessor::readScenes(CSVDocument &doc) 
//{
//	int cId = doc.getColumnIndex(UTF8String("id"));
//	int cName = doc.getColumnIndex(UTF8String("\xE5\x9C\xBA\xE6\x99\xAF\xE5\x90\x8D\xE7\xA7\xB0"));
//	int cType = doc.getColumnIndex(UTF8String("\xE5\x9C\xBA\xE6\x99\xAF\xE7\xB1\xBB\xE5\x9E\x8B"));
//	int cWeather = doc.getColumnIndex(UTF8String("\xE5\xA4\xA9\xE6\xB0\x94"));
//	int cMusic = doc.getColumnIndex(UTF8String("\xE8\x83\x8C\xE6\x99\xAF\xE9\x9F\xB3\xE4\xB9\x90"));
//	int cMap = doc.getColumnIndex(UTF8String("\xE5\x9C\xBA\xE6\x99\xAF\xE5\x9C\xB0\xE5\x9B\xBE\xE5\x90\x8D"));
//
//	int maxId = 0;
//	const int totalCount = (int)doc.numRows();
//	SceneStruct *scenes = m_Allocator.Alloc<SceneStruct>(totalCount);
//	for (int i=0; i<totalCount; ++i)
//	{
//		SceneStruct *scene = &scenes[i];
//		scene->id = doc.getValue(i, cId);
//		scene->name = m_Allocator.AllocStr(doc.getValue(i, cName));
//		scene->type = (BYTE)doc.getValue(i, cType);
//		scene->weather = doc.getValue(i, cWeather);
//		scene->mapFileName = m_Allocator.AllocStr(doc.getValue(i, cMap));
//		scene->music = m_Allocator.AllocStr(doc.getValue(i, cMusic));
//		maxId = max(maxId, scene->id);
//	}
//
//	m_sceneStructList.setLength(maxId + 1);
//	memset(m_sceneStructList.own_ptr(), 0, sizeof(m_sceneStructList.ptr()[0]) * (maxId + 1));
//	SceneStruct **sceneList = m_sceneStructList.own_ptr();
//	for (int i=0; i<totalCount; ++i)
//	{
//		SceneStruct *scene = &scenes[i];
//		sceneList[scene->id] = scene;
//		addSceneByMapName(scene->mapFileName,scene);
//		addSceneBySceneName(scene->name,scene);
//		//地图信息加载到MapArchiverManager
//		m_mapArchiverManager.readFile(scene->mapFileName);
//		//添加到静态场景列表
//		if (0 == scene->type)
//		{
//			m_staicSceneList.push_back(scene->id);
//		}
//	}
//
//}
//
//void SceneAccessor::readSceneNpcs( CSVDocument &doc )
//{
//	int cId = doc.getColumnIndex(UTF8String("NPCID"));
//	int cName = doc.getColumnIndex(UTF8String("\xE5\x90\x8D\xE7\xA7\xB0"));
//	int cSceneId = doc.getColumnIndex(UTF8String("\xE5\x9C\xBA\xE6\x99\xAFID"));
//	int cBody = doc.getColumnIndex(UTF8String("\xE5\xA4\x96\xE5\xBD\xA2"));
//	int cX = doc.getColumnIndex(UTF8String("\xE5\x9D\x90\xE6\xA0\x87X"));
//	int cY = doc.getColumnIndex(UTF8String("\xE5\x9D\x90\xE6\xA0\x87Y"));
//	int cScript = doc.getColumnIndex(UTF8String("\xE8\x84\x9A\xE6\x9C\xAC"));
//	int cDefaultTalk1 = doc.getColumnIndex(UTF8String("\xE9\xBB\x98\xE8\xAE\xA4\xE5\xAF\xB9\xE8\xAF\x9D\x31"));
//	int cDefaultTalk2 = doc.getColumnIndex(UTF8String("\xE9\xBB\x98\xE8\xAE\xA4\xE5\xAF\xB9\xE8\xAF\x9D\x32"));
//	int cDefaultTalk3 = doc.getColumnIndex(UTF8String("\xE9\xBB\x98\xE8\xAE\xA4\xE5\xAF\xB9\xE8\xAF\x9D\x33"));
//
//	SceneStruct **sceneList = m_sceneStructList.own_ptr();
//	const int sceneCount = (int)m_sceneStructList.length();
//
//	int maxId = 0;
//	const int totalCount = (int)doc.numRows();
//	SceneNpc *npcList = m_Allocator.Alloc<SceneNpc>(totalCount);
//	for (int i=0; i<totalCount; ++i)
//	{
//		SceneNpc *npc = &npcList[i];
//		npc->sceneId = doc.getValue(i, cSceneId);
//		if (npc->sceneId > 0 && npc->sceneId < sceneCount && sceneList[npc->sceneId])
//		{
//			npc->npcId = doc.getValue(i, cId);
//			npc->name = m_Allocator.AllocStr(doc.getValue(i, cName));
//			npc->body = doc.getValue(i, cBody);
//			npc->x = doc.getValue(i, cX);
//			npc->y = doc.getValue(i, cY);
//			npc->script =  m_Allocator.AllocStr(doc.getValue(i, cScript));
//			npc->defaultTalk[0] =  m_Allocator.AllocStr(doc.getValue(i, cDefaultTalk1));
//			npc->defaultTalk[1] =  m_Allocator.AllocStr(doc.getValue(i, cDefaultTalk2));
//			npc->defaultTalk[2] =  m_Allocator.AllocStr(doc.getValue(i, cDefaultTalk3));
//			maxId = max(maxId, npc->npcId);
//		}
//	}
//
//	m_sceneNpcList.setLength(maxId + 1);
//	memset(m_sceneNpcList.own_ptr(), 0, sizeof(m_sceneNpcList.ptr()[0]) * (maxId + 1));
//	PSceneNpc *sceneNpcList = m_sceneNpcList.own_ptr();
//	for (int i=0; i<totalCount; ++i)
//	{
//		SceneNpc* npc = &npcList[i];
//		sceneNpcList[npc->npcId] = npc;
//	}
//}
//
//
const std::vector<PSceneNpc>* SceneAccessor::getSceneNpcListBySceneID( int sceneId )
{
	int i;
	std::vector<PSceneNpc>* ppSceneNpcL = new std::vector<PSceneNpc>;
	SceneNpc** tmpSceneNpc = m_sceneNpcList.own_ptr();
	for (i = (int)m_sceneNpcList.length()- 1;i >= 0;i--)
	{
		if (tmpSceneNpc[i]&&tmpSceneNpc[i]->sceneId == sceneId)
		{
			ppSceneNpcL->push_back(tmpSceneNpc[i]);
		}
	}
	return ppSceneNpcL;
}


void SceneAccessor::addSceneByMapName(const std::string &mapName,PSceneStruct pSceneStruct )
{
	//地图名称索引场景结构
	if (mapName.empty()||!pSceneStruct)
		assert(0);
	m_mapNameSceneStructList[mapName] = pSceneStruct;
}

void SceneAccessor::addSceneBySceneName( const std::string &sceneName,PSceneStruct pSceneStruct )
{
	//场景名称索引场景结构
	if (sceneName.empty()||!pSceneStruct)
		assert(0);
	m_sceneNameSceneStructList[sceneName] = pSceneStruct;
}


const PSceneStruct SceneAccessor::getSceneStructByMapName( const std::string &mapName )
{
	//由地图名称获取场景结构
	if (m_mapNameSceneStructList.find(mapName) == m_mapNameSceneStructList.end())
		return NULL;
	return m_mapNameSceneStructList[mapName];
}

const PSceneStruct SceneAccessor::getSceneStructBySceneName( const std::string &sceneName )
{
	//由场景名称获取场景结构
	if (m_sceneNameSceneStructList.find(sceneName) == m_sceneNameSceneStructList.end())
		return NULL;
	return m_sceneNameSceneStructList[sceneName];
}

int SceneAccessor::getSceneIdByMapName( const std::string &mapName )
{
	if (m_mapNameSceneStructList.find(mapName) == m_mapNameSceneStructList.end())
		return -1;
	SceneStruct* sceneStruct = m_sceneNameSceneStructList[mapName];
	if (!sceneStruct)
		return -1;
	return sceneStruct->id;
}

const char* SceneAccessor::getMapNameBySceneID( int sceneId )
{
	//由场景id获取场景名
	const PSceneStruct pSceneStruct = getSceneByID(sceneId);
	if (!pSceneStruct) return NULL;
	return pSceneStruct->mapFileName;
}



//
//void SceneAccessor::readSceneGates(CSVDocument& doc)
//{
//	int cId = doc.getColumnIndex(UTF8String("\xE4\xBC\xA0\xE9\x80\x81\xE9\x97\xA8ID"));
//	int cSceneId = doc.getColumnIndex(UTF8String("\xE5\x9C\xBA\xE6\x99\xAFID"));
//	int cX = doc.getColumnIndex(UTF8String("X"));
//	int cY = doc.getColumnIndex(UTF8String("Y"));
//	int cTargetId = doc.getColumnIndex(UTF8String("\xE7\x9B\xAE\xE6\xA0\x87\xE5\x9C\xBA\xE6\x99\xAFID"));
//	int cTargetX = doc.getColumnIndex(UTF8String("\xE7\x9B\xAE\xE6\xA0\x87X"));
//	int cTargetY = doc.getColumnIndex(UTF8String("\xE7\x9B\xAE\xE6\xA0\x87Y"));
//
//	const int totalCount = (int)doc.numRows();
//	int maxId = 0;
//	SceneGate *gates = m_Allocator.Alloc<SceneGate>(totalCount);
//	for (int i=0; i<totalCount; ++i)
//	{
//		SceneGate &gate = gates[i];
//		gate.gateId = doc.getValue(i, cId);
//		gate.sceneId = doc.getValue(i, cSceneId);
//		gate.x = doc.getValue(i, cX);
//		gate.y = doc.getValue(i, cY);
//		gate.targetId = doc.getValue(i, cTargetId);
//		gate.targetX = doc.getValue(i, cTargetX);
//		gate.targetY = doc.getValue(i, cTargetY);
//		if (gate.gateId > maxId)
//			maxId = gate.gateId;
//	}
//
//	m_gateList.clear();
//	SceneGate **gateList = m_gateList.insert(0, maxId + 1, true);
//	for (int i=0; i<totalCount; ++i)
//	{
//		SceneGate &gate = gates[i];
//		gateList[gate.gateId] = &gate;
//	}
//
//}
//
//void SceneAccessor::readDuplicates( CSVDocument& doc )
//{
//	int cId = doc.getColumnIndex(UTF8String("\xE5\x89\xAF\xE6\x9C\xACid"));											
//	int cName = doc.getColumnIndex(UTF8String("\xE5\x89\xAF\xE6\x9C\xAC\xE5\x90\x8D\xE7\xA7\xB0"));	
//	int cScene1 = doc.getColumnIndex(UTF8String("\xE5\x9C\xBA\xE6\x99\xAF\x31"));	
//	int cScene2 = doc.getColumnIndex(UTF8String("\xE5\x9C\xBA\xE6\x99\xAF\x32"));	
//	int cScene3 = doc.getColumnIndex(UTF8String("\xE5\x9C\xBA\xE6\x99\xAF\x33"));	
//	int cScene4 = doc.getColumnIndex(UTF8String("\xE5\x9C\xBA\xE6\x99\xAF\x34"));	
//	int cScene5 = doc.getColumnIndex(UTF8String("\xE5\x9C\xBA\xE6\x99\xAF\x35"));	
//	int cScene6 = doc.getColumnIndex(UTF8String("\xE5\x9C\xBA\xE6\x99\xAF\x36"));	
//	int cScene7 = doc.getColumnIndex(UTF8String("\xE5\x9C\xBA\xE6\x99\xAF\x37"));	
//	int cScene8 = doc.getColumnIndex(UTF8String("\xE5\x9C\xBA\xE6\x99\xAF\x38"));	
//	int cX = doc.getColumnIndex(UTF8String("X\xE5\x9D\x90\xE6\xA0\x87"));	
//	int cY = doc.getColumnIndex(UTF8String("Y\xE5\x9D\x90\xE6\xA0\x87"));	
//
//	const int totalCount = (int)doc.numRows();
//	int maxId = 0;
//	DuplicateStruct *duplicates = m_Allocator.Alloc<DuplicateStruct>(totalCount);
//	for (int i=0; i<totalCount; ++i)
//	{
//		DuplicateStruct* duplicate = &duplicates[i];
//		duplicate->duplicateId = doc.getValue(i, cId);//副本id
//		duplicate->duplicateName = m_Allocator.AllocStr(doc.getValue(i, cName));//	副本名称
//		duplicate->sceneIdList[0] = doc.getValue(i, cScene1);	//	场景1 id
//		duplicate->sceneIdList[1] = doc.getValue(i, cScene2);	//	场景2 id
//		duplicate->sceneIdList[2] = doc.getValue(i, cScene3);	//	场景3 id
//		duplicate->sceneIdList[3] = doc.getValue(i, cScene4);	//	场景4 id
//		duplicate->sceneIdList[4] = doc.getValue(i, cScene5);	//	场景5 id
//		duplicate->sceneIdList[5] = doc.getValue(i, cScene6);	//	场景6 id
//		duplicate->sceneIdList[6] = doc.getValue(i, cScene7);	//	场景7 id
//		duplicate->sceneIdList[7] = doc.getValue(i, cScene8);	//	场景8 id
//		duplicate->x = doc.getValue(i, cX);	//	X坐标
//		duplicate->y = doc.getValue(i, cY);	//	Y坐标
//		if (duplicate->duplicateId > maxId)
//			maxId = duplicate->duplicateId;
//	}
//
//	m_duplicateStructList.setLength(maxId + 1);
//	memset(m_duplicateStructList.own_ptr(), 0, sizeof(m_duplicateStructList.ptr()[0]) * (maxId + 1));
//	PDuplicate *duplicateList = m_duplicateStructList.own_ptr();
//
//	for (int i=0; i<totalCount; ++i)
//	{
//		DuplicateStruct* duplicate = &duplicates[i];
//		duplicateList[duplicate->duplicateId] = duplicate;
//	}
//}
//
const SceneGate* SceneAccessor::getSceneGate(const int gateId)
{
	if (gateId < 0 || gateId >= (int)m_gateList.size())
		return NULL;
	return m_gateList.start[gateId];
}

void SceneAccessor::pushToNpcDefaultTalk(lua_State *L, const char* talk, int npcid)
{
	size_t nLen = 0;
	//打开NPCID为下标的表
	lua_rawgeti(L, -1, npcid);
	if (!lua_istable(L, -1))
	{
		lua_pop(L, 1);//弹出栈顶元素
		lua_newtable(L);
		lua_pushvalue(L, -1);
		lua_rawseti(L, -3, npcid);
	}

	//向DefaultTalk表添加内容
	lua_getfield(L, -1, "DefaultTalk");
	if (!lua_istable(L, -1))
	{
		lua_pop(L, 1);
		lua_newtable(L);
		lua_pushvalue(L, -1);
		lua_setfield(L, -3, "DefaultTalk");
	}
	nLen = lua_objlen(L, -1);
	lua_pushstring(L, talk);
	lua_rawseti(L, -2, int(nLen+1));
	lua_pop(L, 1);

	//关闭NPCID为下标的表
	lua_pop(L, 1);
}

//创建NPC默认对话的table
void SceneAccessor::makeNpcDefaultTalkData()
{
	SceneNpc **ppNpcList = m_sceneNpcList.own_ptr();
	INT_PTR nCount = m_sceneNpcList.length();
	lua_State *L = g_Script->getLuaState();
	lua_newtable(L);
	for (INT_PTR i = 1; i < nCount; ++i)
	{
		pushToNpcDefaultTalk(L, ppNpcList[i]->defaultTalk[0], ppNpcList[i]->npcId);
		pushToNpcDefaultTalk(L, ppNpcList[i]->defaultTalk[1], ppNpcList[i]->npcId);
		pushToNpcDefaultTalk(L, ppNpcList[i]->defaultTalk[2], ppNpcList[i]->npcId);
	}
	lua_setglobal(L, "NpcDefaultTalk");
}

const DuplicateStruct* SceneAccessor::getDuplicateStruct( const int duplicateId )
{
	if (duplicateId >= (int)m_duplicateStructList.length()||duplicateId<0)
		return NULL;
	return m_duplicateStructList[duplicateId];
}

