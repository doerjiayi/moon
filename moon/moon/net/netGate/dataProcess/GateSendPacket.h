#ifndef GATE_SEND_PACKET_H__
#define GATE_SEND_PACKET_H__


/**********************************************************
 用于网关发送数据优化的网络发送数据包类
********************************************************/
using namespace lib::sync;
using namespace lib::container;

class CGateSendPacketPool;

class CGateSendPacket : 
	public CDataPacket
{
public:
	CGateSendPacket():CDataPacket()
	{
		m_pPool = NULL;
	}
	CGateSendPacket(const CGateSendPacket& another)
	{
		//如果这里断言了，那么你看到这里可以说明你代码写错了，典型的错误形式：
		//CGateSendPacket packet = player->allocSendPacket();
		//               ^
		//               |
		//             这里少了“&”
		assert(0);
	}
	//设置所属网络数据包池
	inline void setPool(CGateSendPacketPool *pPool){ m_pPool = pPool; };
	//将数据包放回数据包池中
	void freeBack();
	//设置数据包验证信息
	inline void setSendInfo(PEXECDATASENDTHREAD pSendThread, int nUserIndex, int nVerify)
	{
		m_pSendThread = pSendThread;
		m_nUserIndex = nUserIndex;
		m_nVerify = nVerify;
	}
	inline void writeCmd(int nSysId, int nCmd)
	{
		common::NetPacketMessage msg(nSysId, nCmd);
		*this << msg;
	}
	//提交网络数据包到发送队列
	inline void flush()
	{
		if (m_pSendThread)
		{
			EnterCriticalSection( &m_pSendThread->SendQueueLock );
			m_pSendThread->pSendAppendList->add(this);
			LeaveCriticalSection( &m_pSendThread->SendQueueLock );
			m_pSendThread = NULL;//置空避免重复提交
		}
	}
private:
	CGateSendPacketPool	*m_pPool;
	size_t	m_dwHeaderPos;
	PEXECDATASENDTHREAD m_pSendThread;
public:
	int	m_nUserIndex;//用户索引
	int	m_nVerify;
};


/******************************************************
网关发送网络数据包缓存池
用于优化网关发送数据过程中的数据包对象创建与销
使用对象池技术将不用的数据包缓存到队列中供下次使用时直接
取得并使用。
****************************************************/
class CGateSendPacketPool : 
	protected CListAllocator<CGateSendPacket>
{
protected:
	typedef CListAllocator<CGateSendPacket> super;

public:
	~CGateSendPacketPool()
	{
		freePacketMemory();
		//super::~CSingleObjectAllocator();
	}
	//申请网络数据包
	inline CGateSendPacket* allocPacket()
	{
		lib::sync::CSafeLock sl(&m_PacketLock);
		CGateSendPacket* pPacket = allocObject();
		pPacket->setPool(this);
		pPacket->setLength(0);
		return pPacket;
	}
	//释放网络数据包
	inline void freePacket(CGateSendPacket *packet)
	{
		lib::sync::CSafeLock sl(&m_PacketLock);
		freeObject(packet);
	}
	//释放网络数据包列表
	inline void freePacketList(CGateSendPacket **ppPacketList, int nCount)
	{
		lib::sync::CSafeLock sl(&m_PacketLock);
		addArray(ppPacketList, nCount);
	}
	//释放所有空闲网络数据包的内存
	inline void freePacketMemory()
	{
		lib::sync::CSafeLock sl(&m_PacketLock);
		CGateSendPacket **pPacketList = *this;
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

inline void CGateSendPacket::freeBack(){ if (m_pPool) m_pPool->freePacket(this); }

#endif
