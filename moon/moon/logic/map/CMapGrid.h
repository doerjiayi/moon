#ifndef _CGAME_GRID_RELATION_
#define _CGAME_GRID_RELATION_

using namespace lib::container;
class CEntity;


#define GX(x)	(x/128)
#define GY(y)	(y/128)

typedef CBList<CEntity*> MapGridCell;

class CMapGrid
{
public:
	CMapGrid();
	~CMapGrid(void);

	//初始化
	bool init(int pxWidth, int pxHeight);
	
	//进入地图
	void addToGrid(int px, int py, CEntity* entity);

	//离开地图
	void removeFromGrid(int px, int py, CEntity* entity);

	//根据所在块填充可视范围内的对象列表
	int getEntityList(int left, int right, int top, int bottom, CBList<CEntity*>& EList, CEntity* pEntity);

	//通过像素坐标获取网格
	inline MapGridCell* getGrid(int px, int py)
	{
		return getGridAt(GX(px), GY(py));
	}
	//通过网格坐标获取网格
	inline MapGridCell* getGridAt(unsigned int gx, unsigned int gy)
	{
		if (gx >= m_nGridWidth || gy >= m_nGridHeight)
			return NULL;
		return &m_pGrid[m_nGridWidth * gy + gx];
	}
private:
	MapGridCell*		m_pGrid;		//当前地图的块grid列表
	unsigned int	m_nGridWidth;	//地图的横向最大块数
	unsigned int	m_nGridHeight;
};


#endif
