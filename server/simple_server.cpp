// Simple server that accepts multiple clients messages and sends them back to all clients
#include "simple_server.hpp"

simpleServer::simpleServer(int listeningPort) {
    port = listeningPort;
    
}

simpleServer::~simpleServer() {

    closeConnections();
    close(listenFD);

}

int simpleServer::initialize() {

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '\0', sizeof(serv_addr));

    listenFD = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);

    bind(listenFD, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(listenFD, 10); // TODO: LEAVE MAX WAITING CONNECTIONS AT 10?

    return 0;
}

void simpleServer::closeConnections() {
    for (clientConn client : clients)
    {
        client.close();
    }
}

int simpleServer::getListenSocket() {
    return listenFD;
}

void simpleServer::run() {

    while(true) {
        std::unique_lock<std::mutex> lk(runLock);

    }



}