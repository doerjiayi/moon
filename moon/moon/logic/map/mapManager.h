#pragma once
#include <vector>
#include <list>
#include <string>
#include <map>


class CNpc;
class SceneManager;

#define ADD_SCENE_NUM 10
#define SCENE_MANAGER_NUM 50

//十分钟没人在副本就删除场景管理器sceneManager
#define LEAVE_SCENE_DESTORY_INTERVAL 600000

#define ADD_SCENE_NPC_NODE	50
#define ADD_SCENE_MONSTER_NODE	50

class Scene;

typedef std::list<Scene*> SceneList;
typedef SceneList::iterator SceneListIt;
typedef SceneList::const_iterator SceneListConstIt;

typedef std::vector<uint32> SceneIdList;
typedef std::list<CEntity*> PlayerList;
typedef PlayerList::iterator PlayerListIt;

class Scene
{
public:
	Scene();//使用这个构造函数需要后面调用initWithSceneId来初始化
	Scene(uint32 sceneId);
	~Scene();
	void destory();
	bool reset();
	bool initWithSceneId(int sceneId);//由id初始化场景
protected:
	bool initData(int sceneId);//初始化数据
	bool initMapData(const char* mapFileName);//加载地图数据
	bool initMapGrid();//初始化地图信息

	bool loadDataToMember();//加载配置数据到成员（需要先初始化数据initData）
public:
	//列表 npc存取
	inline CNpc* getNpcNode(int npcId){if (npcId <0 || npcId >=(int)m_NpcList.size())return NULL; return m_NpcList[npcId];}
	bool setNpcNode(SceneNpc* sceneNpc);

	inline SceneStruct* getpSceneStruct(){return m_pSceneStruct;}
	inline MapArchiver* getSceneMap(){return m_pSceneMap;}
	bool isStaticScene() const;
public:
	uint32				m_nSceneId;//场景ID
	int				m_nMapWidth;//地图像素宽度
	int				m_nMapHeight;//地图像素高度
	CMapGrid*		m_pMapGrid;//可视网格
	SceneManager*	m_pSceneManager;//所属场景管理器
	SceneStruct*	m_pSceneStruct;//场景配置表数据
	MapArchiver*	m_pSceneMap;//地图文件数据

	std::vector<CNpc*> m_NpcList;//npcId 索引CNpc*
};
	
class DuplicateManager//副本管理器
{
public:
	DuplicateManager();
	~DuplicateManager();
	void destroy();
	bool init();//初始化
	SceneManager* createDuplicate(int duplicateId);//创建副本
	SceneManager* getDuplicateByGuid(uint64 guid);
	const Scene* getSceneByDuplicateGuidAndSceneId(int guid,int sceneId);
	void OnRoutine();//副本例程
	static void testScene();//测试使用
	uint64 m_dynamicGuid;//动态sceneManager的guid记录（从1一直增长）
protected:
	uint64 addDuplicateWithSceneManager(SceneManager* sceneManager);

	std::vector<SceneManager*> m_sceneManagerList;
	unsigned long m_tickCountTime;
};

class SceneMemoryPoolManager//管理场景内存
{
	SceneMemoryPoolManager();
public:
	inline static SceneMemoryPoolManager* instance(){static SceneMemoryPoolManager _SceneMemPool;return &_SceneMemPool;}
	inline SceneList* getMemPool(){return &m_SceneMemoryPoolList;}
	Scene* PopSceneInitWithSceneID(int sceneId);//获取场景对象并初始化
	bool PushScene(Scene* scene);//回收场景
	~SceneMemoryPoolManager();
protected:
	Scene* PopScene();
private:
	SceneList m_SceneMemoryPoolList;//从列表前面取，从后面回收
};

class SceneManager//管理场景
{
public:
	SceneManager(uint64 guid = 0);
	~SceneManager();

	void init(const SceneIdList &sceneIdList,const DuplicateStruct* duplicateStruct);
	bool initScenes(const SceneIdList &sceneIdList);//由场景id列表初始化副本
	bool destroyScenes();//副本销毁
	bool addScene(uint32 sceneId);//动态添加场景
	Scene* getSceneByID(uint32 id);//由id获取场景
	bool popSceneBySceneID(uint32 sceneId);//场景回收
	bool addPlayer(CEntity* player);//副本加入玩家
	bool delPlayer(CEntity* player);//副本玩家退出
public:
	int m_playerNum;//副本玩家数量
	unsigned long m_lastPlayerLeaveTime;//最后玩家离开时间，有玩家时为0
	PlayerList m_playerList;//玩家列表
	char m_duplicateName[48];//副本名字
	int m_duplicateId;//副本id
	uint64 m_Guid;//副本guid
	int m_firstSceneX;//初始X坐标（第一个场景使用）
	int m_firstSceneY;//初始Y坐标（第一个场景使用）
	SceneList  m_SceneList;//场景列表(场景数不超过8个)
};



inline bool Scene::isStaticScene() const { return m_pSceneManager->m_Guid == 0; }
