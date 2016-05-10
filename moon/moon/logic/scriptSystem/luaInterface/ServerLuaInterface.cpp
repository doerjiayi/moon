/*
** Lua binding: serverLuaInterface
** Generated automatically by tolua++-1.0.92 on Sun Feb 16 02:30:55 2014.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "StdAfx.h"

#include "ServerLuaInterface.h"
/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_CDoerUnit (lua_State* tolua_S)
{
 CDoerUnit* self = (CDoerUnit*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CPlayerWeapon (lua_State* tolua_S)
{
 CPlayerWeapon* self = (CPlayerWeapon*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CEntity (lua_State* tolua_S)
{
 CEntity* self = (CEntity*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ItemAccessor (lua_State* tolua_S)
{
 ItemAccessor* self = (ItemAccessor*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CPlayerEquip (lua_State* tolua_S)
{
 CPlayerEquip* self = (CPlayerEquip*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_DuplicateManager (lua_State* tolua_S)
{
 DuplicateManager* self = (DuplicateManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_DoerAbilData (lua_State* tolua_S)
{
 DoerAbilData* self = (DoerAbilData*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Scene (lua_State* tolua_S)
{
 Scene* self = (Scene*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CPlayerBag (lua_State* tolua_S)
{
 CPlayerBag* self = (CPlayerBag*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CDoerBattle (lua_State* tolua_S)
{
 CDoerBattle* self = (CDoerBattle*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CPlayerNpcTalk (lua_State* tolua_S)
{
 CPlayerNpcTalk* self = (CPlayerNpcTalk*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_PlayerDataAccessor (lua_State* tolua_S)
{
 PlayerDataAccessor* self = (PlayerDataAccessor*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CPlayer (lua_State* tolua_S)
{
 CPlayer* self = (CPlayer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CPlayerQuest (lua_State* tolua_S)
{
 CPlayerQuest* self = (CPlayerQuest*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CPlayerTeam (lua_State* tolua_S)
{
 CPlayerTeam* self = (CPlayerTeam*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

//static int tolua_collect_BeadSeries (lua_State* tolua_S)
//{
// BeadSeries* self = (BeadSeries*) tolua_tousertype(tolua_S,1,0);
//	Mtolua_delete(self);
//	return 0;
//}

static int tolua_collect_WeaponAccessor (lua_State* tolua_S)
{
 WeaponAccessor* self = (WeaponAccessor*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CDoer (lua_State* tolua_S)
{
 CDoer* self = (CDoer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_SceneManager (lua_State* tolua_S)
{
 SceneManager* self = (SceneManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CDoerAbility (lua_State* tolua_S)
{
 CDoerAbility* self = (CDoerAbility*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CBList<CEntity::ViewStruct>");
 tolua_usertype(tolua_S,"CGateSendPacket");
 tolua_usertype(tolua_S,"CMapGrid");
 tolua_usertype(tolua_S,"Bead");
 tolua_usertype(tolua_S,"WeaponAccessor");
 tolua_usertype(tolua_S,"CPlayerEquip");
 tolua_usertype(tolua_S,"DuplicateManager");
 tolua_usertype(tolua_S,"uint32");
 tolua_usertype(tolua_S,"PlayerQuestData");
 tolua_usertype(tolua_S,"common::Bead");
 tolua_usertype(tolua_S,"CPlayer");
 tolua_usertype(tolua_S,"QuestConfig::ENUM_QUEST_TARGET");
 tolua_usertype(tolua_S,"AttributeValue");
 tolua_usertype(tolua_S,"DuplicateStruct");
 tolua_usertype(tolua_S,"INT_PTR");
 tolua_usertype(tolua_S,"common::DropItemData");
 tolua_usertype(tolua_S,"CEntity");
 tolua_usertype(tolua_S,"DoerMsg");
 tolua_usertype(tolua_S,"SceneNpc");
 tolua_usertype(tolua_S,"common::ItemSeries");
 tolua_usertype(tolua_S,"PlayerDataAccessor");
 tolua_usertype(tolua_S,"CFBead");
 tolua_usertype(tolua_S,"EntityDesc");
 tolua_usertype(tolua_S,"CGuild");
 tolua_usertype(tolua_S,"STDGUID");
 tolua_usertype(tolua_S,"CPlayerNpcTalk");
 tolua_usertype(tolua_S,"common::EntityDesc");
 tolua_usertype(tolua_S,"SceneManager");
 tolua_usertype(tolua_S,"CDoerAbility");
 tolua_usertype(tolua_S,"CEntity::ViewStruct");
 tolua_usertype(tolua_S,"PlayerList");
 tolua_usertype(tolua_S,"EntityPosition");
 tolua_usertype(tolua_S,"common::UserItem");
 tolua_usertype(tolua_S,"lib::memory::Object");
 tolua_usertype(tolua_S,"CTeam");
 tolua_usertype(tolua_S,"GRect");
 tolua_usertype(tolua_S,"*");
 tolua_usertype(tolua_S,"ItemAttributeGroup");
 tolua_usertype(tolua_S,"common::SendClientDropItem");
 tolua_usertype(tolua_S,"std::vector<BeadSeries>");
 tolua_usertype(tolua_S,"Scene");
 tolua_usertype(tolua_S,"CLogicGate");
 tolua_usertype(tolua_S,"common::Weapon");
 tolua_usertype(tolua_S,"CFWeapon");
 tolua_usertype(tolua_S,"common::PlayerQuestData");
 tolua_usertype(tolua_S,"common::Attribute");
 tolua_usertype(tolua_S,"MapArchiver");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"BeadSeries");
 tolua_usertype(tolua_S,"CDoer");
 tolua_usertype(tolua_S,"CPlayerBag");
 tolua_usertype(tolua_S,"Weapon");
 tolua_usertype(tolua_S,"PlayerId");
 tolua_usertype(tolua_S,"CDoerUnit");
 tolua_usertype(tolua_S,"CDataPacketReader");
 tolua_usertype(tolua_S,"CNpc");
 tolua_usertype(tolua_S,"CFItem");
 tolua_usertype(tolua_S,"SceneStruct");
 tolua_usertype(tolua_S,"AttackPowerType");
 tolua_usertype(tolua_S,"ItemAccessor");
 tolua_usertype(tolua_S,"CDataPacket");
 tolua_usertype(tolua_S,"CDoerBattle");
 tolua_usertype(tolua_S,"CBaseObject");
 tolua_usertype(tolua_S,"UserItem");
 tolua_usertype(tolua_S,"TickTime");
 tolua_usertype(tolua_S,"uint64");
 tolua_usertype(tolua_S,"uint8");
 tolua_usertype(tolua_S,"CPlayerQuest");
 tolua_usertype(tolua_S,"EnterGameStruct");
 tolua_usertype(tolua_S,"CPlayerTeam");
 tolua_usertype(tolua_S,"common::PlayerDoneQuestData");
 tolua_usertype(tolua_S,"CFPlayerLevel");
 tolua_usertype(tolua_S,"LogicEvent");
 tolua_usertype(tolua_S,"SceneIdList");
 tolua_usertype(tolua_S,"CPlayerChat");
 tolua_usertype(tolua_S,"StdBeadQuality");
 tolua_usertype(tolua_S,"GuildId");
 tolua_usertype(tolua_S,"common::EntityPosition");
 tolua_usertype(tolua_S,"CPlayerWeapon");
 tolua_usertype(tolua_S,"DoerAbilData");
 tolua_usertype(tolua_S,"ItemSeries");
}

/* get function: type of class  common::Attribute */
#ifndef TOLUA_DISABLE_tolua_get_common__Attribute_unsigned_type
static int tolua_get_common__Attribute_unsigned_type(lua_State* tolua_S)
{
  common::Attribute* self = (common::Attribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->type);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: type of class  common::Attribute */
#ifndef TOLUA_DISABLE_tolua_set_common__Attribute_unsigned_type
static int tolua_set_common__Attribute_unsigned_type(lua_State* tolua_S)
{
  common::Attribute* self = (common::Attribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->type = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: reserve of class  common::Attribute */
#ifndef TOLUA_DISABLE_tolua_get_common__Attribute_unsigned_reserve
static int tolua_get_common__Attribute_unsigned_reserve(lua_State* tolua_S)
{
  common::Attribute* self = (common::Attribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'reserve'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->reserve);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: reserve of class  common::Attribute */
#ifndef TOLUA_DISABLE_tolua_set_common__Attribute_unsigned_reserve
static int tolua_set_common__Attribute_unsigned_reserve(lua_State* tolua_S)
{
  common::Attribute* self = (common::Attribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'reserve'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->reserve,(const char*)tolua_tostring(tolua_S,2,0),3-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  common::Attribute */
#ifndef TOLUA_DISABLE_tolua_get_common__Attribute_value
static int tolua_get_common__Attribute_value(lua_State* tolua_S)
{
  common::Attribute* self = (common::Attribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  common::Attribute */
#ifndef TOLUA_DISABLE_tolua_set_common__Attribute_value
static int tolua_set_common__Attribute_value(lua_State* tolua_S)
{
  common::Attribute* self = (common::Attribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->value = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nDuplicateId of class  common::EntityPosition */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityPosition_nDuplicateId
static int tolua_get_common__EntityPosition_nDuplicateId(lua_State* tolua_S)
{
  common::EntityPosition* self = (common::EntityPosition*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nDuplicateId'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->nDuplicateId,"uint64");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nDuplicateId of class  common::EntityPosition */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityPosition_nDuplicateId
static int tolua_set_common__EntityPosition_nDuplicateId(lua_State* tolua_S)
{
  common::EntityPosition* self = (common::EntityPosition*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nDuplicateId'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint64",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nDuplicateId = *((uint64*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nSceneId of class  common::EntityPosition */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityPosition_nSceneId
static int tolua_get_common__EntityPosition_nSceneId(lua_State* tolua_S)
{
  common::EntityPosition* self = (common::EntityPosition*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nSceneId'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->nSceneId,"uint32");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nSceneId of class  common::EntityPosition */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityPosition_nSceneId
static int tolua_set_common__EntityPosition_nSceneId(lua_State* tolua_S)
{
  common::EntityPosition* self = (common::EntityPosition*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nSceneId'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint32",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nSceneId = *((uint32*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nMapX of class  common::EntityPosition */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityPosition_nMapX
static int tolua_get_common__EntityPosition_nMapX(lua_State* tolua_S)
{
  common::EntityPosition* self = (common::EntityPosition*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nMapX'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->nMapX,"uint32");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nMapX of class  common::EntityPosition */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityPosition_nMapX
static int tolua_set_common__EntityPosition_nMapX(lua_State* tolua_S)
{
  common::EntityPosition* self = (common::EntityPosition*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nMapX'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint32",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nMapX = *((uint32*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nMapY of class  common::EntityPosition */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityPosition_nMapY
static int tolua_get_common__EntityPosition_nMapY(lua_State* tolua_S)
{
  common::EntityPosition* self = (common::EntityPosition*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nMapY'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->nMapY,"uint32");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nMapY of class  common::EntityPosition */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityPosition_nMapY
static int tolua_set_common__EntityPosition_nMapY(lua_State* tolua_S)
{
  common::EntityPosition* self = (common::EntityPosition*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nMapY'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint32",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nMapY = *((uint32*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: series of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_get_common__UserItem_series
static int tolua_get_common__UserItem_series(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'series'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->series,"ItemSeries");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: series of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_set_common__UserItem_series
static int tolua_set_common__UserItem_series(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'series'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ItemSeries",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->series = *((ItemSeries*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wItemId of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_get_common__UserItem_unsigned_wItemId
static int tolua_get_common__UserItem_unsigned_wItemId(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'wItemId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->wItemId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: wItemId of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_set_common__UserItem_unsigned_wItemId
static int tolua_set_common__UserItem_unsigned_wItemId(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'wItemId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->wItemId = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: btStrong of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_get_common__UserItem_unsigned_btStrong
static int tolua_get_common__UserItem_unsigned_btStrong(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'btStrong'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->btStrong);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: btStrong of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_set_common__UserItem_unsigned_btStrong
static int tolua_set_common__UserItem_unsigned_btStrong(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'btStrong'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->btStrong = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: btQuality of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_get_common__UserItem_unsigned_btQuality
static int tolua_get_common__UserItem_unsigned_btQuality(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'btQuality'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->btQuality);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: btQuality of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_set_common__UserItem_unsigned_btQuality
static int tolua_set_common__UserItem_unsigned_btQuality(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'btQuality'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->btQuality = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: InlayItems of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_get_serverLuaInterface_common_UserItem_InlayItems
static int tolua_get_serverLuaInterface_common_UserItem_InlayItems(lua_State* tolua_S)
{
 int tolua_index;
  common::UserItem* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (common::UserItem*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=MaxItemHole)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->InlayItems[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: InlayItems of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_set_serverLuaInterface_common_UserItem_InlayItems
static int tolua_set_serverLuaInterface_common_UserItem_InlayItems(lua_State* tolua_S)
{
 int tolua_index;
  common::UserItem* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (common::UserItem*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=MaxItemHole)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->InlayItems[tolua_index] = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nExpireTime of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_get_common__UserItem_nExpireTime
static int tolua_get_common__UserItem_nExpireTime(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nExpireTime'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->nExpireTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nExpireTime of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_set_common__UserItem_nExpireTime
static int tolua_set_common__UserItem_nExpireTime(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nExpireTime'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nExpireTime = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: btCount of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_get_common__UserItem_unsigned_btCount
static int tolua_get_common__UserItem_unsigned_btCount(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'btCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->btCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: btCount of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_set_common__UserItem_unsigned_btCount
static int tolua_set_common__UserItem_unsigned_btCount(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'btCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->btCount = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: btFlag of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_get_common__UserItem_unsigned_btFlag
static int tolua_get_common__UserItem_unsigned_btFlag(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'btFlag'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->btFlag);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: btFlag of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_set_common__UserItem_unsigned_btFlag
static int tolua_set_common__UserItem_unsigned_btFlag(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'btFlag'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->btFlag = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: btReserve of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_get_common__UserItem_unsigned_btReserve
static int tolua_get_common__UserItem_unsigned_btReserve(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'btReserve'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->btReserve);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: btReserve of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_set_common__UserItem_unsigned_btReserve
static int tolua_set_common__UserItem_unsigned_btReserve(lua_State* tolua_S)
{
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'btReserve'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->btReserve,(const char*)tolua_tostring(tolua_S,2,0),2-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIsHoleOpend of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_common_UserItem_getIsHoleOpend00
static int tolua_serverLuaInterface_common_UserItem_getIsHoleOpend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const common::UserItem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const common::UserItem* self = (const common::UserItem*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIsHoleOpend'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getIsHoleOpend(index);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIsHoleOpend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: openHole of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_common_UserItem_openHole00
static int tolua_serverLuaInterface_common_UserItem_openHole00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"common::UserItem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  bool boOpen = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'openHole'", NULL);
#endif
  {
   self->openHole(index,boOpen);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'openHole'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOpendHoleCount of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_common_UserItem_getOpendHoleCount00
static int tolua_serverLuaInterface_common_UserItem_getOpendHoleCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const common::UserItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const common::UserItem* self = (const common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOpendHoleCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getOpendHoleCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOpendHoleCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInlayedItem of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_common_UserItem_getInlayedItem00
static int tolua_serverLuaInterface_common_UserItem_getInlayedItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const common::UserItem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const common::UserItem* self = (const common::UserItem*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInlayedItem'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getInlayedItem(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInlayedItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setInlayedItem of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_common_UserItem_setInlayedItem00
static int tolua_serverLuaInterface_common_UserItem_setInlayedItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"common::UserItem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  int wItemId = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setInlayedItem'", NULL);
#endif
  {
   self->setInlayedItem(index,wItemId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInlayedItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: binded of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_common_UserItem_binded00
static int tolua_serverLuaInterface_common_UserItem_binded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const common::UserItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const common::UserItem* self = (const common::UserItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'binded'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->binded();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'binded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBind of class  common::UserItem */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_common_UserItem_setBind00
static int tolua_serverLuaInterface_common_UserItem_setBind00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"common::UserItem",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  common::UserItem* self = (common::UserItem*)  tolua_tousertype(tolua_S,1,0);
  bool boBind = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBind'", NULL);
#endif
  {
   self->setBind(boBind);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBind'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: race of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityDesc_unsigned_race
static int tolua_get_common__EntityDesc_unsigned_race(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'race'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->race);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: race of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityDesc_unsigned_race
static int tolua_set_common__EntityDesc_unsigned_race(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'race'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->race = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: genob of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityDesc_unsigned_genob
static int tolua_get_common__EntityDesc_unsigned_genob(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'genob'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->genob);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: genob of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityDesc_unsigned_genob
static int tolua_set_common__EntityDesc_unsigned_genob(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'genob'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->genob = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: level of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityDesc_unsigned_level
static int tolua_get_common__EntityDesc_unsigned_level(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'level'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->level);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: level of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityDesc_unsigned_level
static int tolua_set_common__EntityDesc_unsigned_level(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'level'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->level = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: body of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityDesc_unsigned_body
static int tolua_get_common__EntityDesc_unsigned_body(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'body'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->body);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: body of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityDesc_unsigned_body
static int tolua_set_common__EntityDesc_unsigned_body(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'body'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->body = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: weapon of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityDesc_unsigned_weapon
static int tolua_get_common__EntityDesc_unsigned_weapon(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'weapon'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->weapon);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: weapon of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityDesc_unsigned_weapon
static int tolua_set_common__EntityDesc_unsigned_weapon(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'weapon'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->weapon = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wpeffect of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityDesc_unsigned_wpeffect
static int tolua_get_common__EntityDesc_unsigned_wpeffect(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'wpeffect'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->wpeffect);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: wpeffect of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityDesc_unsigned_wpeffect
static int tolua_set_common__EntityDesc_unsigned_wpeffect(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'wpeffect'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->wpeffect = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mount of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityDesc_unsigned_mount
static int tolua_get_common__EntityDesc_unsigned_mount(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mount of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityDesc_unsigned_mount
static int tolua_set_common__EntityDesc_unsigned_mount(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mount = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: moveSpeed of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityDesc_unsigned_moveSpeed
static int tolua_get_common__EntityDesc_unsigned_moveSpeed(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'moveSpeed'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->moveSpeed);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: moveSpeed of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityDesc_unsigned_moveSpeed
static int tolua_set_common__EntityDesc_unsigned_moveSpeed(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'moveSpeed'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->moveSpeed = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: hitSpeedRate of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityDesc_hitSpeedRate
static int tolua_get_common__EntityDesc_hitSpeedRate(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hitSpeedRate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->hitSpeedRate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: hitSpeedRate of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityDesc_hitSpeedRate
static int tolua_set_common__EntityDesc_hitSpeedRate(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hitSpeedRate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->hitSpeedRate = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: flags of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityDesc_unsigned_flags
static int tolua_get_common__EntityDesc_unsigned_flags(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flags'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->flags);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: flags of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityDesc_unsigned_flags
static int tolua_set_common__EntityDesc_unsigned_flags(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flags'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->flags = ((unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: vipLevel of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityDesc_unsigned_vipLevel
static int tolua_get_common__EntityDesc_unsigned_vipLevel(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'vipLevel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->vipLevel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: vipLevel of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityDesc_unsigned_vipLevel
static int tolua_set_common__EntityDesc_unsigned_vipLevel(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'vipLevel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->vipLevel = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: reserve of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_get_common__EntityDesc_unsigned_reserve
static int tolua_get_common__EntityDesc_unsigned_reserve(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'reserve'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->reserve);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: reserve of class  common::EntityDesc */
#ifndef TOLUA_DISABLE_tolua_set_common__EntityDesc_unsigned_reserve
static int tolua_set_common__EntityDesc_unsigned_reserve(lua_State* tolua_S)
{
  common::EntityDesc* self = (common::EntityDesc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'reserve'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->reserve,(const char*)tolua_tostring(tolua_S,2,0),3-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: questID of class  common::PlayerQuestData */
#ifndef TOLUA_DISABLE_tolua_get_common__PlayerQuestData_unsigned_questID
static int tolua_get_common__PlayerQuestData_unsigned_questID(lua_State* tolua_S)
{
  common::PlayerQuestData* self = (common::PlayerQuestData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'questID'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->questID);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: questID of class  common::PlayerQuestData */
#ifndef TOLUA_DISABLE_tolua_set_common__PlayerQuestData_unsigned_questID
static int tolua_set_common__PlayerQuestData_unsigned_questID(lua_State* tolua_S)
{
  common::PlayerQuestData* self = (common::PlayerQuestData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'questID'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->questID = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: completeTimes of class  common::PlayerQuestData */
#ifndef TOLUA_DISABLE_tolua_get_common__PlayerQuestData_unsigned_completeTimes
static int tolua_get_common__PlayerQuestData_unsigned_completeTimes(lua_State* tolua_S)
{
  common::PlayerQuestData* self = (common::PlayerQuestData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'completeTimes'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->completeTimes);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: completeTimes of class  common::PlayerQuestData */
#ifndef TOLUA_DISABLE_tolua_set_common__PlayerQuestData_unsigned_completeTimes
static int tolua_set_common__PlayerQuestData_unsigned_completeTimes(lua_State* tolua_S)
{
  common::PlayerQuestData* self = (common::PlayerQuestData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'completeTimes'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->completeTimes = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: targetCount of class  common::PlayerQuestData */
#ifndef TOLUA_DISABLE_tolua_get_common__PlayerQuestData_unsigned_targetCount
static int tolua_get_common__PlayerQuestData_unsigned_targetCount(lua_State* tolua_S)
{
  common::PlayerQuestData* self = (common::PlayerQuestData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'targetCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->targetCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: targetCount of class  common::PlayerQuestData */
#ifndef TOLUA_DISABLE_tolua_set_common__PlayerQuestData_unsigned_targetCount
static int tolua_set_common__PlayerQuestData_unsigned_targetCount(lua_State* tolua_S)
{
  common::PlayerQuestData* self = (common::PlayerQuestData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'targetCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->targetCount = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: endTime of class  common::PlayerQuestData */
#ifndef TOLUA_DISABLE_tolua_get_common__PlayerQuestData_unsigned_endTime
static int tolua_get_common__PlayerQuestData_unsigned_endTime(lua_State* tolua_S)
{
  common::PlayerQuestData* self = (common::PlayerQuestData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endTime'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->endTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: endTime of class  common::PlayerQuestData */
#ifndef TOLUA_DISABLE_tolua_set_common__PlayerQuestData_unsigned_endTime
static int tolua_set_common__PlayerQuestData_unsigned_endTime(lua_State* tolua_S)
{
  common::PlayerQuestData* self = (common::PlayerQuestData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endTime'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->endTime = ((unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: target of class  common::PlayerQuestData */
#ifndef TOLUA_DISABLE_tolua_get_common__PlayerQuestData_unsigned_target
static int tolua_get_common__PlayerQuestData_unsigned_target(lua_State* tolua_S)
{
  common::PlayerQuestData* self = (common::PlayerQuestData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'target'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->target);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: target of class  common::PlayerQuestData */
#ifndef TOLUA_DISABLE_tolua_set_common__PlayerQuestData_unsigned_target
static int tolua_set_common__PlayerQuestData_unsigned_target(lua_State* tolua_S)
{
  common::PlayerQuestData* self = (common::PlayerQuestData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'target'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->target,(const char*)tolua_tostring(tolua_S,2,0),4-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mask of class  common::PlayerDoneQuestData */
#ifndef TOLUA_DISABLE_tolua_get_common__PlayerDoneQuestData_unsigned_mask
static int tolua_get_common__PlayerDoneQuestData_unsigned_mask(lua_State* tolua_S)
{
  common::PlayerDoneQuestData* self = (common::PlayerDoneQuestData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mask'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mask);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mask of class  common::PlayerDoneQuestData */
#ifndef TOLUA_DISABLE_tolua_set_common__PlayerDoneQuestData_unsigned_mask
static int tolua_set_common__PlayerDoneQuestData_unsigned_mask(lua_State* tolua_S)
{
  common::PlayerDoneQuestData* self = (common::PlayerDoneQuestData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mask'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mask = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: questID of class  common::PlayerDoneQuestData */
#ifndef TOLUA_DISABLE_tolua_get_common__PlayerDoneQuestData_unsigned_questID
static int tolua_get_common__PlayerDoneQuestData_unsigned_questID(lua_State* tolua_S)
{
  common::PlayerDoneQuestData* self = (common::PlayerDoneQuestData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'questID'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->questID);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: questID of class  common::PlayerDoneQuestData */
#ifndef TOLUA_DISABLE_tolua_set_common__PlayerDoneQuestData_unsigned_questID
static int tolua_set_common__PlayerDoneQuestData_unsigned_questID(lua_State* tolua_S)
{
  common::PlayerDoneQuestData* self = (common::PlayerDoneQuestData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'questID'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->questID = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: series of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_get_common__Bead_series
static int tolua_get_common__Bead_series(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'series'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->series,"BeadSeries");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: series of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_set_common__Bead_series
static int tolua_set_common__Bead_series(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'series'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"BeadSeries",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->series = *((BeadSeries*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: beadId of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_get_common__Bead_unsigned_beadId
static int tolua_get_common__Bead_unsigned_beadId(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'beadId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->beadId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: beadId of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_set_common__Bead_unsigned_beadId
static int tolua_set_common__Bead_unsigned_beadId(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'beadId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->beadId = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: addSoulEater of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_get_common__Bead_unsigned_addSoulEater
static int tolua_get_common__Bead_unsigned_addSoulEater(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'addSoulEater'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->addSoulEater);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: addSoulEater of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_set_common__Bead_unsigned_addSoulEater
static int tolua_set_common__Bead_unsigned_addSoulEater(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'addSoulEater'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->addSoulEater = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: exp of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_get_common__Bead_unsigned_exp
static int tolua_get_common__Bead_unsigned_exp(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'exp'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->exp);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: exp of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_set_common__Bead_unsigned_exp
static int tolua_set_common__Bead_unsigned_exp(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'exp'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->exp = ((unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: baseAttr of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_get_common__Bead_baseAttr
static int tolua_get_common__Bead_baseAttr(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'baseAttr'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->baseAttr,"common::Attribute");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: baseAttr of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_set_common__Bead_baseAttr
static int tolua_set_common__Bead_baseAttr(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'baseAttr'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"common::Attribute",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->baseAttr = *((common::Attribute*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: addAttr of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_get_common__Bead_addAttr
static int tolua_get_common__Bead_addAttr(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'addAttr'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->addAttr,"common::Attribute");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: addAttr of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_set_common__Bead_addAttr
static int tolua_set_common__Bead_addAttr(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'addAttr'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"common::Attribute",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->addAttr = *((common::Attribute*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: elementRatio of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_get_common__Bead_unsigned_elementRatio
static int tolua_get_common__Bead_unsigned_elementRatio(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'elementRatio'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->elementRatio);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: elementRatio of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_set_common__Bead_unsigned_elementRatio
static int tolua_set_common__Bead_unsigned_elementRatio(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'elementRatio'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->elementRatio = ((unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: level of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_get_common__Bead_unsigned_level
static int tolua_get_common__Bead_unsigned_level(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'level'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->level);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: level of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_set_common__Bead_unsigned_level
static int tolua_set_common__Bead_unsigned_level(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'level'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->level = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: reserve of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_get_common__Bead_unsigned_reserve
static int tolua_get_common__Bead_unsigned_reserve(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'reserve'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->reserve);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: reserve of class  common::Bead */
#ifndef TOLUA_DISABLE_tolua_set_common__Bead_unsigned_reserve
static int tolua_set_common__Bead_unsigned_reserve(lua_State* tolua_S)
{
  common::Bead* self = (common::Bead*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'reserve'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->reserve,(const char*)tolua_tostring(tolua_S,2,0),3-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: weaponId of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_get_common__Weapon_unsigned_weaponId
static int tolua_get_common__Weapon_unsigned_weaponId(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'weaponId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->weaponId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: weaponId of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_set_common__Weapon_unsigned_weaponId
static int tolua_set_common__Weapon_unsigned_weaponId(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'weaponId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->weaponId = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: level of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_get_common__Weapon_unsigned_level
static int tolua_get_common__Weapon_unsigned_level(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'level'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->level);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: level of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_set_common__Weapon_unsigned_level
static int tolua_set_common__Weapon_unsigned_level(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'level'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->level = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: soulEater of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_get_common__Weapon_unsigned_soulEater
static int tolua_get_common__Weapon_unsigned_soulEater(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'soulEater'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->soulEater);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: soulEater of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_set_common__Weapon_unsigned_soulEater
static int tolua_set_common__Weapon_unsigned_soulEater(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'soulEater'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->soulEater = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: eternalValue of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_get_common__Weapon_unsigned_eternalValue
static int tolua_get_common__Weapon_unsigned_eternalValue(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eternalValue'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->eternalValue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: eternalValue of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_set_common__Weapon_unsigned_eternalValue
static int tolua_set_common__Weapon_unsigned_eternalValue(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eternalValue'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->eternalValue = ((unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxEternalValue of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_get_common__Weapon_unsigned_maxEternalValue
static int tolua_get_common__Weapon_unsigned_maxEternalValue(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxEternalValue'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->maxEternalValue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxEternalValue of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_set_common__Weapon_unsigned_maxEternalValue
static int tolua_set_common__Weapon_unsigned_maxEternalValue(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxEternalValue'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->maxEternalValue = ((unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: baseAttr of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_get_common__Weapon_baseAttr
static int tolua_get_common__Weapon_baseAttr(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'baseAttr'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->baseAttr,"common::Attribute");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: baseAttr of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_set_common__Weapon_baseAttr
static int tolua_set_common__Weapon_baseAttr(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'baseAttr'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"common::Attribute",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->baseAttr = *((common::Attribute*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: holeBeads of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_get_serverLuaInterface_common_Weapon_holeBeads
static int tolua_get_serverLuaInterface_common_Weapon_holeBeads(lua_State* tolua_S)
{
 int tolua_index;
  common::Weapon* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (common::Weapon*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=MAX_WEAPON_HOLES)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->holeBeads[tolua_index],"BeadSeries");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: holeBeads of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_set_serverLuaInterface_common_Weapon_holeBeads
static int tolua_set_serverLuaInterface_common_Weapon_holeBeads(lua_State* tolua_S)
{
 int tolua_index;
  common::Weapon* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (common::Weapon*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=MAX_WEAPON_HOLES)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->holeBeads[tolua_index] = *((BeadSeries*)  tolua_tousertype(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: holeState of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_get_common__Weapon_unsigned_holeState
static int tolua_get_common__Weapon_unsigned_holeState(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'holeState'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->holeState);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: holeState of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_set_common__Weapon_unsigned_holeState
static int tolua_set_common__Weapon_unsigned_holeState(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'holeState'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->holeState,(const char*)tolua_tostring(tolua_S,2,0),MAX_WEAPON_HOLES-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: reserve of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_get_common__Weapon_unsigned_reserve
static int tolua_get_common__Weapon_unsigned_reserve(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'reserve'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->reserve);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: reserve of class  common::Weapon */
#ifndef TOLUA_DISABLE_tolua_set_common__Weapon_unsigned_reserve
static int tolua_set_common__Weapon_unsigned_reserve(lua_State* tolua_S)
{
  common::Weapon* self = (common::Weapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'reserve'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->reserve = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: series of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_get_common__DropItemData_series
static int tolua_get_common__DropItemData_series(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'series'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->series,"ItemSeries");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: series of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_set_common__DropItemData_series
static int tolua_set_common__DropItemData_series(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'series'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ItemSeries",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->series = *((ItemSeries*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ownerId of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_get_common__DropItemData_ownerId
static int tolua_get_common__DropItemData_ownerId(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ownerId'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->ownerId,"PlayerId");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ownerId of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_set_common__DropItemData_ownerId
static int tolua_set_common__DropItemData_ownerId(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ownerId'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"PlayerId",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ownerId = *((PlayerId*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: serverIdent of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_get_common__DropItemData_serverIdent
static int tolua_get_common__DropItemData_serverIdent(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'serverIdent'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->serverIdent);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: serverIdent of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_set_common__DropItemData_serverIdent
static int tolua_set_common__DropItemData_serverIdent(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'serverIdent'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->serverIdent = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: expireTime of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_get_common__DropItemData_unsigned_expireTime
static int tolua_get_common__DropItemData_unsigned_expireTime(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'expireTime'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->expireTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: expireTime of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_set_common__DropItemData_unsigned_expireTime
static int tolua_set_common__DropItemData_unsigned_expireTime(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'expireTime'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->expireTime = ((unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: itemId of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_get_common__DropItemData_itemId
static int tolua_get_common__DropItemData_itemId(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'itemId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->itemId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: itemId of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_set_common__DropItemData_itemId
static int tolua_set_common__DropItemData_itemId(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'itemId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->itemId = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: quality of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_get_common__DropItemData_unsigned_quality
static int tolua_get_common__DropItemData_unsigned_quality(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'quality'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->quality);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: quality of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_set_common__DropItemData_unsigned_quality
static int tolua_set_common__DropItemData_unsigned_quality(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'quality'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->quality = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: strong of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_get_common__DropItemData_unsigned_strong
static int tolua_get_common__DropItemData_unsigned_strong(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'strong'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->strong);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: strong of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_set_common__DropItemData_unsigned_strong
static int tolua_set_common__DropItemData_unsigned_strong(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'strong'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->strong = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: itemCount of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_get_common__DropItemData_itemCount
static int tolua_get_common__DropItemData_itemCount(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'itemCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->itemCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: itemCount of class  common::DropItemData */
#ifndef TOLUA_DISABLE_tolua_set_common__DropItemData_itemCount
static int tolua_set_common__DropItemData_itemCount(lua_State* tolua_S)
{
  common::DropItemData* self = (common::DropItemData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'itemCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->itemCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: series of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_get_common__SendClientDropItem_series
static int tolua_get_common__SendClientDropItem_series(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'series'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->series,"ItemSeries");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: series of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_set_common__SendClientDropItem_series
static int tolua_set_common__SendClientDropItem_series(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'series'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ItemSeries",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->series = *((ItemSeries*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: serverIdent of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_get_common__SendClientDropItem_serverIdent
static int tolua_get_common__SendClientDropItem_serverIdent(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'serverIdent'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->serverIdent);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: serverIdent of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_set_common__SendClientDropItem_serverIdent
static int tolua_set_common__SendClientDropItem_serverIdent(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'serverIdent'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->serverIdent = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: itemId of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_get_common__SendClientDropItem_itemId
static int tolua_get_common__SendClientDropItem_itemId(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'itemId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->itemId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: itemId of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_set_common__SendClientDropItem_itemId
static int tolua_set_common__SendClientDropItem_itemId(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'itemId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->itemId = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: itemCount of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_get_common__SendClientDropItem_unsigned_itemCount
static int tolua_get_common__SendClientDropItem_unsigned_itemCount(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'itemCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->itemCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: itemCount of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_set_common__SendClientDropItem_unsigned_itemCount
static int tolua_set_common__SendClientDropItem_unsigned_itemCount(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'itemCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->itemCount = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: quality of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_get_common__SendClientDropItem_unsigned_quality
static int tolua_get_common__SendClientDropItem_unsigned_quality(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'quality'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->quality);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: quality of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_set_common__SendClientDropItem_unsigned_quality
static int tolua_set_common__SendClientDropItem_unsigned_quality(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'quality'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->quality = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: strong of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_get_common__SendClientDropItem_unsigned_strong
static int tolua_get_common__SendClientDropItem_unsigned_strong(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'strong'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->strong);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: strong of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_set_common__SendClientDropItem_unsigned_strong
static int tolua_set_common__SendClientDropItem_unsigned_strong(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'strong'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->strong = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_get_common__SendClientDropItem_x
static int tolua_get_common__SendClientDropItem_x(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_set_common__SendClientDropItem_x
static int tolua_set_common__SendClientDropItem_x(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_get_common__SendClientDropItem_y
static int tolua_get_common__SendClientDropItem_y(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  common::SendClientDropItem */
#ifndef TOLUA_DISABLE_tolua_set_common__SendClientDropItem_y
static int tolua_set_common__SendClientDropItem_y(lua_State* tolua_S)
{
  common::SendClientDropItem* self = (common::SendClientDropItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ItemAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_ItemAccessor_new00
static int tolua_serverLuaInterface_ItemAccessor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ItemAccessor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ItemAccessor* tolua_ret = (ItemAccessor*)  Mtolua_new((ItemAccessor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ItemAccessor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ItemAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_ItemAccessor_new00_local
static int tolua_serverLuaInterface_ItemAccessor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ItemAccessor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ItemAccessor* tolua_ret = (ItemAccessor*)  Mtolua_new((ItemAccessor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ItemAccessor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ItemAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_ItemAccessor_delete00
static int tolua_serverLuaInterface_ItemAccessor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ItemAccessor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ItemAccessor* self = (ItemAccessor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getItem of class  ItemAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_ItemAccessor_getItem00
static int tolua_serverLuaInterface_ItemAccessor_getItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ItemAccessor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint32",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ItemAccessor* self = (const ItemAccessor*)  tolua_tousertype(tolua_S,1,0);
  uint32 itemId = *((uint32*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getItem'", NULL);
#endif
  {
   const CFItem* tolua_ret = (const CFItem*)  self->getItem(itemId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const CFItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getItemByName of class  ItemAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_ItemAccessor_getItemByName00
static int tolua_serverLuaInterface_ItemAccessor_getItemByName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ItemAccessor",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ItemAccessor* self = (const ItemAccessor*)  tolua_tousertype(tolua_S,1,0);
  const char* sName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getItemByName'", NULL);
#endif
  {
   const CFItem* tolua_ret = (const CFItem*)  self->getItemByName(sName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const CFItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getItemByName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  PlayerDataAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_PlayerDataAccessor_new00
static int tolua_serverLuaInterface_PlayerDataAccessor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PlayerDataAccessor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   PlayerDataAccessor* tolua_ret = (PlayerDataAccessor*)  Mtolua_new((PlayerDataAccessor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PlayerDataAccessor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  PlayerDataAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_PlayerDataAccessor_new00_local
static int tolua_serverLuaInterface_PlayerDataAccessor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PlayerDataAccessor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   PlayerDataAccessor* tolua_ret = (PlayerDataAccessor*)  Mtolua_new((PlayerDataAccessor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PlayerDataAccessor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  PlayerDataAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_PlayerDataAccessor_delete00
static int tolua_serverLuaInterface_PlayerDataAccessor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PlayerDataAccessor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PlayerDataAccessor* self = (PlayerDataAccessor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLevel of class  PlayerDataAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_PlayerDataAccessor_getLevel00
static int tolua_serverLuaInterface_PlayerDataAccessor_getLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const PlayerDataAccessor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const PlayerDataAccessor* self = (const PlayerDataAccessor*)  tolua_tousertype(tolua_S,1,0);
  int level = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLevel'", NULL);
#endif
  {
   const CFPlayerLevel* tolua_ret = (const CFPlayerLevel*)  self->getLevel(level);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const CFPlayerLevel");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadConfig of class  PlayerDataAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_PlayerDataAccessor_loadConfig00
static int tolua_serverLuaInterface_PlayerDataAccessor_loadConfig00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PlayerDataAccessor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PlayerDataAccessor* self = (PlayerDataAccessor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadConfig'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->loadConfig();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadConfig'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  WeaponAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_WeaponAccessor_new00
static int tolua_serverLuaInterface_WeaponAccessor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"WeaponAccessor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   WeaponAccessor* tolua_ret = (WeaponAccessor*)  Mtolua_new((WeaponAccessor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"WeaponAccessor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  WeaponAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_WeaponAccessor_new00_local
static int tolua_serverLuaInterface_WeaponAccessor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"WeaponAccessor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   WeaponAccessor* tolua_ret = (WeaponAccessor*)  Mtolua_new((WeaponAccessor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"WeaponAccessor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  WeaponAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_WeaponAccessor_delete00
static int tolua_serverLuaInterface_WeaponAccessor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"WeaponAccessor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  WeaponAccessor* self = (WeaponAccessor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBeadById of class  WeaponAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_WeaponAccessor_getBeadById00
static int tolua_serverLuaInterface_WeaponAccessor_getBeadById00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const WeaponAccessor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint32",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const WeaponAccessor* self = (const WeaponAccessor*)  tolua_tousertype(tolua_S,1,0);
  uint32 id = *((uint32*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBeadById'", NULL);
#endif
  {
   const CFBead* tolua_ret = (const CFBead*)  self->getBeadById(id);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const CFBead");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBeadById'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWeaponById of class  WeaponAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_WeaponAccessor_getWeaponById00
static int tolua_serverLuaInterface_WeaponAccessor_getWeaponById00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const WeaponAccessor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint8",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const WeaponAccessor* self = (const WeaponAccessor*)  tolua_tousertype(tolua_S,1,0);
  uint8 id = *((uint8*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWeaponById'", NULL);
#endif
  {
   const CFWeapon* tolua_ret = (const CFWeapon*)  self->getWeaponById(id);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const CFWeapon");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWeaponById'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBeadQuality of class  WeaponAccessor */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_WeaponAccessor_getBeadQuality00
static int tolua_serverLuaInterface_WeaponAccessor_getBeadQuality00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const WeaponAccessor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint8",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const WeaponAccessor* self = (const WeaponAccessor*)  tolua_tousertype(tolua_S,1,0);
  uint8 quality = *((uint8*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBeadQuality'", NULL);
#endif
  {
   const StdBeadQuality* tolua_ret = (const StdBeadQuality*)  self->getBeadQuality(quality);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const StdBeadQuality");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBeadQuality'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Scene */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_Scene_new00
static int tolua_serverLuaInterface_Scene_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Scene* tolua_ret = (Scene*)  Mtolua_new((Scene)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Scene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Scene */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_Scene_new00_local
static int tolua_serverLuaInterface_Scene_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Scene* tolua_ret = (Scene*)  Mtolua_new((Scene)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Scene");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Scene */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_Scene_new01
static int tolua_serverLuaInterface_Scene_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Scene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint32",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  uint32 sceneId = *((uint32*)  tolua_tousertype(tolua_S,2,0));
  {
   Scene* tolua_ret = (Scene*)  Mtolua_new((Scene)(sceneId));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Scene");
  }
 }
 return 1;
tolua_lerror:
 return tolua_serverLuaInterface_Scene_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Scene */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_Scene_new01_local
static int tolua_serverLuaInterface_Scene_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Scene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint32",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  uint32 sceneId = *((uint32*)  tolua_tousertype(tolua_S,2,0));
  {
   Scene* tolua_ret = (Scene*)  Mtolua_new((Scene)(sceneId));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Scene");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_serverLuaInterface_Scene_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Scene */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_Scene_delete00
static int tolua_serverLuaInterface_Scene_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destory of class  Scene */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_Scene_destory00
static int tolua_serverLuaInterface_Scene_destory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destory'", NULL);
#endif
  {
   self->destory();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reset of class  Scene */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_Scene_reset00
static int tolua_serverLuaInterface_Scene_reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reset'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->reset();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithSceneId of class  Scene */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_Scene_initWithSceneId00
static int tolua_serverLuaInterface_Scene_initWithSceneId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  int sceneId = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithSceneId'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithSceneId(sceneId);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithSceneId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNpcNode of class  Scene */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_Scene_getNpcNode00
static int tolua_serverLuaInterface_Scene_getNpcNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  int npcId = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNpcNode'", NULL);
#endif
  {
   CNpc* tolua_ret = (CNpc*)  self->getNpcNode(npcId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CNpc");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNpcNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setNpcNode of class  Scene */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_Scene_setNpcNode00
static int tolua_serverLuaInterface_Scene_setNpcNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SceneNpc",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  SceneNpc* sceneNpc = ((SceneNpc*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setNpcNode'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setNpcNode(sceneNpc);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNpcNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getpSceneStruct of class  Scene */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_Scene_getpSceneStruct00
static int tolua_serverLuaInterface_Scene_getpSceneStruct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getpSceneStruct'", NULL);
#endif
  {
   SceneStruct* tolua_ret = (SceneStruct*)  self->getpSceneStruct();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneStruct");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getpSceneStruct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSceneMap of class  Scene */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_Scene_getSceneMap00
static int tolua_serverLuaInterface_Scene_getSceneMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneMap'", NULL);
#endif
  {
   MapArchiver* tolua_ret = (MapArchiver*)  self->getSceneMap();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MapArchiver");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSceneMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isStaticScene of class  Scene */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_Scene_isStaticScene00
static int tolua_serverLuaInterface_Scene_isStaticScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isStaticScene'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isStaticScene();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isStaticScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nSceneId of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_m_nSceneId
static int tolua_get_Scene_m_nSceneId(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nSceneId'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_nSceneId,"uint32");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nSceneId of class  Scene */
#ifndef TOLUA_DISABLE_tolua_set_Scene_m_nSceneId
static int tolua_set_Scene_m_nSceneId(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nSceneId'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint32",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nSceneId = *((uint32*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nMapWidth of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_m_nMapWidth
static int tolua_get_Scene_m_nMapWidth(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nMapWidth'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nMapWidth);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nMapWidth of class  Scene */
#ifndef TOLUA_DISABLE_tolua_set_Scene_m_nMapWidth
static int tolua_set_Scene_m_nMapWidth(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nMapWidth'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nMapWidth = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nMapHeight of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_m_nMapHeight
static int tolua_get_Scene_m_nMapHeight(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nMapHeight'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nMapHeight);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nMapHeight of class  Scene */
#ifndef TOLUA_DISABLE_tolua_set_Scene_m_nMapHeight
static int tolua_set_Scene_m_nMapHeight(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nMapHeight'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nMapHeight = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pMapGrid of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_m_pMapGrid_ptr
static int tolua_get_Scene_m_pMapGrid_ptr(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pMapGrid'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pMapGrid,"CMapGrid");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pMapGrid of class  Scene */
#ifndef TOLUA_DISABLE_tolua_set_Scene_m_pMapGrid_ptr
static int tolua_set_Scene_m_pMapGrid_ptr(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pMapGrid'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CMapGrid",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pMapGrid = ((CMapGrid*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pSceneManager of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_m_pSceneManager_ptr
static int tolua_get_Scene_m_pSceneManager_ptr(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pSceneManager'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pSceneManager,"SceneManager");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pSceneManager of class  Scene */
#ifndef TOLUA_DISABLE_tolua_set_Scene_m_pSceneManager_ptr
static int tolua_set_Scene_m_pSceneManager_ptr(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pSceneManager'",NULL);
  if (!tolua_isusertype(tolua_S,2,"SceneManager",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pSceneManager = ((SceneManager*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pSceneStruct of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_m_pSceneStruct_ptr
static int tolua_get_Scene_m_pSceneStruct_ptr(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pSceneStruct'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pSceneStruct,"SceneStruct");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pSceneStruct of class  Scene */
#ifndef TOLUA_DISABLE_tolua_set_Scene_m_pSceneStruct_ptr
static int tolua_set_Scene_m_pSceneStruct_ptr(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pSceneStruct'",NULL);
  if (!tolua_isusertype(tolua_S,2,"SceneStruct",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pSceneStruct = ((SceneStruct*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pSceneMap of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_m_pSceneMap_ptr
static int tolua_get_Scene_m_pSceneMap_ptr(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pSceneMap'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pSceneMap,"MapArchiver");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pSceneMap of class  Scene */
#ifndef TOLUA_DISABLE_tolua_set_Scene_m_pSceneMap_ptr
static int tolua_set_Scene_m_pSceneMap_ptr(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pSceneMap'",NULL);
  if (!tolua_isusertype(tolua_S,2,"MapArchiver",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pSceneMap = ((MapArchiver*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  DuplicateManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_DuplicateManager_new00
static int tolua_serverLuaInterface_DuplicateManager_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DuplicateManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   DuplicateManager* tolua_ret = (DuplicateManager*)  Mtolua_new((DuplicateManager)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"DuplicateManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  DuplicateManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_DuplicateManager_new00_local
static int tolua_serverLuaInterface_DuplicateManager_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DuplicateManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   DuplicateManager* tolua_ret = (DuplicateManager*)  Mtolua_new((DuplicateManager)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"DuplicateManager");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  DuplicateManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_DuplicateManager_delete00
static int tolua_serverLuaInterface_DuplicateManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DuplicateManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DuplicateManager* self = (DuplicateManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroy of class  DuplicateManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_DuplicateManager_destroy00
static int tolua_serverLuaInterface_DuplicateManager_destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DuplicateManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DuplicateManager* self = (DuplicateManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroy'", NULL);
#endif
  {
   self->destroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  DuplicateManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_DuplicateManager_init00
static int tolua_serverLuaInterface_DuplicateManager_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DuplicateManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DuplicateManager* self = (DuplicateManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createDuplicate of class  DuplicateManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_DuplicateManager_createDuplicate00
static int tolua_serverLuaInterface_DuplicateManager_createDuplicate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DuplicateManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DuplicateManager* self = (DuplicateManager*)  tolua_tousertype(tolua_S,1,0);
  int duplicateId = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createDuplicate'", NULL);
#endif
  {
   SceneManager* tolua_ret = (SceneManager*)  self->createDuplicate(duplicateId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createDuplicate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDuplicateByGuid of class  DuplicateManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_DuplicateManager_getDuplicateByGuid00
static int tolua_serverLuaInterface_DuplicateManager_getDuplicateByGuid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DuplicateManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint64",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DuplicateManager* self = (DuplicateManager*)  tolua_tousertype(tolua_S,1,0);
  uint64 guid = *((uint64*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDuplicateByGuid'", NULL);
#endif
  {
   SceneManager* tolua_ret = (SceneManager*)  self->getDuplicateByGuid(guid);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDuplicateByGuid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSceneByDuplicateGuidAndSceneId of class  DuplicateManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_DuplicateManager_getSceneByDuplicateGuidAndSceneId00
static int tolua_serverLuaInterface_DuplicateManager_getSceneByDuplicateGuidAndSceneId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DuplicateManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DuplicateManager* self = (DuplicateManager*)  tolua_tousertype(tolua_S,1,0);
  int guid = ((int)  tolua_tonumber(tolua_S,2,0));
  int sceneId = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneByDuplicateGuidAndSceneId'", NULL);
#endif
  {
   const Scene* tolua_ret = (const Scene*)  self->getSceneByDuplicateGuidAndSceneId(guid,sceneId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const Scene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSceneByDuplicateGuidAndSceneId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnRoutine of class  DuplicateManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_DuplicateManager_OnRoutine00
static int tolua_serverLuaInterface_DuplicateManager_OnRoutine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DuplicateManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DuplicateManager* self = (DuplicateManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnRoutine'", NULL);
#endif
  {
   self->OnRoutine();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnRoutine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: testScene of class  DuplicateManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_DuplicateManager_testScene00
static int tolua_serverLuaInterface_DuplicateManager_testScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DuplicateManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   DuplicateManager::testScene();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'testScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_dynamicGuid of class  DuplicateManager */
#ifndef TOLUA_DISABLE_tolua_get_DuplicateManager_m_dynamicGuid
static int tolua_get_DuplicateManager_m_dynamicGuid(lua_State* tolua_S)
{
  DuplicateManager* self = (DuplicateManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dynamicGuid'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_dynamicGuid,"uint64");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_dynamicGuid of class  DuplicateManager */
#ifndef TOLUA_DISABLE_tolua_set_DuplicateManager_m_dynamicGuid
static int tolua_set_DuplicateManager_m_dynamicGuid(lua_State* tolua_S)
{
  DuplicateManager* self = (DuplicateManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dynamicGuid'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint64",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_dynamicGuid = *((uint64*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_SceneManager_new00
static int tolua_serverLuaInterface_SceneManager_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SceneManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint64",1,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  uint64 guid = *((uint64*)  tolua_tousertype(tolua_S,2,(void*)0));
  {
   SceneManager* tolua_ret = (SceneManager*)  Mtolua_new((SceneManager)(guid));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_SceneManager_new00_local
static int tolua_serverLuaInterface_SceneManager_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SceneManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint64",1,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  uint64 guid = *((uint64*)  tolua_tousertype(tolua_S,2,(void*)0));
  {
   SceneManager* tolua_ret = (SceneManager*)  Mtolua_new((SceneManager)(guid));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneManager");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_SceneManager_delete00
static int tolua_serverLuaInterface_SceneManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_SceneManager_init00
static int tolua_serverLuaInterface_SceneManager_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const SceneIdList",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"const DuplicateStruct",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const SceneIdList* sceneIdList = ((const SceneIdList*)  tolua_tousertype(tolua_S,2,0));
  const DuplicateStruct* duplicateStruct = ((const DuplicateStruct*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   self->init(*sceneIdList,duplicateStruct);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initScenes of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_SceneManager_initScenes00
static int tolua_serverLuaInterface_SceneManager_initScenes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const SceneIdList",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const SceneIdList* sceneIdList = ((const SceneIdList*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initScenes'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initScenes(*sceneIdList);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initScenes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyScenes of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_SceneManager_destroyScenes00
static int tolua_serverLuaInterface_SceneManager_destroyScenes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyScenes'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->destroyScenes();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyScenes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addScene of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_SceneManager_addScene00
static int tolua_serverLuaInterface_SceneManager_addScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint32",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
  uint32 sceneId = *((uint32*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addScene'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->addScene(sceneId);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSceneByID of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_SceneManager_getSceneByID00
static int tolua_serverLuaInterface_SceneManager_getSceneByID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint32",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
  uint32 id = *((uint32*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneByID'", NULL);
#endif
  {
   Scene* tolua_ret = (Scene*)  self->getSceneByID(id);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Scene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSceneByID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: popSceneBySceneID of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_SceneManager_popSceneBySceneID00
static int tolua_serverLuaInterface_SceneManager_popSceneBySceneID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint32",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
  uint32 sceneId = *((uint32*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popSceneBySceneID'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->popSceneBySceneID(sceneId);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popSceneBySceneID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addPlayer of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_SceneManager_addPlayer00
static int tolua_serverLuaInterface_SceneManager_addPlayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CEntity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
  CEntity* player = ((CEntity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addPlayer'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->addPlayer(player);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addPlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delPlayer of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_SceneManager_delPlayer00
static int tolua_serverLuaInterface_SceneManager_delPlayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CEntity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
  CEntity* player = ((CEntity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delPlayer'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->delPlayer(player);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delPlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_playerNum of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_get_SceneManager_m_playerNum
static int tolua_get_SceneManager_m_playerNum(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_playerNum'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_playerNum);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_playerNum of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_set_SceneManager_m_playerNum
static int tolua_set_SceneManager_m_playerNum(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_playerNum'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_playerNum = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_lastPlayerLeaveTime of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_get_SceneManager_unsigned_m_lastPlayerLeaveTime
static int tolua_get_SceneManager_unsigned_m_lastPlayerLeaveTime(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_lastPlayerLeaveTime'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_lastPlayerLeaveTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_lastPlayerLeaveTime of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_set_SceneManager_unsigned_m_lastPlayerLeaveTime
static int tolua_set_SceneManager_unsigned_m_lastPlayerLeaveTime(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_lastPlayerLeaveTime'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_lastPlayerLeaveTime = ((unsigned long)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_playerList of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_get_SceneManager_m_playerList
static int tolua_get_SceneManager_m_playerList(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_playerList'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_playerList,"PlayerList");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_playerList of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_set_SceneManager_m_playerList
static int tolua_set_SceneManager_m_playerList(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_playerList'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"PlayerList",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_playerList = *((PlayerList*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_duplicateName of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_get_SceneManager_m_duplicateName
static int tolua_get_SceneManager_m_duplicateName(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_duplicateName'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->m_duplicateName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_duplicateName of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_set_SceneManager_m_duplicateName
static int tolua_set_SceneManager_m_duplicateName(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_duplicateName'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->m_duplicateName,(const char*)tolua_tostring(tolua_S,2,0),48-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_duplicateId of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_get_SceneManager_m_duplicateId
static int tolua_get_SceneManager_m_duplicateId(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_duplicateId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_duplicateId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_duplicateId of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_set_SceneManager_m_duplicateId
static int tolua_set_SceneManager_m_duplicateId(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_duplicateId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_duplicateId = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_Guid of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_get_SceneManager_m_Guid
static int tolua_get_SceneManager_m_Guid(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Guid'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_Guid,"uint64");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_Guid of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_set_SceneManager_m_Guid
static int tolua_set_SceneManager_m_Guid(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Guid'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint64",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_Guid = *((uint64*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_firstSceneX of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_get_SceneManager_m_firstSceneX
static int tolua_get_SceneManager_m_firstSceneX(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_firstSceneX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_firstSceneX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_firstSceneX of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_set_SceneManager_m_firstSceneX
static int tolua_set_SceneManager_m_firstSceneX(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_firstSceneX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_firstSceneX = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_firstSceneY of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_get_SceneManager_m_firstSceneY
static int tolua_get_SceneManager_m_firstSceneY(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_firstSceneY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_firstSceneY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_firstSceneY of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_set_SceneManager_m_firstSceneY
static int tolua_set_SceneManager_m_firstSceneY(lua_State* tolua_S)
{
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_firstSceneY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_firstSceneY = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mask of class  ViewStruct */
#ifndef TOLUA_DISABLE_tolua_get_CEntity__ViewStruct_unsigned_mask
static int tolua_get_CEntity__ViewStruct_unsigned_mask(lua_State* tolua_S)
{
  CEntity::ViewStruct* self = (CEntity::ViewStruct*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mask'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mask);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mask of class  ViewStruct */
#ifndef TOLUA_DISABLE_tolua_set_CEntity__ViewStruct_unsigned_mask
static int tolua_set_CEntity__ViewStruct_unsigned_mask(lua_State* tolua_S)
{
  CEntity::ViewStruct* self = (CEntity::ViewStruct*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mask'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mask = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pEntity of class  ViewStruct */
#ifndef TOLUA_DISABLE_tolua_get_CEntity__ViewStruct_pEntity_ptr
static int tolua_get_CEntity__ViewStruct_pEntity_ptr(lua_State* tolua_S)
{
  CEntity::ViewStruct* self = (CEntity::ViewStruct*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pEntity'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->pEntity,"CEntity");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pEntity of class  ViewStruct */
#ifndef TOLUA_DISABLE_tolua_set_CEntity__ViewStruct_pEntity_ptr
static int tolua_set_CEntity__ViewStruct_pEntity_ptr(lua_State* tolua_S)
{
  CEntity::ViewStruct* self = (CEntity::ViewStruct*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pEntity'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CEntity",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pEntity = ((CEntity*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CEntity_new00
static int tolua_serverLuaInterface_CEntity_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CEntity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CEntity* tolua_ret = (CEntity*)  Mtolua_new((CEntity)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CEntity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CEntity_new00_local
static int tolua_serverLuaInterface_CEntity_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CEntity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CEntity* tolua_ret = (CEntity*)  Mtolua_new((CEntity)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CEntity");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CEntity_delete00
static int tolua_serverLuaInterface_CEntity_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CEntity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CEntity_init00
static int tolua_serverLuaInterface_CEntity_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CEntity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   self->init(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: run of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CEntity_run00
static int tolua_serverLuaInterface_CEntity_run00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CEntity",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
  TickTime dwCurrTick = *((TickTime*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'run'", NULL);
#endif
  {
   self->run(dwCurrTick);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'run'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: disappear of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CEntity_disappear00
static int tolua_serverLuaInterface_CEntity_disappear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CEntity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disappear'", NULL);
#endif
  {
   self->disappear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'disappear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPlayerIndex of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CEntity_getPlayerIndex00
static int tolua_serverLuaInterface_CEntity_getPlayerIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CEntity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPlayerIndex'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getPlayerIndex();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPlayerIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: findEntity of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CEntity_findEntity00
static int tolua_serverLuaInterface_CEntity_findEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CEntity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CBaseObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
  CBaseObject* pEntity = ((CBaseObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'findEntity'", NULL);
#endif
  {
   int tolua_ret = (int)  self->findEntity(pEntity);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'findEntity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRandomKey of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CEntity_getRandomKey00
static int tolua_serverLuaInterface_CEntity_getRandomKey00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CEntity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
  int min = ((int)  tolua_tonumber(tolua_S,2,0));
  int max = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRandomKey'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getRandomKey(min,max);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRandomKey'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScene of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CEntity_setScene00
static int tolua_serverLuaInterface_CEntity_setScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CEntity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScene'", NULL);
#endif
  {
   self->setScene(scene,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setXY of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CEntity_setXY00
static int tolua_serverLuaInterface_CEntity_setXY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CEntity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setXY'", NULL);
#endif
  {
   self->setXY(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setXY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEntityDescription of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CEntity_getEntityDescription00
static int tolua_serverLuaInterface_CEntity_getEntityDescription00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CEntity",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"EntityDesc",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
  EntityDesc* desc = ((EntityDesc*)  tolua_tousertype(tolua_S,2,0));
  CPlayer* player = ((CPlayer*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEntityDescription'", NULL);
#endif
  {
   EntityDesc& tolua_ret = (EntityDesc&)  self->getEntityDescription(*desc,player);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"EntityDesc");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEntityDescription'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_EntityId of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_get_CEntity_m_EntityId
static int tolua_get_CEntity_m_EntityId(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_EntityId'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_EntityId,"STDGUID");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_EntityId of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_set_CEntity_m_EntityId
static int tolua_set_CEntity_m_EntityId(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_EntityId'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"STDGUID",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_EntityId = *((STDGUID*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nX of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_get_CEntity_m_nX
static int tolua_get_CEntity_m_nX(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nX of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_set_CEntity_m_nX
static int tolua_set_CEntity_m_nX(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nX = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nY of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_get_CEntity_m_nY
static int tolua_get_CEntity_m_nY(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nY of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_set_CEntity_m_nY
static int tolua_set_CEntity_m_nY(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nY = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_dwStateMasks of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_get_CEntity_unsigned_m_dwStateMasks
static int tolua_get_CEntity_unsigned_m_dwStateMasks(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwStateMasks'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_dwStateMasks);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_dwStateMasks of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_set_CEntity_unsigned_m_dwStateMasks
static int tolua_set_CEntity_unsigned_m_dwStateMasks(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwStateMasks'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_dwStateMasks = ((unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_btType of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_get_CEntity_unsigned_m_btType
static int tolua_get_CEntity_unsigned_m_btType(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btType'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_btType);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_btType of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_set_CEntity_unsigned_m_btType
static int tolua_set_CEntity_unsigned_m_btType(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btType'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_btType = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_btDirection of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_get_CEntity_m_btDirection
static int tolua_get_CEntity_m_btDirection(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btDirection'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_btDirection);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_btDirection of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_set_CEntity_m_btDirection
static int tolua_set_CEntity_m_btDirection(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btDirection'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_btDirection = ((char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_boDisappeared of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_get_CEntity_m_boDisappeared
static int tolua_get_CEntity_m_boDisappeared(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_boDisappeared'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->m_boDisappeared);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_boDisappeared of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_set_CEntity_m_boDisappeared
static int tolua_set_CEntity_m_boDisappeared(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_boDisappeared'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_boDisappeared = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_boDead of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_get_CEntity_m_boDead
static int tolua_get_CEntity_m_boDead(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_boDead'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->m_boDead);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_boDead of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_set_CEntity_m_boDead
static int tolua_set_CEntity_m_boDead(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_boDead'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_boDead = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_boGodMode of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_get_CEntity_m_boGodMode
static int tolua_get_CEntity_m_boGodMode(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_boGodMode'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->m_boGodMode);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_boGodMode of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_set_CEntity_m_boGodMode
static int tolua_set_CEntity_m_boGodMode(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_boGodMode'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_boGodMode = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _______reserve of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_get_CEntity________reserve
static int tolua_get_CEntity________reserve(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_______reserve'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->_______reserve);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _______reserve of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_set_CEntity________reserve
static int tolua_set_CEntity________reserve(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_______reserve'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->_______reserve,(const char*)tolua_tostring(tolua_S,2,0),1-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_wEntityBody of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_get_CEntity_unsigned_m_wEntityBody
static int tolua_get_CEntity_unsigned_m_wEntityBody(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wEntityBody'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_wEntityBody);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_wEntityBody of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_set_CEntity_unsigned_m_wEntityBody
static int tolua_set_CEntity_unsigned_m_wEntityBody(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wEntityBody'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_wEntityBody = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_ImpactRect of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_get_CEntity_m_ImpactRect
static int tolua_get_CEntity_m_ImpactRect(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_ImpactRect'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_ImpactRect,"GRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_ImpactRect of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_set_CEntity_m_ImpactRect
static int tolua_set_CEntity_m_ImpactRect(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_ImpactRect'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_ImpactRect = *((GRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pScene of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_get_CEntity_m_pScene_ptr
static int tolua_get_CEntity_m_pScene_ptr(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pScene'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pScene,"Scene");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pScene of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_set_CEntity_m_pScene_ptr
static int tolua_set_CEntity_m_pScene_ptr(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pScene'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pScene = ((Scene*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_dwDieTick of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_get_CEntity_m_dwDieTick
static int tolua_get_CEntity_m_dwDieTick(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwDieTick'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_dwDieTick,"TickTime");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_dwDieTick of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_set_CEntity_m_dwDieTick
static int tolua_set_CEntity_m_dwDieTick(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwDieTick'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_dwDieTick = *((TickTime*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_dwDisappearTick of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_get_CEntity_m_dwDisappearTick
static int tolua_get_CEntity_m_dwDisappearTick(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwDisappearTick'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_dwDisappearTick,"TickTime");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_dwDisappearTick of class  CEntity */
#ifndef TOLUA_DISABLE_tolua_set_CEntity_m_dwDisappearTick
static int tolua_set_CEntity_m_dwDisappearTick(lua_State* tolua_S)
{
  CEntity* self = (CEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwDisappearTick'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_dwDisappearTick = *((TickTime*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerAbility_new00
static int tolua_serverLuaInterface_CDoerAbility_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CDoerAbility",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CDoerAbility* tolua_ret = (CDoerAbility*)  Mtolua_new((CDoerAbility)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CDoerAbility");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerAbility_new00_local
static int tolua_serverLuaInterface_CDoerAbility_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CDoerAbility",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CDoerAbility* tolua_ret = (CDoerAbility*)  Mtolua_new((CDoerAbility)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CDoerAbility");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerAbility_delete00
static int tolua_serverLuaInterface_CDoerAbility_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerAbility",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerAbility* self = (CDoerAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recalcAbility of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerAbility_recalcAbility00
static int tolua_serverLuaInterface_CDoerAbility_recalcAbility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerAbility",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerAbility* self = (CDoerAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recalcAbility'", NULL);
#endif
  {
   self->recalcAbility();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'recalcAbility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendAbility of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerAbility_sendAbility00
static int tolua_serverLuaInterface_CDoerAbility_sendAbility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerAbility",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerAbility* self = (CDoerAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendAbility'", NULL);
#endif
  {
   self->sendAbility();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendAbility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nHP of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_get_CDoerAbility_m_nHP
static int tolua_get_CDoerAbility_m_nHP(lua_State* tolua_S)
{
  CDoerAbility* self = (CDoerAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nHP'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nHP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nHP of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_set_CDoerAbility_m_nHP
static int tolua_set_CDoerAbility_m_nHP(lua_State* tolua_S)
{
  CDoerAbility* self = (CDoerAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nHP'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nHP = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nMP of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_get_CDoerAbility_m_nMP
static int tolua_get_CDoerAbility_m_nMP(lua_State* tolua_S)
{
  CDoerAbility* self = (CDoerAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nMP'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nMP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nMP of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_set_CDoerAbility_m_nMP
static int tolua_set_CDoerAbility_m_nMP(lua_State* tolua_S)
{
  CDoerAbility* self = (CDoerAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nMP'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nMP = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_wBody of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_get_CDoerAbility_unsigned_m_wBody
static int tolua_get_CDoerAbility_unsigned_m_wBody(lua_State* tolua_S)
{
  CDoerAbility* self = (CDoerAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wBody'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_wBody);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_wBody of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_set_CDoerAbility_unsigned_m_wBody
static int tolua_set_CDoerAbility_unsigned_m_wBody(lua_State* tolua_S)
{
  CDoerAbility* self = (CDoerAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wBody'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_wBody = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_wWeapon of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_get_CDoerAbility_unsigned_m_wWeapon
static int tolua_get_CDoerAbility_unsigned_m_wWeapon(lua_State* tolua_S)
{
  CDoerAbility* self = (CDoerAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wWeapon'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_wWeapon);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_wWeapon of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_set_CDoerAbility_unsigned_m_wWeapon
static int tolua_set_CDoerAbility_unsigned_m_wWeapon(lua_State* tolua_S)
{
  CDoerAbility* self = (CDoerAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wWeapon'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_wWeapon = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_wMount of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_get_CDoerAbility_unsigned_m_wMount
static int tolua_get_CDoerAbility_unsigned_m_wMount(lua_State* tolua_S)
{
  CDoerAbility* self = (CDoerAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wMount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_wMount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_wMount of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_set_CDoerAbility_unsigned_m_wMount
static int tolua_set_CDoerAbility_unsigned_m_wMount(lua_State* tolua_S)
{
  CDoerAbility* self = (CDoerAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wMount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_wMount = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __DoerAbilData__ of class  CDoerAbility */
#ifndef TOLUA_DISABLE_tolua_get_CDoerAbility___DoerAbilData__
static int tolua_get_CDoerAbility___DoerAbilData__(lua_State* tolua_S)
{
  CDoerAbility* self = (CDoerAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__DoerAbilData__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<DoerAbilData*>(self), "DoerAbilData");
#else
   tolua_pushusertype(tolua_S,(void*)((DoerAbilData*)self), "DoerAbilData");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: biLi of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_biLi
static int tolua_get_DoerAbilData_biLi(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'biLi'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->biLi,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: biLi of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_biLi
static int tolua_set_DoerAbilData_biLi(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'biLi'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->biLi = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: lingQiao of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_lingQiao
static int tolua_get_DoerAbilData_lingQiao(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lingQiao'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->lingQiao,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: lingQiao of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_lingQiao
static int tolua_set_DoerAbilData_lingQiao(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lingQiao'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->lingQiao = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tiPo of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_tiPo
static int tolua_get_DoerAbilData_tiPo(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tiPo'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->tiPo,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tiPo of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_tiPo
static int tolua_set_DoerAbilData_tiPo(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tiPo'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tiPo = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: neiXi of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_neiXi
static int tolua_get_DoerAbilData_neiXi(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'neiXi'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->neiXi,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: neiXi of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_neiXi
static int tolua_set_DoerAbilData_neiXi(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'neiXi'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->neiXi = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: gangQi of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_gangQi
static int tolua_get_DoerAbilData_gangQi(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gangQi'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->gangQi,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: gangQi of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_gangQi
static int tolua_set_DoerAbilData_gangQi(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gangQi'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->gangQi = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: waiGong of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_waiGong
static int tolua_get_DoerAbilData_waiGong(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'waiGong'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->waiGong,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: waiGong of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_waiGong
static int tolua_set_DoerAbilData_waiGong(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'waiGong'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->waiGong = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: neiGong of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_neiGong
static int tolua_get_DoerAbilData_neiGong(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'neiGong'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->neiGong,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: neiGong of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_neiGong
static int tolua_set_DoerAbilData_neiGong(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'neiGong'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->neiGong = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: waiFang of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_waiFang
static int tolua_get_DoerAbilData_waiFang(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'waiFang'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->waiFang,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: waiFang of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_waiFang
static int tolua_set_DoerAbilData_waiFang(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'waiFang'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->waiFang = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: neiFang of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_neiFang
static int tolua_get_DoerAbilData_neiFang(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'neiFang'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->neiFang,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: neiFang of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_neiFang
static int tolua_set_DoerAbilData_neiFang(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'neiFang'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->neiFang = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: waiFangCT of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_waiFangCT
static int tolua_get_DoerAbilData_waiFangCT(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'waiFangCT'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->waiFangCT,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: waiFangCT of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_waiFangCT
static int tolua_set_DoerAbilData_waiFangCT(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'waiFangCT'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->waiFangCT = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: neiFangCT of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_neiFangCT
static int tolua_get_DoerAbilData_neiFangCT(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'neiFangCT'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->neiFangCT,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: neiFangCT of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_neiFangCT
static int tolua_set_DoerAbilData_neiFangCT(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'neiFangCT'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->neiFangCT = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: qiXue of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_qiXue
static int tolua_get_DoerAbilData_qiXue(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'qiXue'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->qiXue,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: qiXue of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_qiXue
static int tolua_set_DoerAbilData_qiXue(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'qiXue'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->qiXue = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: neiLi of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_neiLi
static int tolua_get_DoerAbilData_neiLi(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'neiLi'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->neiLi,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: neiLi of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_neiLi
static int tolua_set_DoerAbilData_neiLi(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'neiLi'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->neiLi = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: waiBao of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_waiBao
static int tolua_get_DoerAbilData_waiBao(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'waiBao'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->waiBao,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: waiBao of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_waiBao
static int tolua_set_DoerAbilData_waiBao(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'waiBao'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->waiBao = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: neiBao of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_neiBao
static int tolua_get_DoerAbilData_neiBao(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'neiBao'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->neiBao,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: neiBao of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_neiBao
static int tolua_set_DoerAbilData_neiBao(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'neiBao'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->neiBao = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: kangWaiBao of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_kangWaiBao
static int tolua_get_DoerAbilData_kangWaiBao(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'kangWaiBao'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->kangWaiBao,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: kangWaiBao of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_kangWaiBao
static int tolua_set_DoerAbilData_kangWaiBao(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'kangWaiBao'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->kangWaiBao = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: kangNeiBao of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_kangNeiBao
static int tolua_get_DoerAbilData_kangNeiBao(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'kangNeiBao'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->kangNeiBao,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: kangNeiBao of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_kangNeiBao
static int tolua_set_DoerAbilData_kangNeiBao(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'kangNeiBao'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->kangNeiBao = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mingZhong of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_mingZhong
static int tolua_get_DoerAbilData_mingZhong(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mingZhong'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mingZhong,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mingZhong of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_mingZhong
static int tolua_set_DoerAbilData_mingZhong(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mingZhong'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mingZhong = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: shanBi of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_shanBi
static int tolua_get_DoerAbilData_shanBi(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'shanBi'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->shanBi,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: shanBi of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_shanBi
static int tolua_set_DoerAbilData_shanBi(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'shanBi'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->shanBi = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: hitSpeed of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_hitSpeed
static int tolua_get_DoerAbilData_hitSpeed(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hitSpeed'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->hitSpeed,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: hitSpeed of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_hitSpeed
static int tolua_set_DoerAbilData_hitSpeed(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hitSpeed'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->hitSpeed = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: moveSpeed of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_moveSpeed
static int tolua_get_DoerAbilData_moveSpeed(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'moveSpeed'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->moveSpeed,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: moveSpeed of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_moveSpeed
static int tolua_set_DoerAbilData_moveSpeed(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'moveSpeed'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->moveSpeed = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: qiXueHuiFu of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_qiXueHuiFu
static int tolua_get_DoerAbilData_qiXueHuiFu(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'qiXueHuiFu'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->qiXueHuiFu,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: qiXueHuiFu of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_qiXueHuiFu
static int tolua_set_DoerAbilData_qiXueHuiFu(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'qiXueHuiFu'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->qiXueHuiFu = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: neiLiHuiFu of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_neiLiHuiFu
static int tolua_get_DoerAbilData_neiLiHuiFu(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'neiLiHuiFu'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->neiLiHuiFu,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: neiLiHuiFu of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_neiLiHuiFu
static int tolua_set_DoerAbilData_neiLiHuiFu(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'neiLiHuiFu'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->neiLiHuiFu = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fuYuan of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_get_DoerAbilData_fuYuan
static int tolua_get_DoerAbilData_fuYuan(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fuYuan'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->fuYuan,"AttributeValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: fuYuan of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_set_DoerAbilData_fuYuan
static int tolua_set_DoerAbilData_fuYuan(lua_State* tolua_S)
{
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fuYuan'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AttributeValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->fuYuan = *((AttributeValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_DoerAbilData_new00
static int tolua_serverLuaInterface_DoerAbilData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DoerAbilData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   DoerAbilData* tolua_ret = (DoerAbilData*)  Mtolua_new((DoerAbilData)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"DoerAbilData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_DoerAbilData_new00_local
static int tolua_serverLuaInterface_DoerAbilData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DoerAbilData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   DoerAbilData* tolua_ret = (DoerAbilData*)  Mtolua_new((DoerAbilData)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"DoerAbilData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reset of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_DoerAbilData_reset00
static int tolua_serverLuaInterface_DoerAbilData_reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DoerAbilData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reset'", NULL);
#endif
  {
   self->reset();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: calculateItemAttribute of class  DoerAbilData */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_DoerAbilData_calculateItemAttribute00
static int tolua_serverLuaInterface_DoerAbilData_calculateItemAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DoerAbilData",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const ItemAttributeGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DoerAbilData* self = (DoerAbilData*)  tolua_tousertype(tolua_S,1,0);
  const ItemAttributeGroup* itemAttr = ((const ItemAttributeGroup*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'calculateItemAttribute'", NULL);
#endif
  {
   self->calculateItemAttribute(itemAttr);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'calculateItemAttribute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoer_new00
static int tolua_serverLuaInterface_CDoer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CDoer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CDoer* tolua_ret = (CDoer*)  Mtolua_new((CDoer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CDoer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoer_new00_local
static int tolua_serverLuaInterface_CDoer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CDoer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CDoer* tolua_ret = (CDoer*)  Mtolua_new((CDoer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CDoer");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoer_delete00
static int tolua_serverLuaInterface_CDoer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: run of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoer_run00
static int tolua_serverLuaInterface_CDoer_run00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
  TickTime dwCurrTick = *((TickTime*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'run'", NULL);
#endif
  {
   self->run(dwCurrTick);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'run'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initialize of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoer_initialize00
static int tolua_serverLuaInterface_CDoer_initialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initialize'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initialize();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: disappear of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoer_disappear00
static int tolua_serverLuaInterface_CDoer_disappear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disappear'", NULL);
#endif
  {
   self->disappear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'disappear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setViewArea of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoer_setViewArea00
static int tolua_serverLuaInterface_CDoer_setViewArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
  int val = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setViewArea'", NULL);
#endif
  {
   self->setViewArea(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setViewArea'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewIndex of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoer_getViewIndex00
static int tolua_serverLuaInterface_CDoer_getViewIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CEntity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
  CEntity* pEntity = ((CEntity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewIndex'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getViewIndex(pEntity);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getModule of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoer_getModule00
static int tolua_serverLuaInterface_CDoer_getModule00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
  const int nSysId = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getModule'", NULL);
#endif
  {
   CDoerUnit* tolua_ret = (CDoerUnit*)  self->getModule(nSysId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CDoerUnit");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getModule'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendMsg of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoer_sendMsg00
static int tolua_serverLuaInterface_CDoer_sendMsg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"INT_PTR",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"INT_PTR",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"INT_PTR",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"INT_PTR",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
  int ident = ((int)  tolua_tonumber(tolua_S,2,0));
  int sysId = ((int)  tolua_tonumber(tolua_S,3,0));
  INT_PTR p1 = *((INT_PTR*)  tolua_tousertype(tolua_S,4,0));
  INT_PTR p2 = *((INT_PTR*)  tolua_tousertype(tolua_S,5,0));
  INT_PTR p3 = *((INT_PTR*)  tolua_tousertype(tolua_S,6,0));
  INT_PTR p4 = *((INT_PTR*)  tolua_tousertype(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendMsg'", NULL);
#endif
  {
   self->sendMsg(ident,sysId,p1,p2,p3,p4);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendMsg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: broadcastMsg of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoer_broadcastMsg00
static int tolua_serverLuaInterface_CDoer_broadcastMsg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"INT_PTR",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"INT_PTR",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"INT_PTR",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"INT_PTR",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
  int ident = ((int)  tolua_tonumber(tolua_S,2,0));
  int sysId = ((int)  tolua_tonumber(tolua_S,3,0));
  INT_PTR p1 = *((INT_PTR*)  tolua_tousertype(tolua_S,4,0));
  INT_PTR p2 = *((INT_PTR*)  tolua_tousertype(tolua_S,5,0));
  INT_PTR p3 = *((INT_PTR*)  tolua_tousertype(tolua_S,6,0));
  INT_PTR p4 = *((INT_PTR*)  tolua_tousertype(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'broadcastMsg'", NULL);
#endif
  {
   self->broadcastMsg(ident,sysId,p1,p2,p3,p4);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'broadcastMsg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: broadcastPlayerMsg of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoer_broadcastPlayerMsg00
static int tolua_serverLuaInterface_CDoer_broadcastPlayerMsg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"INT_PTR",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"INT_PTR",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"INT_PTR",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"INT_PTR",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
  int ident = ((int)  tolua_tonumber(tolua_S,2,0));
  int sysId = ((int)  tolua_tonumber(tolua_S,3,0));
  INT_PTR p1 = *((INT_PTR*)  tolua_tousertype(tolua_S,4,0));
  INT_PTR p2 = *((INT_PTR*)  tolua_tousertype(tolua_S,5,0));
  INT_PTR p3 = *((INT_PTR*)  tolua_tousertype(tolua_S,6,0));
  INT_PTR p4 = *((INT_PTR*)  tolua_tousertype(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'broadcastPlayerMsg'", NULL);
#endif
  {
   self->broadcastPlayerMsg(ident,sysId,p1,p2,p3,p4);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'broadcastPlayerMsg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: gainExp of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoer_gainExp00
static int tolua_serverLuaInterface_CDoer_gainExp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
  int exp = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'gainExp'", NULL);
#endif
  {
   self->gainExp(exp);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'gainExp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: winExp of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoer_winExp00
static int tolua_serverLuaInterface_CDoer_winExp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
  int exp = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'winExp'", NULL);
#endif
  {
   self->winExp(exp);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'winExp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_sName of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_m_sName
static int tolua_get_CDoer_m_sName(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_sName'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->m_sName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_sName of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_m_sName
static int tolua_set_CDoer_m_sName(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_sName'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->m_sName,(const char*)tolua_tostring(tolua_S,2,0),48-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nLevel of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_m_nLevel
static int tolua_get_CDoer_m_nLevel(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nLevel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nLevel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nLevel of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_m_nLevel
static int tolua_set_CDoer_m_nLevel(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nLevel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nLevel = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_btAttackType of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_unsigned_m_btAttackType
static int tolua_get_CDoer_unsigned_m_btAttackType(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btAttackType'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_btAttackType);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_btAttackType of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_unsigned_m_btAttackType
static int tolua_set_CDoer_unsigned_m_btAttackType(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btAttackType'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_btAttackType = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_btVipLevel of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_unsigned_m_btVipLevel
static int tolua_get_CDoer_unsigned_m_btVipLevel(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btVipLevel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_btVipLevel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_btVipLevel of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_unsigned_m_btVipLevel
static int tolua_set_CDoer_unsigned_m_btVipLevel(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btVipLevel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_btVipLevel = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_wMonId of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_unsigned_m_wMonId
static int tolua_get_CDoer_unsigned_m_wMonId(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wMonId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_wMonId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_wMonId of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_unsigned_m_wMonId
static int tolua_set_CDoer_unsigned_m_wMonId(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wMonId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_wMonId = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nExp of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_m_nExp
static int tolua_get_CDoer_m_nExp(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nExp'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nExp);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nExp of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_m_nExp
static int tolua_set_CDoer_m_nExp(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nExp'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nExp = ((long long)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nExpMax of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_m_nExpMax
static int tolua_get_CDoer_m_nExpMax(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nExpMax'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nExpMax);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nExpMax of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_m_nExpMax
static int tolua_set_CDoer_m_nExpMax(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nExpMax'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nExpMax = ((long long)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nMonExp of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_m_nMonExp
static int tolua_get_CDoer_m_nMonExp(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nMonExp'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nMonExp);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nMonExp of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_m_nMonExp
static int tolua_set_CDoer_m_nMonExp(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nMonExp'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nMonExp = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_wMoveSpeed of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_unsigned_m_wMoveSpeed
static int tolua_get_CDoer_unsigned_m_wMoveSpeed(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wMoveSpeed'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_wMoveSpeed);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_wMoveSpeed of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_unsigned_m_wMoveSpeed
static int tolua_set_CDoer_unsigned_m_wMoveSpeed(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wMoveSpeed'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_wMoveSpeed = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_wAttackInterval of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_unsigned_m_wAttackInterval
static int tolua_get_CDoer_unsigned_m_wAttackInterval(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wAttackInterval'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_wAttackInterval);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_wAttackInterval of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_unsigned_m_wAttackInterval
static int tolua_set_CDoer_unsigned_m_wAttackInterval(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wAttackInterval'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_wAttackInterval = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_wAttackTime of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_unsigned_m_wAttackTime
static int tolua_get_CDoer_unsigned_m_wAttackTime(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wAttackTime'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_wAttackTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_wAttackTime of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_unsigned_m_wAttackTime
static int tolua_set_CDoer_unsigned_m_wAttackTime(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_wAttackTime'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_wAttackTime = ((unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _____reserve of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_unsigned______reserve
static int tolua_get_CDoer_unsigned______reserve(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_____reserve'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->_____reserve);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _____reserve of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_unsigned______reserve
static int tolua_set_CDoer_unsigned______reserve(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_____reserve'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->_____reserve,(const char*)tolua_tostring(tolua_S,2,0),2-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nBornX of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_m_nBornX
static int tolua_get_CDoer_m_nBornX(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nBornX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nBornX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nBornX of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_m_nBornX
static int tolua_set_CDoer_m_nBornX(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nBornX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nBornX = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nBornY of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_m_nBornY
static int tolua_get_CDoer_m_nBornY(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nBornY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nBornY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nBornY of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_m_nBornY
static int tolua_set_CDoer_m_nBornY(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nBornY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nBornY = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_Abil of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_m_Abil
static int tolua_get_CDoer_m_Abil(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Abil'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_Abil,"CDoerAbility");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_Abil of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_m_Abil
static int tolua_set_CDoer_m_Abil(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Abil'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDoerAbility",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_Abil = *((CDoerAbility*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_Battle of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_m_Battle
static int tolua_get_CDoer_m_Battle(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Battle'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_Battle,"CDoerBattle");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_Battle of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_m_Battle
static int tolua_set_CDoer_m_Battle(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Battle'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDoerBattle",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_Battle = *((CDoerBattle*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_ViewList of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_m_ViewList
static int tolua_get_CDoer_m_ViewList(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_ViewList'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_ViewList,"CBList<CEntity::ViewStruct>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_ViewList of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_m_ViewList
static int tolua_set_CDoer_m_ViewList(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_ViewList'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CBList<CEntity::ViewStruct>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_ViewList = *((CBList<CEntity::ViewStruct>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pFirstMsg of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_m_pFirstMsg_ptr
static int tolua_get_CDoer_m_pFirstMsg_ptr(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pFirstMsg'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pFirstMsg,"DoerMsg");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pFirstMsg of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_m_pFirstMsg_ptr
static int tolua_set_CDoer_m_pFirstMsg_ptr(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pFirstMsg'",NULL);
  if (!tolua_isusertype(tolua_S,2,"DoerMsg",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pFirstMsg = ((DoerMsg*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pLastMsg of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_m_pLastMsg_ptr
static int tolua_get_CDoer_m_pLastMsg_ptr(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pLastMsg'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pLastMsg,"DoerMsg");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pLastMsg of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_m_pLastMsg_ptr
static int tolua_set_CDoer_m_pLastMsg_ptr(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pLastMsg'",NULL);
  if (!tolua_isusertype(tolua_S,2,"DoerMsg",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pLastMsg = ((DoerMsg*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_dwNextUpdateViewTime of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_m_dwNextUpdateViewTime
static int tolua_get_CDoer_m_dwNextUpdateViewTime(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwNextUpdateViewTime'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_dwNextUpdateViewTime,"TickTime");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_dwNextUpdateViewTime of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_m_dwNextUpdateViewTime
static int tolua_set_CDoer_m_dwNextUpdateViewTime(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwNextUpdateViewTime'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_dwNextUpdateViewTime = *((TickTime*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_dwLastRunTick of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_get_CDoer_m_dwLastRunTick
static int tolua_get_CDoer_m_dwLastRunTick(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwLastRunTick'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_dwLastRunTick,"TickTime");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_dwLastRunTick of class  CDoer */
#ifndef TOLUA_DISABLE_tolua_set_CDoer_m_dwLastRunTick
static int tolua_set_CDoer_m_dwLastRunTick(lua_State* tolua_S)
{
  CDoer* self = (CDoer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwLastRunTick'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_dwLastRunTick = *((TickTime*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_new00
static int tolua_serverLuaInterface_CPlayerWeapon_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CPlayerWeapon* tolua_ret = (CPlayerWeapon*)  Mtolua_new((CPlayerWeapon)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CPlayerWeapon");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_new00_local
static int tolua_serverLuaInterface_CPlayerWeapon_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CPlayerWeapon* tolua_ret = (CPlayerWeapon*)  Mtolua_new((CPlayerWeapon)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CPlayerWeapon");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_delete00
static int tolua_serverLuaInterface_CPlayerWeapon_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_init00
static int tolua_serverLuaInterface_CPlayerWeapon_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadData of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_loadData00
static int tolua_serverLuaInterface_CPlayerWeapon_loadData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDataPacketReader",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
  CDataPacketReader* data = ((CDataPacketReader*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadData'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->loadData(*data);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: saveData of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_saveData00
static int tolua_serverLuaInterface_CPlayerWeapon_saveData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDataPacket",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
  CDataPacket* data = ((CDataPacket*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'saveData'", NULL);
#endif
  {
   self->saveData(*data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dispatchRecvPacket of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_dispatchRecvPacket00
static int tolua_serverLuaInterface_CPlayerWeapon_dispatchRecvPacket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CDataPacketReader",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
  int btCmd = ((int)  tolua_tonumber(tolua_S,2,0));
  CDataPacketReader* inPacket = ((CDataPacketReader*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dispatchRecvPacket'", NULL);
#endif
  {
   self->dispatchRecvPacket(btCmd,*inPacket);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dispatchRecvPacket'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dispatchMsg of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_dispatchMsg00
static int tolua_serverLuaInterface_CPlayerWeapon_dispatchMsg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"DoerMsg",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
  DoerMsg* msg = ((DoerMsg*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dispatchMsg'", NULL);
#endif
  {
   self->dispatchMsg(msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dispatchMsg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: offline of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_offline00
static int tolua_serverLuaInterface_CPlayerWeapon_offline00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'offline'", NULL);
#endif
  {
   self->offline();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'offline'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addBead of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_addBead00
static int tolua_serverLuaInterface_CPlayerWeapon_addBead00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
  unsigned short beadId = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
  unsigned char level = ((unsigned char)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addBead'", NULL);
#endif
  {
   self->addBead(beadId,level);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addBead'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delBead of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_delBead00
static int tolua_serverLuaInterface_CPlayerWeapon_delBead00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"BeadSeries",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
  BeadSeries serires = *((BeadSeries*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delBead'", NULL);
#endif
  {
   self->delBead(serires);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delBead'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: findBead of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_findBead00
static int tolua_serverLuaInterface_CPlayerWeapon_findBead00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"BeadSeries",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
  BeadSeries serires = *((BeadSeries*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'findBead'", NULL);
#endif
  {
   Bead* tolua_ret = (Bead*)  self->findBead(serires);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Bead");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'findBead'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearWeaponInfo of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_clearWeaponInfo00
static int tolua_serverLuaInterface_CPlayerWeapon_clearWeaponInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearWeaponInfo'", NULL);
#endif
  {
   self->clearWeaponInfo();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearWeaponInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearBeadList of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_clearBeadList00
static int tolua_serverLuaInterface_CPlayerWeapon_clearBeadList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearBeadList'", NULL);
#endif
  {
   self->clearBeadList();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearBeadList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendWeaponFullInfo of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_sendWeaponFullInfo00
static int tolua_serverLuaInterface_CPlayerWeapon_sendWeaponFullInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendWeaponFullInfo'", NULL);
#endif
  {
   self->sendWeaponFullInfo();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendWeaponFullInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendWeaponInfo of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_sendWeaponInfo00
static int tolua_serverLuaInterface_CPlayerWeapon_sendWeaponInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendWeaponInfo'", NULL);
#endif
  {
   self->sendWeaponInfo();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendWeaponInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendAddBead of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_sendAddBead00
static int tolua_serverLuaInterface_CPlayerWeapon_sendAddBead00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Bead",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
  Bead* pBead = ((Bead*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendAddBead'", NULL);
#endif
  {
   self->sendAddBead(pBead);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendAddBead'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendDelBead of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_sendDelBead00
static int tolua_serverLuaInterface_CPlayerWeapon_sendDelBead00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"BeadSeries",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
  BeadSeries series = *((BeadSeries*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendDelBead'", NULL);
#endif
  {
   self->sendDelBead(series);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendDelBead'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendBeadEat of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_sendBeadEat00
static int tolua_serverLuaInterface_CPlayerWeapon_sendBeadEat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Bead",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"std::vector<BeadSeries>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
  Bead* pMainBead = ((Bead*)  tolua_tousertype(tolua_S,2,0));
  std::vector<BeadSeries> attachSerieses = *((std::vector<BeadSeries>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendBeadEat'", NULL);
#endif
  {
   self->sendBeadEat(pMainBead,attachSerieses);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendBeadEat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendWeaponOperateRes of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerWeapon_sendWeaponOperateRes00
static int tolua_serverLuaInterface_CPlayerWeapon_sendWeaponOperateRes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerWeapon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
  unsigned char op = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
  unsigned char res = ((unsigned char)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendWeaponOperateRes'", NULL);
#endif
  {
   self->sendWeaponOperateRes(op,res);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendWeaponOperateRes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_Weapon of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_get_CPlayerWeapon_m_Weapon
static int tolua_get_CPlayerWeapon_m_Weapon(lua_State* tolua_S)
{
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Weapon'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_Weapon,"Weapon");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_Weapon of class  CPlayerWeapon */
#ifndef TOLUA_DISABLE_tolua_set_CPlayerWeapon_m_Weapon
static int tolua_set_CPlayerWeapon_m_Weapon(lua_State* tolua_S)
{
  CPlayerWeapon* self = (CPlayerWeapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Weapon'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Weapon",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_Weapon = *((Weapon*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_new00
static int tolua_serverLuaInterface_CPlayer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CPlayer* tolua_ret = (CPlayer*)  Mtolua_new((CPlayer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CPlayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_new00_local
static int tolua_serverLuaInterface_CPlayer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CPlayer* tolua_ret = (CPlayer*)  Mtolua_new((CPlayer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CPlayer");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_delete00
static int tolua_serverLuaInterface_CPlayer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: run of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_run00
static int tolua_serverLuaInterface_CPlayer_run00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
  TickTime dwCurrTick = *((TickTime*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'run'", NULL);
#endif
  {
   self->run(dwCurrTick);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'run'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initialize of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_initialize00
static int tolua_serverLuaInterface_CPlayer_initialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initialize'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initialize();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIdentity of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_setIdentity00
static int tolua_serverLuaInterface_CPlayer_setIdentity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"EnterGameStruct",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
  EnterGameStruct* pEnterStruct = ((EnterGameStruct*)  tolua_tousertype(tolua_S,2,0));
  bool boIsNewPlayer = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIdentity'", NULL);
#endif
  {
   self->setIdentity(pEnterStruct,boIsNewPlayer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadData of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_loadData00
static int tolua_serverLuaInterface_CPlayer_loadData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDataPacketReader",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
  CDataPacketReader* data = ((CDataPacketReader*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadData'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->loadData(*data);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: saveData of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_saveData00
static int tolua_serverLuaInterface_CPlayer_saveData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDataPacket",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
  CDataPacket* data = ((CDataPacket*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'saveData'", NULL);
#endif
  {
   self->saveData(*data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: close of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_close00
static int tolua_serverLuaInterface_CPlayer_close00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
  bool boRemoteClose = ((bool)  tolua_toboolean(tolua_S,2,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'close'", NULL);
#endif
  {
   self->close(boRemoteClose);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'close'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readyForRun of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_readyForRun00
static int tolua_serverLuaInterface_CPlayer_readyForRun00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readyForRun'", NULL);
#endif
  {
   self->readyForRun();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readyForRun'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendSceneInfo of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_sendSceneInfo00
static int tolua_serverLuaInterface_CPlayer_sendSceneInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendSceneInfo'", NULL);
#endif
  {
   self->sendSceneInfo();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendSceneInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendCoinCount of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_sendCoinCount00
static int tolua_serverLuaInterface_CPlayer_sendCoinCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendCoinCount'", NULL);
#endif
  {
   self->sendCoinCount();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendCoinCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendGameGoldCount of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_sendGameGoldCount00
static int tolua_serverLuaInterface_CPlayer_sendGameGoldCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendGameGoldCount'", NULL);
#endif
  {
   self->sendGameGoldCount();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendGameGoldCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendEntityAppear of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_sendEntityAppear00
static int tolua_serverLuaInterface_CPlayer_sendEntityAppear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CEntity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
  CEntity* pEntity = ((CEntity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendEntityAppear'", NULL);
#endif
  {
   self->sendEntityAppear(pEntity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendEntityAppear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getModule of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_getModule00
static int tolua_serverLuaInterface_CPlayer_getModule00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const int nSysId = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getModule'", NULL);
#endif
  {
   CDoerUnit* tolua_ret = (CDoerUnit*)  self->getModule(nSysId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CDoerUnit");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getModule'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: allocSendPacket of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_allocSendPacket00
static int tolua_serverLuaInterface_CPlayer_allocSendPacket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'allocSendPacket'", NULL);
#endif
  {
   CGateSendPacket& tolua_ret = (CGateSendPacket&)  self->allocSendPacket();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"CGateSendPacket");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'allocSendPacket'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: gotoBornScene of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_gotoBornScene00
static int tolua_serverLuaInterface_CPlayer_gotoBornScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'gotoBornScene'", NULL);
#endif
  {
   self->gotoBornScene();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'gotoBornScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addCoin of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_addCoin00
static int tolua_serverLuaInterface_CPlayer_addCoin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
  int count = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addCoin'", NULL);
#endif
  {
   self->addCoin(count);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addCoin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: decCoin of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayer_decCoin00
static int tolua_serverLuaInterface_CPlayer_decCoin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
  int count = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'decCoin'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->decCoin(count);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'decCoin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nPlayerIndex of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_nPlayerIndex
static int tolua_get_CPlayer_m_nPlayerIndex(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nPlayerIndex'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nPlayerIndex);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nPlayerIndex of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_nPlayerIndex
static int tolua_set_CPlayer_m_nPlayerIndex(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nPlayerIndex'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nPlayerIndex = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_sAccount of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_sAccount
static int tolua_get_CPlayer_m_sAccount(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_sAccount'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->m_sAccount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_sAccount of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_sAccount
static int tolua_set_CPlayer_m_sAccount(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_sAccount'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->m_sAccount,(const char*)tolua_tostring(tolua_S,2,0),64-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nAccountId of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_nAccountId
static int tolua_get_CPlayer_m_nAccountId(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nAccountId'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_nAccountId,"uint32");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nAccountId of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_nAccountId
static int tolua_set_CPlayer_m_nAccountId(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nAccountId'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint32",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nAccountId = *((uint32*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nCreateTime of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_nCreateTime
static int tolua_get_CPlayer_m_nCreateTime(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nCreateTime'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_nCreateTime,"uint64");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nCreateTime of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_nCreateTime
static int tolua_set_CPlayer_m_nCreateTime(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nCreateTime'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"uint64",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nCreateTime = *((uint64*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pGate of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_pGate_ptr
static int tolua_get_CPlayer_m_pGate_ptr(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pGate'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pGate,"CLogicGate");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pGate of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_pGate_ptr
static int tolua_set_CPlayer_m_pGate_ptr(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pGate'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CLogicGate",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pGate = ((CLogicGate*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_llSocket of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_llSocket
static int tolua_get_CPlayer_m_llSocket(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_llSocket'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_llSocket);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_llSocket of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_llSocket
static int tolua_set_CPlayer_m_llSocket(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_llSocket'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_llSocket = ((long long)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nGateIndex of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_nGateIndex
static int tolua_get_CPlayer_m_nGateIndex(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nGateIndex'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nGateIndex);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nGateIndex of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_nGateIndex
static int tolua_set_CPlayer_m_nGateIndex(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nGateIndex'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nGateIndex = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nGateUserIndex of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_nGateUserIndex
static int tolua_get_CPlayer_m_nGateUserIndex(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nGateUserIndex'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nGateUserIndex);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nGateUserIndex of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_nGateUserIndex
static int tolua_set_CPlayer_m_nGateUserIndex(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nGateUserIndex'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nGateUserIndex = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nGateVerify of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_nGateVerify
static int tolua_get_CPlayer_m_nGateVerify(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nGateVerify'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nGateVerify);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nGateVerify of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_nGateVerify
static int tolua_set_CPlayer_m_nGateVerify(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nGateVerify'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nGateVerify = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nClientAddr of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_nClientAddr
static int tolua_get_CPlayer_m_nClientAddr(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nClientAddr'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nClientAddr);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nClientAddr of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_nClientAddr
static int tolua_set_CPlayer_m_nClientAddr(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nClientAddr'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nClientAddr = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_dwEnterTick of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_dwEnterTick
static int tolua_get_CPlayer_m_dwEnterTick(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwEnterTick'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_dwEnterTick,"TickTime");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_dwEnterTick of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_dwEnterTick
static int tolua_set_CPlayer_m_dwEnterTick(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwEnterTick'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_dwEnterTick = *((TickTime*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nEnterGameTime of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_nEnterGameTime
static int tolua_get_CPlayer_m_nEnterGameTime(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nEnterGameTime'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nEnterGameTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nEnterGameTime of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_nEnterGameTime
static int tolua_set_CPlayer_m_nEnterGameTime(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nEnterGameTime'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nEnterGameTime = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_dwClosedTick of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_dwClosedTick
static int tolua_get_CPlayer_m_dwClosedTick(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwClosedTick'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_dwClosedTick,"TickTime");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_dwClosedTick of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_dwClosedTick
static int tolua_set_CPlayer_m_dwClosedTick(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwClosedTick'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_dwClosedTick = *((TickTime*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_dwInvalidTick of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_dwInvalidTick
static int tolua_get_CPlayer_m_dwInvalidTick(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwInvalidTick'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_dwInvalidTick,"TickTime");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_dwInvalidTick of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_dwInvalidTick
static int tolua_set_CPlayer_m_dwInvalidTick(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwInvalidTick'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_dwInvalidTick = *((TickTime*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_dwNextSaveDataTick of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_dwNextSaveDataTick
static int tolua_get_CPlayer_m_dwNextSaveDataTick(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwNextSaveDataTick'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_dwNextSaveDataTick,"TickTime");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_dwNextSaveDataTick of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_dwNextSaveDataTick
static int tolua_set_CPlayer_m_dwNextSaveDataTick(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwNextSaveDataTick'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_dwNextSaveDataTick = *((TickTime*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_boValid of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_boValid
static int tolua_get_CPlayer_m_boValid(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_boValid'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->m_boValid);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_boValid of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_boValid
static int tolua_set_CPlayer_m_boValid(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_boValid'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_boValid = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _____________reserve0 of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer______________reserve0
static int tolua_get_CPlayer______________reserve0(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_____________reserve0'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->_____________reserve0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _____________reserve0 of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer______________reserve0
static int tolua_set_CPlayer______________reserve0(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_____________reserve0'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->_____________reserve0,(const char*)tolua_tostring(tolua_S,2,0),3-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_boIsNewPlayer of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_boIsNewPlayer
static int tolua_get_CPlayer_m_boIsNewPlayer(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_boIsNewPlayer'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->m_boIsNewPlayer);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_boIsNewPlayer of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_boIsNewPlayer
static int tolua_set_CPlayer_m_boIsNewPlayer(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_boIsNewPlayer'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_boIsNewPlayer = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_btGender of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_unsigned_m_btGender
static int tolua_get_CPlayer_unsigned_m_btGender(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btGender'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_btGender);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_btGender of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_unsigned_m_btGender
static int tolua_set_CPlayer_unsigned_m_btGender(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btGender'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_btGender = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_btJob of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_unsigned_m_btJob
static int tolua_get_CPlayer_unsigned_m_btJob(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btJob'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_btJob);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_btJob of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_unsigned_m_btJob
static int tolua_set_CPlayer_unsigned_m_btJob(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btJob'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_btJob = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_btGMLevel of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_unsigned_m_btGMLevel
static int tolua_get_CPlayer_unsigned_m_btGMLevel(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btGMLevel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_btGMLevel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_btGMLevel of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_unsigned_m_btGMLevel
static int tolua_set_CPlayer_unsigned_m_btGMLevel(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btGMLevel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_btGMLevel = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_GuildId of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_GuildId
static int tolua_get_CPlayer_m_GuildId(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_GuildId'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_GuildId,"GuildId");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_GuildId of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_GuildId
static int tolua_set_CPlayer_m_GuildId(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_GuildId'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GuildId",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_GuildId = *((GuildId*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pGuild of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_pGuild_ptr
static int tolua_get_CPlayer_m_pGuild_ptr(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pGuild'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pGuild,"CGuild");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pGuild of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_pGuild_ptr
static int tolua_set_CPlayer_m_pGuild_ptr(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pGuild'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CGuild",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pGuild = ((CGuild*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nCoin of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_nCoin
static int tolua_get_CPlayer_m_nCoin(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nCoin'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nCoin);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nCoin of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_nCoin
static int tolua_set_CPlayer_m_nCoin(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nCoin'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nCoin = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nGameGold of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_nGameGold
static int tolua_get_CPlayer_m_nGameGold(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nGameGold'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nGameGold);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nGameGold of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_nGameGold
static int tolua_set_CPlayer_m_nGameGold(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nGameGold'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nGameGold = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_DearId of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_DearId
static int tolua_get_CPlayer_m_DearId(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_DearId'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_DearId,"PlayerId");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_DearId of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_DearId
static int tolua_set_CPlayer_m_DearId(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_DearId'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"PlayerId",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_DearId = *((PlayerId*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_sDearName of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_sDearName
static int tolua_get_CPlayer_m_sDearName(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_sDearName'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->m_sDearName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_sDearName of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_sDearName
static int tolua_set_CPlayer_m_sDearName(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_sDearName'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->m_sDearName,(const char*)tolua_tostring(tolua_S,2,0),48-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_Bag of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_Bag
static int tolua_get_CPlayer_m_Bag(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Bag'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_Bag,"CPlayerBag");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_Bag of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_Bag
static int tolua_set_CPlayer_m_Bag(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Bag'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CPlayerBag",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_Bag = *((CPlayerBag*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_Equip of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_Equip
static int tolua_get_CPlayer_m_Equip(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Equip'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_Equip,"CPlayerEquip");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_Equip of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_Equip
static int tolua_set_CPlayer_m_Equip(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Equip'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CPlayerEquip",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_Equip = *((CPlayerEquip*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_Quest of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_Quest
static int tolua_get_CPlayer_m_Quest(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Quest'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_Quest,"CPlayerQuest");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_Quest of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_Quest
static int tolua_set_CPlayer_m_Quest(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Quest'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CPlayerQuest",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_Quest = *((CPlayerQuest*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_NpcTalk of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_NpcTalk
static int tolua_get_CPlayer_m_NpcTalk(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_NpcTalk'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_NpcTalk,"CPlayerNpcTalk");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_NpcTalk of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_NpcTalk
static int tolua_set_CPlayer_m_NpcTalk(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_NpcTalk'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CPlayerNpcTalk",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_NpcTalk = *((CPlayerNpcTalk*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_playerChat of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_playerChat
static int tolua_get_CPlayer_m_playerChat(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_playerChat'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_playerChat,"CPlayerChat");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_playerChat of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_playerChat
static int tolua_set_CPlayer_m_playerChat(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_playerChat'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CPlayerChat",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_playerChat = *((CPlayerChat*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_team of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_team
static int tolua_get_CPlayer_m_team(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_team'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_team,"CPlayerTeam");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_team of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_team
static int tolua_set_CPlayer_m_team(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_team'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CPlayerTeam",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_team = *((CPlayerTeam*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_Weapon of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_Weapon
static int tolua_get_CPlayer_m_Weapon(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Weapon'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_Weapon,"CPlayerWeapon");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_Weapon of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_Weapon
static int tolua_set_CPlayer_m_Weapon(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_Weapon'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CPlayerWeapon",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_Weapon = *((CPlayerWeapon*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nNetMsgIndex of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_nNetMsgIndex
static int tolua_get_CPlayer_m_nNetMsgIndex(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nNetMsgIndex'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nNetMsgIndex);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nNetMsgIndex of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_nNetMsgIndex
static int tolua_set_CPlayer_m_nNetMsgIndex(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nNetMsgIndex'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nNetMsgIndex = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_StaticPosition of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_StaticPosition
static int tolua_get_CPlayer_m_StaticPosition(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_StaticPosition'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_StaticPosition,"EntityPosition");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_StaticPosition of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_StaticPosition
static int tolua_set_CPlayer_m_StaticPosition(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_StaticPosition'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"EntityPosition",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_StaticPosition = *((EntityPosition*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_DynamicPosition of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_get_CPlayer_m_DynamicPosition
static int tolua_get_CPlayer_m_DynamicPosition(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_DynamicPosition'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_DynamicPosition,"EntityPosition");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_DynamicPosition of class  CPlayer */
#ifndef TOLUA_DISABLE_tolua_set_CPlayer_m_DynamicPosition
static int tolua_set_CPlayer_m_DynamicPosition(lua_State* tolua_S)
{
  CPlayer* self = (CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_DynamicPosition'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"EntityPosition",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_DynamicPosition = *((EntityPosition*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CDoerUnit */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerUnit_new00
static int tolua_serverLuaInterface_CDoerUnit_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CDoerUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CDoerUnit* tolua_ret = (CDoerUnit*)  Mtolua_new((CDoerUnit)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CDoerUnit");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CDoerUnit */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerUnit_new00_local
static int tolua_serverLuaInterface_CDoerUnit_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CDoerUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CDoerUnit* tolua_ret = (CDoerUnit*)  Mtolua_new((CDoerUnit)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CDoerUnit");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CDoerUnit */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerUnit_delete00
static int tolua_serverLuaInterface_CDoerUnit_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerUnit* self = (CDoerUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CDoerUnit */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerUnit_init00
static int tolua_serverLuaInterface_CDoerUnit_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerUnit* self = (CDoerUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadData of class  CDoerUnit */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerUnit_loadData00
static int tolua_serverLuaInterface_CDoerUnit_loadData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerUnit",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDataPacketReader",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerUnit* self = (CDoerUnit*)  tolua_tousertype(tolua_S,1,0);
  CDataPacketReader* data = ((CDataPacketReader*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadData'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->loadData(*data);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: saveData of class  CDoerUnit */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerUnit_saveData00
static int tolua_serverLuaInterface_CDoerUnit_saveData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerUnit",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDataPacket",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerUnit* self = (CDoerUnit*)  tolua_tousertype(tolua_S,1,0);
  CDataPacket* data = ((CDataPacket*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'saveData'", NULL);
#endif
  {
   self->saveData(*data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dispatchRecvPacket of class  CDoerUnit */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerUnit_dispatchRecvPacket00
static int tolua_serverLuaInterface_CDoerUnit_dispatchRecvPacket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerUnit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CDataPacketReader",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerUnit* self = (CDoerUnit*)  tolua_tousertype(tolua_S,1,0);
  int btCmd = ((int)  tolua_tonumber(tolua_S,2,0));
  CDataPacketReader* inPacket = ((CDataPacketReader*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dispatchRecvPacket'", NULL);
#endif
  {
   self->dispatchRecvPacket(btCmd,*inPacket);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dispatchRecvPacket'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dispatchMsg of class  CDoerUnit */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerUnit_dispatchMsg00
static int tolua_serverLuaInterface_CDoerUnit_dispatchMsg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerUnit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"DoerMsg",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerUnit* self = (CDoerUnit*)  tolua_tousertype(tolua_S,1,0);
  DoerMsg* msg = ((DoerMsg*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dispatchMsg'", NULL);
#endif
  {
   self->dispatchMsg(msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dispatchMsg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: offline of class  CDoerUnit */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerUnit_offline00
static int tolua_serverLuaInterface_CDoerUnit_offline00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerUnit* self = (CDoerUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'offline'", NULL);
#endif
  {
   self->offline();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'offline'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pActor of class  CDoerUnit */
#ifndef TOLUA_DISABLE_tolua_get_CDoerUnit_m_pActor_ptr
static int tolua_get_CDoerUnit_m_pActor_ptr(lua_State* tolua_S)
{
  CDoerUnit* self = (CDoerUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pActor'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pActor,"CDoer");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pActor of class  CDoerUnit */
#ifndef TOLUA_DISABLE_tolua_set_CDoerUnit_m_pActor_ptr
static int tolua_set_CDoerUnit_m_pActor_ptr(lua_State* tolua_S)
{
  CDoerUnit* self = (CDoerUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pActor'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CDoer",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pActor = ((CDoer*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pPlayer of class  CDoerUnit */
#ifndef TOLUA_DISABLE_tolua_get_CDoerUnit_m_pPlayer_ptr
static int tolua_get_CDoerUnit_m_pPlayer_ptr(lua_State* tolua_S)
{
  CDoerUnit* self = (CDoerUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pPlayer'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pPlayer,"CPlayer");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pPlayer of class  CDoerUnit */
#ifndef TOLUA_DISABLE_tolua_set_CDoerUnit_m_pPlayer_ptr
static int tolua_set_CDoerUnit_m_pPlayer_ptr(lua_State* tolua_S)
{
  CDoerUnit* self = (CDoerUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pPlayer'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CPlayer",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pPlayer = ((CPlayer*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CPlayerTeam */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerTeam_new00
static int tolua_serverLuaInterface_CPlayerTeam_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayerTeam",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CPlayerTeam* tolua_ret = (CPlayerTeam*)  Mtolua_new((CPlayerTeam)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CPlayerTeam");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CPlayerTeam */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerTeam_new00_local
static int tolua_serverLuaInterface_CPlayerTeam_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayerTeam",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CPlayerTeam* tolua_ret = (CPlayerTeam*)  Mtolua_new((CPlayerTeam)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CPlayerTeam");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CPlayerTeam */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerTeam_delete00
static int tolua_serverLuaInterface_CPlayerTeam_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerTeam",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerTeam* self = (CPlayerTeam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CPlayerTeam */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerTeam_init00
static int tolua_serverLuaInterface_CPlayerTeam_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerTeam",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerTeam* self = (CPlayerTeam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dispatchRecvPacket of class  CPlayerTeam */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerTeam_dispatchRecvPacket00
static int tolua_serverLuaInterface_CPlayerTeam_dispatchRecvPacket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerTeam",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CDataPacketReader",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerTeam* self = (CPlayerTeam*)  tolua_tousertype(tolua_S,1,0);
  int btCmd = ((int)  tolua_tonumber(tolua_S,2,0));
  CDataPacketReader* inPacket = ((CDataPacketReader*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dispatchRecvPacket'", NULL);
#endif
  {
   self->dispatchRecvPacket(btCmd,*inPacket);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dispatchRecvPacket'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pTeam of class  CPlayerTeam */
#ifndef TOLUA_DISABLE_tolua_get_CPlayerTeam_m_pTeam_ptr
static int tolua_get_CPlayerTeam_m_pTeam_ptr(lua_State* tolua_S)
{
  CPlayerTeam* self = (CPlayerTeam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pTeam'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pTeam,"CTeam");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pTeam of class  CPlayerTeam */
#ifndef TOLUA_DISABLE_tolua_set_CPlayerTeam_m_pTeam_ptr
static int tolua_set_CPlayerTeam_m_pTeam_ptr(lua_State* tolua_S)
{
  CPlayerTeam* self = (CPlayerTeam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pTeam'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CTeam",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pTeam = ((CTeam*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_new00
static int tolua_serverLuaInterface_CPlayerQuest_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CPlayerQuest* tolua_ret = (CPlayerQuest*)  Mtolua_new((CPlayerQuest)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CPlayerQuest");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_new00_local
static int tolua_serverLuaInterface_CPlayerQuest_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CPlayerQuest* tolua_ret = (CPlayerQuest*)  Mtolua_new((CPlayerQuest)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CPlayerQuest");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_delete00
static int tolua_serverLuaInterface_CPlayerQuest_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_init00
static int tolua_serverLuaInterface_CPlayerQuest_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadData of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_loadData00
static int tolua_serverLuaInterface_CPlayerQuest_loadData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDataPacketReader",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  CDataPacketReader* data = ((CDataPacketReader*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadData'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->loadData(*data);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: saveData of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_saveData00
static int tolua_serverLuaInterface_CPlayerQuest_saveData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDataPacket",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  CDataPacket* data = ((CDataPacket*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'saveData'", NULL);
#endif
  {
   self->saveData(*data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dispatchRecvPacket of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_dispatchRecvPacket00
static int tolua_serverLuaInterface_CPlayerQuest_dispatchRecvPacket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CDataPacketReader",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  int btCmd = ((int)  tolua_tonumber(tolua_S,2,0));
  CDataPacketReader* inPacket = ((CDataPacketReader*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dispatchRecvPacket'", NULL);
#endif
  {
   self->dispatchRecvPacket(btCmd,*inPacket);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dispatchRecvPacket'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendQuestDatas of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_sendQuestDatas00
static int tolua_serverLuaInterface_CPlayerQuest_sendQuestDatas00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendQuestDatas'", NULL);
#endif
  {
   self->sendQuestDatas();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendQuestDatas'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendAddAcceptQuest of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_sendAddAcceptQuest00
static int tolua_serverLuaInterface_CPlayerQuest_sendAddAcceptQuest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PlayerQuestData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  PlayerQuestData* pQuestData = ((PlayerQuestData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendAddAcceptQuest'", NULL);
#endif
  {
   self->sendAddAcceptQuest(pQuestData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendAddAcceptQuest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendAddCanAcceptQuest of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_sendAddCanAcceptQuest00
static int tolua_serverLuaInterface_CPlayerQuest_sendAddCanAcceptQuest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  unsigned short questID = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendAddCanAcceptQuest'", NULL);
#endif
  {
   self->sendAddCanAcceptQuest(questID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendAddCanAcceptQuest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendUpdateAcceptQuest of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_sendUpdateAcceptQuest00
static int tolua_serverLuaInterface_CPlayerQuest_sendUpdateAcceptQuest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  unsigned short questID = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
  unsigned char idx = ((unsigned char)  tolua_tonumber(tolua_S,3,0));
  unsigned char count = ((unsigned char)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendUpdateAcceptQuest'", NULL);
#endif
  {
   self->sendUpdateAcceptQuest(questID,idx,count);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendUpdateAcceptQuest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendDelAcceptQuest of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_sendDelAcceptQuest00
static int tolua_serverLuaInterface_CPlayerQuest_sendDelAcceptQuest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  unsigned short questID = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendDelAcceptQuest'", NULL);
#endif
  {
   self->sendDelAcceptQuest(questID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendDelAcceptQuest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendDelCanAcceptQuest of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_sendDelCanAcceptQuest00
static int tolua_serverLuaInterface_CPlayerQuest_sendDelCanAcceptQuest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  unsigned short questID = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendDelCanAcceptQuest'", NULL);
#endif
  {
   self->sendDelCanAcceptQuest(questID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendDelCanAcceptQuest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkCanAccept of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_checkCanAccept00
static int tolua_serverLuaInterface_CPlayerQuest_checkCanAccept00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  unsigned short tolua_var_1 = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkCanAccept'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkCanAccept(tolua_var_1);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkCanAccept'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkCanSubmit of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_checkCanSubmit00
static int tolua_serverLuaInterface_CPlayerQuest_checkCanSubmit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  unsigned short tolua_var_2 = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkCanSubmit'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkCanSubmit(tolua_var_2);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkCanSubmit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: acceptQuest of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_acceptQuest00
static int tolua_serverLuaInterface_CPlayerQuest_acceptQuest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  unsigned short tolua_var_3 = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'acceptQuest'", NULL);
#endif
  {
   self->acceptQuest(tolua_var_3);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'acceptQuest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: submitQuest of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_submitQuest00
static int tolua_serverLuaInterface_CPlayerQuest_submitQuest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  unsigned short tolua_var_4 = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'submitQuest'", NULL);
#endif
  {
   self->submitQuest(tolua_var_4);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'submitQuest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNpcQuestState of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_getNpcQuestState00
static int tolua_serverLuaInterface_CPlayerQuest_getNpcQuestState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  unsigned long long npcId = ((unsigned long long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNpcQuestState'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getNpcQuestState(npcId);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNpcQuestState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateQuestTarget of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_updateQuestTarget00
static int tolua_serverLuaInterface_CPlayerQuest_updateQuestTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  int questID = ((int)  tolua_tonumber(tolua_S,2,0));
  int tarIdx = ((int)  tolua_tonumber(tolua_S,3,0));
  int tarAddCount = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateQuestTarget'", NULL);
#endif
  {
   self->updateQuestTarget(questID,tarIdx,tarAddCount);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateQuestTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: questNormalHandler of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_questNormalHandler00
static int tolua_serverLuaInterface_CPlayerQuest_questNormalHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"QuestConfig::ENUM_QUEST_TARGET",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  const int id = ((const int)  tolua_tonumber(tolua_S,2,0));
  int nCount = ((int)  tolua_tonumber(tolua_S,3,0));
  QuestConfig::ENUM_QUEST_TARGET type = *((QuestConfig::ENUM_QUEST_TARGET*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'questNormalHandler'", NULL);
#endif
  {
   self->questNormalHandler(id,nCount,type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'questNormalHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addItem of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_addItem00
static int tolua_serverLuaInterface_CPlayerQuest_addItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"LogicEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LogicEvent* event = ((LogicEvent*)  tolua_tousertype(tolua_S,2,0));
  {
   CPlayerQuest::addItem(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delItem of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_delItem00
static int tolua_serverLuaInterface_CPlayerQuest_delItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"LogicEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LogicEvent* event = ((LogicEvent*)  tolua_tousertype(tolua_S,2,0));
  {
   CPlayerQuest::delItem(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: actorDie of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_actorDie00
static int tolua_serverLuaInterface_CPlayerQuest_actorDie00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"LogicEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LogicEvent* event = ((LogicEvent*)  tolua_tousertype(tolua_S,2,0));
  {
   CPlayerQuest::actorDie(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'actorDie'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearAllQuest of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_clearAllQuest00
static int tolua_serverLuaInterface_CPlayerQuest_clearAllQuest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearAllQuest'", NULL);
#endif
  {
   self->clearAllQuest();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearAllQuest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addQuest of class  CPlayerQuest */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerQuest_addQuest00
static int tolua_serverLuaInterface_CPlayerQuest_addQuest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerQuest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerQuest* self = (CPlayerQuest*)  tolua_tousertype(tolua_S,1,0);
  unsigned short questID = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addQuest'", NULL);
#endif
  {
   self->addQuest(questID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addQuest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CPlayerNpcTalk */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerNpcTalk_new00
static int tolua_serverLuaInterface_CPlayerNpcTalk_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayerNpcTalk",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CPlayerNpcTalk* tolua_ret = (CPlayerNpcTalk*)  Mtolua_new((CPlayerNpcTalk)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CPlayerNpcTalk");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CPlayerNpcTalk */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerNpcTalk_new00_local
static int tolua_serverLuaInterface_CPlayerNpcTalk_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayerNpcTalk",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CPlayerNpcTalk* tolua_ret = (CPlayerNpcTalk*)  Mtolua_new((CPlayerNpcTalk)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CPlayerNpcTalk");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CPlayerNpcTalk */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerNpcTalk_delete00
static int tolua_serverLuaInterface_CPlayerNpcTalk_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerNpcTalk",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerNpcTalk* self = (CPlayerNpcTalk*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CPlayerNpcTalk */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerNpcTalk_init00
static int tolua_serverLuaInterface_CPlayerNpcTalk_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerNpcTalk",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerNpcTalk* self = (CPlayerNpcTalk*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadData of class  CPlayerNpcTalk */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerNpcTalk_loadData00
static int tolua_serverLuaInterface_CPlayerNpcTalk_loadData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerNpcTalk",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDataPacketReader",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerNpcTalk* self = (CPlayerNpcTalk*)  tolua_tousertype(tolua_S,1,0);
  CDataPacketReader* data = ((CDataPacketReader*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadData'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->loadData(*data);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: saveData of class  CPlayerNpcTalk */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerNpcTalk_saveData00
static int tolua_serverLuaInterface_CPlayerNpcTalk_saveData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerNpcTalk",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDataPacket",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerNpcTalk* self = (CPlayerNpcTalk*)  tolua_tousertype(tolua_S,1,0);
  CDataPacket* data = ((CDataPacket*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'saveData'", NULL);
#endif
  {
   self->saveData(*data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dispatchRecvPacket of class  CPlayerNpcTalk */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerNpcTalk_dispatchRecvPacket00
static int tolua_serverLuaInterface_CPlayerNpcTalk_dispatchRecvPacket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerNpcTalk",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CDataPacketReader",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerNpcTalk* self = (CPlayerNpcTalk*)  tolua_tousertype(tolua_S,1,0);
  int btCmd = ((int)  tolua_tonumber(tolua_S,2,0));
  CDataPacketReader* inPacket = ((CDataPacketReader*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dispatchRecvPacket'", NULL);
#endif
  {
   self->dispatchRecvPacket(btCmd,*inPacket);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dispatchRecvPacket'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendCloseTalk of class  CPlayerNpcTalk */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerNpcTalk_sendCloseTalk00
static int tolua_serverLuaInterface_CPlayerNpcTalk_sendCloseTalk00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerNpcTalk",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerNpcTalk* self = (CPlayerNpcTalk*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendCloseTalk'", NULL);
#endif
  {
   self->sendCloseTalk();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendCloseTalk'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nTalkNpcID of class  CPlayerNpcTalk */
#ifndef TOLUA_DISABLE_tolua_get_CPlayerNpcTalk_m_nTalkNpcID
static int tolua_get_CPlayerNpcTalk_m_nTalkNpcID(lua_State* tolua_S)
{
  CPlayerNpcTalk* self = (CPlayerNpcTalk*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nTalkNpcID'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nTalkNpcID);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nTalkNpcID of class  CPlayerNpcTalk */
#ifndef TOLUA_DISABLE_tolua_set_CPlayerNpcTalk_m_nTalkNpcID
static int tolua_set_CPlayerNpcTalk_m_nTalkNpcID(lua_State* tolua_S)
{
  CPlayerNpcTalk* self = (CPlayerNpcTalk*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nTalkNpcID'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nTalkNpcID = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_npcName of class  CPlayerNpcTalk */
#ifndef TOLUA_DISABLE_tolua_get_CPlayerNpcTalk_m_npcName
static int tolua_get_CPlayerNpcTalk_m_npcName(lua_State* tolua_S)
{
  CPlayerNpcTalk* self = (CPlayerNpcTalk*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_npcName'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->m_npcName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_npcName of class  CPlayerNpcTalk */
#ifndef TOLUA_DISABLE_tolua_set_CPlayerNpcTalk_m_npcName
static int tolua_set_CPlayerNpcTalk_m_npcName(lua_State* tolua_S)
{
  CPlayerNpcTalk* self = (CPlayerNpcTalk*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_npcName'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->m_npcName,(const char*)tolua_tostring(tolua_S,2,0),48-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CPlayerEquip */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerEquip_new00
static int tolua_serverLuaInterface_CPlayerEquip_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayerEquip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CPlayerEquip* tolua_ret = (CPlayerEquip*)  Mtolua_new((CPlayerEquip)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CPlayerEquip");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CPlayerEquip */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerEquip_new00_local
static int tolua_serverLuaInterface_CPlayerEquip_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayerEquip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CPlayerEquip* tolua_ret = (CPlayerEquip*)  Mtolua_new((CPlayerEquip)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CPlayerEquip");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CPlayerEquip */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerEquip_delete00
static int tolua_serverLuaInterface_CPlayerEquip_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerEquip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerEquip* self = (CPlayerEquip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CPlayerEquip */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerEquip_init00
static int tolua_serverLuaInterface_CPlayerEquip_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerEquip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerEquip* self = (CPlayerEquip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadData of class  CPlayerEquip */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerEquip_loadData00
static int tolua_serverLuaInterface_CPlayerEquip_loadData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerEquip",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDataPacketReader",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerEquip* self = (CPlayerEquip*)  tolua_tousertype(tolua_S,1,0);
  CDataPacketReader* data = ((CDataPacketReader*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadData'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->loadData(*data);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: saveData of class  CPlayerEquip */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerEquip_saveData00
static int tolua_serverLuaInterface_CPlayerEquip_saveData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerEquip",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDataPacket",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerEquip* self = (CPlayerEquip*)  tolua_tousertype(tolua_S,1,0);
  CDataPacket* data = ((CDataPacket*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'saveData'", NULL);
#endif
  {
   self->saveData(*data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dispatchRecvPacket of class  CPlayerEquip */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerEquip_dispatchRecvPacket00
static int tolua_serverLuaInterface_CPlayerEquip_dispatchRecvPacket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerEquip",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CDataPacketReader",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerEquip* self = (CPlayerEquip*)  tolua_tousertype(tolua_S,1,0);
  int btCmd = ((int)  tolua_tonumber(tolua_S,2,0));
  CDataPacketReader* inPacket = ((CDataPacketReader*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dispatchRecvPacket'", NULL);
#endif
  {
   self->dispatchRecvPacket(btCmd,*inPacket);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dispatchRecvPacket'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEquipPos of class  CPlayerEquip */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerEquip_getEquipPos00
static int tolua_serverLuaInterface_CPlayerEquip_getEquipPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerEquip",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerEquip* self = (CPlayerEquip*)  tolua_tousertype(tolua_S,1,0);
  int btItemType = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEquipPos'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getEquipPos(btItemType);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEquipPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: findEquipItem of class  CPlayerEquip */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerEquip_findEquipItem00
static int tolua_serverLuaInterface_CPlayerEquip_findEquipItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerEquip",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"common::ItemSeries",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerEquip* self = (CPlayerEquip*)  tolua_tousertype(tolua_S,1,0);
  common::ItemSeries series = *((common::ItemSeries*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'findEquipItem'", NULL);
#endif
  {
   int tolua_ret = (int)  self->findEquipItem(series);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'findEquipItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendEquipItems of class  CPlayerEquip */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerEquip_sendEquipItems00
static int tolua_serverLuaInterface_CPlayerEquip_sendEquipItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerEquip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerEquip* self = (CPlayerEquip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendEquipItems'", NULL);
#endif
  {
   self->sendEquipItems();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendEquipItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_ItemList of class  CPlayerEquip */
#ifndef TOLUA_DISABLE_tolua_get_serverLuaInterface_CPlayerEquip_m_ItemList
static int tolua_get_serverLuaInterface_CPlayerEquip_m_ItemList(lua_State* tolua_S)
{
 int tolua_index;
  CPlayerEquip* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (CPlayerEquip*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=CPlayerEquip::EquipCount)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->m_ItemList[tolua_index],"UserItem");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_ItemList of class  CPlayerEquip */
#ifndef TOLUA_DISABLE_tolua_set_serverLuaInterface_CPlayerEquip_m_ItemList
static int tolua_set_serverLuaInterface_CPlayerEquip_m_ItemList(lua_State* tolua_S)
{
 int tolua_index;
  CPlayerEquip* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (CPlayerEquip*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=CPlayerEquip::EquipCount)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->m_ItemList[tolua_index] = ((UserItem*)  tolua_tousertype(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_new00
static int tolua_serverLuaInterface_CDoerBattle_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CDoerBattle* tolua_ret = (CDoerBattle*)  Mtolua_new((CDoerBattle)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CDoerBattle");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_new00_local
static int tolua_serverLuaInterface_CDoerBattle_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CDoerBattle* tolua_ret = (CDoerBattle*)  Mtolua_new((CDoerBattle)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CDoerBattle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_delete00
static int tolua_serverLuaInterface_CDoerBattle_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isRunning of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_isRunning00
static int tolua_serverLuaInterface_CDoerBattle_isRunning00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CDoerBattle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CDoerBattle* self = (const CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isRunning'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isRunning();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isRunning'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: startMove of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_startMove00
static int tolua_serverLuaInterface_CDoerBattle_startMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  short speedX = ((short)  tolua_tonumber(tolua_S,2,0));
  short speedY = ((short)  tolua_tonumber(tolua_S,3,0));
  unsigned short accTime = ((unsigned short)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'startMove'", NULL);
#endif
  {
   self->startMove(speedX,speedY,accTime);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'startMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopMove of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_stopMove00
static int tolua_serverLuaInterface_CDoerBattle_stopMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  bool broadcast = ((bool)  tolua_toboolean(tolua_S,2,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopMove'", NULL);
#endif
  {
   self->stopMove(broadcast);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: startAttack of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_startAttack00
static int tolua_serverLuaInterface_CDoerBattle_startAttack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const *",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"uint32",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  CFSkillPostureLevel* const * postureList = *((CFSkillPostureLevel* const **)  tolua_tousertype(tolua_S,2,0));
  uint32 postureCount = *((uint32*)  tolua_tousertype(tolua_S,3,0));
  int dir = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'startAttack'", NULL);
#endif
  {
   self->startAttack(postureList,postureCount,dir);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'startAttack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopAttack of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_stopAttack00
static int tolua_serverLuaInterface_CDoerBattle_stopAttack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopAttack'", NULL);
#endif
  {
   self->stopAttack();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopAttack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendSceneInfo of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_sendSceneInfo00
static int tolua_serverLuaInterface_CDoerBattle_sendSceneInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendSceneInfo'", NULL);
#endif
  {
   self->sendSceneInfo();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendSceneInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendSyncPositionTo of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_sendSyncPositionTo00
static int tolua_serverLuaInterface_CDoerBattle_sendSyncPositionTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  CPlayer* target = ((CPlayer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendSyncPositionTo'", NULL);
#endif
  {
   self->sendSyncPositionTo(target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendSyncPositionTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendStartRunTo of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_sendStartRunTo00
static int tolua_serverLuaInterface_CDoerBattle_sendStartRunTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  CPlayer* target = ((CPlayer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendStartRunTo'", NULL);
#endif
  {
   self->sendStartRunTo(target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendStartRunTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: run of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_run00
static int tolua_serverLuaInterface_CDoerBattle_run00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  TickTime dwCurrTick = *((TickTime*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'run'", NULL);
#endif
  {
   self->run(dwCurrTick);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'run'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: damageHP of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_damageHP00
static int tolua_serverLuaInterface_CDoerBattle_damageHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CDoer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  CDoer* sponsor = ((CDoer*)  tolua_tousertype(tolua_S,2,0));
  int damage = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'damageHP'", NULL);
#endif
  {
   self->damageHP(sponsor,damage);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'damageHP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: struck of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_struck00
static int tolua_serverLuaInterface_CDoerBattle_struck00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CDoer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"AttackPowerType",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  CDoer* sponsor = ((CDoer*)  tolua_tousertype(tolua_S,2,0));
  AttackPowerType pwrType = *((AttackPowerType*)  tolua_tousertype(tolua_S,3,0));
  int power = ((int)  tolua_tonumber(tolua_S,4,0));
  double rate = ((double)  tolua_tonumber(tolua_S,5,1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'struck'", NULL);
#endif
  {
   self->struck(sponsor,pwrType,power,rate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'struck'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: die of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_die00
static int tolua_serverLuaInterface_CDoerBattle_die00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CDoer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  CDoer* killer = ((CDoer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'die'", NULL);
#endif
  {
   self->die(killer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'die'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reviviscent of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_reviviscent00
static int tolua_serverLuaInterface_CDoerBattle_reviviscent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reviviscent'", NULL);
#endif
  {
   self->reviviscent();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reviviscent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: outOfControl of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_outOfControl00
static int tolua_serverLuaInterface_CDoerBattle_outOfControl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  int moveTime = ((int)  tolua_tonumber(tolua_S,2,0));
  int attackTime = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'outOfControl'", NULL);
#endif
  {
   self->outOfControl(moveTime,attackTime);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'outOfControl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: collapse of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_collapse00
static int tolua_serverLuaInterface_CDoerBattle_collapse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  int layTime = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'collapse'", NULL);
#endif
  {
   self->collapse(layTime);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'collapse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: decideDamageType of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_decideDamageType00
static int tolua_serverLuaInterface_CDoerBattle_decideDamageType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CDoer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"AttackPowerType",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  CDoer* sponsor = ((CDoer*)  tolua_tousertype(tolua_S,2,0));
  AttackPowerType tolua_var_5 = *((AttackPowerType*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'decideDamageType'", NULL);
#endif
  {
   double tolua_ret = (double)  self->decideDamageType(sponsor,tolua_var_5);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'decideDamageType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: calcDamageValue of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_calcDamageValue00
static int tolua_serverLuaInterface_CDoerBattle_calcDamageValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CDoer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"AttackPowerType",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  CDoer* sponsor = ((CDoer*)  tolua_tousertype(tolua_S,2,0));
  AttackPowerType pwrType = *((AttackPowerType*)  tolua_tousertype(tolua_S,3,0));
  int power = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'calcDamageValue'", NULL);
#endif
  {
   int tolua_ret = (int)  self->calcDamageValue(sponsor,pwrType,power);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'calcDamageValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: calcNewPositionAtTime of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_calcNewPositionAtTime00
static int tolua_serverLuaInterface_CDoerBattle_calcNewPositionAtTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  TickTime dwTick = *((TickTime*)  tolua_tousertype(tolua_S,2,0));
  int nNewX = ((int)  tolua_tonumber(tolua_S,3,0));
  int nNewY = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'calcNewPositionAtTime'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->calcNewPositionAtTime(dwTick,nNewX,nNewY);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)nNewX);
   tolua_pushnumber(tolua_S,(lua_Number)nNewY);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'calcNewPositionAtTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isAttackableActor of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_isAttackableActor00
static int tolua_serverLuaInterface_CDoerBattle_isAttackableActor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CDoer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  CDoer* target = ((CDoer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isAttackableActor'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isAttackableActor(target);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isAttackableActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLastHiter of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_setLastHiter00
static int tolua_serverLuaInterface_CDoerBattle_setLastHiter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CDoer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  CDoer* sponsor = ((CDoer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLastHiter'", NULL);
#endif
  {
   self->setLastHiter(sponsor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLastHiter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTargetActor of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_setTargetActor00
static int tolua_serverLuaInterface_CDoerBattle_setTargetActor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CDoer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  CDoer* target = ((CDoer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTargetActor'", NULL);
#endif
  {
   self->setTargetActor(target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTargetActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMoveTarget of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_setMoveTarget00
static int tolua_serverLuaInterface_CDoerBattle_setMoveTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  int tx = ((int)  tolua_tonumber(tolua_S,2,0));
  int ty = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMoveTarget'", NULL);
#endif
  {
   self->setMoveTarget(tx,ty);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMoveTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_init00
static int tolua_serverLuaInterface_CDoerBattle_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadData of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_loadData00
static int tolua_serverLuaInterface_CDoerBattle_loadData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDataPacketReader",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  CDataPacketReader* data = ((CDataPacketReader*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadData'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->loadData(*data);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dispatchRecvPacket of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_dispatchRecvPacket00
static int tolua_serverLuaInterface_CDoerBattle_dispatchRecvPacket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CDataPacketReader",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  int btCmd = ((int)  tolua_tonumber(tolua_S,2,0));
  CDataPacketReader* inPacket = ((CDataPacketReader*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dispatchRecvPacket'", NULL);
#endif
  {
   self->dispatchRecvPacket(btCmd,*inPacket);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dispatchRecvPacket'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dispatchMsg of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_dispatchMsg00
static int tolua_serverLuaInterface_CDoerBattle_dispatchMsg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"DoerMsg",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
  DoerMsg* msg = ((DoerMsg*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dispatchMsg'", NULL);
#endif
  {
   self->dispatchMsg(msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dispatchMsg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: offline of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CDoerBattle_offline00
static int tolua_serverLuaInterface_CDoerBattle_offline00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CDoerBattle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'offline'", NULL);
#endif
  {
   self->offline();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'offline'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_dwMonFlags of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_get_CDoerBattle_unsigned_m_dwMonFlags
static int tolua_get_CDoerBattle_unsigned_m_dwMonFlags(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwMonFlags'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_dwMonFlags);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_dwMonFlags of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_set_CDoerBattle_unsigned_m_dwMonFlags
static int tolua_set_CDoerBattle_unsigned_m_dwMonFlags(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwMonFlags'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_dwMonFlags = ((unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nTargetX of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_get_CDoerBattle_m_nTargetX
static int tolua_get_CDoerBattle_m_nTargetX(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nTargetX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nTargetX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nTargetX of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_set_CDoerBattle_m_nTargetX
static int tolua_set_CDoerBattle_m_nTargetX(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nTargetX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nTargetX = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nTargetY of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_get_CDoerBattle_m_nTargetY
static int tolua_get_CDoerBattle_m_nTargetY(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nTargetY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nTargetY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nTargetY of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_set_CDoerBattle_m_nTargetY
static int tolua_set_CDoerBattle_m_nTargetY(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nTargetY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nTargetY = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_boReturning of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_get_CDoerBattle_m_boReturning
static int tolua_get_CDoerBattle_m_boReturning(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_boReturning'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->m_boReturning);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_boReturning of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_set_CDoerBattle_m_boReturning
static int tolua_set_CDoerBattle_m_boReturning(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_boReturning'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_boReturning = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ___________reserve of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_get_CDoerBattle____________reserve
static int tolua_get_CDoerBattle____________reserve(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '___________reserve'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->___________reserve);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ___________reserve of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_set_CDoerBattle____________reserve
static int tolua_set_CDoerBattle____________reserve(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '___________reserve'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->___________reserve,(const char*)tolua_tostring(tolua_S,2,0),3-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pTargetActor of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_get_CDoerBattle_m_pTargetActor_ptr
static int tolua_get_CDoerBattle_m_pTargetActor_ptr(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pTargetActor'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pTargetActor,"CDoer");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pTargetActor of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_set_CDoerBattle_m_pTargetActor_ptr
static int tolua_set_CDoerBattle_m_pTargetActor_ptr(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pTargetActor'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CDoer",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pTargetActor = ((CDoer*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pLastHiter of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_get_CDoerBattle_m_pLastHiter_ptr
static int tolua_get_CDoerBattle_m_pLastHiter_ptr(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pLastHiter'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pLastHiter,"CDoer");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pLastHiter of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_set_CDoerBattle_m_pLastHiter_ptr
static int tolua_set_CDoerBattle_m_pLastHiter_ptr(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pLastHiter'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CDoer",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pLastHiter = ((CDoer*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_dwLastHiterTimeOut of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_get_CDoerBattle_m_dwLastHiterTimeOut
static int tolua_get_CDoerBattle_m_dwLastHiterTimeOut(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwLastHiterTimeOut'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_dwLastHiterTimeOut,"TickTime");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_dwLastHiterTimeOut of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_set_CDoerBattle_m_dwLastHiterTimeOut
static int tolua_set_CDoerBattle_m_dwLastHiterTimeOut(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwLastHiterTimeOut'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_dwLastHiterTimeOut = *((TickTime*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_dwNextSearchTargetTick of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_get_CDoerBattle_m_dwNextSearchTargetTick
static int tolua_get_CDoerBattle_m_dwNextSearchTargetTick(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwNextSearchTargetTick'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_dwNextSearchTargetTick,"TickTime");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_dwNextSearchTargetTick of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_set_CDoerBattle_m_dwNextSearchTargetTick
static int tolua_set_CDoerBattle_m_dwNextSearchTargetTick(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwNextSearchTargetTick'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_dwNextSearchTargetTick = *((TickTime*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_dwMonNormalAttackPrepareEndTick of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_get_CDoerBattle_m_dwMonNormalAttackPrepareEndTick
static int tolua_get_CDoerBattle_m_dwMonNormalAttackPrepareEndTick(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwMonNormalAttackPrepareEndTick'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_dwMonNormalAttackPrepareEndTick,"TickTime");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_dwMonNormalAttackPrepareEndTick of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_set_CDoerBattle_m_dwMonNormalAttackPrepareEndTick
static int tolua_set_CDoerBattle_m_dwMonNormalAttackPrepareEndTick(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwMonNormalAttackPrepareEndTick'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_dwMonNormalAttackPrepareEndTick = *((TickTime*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_dwMonNormalAttackTakeEffectTick of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_get_CDoerBattle_m_dwMonNormalAttackTakeEffectTick
static int tolua_get_CDoerBattle_m_dwMonNormalAttackTakeEffectTick(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwMonNormalAttackTakeEffectTick'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_dwMonNormalAttackTakeEffectTick,"TickTime");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_dwMonNormalAttackTakeEffectTick of class  CDoerBattle */
#ifndef TOLUA_DISABLE_tolua_set_CDoerBattle_m_dwMonNormalAttackTakeEffectTick
static int tolua_set_CDoerBattle_m_dwMonNormalAttackTakeEffectTick(lua_State* tolua_S)
{
  CDoerBattle* self = (CDoerBattle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_dwMonNormalAttackTakeEffectTick'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"TickTime",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_dwMonNormalAttackTakeEffectTick = *((TickTime*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_new00
static int tolua_serverLuaInterface_CPlayerBag_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CPlayerBag* tolua_ret = (CPlayerBag*)  Mtolua_new((CPlayerBag)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CPlayerBag");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_new00_local
static int tolua_serverLuaInterface_CPlayerBag_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CPlayerBag* tolua_ret = (CPlayerBag*)  Mtolua_new((CPlayerBag)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CPlayerBag");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_delete00
static int tolua_serverLuaInterface_CPlayerBag_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_init00
static int tolua_serverLuaInterface_CPlayerBag_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadData of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_loadData00
static int tolua_serverLuaInterface_CPlayerBag_loadData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDataPacketReader",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
  CDataPacketReader* data = ((CDataPacketReader*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadData'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->loadData(*data);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: saveData of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_saveData00
static int tolua_serverLuaInterface_CPlayerBag_saveData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CDataPacket",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
  CDataPacket* data = ((CDataPacket*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'saveData'", NULL);
#endif
  {
   self->saveData(*data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getItem of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_getItem00
static int tolua_serverLuaInterface_CPlayerBag_getItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const common::ItemSeries",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
  const common::ItemSeries series = *((const common::ItemSeries*)  tolua_tousertype(tolua_S,2,0));
  int pIndex = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getItem'", NULL);
#endif
  {
   UserItem* tolua_ret = (UserItem*)  self->getItem(series,&pIndex);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UserItem");
   tolua_pushnumber(tolua_S,(lua_Number)pIndex);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getItem of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_getItem01
static int tolua_serverLuaInterface_CPlayerBag_getItem01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
  const int wItemId = ((const int)  tolua_tonumber(tolua_S,2,0));
  int pIndex = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getItem'", NULL);
#endif
  {
   UserItem* tolua_ret = (UserItem*)  self->getItem(wItemId,&pIndex);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UserItem");
   tolua_pushnumber(tolua_S,(lua_Number)pIndex);
  }
 }
 return 2;
tolua_lerror:
 return tolua_serverLuaInterface_CPlayerBag_getItem00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getItemCount of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_getItemCount00
static int tolua_serverLuaInterface_CPlayerBag_getItemCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
  const int wItemId = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getItemCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getItemCount(wItemId);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getItemCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addItem of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_addItem00
static int tolua_serverLuaInterface_CPlayerBag_addItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isstring(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
  const int wItemId = ((const int)  tolua_tonumber(tolua_S,2,0));
  int nCount = ((int)  tolua_tonumber(tolua_S,3,0));
  int nQuality = ((int)  tolua_tonumber(tolua_S,4,0));
  int nStrong = ((int)  tolua_tonumber(tolua_S,5,0));
  int nUseTime = ((int)  tolua_tonumber(tolua_S,6,0));
  const bool boBind = ((const bool)  tolua_toboolean(tolua_S,7,0));
  int nLogID = ((int)  tolua_tonumber(tolua_S,8,0));
  const char* sGiver = ((const char*)  tolua_tostring(tolua_S,9,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addItem'", NULL);
#endif
  {
   int tolua_ret = (int)  self->addItem(wItemId,nCount,nQuality,nStrong,nUseTime,boBind,nLogID,sGiver);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delItem of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_delItem00
static int tolua_serverLuaInterface_CPlayerBag_delItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
  const int wItemId = ((const int)  tolua_tonumber(tolua_S,2,0));
  int nCount = ((int)  tolua_tonumber(tolua_S,3,0));
  int nLogId = ((int)  tolua_tonumber(tolua_S,4,0));
  const char* sGiver = ((const char*)  tolua_tostring(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delItem'", NULL);
#endif
  {
   int tolua_ret = (int)  self->delItem(wItemId,nCount,nLogId,sGiver);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addItem of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_addItem01
static int tolua_serverLuaInterface_CPlayerBag_addItem01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"UserItem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
  UserItem* pUserItem = ((UserItem*)  tolua_tousertype(tolua_S,2,0));
  int nLogID = ((int)  tolua_tonumber(tolua_S,3,0));
  const char* sGiver = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addItem'", NULL);
#endif
  {
   self->addItem(pUserItem,nLogID,sGiver);
  }
 }
 return 0;
tolua_lerror:
 return tolua_serverLuaInterface_CPlayerBag_addItem00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delItem of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_delItem01
static int tolua_serverLuaInterface_CPlayerBag_delItem01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
  const int nItemListIndex = ((const int)  tolua_tonumber(tolua_S,2,0));
  int nLogId = ((int)  tolua_tonumber(tolua_S,3,0));
  const char* sGiver = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delItem'", NULL);
#endif
  {
   self->delItem(nItemListIndex,nLogId,sGiver);
  }
 }
 return 0;
tolua_lerror:
 return tolua_serverLuaInterface_CPlayerBag_delItem00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCanAddItemCount of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_getCanAddItemCount00
static int tolua_serverLuaInterface_CPlayerBag_getCanAddItemCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
  const int wItemId = ((const int)  tolua_tonumber(tolua_S,2,0));
  int nCount = ((int)  tolua_tonumber(tolua_S,3,0));
  int nExpireTime = ((int)  tolua_tonumber(tolua_S,4,0));
  const bool boBind = ((const bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCanAddItemCount'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getCanAddItemCount(wItemId,nCount,nExpireTime,boBind);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCanAddItemCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCanOverlapItem of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_getCanOverlapItem00
static int tolua_serverLuaInterface_CPlayerBag_getCanOverlapItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
  const int wItemId = ((const int)  tolua_tonumber(tolua_S,2,0));
  int nExpireTime = ((int)  tolua_tonumber(tolua_S,3,0));
  const bool boBind = ((const bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCanOverlapItem'", NULL);
#endif
  {
   UserItem* tolua_ret = (UserItem*)  self->getCanOverlapItem(wItemId,nExpireTime,boBind);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UserItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCanOverlapItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initUserItemFromStdItem of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_initUserItemFromStdItem00
static int tolua_serverLuaInterface_CPlayerBag_initUserItemFromStdItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"UserItem",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const CFItem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,8,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
  UserItem* pUserItem = ((UserItem*)  tolua_tousertype(tolua_S,2,0));
  const CFItem* pStdItem = ((const CFItem*)  tolua_tousertype(tolua_S,3,0));
  int nCount = ((int)  tolua_tonumber(tolua_S,4,0));
  int nQuality = ((int)  tolua_tonumber(tolua_S,5,0));
  int nStrong = ((int)  tolua_tonumber(tolua_S,6,0));
  int nExpireTime = ((int)  tolua_tonumber(tolua_S,7,0));
  bool boBind = ((bool)  tolua_toboolean(tolua_S,8,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initUserItemFromStdItem'", NULL);
#endif
  {
   self->initUserItemFromStdItem(pUserItem,pStdItem,nCount,nQuality,nStrong,nExpireTime,boBind);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initUserItemFromStdItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendBagItems of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_serverLuaInterface_CPlayerBag_sendBagItems00
static int tolua_serverLuaInterface_CPlayerBag_sendBagItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CPlayerBag",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendBagItems'", NULL);
#endif
  {
   self->sendBagItems();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendBagItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_btBagCurSize of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_get_CPlayerBag_unsigned_m_btBagCurSize
static int tolua_get_CPlayerBag_unsigned_m_btBagCurSize(lua_State* tolua_S)
{
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btBagCurSize'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_btBagCurSize);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_btBagCurSize of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_set_CPlayerBag_unsigned_m_btBagCurSize
static int tolua_set_CPlayerBag_unsigned_m_btBagCurSize(lua_State* tolua_S)
{
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_btBagCurSize'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_btBagCurSize = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ______reserve of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_get_CPlayerBag_______reserve
static int tolua_get_CPlayerBag_______reserve(lua_State* tolua_S)
{
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '______reserve'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->______reserve);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ______reserve of class  CPlayerBag */
#ifndef TOLUA_DISABLE_tolua_set_CPlayerBag_______reserve
static int tolua_set_CPlayerBag_______reserve(lua_State* tolua_S)
{
  CPlayerBag* self = (CPlayerBag*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '______reserve'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->______reserve,(const char*)tolua_tostring(tolua_S,2,0),3-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE


/* Open function */
static int tolua_serverLuaInterface_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"common",0);
  tolua_beginmodule(tolua_S,"common");
   tolua_constant(tolua_S,"ptPC",common::ptPC);
   tolua_constant(tolua_S,"ptiPhone",common::ptiPhone);
   tolua_constant(tolua_S,"ptiPad",common::ptiPad);
   tolua_constant(tolua_S,"ptAndroidPhone",common::ptAndroidPhone);
   tolua_constant(tolua_S,"ptAndroidPad",common::ptAndroidPad);
   tolua_constant(tolua_S,"ptWinPhone",common::ptWinPhone);
   tolua_constant(tolua_S,"ptWinPad",common::ptWinPad);
   tolua_constant(tolua_S,"aNull",common::aNull);
   tolua_constant(tolua_S,"aBiLi",common::aBiLi);
   tolua_constant(tolua_S,"aLingQiao",common::aLingQiao);
   tolua_constant(tolua_S,"aTiPo",common::aTiPo);
   tolua_constant(tolua_S,"aNeiXi",common::aNeiXi);
   tolua_constant(tolua_S,"aGangQi",common::aGangQi);
   tolua_constant(tolua_S,"aWaiGong",common::aWaiGong);
   tolua_constant(tolua_S,"aNeiGong",common::aNeiGong);
   tolua_constant(tolua_S,"aWaiFang",common::aWaiFang);
   tolua_constant(tolua_S,"aNeiFang",common::aNeiFang);
   tolua_constant(tolua_S,"aWaiFangCT",common::aWaiFangCT);
   tolua_constant(tolua_S,"aNeiFangCT",common::aNeiFangCT);
   tolua_constant(tolua_S,"aQiXue",common::aQiXue);
   tolua_constant(tolua_S,"aNeiLi",common::aNeiLi);
   tolua_constant(tolua_S,"aWaiBao",common::aWaiBao);
   tolua_constant(tolua_S,"aNeiBao",common::aNeiBao);
   tolua_constant(tolua_S,"aKangWaiBao",common::aKangWaiBao);
   tolua_constant(tolua_S,"aKangNeiBao",common::aKangNeiBao);
   tolua_constant(tolua_S,"aMingZhong",common::aMingZhong);
   tolua_constant(tolua_S,"aShanBi",common::aShanBi);
   tolua_constant(tolua_S,"aHitSpeed",common::aHitSpeed);
   tolua_constant(tolua_S,"aMoveSpeed",common::aMoveSpeed);
   tolua_constant(tolua_S,"aQiXueHuiFu",common::aQiXueHuiFu);
   tolua_constant(tolua_S,"aNeiLiHuiFu",common::aNeiLiHuiFu);
   tolua_constant(tolua_S,"aFuYuan",common::aFuYuan);
   tolua_constant(tolua_S,"AttributeCount",common::AttributeCount);
   tolua_cclass(tolua_S,"Attribute","common::Attribute","",NULL);
   tolua_beginmodule(tolua_S,"Attribute");
    tolua_variable(tolua_S,"type",tolua_get_common__Attribute_unsigned_type,tolua_set_common__Attribute_unsigned_type);
    tolua_variable(tolua_S,"reserve",tolua_get_common__Attribute_unsigned_reserve,tolua_set_common__Attribute_unsigned_reserve);
    tolua_variable(tolua_S,"value",tolua_get_common__Attribute_value,tolua_set_common__Attribute_value);
   tolua_endmodule(tolua_S);
   tolua_constant(tolua_S,"iDress",common::iDress);
   tolua_constant(tolua_S,"iPants",common::iPants);
   tolua_constant(tolua_S,"iHat",common::iHat);
   tolua_constant(tolua_S,"iBoot",common::iBoot);
   tolua_constant(tolua_S,"iQuest",common::iQuest);
   tolua_cclass(tolua_S,"EntityPosition","common::EntityPosition","",NULL);
   tolua_beginmodule(tolua_S,"EntityPosition");
    tolua_variable(tolua_S,"nDuplicateId",tolua_get_common__EntityPosition_nDuplicateId,tolua_set_common__EntityPosition_nDuplicateId);
    tolua_variable(tolua_S,"nSceneId",tolua_get_common__EntityPosition_nSceneId,tolua_set_common__EntityPosition_nSceneId);
    tolua_variable(tolua_S,"nMapX",tolua_get_common__EntityPosition_nMapX,tolua_set_common__EntityPosition_nMapX);
    tolua_variable(tolua_S,"nMapY",tolua_get_common__EntityPosition_nMapY,tolua_set_common__EntityPosition_nMapY);
   tolua_endmodule(tolua_S);
   tolua_constant(tolua_S,"apOuter",common::apOuter);
   tolua_constant(tolua_S,"apInner",common::apInner);
   tolua_cclass(tolua_S,"UserItem","common::UserItem","",NULL);
   tolua_beginmodule(tolua_S,"UserItem");
    tolua_variable(tolua_S,"series",tolua_get_common__UserItem_series,tolua_set_common__UserItem_series);
    tolua_variable(tolua_S,"wItemId",tolua_get_common__UserItem_unsigned_wItemId,tolua_set_common__UserItem_unsigned_wItemId);
    tolua_variable(tolua_S,"btStrong",tolua_get_common__UserItem_unsigned_btStrong,tolua_set_common__UserItem_unsigned_btStrong);
    tolua_variable(tolua_S,"btQuality",tolua_get_common__UserItem_unsigned_btQuality,tolua_set_common__UserItem_unsigned_btQuality);
    tolua_array(tolua_S,"InlayItems",tolua_get_serverLuaInterface_common_UserItem_InlayItems,tolua_set_serverLuaInterface_common_UserItem_InlayItems);
    tolua_variable(tolua_S,"nExpireTime",tolua_get_common__UserItem_nExpireTime,tolua_set_common__UserItem_nExpireTime);
    tolua_variable(tolua_S,"btCount",tolua_get_common__UserItem_unsigned_btCount,tolua_set_common__UserItem_unsigned_btCount);
    tolua_variable(tolua_S,"btFlag",tolua_get_common__UserItem_unsigned_btFlag,tolua_set_common__UserItem_unsigned_btFlag);
    tolua_variable(tolua_S,"btReserve",tolua_get_common__UserItem_unsigned_btReserve,tolua_set_common__UserItem_unsigned_btReserve);
    tolua_function(tolua_S,"getIsHoleOpend",tolua_serverLuaInterface_common_UserItem_getIsHoleOpend00);
    tolua_function(tolua_S,"openHole",tolua_serverLuaInterface_common_UserItem_openHole00);
    tolua_function(tolua_S,"getOpendHoleCount",tolua_serverLuaInterface_common_UserItem_getOpendHoleCount00);
    tolua_function(tolua_S,"getInlayedItem",tolua_serverLuaInterface_common_UserItem_getInlayedItem00);
    tolua_function(tolua_S,"setInlayedItem",tolua_serverLuaInterface_common_UserItem_setInlayedItem00);
    tolua_function(tolua_S,"binded",tolua_serverLuaInterface_common_UserItem_binded00);
    tolua_function(tolua_S,"setBind",tolua_serverLuaInterface_common_UserItem_setBind00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"EntityDesc","common::EntityDesc","",NULL);
   tolua_beginmodule(tolua_S,"EntityDesc");
    tolua_constant(tolua_S,"efDead",common::EntityDesc::efDead);
    tolua_variable(tolua_S,"race",tolua_get_common__EntityDesc_unsigned_race,tolua_set_common__EntityDesc_unsigned_race);
    tolua_variable(tolua_S,"genob",tolua_get_common__EntityDesc_unsigned_genob,tolua_set_common__EntityDesc_unsigned_genob);
    tolua_variable(tolua_S,"level",tolua_get_common__EntityDesc_unsigned_level,tolua_set_common__EntityDesc_unsigned_level);
    tolua_variable(tolua_S,"body",tolua_get_common__EntityDesc_unsigned_body,tolua_set_common__EntityDesc_unsigned_body);
    tolua_variable(tolua_S,"weapon",tolua_get_common__EntityDesc_unsigned_weapon,tolua_set_common__EntityDesc_unsigned_weapon);
    tolua_variable(tolua_S,"wpeffect",tolua_get_common__EntityDesc_unsigned_wpeffect,tolua_set_common__EntityDesc_unsigned_wpeffect);
    tolua_variable(tolua_S,"mount",tolua_get_common__EntityDesc_unsigned_mount,tolua_set_common__EntityDesc_unsigned_mount);
    tolua_variable(tolua_S,"moveSpeed",tolua_get_common__EntityDesc_unsigned_moveSpeed,tolua_set_common__EntityDesc_unsigned_moveSpeed);
    tolua_variable(tolua_S,"hitSpeedRate",tolua_get_common__EntityDesc_hitSpeedRate,tolua_set_common__EntityDesc_hitSpeedRate);
    tolua_variable(tolua_S,"flags",tolua_get_common__EntityDesc_unsigned_flags,tolua_set_common__EntityDesc_unsigned_flags);
    tolua_variable(tolua_S,"vipLevel",tolua_get_common__EntityDesc_unsigned_vipLevel,tolua_set_common__EntityDesc_unsigned_vipLevel);
    tolua_variable(tolua_S,"reserve",tolua_get_common__EntityDesc_unsigned_reserve,tolua_set_common__EntityDesc_unsigned_reserve);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"PlayerQuestData","common::PlayerQuestData","",NULL);
   tolua_beginmodule(tolua_S,"PlayerQuestData");
    tolua_variable(tolua_S,"questID",tolua_get_common__PlayerQuestData_unsigned_questID,tolua_set_common__PlayerQuestData_unsigned_questID);
    tolua_variable(tolua_S,"completeTimes",tolua_get_common__PlayerQuestData_unsigned_completeTimes,tolua_set_common__PlayerQuestData_unsigned_completeTimes);
    tolua_variable(tolua_S,"targetCount",tolua_get_common__PlayerQuestData_unsigned_targetCount,tolua_set_common__PlayerQuestData_unsigned_targetCount);
    tolua_variable(tolua_S,"endTime",tolua_get_common__PlayerQuestData_unsigned_endTime,tolua_set_common__PlayerQuestData_unsigned_endTime);
    tolua_variable(tolua_S,"target",tolua_get_common__PlayerQuestData_unsigned_target,tolua_set_common__PlayerQuestData_unsigned_target);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"PlayerDoneQuestData","common::PlayerDoneQuestData","",NULL);
   tolua_beginmodule(tolua_S,"PlayerDoneQuestData");
    tolua_variable(tolua_S,"mask",tolua_get_common__PlayerDoneQuestData_unsigned_mask,tolua_set_common__PlayerDoneQuestData_unsigned_mask);
    tolua_variable(tolua_S,"questID",tolua_get_common__PlayerDoneQuestData_unsigned_questID,tolua_set_common__PlayerDoneQuestData_unsigned_questID);
   tolua_endmodule(tolua_S);
   tolua_constant(tolua_S,"beNone",common::beNone);
   tolua_constant(tolua_S,"beNormal",common::beNormal);
   tolua_constant(tolua_S,"beIce",common::beIce);
   tolua_constant(tolua_S,"beFire",common::beFire);
   tolua_constant(tolua_S,"beElec",common::beElec);
   tolua_constant(tolua_S,"beDrug",common::beDrug);
   tolua_constant(tolua_S,"bhsNone",common::bhsNone);
   tolua_constant(tolua_S,"bhsLock",common::bhsLock);
   tolua_constant(tolua_S,"bhsUnLock",common::bhsUnLock);
   tolua_constant(tolua_S,"bhsOpen",common::bhsOpen);
   tolua_constant(tolua_S,"bhsNest",common::bhsNest);
   tolua_cclass(tolua_S,"Bead","common::Bead","",NULL);
   tolua_beginmodule(tolua_S,"Bead");
    tolua_variable(tolua_S,"series",tolua_get_common__Bead_series,tolua_set_common__Bead_series);
    tolua_variable(tolua_S,"beadId",tolua_get_common__Bead_unsigned_beadId,tolua_set_common__Bead_unsigned_beadId);
    tolua_variable(tolua_S,"addSoulEater",tolua_get_common__Bead_unsigned_addSoulEater,tolua_set_common__Bead_unsigned_addSoulEater);
    tolua_variable(tolua_S,"exp",tolua_get_common__Bead_unsigned_exp,tolua_set_common__Bead_unsigned_exp);
    tolua_variable(tolua_S,"baseAttr",tolua_get_common__Bead_baseAttr,tolua_set_common__Bead_baseAttr);
    tolua_variable(tolua_S,"addAttr",tolua_get_common__Bead_addAttr,tolua_set_common__Bead_addAttr);
    tolua_variable(tolua_S,"elementRatio",tolua_get_common__Bead_unsigned_elementRatio,tolua_set_common__Bead_unsigned_elementRatio);
    tolua_variable(tolua_S,"level",tolua_get_common__Bead_unsigned_level,tolua_set_common__Bead_unsigned_level);
    tolua_variable(tolua_S,"reserve",tolua_get_common__Bead_unsigned_reserve,tolua_set_common__Bead_unsigned_reserve);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Weapon","common::Weapon","",NULL);
   tolua_beginmodule(tolua_S,"Weapon");
    tolua_variable(tolua_S,"weaponId",tolua_get_common__Weapon_unsigned_weaponId,tolua_set_common__Weapon_unsigned_weaponId);
    tolua_variable(tolua_S,"level",tolua_get_common__Weapon_unsigned_level,tolua_set_common__Weapon_unsigned_level);
    tolua_variable(tolua_S,"soulEater",tolua_get_common__Weapon_unsigned_soulEater,tolua_set_common__Weapon_unsigned_soulEater);
    tolua_variable(tolua_S,"eternalValue",tolua_get_common__Weapon_unsigned_eternalValue,tolua_set_common__Weapon_unsigned_eternalValue);
    tolua_variable(tolua_S,"maxEternalValue",tolua_get_common__Weapon_unsigned_maxEternalValue,tolua_set_common__Weapon_unsigned_maxEternalValue);
    tolua_variable(tolua_S,"baseAttr",tolua_get_common__Weapon_baseAttr,tolua_set_common__Weapon_baseAttr);
    tolua_array(tolua_S,"holeBeads",tolua_get_serverLuaInterface_common_Weapon_holeBeads,tolua_set_serverLuaInterface_common_Weapon_holeBeads);
    tolua_variable(tolua_S,"holeState",tolua_get_common__Weapon_unsigned_holeState,tolua_set_common__Weapon_unsigned_holeState);
    tolua_variable(tolua_S,"reserve",tolua_get_common__Weapon_unsigned_reserve,tolua_set_common__Weapon_unsigned_reserve);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"DropItemData","common::DropItemData","",NULL);
   tolua_beginmodule(tolua_S,"DropItemData");
    tolua_variable(tolua_S,"series",tolua_get_common__DropItemData_series,tolua_set_common__DropItemData_series);
    tolua_variable(tolua_S,"ownerId",tolua_get_common__DropItemData_ownerId,tolua_set_common__DropItemData_ownerId);
    tolua_variable(tolua_S,"serverIdent",tolua_get_common__DropItemData_serverIdent,tolua_set_common__DropItemData_serverIdent);
    tolua_variable(tolua_S,"expireTime",tolua_get_common__DropItemData_unsigned_expireTime,tolua_set_common__DropItemData_unsigned_expireTime);
    tolua_variable(tolua_S,"itemId",tolua_get_common__DropItemData_itemId,tolua_set_common__DropItemData_itemId);
    tolua_variable(tolua_S,"quality",tolua_get_common__DropItemData_unsigned_quality,tolua_set_common__DropItemData_unsigned_quality);
    tolua_variable(tolua_S,"strong",tolua_get_common__DropItemData_unsigned_strong,tolua_set_common__DropItemData_unsigned_strong);
    tolua_variable(tolua_S,"itemCount",tolua_get_common__DropItemData_itemCount,tolua_set_common__DropItemData_itemCount);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"SendClientDropItem","common::SendClientDropItem","",NULL);
   tolua_beginmodule(tolua_S,"SendClientDropItem");
    tolua_variable(tolua_S,"series",tolua_get_common__SendClientDropItem_series,tolua_set_common__SendClientDropItem_series);
    tolua_variable(tolua_S,"serverIdent",tolua_get_common__SendClientDropItem_serverIdent,tolua_set_common__SendClientDropItem_serverIdent);
    tolua_variable(tolua_S,"itemId",tolua_get_common__SendClientDropItem_itemId,tolua_set_common__SendClientDropItem_itemId);
    tolua_variable(tolua_S,"itemCount",tolua_get_common__SendClientDropItem_unsigned_itemCount,tolua_set_common__SendClientDropItem_unsigned_itemCount);
    tolua_variable(tolua_S,"quality",tolua_get_common__SendClientDropItem_unsigned_quality,tolua_set_common__SendClientDropItem_unsigned_quality);
    tolua_variable(tolua_S,"strong",tolua_get_common__SendClientDropItem_unsigned_strong,tolua_set_common__SendClientDropItem_unsigned_strong);
    tolua_variable(tolua_S,"x",tolua_get_common__SendClientDropItem_x,tolua_set_common__SendClientDropItem_x);
    tolua_variable(tolua_S,"y",tolua_get_common__SendClientDropItem_y,tolua_set_common__SendClientDropItem_y);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ItemAccessor","ItemAccessor","Object",tolua_collect_ItemAccessor);
  #else
  tolua_cclass(tolua_S,"ItemAccessor","ItemAccessor","Object",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ItemAccessor");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_ItemAccessor_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_ItemAccessor_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_ItemAccessor_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_ItemAccessor_delete00);
   tolua_function(tolua_S,"getItem",tolua_serverLuaInterface_ItemAccessor_getItem00);
   tolua_function(tolua_S,"getItemByName",tolua_serverLuaInterface_ItemAccessor_getItemByName00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"PlayerDataAccessor","PlayerDataAccessor","lib::memory::Object",tolua_collect_PlayerDataAccessor);
  #else
  tolua_cclass(tolua_S,"PlayerDataAccessor","PlayerDataAccessor","lib::memory::Object",NULL);
  #endif
  tolua_beginmodule(tolua_S,"PlayerDataAccessor");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_PlayerDataAccessor_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_PlayerDataAccessor_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_PlayerDataAccessor_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_PlayerDataAccessor_delete00);
   tolua_function(tolua_S,"getLevel",tolua_serverLuaInterface_PlayerDataAccessor_getLevel00);
   tolua_function(tolua_S,"loadConfig",tolua_serverLuaInterface_PlayerDataAccessor_loadConfig00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"WeaponAccessor","WeaponAccessor","lib::memory::Object",tolua_collect_WeaponAccessor);
  #else
  tolua_cclass(tolua_S,"WeaponAccessor","WeaponAccessor","lib::memory::Object",NULL);
  #endif
  tolua_beginmodule(tolua_S,"WeaponAccessor");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_WeaponAccessor_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_WeaponAccessor_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_WeaponAccessor_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_WeaponAccessor_delete00);
   tolua_function(tolua_S,"getBeadById",tolua_serverLuaInterface_WeaponAccessor_getBeadById00);
   tolua_function(tolua_S,"getWeaponById",tolua_serverLuaInterface_WeaponAccessor_getWeaponById00);
   tolua_function(tolua_S,"getBeadQuality",tolua_serverLuaInterface_WeaponAccessor_getBeadQuality00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Scene","Scene","",tolua_collect_Scene);
  #else
  tolua_cclass(tolua_S,"Scene","Scene","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Scene");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_Scene_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_Scene_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_Scene_new00_local);
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_Scene_new01);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_Scene_new01_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_Scene_new01_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_Scene_delete00);
   tolua_function(tolua_S,"destory",tolua_serverLuaInterface_Scene_destory00);
   tolua_function(tolua_S,"reset",tolua_serverLuaInterface_Scene_reset00);
   tolua_function(tolua_S,"initWithSceneId",tolua_serverLuaInterface_Scene_initWithSceneId00);
   tolua_function(tolua_S,"getNpcNode",tolua_serverLuaInterface_Scene_getNpcNode00);
   tolua_function(tolua_S,"setNpcNode",tolua_serverLuaInterface_Scene_setNpcNode00);
   tolua_function(tolua_S,"getpSceneStruct",tolua_serverLuaInterface_Scene_getpSceneStruct00);
   tolua_function(tolua_S,"getSceneMap",tolua_serverLuaInterface_Scene_getSceneMap00);
   tolua_function(tolua_S,"isStaticScene",tolua_serverLuaInterface_Scene_isStaticScene00);
   tolua_variable(tolua_S,"m_nSceneId",tolua_get_Scene_m_nSceneId,tolua_set_Scene_m_nSceneId);
   tolua_variable(tolua_S,"m_nMapWidth",tolua_get_Scene_m_nMapWidth,tolua_set_Scene_m_nMapWidth);
   tolua_variable(tolua_S,"m_nMapHeight",tolua_get_Scene_m_nMapHeight,tolua_set_Scene_m_nMapHeight);
   tolua_variable(tolua_S,"m_pMapGrid",tolua_get_Scene_m_pMapGrid_ptr,tolua_set_Scene_m_pMapGrid_ptr);
   tolua_variable(tolua_S,"m_pSceneManager",tolua_get_Scene_m_pSceneManager_ptr,tolua_set_Scene_m_pSceneManager_ptr);
   tolua_variable(tolua_S,"m_pSceneStruct",tolua_get_Scene_m_pSceneStruct_ptr,tolua_set_Scene_m_pSceneStruct_ptr);
   tolua_variable(tolua_S,"m_pSceneMap",tolua_get_Scene_m_pSceneMap_ptr,tolua_set_Scene_m_pSceneMap_ptr);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"DuplicateManager","DuplicateManager","",tolua_collect_DuplicateManager);
  #else
  tolua_cclass(tolua_S,"DuplicateManager","DuplicateManager","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"DuplicateManager");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_DuplicateManager_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_DuplicateManager_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_DuplicateManager_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_DuplicateManager_delete00);
   tolua_function(tolua_S,"destroy",tolua_serverLuaInterface_DuplicateManager_destroy00);
   tolua_function(tolua_S,"init",tolua_serverLuaInterface_DuplicateManager_init00);
   tolua_function(tolua_S,"createDuplicate",tolua_serverLuaInterface_DuplicateManager_createDuplicate00);
   tolua_function(tolua_S,"getDuplicateByGuid",tolua_serverLuaInterface_DuplicateManager_getDuplicateByGuid00);
   tolua_function(tolua_S,"getSceneByDuplicateGuidAndSceneId",tolua_serverLuaInterface_DuplicateManager_getSceneByDuplicateGuidAndSceneId00);
   tolua_function(tolua_S,"OnRoutine",tolua_serverLuaInterface_DuplicateManager_OnRoutine00);
   tolua_function(tolua_S,"testScene",tolua_serverLuaInterface_DuplicateManager_testScene00);
   tolua_variable(tolua_S,"m_dynamicGuid",tolua_get_DuplicateManager_m_dynamicGuid,tolua_set_DuplicateManager_m_dynamicGuid);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"SceneManager","SceneManager","",tolua_collect_SceneManager);
  #else
  tolua_cclass(tolua_S,"SceneManager","SceneManager","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"SceneManager");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_SceneManager_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_SceneManager_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_SceneManager_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_SceneManager_delete00);
   tolua_function(tolua_S,"init",tolua_serverLuaInterface_SceneManager_init00);
   tolua_function(tolua_S,"initScenes",tolua_serverLuaInterface_SceneManager_initScenes00);
   tolua_function(tolua_S,"destroyScenes",tolua_serverLuaInterface_SceneManager_destroyScenes00);
   tolua_function(tolua_S,"addScene",tolua_serverLuaInterface_SceneManager_addScene00);
   tolua_function(tolua_S,"getSceneByID",tolua_serverLuaInterface_SceneManager_getSceneByID00);
   tolua_function(tolua_S,"popSceneBySceneID",tolua_serverLuaInterface_SceneManager_popSceneBySceneID00);
   tolua_function(tolua_S,"addPlayer",tolua_serverLuaInterface_SceneManager_addPlayer00);
   tolua_function(tolua_S,"delPlayer",tolua_serverLuaInterface_SceneManager_delPlayer00);
   tolua_variable(tolua_S,"m_playerNum",tolua_get_SceneManager_m_playerNum,tolua_set_SceneManager_m_playerNum);
   tolua_variable(tolua_S,"m_lastPlayerLeaveTime",tolua_get_SceneManager_unsigned_m_lastPlayerLeaveTime,tolua_set_SceneManager_unsigned_m_lastPlayerLeaveTime);
   tolua_variable(tolua_S,"m_playerList",tolua_get_SceneManager_m_playerList,tolua_set_SceneManager_m_playerList);
   tolua_variable(tolua_S,"m_duplicateName",tolua_get_SceneManager_m_duplicateName,tolua_set_SceneManager_m_duplicateName);
   tolua_variable(tolua_S,"m_duplicateId",tolua_get_SceneManager_m_duplicateId,tolua_set_SceneManager_m_duplicateId);
   tolua_variable(tolua_S,"m_Guid",tolua_get_SceneManager_m_Guid,tolua_set_SceneManager_m_Guid);
   tolua_variable(tolua_S,"m_firstSceneX",tolua_get_SceneManager_m_firstSceneX,tolua_set_SceneManager_m_firstSceneX);
   tolua_variable(tolua_S,"m_firstSceneY",tolua_get_SceneManager_m_firstSceneY,tolua_set_SceneManager_m_firstSceneY);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"eUnknown",eUnknown);
  tolua_constant(tolua_S,"eActor",eActor);
  tolua_constant(tolua_S,"eNormalMonster",eNormalMonster);
  tolua_constant(tolua_S,"eNPC",eNPC);
  tolua_constant(tolua_S,"ePlayer",ePlayer);
  tolua_constant(tolua_S,"esDescDirty",esDescDirty);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CEntity","CEntity","CBaseObject",tolua_collect_CEntity);
  #else
  tolua_cclass(tolua_S,"CEntity","CEntity","CBaseObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CEntity");
   tolua_cclass(tolua_S,"ViewStruct","CEntity::ViewStruct","",NULL);
   tolua_beginmodule(tolua_S,"ViewStruct");
    tolua_variable(tolua_S,"mask",tolua_get_CEntity__ViewStruct_unsigned_mask,tolua_set_CEntity__ViewStruct_unsigned_mask);
    tolua_variable(tolua_S,"pEntity",tolua_get_CEntity__ViewStruct_pEntity_ptr,tolua_set_CEntity__ViewStruct_pEntity_ptr);
   tolua_endmodule(tolua_S);
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_CEntity_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_CEntity_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_CEntity_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_CEntity_delete00);
   tolua_function(tolua_S,"init",tolua_serverLuaInterface_CEntity_init00);
   tolua_function(tolua_S,"run",tolua_serverLuaInterface_CEntity_run00);
   tolua_function(tolua_S,"disappear",tolua_serverLuaInterface_CEntity_disappear00);
   tolua_function(tolua_S,"getPlayerIndex",tolua_serverLuaInterface_CEntity_getPlayerIndex00);
   tolua_function(tolua_S,"findEntity",tolua_serverLuaInterface_CEntity_findEntity00);
   tolua_function(tolua_S,"getRandomKey",tolua_serverLuaInterface_CEntity_getRandomKey00);
   tolua_function(tolua_S,"setScene",tolua_serverLuaInterface_CEntity_setScene00);
   tolua_function(tolua_S,"setXY",tolua_serverLuaInterface_CEntity_setXY00);
   tolua_function(tolua_S,"getEntityDescription",tolua_serverLuaInterface_CEntity_getEntityDescription00);
   tolua_variable(tolua_S,"m_EntityId",tolua_get_CEntity_m_EntityId,tolua_set_CEntity_m_EntityId);
   tolua_variable(tolua_S,"m_nX",tolua_get_CEntity_m_nX,tolua_set_CEntity_m_nX);
   tolua_variable(tolua_S,"m_nY",tolua_get_CEntity_m_nY,tolua_set_CEntity_m_nY);
   tolua_variable(tolua_S,"m_dwStateMasks",tolua_get_CEntity_unsigned_m_dwStateMasks,tolua_set_CEntity_unsigned_m_dwStateMasks);
   tolua_variable(tolua_S,"m_btType",tolua_get_CEntity_unsigned_m_btType,tolua_set_CEntity_unsigned_m_btType);
   tolua_variable(tolua_S,"m_btDirection",tolua_get_CEntity_m_btDirection,tolua_set_CEntity_m_btDirection);
   tolua_variable(tolua_S,"m_boDisappeared",tolua_get_CEntity_m_boDisappeared,tolua_set_CEntity_m_boDisappeared);
   tolua_variable(tolua_S,"m_boDead",tolua_get_CEntity_m_boDead,tolua_set_CEntity_m_boDead);
   tolua_variable(tolua_S,"m_boGodMode",tolua_get_CEntity_m_boGodMode,tolua_set_CEntity_m_boGodMode);
   tolua_variable(tolua_S,"_______reserve",tolua_get_CEntity________reserve,tolua_set_CEntity________reserve);
   tolua_variable(tolua_S,"m_wEntityBody",tolua_get_CEntity_unsigned_m_wEntityBody,tolua_set_CEntity_unsigned_m_wEntityBody);
   tolua_variable(tolua_S,"m_ImpactRect",tolua_get_CEntity_m_ImpactRect,tolua_set_CEntity_m_ImpactRect);
   tolua_variable(tolua_S,"m_pScene",tolua_get_CEntity_m_pScene_ptr,tolua_set_CEntity_m_pScene_ptr);
   tolua_variable(tolua_S,"m_dwDieTick",tolua_get_CEntity_m_dwDieTick,tolua_set_CEntity_m_dwDieTick);
   tolua_variable(tolua_S,"m_dwDisappearTick",tolua_get_CEntity_m_dwDisappearTick,tolua_set_CEntity_m_dwDisappearTick);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CDoerAbility","CDoerAbility","CDoerUnit",tolua_collect_CDoerAbility);
  #else
  tolua_cclass(tolua_S,"CDoerAbility","CDoerAbility","CDoerUnit",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CDoerAbility");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_CDoerAbility_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_CDoerAbility_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_CDoerAbility_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_CDoerAbility_delete00);
   tolua_function(tolua_S,"recalcAbility",tolua_serverLuaInterface_CDoerAbility_recalcAbility00);
   tolua_function(tolua_S,"sendAbility",tolua_serverLuaInterface_CDoerAbility_sendAbility00);
   tolua_variable(tolua_S,"m_nHP",tolua_get_CDoerAbility_m_nHP,tolua_set_CDoerAbility_m_nHP);
   tolua_variable(tolua_S,"m_nMP",tolua_get_CDoerAbility_m_nMP,tolua_set_CDoerAbility_m_nMP);
   tolua_variable(tolua_S,"m_wBody",tolua_get_CDoerAbility_unsigned_m_wBody,tolua_set_CDoerAbility_unsigned_m_wBody);
   tolua_variable(tolua_S,"m_wWeapon",tolua_get_CDoerAbility_unsigned_m_wWeapon,tolua_set_CDoerAbility_unsigned_m_wWeapon);
   tolua_variable(tolua_S,"m_wMount",tolua_get_CDoerAbility_unsigned_m_wMount,tolua_set_CDoerAbility_unsigned_m_wMount);
   tolua_variable(tolua_S,"__DoerAbilData__",tolua_get_CDoerAbility___DoerAbilData__,NULL);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ItemAttributeGroup","ItemAttributeGroup","",NULL);
  tolua_beginmodule(tolua_S,"ItemAttributeGroup");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"DoerAbilData","DoerAbilData","",tolua_collect_DoerAbilData);
  #else
  tolua_cclass(tolua_S,"DoerAbilData","DoerAbilData","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"DoerAbilData");
   tolua_variable(tolua_S,"biLi",tolua_get_DoerAbilData_biLi,tolua_set_DoerAbilData_biLi);
   tolua_variable(tolua_S,"lingQiao",tolua_get_DoerAbilData_lingQiao,tolua_set_DoerAbilData_lingQiao);
   tolua_variable(tolua_S,"tiPo",tolua_get_DoerAbilData_tiPo,tolua_set_DoerAbilData_tiPo);
   tolua_variable(tolua_S,"neiXi",tolua_get_DoerAbilData_neiXi,tolua_set_DoerAbilData_neiXi);
   tolua_variable(tolua_S,"gangQi",tolua_get_DoerAbilData_gangQi,tolua_set_DoerAbilData_gangQi);
   tolua_variable(tolua_S,"waiGong",tolua_get_DoerAbilData_waiGong,tolua_set_DoerAbilData_waiGong);
   tolua_variable(tolua_S,"neiGong",tolua_get_DoerAbilData_neiGong,tolua_set_DoerAbilData_neiGong);
   tolua_variable(tolua_S,"waiFang",tolua_get_DoerAbilData_waiFang,tolua_set_DoerAbilData_waiFang);
   tolua_variable(tolua_S,"neiFang",tolua_get_DoerAbilData_neiFang,tolua_set_DoerAbilData_neiFang);
   tolua_variable(tolua_S,"waiFangCT",tolua_get_DoerAbilData_waiFangCT,tolua_set_DoerAbilData_waiFangCT);
   tolua_variable(tolua_S,"neiFangCT",tolua_get_DoerAbilData_neiFangCT,tolua_set_DoerAbilData_neiFangCT);
   tolua_variable(tolua_S,"qiXue",tolua_get_DoerAbilData_qiXue,tolua_set_DoerAbilData_qiXue);
   tolua_variable(tolua_S,"neiLi",tolua_get_DoerAbilData_neiLi,tolua_set_DoerAbilData_neiLi);
   tolua_variable(tolua_S,"waiBao",tolua_get_DoerAbilData_waiBao,tolua_set_DoerAbilData_waiBao);
   tolua_variable(tolua_S,"neiBao",tolua_get_DoerAbilData_neiBao,tolua_set_DoerAbilData_neiBao);
   tolua_variable(tolua_S,"kangWaiBao",tolua_get_DoerAbilData_kangWaiBao,tolua_set_DoerAbilData_kangWaiBao);
   tolua_variable(tolua_S,"kangNeiBao",tolua_get_DoerAbilData_kangNeiBao,tolua_set_DoerAbilData_kangNeiBao);
   tolua_variable(tolua_S,"mingZhong",tolua_get_DoerAbilData_mingZhong,tolua_set_DoerAbilData_mingZhong);
   tolua_variable(tolua_S,"shanBi",tolua_get_DoerAbilData_shanBi,tolua_set_DoerAbilData_shanBi);
   tolua_variable(tolua_S,"hitSpeed",tolua_get_DoerAbilData_hitSpeed,tolua_set_DoerAbilData_hitSpeed);
   tolua_variable(tolua_S,"moveSpeed",tolua_get_DoerAbilData_moveSpeed,tolua_set_DoerAbilData_moveSpeed);
   tolua_variable(tolua_S,"qiXueHuiFu",tolua_get_DoerAbilData_qiXueHuiFu,tolua_set_DoerAbilData_qiXueHuiFu);
   tolua_variable(tolua_S,"neiLiHuiFu",tolua_get_DoerAbilData_neiLiHuiFu,tolua_set_DoerAbilData_neiLiHuiFu);
   tolua_variable(tolua_S,"fuYuan",tolua_get_DoerAbilData_fuYuan,tolua_set_DoerAbilData_fuYuan);
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_DoerAbilData_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_DoerAbilData_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_DoerAbilData_new00_local);
   tolua_function(tolua_S,"reset",tolua_serverLuaInterface_DoerAbilData_reset00);
   tolua_function(tolua_S,"calculateItemAttribute",tolua_serverLuaInterface_DoerAbilData_calculateItemAttribute00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CDoer","CDoer","CEntity",tolua_collect_CDoer);
  #else
  tolua_cclass(tolua_S,"CDoer","CDoer","CEntity",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CDoer");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_CDoer_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_CDoer_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_CDoer_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_CDoer_delete00);
   tolua_function(tolua_S,"run",tolua_serverLuaInterface_CDoer_run00);
   tolua_function(tolua_S,"initialize",tolua_serverLuaInterface_CDoer_initialize00);
   tolua_function(tolua_S,"disappear",tolua_serverLuaInterface_CDoer_disappear00);
   tolua_function(tolua_S,"setViewArea",tolua_serverLuaInterface_CDoer_setViewArea00);
   tolua_function(tolua_S,"getViewIndex",tolua_serverLuaInterface_CDoer_getViewIndex00);
   tolua_function(tolua_S,"getModule",tolua_serverLuaInterface_CDoer_getModule00);
   tolua_function(tolua_S,"sendMsg",tolua_serverLuaInterface_CDoer_sendMsg00);
   tolua_function(tolua_S,"broadcastMsg",tolua_serverLuaInterface_CDoer_broadcastMsg00);
   tolua_function(tolua_S,"broadcastPlayerMsg",tolua_serverLuaInterface_CDoer_broadcastPlayerMsg00);
   tolua_function(tolua_S,"gainExp",tolua_serverLuaInterface_CDoer_gainExp00);
   tolua_function(tolua_S,"winExp",tolua_serverLuaInterface_CDoer_winExp00);
   tolua_variable(tolua_S,"m_sName",tolua_get_CDoer_m_sName,tolua_set_CDoer_m_sName);
   tolua_variable(tolua_S,"m_nLevel",tolua_get_CDoer_m_nLevel,tolua_set_CDoer_m_nLevel);
   tolua_variable(tolua_S,"m_btAttackType",tolua_get_CDoer_unsigned_m_btAttackType,tolua_set_CDoer_unsigned_m_btAttackType);
   tolua_variable(tolua_S,"m_btVipLevel",tolua_get_CDoer_unsigned_m_btVipLevel,tolua_set_CDoer_unsigned_m_btVipLevel);
   tolua_variable(tolua_S,"m_wMonId",tolua_get_CDoer_unsigned_m_wMonId,tolua_set_CDoer_unsigned_m_wMonId);
   tolua_variable(tolua_S,"m_nExp",tolua_get_CDoer_m_nExp,tolua_set_CDoer_m_nExp);
   tolua_variable(tolua_S,"m_nExpMax",tolua_get_CDoer_m_nExpMax,tolua_set_CDoer_m_nExpMax);
   tolua_variable(tolua_S,"m_nMonExp",tolua_get_CDoer_m_nMonExp,tolua_set_CDoer_m_nMonExp);
   tolua_variable(tolua_S,"m_wMoveSpeed",tolua_get_CDoer_unsigned_m_wMoveSpeed,tolua_set_CDoer_unsigned_m_wMoveSpeed);
   tolua_variable(tolua_S,"m_wAttackInterval",tolua_get_CDoer_unsigned_m_wAttackInterval,tolua_set_CDoer_unsigned_m_wAttackInterval);
   tolua_variable(tolua_S,"m_wAttackTime",tolua_get_CDoer_unsigned_m_wAttackTime,tolua_set_CDoer_unsigned_m_wAttackTime);
   tolua_variable(tolua_S,"_____reserve",tolua_get_CDoer_unsigned______reserve,tolua_set_CDoer_unsigned______reserve);
   tolua_variable(tolua_S,"m_nBornX",tolua_get_CDoer_m_nBornX,tolua_set_CDoer_m_nBornX);
   tolua_variable(tolua_S,"m_nBornY",tolua_get_CDoer_m_nBornY,tolua_set_CDoer_m_nBornY);
   tolua_variable(tolua_S,"m_Abil",tolua_get_CDoer_m_Abil,tolua_set_CDoer_m_Abil);
   tolua_variable(tolua_S,"m_Battle",tolua_get_CDoer_m_Battle,tolua_set_CDoer_m_Battle);
   tolua_variable(tolua_S,"m_ViewList",tolua_get_CDoer_m_ViewList,tolua_set_CDoer_m_ViewList);
   tolua_variable(tolua_S,"m_pFirstMsg",tolua_get_CDoer_m_pFirstMsg_ptr,tolua_set_CDoer_m_pFirstMsg_ptr);
   tolua_variable(tolua_S,"m_pLastMsg",tolua_get_CDoer_m_pLastMsg_ptr,tolua_set_CDoer_m_pLastMsg_ptr);
   tolua_variable(tolua_S,"m_dwNextUpdateViewTime",tolua_get_CDoer_m_dwNextUpdateViewTime,tolua_set_CDoer_m_dwNextUpdateViewTime);
   tolua_variable(tolua_S,"m_dwLastRunTick",tolua_get_CDoer_m_dwLastRunTick,tolua_set_CDoer_m_dwLastRunTick);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CPlayerWeapon","CPlayerWeapon","CDoerUnit",tolua_collect_CPlayerWeapon);
  #else
  tolua_cclass(tolua_S,"CPlayerWeapon","CPlayerWeapon","CDoerUnit",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CPlayerWeapon");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_CPlayerWeapon_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_CPlayerWeapon_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_CPlayerWeapon_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_CPlayerWeapon_delete00);
   tolua_function(tolua_S,"init",tolua_serverLuaInterface_CPlayerWeapon_init00);
   tolua_function(tolua_S,"loadData",tolua_serverLuaInterface_CPlayerWeapon_loadData00);
   tolua_function(tolua_S,"saveData",tolua_serverLuaInterface_CPlayerWeapon_saveData00);
   tolua_function(tolua_S,"dispatchRecvPacket",tolua_serverLuaInterface_CPlayerWeapon_dispatchRecvPacket00);
   tolua_function(tolua_S,"dispatchMsg",tolua_serverLuaInterface_CPlayerWeapon_dispatchMsg00);
   tolua_function(tolua_S,"offline",tolua_serverLuaInterface_CPlayerWeapon_offline00);
   tolua_function(tolua_S,"addBead",tolua_serverLuaInterface_CPlayerWeapon_addBead00);
   tolua_function(tolua_S,"delBead",tolua_serverLuaInterface_CPlayerWeapon_delBead00);
   tolua_function(tolua_S,"findBead",tolua_serverLuaInterface_CPlayerWeapon_findBead00);
   tolua_function(tolua_S,"clearWeaponInfo",tolua_serverLuaInterface_CPlayerWeapon_clearWeaponInfo00);
   tolua_function(tolua_S,"clearBeadList",tolua_serverLuaInterface_CPlayerWeapon_clearBeadList00);
   tolua_function(tolua_S,"sendWeaponFullInfo",tolua_serverLuaInterface_CPlayerWeapon_sendWeaponFullInfo00);
   tolua_function(tolua_S,"sendWeaponInfo",tolua_serverLuaInterface_CPlayerWeapon_sendWeaponInfo00);
   tolua_function(tolua_S,"sendAddBead",tolua_serverLuaInterface_CPlayerWeapon_sendAddBead00);
   tolua_function(tolua_S,"sendDelBead",tolua_serverLuaInterface_CPlayerWeapon_sendDelBead00);
   tolua_function(tolua_S,"sendBeadEat",tolua_serverLuaInterface_CPlayerWeapon_sendBeadEat00);
   tolua_function(tolua_S,"sendWeaponOperateRes",tolua_serverLuaInterface_CPlayerWeapon_sendWeaponOperateRes00);
   tolua_variable(tolua_S,"m_Weapon",tolua_get_CPlayerWeapon_m_Weapon,tolua_set_CPlayerWeapon_m_Weapon);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CPlayer","CPlayer","CDoer",tolua_collect_CPlayer);
  #else
  tolua_cclass(tolua_S,"CPlayer","CPlayer","CDoer",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CPlayer");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_CPlayer_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_CPlayer_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_CPlayer_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_CPlayer_delete00);
   tolua_function(tolua_S,"run",tolua_serverLuaInterface_CPlayer_run00);
   tolua_function(tolua_S,"initialize",tolua_serverLuaInterface_CPlayer_initialize00);
   tolua_function(tolua_S,"setIdentity",tolua_serverLuaInterface_CPlayer_setIdentity00);
   tolua_function(tolua_S,"loadData",tolua_serverLuaInterface_CPlayer_loadData00);
   tolua_function(tolua_S,"saveData",tolua_serverLuaInterface_CPlayer_saveData00);
   tolua_function(tolua_S,"close",tolua_serverLuaInterface_CPlayer_close00);
   tolua_function(tolua_S,"readyForRun",tolua_serverLuaInterface_CPlayer_readyForRun00);
   tolua_function(tolua_S,"sendSceneInfo",tolua_serverLuaInterface_CPlayer_sendSceneInfo00);
   tolua_function(tolua_S,"sendCoinCount",tolua_serverLuaInterface_CPlayer_sendCoinCount00);
   tolua_function(tolua_S,"sendGameGoldCount",tolua_serverLuaInterface_CPlayer_sendGameGoldCount00);
   tolua_function(tolua_S,"sendEntityAppear",tolua_serverLuaInterface_CPlayer_sendEntityAppear00);
   tolua_function(tolua_S,"getModule",tolua_serverLuaInterface_CPlayer_getModule00);
   tolua_function(tolua_S,"allocSendPacket",tolua_serverLuaInterface_CPlayer_allocSendPacket00);
   tolua_function(tolua_S,"gotoBornScene",tolua_serverLuaInterface_CPlayer_gotoBornScene00);
   tolua_function(tolua_S,"addCoin",tolua_serverLuaInterface_CPlayer_addCoin00);
   tolua_function(tolua_S,"decCoin",tolua_serverLuaInterface_CPlayer_decCoin00);
   tolua_variable(tolua_S,"m_nPlayerIndex",tolua_get_CPlayer_m_nPlayerIndex,tolua_set_CPlayer_m_nPlayerIndex);
   tolua_variable(tolua_S,"m_sAccount",tolua_get_CPlayer_m_sAccount,tolua_set_CPlayer_m_sAccount);
   tolua_variable(tolua_S,"m_nAccountId",tolua_get_CPlayer_m_nAccountId,tolua_set_CPlayer_m_nAccountId);
   tolua_variable(tolua_S,"m_nCreateTime",tolua_get_CPlayer_m_nCreateTime,tolua_set_CPlayer_m_nCreateTime);
   tolua_variable(tolua_S,"m_pGate",tolua_get_CPlayer_m_pGate_ptr,tolua_set_CPlayer_m_pGate_ptr);
   tolua_variable(tolua_S,"m_llSocket",tolua_get_CPlayer_m_llSocket,tolua_set_CPlayer_m_llSocket);
   tolua_variable(tolua_S,"m_nGateIndex",tolua_get_CPlayer_m_nGateIndex,tolua_set_CPlayer_m_nGateIndex);
   tolua_variable(tolua_S,"m_nGateUserIndex",tolua_get_CPlayer_m_nGateUserIndex,tolua_set_CPlayer_m_nGateUserIndex);
   tolua_variable(tolua_S,"m_nGateVerify",tolua_get_CPlayer_m_nGateVerify,tolua_set_CPlayer_m_nGateVerify);
   tolua_variable(tolua_S,"m_nClientAddr",tolua_get_CPlayer_m_nClientAddr,tolua_set_CPlayer_m_nClientAddr);
   tolua_variable(tolua_S,"m_dwEnterTick",tolua_get_CPlayer_m_dwEnterTick,tolua_set_CPlayer_m_dwEnterTick);
   tolua_variable(tolua_S,"m_nEnterGameTime",tolua_get_CPlayer_m_nEnterGameTime,tolua_set_CPlayer_m_nEnterGameTime);
   tolua_variable(tolua_S,"m_dwClosedTick",tolua_get_CPlayer_m_dwClosedTick,tolua_set_CPlayer_m_dwClosedTick);
   tolua_variable(tolua_S,"m_dwInvalidTick",tolua_get_CPlayer_m_dwInvalidTick,tolua_set_CPlayer_m_dwInvalidTick);
   tolua_variable(tolua_S,"m_dwNextSaveDataTick",tolua_get_CPlayer_m_dwNextSaveDataTick,tolua_set_CPlayer_m_dwNextSaveDataTick);
   tolua_variable(tolua_S,"m_boValid",tolua_get_CPlayer_m_boValid,tolua_set_CPlayer_m_boValid);
   tolua_variable(tolua_S,"_____________reserve0",tolua_get_CPlayer______________reserve0,tolua_set_CPlayer______________reserve0);
   tolua_variable(tolua_S,"m_boIsNewPlayer",tolua_get_CPlayer_m_boIsNewPlayer,tolua_set_CPlayer_m_boIsNewPlayer);
   tolua_variable(tolua_S,"m_btGender",tolua_get_CPlayer_unsigned_m_btGender,tolua_set_CPlayer_unsigned_m_btGender);
   tolua_variable(tolua_S,"m_btJob",tolua_get_CPlayer_unsigned_m_btJob,tolua_set_CPlayer_unsigned_m_btJob);
   tolua_variable(tolua_S,"m_btGMLevel",tolua_get_CPlayer_unsigned_m_btGMLevel,tolua_set_CPlayer_unsigned_m_btGMLevel);
   tolua_variable(tolua_S,"m_GuildId",tolua_get_CPlayer_m_GuildId,tolua_set_CPlayer_m_GuildId);
   tolua_variable(tolua_S,"m_pGuild",tolua_get_CPlayer_m_pGuild_ptr,tolua_set_CPlayer_m_pGuild_ptr);
   tolua_variable(tolua_S,"m_nCoin",tolua_get_CPlayer_m_nCoin,tolua_set_CPlayer_m_nCoin);
   tolua_variable(tolua_S,"m_nGameGold",tolua_get_CPlayer_m_nGameGold,tolua_set_CPlayer_m_nGameGold);
   tolua_variable(tolua_S,"m_DearId",tolua_get_CPlayer_m_DearId,tolua_set_CPlayer_m_DearId);
   tolua_variable(tolua_S,"m_sDearName",tolua_get_CPlayer_m_sDearName,tolua_set_CPlayer_m_sDearName);
   tolua_variable(tolua_S,"m_Bag",tolua_get_CPlayer_m_Bag,tolua_set_CPlayer_m_Bag);
   tolua_variable(tolua_S,"m_Equip",tolua_get_CPlayer_m_Equip,tolua_set_CPlayer_m_Equip);
   tolua_variable(tolua_S,"m_Quest",tolua_get_CPlayer_m_Quest,tolua_set_CPlayer_m_Quest);
   tolua_variable(tolua_S,"m_NpcTalk",tolua_get_CPlayer_m_NpcTalk,tolua_set_CPlayer_m_NpcTalk);
   tolua_variable(tolua_S,"m_playerChat",tolua_get_CPlayer_m_playerChat,tolua_set_CPlayer_m_playerChat);
   tolua_variable(tolua_S,"m_team",tolua_get_CPlayer_m_team,tolua_set_CPlayer_m_team);
   tolua_variable(tolua_S,"m_Weapon",tolua_get_CPlayer_m_Weapon,tolua_set_CPlayer_m_Weapon);
   tolua_variable(tolua_S,"m_nNetMsgIndex",tolua_get_CPlayer_m_nNetMsgIndex,tolua_set_CPlayer_m_nNetMsgIndex);
   tolua_variable(tolua_S,"m_StaticPosition",tolua_get_CPlayer_m_StaticPosition,tolua_set_CPlayer_m_StaticPosition);
   tolua_variable(tolua_S,"m_DynamicPosition",tolua_get_CPlayer_m_DynamicPosition,tolua_set_CPlayer_m_DynamicPosition);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CDoerUnit","CDoerUnit","",tolua_collect_CDoerUnit);
  #else
  tolua_cclass(tolua_S,"CDoerUnit","CDoerUnit","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CDoerUnit");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_CDoerUnit_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_CDoerUnit_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_CDoerUnit_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_CDoerUnit_delete00);
   tolua_function(tolua_S,"init",tolua_serverLuaInterface_CDoerUnit_init00);
   tolua_function(tolua_S,"loadData",tolua_serverLuaInterface_CDoerUnit_loadData00);
   tolua_function(tolua_S,"saveData",tolua_serverLuaInterface_CDoerUnit_saveData00);
   tolua_function(tolua_S,"dispatchRecvPacket",tolua_serverLuaInterface_CDoerUnit_dispatchRecvPacket00);
   tolua_function(tolua_S,"dispatchMsg",tolua_serverLuaInterface_CDoerUnit_dispatchMsg00);
   tolua_function(tolua_S,"offline",tolua_serverLuaInterface_CDoerUnit_offline00);
   tolua_variable(tolua_S,"m_pActor",tolua_get_CDoerUnit_m_pActor_ptr,tolua_set_CDoerUnit_m_pActor_ptr);
   tolua_variable(tolua_S,"m_pPlayer",tolua_get_CDoerUnit_m_pPlayer_ptr,tolua_set_CDoerUnit_m_pPlayer_ptr);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CTeam","CTeam","",NULL);
  tolua_beginmodule(tolua_S,"CTeam");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CPlayerTeam","CPlayerTeam","CDoerUnit",tolua_collect_CPlayerTeam);
  #else
  tolua_cclass(tolua_S,"CPlayerTeam","CPlayerTeam","CDoerUnit",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CPlayerTeam");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_CPlayerTeam_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_CPlayerTeam_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_CPlayerTeam_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_CPlayerTeam_delete00);
   tolua_function(tolua_S,"init",tolua_serverLuaInterface_CPlayerTeam_init00);
   tolua_function(tolua_S,"dispatchRecvPacket",tolua_serverLuaInterface_CPlayerTeam_dispatchRecvPacket00);
   tolua_variable(tolua_S,"m_pTeam",tolua_get_CPlayerTeam_m_pTeam_ptr,tolua_set_CPlayerTeam_m_pTeam_ptr);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CPlayerQuest","CPlayerQuest","CDoerUnit",tolua_collect_CPlayerQuest);
  #else
  tolua_cclass(tolua_S,"CPlayerQuest","CPlayerQuest","CDoerUnit",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CPlayerQuest");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_CPlayerQuest_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_CPlayerQuest_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_CPlayerQuest_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_CPlayerQuest_delete00);
   tolua_function(tolua_S,"init",tolua_serverLuaInterface_CPlayerQuest_init00);
   tolua_function(tolua_S,"loadData",tolua_serverLuaInterface_CPlayerQuest_loadData00);
   tolua_function(tolua_S,"saveData",tolua_serverLuaInterface_CPlayerQuest_saveData00);
   tolua_function(tolua_S,"dispatchRecvPacket",tolua_serverLuaInterface_CPlayerQuest_dispatchRecvPacket00);
   tolua_function(tolua_S,"sendQuestDatas",tolua_serverLuaInterface_CPlayerQuest_sendQuestDatas00);
   tolua_function(tolua_S,"sendAddAcceptQuest",tolua_serverLuaInterface_CPlayerQuest_sendAddAcceptQuest00);
   tolua_function(tolua_S,"sendAddCanAcceptQuest",tolua_serverLuaInterface_CPlayerQuest_sendAddCanAcceptQuest00);
   tolua_function(tolua_S,"sendUpdateAcceptQuest",tolua_serverLuaInterface_CPlayerQuest_sendUpdateAcceptQuest00);
   tolua_function(tolua_S,"sendDelAcceptQuest",tolua_serverLuaInterface_CPlayerQuest_sendDelAcceptQuest00);
   tolua_function(tolua_S,"sendDelCanAcceptQuest",tolua_serverLuaInterface_CPlayerQuest_sendDelCanAcceptQuest00);
   tolua_function(tolua_S,"checkCanAccept",tolua_serverLuaInterface_CPlayerQuest_checkCanAccept00);
   tolua_function(tolua_S,"checkCanSubmit",tolua_serverLuaInterface_CPlayerQuest_checkCanSubmit00);
   tolua_function(tolua_S,"acceptQuest",tolua_serverLuaInterface_CPlayerQuest_acceptQuest00);
   tolua_function(tolua_S,"submitQuest",tolua_serverLuaInterface_CPlayerQuest_submitQuest00);
   tolua_function(tolua_S,"getNpcQuestState",tolua_serverLuaInterface_CPlayerQuest_getNpcQuestState00);
   tolua_function(tolua_S,"updateQuestTarget",tolua_serverLuaInterface_CPlayerQuest_updateQuestTarget00);
   tolua_function(tolua_S,"questNormalHandler",tolua_serverLuaInterface_CPlayerQuest_questNormalHandler00);
   tolua_function(tolua_S,"addItem",tolua_serverLuaInterface_CPlayerQuest_addItem00);
   tolua_function(tolua_S,"delItem",tolua_serverLuaInterface_CPlayerQuest_delItem00);
   tolua_function(tolua_S,"actorDie",tolua_serverLuaInterface_CPlayerQuest_actorDie00);
   tolua_function(tolua_S,"clearAllQuest",tolua_serverLuaInterface_CPlayerQuest_clearAllQuest00);
   tolua_function(tolua_S,"addQuest",tolua_serverLuaInterface_CPlayerQuest_addQuest00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CPlayerNpcTalk","CPlayerNpcTalk","CDoerUnit",tolua_collect_CPlayerNpcTalk);
  #else
  tolua_cclass(tolua_S,"CPlayerNpcTalk","CPlayerNpcTalk","CDoerUnit",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CPlayerNpcTalk");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_CPlayerNpcTalk_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_CPlayerNpcTalk_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_CPlayerNpcTalk_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_CPlayerNpcTalk_delete00);
   tolua_function(tolua_S,"init",tolua_serverLuaInterface_CPlayerNpcTalk_init00);
   tolua_function(tolua_S,"loadData",tolua_serverLuaInterface_CPlayerNpcTalk_loadData00);
   tolua_function(tolua_S,"saveData",tolua_serverLuaInterface_CPlayerNpcTalk_saveData00);
   tolua_function(tolua_S,"dispatchRecvPacket",tolua_serverLuaInterface_CPlayerNpcTalk_dispatchRecvPacket00);
   tolua_function(tolua_S,"sendCloseTalk",tolua_serverLuaInterface_CPlayerNpcTalk_sendCloseTalk00);
   tolua_variable(tolua_S,"m_nTalkNpcID",tolua_get_CPlayerNpcTalk_m_nTalkNpcID,tolua_set_CPlayerNpcTalk_m_nTalkNpcID);
   tolua_variable(tolua_S,"m_npcName",tolua_get_CPlayerNpcTalk_m_npcName,tolua_set_CPlayerNpcTalk_m_npcName);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CPlayerEquip","CPlayerEquip","CDoerUnit",tolua_collect_CPlayerEquip);
  #else
  tolua_cclass(tolua_S,"CPlayerEquip","CPlayerEquip","CDoerUnit",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CPlayerEquip");
   tolua_constant(tolua_S,"epHat",CPlayerEquip::epHat);
   tolua_constant(tolua_S,"epDress",CPlayerEquip::epDress);
   tolua_constant(tolua_S,"epPants",CPlayerEquip::epPants);
   tolua_constant(tolua_S,"epBoot",CPlayerEquip::epBoot);
   tolua_constant(tolua_S,"EquipCount",CPlayerEquip::EquipCount);
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_CPlayerEquip_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_CPlayerEquip_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_CPlayerEquip_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_CPlayerEquip_delete00);
   tolua_function(tolua_S,"init",tolua_serverLuaInterface_CPlayerEquip_init00);
   tolua_function(tolua_S,"loadData",tolua_serverLuaInterface_CPlayerEquip_loadData00);
   tolua_function(tolua_S,"saveData",tolua_serverLuaInterface_CPlayerEquip_saveData00);
   tolua_function(tolua_S,"dispatchRecvPacket",tolua_serverLuaInterface_CPlayerEquip_dispatchRecvPacket00);
   tolua_function(tolua_S,"getEquipPos",tolua_serverLuaInterface_CPlayerEquip_getEquipPos00);
   tolua_function(tolua_S,"findEquipItem",tolua_serverLuaInterface_CPlayerEquip_findEquipItem00);
   tolua_function(tolua_S,"sendEquipItems",tolua_serverLuaInterface_CPlayerEquip_sendEquipItems00);
   tolua_array(tolua_S,"m_ItemList",tolua_get_serverLuaInterface_CPlayerEquip_m_ItemList,tolua_set_serverLuaInterface_CPlayerEquip_m_ItemList);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CDataPacketReader","CDataPacketReader","",NULL);
  tolua_beginmodule(tolua_S,"CDataPacketReader");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CDataPacket","CDataPacket","",NULL);
  tolua_beginmodule(tolua_S,"CDataPacket");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CDoerBattle","CDoerBattle","CDoerUnit",tolua_collect_CDoerBattle);
  #else
  tolua_cclass(tolua_S,"CDoerBattle","CDoerBattle","CDoerUnit",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CDoerBattle");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_CDoerBattle_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_CDoerBattle_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_CDoerBattle_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_CDoerBattle_delete00);
   tolua_function(tolua_S,"isRunning",tolua_serverLuaInterface_CDoerBattle_isRunning00);
   tolua_function(tolua_S,"startMove",tolua_serverLuaInterface_CDoerBattle_startMove00);
   tolua_function(tolua_S,"stopMove",tolua_serverLuaInterface_CDoerBattle_stopMove00);
   tolua_function(tolua_S,"startAttack",tolua_serverLuaInterface_CDoerBattle_startAttack00);
   tolua_function(tolua_S,"stopAttack",tolua_serverLuaInterface_CDoerBattle_stopAttack00);
   tolua_function(tolua_S,"sendSceneInfo",tolua_serverLuaInterface_CDoerBattle_sendSceneInfo00);
   tolua_function(tolua_S,"sendSyncPositionTo",tolua_serverLuaInterface_CDoerBattle_sendSyncPositionTo00);
   tolua_function(tolua_S,"sendStartRunTo",tolua_serverLuaInterface_CDoerBattle_sendStartRunTo00);
   tolua_function(tolua_S,"run",tolua_serverLuaInterface_CDoerBattle_run00);
   tolua_function(tolua_S,"damageHP",tolua_serverLuaInterface_CDoerBattle_damageHP00);
   tolua_function(tolua_S,"struck",tolua_serverLuaInterface_CDoerBattle_struck00);
   tolua_function(tolua_S,"die",tolua_serverLuaInterface_CDoerBattle_die00);
   tolua_function(tolua_S,"reviviscent",tolua_serverLuaInterface_CDoerBattle_reviviscent00);
   tolua_function(tolua_S,"outOfControl",tolua_serverLuaInterface_CDoerBattle_outOfControl00);
   tolua_function(tolua_S,"collapse",tolua_serverLuaInterface_CDoerBattle_collapse00);
   tolua_function(tolua_S,"decideDamageType",tolua_serverLuaInterface_CDoerBattle_decideDamageType00);
   tolua_function(tolua_S,"calcDamageValue",tolua_serverLuaInterface_CDoerBattle_calcDamageValue00);
   tolua_function(tolua_S,"calcNewPositionAtTime",tolua_serverLuaInterface_CDoerBattle_calcNewPositionAtTime00);
   tolua_function(tolua_S,"isAttackableActor",tolua_serverLuaInterface_CDoerBattle_isAttackableActor00);
   tolua_function(tolua_S,"setLastHiter",tolua_serverLuaInterface_CDoerBattle_setLastHiter00);
   tolua_function(tolua_S,"setTargetActor",tolua_serverLuaInterface_CDoerBattle_setTargetActor00);
   tolua_function(tolua_S,"setMoveTarget",tolua_serverLuaInterface_CDoerBattle_setMoveTarget00);
   tolua_function(tolua_S,"init",tolua_serverLuaInterface_CDoerBattle_init00);
   tolua_function(tolua_S,"loadData",tolua_serverLuaInterface_CDoerBattle_loadData00);
   tolua_function(tolua_S,"dispatchRecvPacket",tolua_serverLuaInterface_CDoerBattle_dispatchRecvPacket00);
   tolua_function(tolua_S,"dispatchMsg",tolua_serverLuaInterface_CDoerBattle_dispatchMsg00);
   tolua_function(tolua_S,"offline",tolua_serverLuaInterface_CDoerBattle_offline00);
   tolua_variable(tolua_S,"m_dwMonFlags",tolua_get_CDoerBattle_unsigned_m_dwMonFlags,tolua_set_CDoerBattle_unsigned_m_dwMonFlags);
   tolua_variable(tolua_S,"m_nTargetX",tolua_get_CDoerBattle_m_nTargetX,tolua_set_CDoerBattle_m_nTargetX);
   tolua_variable(tolua_S,"m_nTargetY",tolua_get_CDoerBattle_m_nTargetY,tolua_set_CDoerBattle_m_nTargetY);
   tolua_variable(tolua_S,"m_boReturning",tolua_get_CDoerBattle_m_boReturning,tolua_set_CDoerBattle_m_boReturning);
   tolua_variable(tolua_S,"___________reserve",tolua_get_CDoerBattle____________reserve,tolua_set_CDoerBattle____________reserve);
   tolua_variable(tolua_S,"m_pTargetActor",tolua_get_CDoerBattle_m_pTargetActor_ptr,tolua_set_CDoerBattle_m_pTargetActor_ptr);
   tolua_variable(tolua_S,"m_pLastHiter",tolua_get_CDoerBattle_m_pLastHiter_ptr,tolua_set_CDoerBattle_m_pLastHiter_ptr);
   tolua_variable(tolua_S,"m_dwLastHiterTimeOut",tolua_get_CDoerBattle_m_dwLastHiterTimeOut,tolua_set_CDoerBattle_m_dwLastHiterTimeOut);
   tolua_variable(tolua_S,"m_dwNextSearchTargetTick",tolua_get_CDoerBattle_m_dwNextSearchTargetTick,tolua_set_CDoerBattle_m_dwNextSearchTargetTick);
   tolua_variable(tolua_S,"m_dwMonNormalAttackPrepareEndTick",tolua_get_CDoerBattle_m_dwMonNormalAttackPrepareEndTick,tolua_set_CDoerBattle_m_dwMonNormalAttackPrepareEndTick);
   tolua_variable(tolua_S,"m_dwMonNormalAttackTakeEffectTick",tolua_get_CDoerBattle_m_dwMonNormalAttackTakeEffectTick,tolua_set_CDoerBattle_m_dwMonNormalAttackTakeEffectTick);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CFItem","CFItem","",NULL);
  tolua_beginmodule(tolua_S,"CFItem");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CPlayerBag","CPlayerBag","CDoerUnit",tolua_collect_CPlayerBag);
  #else
  tolua_cclass(tolua_S,"CPlayerBag","CPlayerBag","CDoerUnit",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CPlayerBag");
   tolua_function(tolua_S,"new",tolua_serverLuaInterface_CPlayerBag_new00);
   tolua_function(tolua_S,"new_local",tolua_serverLuaInterface_CPlayerBag_new00_local);
   tolua_function(tolua_S,".call",tolua_serverLuaInterface_CPlayerBag_new00_local);
   tolua_function(tolua_S,"delete",tolua_serverLuaInterface_CPlayerBag_delete00);
   tolua_function(tolua_S,"init",tolua_serverLuaInterface_CPlayerBag_init00);
   tolua_function(tolua_S,"loadData",tolua_serverLuaInterface_CPlayerBag_loadData00);
   tolua_function(tolua_S,"saveData",tolua_serverLuaInterface_CPlayerBag_saveData00);
   tolua_function(tolua_S,"getItem",tolua_serverLuaInterface_CPlayerBag_getItem00);
   tolua_function(tolua_S,"getItem",tolua_serverLuaInterface_CPlayerBag_getItem01);
   tolua_function(tolua_S,"getItemCount",tolua_serverLuaInterface_CPlayerBag_getItemCount00);
   tolua_function(tolua_S,"addItem",tolua_serverLuaInterface_CPlayerBag_addItem00);
   tolua_function(tolua_S,"delItem",tolua_serverLuaInterface_CPlayerBag_delItem00);
   tolua_function(tolua_S,"addItem",tolua_serverLuaInterface_CPlayerBag_addItem01);
   tolua_function(tolua_S,"delItem",tolua_serverLuaInterface_CPlayerBag_delItem01);
   tolua_function(tolua_S,"getCanAddItemCount",tolua_serverLuaInterface_CPlayerBag_getCanAddItemCount00);
   tolua_function(tolua_S,"getCanOverlapItem",tolua_serverLuaInterface_CPlayerBag_getCanOverlapItem00);
   tolua_function(tolua_S,"initUserItemFromStdItem",tolua_serverLuaInterface_CPlayerBag_initUserItemFromStdItem00);
   tolua_function(tolua_S,"sendBagItems",tolua_serverLuaInterface_CPlayerBag_sendBagItems00);
   tolua_variable(tolua_S,"m_btBagCurSize",tolua_get_CPlayerBag_unsigned_m_btBagCurSize,tolua_set_CPlayerBag_unsigned_m_btBagCurSize);
   tolua_variable(tolua_S,"______reserve",tolua_get_CPlayerBag_______reserve,tolua_set_CPlayerBag_______reserve);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"ENPC_QSTATE_NONE",ENPC_QSTATE_NONE);
  tolua_constant(tolua_S,"ENPC_QSTATE_ACCEPT",ENPC_QSTATE_ACCEPT);
  tolua_constant(tolua_S,"ENPC_QSTATE_HAVE_ACCEPT",ENPC_QSTATE_HAVE_ACCEPT);
  tolua_constant(tolua_S,"ENPC_QSTATE_SUBMIT",ENPC_QSTATE_SUBMIT);
 tolua_endmodule(tolua_S);
 return 1;
}

#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_serverLuaInterface (lua_State* tolua_S) {
 return tolua_serverLuaInterface_open(tolua_S);
};
#endif

