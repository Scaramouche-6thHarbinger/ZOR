#ifndef __CARD_H__
#define __CARD_H__

#include <vector>
#include <inttypes.h>

namespace NLogic {

class Card
{
public:
	enum class CardItemType
	{
		__NONE__,

//		NORMAL_CARD_ITEM_TYPE_GOOD = 0,
//		NORMAL_CARD_ITEM_TYPE_NORMAL,
//		NORMAL_CARD_ITEM_TYPE_BAD,
//
//		ZEN_CARD_ITEM_TYPE_GOOD,
//		ZEN_CARD_ITEM_TYPE_NORMAL,
//		ZEN_CARD_ITEM_TYPE_BAD,

		CARD_ITEM_TYPE_GOOD	= 0,
		CARD_ITEM_TYPE_NORMAL,
		CARD_ITEM_TYPE_BAD,

		__MAX__,
	};
public:
	struct Data
	{
		int tid;
		int sheetType;
		int classType;
		int quality;
		int refine;

		int effPos;
		int effValue;
		int effType;

		Data()
		{
			tid = 0;
			sheetType = 0;
			classType = 0;
			quality = 0;
			refine = 0;

			effPos		= -1;
			effValue	= -1;
			effType		= -1;
		}
	};

public:
	typedef std::vector<Data *> CARDITEMVECTOR;

public:
	Card();
	virtual ~Card();

	void				Initialize();
	void				Finalize();

	void				Clear();
	int					HasCardCount();

	CARDITEMVECTOR &	GetNormalCardVector();
	CARDITEMVECTOR &	GetZenCardVector();

	Data *				GetNormalCardData(CardItemType eItemType);
	void				AddNormalCardData(CardItemType eItemType, Data * pData);

	Data *				GetZenCardData(CardItemType eItemType);
	void				AddZenCardData(CardItemType eItemType, Data * pData);

	int					GetMaxCount() { return s_Max; }

	void				SetDungeonRewardFlag(bool bFlag);
	bool				GetDungeonRewardFlag();

	void				SetDungeonRewardFlagZEN(bool bFlag);
	bool				GetDungeonRewardFlagZEN();

private:
	CARDITEMVECTOR		clsNormalCardVector;
	CARDITEMVECTOR		clsZenCardVector;
	bool				bDungeonRewardFlag;
	bool				bDungeonRewardFlagZEN;
	int					s_Max;
};

} /* namespace NLogic */ } /* namespace ProjectZ */
#endif /* CARD_H_ */
