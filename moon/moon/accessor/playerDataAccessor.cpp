#include "StdAfx.h"

PlayerDataAccessor::PlayerDataAccessor():super()
{
	m_Levels.setLength(MAX_LEVEL + 1);
}

PlayerDataAccessor::~PlayerDataAccessor()
{

}

const CFPlayerLevel* PlayerDataAccessor::getLevel(int level) const
{
	if (level < 0) level = 0;
	else if (level > MAX_LEVEL)
		level = MAX_LEVEL;
	return &m_Levels.ptr()[level];
}

bool PlayerDataAccessor::loadConfig()
{
	/*CSVDocument doc;

#define DCL(name, fn) {\
	if (!CConfigManager::LoadCSVDocument(doc, "./config/"name))\
	return false;\
	fn(doc); }
#define DCLI(name, fn, i) {\
	if (!CConfigManager::LoadCSVDocument(doc, "./config/"name))\
	return false;\
	fn(doc, i); }

	DCL("player/LevelConfig.csv", readExpConfig);
	DCLI("player/Job1LevelAttr.csv", readJobLevelAttrConfig, 0);
	DCLI("player/Job2LevelAttr.csv", readJobLevelAttrConfig, 1);
	DCLI("player/Job3LevelAttr.csv", readJobLevelAttrConfig, 2);*/

	return true;
}

//void PlayerDataAccessor::readExpConfig(SG2DEX::CSVDocument &doc)
//{
//	const int cLevel = doc.getColumnIndex(UTF8String("\xE7\xAD\x89\xE7\xBA\xA7"));
//	const int cExp = doc.getColumnIndex(UTF8String("\xE5\x8D\x87\xE7\xBA\xA7\xE7\xBB\x8F\xE9\xAA\x8C"));
//
//	CFPlayerLevel *levels = m_Levels.own_ptr();
//	const int numRows = (int)doc.numRows();
//	for (int i=0; i<numRows; ++i)
//	{
//		int nLvl = doc.getValue(i, cLevel);
//		if (nLvl >= 0 && nLvl <= MAX_LEVEL)
//		{
//			CFPlayerLevel &level = levels[nLvl];
//			level.expMax = (long long)((double)doc.getValue(i, cExp));
//		}
//	}
//}
//
//void CFPlayerLevelProvider::readJobLevelAttrConfig(SG2DEX::CSVDocument &doc, int job)
//{
//	const int cLevel = doc.getColumnIndex(UTF8String("\xE7\xAD\x89\xE7\xBA\xA7"));
//	const int cBiLi = doc.getColumnIndex(UTF8String("\xE8\x87\x82\xE5\x8A\x9B"));
//	const int cLingQiao = doc.getColumnIndex(UTF8String("\xE7\x81\xB5\xE5\xB7\xA7"));
//	const int cTiPo = doc.getColumnIndex(UTF8String("\xE4\xBD\x93\xE9\xAD\x84"));
//	const int cNeiXi = doc.getColumnIndex(UTF8String("\xE5\x86\x85\xE6\x81\xAF"));
//	const int cGangQi = doc.getColumnIndex(UTF8String("\xE7\xBD\xA1\xE6\xB0\x94"));
//	const int cWaiGong = doc.getColumnIndex(UTF8String("\xE5\xA4\x96\xE5\x8A\x9F"));
//	const int cNeiGong = doc.getColumnIndex(UTF8String("\xE5\x86\x85\xE5\x8A\x9F"));
//	const int cWaiFang = doc.getColumnIndex(UTF8String("\xE5\xA4\x96\xE9\x98\xB2"));
//	const int cNeiFang = doc.getColumnIndex(UTF8String("\xE5\xA4\x96\xE9\x98\xB2"));
//	const int cWaiFangCT = doc.getColumnIndex(UTF8String("\xE5\xA4\x96\xE9\x98\xB2\xE7\xA9\xBF\xE9\x80\x8F"));
//	const int cNeiFangCT = doc.getColumnIndex(UTF8String("\xE5\x86\x85\xE9\x98\xB2\xE7\xA9\xBF\xE9\x80\x8F"));
//	const int cQiXue = doc.getColumnIndex(UTF8String("\xE6\xB0\x94\xE8\xA1\x80"));
//	const int cNeiLi = doc.getColumnIndex(UTF8String("\xE5\x86\x85\xE5\x8A\x9B"));
//	const int cWaiBao = doc.getColumnIndex(UTF8String("\xE5\xA4\x96\xE6\x9A\xB4\xE5\x87\xBB"));
//	const int cNeiBao = doc.getColumnIndex(UTF8String("\xE5\x86\x85\xE6\x9A\xB4\xE5\x87\xBB"));
//	const int cKangWaiBao = doc.getColumnIndex(UTF8String("\xE6\x8A\x97\xE5\xA4\x96\xE6\x9A\xB4"));
//	const int cKangNeiBao = doc.getColumnIndex(UTF8String("\xE6\x8A\x97\xE5\x86\x85\xE6\x9A\xB4"));
//	const int cMingZhong = doc.getColumnIndex(UTF8String("\xE5\x91\xBD\xE4\xB8\xAD"));
//	const int cShanBi = doc.getColumnIndex(UTF8String("\xE9\x97\xAA\xE9\x81\xBF"));
//	const int cHitSpeed = doc.getColumnIndex(UTF8String("\xE6\x94\xBB\xE5\x87\xBB\xE9\x80\x9F\xE5\xBA\xA6"));
//	const int cMoveSpeed = doc.getColumnIndex(UTF8String("\xE7\xA7\xBB\xE5\x8A\xA8\xE9\x80\x9F\xE5\xBA\xA6"));
//	const int cQiXueHuiFu = doc.getColumnIndex(UTF8String("\xE6\xB0\x94\xE8\xA1\x80\xE6\x81\xA2\xE5\xA4\x8D\xE9\x80\x9F\xE5\xBA\xA6"));
//	const int cNeiLiHuiFu = doc.getColumnIndex(UTF8String("\xE5\x86\x85\xE5\x8A\x9B\xE6\x81\xA2\xE5\xA4\x8D\xE9\x80\x9F\xE5\xBA\xA6"));
//	const int cFuYuan = doc.getColumnIndex(UTF8String("\xE7\xA6\x8F\xE7\xBC\x98"));
//
//	CFPlayerLevel *levels = m_Levels.own_ptr();
//	const int numRows = (int)doc.numRows();
//	for (int i=0; i<numRows; ++i)
//	{
//		int nLvl = doc.getValue(i, cLevel);
//		if (nLvl >= 0 && nLvl <= MAX_LEVEL)
//		{
//			ActorAbilData &abil = levels[nLvl].jobAbils[job];
//			abil.biLi = doc.getValue(i, cBiLi);
//			abil.lingQiao = doc.getValue(i, cLingQiao);
//			abil.tiPo = doc.getValue(i, cTiPo);
//			abil.neiXi = doc.getValue(i, cNeiXi);
//			abil.gangQi = doc.getValue(i, cGangQi);
//			abil.waiGong = doc.getValue(i, cWaiGong);
//			abil.neiGong = doc.getValue(i, cNeiGong);
//			abil.waiFang = doc.getValue(i, cWaiFang);
//			abil.neiFang = doc.getValue(i, cNeiFang);
//			abil.waiFangCT = doc.getValue(i, cWaiFangCT);
//			abil.neiFangCT = doc.getValue(i, cNeiFangCT);
//			abil.qiXue = doc.getValue(i, cQiXue);
//			abil.neiLi = doc.getValue(i, cNeiLi);
//			abil.waiBao = doc.getValue(i, cWaiBao);
//			abil.neiBao = doc.getValue(i, cNeiBao);
//			abil.kangWaiBao = doc.getValue(i, cKangWaiBao);
//			abil.kangNeiBao = doc.getValue(i, cKangNeiBao);
//			abil.shanBi = doc.getValue(i, cShanBi);
//			abil.mingZhong = doc.getValue(i, cMingZhong);
//			abil.hitSpeed = doc.getValue(i, cHitSpeed);
//			abil.moveSpeed = doc.getValue(i, cMoveSpeed);
//			abil.qiXueHuiFu = doc.getValue(i, cQiXueHuiFu);
//			abil.neiLiHuiFu = doc.getValue(i, cNeiLiHuiFu);
//			abil.fuYuan = doc.getValue(i, cFuYuan);
//		}
//	}
//}

