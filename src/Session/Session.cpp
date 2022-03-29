#include <Session.h>

void *Session::EvtProcRoutine(void *arg)
{
    Session *pSession = (Session *)arg;
    int ret = 0;
    do {
        LOG("before sem");
        do {
            ret = ysf_sem_wait(&pSession->m_cmd_sem);
            if (ret != 0 && errno != EINVAL) {
                LOGF("ysf_sem_wait error (%s)", strerror(errno));
                return NULL;
            }
        } while (ret != 0);
        LOG("after sem");

        NetPacket *pPacket = new NetPacket();
        pPacket = (NetPacket*)pSession->api_queue.dequeue();

        LOGI("wCMD = %d", pPacket->header.wCMD);
        LOGI("handle packet len: %d", pPacket->bodyLen);

        if (pPacket != NULL) {
            delete pPacket;
        } else {
            LOGD("received NULL packet, skipping");
        }
    } while (pSession->isRunning);
    LOGD("X");
    return NULL;
}

void *Session::PacketRoutine(void *arg) {
    Session *pSession = (Session *)arg;
    int asockfd = pSession->sockfd;
    while (pSession->isRunning) {
        pthread_mutex_lock(&pSession->mutex);
        byte *header = new byte[sizeof(tagNetHeader)];
        int len = recv(asockfd, header, sizeof(tagNetHeader), 0);
        if (len < 0) {
            LOGE("ERROR on recv");
            LOGF("%s", strerror(errno));
            continue;
        } else if (len == 0) {
            LOGD("Client closed");
            break;
        } else {

            NetHeader *pNetHeader = (NetHeader *)header;

            if (!pNetHeader->isValid()) {
                LOGW("Invalid net header");
                continue;
            }
            LOG("Received %d bytes session_id %d", len, asockfd);
            LOG("packet_id: %d, packet_len: %d", pNetHeader->wCMD, pNetHeader->wLen);
            byte *body = new byte[pNetHeader->wLen -3];

            len = recv(asockfd, body, pNetHeader->wLen -3, 0);
            if (len != pNetHeader->wLen -3) {
                LOGE("ERROR on recv");
                continue;
            }

            NetPacket *pNetPacket = new NetPacket();
            pNetPacket->header.byStartFlag = pNetHeader->byStartFlag;
            pNetPacket->header.wLen = pNetHeader->wLen;
            pNetPacket->header.byReserve = pNetHeader->byReserve;
            pNetPacket->header.wCMD = pNetHeader->wCMD;

            pNetPacket->bodyLen = pNetHeader->wLen -3;
            pNetPacket->body = new byte[pNetPacket->bodyLen];
            memcpy(pNetPacket->body, body, pNetPacket->bodyLen);

            delete body;

            pSession->handlePacket(pNetPacket);
        }
        //delete[] header;
        // dont delete header, it will be deleted in the EvtProcRoutine
        pthread_mutex_unlock(&pSession->mutex);
    }
    return NULL;
}

void Session::sendPacket(byte *pBuf, uint mlen) {
    pthread_mutex_lock(&mutex);
    int len = send(sockfd, pBuf, mlen, 0);
    if (len < 0 || len != (int)mlen) {
        LOGE("ERROR on send");
        LOGE("%s", strerror(errno));
    } else if (len == 0) {
        LOGD("Client closed");
    } else {
        LOG("Sent %d bytes", len);
    }
    pthread_mutex_unlock(&mutex);
}

int Session::handlePacket(NetPacket *pNetPacket) {
    if (api_queue.enqueue((void *)pNetPacket)) {
        LOG("sent successfully, posting to queue");
        ysf_sem_post(&m_cmd_sem);
        return 0;
    } else {
        delete pNetPacket;
        LOGE("unknown error");
        return 1;
    }
    // we should not be able to reach this
    return -1;
}

Session::Session(int asockfd) : api_queue()
{
    LOGD("Session::Session(int asockfd)");
    sockfd = asockfd;
    isRunning = true;
    ysf_sem_init(&m_cmd_sem, 0);
    pthread_create(&pid, NULL, PacketRoutine, this);
    pthread_create(&pid, NULL, EvtProcRoutine, this);
}

Session::~Session()
{
    LOGD("Session::~Session()");
}