#include "StdAfx.h"

CMapGrid::CMapGrid()
:m_pGrid(NULL)
{
}

CMapGrid::~CMapGrid(void)
{
	if (NULL != m_pGrid)
	{
		delete []m_pGrid;
		m_pGrid = NULL;
	}
}

bool CMapGrid::init(int pxWidth, int pxHeight)
{
	m_nGridWidth = ((pxWidth + 127) & (~127)) / 128;
	m_nGridHeight = ((pxHeight + 127) & (~127)) / 128;

	m_pGrid = new MapGridCell[m_nGridWidth*m_nGridHeight];//申请m_maxGrid_x*m_maxGrid_y块内存
	return true;
}

//填充当前块中可视范围内所有块的对象列表
int CMapGrid::getEntityList(int left, int right, int top, int bottom, CBList<CEntity*>& EList, CEntity* pEntity)
{
	//最小取0
	left = (left > 0) ? left : 0;
	top = (top > 0) ? top : 0;
	//最大不超过边界
	right = (right >= (int)m_nGridWidth) ? m_nGridWidth-1 : right;
	bottom = (bottom >= (int)m_nGridHeight) ? m_nGridHeight-1 : bottom;

	EList.clear();		
	int nCurGrid = -1;
	for (int y = top; y <= bottom; ++y)
	{
		for (int x = left; x <= right; ++x)
		{
			nCurGrid = y*m_nGridWidth + x;
			CEntity** ppList = m_pGrid[nCurGrid];
			for (INT_PTR i = m_pGrid[nCurGrid].count()-1; i > -1; --i)
			{
				if (pEntity != ppList[i])
				{
					EList.add(ppList[i]);
				}
			}
		}
	}
	return (INT)EList.count();
}

//进入地图
void CMapGrid::addToGrid(int x, int y, CEntity* entity)
{
	assert(entity);
	MapGridCell* pGrid = getGrid(x, y);
	if (pGrid)
		pGrid->add(entity);
}

void CMapGrid::removeFromGrid(int px, int py, CEntity* entity)
{
	assert(entity);
	MapGridCell* pGrid = getGrid(px, py);
	if (pGrid)
	{
		INT_PTR idx = pGrid->index(entity);
		if (idx > -1)
			pGrid->remove(idx);
	}
}
