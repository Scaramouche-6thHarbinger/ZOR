#include "Status.h"

#include <algorithm>

namespace NLogic {

Status::Status(User * pUser) {
	// TODO Auto-generated constructor stub

	_user = pUser;

	_clsStatusTree.clear();

	Status::Data * pData = new Status::Data;
	pData->_eStatusType = Status::StatusType::BATTLEPET_REBIRTH;
	pData->_bRegist = false;
	pData->_durationTime = 0;
	pData->_elapseTime = 0;
	pData->_value = 0;
	pData->_valueType = 0;
	pData->_effectID = 0;
	pData->_defenderID = 0;
	pData->_defenderType = 0;

	_clsStatusTree[Status::StatusType::BATTLEPET_REBIRTH] = pData;
}

Status::~Status() {
	// TODO Auto-generated destructor stub

	std::for_each(_clsStatusTree.begin(), _clsStatusTree.end(), [&](STATUSTREE::value_type & pair) {
		delete pair.second;
	} );
}

void
Status::Initialize()
{
	std::for_each(_clsStatusTree.begin(), _clsStatusTree.end(), [](STATUSTREE::value_type & pair) {
		pair.second->Clear();
	} );
}

void
Status::Finalize()
{

}

Status::STATUSTREE &
Status::GetStatusTree()
{
	return _clsStatusTree;
}

Status::Data *
Status::GetStausData(StatusType eStatusType)
{
	auto itr = _clsStatusTree.find(eStatusType);
	if (itr == _clsStatusTree.end())
		return NULL;

	return itr->second;
}

} // namespace NLogic
