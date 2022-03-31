#ifndef __STATUS_H__
#define __STATUS_H__

#include <inttypes.h>
#include <map>

class User;

namespace NLogic {

class Status
{

public:
	enum class StatusType {
		__NONE__,

		BATTLEPET_REBIRTH = 36,

		__MAX__,
	};

public:
	struct Data {
		bool		_bRegist;
		StatusType	_eStatusType;
		uint16_t	_durationTime;
		uint16_t	_elapseTime;
		uint16_t	_value;
		uint8_t	_valueType; 	//( 0 : + , 1 : %)
		uint8_t	_effectID;
		uint32_t	_defenderID;
		uint8_t	_defenderType; //(0 : Ï£ºÏù∏Í≥? 1: Î™¨Ïä§?Ñ∞ 2: Ï£ºÏù∏Í≥µÏÜå?ôò, 3: Î™¨Ïä§?Ñ∞ ?Üå?ôò)

		void Clear()
		{
			_bRegist = false;
			_durationTime = 0;
			_elapseTime = 0;
			_value = 0;
			_valueType = 0;
			_effectID = 0;
			_defenderID = 0;
			_defenderType = 0;
		}
	};

public:
	typedef std::map<StatusType, Data *> STATUSTREE;

public:
	Status(User * pUser);
	virtual ~Status();

	void 	Initialize();
	void	Finalize();

	STATUSTREE & 	GetStatusTree();
	Data *			GetStausData(StatusType eStatusType);

private:
	STATUSTREE _clsStatusTree;
	User * _user;
};

} // namespace NLogic

#endif // __STATUS_H__
