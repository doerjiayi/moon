#include "StdAfx.h"

void MapArchiver::load(CDataPacketReader &stream)
{
	MapHeader hdr;
	//读取文件头
	stream >> hdr;
	if (hdr.uIdent != MAPHEADER_IDENT)
	{
		//throw Error"非有效的地图文档数据流");
		throw;
	}
		
	if (hdr.version != MAPFILE_VERSION)
	{
		//throw Error("地图文档有效，但版本号(0x%8X)无法被解析", hdr.version);
		throw; 
	}
		
	if (hdr.compressedSize > stream.getAvaliableLength())
	{
		//throw Error("地图文档数据内容错误！");
		throw;
	}

	//将地图大小对齐到地图网格边界
	hdr.mapWidth = hdr.mapWidth/UnitWidth * UnitWidth;
	hdr.mapHeight = hdr.mapHeight/UnitHeight * UnitHeight;
		

	m_nWidth = hdr.mapWidth;
	m_nHeight = hdr.mapHeight;

	//解压数据
	uLongf dataSize = hdr.uncompressedSize;
	CDataPacket dataStream;
	dataStream.setLength(dataSize);
	dataStream.setPosition(0);
	int err = uncompress((Bytef*)dataStream.getMemoryPtr(), &dataSize, (Bytef*)stream.getOffsetPtr(), hdr.compressedSize);
	if (err != Z_OK)
	{
		//throw Error("解压缩地图文档数据失败： %0xX.", err);
		throw;
	}
		
	dataStream.setLength(dataSize);

	//读取限定数据
	//m_nCountGrip = (((hdr.mapWidth + UnitWidth -1) & ~(UnitWidth -1))/UnitWidth) * (((hdr.mapHeight + UnitHeight - 1) & ~(UnitHeight - 1))/UnitHeight) * sizeof(m_pPointData[0]);
	m_ColGrids = (hdr.mapWidth/UnitWidth);
	m_RowGrids =  (hdr.mapHeight/UnitHeight);
	m_nCountGrip =  m_RowGrids * m_ColGrids * sizeof(m_pPointData[0]);
	m_pPointData = (MapPointData*)realloc(m_pPointData, m_nCountGrip);
	dataStream.readBuf(m_pPointData, m_nCountGrip);
}

//////////////////////////////////////////////////////////////////////////
//Map

MapArchiver* MapLoad::LoadMapFile(const char * pPath)
{
	if(!pPath)
	{
		return NULL;
	}
	m_path += pPath;
	FILE *pFile = fopen(m_path.c_str(), "ab+");
	if(!pFile)
	{
		return NULL;
	}
	fseek(pFile, 0, SEEK_END);
	size_t size = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);
	void *pData = malloc(size);
	fread(pData, 1, size, pFile);
	CDataPacketReader reader(pData, size);
	MapArchiver* mapArchiver = new MapArchiver;
	mapArchiver->load(reader);
	free(pData);
	fclose(pFile);
	return mapArchiver;
}

void MapArchiverManager::readFile(const std::string& filename)
{
	if (m_mapArchiver.find(filename) == m_mapArchiver.end())
	{
		//这里读取地图文件初始化scene列表
		const char* path = "./config/map/";
		MapLoad mapLoad(path);
		MapArchiver* mapArchiver = mapLoad.LoadMapFile(filename.c_str());
		m_mapArchiver[filename] = mapArchiver;
	}
}

MapArchiver* MapArchiverManager::getMapArchiver(const std::string& name)
{
	if (m_mapArchiver.find(name) == m_mapArchiver.end())
	{
		return NULL;
	}
	return m_mapArchiver[name];
}

MapArchiverManager::~MapArchiverManager()
{
	std::map<std::string,MapArchiver*>::iterator it = m_mapArchiver.begin();
	std::map<std::string,MapArchiver*>::iterator it_end = m_mapArchiver.end();
	for (;it != it_end;it++)
	{
		SafeDelete(it->second);
	}
	m_mapArchiver.clear();
}




