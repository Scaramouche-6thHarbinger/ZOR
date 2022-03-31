/*
 * Buff.h
 *
 *  Created on: 2013. 10. 21.
 *      Author: jjaehuny
 */

#ifndef __BUFF_H__
#define __BUFF_H__

#include <vector>
#include <inttypes.h>

class User;

namespace NLogic {

class Buff
{
public:
	enum class BuffType : int {
		__NONE__ = -1,

		WINPOINT = 0,
		FRIEND,
		VIP1,
		VIP2,
		GUILD,

		__MAX__,
	};

public:
	struct Data
	{
		int		u8type; /// 0:?��?��버프, 1:친구버프, 2:VIP 버프1 , 3:VIP 버프2, 4:길드 버프
		int		u16skill_tid;
		int 	u8skill_level;
		int		s16skill_value;				/// %

		unsigned int 	_regdate;

		Data() : u8type(0), u16skill_tid(0), u8skill_level(0), s16skill_value(0), _regdate(0) {}
		void Clear()
		{
			u8type = 0;
			u16skill_tid = 0;
			u8skill_level = 0;
			s16skill_value = 0;
			_regdate = 0;
		}
	};

public:
	typedef std::vector<Data *> DATAVAECTOR;
	Buff(User * pUser);
	virtual ~Buff();

	void Initialize();
	void Finalize();

	Data * GetData(BuffType eBuffType);
	//void 	SetBuff(BuffType eBuffType, int64_t regdate);

	DATAVAECTOR &	GetDataVector() { return _clsBuffVector; }
	int		GetActiveBuffCount(unsigned int nTime);
	int		GetExpConstVIP();
	int		GetItemDropConstVIP();

	void	SetVIPBuff();
	void	RefleshVIPBuff();

public:
	static const int s_FrinedBuffDuration = 60 * 1000 * 10;

private:
	DATAVAECTOR 			_clsBuffVector;
	User *					_user;

	int _expConstVIP;
	int _itemDropConstVIP;
};

} /*NLogic*/

#endif // __BUFF_H__
