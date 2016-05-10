#include "StdAfx.h"

Scene::Scene():m_nSceneId(0),m_pMapGrid(NULL),m_pSceneManager(NULL),m_pSceneStruct(NULL),
m_pSceneMap(NULL)
{
	m_nMapWidth = 0;
	m_nMapHeight = 0;
	m_NpcList.resize(ADD_SCENE_NPC_NODE,NULL);
}


Scene::Scene(uint32 sceneId):m_nSceneId(sceneId),m_pMapGrid(NULL),m_pSceneManager(NULL),
		m_pSceneStruct(NULL),m_pSceneMap(NULL)
{
	initData(sceneId);
	loadDataToMember();//初始化配置场景数据到成员结构
}

Scene::~Scene()
{
	destory();
}

bool Scene::reset()
{
	destory();
	memset(this,0,sizeof(Scene));
	return true;
}

void Scene::destory()
{
	int i;
	CNpc** npcNodeL = m_NpcList.data();

	for (i=(int)m_NpcList.size()-1;i>-1 ;i--)
	{
		SafeDelete(npcNodeL[i]);
	}
	m_NpcList.clear();
	SafeDelete(m_pMapGrid);
}

bool Scene::initWithSceneId(int sceneId)
{
	m_nSceneId = sceneId;
	initData(sceneId);//初始化数据(地图数据)
	loadDataToMember();//初始化数据到成员结构
	return true;
}

bool Scene::initData(int sceneId)//初始化地图数据
{
#if 0
	const char* mapFileName = g_ConfigManager->sceneDataProvider.getMapNameBySceneID(sceneId);
	initMapData(mapFileName);//初始化地图数据（需要先初始化地图才能初始化可视网格）
	initMapGrid();//初始化地图可视网格
#endif
	return true;
}

bool Scene::initMapData(const char* mapFileName)
{
	if(!g_MapArchiverManager)
	{
		logError("地图管理器是空的");
		return false;
	}
	MapArchiver* mapArchiver = g_MapArchiverManager->getMapArchiver(mapFileName);
	if(!mapArchiver)
	{
		logError("初始化地图失败");
		return false;
	}
	m_pSceneMap = mapArchiver;
	return true;
}

bool Scene::loadDataToMember()
{
#if 0
	//场景表结构
	m_pSceneStruct = g_ConfigManager->sceneDataProvider.getSceneByID(m_nSceneId);
	//npc列表
	const std::vector<PSceneNpc>* npcList = g_ConfigManager->sceneDataProvider.getSceneNpcListBySceneID(m_nSceneId);
	SceneNpc*const* pSceneNpc = npcList->data();
	int i;
	for ( i = (int)npcList->size() - 1;i > -1;i--)
	{
		if(!pSceneNpc[i])
		{
			OutputMsg( rmError,"scene initConfigData ,get pScenePeople error\n");
			continue;
		}

		bool res = setNpcNode(pSceneNpc[i]);
		if (!res)
		{
			OutputMsg( rmError,"setNpcNode error,npcName:%s\n",pSceneNpc[i]->script);
		}
	}
	SafeDelete(npcList);
#endif
	return true;
}

bool Scene::initMapGrid()
{
	if(!m_pSceneMap)
	{
		logError("地图文件数据是空的");
		return false;
	}
	m_pMapGrid = new CMapGrid();
	m_pMapGrid->init(m_pSceneMap->m_nWidth,m_pSceneMap->m_nHeight);
	m_nMapWidth = m_pSceneMap->m_nWidth;
	m_nMapHeight = m_pSceneMap->m_nHeight;
	return true;
}

bool Scene::setNpcNode( SceneNpc* sceneNpc)
{
	uint64 npcId = (uint64)sceneNpc->npcId;

	uint32 size = (uint32)m_NpcList.size();
	if (npcId >=size/2)
	{
		m_NpcList.resize(2 * size,NULL);
	}

	CNpc* npc = new CNpc();
	npc->initialize();
	npc->m_EntityId.llid = npcId;//保存npc id
	npc->m_wEntityBody = sceneNpc->body;
	_asncpytA(npc->m_sName, sceneNpc->name);//脚本
	npc->setScene(this,sceneNpc->x,sceneNpc->y);
	
	m_NpcList[npcId] = npc;
	return true;
}


SceneManager::SceneManager(uint64 guid/*= 0*/)
{
	m_playerNum = 0;
	m_lastPlayerLeaveTime = 0;
	m_Guid = guid;
	m_duplicateId = 0;
	m_firstSceneX = 0;
	m_firstSceneY = 0;
	memset(&m_duplicateName,0,sizeof(m_duplicateName));
}


SceneManager::~SceneManager()
{
	destroyScenes();
}


bool SceneManager::initScenes(const SceneIdList &sceneIdList )
{
	int i = 0;
	int size = (int)sceneIdList.size();
	const uint32* sceneIdListData = sceneIdList.data();
	for (i =size -1;i >-1;i++)
	{
		if (sceneIdListData[i]> 0)
			addScene(sceneIdListData[i]);
	}
	return true;
}


bool SceneManager::destroyScenes()
{
	SceneListIt it = m_SceneList.begin();
	SceneListIt itEnd = m_SceneList.end();
	for (;it != itEnd;it++)
	{
		SafeDelete(*it);
	}
	m_SceneList.clear();
	return true;
}

bool SceneManager::addScene(uint32 sceneId )
{
	Scene* scene = SceneMemoryPoolManager::instance()->PopSceneInitWithSceneID(sceneId);
	if(!scene)return false;
	m_SceneList.push_back(scene);
	scene->m_pSceneManager = this;
	return true;
}


bool SceneManager::popSceneBySceneID( uint32 sceneId )
{
	SceneListIt it = m_SceneList.begin();
	SceneListIt itEnd = m_SceneList.end();
	for (;it != itEnd;it++)
	{
		Scene* scene = *it; 
		if (scene &&scene->m_nSceneId == sceneId)
		{
			m_SceneList.erase(it);
			//离开回收场景
			SceneMemoryPoolManager::instance()->PushScene(scene);
			scene = NULL;
			return true;
		}
	}
	return false;
}

bool SceneManager::delPlayer( CEntity* player )
{
	PlayerListIt it = std::find(m_playerList.begin(),m_playerList.end(),player);
	if (m_playerList.end() == it)//不存在该玩家
		return false;
	m_playerList.erase(it);
	m_playerNum--;
	if (0 == m_playerNum)
	{
		m_lastPlayerLeaveTime = GetTickCount();//设置最后离开者时间
	}
	return true;
}

bool SceneManager::addPlayer( CEntity* player)
{
	std::list<CEntity*>::iterator it = std::find(m_playerList.begin(),m_playerList.end(),player);
	if (m_playerList.end() != it)//已存在该玩家
		return false;
	m_playerList.push_back(player);
	m_playerNum++;
	m_lastPlayerLeaveTime = 0;//最后离开者时间设置0（有玩家时为0）
	return true;
}

Scene* SceneManager::getSceneByID( uint32 id )
{
	SceneListConstIt it = m_SceneList.begin();
	SceneListConstIt itEnd = m_SceneList.end();
	for (;it !=itEnd;it++)
	{
		if (id == (*it)->m_nSceneId )
			return *it;
	}
	return NULL;
}

void SceneManager::init(const SceneIdList &sceneIdList,const DuplicateStruct* duplicateStruct)
{
	initScenes(sceneIdList);
	m_duplicateId = duplicateStruct->duplicateId;
	strcpy(m_duplicateName,duplicateStruct->duplicateName);
	assert (duplicateStruct->x >= 0 && duplicateStruct->y >= 0);
	m_firstSceneX  = duplicateStruct->x;
	m_firstSceneY  = duplicateStruct->y;
}



SceneMemoryPoolManager::SceneMemoryPoolManager()
{
	int i;
	for (i = ADD_SCENE_NUM * 5;i >-1;i--)
	{
		m_SceneMemoryPoolList.push_back(new Scene());
	}
}

SceneMemoryPoolManager::~SceneMemoryPoolManager()
{
	std::list<Scene*>::iterator it = m_SceneMemoryPoolList.begin();
	std::list<Scene*>::iterator it_end = m_SceneMemoryPoolList.end();
	for (;it != it_end;it++)
	{
		SafeDelete(*it);
	}
	m_SceneMemoryPoolList.clear();
}

Scene* SceneMemoryPoolManager::PopScene()
{
	if (m_SceneMemoryPoolList.size() <= ADD_SCENE_NUM)
	{
		int i;
		for (i = 0;i < ADD_SCENE_NUM;i++)
		{
			m_SceneMemoryPoolList.push_back(new Scene());
		}
		
	}
	Scene* _scene = m_SceneMemoryPoolList.front();
	m_SceneMemoryPoolList.erase(m_SceneMemoryPoolList.begin());
	return _scene;
}

bool SceneMemoryPoolManager::PushScene(Scene* scene)
{
	if (!scene)
		return false;
	scene->reset();
	m_SceneMemoryPoolList.push_back(scene);
	return true;
}

Scene* SceneMemoryPoolManager::PopSceneInitWithSceneID(int sceneId)
{
	Scene* scene = PopScene();
	if (!scene)
		return NULL;
	scene->initWithSceneId(sceneId);
	return scene;
}

uint64 DuplicateManager::addDuplicateWithSceneManager( SceneManager * sceneManager )
{
	m_dynamicGuid++;
	sceneManager->m_Guid = m_dynamicGuid;
	uint64 size = (uint64)m_sceneManagerList.size();
	if (m_dynamicGuid+1 >= size/2)
	{
		size = max(m_dynamicGuid+1,size * 2);
		m_sceneManagerList.resize(size,NULL);
	}
	m_sceneManagerList[m_dynamicGuid] = sceneManager;
	return m_dynamicGuid;
}

SceneManager* DuplicateManager::createDuplicate(int duplicateId)
{
#if 0
	const DuplicateStruct* duplicateStruct = g_ConfigManager->sceneDataProvider.getDuplicateStruct(duplicateId);
	int size = (int)sizeof(duplicateStruct->sceneIdList)/sizeof(duplicateStruct->sceneIdList[0]);
	std::vector<int> sceneIdList(size,0); 
	int* sceneIdListData = sceneIdList.data();

	BOOL addFlag = FALSE;
	if (duplicateStruct)
	{
		for (int i = size - 1;i>-1;i--)
		{
			if (duplicateStruct->sceneIdList[i] >0)
			{
				sceneIdListData[i] = duplicateStruct->sceneIdList[i];
				addFlag = TRUE;
			}
		}
	}
	if (addFlag)
	{
		SceneManager* sceneManager = new SceneManager();
		sceneManager->init(sceneIdList,duplicateStruct);
		addDuplicateWithSceneManager(sceneManager);
		return sceneManager;
	}
#endif

	return NULL;
}


DuplicateManager::~DuplicateManager()
{
	
}

DuplicateManager::DuplicateManager():m_dynamicGuid(0),m_tickCountTime(0)
{
	m_sceneManagerList.resize(SCENE_MANAGER_NUM,NULL);
}

bool DuplicateManager::init()
{
#if 0
	if (!g_staticSceneManager)
	{
		//初始化静态副本
		g_staticSceneManager = new SceneManager(0);
		g_staticSceneManager->initScenes(g_ConfigManager->sceneDataProvider.m_staicSceneList);
	}
#endif
	return true;
}

SceneManager* DuplicateManager::getDuplicateByGuid(uint64 guid)
{
	if (guid > m_dynamicGuid)return NULL;
	return m_sceneManagerList[guid];
}

void DuplicateManager::OnRoutine()
{
	int i;
	SceneManager** sceneManagerList = m_sceneManagerList.data();
	m_tickCountTime = GetTickCount();
	for (i = (int)m_sceneManagerList.size() -1;i >= 0;i--)
	{
		SceneManager* sceneManager = sceneManagerList[i];
		if (sceneManager)
		{
			unsigned long lastPlayerLeaveTime = sceneManager->m_lastPlayerLeaveTime;
			unsigned long timeInterval = m_tickCountTime - lastPlayerLeaveTime;
			if (lastPlayerLeaveTime > 0 && timeInterval > LEAVE_SCENE_DESTORY_INTERVAL)
			{
				std::vector<SceneManager*>::iterator it = m_sceneManagerList.begin() + i;
				SafeDelete(sceneManager);
			}
		}
	}
	
}

const Scene* DuplicateManager::getSceneByDuplicateGuidAndSceneId( int guid,int sceneId )
{
	SceneManager* sceneManager = getDuplicateByGuid(guid);
	if (!sceneManager)
		return NULL;
	const Scene* scene = sceneManager->getSceneByID(sceneId);
	return scene;
}

void DuplicateManager::destroy()
{
	int i ;
	for (i = (int)m_sceneManagerList.size()-1;i >-1;i--)
	{
		SafeDelete(m_sceneManagerList[i]);
	}
	m_sceneManagerList.clear();
	SafeDelete(g_staticSceneManager);
}

void DuplicateManager::testScene()
{
	////读取配置信息（包含场景配置）
	//g_ConfigManager->initConfig();
	//静态副本
	//g_DuplicateManager->init();
	//动态副本
	//std::vector<int>List2;
	//List2.push_back(1);
	//List2.push_back(2);
	//SceneManager* _dsm = new SceneManager();
	//_dsm->initScenes(List2);
	//const Scene* scene = _dsm->m_SceneList[1];
	//long guid = g_DuplicateManager->addDuplicateWithSceneManager(_dsm);
	//Scene* scene1 = g_DuplicateManager->getSceneByDuplicateGuidAndSceneId(guid,scene->m_nSceneId);
	//std::cout << g_staticSceneManager->m_Guid << std::endl;
// 	CPlayer* player1 = new CPlayer();
// 	CPlayer* player2 = new CPlayer();
// 	int duplicate = 1;
// 	SceneManager* sceneManager = g_DuplicateManager->createDuplicateAndAddPlayer(duplicate,player1);
// 	printf("m_playerNum (%d)\n",sceneManager->m_playerNum);
// 	sceneManager->addPlayerToFirstScene(player2);
// 	printf("m_playerNum (%d)\n",sceneManager->m_playerNum);
}


