#pragma once

//游戏命令实现函数类型
typedef void (*GameCommandFunc)(CPlayer *player, const char* sCmd, char*const* sParams, const int nParamCount);

class GameCommander : public Object
{
public:
	typedef Object super;

public:
	GameCommander();
	~GameCommander();

	//初始化游戏命令
	void init();
	void uninit();
	//分派游戏命令
	void dispatchCmd(CPlayer *player, const char* sCmd, char*const* sParams, const int nParamCount);

protected:
	//游戏命令结构
	struct GameCommand
	{
		short nPrivilege;//权限等级
		short nMinParams;//最少参数数量
		GameCommandFunc func;//名利实现函数
	};

	StringHashMap<GameCommand> m_CmdMap;//命令表

public:
	static void CmdMakeMonster(CPlayer *player, const char* sCmd,  char*const* sParams, const int nParamCount);
	static void CmdAddItem(CPlayer *player, const char* sCmd,  char*const* sParams, const int nParamCount);
	static void CmdAddQuest(CPlayer *player, const char* sCmd,  char*const* sParams, const int nParamCount);
	static void CmdClearQuest(CPlayer *player, const char* sCmd,  char*const* sParams, const int nParamCount);
	static void CmdGodMode(CPlayer *player, const char* sCmd,  char*const* sParams, const int nParamCount);
	static void CmdReviviscent(CPlayer *player, const char* sCmd,  char*const* sParams, const int nParamCount);
	static void CmdMapMove(CPlayer *player, const char* sCmd,  char*const* sParams, const int nParamCount);
	static void CmdGotoPlayer(CPlayer *player, const char* sCmd,  char*const* sParams, const int nParamCount);
	static void CmdRecallPlayer(CPlayer *player, const char* sCmd,  char*const* sParams, const int nParamCount);
	static void CmdCreateDuplicate(CPlayer *player, const char* sCmd,  char*const* sParams, const int nParamCount);
};
