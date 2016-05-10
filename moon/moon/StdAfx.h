#ifndef __ATDAFX_H__
#define __ATDAFX_H__
#if defined(WINDOWS)
#pragma warning (disable:4099)//去掉vs pdb 找不到调试连接对象的调试信息的警告
#endif
//公共头文件
#include "../../moonLib/LibStdAfx.h"
#include "serverInit.h"
#include "lib/graph/geometry.h"

//网络
#if defined(WINDOWS)
#include "net/netGate/win/wsa/wsa.h"
#endif
#include "net/netGate/dataProcess/RunDataSendThread.h"
#include "net/netGate/dataProcess/GateSendPacket.h"
#include "net/netGate/dataProcess/RunGateProto.h"
#include "net/netGate/dataProcess/ExecSockDataMgr.h"
#include "net/netGate/dataProcess/ExecSockMgr.h"
#include "net/netGate/DataPacketPool.hpp"
#include "net/netGate/win/wsa/wsa.h"
#include "net/netGate/base/baseReactor.h"
#include "net/netGate/select/selectReactor.h"
#include "net/netGate/select/SelectSockProcess.h"
#ifdef LINUX
#include "net/netGate/linux/epoll/EpollSockProcess.h"
#include "net/netGate/linux/epoll/epollReactor.h"
#else
#include "net/netGate/win/iocp/iocpReactor.h"
#endif
#include "net/netGate/GateSynergy.h"
#include "net/netGate/LogicGate.h"
#include "net/netGate/GateManager.h"

//配置
#include "config/logicConfig.hpp"
#include "logic/map/SceneFile.h"
#include "logic/map/CMapGrid.h"
#include "logic/map/GridItem.h"
#include "config/sceneConfig.h"
#include "logic/map/mapManager.h"
#include "logic/units/doerUnit/doerAbilData.h"
#include "config/skillconfig.h"
#include "config/questConfig.h"
#include "config/monsterConfig.h"
#include "config/itemConfig.h"
#include "config/weaponConfig.h"
#include "config/playerDataConfig.h"
#include "accessor/itemsAccessor.h"
#include "accessor/sceneAccessor.h"
#include "accessor/monsterAccessor.h"
#include "accessor/weaponAccessor.h"
#include "accessor/skillAccessor.h"
#include "accessor/playerDataAccessor.h"
#include "config/questManager.h"
#include "config/configManager.h"

//脚本
#include "logic/scriptSystem/luaInterface/ServerLuaInterface.h"
#include "logic/scriptSystem/scriptValue.h"
#include "logic/scriptSystem/scriptSystem.h"

//逻辑
#include "logic/base/LogicTypes.h"
#include "logic/event/logicEvent.h"
#include "logic/event/logicEventDispatcher.h"
#include "logic/doer/doerMsg.h"
#include "logic/units/team/Team.h"
#include "logic/units/team/TeamManager.h"
#include "logic/memory/GlobalObjAlloc.h"

//线程
#include "dbClient/account/AccountManager.h"
#include "dbClient/dbm/DBManager.h"
#include "dbClient/gameLog/gameLogMr.h"

//逻辑模块
#include "logic/units/command/gameCommander.h"
#include "logic/units/skill/skillUtil.h"
#include "logic/units/doerUnit/doerUnit.h"
#include "logic/units/doerUnit/doerAbility.h"
#include "logic/units/doerUnit/doerBattle.h"
#include "logic/units/doerUnit/doerBag.h"
#include "logic/units/doerUnit/doerChat.h"
#include "logic/units/doerUnit/doerEquip.h"
#include "logic/units/doerUnit/doerNpcTalk.h"
#include "logic/units/doerUnit/doerQuest.h"
#include "logic/units/doerUnit/doerTeam.h"
#include "logic/units/doerUnit/doerWeapon.h"
#include "logic/units/team/Team.h"
#include "logic/units/team/TeamManager.h"
#include "logic/doer/Entity.h"
#include "logic/doer/doer.h"
#include "logic/doer/Npc.h"
#include "logic/doer/player.h"
#include "logic/doer/playerList.h"
#include "logic/engine/monsterEngine/MonsterEngine.h"
#include "logic/engine/logicEngine/LogicEngine.h"
#include "logic/server/logicServer.h"


#endif
