#ifndef __SOCIALINFO_H__
#define __SOCIALINFO_H__

#include <string>

namespace NLogic {

class SocialInfo {

public:
	// ?ŒŒ?‹° ì´ˆë?? ì°¨ë‹¨ ?—¬ë¶?.
	enum class EnumInviteState : int {
		__NONE__ = -1,

		ALL_BLOCK,					// 0 : ëª¨ë‘ ì°¨ë‹¨,
		DUNGEON_ON,				// 1 : ?˜? „ ì´ˆë?? ON
		PVP_ON,					// 2 : PVP ì´ˆë?? ON
		DUNGEON_PVP_ON,			// 3 : (1+2) : ?˜? „ ì´ˆë?? ON, PVP ì´ˆë?? ON
		BATTLE_ROYAL_ON,			// 4 : ë°°í??ë¡œì–„ ì´ˆë?? ON
		DUNGEON_BATTLE_ROYAL_ON,	// 5 (1+4) : ?˜? „ ì´ˆë?? ON, ë°°í??ë¡œì–„ ON
		PVP_BATTLE_ROYAL_ON,		// 6 (2+4) : PVP ì´ˆë?? ON, ë°°í??ë¡œì–„ ì´ˆë?? ON
		ALL_ON,					// 7 (1+2+4) : ëª¨ë‘ ì´ˆë?? ê°??Š¥

		__MAX__,
	};

	struct Data
	{
		uint32_t		_heart_count;
		int				_heart_blocked;
		int				_invite_blocked;
		int				_profile_opened;
		int				_gender;
		int				_isGenderOpen;	// ?„±ë³? ê³µê°œ ?—¬ë¶? ( 1: open, 0 : block)
		std::string		_birthday;
		int				_isBirthdayOpen;	// ?ƒ?¼ ê³µê°œ ?—¬ë¶?.

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

} // namespace NLogic
#endif // __SOCIALINFO_H__
