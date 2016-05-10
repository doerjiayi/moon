#include "StdAfx.h"

CDoerUnit::CDoerUnit()
{
	m_pActor = NULL;
	m_pPlayer = NULL;
}

CDoerUnit::~CDoerUnit()
{

}

bool CDoerUnit::init()
{
	return true;
}

bool CDoerUnit::loadData(CDataPacketReader &data)
{
	return false;
}

void CDoerUnit::saveData(CDataPacket& data)
{

}

void CDoerUnit::dispatchRecvPacket(int btCmd, CDataPacketReader &inPacket)
{

}

void CDoerUnit::dispatchMsg(DoerMsg *msg)
{

}

void CDoerUnit::offline()
{

}

