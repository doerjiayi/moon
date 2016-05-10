#ifndef __DB_MANAGER_H__
#define __DB_MANAGER_H__

class CDBManager :
	public CCustomSSTClientSocket
{
public:
	typedef CCustomSSTClientSocket super;

public:
	CDBManager();
	~CDBManager();

	//客户端查询角色列表
	void requestQueryChar(common::SERVERUSERHANDLE *pUserHandle, int nAccountId);
	//客户端创建角色
	void requestCreateChar(common::SERVERUSERHANDLE *pUserHandle, int nAccountId, const char *sAccount, const char *sCharName, int btJob, int btGender);
	//客户端删除角色
	void requestDeleteChar(common::SERVERUSERHANDLE *pUserHandle, int nAccountId, common::PlayerId charId);
	//客户端请求进入游戏
	bool requestEnterGame(EnterGameStruct *pEnterGameStruct);
	//从DB数据包管理池中申请一个数据包对象
	CPoolDataPacket* requestPoolDataPacket();
	//保存角色数据
	void requestSaveCharData(common::PlayerId playerId, int nPlayerIndex, CPoolDataPacket *pPacket);

	//启动DB管理器
	bool startManager();
	//停止db管理器
	void stopManager();

protected:
	//每次逻辑循环的例行逻辑处理函数
	VOID SingleRun();
	//当连接处理线程启动后立即调用
	VOID OnWorkThreadStart();
	//当连接处理线程停止前调用
	VOID OnWorkThreadStop();
	//连接到服务器成功后发送注册客户端的消息
	VOID SendRegisteClient();
	//当长时间没有通信后发送保持连接的消息
	VOID SendKeepAlive();
	//从套接字中接收到的数据包处理分派函数
	VOID DispatchRecvPacket(CDataPacketReader &inPacket);

private:
	/* 角色数据加载信息结构 */
	struct LoadPlayerStruct
	{
		EnterGameStruct enterStruct;//进入游戏请求数据
		TICKCOUNT dwLoadTimeOut;//加载超时时间
		int nLoadCount;//加载重试次数
		int nErrorCode;//DB返回的加载失败错误码
		bool boIsNewPlayer;//是否新角色
		char btReserve[3];
		CPoolDataPacket *pCharDataPacket;//加载成功的角色数据包
	};

	/* 角色数据保存结构信息 */
	struct SavePlayerStruct
	{
		common::PlayerId charId;//角色ID
		int nPlayerIndex;//角色索引
		TICKCOUNT dwSaveTimeOut;//保存超时时间
		int nSaveCount;//保存重试次数
		int nErrorCode;//DB返回的保存失败错误码
		bool boSuccess;//是否保存成功
		char btReserve[3];
		CPoolDataPacket *pCharDataPacket;//角色数据包
	};

	/* 角色转储数据头结构 */
	struct DumpPlayerDataHeader
	{
		common::PlayerId charId;//角色ID
		DWORD dwDataSize;//数据长度
		char reserve[20];
	};

private:
	//等待所有数据存储完成
	VOID WaitForAllDataComplete();
	//保存所有存储失败的角色数据到本地临时目录
	VOID DumpSavePlayerFailureList();
	//从本地目录读取所有失败的角色数据
	VOID RestoreSavePlayerFailureList();
	//获取正在加载的角色数据结构
	LoadPlayerStruct* GetLoadPlayerStruct(const common::PlayerId charId, INT_PTR *pIndex = NULL);
	//处理加载角色数据
	VOID ProcessLoadPlayerData();
	//移除角色数据加载记录
	VOID RemoveLoadPlayerData(INT_PTR nIndex);
	//获取正在保存的角色数据结构
	SavePlayerStruct* GetSavePlayerStruct(const common::PlayerId charId, INT_PTR *pIndex = NULL);
	//处理保存角色数据
	VOID ProcessSavePlayerData();
	//移除角色数据保存记录
	VOID RemoveSavePlayerData(INT_PTR nIndex);
	//获取保存失败的角色数据结构
	SavePlayerStruct* GetFailureSavePlayerStruct(const common::PlayerId charId, INT_PTR *pIndex = NULL);
	//将角色数据保存列表中的数据转存到失败列表中
	VOID AddFailureSavePlayerStruct(INT_PTR nSaveListIndex);

	VOID HandleRegistClientRet(CDataPacketReader &inPacket);
	VOID HandleQueryCharListRet(CDataPacketReader &inPacket);
	VOID HandleCreateCharRet(CDataPacketReader &inPacket);
	VOID HandleDeleteCharRet(CDataPacketReader &inPacket);
	VOID HandleLoadCharDataRet(CDataPacketReader &inPacket);
	VOID HandleSaveCharDataRet(CDataPacketReader &inPacket);

private:
	BOOL m_boStarted;//是否已启动服务
	CDataPacketPool	m_DataPacketPool;//数据包缓冲池
	CQueueList<LoadPlayerStruct*> m_LoadPlayerList;//角色数据加载列表
	CCSLock	m_LoadPlayerLock;//角色数据加载列表锁
	CListAllocator<LoadPlayerStruct> m_LoadPlayerAllocator;//角色数据加载结构申请器
	CQueueList<SavePlayerStruct*> m_SavePlayerList;//角色数据保存列表
	CBList<SavePlayerStruct*> m_SavePlayerFailList;//角色数据保存失败列表
	CCSLock m_SavePlayerLock;//角色数据保存列表锁
	CListAllocator<SavePlayerStruct> m_SavePlayerAllocator;//角色数据保存结构申请器
private:
	//DB数据版本号
	static const DWORD DB_DATA_VERSION = 0x010C060E;
};

#endif
