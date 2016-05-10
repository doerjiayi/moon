#pragma once

class CGameDataBufferPool;

/**
	设计用于保存逻辑服务器发来的角色数据或帮会数据的内存缓冲区类。
	由于逻辑服务器发来的数据需要分别向LocalDB以及SQLDB两个地方保存，而如果直接将数据包传输
	给两个对象自己管理则可能导致相同的数据内存被拷贝两份。而通常逻辑发来的这份数据是只读的，不
	需要拷贝两次，只要有一份提供给两个地方使用，并且当两个地方都使用完了则销毁这个数据包即可。
**/
class CGameDataBuffer :
	public CDataPacket
{
	friend class CGameDataBufferPool;
public:
	CGameDataBuffer()
		:CDataPacket()
	{
		m_nRefer = 0;
		m_pPool = NULL;
	}
	
	//设置数据
	inline VOID SetData(const INT64 nDataId, LPCVOID lpData, SIZE_T dwSize)
	{
		m_nDataId = nDataId;
		setLength(0);
		writeBuf(lpData, dwSize);
	}

	//添加引用
	inline LONG AddRef()
	{ 
		return InterlockedIncrement(&m_nRefer); 
	}

	//减少引用
	inline LONG Release();

	//获取数据ID
	inline INT64 GetDataId() const { return m_nDataId; }
private:
	LONG				m_nRefer;
	INT64				m_nDataId;
	CGameDataBufferPool	*m_pPool;
};


/**
	接受自逻辑服务器的数据存缓冲区池。
	设计用于优化逻辑数据包缓冲的性能。
**/
class CGameDataBufferPool :
	protected lib::container::CBList<CGameDataBuffer*>
{
public:
	typedef CBList<CGameDataBuffer*> Inherited;

public:
	//申请一个数据包对象
	inline CGameDataBuffer* AllocDataBuffer()
	{
		lib::sync::CSafeLock cs(&m_ListLock);
		//如果数据包数量为0则批量申请若干个
		if (count() <= 0)
		{
			static const INT OnceAllocCount = 128;
			CGameDataBuffer *pDataBuffer = m_BufferAllocator.allocObjects(OnceAllocCount);
			for (INT_PTR i=0; i<OnceAllocCount; ++i)
			{
				pDataBuffer->m_pPool = this;
				add(pDataBuffer);
				pDataBuffer++;
			}
		}
		//返回列表中的最后一个
		return pop();
	}

	//释放数据包回数据包池中
	inline VOID FreeDataBuffer(CGameDataBuffer *pDataBuffer)
	{
		lib::sync::CSafeLock cs(&m_ListLock);
		add(pDataBuffer);
	}
private:
	lib::sync::CCSLock			m_ListLock;
	lib::memory::CBaseObjAllocator<CGameDataBuffer>	m_BufferAllocator;
};

inline LONG CGameDataBuffer::Release()
{
	LONG nRet = InterlockedDecrement(&m_nRefer);
	Assert(nRet >= 0);
	//如果引用计数为0则将自己添加回Pool的空闲列表中
	if (m_nRefer == 0 && m_pPool)
		m_pPool->FreeDataBuffer(this);
	return nRet;
}

/**
	用于读取CGameDataBuffer的类
	每当将此类通过SetDataBuffer与一个数据包缓冲对象关联，则会增加该数据包缓冲对象的
	引用计数，并在关联新的数据包缓冲对象前减少当前关联的数据包缓冲对象的引用计数。
**/
class CGameDataBufferReader :
	public CDataPacketReader
{
public:
	CGameDataBufferReader()
		:CDataPacketReader()
	{
		m_pDataBuffer = NULL;
	}

	//设置数据缓冲对象
	inline VOID SetDataBuffer(CGameDataBuffer *pDataBuffer)
	{
		if (m_pDataBuffer == pDataBuffer)
			return;
		if (m_pDataBuffer)
		{
			m_pDataBuffer->Release();
			m_pDataBuffer = NULL;
			m_pMemory = m_pMemoryEnd = m_pOffset = m_pDataEnd = NULL;
		}
		m_pDataBuffer = pDataBuffer;
		if (pDataBuffer)
		{
			pDataBuffer->AddRef();
			m_pMemory = m_pOffset = (char*)pDataBuffer->getMemoryPtr();
			m_pMemoryEnd = m_pDataEnd = m_pMemory + pDataBuffer->getLength();
		}
	}
	//获取存储的数据ID
	inline INT64 GetDataId() const 
	{ return m_pDataBuffer ? m_pDataBuffer->GetDataId() : 0; }
private:
	CGameDataBuffer		*m_pDataBuffer;
};

/**
	CGameDataBufferReader对象池
**/
class CGameDataBufferReaderPool :
	protected lib::container::CBList<CGameDataBufferReader*>
{
public:
	typedef CBList<CGameDataBufferReader*> Inherited;

public:
	//申请一个数据包读取对象
	inline CGameDataBufferReader* AllocBufferReader()
	{
		lib::sync::CSafeLock cs(&m_ListLock);
		//如果数据包数量为0则批量申请若干个
		if (count() <= 0)
		{
			static const INT OnceAllocCount = 128;
			CGameDataBufferReader *pReader = m_ReaderAllocator.allocObjects(OnceAllocCount);
			for (INT_PTR i=0; i<OnceAllocCount; ++i)
			{
				add(pReader);
				pReader++;
			}
		}
		//返回列表中的最后一个
		return pop();
	}

	//释放一个数据包读取对象
	inline VOID FreeBufferReader(CGameDataBufferReader *pBufferReader)
	{
		pBufferReader->SetDataBuffer(NULL);
		m_ListLock.Lock();
		add(pBufferReader);
		m_ListLock.Unlock();
	}
private:
	lib::sync::CCSLock				m_ListLock;
	lib::memory::CBaseObjAllocator<CGameDataBufferReader>	m_ReaderAllocator;
};

/**
	CGameDataBufferReader更新请求队列
**/
class CGameDataBufferReaderQueue :
	public lib::container::CQueueList<CGameDataBufferReader*>
{
public:
	typedef CQueueList<CGameDataBufferReader*> Inherited;

public:
	CGameDataBufferReaderQueue()
	{
		setLock(&m_Lock);
	}

private:
	lib::container::CCSLock	m_Lock;
};
