#pragma once


class SceneAccessor
{
public:
	SceneAccessor();
	~SceneAccessor();
	bool loadConfig();

	//void readScenes(CSVDocument &doc);
	//void readSceneNpcs( CSVDocument &doc);
	//void readSceneGates(CSVDocument& doc);
	//void readDuplicates(CSVDocument& doc);

	void addSceneByMapName(const std::string &mapName,PSceneStruct pSceneStruct);
	void addSceneBySceneName(const std::string &sceneName,PSceneStruct pSceneStruct);

	inline const PSceneStruct getSceneByID(uint32 sceneId)
	{
		if (sceneId >= m_sceneStructList.length())return NULL;
	 return m_sceneStructList[sceneId];
	}
	inline PSceneNpc getSceneNpcByNpcID(uint32 npcId)
	{
		if (npcId >= m_sceneNpcList.length())return NULL;
		return m_sceneNpcList[npcId];
	}
	const std::vector<PSceneNpc>* getSceneNpcListBySceneID(int sceneId);//获取指定场景id的npc列表
	const PSceneStruct getSceneStructByMapName(const std::string &mapName);
	const PSceneStruct getSceneStructBySceneName(const std::string &sceneName);
	int  getSceneIdByMapName(const std::string &mapName);
	const char* getMapNameBySceneID(int sceneId);
	lib::container::Array<PSceneNpc>* getScenePeopleList(){return &m_sceneNpcList;}
	const SceneGate* getSceneGate(const int gateId);
	const DuplicateStruct* getDuplicateStruct(const int duplicateId);

	inline SceneBase* getBirthScene(){assert(m_pBirthScene);return m_pBirthScene;}
	inline SceneBase* getUrgentScene(){assert(m_pUrgentScene);return m_pUrgentScene;}
	////创建NPC默认对话的table
	void makeNpcDefaultTalkData();
	void pushToNpcDefaultTalk(lua_State *L, const char* talk, int npcid);

public:
	lib::container::Array<PSceneStruct>  m_sceneStructList;//场景表：scene.csv ,场景id为索引
	std::map<std::string,PSceneStruct> m_mapNameSceneStructList;//场景表：scene.csv  地图名索引场景结构（读取自场景表scene.csv）
	std::map<std::string,PSceneStruct> m_sceneNameSceneStructList;
	lib::container::Array<PSceneNpc> m_sceneNpcList;//场景人物表：sceneEvent.csv
	std::vector<int> m_staicSceneList;//静态场景id列表
	MemoryBlock<SceneGate*, 16> m_gateList;
	lib::container::Array<DuplicateStruct*> m_duplicateStructList;
	SceneBase* m_pBirthScene;//新手村
	SceneBase* m_pUrgentScene;//应急场景
	CConfigAllocator	m_Allocator;//对象内存分配器
	MapArchiverManager m_mapArchiverManager;
};



