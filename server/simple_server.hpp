#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#include <string.h> // needed for memset
#include <string>
#include <errno.h>

#include "clientConn.hpp"

class simpleServer {
    
    private:
        int createClient(int socketFD);
        std::vector<clientConn> clients;

        int port;
        int listenFD = -1;

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
        int run();

        int getListenSocket() {return listenFD;}

}