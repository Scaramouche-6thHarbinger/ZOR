#include <User.h>
#include <Card.h>

namespace NLogic {

Card::Card()
{
	s_Max = static_cast<int>(CardItemType::__MAX__);

	clsNormalCardVector.reserve(s_Max);
	clsZenCardVector.reserve(s_Max);

	for (int i = 0; i < s_Max; i++)
	{
		clsNormalCardVector[i] = NULL;
		clsZenCardVector[i] = NULL;
	}

	bDungeonRewardFlag		= false;
	bDungeonRewardFlagZEN	= false;
}

Card::~Card()
{
	Clear();
}

void
Card::Initialize()
{
	Clear();
}

void
Card::Finalize()
{
	Clear();
}

int
Card::HasCardCount()
{
	int cardCount = 0;

	for (int i = 0; i < s_Max; i++)
	{
		if (NULL == clsNormalCardVector[i])
			continue;

		cardCount++;
	}

	for (int i = 0; i < s_Max; i++)
	{
		if (NULL == clsZenCardVector[i])
			continue;

		cardCount++;
	}

	return cardCount;
}

void
Card::Clear()
{
	for (int i = 0; i < s_Max; i++)
	{
		if (NULL == clsNormalCardVector[i])
			continue;

		delete clsNormalCardVector[i];
		clsNormalCardVector[i] = NULL;
	}

	for (int i = 0; i < s_Max; i++)
	{
		if (NULL == clsZenCardVector[i])
			continue;

		delete clsZenCardVector[i];
		clsZenCardVector[i] = NULL;
	}

	clsNormalCardVector.clear();
	clsZenCardVector.clear();

	bDungeonRewardFlag		= false;
	bDungeonRewardFlagZEN	= false;
}

Card::CARDITEMVECTOR &
Card::GetNormalCardVector()
{
	return clsNormalCardVector;
}

Card::CARDITEMVECTOR &
Card::GetZenCardVector()
{
	return clsZenCardVector;
}

void
Card::AddNormalCardData(CardItemType eItemType, Data * pData)
{
	clsNormalCardVector[static_cast<int>(eItemType)] = pData;
}

Card::Data *
Card::GetNormalCardData(CardItemType eItemType)
{
	return clsNormalCardVector[static_cast<int>(eItemType)];
}

void
Card::AddZenCardData(CardItemType eItemType, Data * pData)
{
	clsZenCardVector[static_cast<int>(eItemType)] = pData;
}

Card::Data *
Card::GetZenCardData(CardItemType eItemType)
{
	return clsZenCardVector[static_cast<int>(eItemType)];
}

void
Card::SetDungeonRewardFlag(bool bFlag)
{
	bDungeonRewardFlag = bFlag;
}

bool
Card::GetDungeonRewardFlag()
{
	return bDungeonRewardFlag;
}

void
Card::SetDungeonRewardFlagZEN(bool bFlag)
{
	bDungeonRewardFlagZEN = bFlag;namespace ProjectZ { 
}

bool
Card::GetDungeonRewardFlagZEN()
{
	return bDungeonRewardFlagZEN;
}

} // namespace NLogic
