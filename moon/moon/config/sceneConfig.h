#pragma once
#include <string>

struct SceneBase
{
	int m_nSceneId;
	int m_nMinX;
	int m_nMaxX;
	int m_nMinY;
	int m_nMaxY;
};

//
//场景NPC配置
//
typedef struct SceneNpc
{
	int npcId;//npcId
	int sceneId;//场景id
	const char *name;//名称
	unsigned short body;//外形
	int x;//坐标X
	int y;//坐标Y
	const char *script;//脚本名
	const char *defaultTalk[3];//最多3个默认对话
}SceneNpc,*PSceneNpc;

//
//场景传送门配置
//
struct SceneGate
{
	uint32 gateId;//传送门ID
	uint32 sceneId;//所在场景ID
	int x;//所在场景X
	int y;//所在场景Y
	uint32 targetId;//目的地场景ID
	uint32 targetX;//目的地场景X
	uint32 targetY;//目的地场景Y
};

//
//场景配置
//
typedef struct SceneStruct
{
	int id;//id(场景id)
	const char *name;//场景名称
	const char *mapFileName;//地图文件名称
	BYTE type;//场景类型
	BYTE weather;//天气
	const char *music;
}SceneStruct,*PSceneStruct;

//
//副本配置
//
typedef struct DuplicateStruct
{
	int duplicateId;//副本id
	const char*	duplicateName;//	副本名称
	int sceneIdList[8];	//	场景id(最多8个)
	int x;	//	X坐标
	int y;	//	Y坐标
}DuplicateStruct,*PDuplicate;


