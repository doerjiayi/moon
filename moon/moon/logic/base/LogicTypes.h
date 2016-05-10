#ifndef __LOGIC_TYPES_H__
#define __LOGIC_TYPES_H__
using namespace common;
using namespace common::NetCmd;
using namespace common::SystemId;
using namespace common::DBType;

/* 客户端请求进入游戏数据结构 */  //在请求进入游戏时候创建case sstuan::NetCmd::cEnterGame:
struct EnterGameStruct
{
	int	nAccountId;//账号ID
	char sAccount[64];//账号字符串
	common::PlayerId charId;//角色ID
	char sCharName[48];//角色名称
	int nClientAddr;//客户端IP地址
	common::SERVERUSERHANDLE userHandle;//网关用户身份句柄
};

class CPoolDataPacket;

/* 加载角色数据完成并建立玩家对象的数据结构 */
struct OpenPlayerStruct
{
	EnterGameStruct enter;//请求进入游戏数据
	CPoolDataPacket* dataPack;//角色数据包
	bool boIsNewPlayer;//是否新玩家
};

#endif
