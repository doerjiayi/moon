#include <string.h>
#include "StdAfx.h"
#include "GateManager.h"

CGateManager::CGateManager()
{
}

CGateManager::~CGateManager()
{
	stopGateManager();
	ClearGates();
}

VOID CGateManager::ClearGates()
{
	for (INT_PTR i=m_GateList.count() - 1; i > -1; --i)
	{
		m_GateList[i]->stopGate();
		m_GateList[i]->release();
	}
	m_GateList.clear();
}

CLogicGate* CGateManager::addGate(const GateConfig *pConfig)
{
	CLogicGate *pGate;
	for (INT_PTR i=m_GateList.count()-1; i>-1; --i)
	{
		pGate = m_GateList[i];
		if (pGate->GetBindPort() == pConfig->nPort)
		{
			logError("[GateManager] can not add gate on port(%d), port exists", pConfig->nPort);
			return NULL;
		}
		if (_stricmp(pGate->GetGateName(), pConfig->sName) == 0)
		{
			logError("[GateManager] can not add gate named(%s), name exists", pConfig->sName);
			return NULL;
		}
	}

	pGate = new CLogicGate();
	pGate->SetBindAddress(pConfig->sAddress);
	pGate->SetBindPort(pConfig->nPort);
	pGate->SetSendThreadCount(pConfig->nSendThreadCount);
	pGate->SetGateName(pConfig->sName);
	pGate->SetGateIndex((int)m_GateList.add(pGate));

	return pGate;
}

bool CGateManager::startGateManager()
{
	INT_PTR nCount = m_GateList.count();

	for (INT_PTR i=0; i<nCount; ++i)
	{
		if (!m_GateList[i]->startGate())
		{
			stopGateManager();
			return false;
		}
	}
	return true;
}

void CGateManager::stopGateManager()
{
	INT_PTR nCount = m_GateList.count();

	for (INT_PTR i=nCount - 1; i>-1; --i)
	{
		m_GateList[i]->stopGate();
	}
}
