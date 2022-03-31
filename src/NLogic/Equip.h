#ifndef __EQUIP_H__
#define __EQUIP_H__

#include <map>

#include <Enum.h>

class User;

namespace NLogic {

class Item;

class Equip
{
public:
	typedef std::map<int, Item *> EQUIPTREE;

public:
	Equip(User * pUser);
	virtual ~Equip();

	void 			Initialize();
	void 			Finalize();

	bool 			AddItem(EnumItemEquipPosition ePosition, Item * pItem);
	Item *			GetItem(EnumItemEquipPosition ePosition);
	Item *			PopItem(EnumItemEquipPosition ePosition);
	bool 			IsExistItem(EnumItemEquipPosition ePosition);

	EQUIPTREE &		GetEquipTree();

	void			EquipAddFromCharacterInfo();
	void			UpdateCharacterInfo();

	int				HasItemCount();
	int				GetEquipItemIconIndex(EnumItemEquipPosition ePosition);

private:
	User *			_user;

//	static const int s_max = 12;
	EQUIPTREE 		_clsEquipTree;
};

} // namespace NLogic

#endif // __EQUIP_H__