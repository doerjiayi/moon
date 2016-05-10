/*
 * ConfigManager.cpp
 *
 *  Created on: 2013-2-6
 *      Author: root
 */


#include "StdAfx.h"

CConfigManager::CConfigManager()
{

}

CConfigManager::~CConfigManager()
{
	
}

//bool CConfigManager::LoadCSVDocument(CSVDocument &doc, const char* path)
//{
//	lib::stream::CFileStream fs(path, lib::stream::CFileStream::faRead);
//	long long sz = fs.getSize();
//	if (sz <= 0)
//	{
//		OutputError(-1, "can not load csv document %s", path);
//		return false;
//	}
//	MultiByteString mbs(sz);
//	mbs.setLength(fs.read(mbs.own_ptr(), sz));
//	UTF8String utf;
//	MultiByteString2UTF8String(utf, mbs, "GB2312");
//	StreamWriter stream(utf.ptr(), utf.length());
//	stream.setLength(utf.length());
//	stream.setPosition(0);
//	doc.load(stream);
//	return true;
//}

bool CConfigManager::initConfig()
{
	////人物等级配置
	//if (!playerLevelDataProvider.loadConfig())
	//{
	//	OutputError(rmError, "player level config load error");
	//	return false;
	//}
	////物品
 // 	if (!itemAccessor.loadConfig())
	//{
	//	OutputError(rmError, "stdItem config load error");
	//	return false;
	//}
	////技能
	//if (!skillDataProvider.loadConfig())
	//{
	//	OutputError(rmError, "skill config load error");
	//	return false;
	//}
	////怪物
	//if (!monsterDataProvider.loadConfig())
	//{
	//	OutputError(rmError, "monster config load error");
	//	return false;
	//}
	////场景
 // 	if (!sceneDataProvider.loadConfig())
	//{
	//	OutputError(rmError, "scene config load error");
	//	return false;
	//}
	////任务
	//if (!questDataProvider.loadQuestConfig())
	//{
	//	OutputError(rmError, "quest config load error");
	//	return false;
	//}
	////武器
	//if (!weaponDataProvider.loadConfig())
	//{
	//	OutputError(rmError, "weapon config load error");
	//	return false;
	//}
	return true;
}

bool CConfigManager::initSystem()
{
	//if(!scriptSystemLoad.init())//ScriptSystemLoad需要在DuplicateManager之前初始化
	//{
	//	OutputMsgError("ScriptSystemLoad init error\n");
	//	return false;
	//}
	//if (!langPackMgr.loadLANGPack("./lang"))
	//{
	//	OutputMsgError( "language pack load error\n");
	//	return false;
	//}
	//langPackMgr.makeLangScript();

	//if (!duplicateManager.init())
	//{
	//	OutputMsgError("DuplicateManager init error\n");
	//	return false;
	//}
	//g_DuplicateManager = &duplicateManager;

	//ScriptSystemLoad::testScriptSystemLoad();
	return true;
}

void CConfigManager::destroyConfig()
{
	destroySystem();
}

void CConfigManager::destroySystem()
{
	//g_DuplicateManager->destroy();
	//g_DuplicateManager = NULL;
}




