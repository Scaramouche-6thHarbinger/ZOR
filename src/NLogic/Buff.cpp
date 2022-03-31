/*
 * Buff.cpp
 *
 *  Created on: 2013. 10. 21.
 *      Author: jjaehuny
 */

#include <Buff.h>
#include <time.h>
#include <User.h>

namespace NLogic {

Buff::Buff(User * pUser) : _clsBuffVector(static_cast<int>(BuffType::__MAX__)), _user(pUser), _expConstVIP(0), _itemDropConstVIP(0)
{
	for (int i = static_cast<int>(BuffType::WINPOINT); i < static_cast<int>(BuffType::__MAX__); ++i)
	{
		_clsBuffVector[i] = new Data;
	}
}

Buff::~Buff()
{
	for (int i = static_cast<int>(BuffType::WINPOINT); i < static_cast<int>(BuffType::__MAX__); ++i)
	{
		delete _clsBuffVector[i];
	}
}

void
Buff::Initialize()
{
	for (int i = static_cast<int>(BuffType::WINPOINT); i < static_cast<int>(BuffType::__MAX__); ++i)
	{
		_clsBuffVector[i]->Clear();
	}
}

void
Buff::Finalize()
{
	for (int i = static_cast<int>(BuffType::WINPOINT); i < static_cast<int>(BuffType::__MAX__); ++i)
	{
		_clsBuffVector[i]->Clear();
	}
}

Buff::Data *
Buff::GetData(Buff::BuffType eBuffType)
{
	return _clsBuffVector[static_cast<int>(eBuffType)];
}

int
Buff::GetActiveBuffCount(unsigned int nTime)
{
	int activeBuffCount = 0;

	for (int i = static_cast<int>(BuffType::WINPOINT); i < static_cast<int>(BuffType::__MAX__); ++i)
	{
		Data * pData = _clsBuffVector[i];

		if (pData->_regdate < nTime)
			pData->Clear();
		else
			activeBuffCount++;
	}

	return activeBuffCount;
}

void
Buff::SetVIPBuff()
{
	LOGW("TODO : Buff::SetVIPBuff()");
	/**
	if (false == NResource::Static::Instance().GetContentsOpenResource()->IsOpen(VIP_SYSTEM))
	{
		DEBUGLOG("false == NResource::Static::Instance().GetContentsOpenResource()->IsOpen(VIP_SYSTEM)");
		return;
	}

	NResource::VIPResource::Data & vipData = NResource::Static::Instance().GetVIPResource()->GetData();

	int vipType = 0;
	if (vipData._VIP3_VP <= _user->GetUserInfo().reserve4)
		vipType = 3;
	else if (vipData._VIP2_VP <= _user->GetUserInfo().reserve4)
		vipType = 2;
	else if (vipData._VIP1_VP <= _user->GetUserInfo().reserve4)
		vipType = 1;

	NResource::VIPSkillBuffData::Flyweight * pFlyVip = NResource::Static::Instance().GetVIPResource()->GetFly(vipType);

	if (NULL != pFlyVip)
	{
		_expConstVIP		= pFlyVip->_EXP_CONST;
		_itemDropConstVIP	= pFlyVip->_ITEM_DROP_CONST;

		NResource::VIPResource::Data & vipData = NResource::Static::Instance().GetVIPResource()->GetData();

		int vipPoint = _user->GetUserInfo().reserve4 - vipData._VIP1_VP;

		time_t buffTime = 0;
		if (vipPoint < vipData._MINUS_VP_AMOUNT_PER_PERIOD)
			buffTime = vipData._MINUS_VP_MIN_PERIOD  * 60;
		else
		{
			if (0 < vipPoint % vipData._MINUS_VP_AMOUNT_PER_PERIOD)
				buffTime = (vipPoint / vipData._MINUS_VP_AMOUNT_PER_PERIOD) * (vipData._MINUS_VP_MIN_PERIOD  * 60) + vipData._MINUS_VP_MIN_PERIOD  * 60;
			else
				buffTime = (vipPoint / vipData._MINUS_VP_AMOUNT_PER_PERIOD) * (vipData._MINUS_VP_MIN_PERIOD  * 60);
		}

		NLogic::Buff::Data * pBuffData1 = _user->GetBuff()->GetData(NLogic::Buff::BuffType::VIP1);
		if (NULL != pBuffData1 && 0 < pFlyVip->_SKILL1_TID)
		{
			pBuffData1->u8type = static_cast<int32_t>(NLogic::Buff::BuffType::VIP1);
			pBuffData1->u16skill_tid = pFlyVip->_SKILL1_TID;
			pBuffData1->s16skill_value = pFlyVip->_SKILL1_VALUE;
			pBuffData1->u8skill_level = pFlyVip->_SKILL1_LEVEL;

			if (_user->GetUserInfo().reserve3 > _user->GetUserInfo().reserve5)
				pBuffData1->_regdate = _user->GetUserInfo().reserve3 + buffTime;
			else
				pBuffData1->_regdate = _user->GetUserInfo().reserve5 + buffTime;
		}

		NLogic::Buff::Data * pBuffData2= _user->GetBuff()->GetData(NLogic::Buff::BuffType::VIP2);
		if (NULL != pBuffData2 && 0 < pFlyVip->_SKILL2_TID)
		{
			pBuffData2->u8type = static_cast<uint32_t>(NLogic::Buff::BuffType::VIP2);
			pBuffData2->u16skill_tid = pFlyVip->_SKILL2_TID;
			pBuffData2->s16skill_value = pFlyVip->_SKILL2_VALUE;
			pBuffData2->u8skill_level = pFlyVip->_SKILL2_LEVEL;

			if (_user->GetUserInfo().reserve3 > _user->GetUserInfo().reserve5)
				pBuffData2->_regdate = _user->GetUserInfo().reserve3 + buffTime;
			else
				pBuffData2->_regdate = _user->GetUserInfo().reserve5 + buffTime;
		}
	}
	else
	{
		_expConstVIP		= 0;
		_itemDropConstVIP	= 0;
	}

	_user->FlushUserInfoCache();
	**/
}

void
Buff::RefleshVIPBuff()
{
	LOGW("TODO : Buff::RefleshVIPBuff()");
	/**
	if (0 >= _user->GetUserInfo().reserve3)
		return;

	NResource::VIPResource::Data & vipData = NResource::Static::Instance().GetVIPResource()->GetData();

	time_t curtime = time(NULL);
	time_t lastTime = 0;
	if (_user->GetUserInfo().reserve3 > _user->GetUserInfo().reserve5)
		lastTime = curtime - _user->GetUserInfo().reserve3;
	else
		lastTime = curtime - _user->GetUserInfo().reserve5;

	if (lastTime < vipData._MINUS_VP_MIN_PERIOD * 60)
		return;

	if (static_cast<int>(_user->GetUserInfo().reserve4) > lastTime / (vipData._MINUS_VP_MIN_PERIOD * 60) * vipData._MINUS_VP_AMOUNT_PER_PERIOD)
		_user->GetUserInfo().reserve4 -= lastTime / (vipData._MINUS_VP_MIN_PERIOD * 60) * vipData._MINUS_VP_AMOUNT_PER_PERIOD;
	else
		_user->GetUserInfo().reserve4 = 0;

	_user->GetUserInfo().reserve5 = curtime;

	SetVIPBuff();
	**/
}

int
Buff::GetExpConstVIP()
{
	RefleshVIPBuff();
	return _expConstVIP;
}

int
Buff::GetItemDropConstVIP()
{
	RefleshVIPBuff();
	return _itemDropConstVIP;
}

} /*NLogic*/