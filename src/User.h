#ifndef __USER_H__
#define __USER_H__

#include <Session.h>

class User {
public:
    User();
    ~User();

    void SetSession(Session session);
};

#endif // __USER_H__