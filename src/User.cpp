#include <User.h>

User::User()
{
    LOGD("User::User()");
}

User::~User()
{
    LOGD("User::~User()");
    delete session;
}

void User::SetSession(Session *session)
{
    LOGD("User::SetSession(Session *session)");
    this->session = session;
}