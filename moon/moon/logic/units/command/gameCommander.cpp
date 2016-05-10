#include "StdAfx.h"

struct GameCommandDef
{
	const char* sCmd;//游戏命令
	short nPrivilege;//权限等级
	short nMinParams;//最少参数数量
	GameCommandFunc func;//命令实现函数
};

static GameCommandDef CmdDef[] = {
	{ "mob", 9, 1, &GameCommander::CmdMakeMonster },
	{ "additem", 10, 1, &GameCommander::CmdAddItem },
	{ "jrw", 9, 1, &GameCommander::CmdAddQuest },
	{ "qcrw", 9, 0, &GameCommander::CmdClearQuest },
	{ "god", 9, 0, &GameCommander::CmdGodMode },
	{ "revi", 9, 0, &GameCommander::CmdReviviscent },
	{"dup",9,1,&GameCommander::CmdCreateDuplicate},
	{"map",5,1,&GameCommander::CmdMapMove},
	{"goto",5,1,&GameCommander::CmdGotoPlayer},
	{"recall",9,1,&GameCommander::CmdRecallPlayer},
};

GameCommander::GameCommander():super()
{

}

GameCommander::~GameCommander()
{

}

void GameCommander::init()
{
	GameCommand Cmd;
	for (int i=0; i<(int)ARRAY_LEN(CmdDef); ++i)
	{
		const GameCommandDef &def = CmdDef[i];
		Cmd.nPrivilege = def.nPrivilege;
		Cmd.nMinParams = def.nMinParams;
		Cmd.func = def.func;
		m_CmdMap.insert(StringHashMap<GameCommand>::HashMapPair(moon::String(def.sCmd), Cmd));
	}
}

void GameCommander::uninit()
{

}

void GameCommander::dispatchCmd(CPlayer *player, const char* sCmd, char*const* sParams, const int nParamCount)
{
	StringHashMap<GameCommand>::iterator it = m_CmdMap.find(moon::String(sCmd));
	if (it == m_CmdMap.end())
	{
		return;
	}
	//检查玩家权限
	const GameCommand &cmd = it->second;
	if (player->m_btGMLevel < cmd.nPrivilege)
	{

		return;
	}
	//检查参数数量
	if (nParamCount < cmd.nMinParams)
	{
		return;
	}
	//执行命令
	cmd.func(player, sCmd, sParams, nParamCount);
}

void GameCommander::CmdMakeMonster(CPlayer *player, const char* sCmd, char*const* sParams, const int nParamCount)
{
	const monsterStruct *pStdMon = NULL;
	int monId = strtol(sParams[0], NULL, 10);
	if (monId > 0)
		pStdMon = g_ConfigManager->monsterDataAccessor.getMonsterById(monId);
	else pStdMon = g_ConfigManager->monsterDataAccessor.getMonsterByName(sParams[0]);

	int nCount = nParamCount >= 2 ? strtol(sParams[1], NULL, 10) : 1;
	if (nCount < 1) nCount = 1;

	int x = player->m_nX, y = player->m_nY;
	//向角色面向的方向刷怪
	if (player->m_btDirection == 0)
		x -= 100;
	else x += 100;
	if (x < 0) x = 0;
	else if (x > player->m_pScene->m_nMapWidth) x = player->m_pScene->m_nMapWidth - 1;

	for (int i=nCount-1; i>-1; --i)
	{
		g_LogicEngine->monsterEngine().makeMonster(pStdMon->monId, player->m_pScene, x, y);
	}
}

void GameCommander::CmdAddItem(CPlayer *player, const char* sCmd, char*const* sParams, const int nParamCount)
{
	int itemId = strtol(sParams[0], NULL, 10);
	if (itemId <= 0)
	{
		const CFItem *config = g_ConfigManager->itemDataAccessor.getItemByName(sParams[0]);
		if (config == NULL)return;
		itemId = config->m_nItemId;
	}
	int itemCount = 1;
	if (nParamCount > 1)
	{
		itemCount = strtol(sParams[1], NULL, 10);
	}
	player->m_Bag.addItem(itemId, itemCount, 0, 0, 0, false, 0, NULL);
}

void GameCommander::CmdAddQuest( CPlayer *player, const char* sCmd, char*const* sParams, const int nParamCount )
{
	int questID = strtol(sParams[0], NULL, 10);
	if (questID <= 0)
	{
		const QuestConfig *pQuest = g_ConfigManager->missionDataProvider.getQuest(questID);
		if (NULL == pQuest)	return;
		questID = pQuest->nQid;
	}
	player->m_Quest.addQuest(questID);
}

//任务状态初始化
void GameCommander::CmdClearQuest( CPlayer *player, const char* sCmd, char*const* sParams, const int nParamCount )
{
	player->m_Quest.clearAllQuest();
}

void GameCommander::CmdGodMode(CPlayer *player, const char* sCmd, char*const* sParams, const int nParamCount)
{
	player->m_boGodMode = !player->m_boGodMode;
}

void GameCommander::CmdReviviscent(CPlayer *player, const char* sCmd, char*const* sParams, const int nParamCount)
{
	CPlayer *targetPlayer = player;
	if (nParamCount > 0)
		targetPlayer = g_LogicEngine->getPlayerList().getPlayerByName(sParams[0]);

	if (targetPlayer)
	{
		targetPlayer->m_Battle.reviviscent();
	}
}

void GameCommander::CmdMapMove(CPlayer *player, const char* sCmd, char*const* sParams, const int nParamCount)
{
	int sceneId = strtol(sParams[0], NULL, 10);
	Scene *pScene = NULL;
	if (sceneId > 0)
	{
		pScene = g_staticSceneManager->getSceneByID(sceneId);
	}
	else
	{
		sceneId = g_ConfigManager->sceneDataAccessor.getSceneIdByMapName(sParams[0]);
		if (sceneId >= 0)
			pScene = g_staticSceneManager->getSceneByID(sceneId);
	}

	if (pScene)
	{
		player->m_Battle.stopMove();
		player->setScene(pScene, 100, 100);
	}
}

void GameCommander::CmdGotoPlayer(CPlayer *player, const char* sCmd, char*const* sParams, const int nParamCount)
{
	CPlayer *target = g_LogicEngine->getPlayerList().getPlayerByName(sParams[0]);
	if (target)
	{
		player->m_Battle.stopMove();
		player->setScene(target->m_pScene, target->m_nX, target->m_nY);
	}
}

void GameCommander::CmdRecallPlayer(CPlayer *player, const char* sCmd, char*const* sParams, const int nParamCount)
{
	CPlayer *target = g_LogicEngine->getPlayerList().getPlayerByName(sParams[0]);
	if (target)
	{
		target->m_Battle.stopMove();
		target->setScene(player->m_pScene, player->m_nX, player->m_nY);
	}
}

void GameCommander::CmdCreateDuplicate(CPlayer *player, const char* sCmd, char*const* sParams, const int nParamCount)
{
	const int dupId = strtol(sParams[0], NULL, 10);
	SceneManager *sceneMgr = g_DuplicateManager->createDuplicate(dupId);
	if (sceneMgr)
	{
		player->setScene(*sceneMgr->m_SceneList.begin(), sceneMgr->m_firstSceneX, sceneMgr->m_firstSceneY);
	}
}


 
