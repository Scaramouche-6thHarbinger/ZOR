#include <User.h>

User::User() : _clsBagVector(static_cast<int>(BAG_TYPE_MAX))
, _session(NULL), _bClose(false), _bDelUser(false), _bZENEvent(false), _bBattleReconnect(false), /**_space(NULL), _world(NULL), _reserveSpace(NULL), **/ _worldIndex(-1)
, _partyAccept(false), _bagInfoCache(false), _battle_aftereffect(false), _latency(0), _refCount(0)
, _array_dungeon_clear_info(static_cast<int>(MAX_DUNGEON_COUNT)), _array_bag_order_info(static_cast<int>(BAG_TYPE_MAX))
{
    LOGD("User::User()");

    //this->SetState(NState::Static::Instance().TITLE());
}

User::~User()
{
    LOGD("User::~User()");
    delete _session;
}

void User::Initialize() {
    LOGD("User::Initialize()");
    this->_socialID.clear();

    std::for_each(_clsBagVector.begin(), _clsBagVector.end(), [](NLogic::Bag *bag) {
        bag->Initialize();
    });
}

void User::Finalize() {
    LOGD("User::Finalize()");
    std::for_each(_clsBagVector.begin(), _clsBagVector.end(), [](NLogic::Bag *bag) {
        bag->Finalize();
    });
}

void User::SetSession(Session *session)
{
    LOGD("User::SetSession(Session *session)");
    this->_session = session;
}

void
User::SetState(State * state)
{
	_state = state;
}