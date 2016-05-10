#include "StdAfx.h"
#include "GridItem.h"




void GridItem::delEntity( CEntity* pEntity )
{
	m_entityList.remove(m_entityList.index(pEntity));
}

void GridItem::addEntity( CEntity* pEntity )
{
	m_entityList.add(pEntity);
}
