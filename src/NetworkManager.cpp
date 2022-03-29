#include <NetworkManager.h>

void *NetworkManager::EvtProcRoutine(void *arg) {
    NetworkManager *pNetworkManager = (NetworkManager *)arg;
    int asockfd;
    while (pNetworkManager->isRunning) {
        asockfd = accept(pNetworkManager->sockfd, (struct sockaddr *)&pNetworkManager->cli_addr, &pNetworkManager->clilen);
        if (asockfd < 0) {
            LOGE("ERROR on accept");
            continue;
        }

        Session *pSession = new Session(asockfd);
        pNetworkManager->sessions.insert(std::pair<uint, Session *>(asockfd, pSession));
    }
    return NULL;
}

NetworkManager::NetworkManager() {
    LOGD("NetworkManager::NetworkManager()");
    struct sockaddr_in serv_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        LOGE("ERROR opening socket");
        LOGE("%s", strerror(errno));
        return;
    }
    isRunning = true;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(55000);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        LOGE("ERROR on binding");
        LOGF("%s", strerror(errno));
    }
    // set reuse
    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
    listen(sockfd, 4);
    LOGI("Listening on port 55000, socket fd: %d", sockfd);
    clilen = sizeof(cli_addr);

    sessions.clear();
    isRunning = true;
    pthread_create(&pid, NULL, EvtProcRoutine, this);
}

NetworkManager::~NetworkManager() {
    LOGD("NetworkManager::~NetworkManager()");
    isRunning = false;
    close(sockfd);
    pthread_join(pid, NULL);
}