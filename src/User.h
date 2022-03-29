#ifndef __USER_H__
#define __USER_H__

#include <util.h>
#include <Session.h>

class Session;

class User {
public:
    User();
    ~User();

    void SetSession(Session *session);

private:
    Session *session;
};

#endif // __USER_H__