#ifndef __GATE_MANAGER_H__
#define __GATE_MANAGER_H__

class CGateManager
{
public:
	//网关配置
	struct GateConfig
	{
		char	sAddress[32];//绑定地址
		int		nPort;//绑定端口
		int		nSendThreadCount;//发送线程数量
		char	sName[48];//网关名称
	};

public:
	CGateManager();
	~CGateManager();

	//添加网关
	CLogicGate* addGate(const GateConfig *pConfig);
	//获取网关数量
	inline int getGateCount(){ return (int)m_GateList.count(); }
	//按编号获取网关对象
	inline CLogicGate* getGate(const int nGateIndex)
	{
		if (nGateIndex >= 0 && nGateIndex < m_GateList.count())
			return m_GateList[nGateIndex];
		return NULL;
	}
	//启动网关管理器
	bool startGateManager();
	//停止网关管理器
	void stopGateManager();

protected:
	VOID ClearGates();

private:
	CBList<CLogicGate*>		m_GateList;
};

#endif
