#include "StdAfx.h"
#include "doerQuest.h"

CPlayerQuest::CPlayerQuest()
{
}

CPlayerQuest::~CPlayerQuest()
{
	clearAcceptQuests();
	clearDoneQuests();
	clearCanAcceptQuests();
}

void CPlayerQuest::addItem(LogicEvent* event)
{//获得道具
	CDoer* pActor = (CDoer*)event->sender;
	if (pActor->m_btType == ePlayer)
	{
		CPlayer* pPlayer = (CPlayer*)pActor;
		pPlayer->m_Quest.questNormalHandler(int(event->n1), int(event->n2), QuestConfig::EQUEST_TARGET_GET_ITEM);
	}
}

void CPlayerQuest::delItem(LogicEvent* event)
{//使用道具
	CDoer* pActor = (CDoer*)event->sender;
	if (pActor->m_btType == ePlayer)
	{
		CPlayer* pPlayer = (CPlayer*)event->sender;
		pPlayer->m_Quest.questNormalHandler(int(event->n1), int(event->n2), QuestConfig::EQUEST_TARGET_GET_ITEM);
	}
}

void CPlayerQuest::actorDie(LogicEvent* event)
{
	CDoer* pDoer = (CDoer*)event->sender;
	if (pDoer->m_btType == eNormalMonster)
	{
		CDoer *pKiller = (CDoer*)event->n1;
		if (pKiller->m_btType == ePlayer)
		{
			CPlayer* pPlayer = (CPlayer*)pKiller;
			pPlayer->m_Quest.questNormalHandler(int(pDoer->m_wMonId), 1, QuestConfig::EQUEST_TARGET_KILL);
		}
	}
}

void CPlayerQuest::questNormalHandler(const int id, int nCount, QuestConfig::ENUM_QUEST_TARGET type)
{
	PlayerQuestData **ppPQDList = m_AcceptQuestDataList;
	QuestAccessor &questMgr = g_ConfigManager->missionDataProvider;
	//遍历已接任务查找需要更新的任务
	for (INT_PTR i_accept = m_AcceptQuestDataList.count()-1; i_accept > -1; --i_accept)
	{
		unsigned short questID = ppPQDList[i_accept]->questID;
		const QuestConfig *pQuest = questMgr.getQuest(questID);
		if (NULL == pQuest) continue;
		const QuestConfig::QUESTTARGETLIST *pTarget = &pQuest->Target;
		for (int i_tar = pTarget->nCount-1; i_tar > -1; --i_tar)
		{
			//查找任务目标是对应类型
			const QuestConfig::QUESTTARGET *pTar = &pTarget->pTargetList[i_tar];
			if (pTar->nType == type)
			{
				if (id == pTar->nId)
					updateQuestTarget(questID, i_tar, nCount);
			}
		}
	}
}

bool CPlayerQuest::init()
{
	return true;
}

//清除已接列表
void CPlayerQuest::clearAcceptQuests()
{
	PlayerQuestData **ppAcceptList = m_AcceptQuestDataList;
	for (INT_PTR i = m_AcceptQuestDataList.count()-1; i > -1; --i)
		CGlobalLogicObjAlloc::freePlayerQuestData(ppAcceptList[i]);
	m_AcceptQuestDataList.clear();
}

//清除已完成列表
void CPlayerQuest::clearDoneQuests()
{
	PlayerDoneQuestData **ppDoneList = m_DoneQuestDataList;
	for (INT_PTR i = m_DoneQuestDataList.count()-1; i > -1; --i)
		CGlobalLogicObjAlloc::freePlayerDoneQuestData(ppDoneList[i]);
	m_DoneQuestDataList.clear();
}

//清除可接列表
void CPlayerQuest::clearCanAcceptQuests()
{
	m_CanAcceptQuestList.clear();
}

//加载任务数据
bool CPlayerQuest::loadData( CDataPacketReader &data )
{
	common::DBType::DataSectionHeader *pSecHdr;
	if (data.getAvaliableLength() < sizeof (*pSecHdr))
		return false;
	pSecHdr = (common::DBType::DataSectionHeader*)data.getOffsetPtr();
	if (pSecHdr->wDataType != common::SystemId::sysQuest)
	{
		logError( "角色(%lld:%s)数据的任务数据错误", 
			m_pPlayer->m_EntityId.llid, m_pPlayer->m_sName);
		return false;
	}
	data.adjustOffset(sizeof(*pSecHdr));
	unsigned short nDoneSize = 0;
	data >> nDoneSize;
	logError("数据库中已完成任务数量:%d\n", nDoneSize);
	//加载已完成任务
	if (!loadDoneQuestData(data, nDoneSize))
		return false;

	unsigned short nAcceptSize = 0;
	data >> nAcceptSize;
	logDebug("数据库中已接任务数量:%d\n", nAcceptSize);
	//加载已接任务
	if (!loadQuestData(data, nAcceptSize))
		return false;

	return true;
}

//加载已完成任务
bool CPlayerQuest::loadDoneQuestData( CDataPacketReader &data, unsigned short nDataCount )
{
	clearDoneQuests();

	PlayerDoneQuestData *pDoneQuestData; 
	m_DoneQuestDataList.reserve(nDataCount);
	for (int i = 0; i < nDataCount; ++i)
	{
		if (data.getAvaliableLength() < sizeof(*pDoneQuestData))
		{
			logError("角色(%lld:%s)数据的任务数据错误", 
				m_pPlayer->m_EntityId.llid, m_pPlayer->m_sName);
			return false;
		}
		pDoneQuestData = CGlobalLogicObjAlloc::allocPlayerDoneQuestData();
		data >> *pDoneQuestData;
		m_DoneQuestDataList.add(pDoneQuestData);
	}

	//判断已完成的任务的父任务
	CBList<PlayerDoneQuestData*> tempList;
	PlayerDoneQuestData **ppTemp = tempList;
	bool bRepeat = false;
	INT_PTR nCount = m_DoneQuestDataList.count();
	PlayerDoneQuestData **ppDQData = m_DoneQuestDataList;
	QuestAccessor &questMgr = g_ConfigManager->missionDataProvider;	
	for (INT_PTR i_DQList = 0; i_DQList < nCount; ++i_DQList)
	{
		const QuestConfig *pQuest = questMgr.getQuest(ppDQData[i_DQList]->questID);
		if (NULL == pQuest || -1 == pQuest->nParentId) continue;
		bool bFound = false;
		for (INT_PTR iDQ2 = 0; iDQ2 < nCount; ++iDQ2)
		{//查找在已完成列表内是否存在
			if (ppDQData[iDQ2]->questID == pQuest->nParentId)
			{
				bFound = true;
				break;
			}
		}
		if (!bFound)
		{//已完成列表没找到
			bRepeat = false;
			for (INT_PTR nTemp = tempList.count()-1; nTemp > -1; --nTemp)
			{//在临时已完成表中查找
				if (ppTemp[nTemp]->questID == pQuest->nParentId)
				{
					bRepeat = true;
					break;
				}
			}
			if (bRepeat) continue;//在临时已完成表中已存在,跳过
			PlayerDoneQuestData* pTemp = CGlobalLogicObjAlloc::allocPlayerDoneQuestData();
			pTemp->mask = QUEST_MASK_NOT_ALL_DONE;
			pTemp->questID = pQuest->nParentId;
			tempList.add(pTemp);
		}
	}
	m_DoneQuestDataList.addList(tempList);

	return true;
}

//加载已接任务
bool CPlayerQuest::loadQuestData( CDataPacketReader &data, unsigned short nDataSize )
{
	clearAcceptQuests();
	m_AcceptQuestDataList.reserve(nDataSize);

	PlayerQuestData *pQuestData;
	for (int i = 0; i < nDataSize; ++i)
	{
		pQuestData = CGlobalLogicObjAlloc::allocPlayerQuestData();
//		unsigned char nWriteCount = 0;
		data >> pQuestData->questID;			//任务ID
		data >> pQuestData->completeTimes;		//已完成次数
		data >> pQuestData->targetCount;		//目标个数
		data >> pQuestData->endTime;			//结束时间,0表示没有限制
		unsigned char nIndex = 0;
		unsigned char nCount = 0;
		const QuestConfig::QUESTTARGETLIST *pTargetList = g_ConfigManager->missionDataProvider.getQuestTargetList(pQuestData->questID);
		assert(NULL != pTargetList);
		for (int i = 0; i < pTargetList->nCount; ++i)
		{
			if (QuestConfig::EQUEST_TARGET_KILL == pTargetList->pTargetList[i].nType)
			{
				data >> nIndex;
				data >> nCount;
				pQuestData->target[nIndex] = nCount;
			}
			else//重新计算的任务目标进度
			{
				//#pragma __CPMSG__(TODO: ray: 需加上身上可判断的任务目标如背包中有的道具数量)
				int nType = pTargetList->pTargetList[i].nType;
				int nId = pTargetList->pTargetList[i].nId;
				if (QuestConfig::EQUEST_TARGET_GET_ITEM == nType)
				{
					pQuestData->target[i] = m_pPlayer->m_Bag.getItemCount(nId);;
				}
			}			
		}
		m_AcceptQuestDataList.add(pQuestData);
	}
	return true;
}

//保存任务数据
void CPlayerQuest::saveData( CDataPacket& data )
{
	size_t hdrPos = data.getPosition();//保存消息头位置
	common::DBType::DataSectionHeader *secHdr;
	data.adjustOffset(sizeof(*secHdr));

	size_t doneDataPos = data.getPosition();//保存已完成任务数据头位置
	unsigned short nDoneCount = 0;
	data.adjustOffset(sizeof(nDoneCount));
	//保存已完成任务
	unsigned short nDoneSize = saveDoneQuestData(data);

	size_t acceptDataPos = data.getPosition();//保存已接任务数据头位置
	unsigned short nAcceptCount = 0;
	data.adjustOffset(sizeof(nAcceptCount));
	//保存已接任务
	unsigned short nAcceptSize = saveQuestData(data);

	//写入数据头部
	secHdr = (DataSectionHeader*)data.getPositionPtr(hdrPos);
	secHdr->wDataType = common::SystemId::sysQuest;
	secHdr->wDataVersion = common::DBType::QuestDoneDataVersion;
	secHdr->wDataCount = (unsigned short)1;	
	secHdr->wStructSize = (unsigned short)(data.getPosition()-doneDataPos);//当前位置减去数据头位置
	//写入已完成任务的保存长度
	unsigned short* pDoneCount = (unsigned short*)data.getPositionPtr(doneDataPos);
	*pDoneCount = nDoneSize;
	//写入已接任务的保存长度
	unsigned short* pAcceptCount = (unsigned short*)data.getPositionPtr(acceptDataPos);
	*pAcceptCount = nAcceptSize;
}

//保存已完成任务,保存条件:1.还有子任务可接 2.没有子任务 3.没有父任务
unsigned short CPlayerQuest::saveDoneQuestData( CDataPacket &data )
{
	size_t nDataPos = data.getPosition();
	//筛选需要保存的已完成任务
	PlayerDoneQuestData** ppDoneQuestList = m_DoneQuestDataList;
	INT_PTR nCount = m_DoneQuestDataList.count();
	QuestAccessor &questMgr = g_ConfigManager->missionDataProvider;
	unsigned short *pNoParentList = questMgr.getNoParentQuestList();
	INT_PTR nNPQCount = questMgr.getNoParentQuestList().count();
	bool bFound = false;
	for (INT_PTR i_DoneList = 0; i_DoneList < nCount; ++i_DoneList)//已完成列表
	{
		bFound = false;
		PlayerDoneQuestData *pDoneQuest = ppDoneQuestList[i_DoneList];
		if (QUEST_MASK_ALL_DONE == pDoneQuest->mask)
		{
			data << pDoneQuest->mask << pDoneQuest->questID;
			continue;//需保存,找下一个
		}

		//#没有父任务的任务
		for (INT_PTR i_NoParentQuest = 0; i_NoParentQuest < nNPQCount; ++i_NoParentQuest)
		{
			if (pDoneQuest->questID != pNoParentList[i_NoParentQuest]) 
				continue;			
			const QuestConfig *pQuest = questMgr.getQuest(pNoParentList[i_NoParentQuest]);
			if (NULL == pQuest) continue;
			pDoneQuest->mask = QUEST_MASK_ALL_DONE;
			if (0 == pQuest->m_vSubQuest.nCount)
				continue;
			//查找有无未完成的子任务,如果有,则标记上mask为0
			for (INT_PTR i_find = 0; i_find < pQuest->m_vSubQuest.nCount; ++i_find)
			{
				bool bHaveNotDone = true;//标记是否有未完成的子任务
				for (INT_PTR i_DL = 0; i_DL < nCount; ++i_DL)
				{
					if (pQuest->m_vSubQuest.pQuest[i_find]->nQid == ppDoneQuestList[i_DL]->questID)
					{//在已完成列表中找到
						bHaveNotDone = false;
						break;
					}
				}
				if (bHaveNotDone)
				{
					(pDoneQuest)->mask = QUEST_MASK_NOT_ALL_DONE;
					break;
				}
			}
			data << (pDoneQuest)->mask << (pDoneQuest)->questID;
			bFound = true;
			break;	
		}
		if (bFound)	continue;//需保存,找下一个

		//#没有子任务的任务
		const QuestConfig *pQuest = questMgr.getQuest(pDoneQuest->questID);
		if (NULL == pQuest) continue;
		if (0 == pQuest->m_vSubQuest.nCount)
		{
			pDoneQuest->mask = QUEST_MASK_ALL_DONE;
			data << pDoneQuest->mask << pDoneQuest->questID;
			continue;//需保存,找下一个
		}

		//#还有子任务可接的任务
		unsigned short *usList = m_CanAcceptQuestList;
		INT_PTR nCAQCount = m_CanAcceptQuestList.count();
		for (INT_PTR i_CAQ = 0; i_CAQ < nCAQCount; ++i_CAQ)
		{
			if (usList[i_CAQ] == pDoneQuest->questID)
			{
				pDoneQuest->mask = QUEST_MASK_NOT_ALL_DONE;
				data << pDoneQuest->mask << pDoneQuest->questID;
				break;
			}
		}
	}
	return (unsigned short)((data.getPosition()-nDataPos)/sizeof(PlayerDoneQuestData));
}

//保存已接任务
unsigned short CPlayerQuest::saveQuestData( CDataPacket &data )
{
//	size_t nDataPos = data.getPosition();
	PlayerQuestData **ppPQDataList = m_AcceptQuestDataList;
	INT_PTR nListCount = m_AcceptQuestDataList.count();

	//#优化要保存的数据:把可以通过计算得到的数据去除
	QuestAccessor &questMgr = g_ConfigManager->missionDataProvider;
	CBList<PlayerQuestData*> saveQDList;
	for (INT_PTR i_list = 0; i_list < nListCount; ++i_list)
	{
		PlayerQuestData* pQData = ppPQDataList[i_list];
//		int nWriteCount = 0;//需要保存的个数
		const QuestConfig::QUESTTARGETLIST* pTargetList = questMgr.getQuestTargetList(pQData->questID);
		if (NULL == pTargetList)	continue;
		data << pQData->questID;						//任务ID
		data << pQData->completeTimes;					//已完成次数
		data << (unsigned char)pTargetList->nCount;		//目标个数:这里记录该任务的目标总数
		data << (int)pQData->endTime;					//结束时间,0表示没有限制

		for (INT_PTR i_target = 0; i_target < pTargetList->nCount; ++i_target)
		{
			if (QuestConfig::EQUEST_TARGET_KILL == pTargetList->pTargetList[i_target].nType)
			{
//#pragma __CPMSG__(TODO: ray: 要保存的任务目标类型未完全确认)
				//写入索引与个数
				data << (unsigned char) i_target;
				data << (unsigned char)pTargetList->pTargetList[i_target].nCount;//步骤数组
			}
		}
	}
	return (unsigned short)(nListCount);
}

//分派客户端消息
void CPlayerQuest::dispatchRecvPacket( int btCmd, CDataPacketReader &inPacket )
{
	switch(btCmd)
	{
	case common::NetCmd::cSendQuestAbort://放弃任务
		handlePlayerQuestAbort(inPacket);
		break;
	}
}

//发送任务列表到客户端
void CPlayerQuest::sendQuestDatas()
{
	logDebug("发送任务列表到客户端:");
	//初始化可接任务
	CBList<unsigned short> caqList;
	getAdditionCanAcceptList(caqList);

	INT_PTR nCount = m_CanAcceptQuestList.count();//可接任务个数
	INT_PTR nAcceptedCount = m_AcceptQuestDataList.count();//已接任务个数
	CGateSendPacket &packet = m_pPlayer->allocSendPacket();
	packet.writeCmd(common::SystemId::sysQuest, NetCmd::sSendQuestDatas);

	packet << (unsigned char)nCount;
	logDebug(" 可接任务--数量:%d,", nCount);
	if (nCount > 0)
	{//可接任务列表
		unsigned short *cList = m_CanAcceptQuestList;
		for (unsigned char i_canAccept = 0; i_canAccept < nCount; ++i_canAccept)
		{
			packet << cList[i_canAccept];
			logDebug("任务ID:%d\t", cList[i_canAccept]);
		}
		logDebug("\t");
	}

	packet << (unsigned char)nAcceptedCount;
	logDebug("已接任务数量:%d,", nAcceptedCount);
	if (nAcceptedCount > 0)
	{//已接任务详情
		PlayerQuestData** ppList = m_AcceptQuestDataList;
		for (INT_PTR i = nAcceptedCount-1; i > -1; --i)
		{
			packet << ppList[i]->questID;
			logDebug("任务ID:%d\n", ppList[i]->questID);
			packet << ppList[i]->completeTimes;
			packet << ppList[i]->targetCount;
			if (0 != ppList[i]->endTime)
				packet << (unsigned int)(ppList[i]->endTime - CMiniDateTime::now());//客户端只需要知道剩余时间,单位秒
			else
				packet << (unsigned int)(ppList[i]->endTime);

			for (unsigned char i_target = 0; i_target < ppList[i]->targetCount; ++i_target)
			{
				packet << ppList[i]->target[i_target];
			}
		}
		logDebug("\n");
	}
	packet.flush();
}

//发送添加已接任务
void CPlayerQuest::sendAddAcceptQuest( PlayerQuestData* pQuestData )
{
	CGateSendPacket &packet = m_pPlayer->allocSendPacket();
	packet.writeCmd(common::SystemId::sysQuest, NetCmd::sSendAddAcceptQuest);
	packet << pQuestData->questID;
	logDebug("发送添加已接任务:%d\n", pQuestData->questID);
	packet << pQuestData->completeTimes;
	packet << pQuestData->targetCount;
	if (0 != pQuestData->endTime)
		packet << (unsigned int)(pQuestData->endTime - CMiniDateTime::now());//客户端只需要知道剩余时间,单位秒
	else
		packet << (unsigned int)pQuestData->endTime;
	for (int i_target = 0; i_target < pQuestData->targetCount; ++i_target)
	{
		packet << pQuestData->target[i_target];
	}
	packet.flush();
}

//发送更新任务状态
void CPlayerQuest::sendUpdateAcceptQuest(unsigned short questID, unsigned char idx, unsigned char count)
{
	CGateSendPacket &packet = m_pPlayer->allocSendPacket();
	packet.writeCmd(common::SystemId::sysQuest, NetCmd::sSendUpdateAcceptQuest);
	packet << questID;
	logDebug("发送更新任务状态:%d\n", questID);
	packet << idx;
	packet << count;
	packet.flush();
}

//发送删除已接任务
void CPlayerQuest::sendDelAcceptQuest(unsigned short questID)
{
	CGateSendPacket &packet = m_pPlayer->allocSendPacket();
	packet.writeCmd(common::SystemId::sysQuest, NetCmd::sSendDelAcceptQuest);	
	packet << questID;
	logDebug("发送删除已接任务:%d\n", questID);
	packet.flush();
}

//判断能否接该任务
bool CPlayerQuest::checkCanAccept( unsigned short questID)
{
	QuestAccessor &questMgr = g_ConfigManager->missionDataProvider;
	const QuestConfig* pQuestCfg = questMgr.getQuest(questID);
	if (NULL == pQuestCfg) return false;

	//是否禁用
	if (pQuestCfg->boForbid)
		return false;

	//检查是否在已接列表存在	
	PlayerQuestData *pAcceptQuest = NULL;
	if (findAcceptQuest(&pAcceptQuest, questID)) 
		return false;
	//检查是否在已完成列表
	PlayerDoneQuestData **ppDQDList = m_DoneQuestDataList;
	for (INT_PTR i_dqdl = m_DoneQuestDataList.count()-1; i_dqdl > -1; --i_dqdl)
	{
		if (questID == ppDQDList[i_dqdl]->questID)
			return false;
	}
	//父任务是否完成
	if (-1 != pQuestCfg->nParentId)
	{
		PlayerDoneQuestData **ppList = m_DoneQuestDataList;
		bool bDone = false;
		for (INT_PTR i = m_DoneQuestDataList.count()-1; i > -1; --i)
		{
			if (ppList[i]->questID == pQuestCfg->nParentId)
			{
				bDone = true;
				break;
			}
		}
		if (!bDone)	return false;
	}
	//等级是否满足
	if (m_pPlayer->m_nLevel < pQuestCfg->nLevel)
		return false;
//#pragma __CPMSG__(TODO: ray: 任务可接限制待完善)
	return true;
}

//判断能否交该任务
bool CPlayerQuest::checkCanSubmit( unsigned short questID)
{
	QuestAccessor &questMgr = g_ConfigManager->missionDataProvider;
	const QuestConfig* pQuest = questMgr.getQuest(questID);
	if (NULL == pQuest)
		return false;
	if (pQuest->boForbid)
		return false;
	const QuestConfig::QUESTTARGETLIST *pTargetList = &pQuest->Target;
	if (NULL == pTargetList) return false;

	//判断在不在已接列表中
	PlayerQuestData *pPQData = NULL;
	if (!findAcceptQuest(&pPQData, questID)) return false;

	//判断任务目标
	if (0 <= pTargetList->nCount)
	{
		if (NULL == pPQData) return false;
		const QuestConfig::QUESTTARGET* pTar = pTargetList->pTargetList;
		int n = pTargetList->nCount;
		for (int i_tar = 0; i_tar < n; ++i_tar)
		{
			if (pPQData->target[i_tar] < pTar->nCount)
				return false;
		}
	}
	return true;
}


//接任务
void CPlayerQuest::acceptQuest( unsigned short questID)
{
	//新增已接任务
	const QuestConfig* pQuest = g_ConfigManager->missionDataProvider.getQuest(questID);
	if (NULL == pQuest) return;
	PlayerQuestData* pPQData = CGlobalLogicObjAlloc::allocPlayerQuestData();
	if (NULL == pPQData) return;

	pPQData->questID = questID;
	pPQData->completeTimes = 0;
	pPQData->targetCount = pQuest->Target.nCount;
	if (0 == pQuest->nTimeLimit)
		pPQData->endTime = 0;
	else
		pPQData->endTime = pQuest->nTimeLimit + CMiniDateTime::now();

	int n = pQuest->Target.nCount;
	QuestConfig::QUESTTARGET* pTargetList = pQuest->Target.pTargetList;
	for (int i_target = 0; i_target < n; ++i_target)
	{
		QuestConfig::PQUESTTARGET pT = &pTargetList[i_target];
		//如果是收集类的任务,则检查身上该物品的数量
		if (pT->nType == QuestConfig::EQUEST_TARGET_GET_ITEM)
		{
			int n = m_pPlayer->m_Bag.getItemCount(pT->nId);
			pPQData->target[i_target] = n > pT->nCount ? pT->nCount : n;
			continue;
		}
		pPQData->target[i_target] = 0;
	}
	m_AcceptQuestDataList.add(pPQData);
	sendAddAcceptQuest(pPQData);

	//删除可接任务ID
	unsigned short* pCanAccept = m_CanAcceptQuestList;	
	for (INT_PTR i_ca = m_CanAcceptQuestList.count()-1; i_ca > -1; --i_ca)
	{
		if (questID == pCanAccept[i_ca])
		{
			m_CanAcceptQuestList.remove(i_ca, 1);
			break;
		}
	}
	sendDelCanAcceptQuest(questID);
	m_pPlayer->sendMsg(PM_REF_NPC_QUEST_STATE, 0, 0, 0, 0, 0);	
}

//交任务的扣物品,奖励物品等处理
bool CPlayerQuest::submitQuestProcess(unsigned short questID)
{
//	const QuestConfig *pQuest = g_ConfigManager->missionDataProvider.getQuest(questID);
	const QuestConfig::QUESTTARGETLIST *pTargetList = g_ConfigManager->missionDataProvider.getQuestTargetList(questID);
	const QuestConfig::AWARDLIST *pAwardList = g_ConfigManager->missionDataProvider.getQuestAwardList(questID);
	if (NULL == pTargetList) return false;
	if (NULL == pAwardList) return false;
	//任务奖励发放
	if (0 < pAwardList->nCount)
	{
		for (int i = pAwardList->nCount-1; i > -1; --i)
		{
			const QuestConfig::AWARD *pAward = &pAwardList->pAwardList[i];
			if (QuestConfig::EQUEST_AWARD_ITEM == pAward->nType)
			{
				//#pragma __CPMSG__(TODO: ray: 背包能否放入该奖励的判断)
				m_pPlayer->m_Bag.addItem(pAward->nId, pAward->nCount, pAward->nQuality, pAward->nStrong, 0, false, 0, NULL);
			}
		}
	}

	//删除任务道具
	if (0 < pTargetList->nCount)
	{
		for (int i = pTargetList->nCount-1; i > -1; --i)
		{
			const QuestConfig::QUESTTARGET *pTar = &pTargetList->pTargetList[i];
			if (QuestConfig::EQUEST_TARGET_GET_ITEM == pTar->nType)
			{
				//#pragma __CPMSG__(TODO: ray: 交任务删除道具)
				m_pPlayer->m_Bag.delItem(pTar->nId, pTar->nCount, 0, "");
			}
		}
	}
	return true;
}

//交任务
void CPlayerQuest::submitQuest( unsigned short questID)
{
	//删除已接任务
	PlayerQuestData** ppQuestData = m_AcceptQuestDataList;
	for (INT_PTR i_accept = m_AcceptQuestDataList.count()-1; i_accept > -1; --i_accept)
	{
		if (questID == ppQuestData[i_accept]->questID)
		{
			//任务奖励处理
			if (!submitQuestProcess(questID)) return;

			m_AcceptQuestDataList.remove(i_accept, 1);
			sendDelAcceptQuest(questID);

			//更新已完成任务
			PlayerDoneQuestData *pDoneQuestData;
			pDoneQuestData = CGlobalLogicObjAlloc::allocPlayerDoneQuestData();
			pDoneQuestData->mask = QUEST_MASK_NOT_ALL_DONE;
			pDoneQuestData->questID	= questID;
			m_DoneQuestDataList.add(pDoneQuestData);

			//更新可接任务
			CBList<unsigned short> caqList;
			getAdditionCanAcceptList(caqList);
			unsigned short *pCAQ = caqList;
			for (INT_PTR i_caq = caqList.count()-1; i_caq > -1; --i_caq)
			{
				sendAddCanAcceptQuest(pCAQ[i_caq]);
			}
			m_pPlayer->sendMsg(PM_REF_NPC_QUEST_STATE, 0, 0, 0, 0, 0);
			break;
		}
	}
}

//发送添加可接任务
void CPlayerQuest::sendAddCanAcceptQuest(unsigned short questID)
{
	CGateSendPacket &packet = m_pPlayer->allocSendPacket();
	packet.writeCmd(common::SystemId::sysQuest, NetCmd::sSendAddCanAcceptID);	
	packet << questID;
	logDebug("发送添加可接任务%d\n", questID);
	packet.flush();
}

//发送删除可接任务
void CPlayerQuest::sendDelCanAcceptQuest(unsigned short questID)
{
	CGateSendPacket &packet = m_pPlayer->allocSendPacket();
	packet.writeCmd(common::SystemId::sysQuest, NetCmd::sSendDelCanAcceptID);	
	packet << questID;
	logDebug("发送删除可接任务%d\n", questID);
	packet.flush();
}

//放弃任务
void CPlayerQuest::handlePlayerQuestAbort( CDataPacketReader &inPacket )
{
	unsigned short questID = 0;
	inPacket >> questID;
	PlayerQuestData** ppQuestData = m_AcceptQuestDataList;
	for (INT_PTR i_accept = m_AcceptQuestDataList.count()-1; i_accept > -1; --i_accept)
	{
		if (questID == ppQuestData[i_accept]->questID)
		{
			const QuestConfig* pQuest = g_ConfigManager->missionDataProvider.getQuest(questID);
			if (NULL == pQuest) return;
			if (pQuest->boCanGiveUp)
			{
				//删除已接任务
				m_AcceptQuestDataList.remove(i_accept, 1);
				sendDelAcceptQuest(questID);
				//添加可接
				m_CanAcceptQuestList.add(questID);
				sendAddCanAcceptQuest(questID);
				//更新NPC状态
				m_pPlayer->sendMsg(PM_REF_NPC_QUEST_STATE, 0, 0, 0, 0, 0);
			}
			break;
		}
	}
}

//检查某个NPC上的任务状态
int CPlayerQuest::getNpcQuestState(unsigned long long npcId)
{
	QuestConfig **ppQuestList = g_ConfigManager->missionDataProvider.getQuestList();

	//1.检查身上的已接列表在该NPC上是否有关联
	PlayerQuestData **ppPQData = m_AcceptQuestDataList;	
	for (INT_PTR i = m_AcceptQuestDataList.count()-1; i > -1; --i)
	{
		QuestConfig *pQuest = ppQuestList[ppPQData[i]->questID];
		if (NULL == pQuest)	continue;
		//检查是否有任务可交
		if (pQuest->nEndNpc == (int)npcId)
		{
			if (checkCanSubmit(pQuest->nQid))
				return ENPC_QSTATE_SUBMIT;
		}
		//检查是否有对话
		QuestConfig::QUESTTARGETLIST *pTargetList = &pQuest->Target;
		if (0 < pTargetList->nCount)
		{
//			QuestConfig::QUESTTARGET *pTarList = pTargetList->pTargetList;
			for (int i = pTargetList->nCount-1; i > -1; --i )
			{
				//类型是NPC对话并且该对话未完成
				//if (QuestConfig::EQUEST_TARGET_TALK == pTarList[i].nType 
				//	&& pTarList[i].nId == npcId
				//	&& pTarList[i].nCount <= ppPQData[i]->target[i])
				//{
				//	return ENPC_QSTATE_SUBMIT;
				//}
			}
		}
	}
	//2.可接列表在该NPC上是否可接
	unsigned short *pnQuestId = m_CanAcceptQuestList;	
	for (INT_PTR i = m_CanAcceptQuestList.count()-1; i > -1; --i)
	{//遍历身上的可接任务
		QuestConfig *pQuest = ppQuestList[pnQuestId[i]];
		if (NULL == pQuest) continue;
		if (pQuest->nStartNpc == (int)npcId)
		{//该任务的接任务NPC是当前NPC,继续检查该任务是否可接
			if (checkCanAccept(pQuest->nQid))
				return ENPC_QSTATE_ACCEPT;
		}
	}
	//3.检查该NPC上是否有已接的任务
	for (INT_PTR i = m_AcceptQuestDataList.count()-1; i > -1; --i)
	{
		QuestConfig *pQuest = ppQuestList[ppPQData[i]->questID];
		if (NULL == pQuest)	continue;
		if (pQuest->nEndNpc == (int)npcId)	
		{//该任务的交任务NPC是当前NPC
			return ENPC_QSTATE_HAVE_ACCEPT;
		}
	}
	return ENPC_QSTATE_NONE;
}

//获取附加的可接任务列表
void CPlayerQuest::getAdditionCanAcceptList(CBList<unsigned short> &caqList)
{
	//1.已完成任务中查找未完成的子任务 
	PlayerDoneQuestData **ppDQData = m_DoneQuestDataList;
	INT_PTR nDQCount = m_DoneQuestDataList.count();
	QuestAccessor &questMgr = g_ConfigManager->missionDataProvider;
	for (INT_PTR i_DQ = 0; i_DQ < nDQCount; ++i_DQ)
	{
		if (QUEST_MASK_ALL_DONE == ppDQData[i_DQ]->mask) continue;
		const QuestConfig* pQuestCfg = questMgr.getQuest(ppDQData[i_DQ]->questID);
		if (NULL == pQuestCfg || 0 == pQuestCfg->m_vSubQuest.nCount) continue;

		bool bDone = false;
		for (INT_PTR i_subCount = 0; i_subCount < pQuestCfg->m_vSubQuest.nCount; ++i_subCount)
		{
			bDone = false;
			unsigned short subQuestID = pQuestCfg->m_vSubQuest.pQuest[i_subCount]->nQid;
			for (INT_PTR idxDQ = 0; idxDQ < nDQCount; ++idxDQ)
			{//拿子任务ID在已完成任务列表中遍历,如不存在则表示该子任务未完成
				bDone = false;
				if (ppDQData[idxDQ]->questID == subQuestID)
				{
					bDone = true;
					break;
				}
			}
			if (!bDone && checkCanAccept(subQuestID))
			{
				if (!checkCanAcceptRepeat(subQuestID))
				{
					m_CanAcceptQuestList.add(subQuestID);
					caqList.add(subQuestID);
				}
			}
		}
	}

	//2.NoParentList查找能否接
	unsigned short *pNoParentList = questMgr.getNoParentQuestList();
	INT_PTR nNPListCount = questMgr.getNoParentQuestList().count();
	for (INT_PTR i_NP = 0; i_NP < nNPListCount; ++i_NP)
	{
		unsigned short questID = pNoParentList[i_NP];
		if (checkCanAccept(questID))
		{
			if (!checkCanAcceptRepeat(questID))
			{
				m_CanAcceptQuestList.add(questID);
				caqList.add(questID);
			}
		}
	}
}

//检查可接任务是否重复
bool CPlayerQuest::checkCanAcceptRepeat(unsigned short questID)
{
	unsigned short* pCAQList = m_CanAcceptQuestList;
	for (INT_PTR i_CAQ = m_CanAcceptQuestList.count()-1; i_CAQ > -1; --i_CAQ)
	{
		if (pCAQList[i_CAQ] == questID)
			return true;
	}
	return false;
}

bool CPlayerQuest::findAcceptQuest(PlayerQuestData **ppPQData, unsigned short questID)
{
	PlayerQuestData **ppPQDList = m_AcceptQuestDataList;
	for (INT_PTR i_pqd = m_AcceptQuestDataList.count()-1; i_pqd > -1; --i_pqd)
	{
		if (ppPQDList[i_pqd]->questID == questID)
		{
			*ppPQData = ppPQDList[i_pqd];
			return true;
		}
	}
	return false;
}

//更新任务目标进度
void CPlayerQuest::updateQuestTarget(int questID, int tarIdx, int tarAddCount)
{
	QuestAccessor &questMgr = g_ConfigManager->missionDataProvider;
	const QuestConfig::QUESTTARGETLIST *pTargetList = questMgr.getQuestTargetList(questID);
	if (NULL == pTargetList) return;
	
	assert(tarIdx < pTargetList->nCount && tarIdx >= 0);

	//查找是否在已接列表中
	PlayerQuestData *pQuestData = NULL;
	if (!findAcceptQuest(&pQuestData, questID)) return;

	//目标是否已完成
	if (pTargetList->pTargetList[tarIdx].nCount <= pQuestData->target[tarIdx]) return;

	//更新任务进度
	pQuestData->target[tarIdx]++;
	sendUpdateAcceptQuest(questID, tarIdx, pQuestData->target[tarIdx]);
	if (checkCanSubmit(questID))
	{
		m_pPlayer->sendMsg(PM_REF_NPC_QUEST_STATE, 0, 0, 0, 0, 0);
	}
}

//GM命令:清除所有任务
void CPlayerQuest::clearAllQuest()
{
	clearAcceptQuests();
	clearDoneQuests();
	clearCanAcceptQuests();
	sendQuestDatas();
	m_pPlayer->sendMsg(PM_REF_NPC_QUEST_STATE, 0, 0, 0, 0, 0);
}

//GM命令:接受任务
void CPlayerQuest::addQuest( unsigned short questID )
{
	acceptQuest(questID);
}
