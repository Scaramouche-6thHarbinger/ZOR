#include <User.h>

User::User() : _clsBagVector(static_cast<int>(BAG_TYPE_MAX))
{
    LOGD("User::User()");
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