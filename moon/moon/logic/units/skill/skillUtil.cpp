#include "StdAfx.h"
#include "logic/map/SceneFile.h"
#include "skillUtil.h"

namespace SkillUtil
{
	bool isEnemyActor(CDoer *sponsor, CDoer *actor)
	{
		int sType = sponsor->m_btType;
		int tType = actor->m_btType;
		//自己不是敌人
		if (actor == sponsor)
			return false;
		//对话NPC不是敌人
		if (tType == eNPC)
			return false;
		//怪物不是怪物的敌人
		if (tType >= eNormalMonster && tType < eNPC && sType >= eNormalMonster && sType < eNPC)
			return false;
		return true;
	}

	bool isFriendActor(CDoer *sponsor, CDoer *actor)
	{
		return false;
	}

	void timeRect2GameRect(GRect &rect, CDoer *sponsor, const GPoint *center, const CFSkillTimePoint *timePoint)
	{
		rect.y = center->y + timePoint->top;
		rect.height = timePoint->bottom - timePoint->top;
		if (sponsor->m_btDirection == 1)
			rect.x = center->x + timePoint->left;
		else rect.x = center->x - timePoint->right;
		rect.width = timePoint->right - timePoint->left;
	}

	int calcDir8OfSpeed(int sx, int sy)
	{
		if (sx < 0)
		{
			if (sy < 0)
				return 7;
			if (sy > 0)
				return 5;
			return 6;
		}
		else if (sx > 0)
		{
			if (sy < 0)
				return 1;
			if (sy > 0)
				return 3;
			return 2;
		}
		else 
		{
			if (sy < 0)
				return 0;
			if (sy > 0)
				return 4;
		}
		return 2;//by default
	}

	int calcDir8OfPosition(int cx, int cy, int tx, int ty)
	{
		if (tx < cx)
		{
			if (ty < cy)
				return 7;
			if (ty > cy)
				return 5;
			return 6;
		}
		else if (tx > cx)
		{
			if (ty < cy)
				return 1;
			if (ty > cy)
				return 3;
			return 2;
		}
		else
		{
			if (ty < cy)
				return 0;
			if (ty > cy)
				return 4;
		}
		return 2;//by default
	}

	bool fixMovePoint(Scene *scene, int sx, int sy, int &dx, int &dy)
	{
		MapArchiver* map = scene->getSceneMap();
		if (!map)
			return false;

		if (sx < 0) sx = 0;
		else if (sx >= map->m_nWidth) sx = map->m_nWidth;
		if (sy < 0) sy = 0;
		else if (sy >= map->m_nHeight) sy = map->m_nHeight;

		if (dx < 0) dx = 0;
		else if (dx >= map->m_nWidth) dx = map->m_nWidth;
		if (dy < 0) dy = 0;
		else if (dy >= map->m_nHeight) dy = map->m_nHeight;


		double uX = sx / MapArchiver::UnitWidth;
		double uY = sy / MapArchiver::UnitHeight;
		double uDX = dx / MapArchiver::UnitWidth;
		double uDY = dy / MapArchiver::UnitHeight;

		if ((int)uX == (int)uDX && (int)uY == (int)uDY)
			return true;
		double px = uDX - uX, py = uDY - uY;
		int dist = max(1, max(abs((int)px), abs((int)py)));

		px = px / dist;
		py = py / dist;
		for (int i=dist-1; i>-1; --i)
		{
			double newX = uX + px;
			double newY = uY + py;
			unsigned char masks = map->getPointMask((int)newX, (int)newY);
			if (masks & MapArchiver::MoveMask)
			{
				uX = newX;
				uY = newY;
			}
			else
			{
				dx = (int)(uX * MapArchiver::UnitWidth);
				dy = (int)(uY * MapArchiver::UnitHeight);
				return false;
			}
		}
		return true;
	}

	int getRangeActors(CBList<CDoer*> &list, CDoer *sponsor, const GRect &rect, int filter)
	{
		int result = 0;
		CDoer::ViewStruct *viewList = sponsor->m_ViewList;
		GRect impactRect;
		for (INT_PTR i=sponsor->m_ViewList.count()-1; i>-1; --i)
		{
			if (viewList[i].pEntity->m_btType < eActor)
				continue;
			CDoer *actor = (CDoer *)viewList[i].pEntity;
			
			if ((filter & afEnemy) && !isEnemyActor(sponsor, actor))
				continue;
			if ((filter &afFriend) && !isFriendActor(sponsor, actor))
				continue;

			impactRect = actor->m_ImpactRect;
			impactRect.x += actor->m_nX;
			impactRect.y += actor->m_nY;
			if (impactRect.intersects(rect))
			{
				list.add(actor);
				result++;
			}
		}
		return result;
	}

	const CFSkillPostureLevel* getNormalAttackPosture(int job, int index)
	{
		//各职业普通攻击技能ID表
		static const CFSkill *skillList[] = {
			g_ConfigManager->skillDataAccessor.getSkillById(1),
			g_ConfigManager->skillDataAccessor.getSkillById(2),
			g_ConfigManager->skillDataAccessor.getSkillById(3),
		};
		const CFSkillPosture *stdPosture = skillList[job]->postures[index];
		const CFSkillPostureLevel *posture = stdPosture->levels[0];
		return posture;
	}
}
