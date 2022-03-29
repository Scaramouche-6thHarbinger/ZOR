#ifndef __SESSION_H__
#define __SESSION_H__

#include <util.h>
#include <ysf_queue3.h>
#include <ysf_sem.h>

#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

class Session {
public:
    Session(int asockfd);
    ~Session();

    void sendPacket(byte *pBuf, uint len);
    int handlePacket(NetPacket *pBuf);

    bool isRunning;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
private:
    static void *PacketRoutine(void *arg);
    static void *EvtProcRoutine(void *arg);
    pthread_t pid;
    int sockfd;

    ysf_semaphore_t m_cmd_sem;
    ysf_queue3 api_queue;
};

#endif // __SESSION_H__