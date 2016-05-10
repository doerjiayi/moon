#include "StdAfx.h"

using namespace lib::memory;
using namespace lib::sync;

CCSLock *g_GlobalObjAllocLock = NULL;
static SmallObjectAllocator<DoerMsg> *g_DoerMsgAllocator = NULL;
static SmallObjectAllocator<PlayerQuestData> *g_PlayerQuestDataAllocator = NULL;
static SmallObjectAllocator<PlayerDoneQuestData> *g_PlayerDoneQuestAllocator = NULL;
static SmallObjectAllocator<DropItemData> *g_DropItemDataAllocator = NULL;
static SmallObjectAllocator<Bead> *g_WeaponBeadAllocator = NULL;
static SmallObjectAllocator<CTeam> *g_TeamAllocator = NULL;
static SmallObjectAllocator<UserItem>	*g_UserItemAllocator= NULL;

bool CGlobalLogicObjAlloc::init()
{
	g_GlobalObjAllocLock = new  CCSLock();
	g_DoerMsgAllocator = new SmallObjectAllocator<DoerMsg>;
	g_PlayerQuestDataAllocator = new SmallObjectAllocator<PlayerQuestData>;
	g_PlayerDoneQuestAllocator = new SmallObjectAllocator<PlayerDoneQuestData>;
	g_WeaponBeadAllocator = new SmallObjectAllocator<Bead>;
	g_DropItemDataAllocator = new SmallObjectAllocator<DropItemData>;
	g_TeamAllocator = new SmallObjectAllocator<CTeam>;
	g_UserItemAllocator	= new SmallObjectAllocator<UserItem>;
	return true;
}

void CGlobalLogicObjAlloc::destory()
{
	SafeDelete(g_GlobalObjAllocLock);
	SafeDelete(g_DoerMsgAllocator);
	SafeDelete(g_DropItemDataAllocator);
	SafeDelete(g_WeaponBeadAllocator);
	SafeDelete(g_TeamAllocator);
	SafeDelete(g_PlayerQuestDataAllocator);
	SafeDelete(g_PlayerDoneQuestAllocator);
	SafeDelete(g_UserItemAllocator);
}

//道具
UserItem* CGlobalLogicObjAlloc::allocUserItem()
{
	CSafeLock sl(g_GlobalObjAllocLock);
	return g_UserItemAllocator->Alloc();
}

void CGlobalLogicObjAlloc::freeUserItem(UserItem* pUserItem)
{
	CSafeLock sl(g_GlobalObjAllocLock);
	return g_UserItemAllocator->Free(pUserItem);
}

DoerMsg* CGlobalLogicObjAlloc::allocDoerMsg()
{
	CSafeLock sl(g_GlobalObjAllocLock);
	return g_DoerMsgAllocator->Alloc();
}

void CGlobalLogicObjAlloc::freeDoerMsg( DoerMsg *msg )
{
	CSafeLock sl(g_GlobalObjAllocLock);
	return g_DoerMsgAllocator->Free(msg);
}

//已接任务
PlayerQuestData* CGlobalLogicObjAlloc::allocPlayerQuestData()
{
	CSafeLock sl(g_GlobalObjAllocLock);
	return g_PlayerQuestDataAllocator->Alloc();
}

void CGlobalLogicObjAlloc::freePlayerQuestData( PlayerQuestData* pQuestData )
{
	CSafeLock sl(g_GlobalObjAllocLock);
	return g_PlayerQuestDataAllocator->Free(pQuestData);
}

//已完成任务
PlayerDoneQuestData* CGlobalLogicObjAlloc::allocPlayerDoneQuestData()
{
	CSafeLock sl(g_GlobalObjAllocLock);
	return g_PlayerDoneQuestAllocator->Alloc();
}

void CGlobalLogicObjAlloc::freePlayerDoneQuestData( PlayerDoneQuestData* pQDData )
{
	CSafeLock sl(g_GlobalObjAllocLock);
	return g_PlayerDoneQuestAllocator->Free(pQDData);
}

//武器灵珠
Bead* CGlobalLogicObjAlloc::allocWeaponBead()
{
	CSafeLock sl(g_GlobalObjAllocLock);
	return g_WeaponBeadAllocator->Alloc();
}

void CGlobalLogicObjAlloc::freeWeaponBead(Bead* pBead)
{
	CSafeLock sl(g_GlobalObjAllocLock);
	return g_WeaponBeadAllocator->Free(pBead);
}

DropItemData* CGlobalLogicObjAlloc::allocDropItem()
{
	CSafeLock sl(g_GlobalObjAllocLock);
	return g_DropItemDataAllocator->Alloc();
}

void CGlobalLogicObjAlloc::freeDropItem( DropItemData *dropItemdata )
{
	CSafeLock sl(g_GlobalObjAllocLock);
	return g_DropItemDataAllocator->Free(dropItemdata);
}

CTeam* CGlobalLogicObjAlloc::allocTeam()
{
	CSafeLock sl(g_GlobalObjAllocLock);
	return g_TeamAllocator->Alloc();
}

void CGlobalLogicObjAlloc::freeTeam( CTeam* pTeam )
{
	CSafeLock sl(g_GlobalObjAllocLock);
	return g_TeamAllocator->Free(pTeam);
}

