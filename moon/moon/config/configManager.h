/*
 * ConfigManager.h
 *
 *  Created on: 2013-2-6
 *      Author: root
 */

#ifndef __CONFIG_MANAGER_H__
#define __CONFIG_MANAGER_H__


class CConfigManager
{
public:
	QuestAccessor			missionDataProvider;					//任务
	MonsterAccessor			monsterDataAccessor;				//怪物
	SceneAccessor			sceneDataAccessor;					//场景
	SkillProviderAccessor	skillDataAccessor;					//技能
	ItemAccessor			itemDataAccessor;					//道具
	PlayerDataAccessor		playerDataProvider;					//等级
	WeaponAccessor			weaponDataProvider;					//武器
	//CLANGPackMgr			langPackMgr;						//语言包
	//ScriptSystemLoad		scriptSystemLoad;					//脚本加载
	DuplicateManager		duplicateManager;					//副本管理器

public:
	CConfigManager();
	virtual ~CConfigManager();

	//static bool LoadCSVDocument(CSVDocument &doc, const char* path);

	bool initConfig();
	bool initSystem();
	void destroyConfig();
	void destroySystem();
};
#endif /* CONFIGMANAGER_H_ */
