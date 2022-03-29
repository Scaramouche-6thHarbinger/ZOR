#ifndef __SESSION_H__
#define __SESSION_H__

#include <util.h>
#include <Protocol.h>
#include <Packet.h>
#include <Encryption.h>
#include <ysf_queue3.h>
#include <ysf_sem.h>

#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

class User;

class Session {
public:
    Session(int asockfd);
    ~Session();

    void sendRaw(byte *pBuf, uint len);
    void sendPacket(NetPacket *pPacket);
    int handlePacket(NetPacket *pPacket);

private:
    void on_CS_REQ_SERVER_ADDR(Network::Packet * pPacket);
    static void *PacketRoutine(void *arg);
    static void *EvtProcRoutine(void *arg);

    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    bool isRunning;
    pthread_t pid;
    int sockfd;

    User* _user;

    ysf_semaphore_t m_cmd_sem;
    ysf_queue3 api_queue;
};

#endif // __SESSION_H__