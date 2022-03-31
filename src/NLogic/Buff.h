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
		int		u8type; /// 0:?Ή? λ²ν, 1:μΉκ΅¬λ²ν, 2:VIP λ²ν1 , 3:VIP λ²ν2, 4:κΈΈλ λ²ν
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
