#include <NetworkManager.h>

#include <time.h>

int main() 
{
    NetworkManager *pNetworkManager = new NetworkManager();
    sleep(1000);
    delete pNetworkManager;
    return 0;
}