#ifndef __POOL_DATA_PACKET_H__
#define __POOL_DATA_PACKET_H__


class CDataPacketPool;

/**********************************************************
 使用池优化的数据包对象类
  用于跨线程间传递数据
********************************************************/
class CPoolDataPacket :
	public CDataPacket
{
public:
	CPoolDataPacket():CDataPacket()
	{
		m_pPool = NULL;
	}
	//设置所属网络数据包池
	inline void setPool(CDataPacketPool *pPool){ m_pPool = pPool; };
	//将数据包放回数据包池中
	void freeBack();
private:
	CDataPacketPool *m_pPool;
};

/******************************************************
* 数据包对象类缓存池
* 用于优化线程间收取以及发送数据过程中的数据包对象创建与销毁，
* 使用对象池技术将不用的数据包缓存到队列中供下次使用时直接
* 取得并使用。
*****************************************************/
class CDataPacketPool : 
	protected lib::memory::CListAllocator<CPoolDataPacket>
{
protected:
	typedef lib::memory::CListAllocator<CPoolDataPacket> super;
public:
	~CDataPacketPool()
	{
		freePacketMemory();
		//super::~CSingleObjectAllocator();
	}
	//申请网络数据包
	inline CPoolDataPacket* allocPacket()
	{
		lib::sync::CSafeLock sl(&m_PacketLock);
		CPoolDataPacket* pPacket = allocObject();
		pPacket->setPool(this);
		pPacket->setLength(0);
		return pPacket;
	}
	//释放网络数据包
	inline void freePacket(CPoolDataPacket *packet)
	{
		lib::sync::CSafeLock sl(&m_PacketLock);
		freeObject(packet);
	}
	//释放所有空闲数据包的内存
	inline void freePacketMemory()
	{
		lib::sync::CSafeLock sl(&m_PacketLock);
		CPoolDataPacket **pPacketList = *this;
		for (INT_PTR i=count() - 1; i>-1; --i)
		{
			pPacketList[i]->clear();
		}
	}
	//释放并销毁所有数据包
	inline void freeAllPacket()
	{
		super::freeAll();
	}
protected:
	lib::sync::CCSLock		m_PacketLock;
};

inline void CPoolDataPacket::freeBack() { if (m_pPool) m_pPool->freePacket(this); }


#endif
