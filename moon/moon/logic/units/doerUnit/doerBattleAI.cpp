#include "StdAfx.h"

//怪物普通攻击最大距离
static const int NormalAttackDistX = 120;
static const int NormalAttackDistY = 60;

void CDoerBattle::runAI(TickTime dwCurrTick)
{
	if (m_pActor->m_boDead)
		return;
	//如果没有目标则进行目标确定或搜索
	if (!m_pTargetActor)
	{
		//如果存在攻击者，且攻击者可以被自身攻击，则设置攻击者为目标
		if (m_pLastHiter && isAttackableActor(m_pLastHiter))
		{
			setTargetActor(m_pLastHiter);
		}
		//不存在攻击者且怪物自身是主动型怪物，则主动搜索目标
		else if ((m_dwMonFlags & monsterStruct::mfInitiative))
		{
			//如果怪物处于回归状态，则检查是满足结束回归状态的条件
			if (m_boReturning)
			{
				m_boReturning = (abs(m_pActor->m_nX - m_pActor->m_nBornX) >= 180) 
					|| (abs(m_pActor->m_nY - m_pActor->m_nBornY) >= 180);
			}
			//不处于回归状态则搜索目标
			else if (dwCurrTick >= m_dwNextSearchTargetTick)
			{
				searchTarget();
			}
		}
	}
	//如果有目标则优先尝试攻击目标
	if (m_pTargetActor && dwCurrTick >= m_dwOutOfAttackEndTime)
	{
		if (!isAttackableActor(m_pTargetActor))
			setTargetActor(NULL);
		else attackTargetActor();
	}
	//如果具有移动目的地则继续移动
	if (m_nTargetX > -1 && m_nTargetY > -1 && dwCurrTick >= m_dwOutOfMoveEndTime)
	{
		moveToTarget();
	}
	else if (m_dwRunStartTick)
	{
		stopMove();
	}
}

void CDoerBattle::searchTarget()
{
	CDoer* pPrimaryActor = NULL;
	int nMinDistance = INT_MAX;

	m_dwNextSearchTargetTick = g_LogicEngine->getTickCount() + 500;
	CDoer::ViewStruct *viewList = m_pActor->m_ViewList;
	for (INT_PTR i=m_pActor->m_ViewList.count()-1; i>-1; --i)
	{
		if (viewList->pEntity->m_btType == ePlayer)
		{
			CPlayer *player = (CPlayer *)viewList->pEntity;
			if (isAttackableActor(player))
			{
				int dx = abs(player->m_nX - m_pActor->m_nX);
				int dy = abs(player->m_nY - m_pActor->m_nY);
				int dist = (dx < dy) ? dx : dy;
				if (!pPrimaryActor || dist < nMinDistance)
				{
					pPrimaryActor = player;
					nMinDistance = dist;
				}
			}
		}
		viewList++;
	}

	if (pPrimaryActor)
	{
		setTargetActor(pPrimaryActor);
	}
}

void CDoerBattle::attackTargetActor()
{
	const TickTime dwCurrTick = g_LogicEngine->getTickCount();
	const monsterStruct* pStdMon = g_ConfigManager->monsterDataAccessor.getMonsterById(m_pActor->m_wMonId);

	bool inAttackRange = false;
	if (m_pTargetActor->m_Battle.m_dwRunStartTick)
	{
		int newX, newY;
		m_pTargetActor->m_Battle.calcNewPositionAtTime(dwCurrTick + pStdMon->paActTime, newX, newY);
		newX = abs(newX - m_pActor->m_nX);
		newY = abs(newY - m_pActor->m_nY);
		inAttackRange = newX <= 60 && newY <= 30;
	}

	if (!inAttackRange)
	{
		int dx = abs(m_pTargetActor->m_nX - m_pActor->m_nX);
		int dy = abs(m_pTargetActor->m_nY - m_pActor->m_nY);
		inAttackRange = dx <= NormalAttackDistX && dy <= NormalAttackDistY;
	}

	//自身与目标处于攻击范围内，则进行攻击
	if (inAttackRange)
	{
		//攻击前先停止移动
		if (m_nTargetX > -1)
			setMoveTarget(-1, -1);
		m_pActor->m_btDirection = m_pTargetActor->m_nX >= m_pActor->m_nX ? 1 : 0;
		//攻击前施加逻辑硬直
		const int overTick = m_pActor->m_wAttackTime ? m_pActor->m_wAttackTime : 500;
		outOfControl(overTick + randValue(200), m_pActor->m_wAttackInterval + randValue(200));
		//进行攻击
		m_dwMonNormalAttackPrepareEndTick = dwCurrTick + pStdMon->paPrepareTime;
		m_dwMonNormalAttackTakeEffectTick = dwCurrTick + pStdMon->paActTime;
		broadcastNormalAttack(m_pActor->m_btDirection, 0);
	}
	else
	{
		int dx, dy;

		//超出目标追击距离则回归到出生位置
		if (pStdMon->sickRange)
		{
			dx = abs(m_pActor->m_nBornX - m_pActor->m_nX);
			dy = abs(m_pActor->m_nBornY - m_pActor->m_nY);
			if (dx > pStdMon->sickRange || dy > pStdMon->sickRange)
			{
				setTargetActor(NULL);
				setLastHiter(NULL);
				setMoveTarget(m_pActor->m_nBornX, m_pActor->m_nBornY);
				m_boReturning = true;
				return;
			}
		}
		m_boReturning = false;
		//自身移动目的地与目标的位置相差超过一定范围，则重新设定移动目的地
		dx = abs(m_pTargetActor->m_nX - m_pActor->m_nX);
		dy = abs(m_pTargetActor->m_nY - m_pActor->m_nY);
		if (m_nTargetX < 0 || dx >= NormalAttackDistX || dy >= NormalAttackDistY)
		{
			setMoveTarget(m_pTargetActor->m_nX, m_pTargetActor->m_nY);
		}
	}
}

void CDoerBattle::moveToTarget()
{
	int speedX = m_pActor->m_wMoveSpeed;
	int speedY = m_pActor->m_wMoveSpeed / 2;
	const int dx = m_nTargetX - m_pActor->m_nX;
	const int dy = m_nTargetY - m_pActor->m_nY;

	if (dx <= -NormalAttackDistX) speedX = -speedX;
	else if (dx < NormalAttackDistX) speedX = 0;
	if (dy <= -NormalAttackDistY) speedY = -speedY;
	else if (dy < NormalAttackDistX) speedY = 0;
	if (speedX != 0 || speedY != 0)
	{
		if (!m_dwRunStartTick || speedX != m_nRunSpeedX || speedY != m_nRunSpeedY)
		{
			if (speedX < 0)
				m_pActor->m_btDirection = 0;
			else if (speedX > 0)
				m_pActor->m_btDirection = 1;
			startMove(speedX, speedY, 0);
		}
	}
	else if (m_dwRunStartTick)
		stopMove();
}

void CDoerBattle::scatterMonItems(CDoer *onwer)
{
	const monsterStruct *pStdMon = g_ConfigManager->monsterDataAccessor.getMonsterById(m_pActor->m_wMonId);
	const MonDropData *dropData = pStdMon->dropData;
	if (!dropData)
		return;
	bool GroupMasks[256] = {0};
	SendClientDropItem sendData;

	for (int i=dropData->numItems-1; i>-1; --i)
	{
		const MonDropItem *monItem = dropData->items[i];
		//相同的组已经掉落了物品，则不再继续掉落
		if (monItem->group && GroupMasks[monItem->group])
			continue;
		if (randValue(monItem->base) < monItem->rate)
		{
			GroupMasks[monItem->group] = true;

			DropItemData *dropItem = g_LogicEngine->allocDropItem();
			dropItem->ownerId = onwer->m_EntityId;
			dropItem->itemId = monItem->itemId;
			if (monItem->randCount > 1)
				dropItem->itemCount = monItem->minCount + randValue(monItem->randCount);
			else dropItem->itemCount = monItem->minCount;
			if (monItem->randQuality > 1)
				dropItem->quality = monItem->minQuality + randValue(monItem->randQuality);
			else dropItem->quality = monItem->minQuality;
			if (monItem->randStrong > 1)
				dropItem->strong = monItem->minStrong + randValue(monItem->randStrong);
			else dropItem->strong = monItem->minStrong;

			//向归属者发送掉落物品消息
			if (onwer->m_btType == ePlayer)
			{
				sendData.series = dropItem->series;
				sendData.serverIdent = dropItem->serverIdent;
				sendData.itemId = dropItem->itemId;
				sendData.itemCount = dropItem->itemCount;
				sendData.quality = dropItem->quality;
				sendData.strong = dropItem->strong;
				sendData.x = m_pActor->m_nX;
				sendData.y = m_pActor->m_nY;
				CGateSendPacket &pack = ((CPlayer*)onwer)->allocSendPacket();
				pack.writeCmd(sysBattle, sItemDrop);
				pack << m_pActor->m_EntityId;
				pack << sendData;
				pack.flush();
			}
		}
	}
}

