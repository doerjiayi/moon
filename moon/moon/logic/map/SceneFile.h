#pragma once
#include <zconf.h>

class MapArchiver
{

public:
	//定义地图坐标与像素的对应比例，1坐标表示16x16的像素范围
	static const int UnitWidth = 16;
	static const int UnitHeight = 16;

	//地图文件头
	struct MapHeader
	{
		union //文件头标志
		{
			char sIdent[4];
			unsigned int uIdent;
		};
		unsigned int version;//文件版本号
		int mapWidth;//地图像素宽度
		int mapHeight;//地图像素高度
		unsigned short backgroundId;//背景图片ID
		unsigned char numBackLayer;//背景层数量
		unsigned char numFrontLayer;//前景层数量
		unsigned int compressedSize;//数据段压缩后大小
		unsigned int uncompressedSize;//数据段压缩前大小
		char reserve[36];
	};

	//地图文件头标志值
	static const unsigned int MAPHEADER_IDENT = MAKEFOURCC('S', 'M', 'A', 0);
	//地图文件版本号
	static const unsigned int MAPFILE_VERSION = 0x010D0106;

	//地图单元点
	typedef struct MapPointData
	{
		unsigned char masks;//掩码位
		char reserve[1];
	}MapPointData,*PMapPointData;

	//移动标记掩码位，可设置掩码组合
	enum MapPointMask
	{
		mmMovePoint	 = 0x01,//可移动点
		mmDownBlock	 = 0x02,//下降阻挡，无法向下跳跃穿过
		mmUpBlock	 = 0x04,//上升阻挡，无法向上跳跃穿过
	};

	static const unsigned char MoveMask = 1;
public:
	MapArchiver()
	{
		m_nCountGrip = m_nWidth = m_nHeight = m_RowGrids = m_ColGrids = 0;
		m_pPointData = NULL;
	}
	~MapArchiver()
	{
		if (m_pPointData)
		{
			free(m_pPointData);
			m_pPointData = NULL;
		}
	}
	void load(CDataPacketReader &stream);
	inline unsigned char getPointMask(int x,int y){
		return m_pPointData[y * m_ColGrids+x].masks;
	}
public:
	int m_nWidth;//地图宽度
	int m_nHeight;//地图高度
	int m_RowGrids;//行格子数
	int m_ColGrids;//列格子数
	size_t m_nCountGrip;//地图格子数
private:
	PMapPointData m_pPointData;//地图限定数据表，以[y * m_ColGrids+x]作为下标访问
};




class MapLoad
{
public:
	MapLoad(const char* path):m_path(path){}
	~MapLoad(){};
	typedef MapArchiver::MapPointMask GridState;
public:
	MapArchiver* LoadMapFile(const char * pPath);
private:
	std::string m_path;
};


class MapArchiverManager
{
public:
	void readFile(const std::string& filename);
	MapArchiver* getMapArchiver(const std::string& name);
	~MapArchiverManager();
private:
	std::map<std::string,MapArchiver*> m_mapArchiver;//文件名对应MapArchiver*
};
 
