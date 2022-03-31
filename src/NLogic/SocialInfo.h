/*
 * SocialInfo.h
 *
 *  Created on: 2013. 10. 28.
 *      Author: the2
 */

#ifndef SOCIALINFO_H_
#define SOCIALINFO_H_

#include <string>

namespace ProjectZ {
namespace NLogic {

class SocialInfo {

public:
	// 파티 초대 차단 여부.
	enum class EnumInviteState : int {
		__NONE__ = -1,

		ALL_BLOCK,					// 0 : 모두 차단,
		DUNGEON_ON,				// 1 : 던전 초대 ON
		PVP_ON,					// 2 : PVP 초대 ON
		DUNGEON_PVP_ON,			// 3 : (1+2) : 던전 초대 ON, PVP 초대 ON
		BATTLE_ROYAL_ON,			// 4 : 배틀로얄 초대 ON
		DUNGEON_BATTLE_ROYAL_ON,	// 5 (1+4) : 던전 초대 ON, 배틀로얄 ON
		PVP_BATTLE_ROYAL_ON,		// 6 (2+4) : PVP 초대 ON, 배틀로얄 초대 ON
		ALL_ON,					// 7 (1+2+4) : 모두 초대 가능

		__MAX__,
	};

	struct Data
	{
		uint32_t		_heart_count;
		int				_heart_blocked;
		int				_invite_blocked;
		int				_profile_opened;
		int				_gender;
		int				_isGenderOpen;	// 성별 공개 여부 ( 1: open, 0 : block)
		std::string		_birthday;
		int				_isBirthdayOpen;	// 생일 공개 여부.

		Data() : _heart_count(0), _heart_blocked(0), _invite_blocked(7), _profile_opened(1), _gender(0), _isGenderOpen(1), _isBirthdayOpen(1) {}
		void Clear()
		{
			_heart_count = 0;
			_heart_blocked = 0;
			_invite_blocked = 7;
			_profile_opened = 1;
			_gender = 0;
			_isGenderOpen = 1;
			_birthday.clear();
			_isBirthdayOpen = 1;
		}
	};

public:
	SocialInfo();
	virtual ~SocialInfo();

	void Initialize();
	void Finalize();

	Data * GetData() { return _data; }

private:
	Data * _data;
};

} /* namespace NLogic */
} /* namespace ProjectZ */

#endif /* SOCIALINFO_H_ */
