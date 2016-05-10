#include "StdAfx.h"

CEntity::CEntity()
{
	m_EntityId.llid = 0;
	m_btType = eUnknown;
	m_pScene = NULL;
	m_boDisappeared = false;
	memset(&m_EntityDesc, 0, sizeof(m_EntityDesc));
	m_nX = 0;
	m_nY = 0;
	m_btDirection = 0;
	m_boDead = false;
	m_boGodMode = false;
	m_wEntityBody = 0;
	m_dwStateMasks = esDescDirty;
	m_ImpactRect.x = -60;
	m_ImpactRect.y = -120;
	m_ImpactRect.width = 120;
	m_ImpactRect.height = 120;
	m_dwDieTick = 0;
	m_dwDisappearTick = 0;
}

CEntity::~CEntity()
{
	disappear();
}

int CEntity::getRandomKey(int min,int max)
{
	srand((unsigned)::time(NULL));
	int limitNum = max - min + 1;
	int key = rand() % limitNum + min;

	return key;
}

void CEntity::init(int x, int y )
{
	m_nX	= x;
	m_nY = y;
}


void CEntity::run(TickTime dwCurrTick)
{
	if (m_btType != ePlayer)
	{
		if (m_boDead && dwCurrTick - m_dwDieTick >= 5 * 1000)
		{
			disappear();
			return;
		}
	}
}

void CEntity::sceneChanged(Scene *oldScene, int ox, int oy)
{
	
}

void CEntity::positionChanged(int ox, int oy)
{

}

void CEntity::updateEntityDescription()
{
	m_EntityDesc.race = m_btType;
	m_EntityDesc.body = m_wEntityBody;
}

#ifdef _DEBUG
#define AssertScenePosition(scene, x, y) {\
	assert(x >= 0 && x < scene->m_nMapWidth);\
	assert(y >= 0 && y < scene->m_nMapHeight);\
}
#else
#define AssertScenePosition(scene, x, y)
#endif

void CEntity::setScene(Scene* scene,int x,int y)
{
	if (scene != m_pScene)
	{
		if (scene)
		{
			//AssertScenePosition(scene, x, y);
		}
		Scene *oldScene = m_pScene;
		int ox = m_nX, oy = m_nY;

		if (m_pScene)
		{
			m_pScene->m_pMapGrid->removeFromGrid(m_nX, m_nY, this);
		}
		m_pScene = scene;
		m_nX = x;
		m_nY = y;
		if (m_pScene)
		{
			m_pScene->m_pMapGrid->addToGrid(m_nX, m_nY, this);
		}
		sceneChanged(oldScene, ox, oy);
	}
	else setXY(x, y);
}

void CEntity::setXY(int x,int y)
{
	if (x < 0)  x = 0;
	else if (m_pScene && x >= m_pScene->m_nMapWidth)
		x = m_pScene->m_nMapWidth - 1;

	if (y < 0)  y = 0;
	else if (m_pScene && y >= m_pScene->m_nMapHeight)
		y = m_pScene->m_nMapHeight - 1;

	if (x != m_nX || y != m_nY)
	{
		//AssertScenePosition(m_pScene, x, y);

		int ox = m_nX, oy = m_nY;
		m_nX = x;
		m_nY = y;
		if (GX(ox) != GX(x) || GY(oy) != GY(y))
		{
			m_pScene->m_pMapGrid->removeFromGrid(ox, oy, this);
			m_pScene->m_pMapGrid->addToGrid(m_nX, m_nY, this);
		}
		positionChanged(ox, oy);
	}
}

EntityDesc& CEntity::getEntityDescription(EntityDesc &desc, CPlayer *player)
{
	if (m_dwStateMasks & esDescDirty)
	{
		m_dwStateMasks &= ~esDescDirty;
		updateEntityDescription();
	}
	desc = m_EntityDesc;
	if (m_boDead) desc.flags |= EntityDesc::efDead;

	if (m_btType == eNPC)
	{
//		CNpc *npc = (CNpc*)this;
		//desc.weapon = player->m_Quest.getNpcQuestState(npc->m_EntityId.llid);
	}
	else if (m_btType == ePlayer)
	{
	}
	else
	{
	}
	return desc;
}

void CEntity::disappear()
{
	if (!m_boDisappeared)
	{
		setScene(NULL, m_nX, m_nY);
		m_boDisappeared = true;
		m_dwDisappearTick = g_LogicEngine->getTickCount();
	}
}

int CEntity::findEntity( CBaseObject* pEntity )
{
	return 0;
}
