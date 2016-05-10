#ifndef __GATE_SYNERGY_H__
#define __GATE_SYNERGY_H__

/************************************************************
 逻辑网关异步协同数据处理类
**********************************************************/
class CLogicGateSynergy
{
public:
	CLogicGateSynergy();
	virtual ~CLogicGateSynergy();

	//返回用户登陆结果
	void resultUserLogin(const common::SERVERUSERHANDLE *pUserHandle, int nErrorCode, int nUserId);
	//返回用户查询角色结果
	void resultUserQueryCharList(const common::SERVERUSERHANDLE *pUserHandle, int nCharCount, CPoolDataPacket *pPacket);
	//返回用户创建角色结果
	void resultUserCreateChar(const common::SERVERUSERHANDLE *pUserHandle, int nErrorCode, CPoolDataPacket *pPacket);
	//返回用户删除角色结果
	void resultUserDeleteChar(const common::SERVERUSERHANDLE *pUserHandle, int nErrorCode);
	//返回请求进入游戏结果
	void resultEnterGame(const common::SERVERUSERHANDLE *pUserHandle, int nErrorCode);

protected:
	/* 异步过程返回数据 */
	struct SynergyData
	{
		common::SERVERUSERHANDLE userHandle;
		enum OPType
		{
			aorLogin = 1,//登陆返回
			aorQueryCharList,//查询角色列表返回
			aorCreateChar,//创建角色返回
			aorDeleteChar,//删除角色返回
			aorEnterGame,//进入游戏返回
		}opType;
		union
		{
			struct {
				int nErrorCode; 
				int nUserId;
			}login;
			struct {
				int nCharCount;
				CPoolDataPacket *pPacket;
			}querychar;
			struct {
				int nErrorCode;
				CPoolDataPacket *pPacket;
			}createchar;
			struct {
				int nErrorCode;
			}deletechar;
			struct {
				int nErrorCode;
			}enterGame;
		};
	};

protected:
	VOID ProcessSynergyList();
	virtual VOID HandleSynergyData(SynergyData *pData) = 0;

private:
	CQueueList<SynergyData>	m_SynergyDataList;
	CCSLock					m_SynergyDataLock;
};

#endif
