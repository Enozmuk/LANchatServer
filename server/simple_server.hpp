#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#include <string.h> // needed for memset
#include <string>
#include <errno.h>
#include <mutex>
#include <condition_variable>

#include "clientConn.hpp"

class simpleServer {
    
    private:
        int createClient(int socketFD);
        std::vector<clientConn> clients;

        int port;
        int listenFD = -1;

        std::condition_variable running;

        std::mutex runLock; 

    public:
        simpleServer(int port);
        ~simpleServer(); // close listening ports

        // binds to listen socket
        // returns -1 on failure, 0 on success
        int initialize();

        // closes all connections
        void closeConnections();
        
        // start listen
        // no thread for accept, just poll() the fd to see if there is anything to read
        void run();

        int getListenSocket();

};