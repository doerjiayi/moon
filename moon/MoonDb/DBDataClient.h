#ifndef _DB_DATA_CLIENT_H_
#define _DB_DATA_CLIENT_H_
#include <net/socket/CustomSSTClientSocket.h>
class CDBDataServer;

class CDBDataClient : 
	public CCustomMoonServerClientSocket,
	public CMsgQueue
{
	friend class CDBDataServer;
public:
	typedef CCustomMoonServerClientSocket Inherited;

private:
	CDBDataServer*		m_pDataServer;			//所属数据服务器
	CLocalDB*			m_pLocalDB;				//本地数据库
	CSQLDB*				m_pSQLDB;				//SQL数据库
	TICKCOUNT			m_dwClosedTick;			//连接断开的时间
protected:
	//覆盖连接建立的函数
	VOID OnConnected();
	//覆盖连接断开的函数
	VOID OnDisconnected();
	//覆盖套接字错误的函数
	VOID OnError(INT errorCode);
	//覆盖处理内部消息的函数
	VOID DispatchMsg(UINT uMsg, UINT_PTR uParam1, UINT_PTR uParam2, UINT_PTR uParam3);

private:
	//分派客户端收到的数据包的处理函数
	VOID DispatchRecvPacket(CDataPacketReader &inPacket);
	//处理数据客户端注册消息
	VOID CatchRegisterServer(CDataPacketReader &inPacket);
	//数据客户端查询用户角色列表
	VOID CatchQueryCharList(CDataPacketReader &inPacket);
	//数据客户端创建新角色
	VOID CatchCreateChar(CDataPacketReader &inPacket);
	//数据客户端追加角色数据
	VOID CatchImportCharData(CDataPacketReader &inPacket);
	//数据客户端删除角色
	VOID CatchDeleteChar(CDataPacketReader &inPacket);
	//数据客户端读取角色数据
	VOID CatchLoadCharData(CDataPacketReader &inPacket);
	//数据客户端保存角色数据
	VOID CatchSaveCharData(CDataPacketReader &inPacket);

	//数据客户端读取帮会ID列表
	VOID CatchLoadGuildIdList(CDataPacketReader &inPacket);
	//数据客户端读取帮会数据
	VOID CatchLoadGuildData(CDataPacketReader &inPacket);
	//数据客户端保存帮会数据
	VOID CatchSaveGuildData(CDataPacketReader &inPacket);

	//数据客户端查询角色描述数据
	VOID CatchQueryCharDescList(CDataPacketReader &inPacket);
	//数据客户端请求重命名角色
	VOID CatchRenameChar(CDataPacketReader &inPacket);
	//数据客户端请求设置角色状态（屏蔽/删除/恢复）
	VOID CatchSetCharState(CDataPacketReader &inPacket);
public:
	CDBDataClient(CDBDataServer *lpDataServer, SOCKET nSocket, PSOCKADDR_IN pAddrIn);
	~CDBDataClient();

	inline BOOL registed(){ return m_nServerId != 0; }

	//判断是否具有尚未处理完成对的数据
	BOOL HasRemainData();
};

#endif

