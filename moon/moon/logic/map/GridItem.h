#ifndef _CGRID_ITEM_
#define _CGRID_ITEM_


class CEntity;

class GridItem
{
	friend class CMapGrid;
	friend class CEntity;
public:
	GridItem():m_x(0),m_y(0)
	{
	}
	void delEntity(CEntity* pEntity);
	void addEntity(CEntity* pEntity);
	inline void setXY(int x,int y){m_x = x;m_y = y;}
private:
	//当前块保存的可交互对象列表
	CBList<CEntity*> m_entityList;

	int	m_x;//块索引
	int	m_y;
};


#endif

