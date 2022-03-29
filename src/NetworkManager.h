#ifndef __NETWORK_MANAGER_H__
#define __NETWORK_MANAGER_H__

#include <util.h>
#include <Session.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#include <map>

class NetworkManager {
public:
        NetworkManager();
        ~NetworkManager();
public:
    std::map<uint, Session *> sessions;

    int sockfd;
    bool isRunning;
    socklen_t clilen;
    struct sockaddr_in cli_addr;
private:
    static void *EvtProcRoutine(void *arg);
    pthread_t pid;
};

#endif // __NETWORK_MANAGER_H__