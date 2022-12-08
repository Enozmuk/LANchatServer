#include <array>
#include <string>
#include <deque>
#include <mutex>

#define BUFFER_SIZE 1024

/**
 * IMPLEMENTATION NOTES
 * Need to make sure no messages are waiting to be read before writing to socket, otherwise socket might read stuff I've sent?
 * 
*/

class clientConn {

    private:
        std::array<char, BUFFER_SIZE> buffer;

        std::deque<std::string> sendQueue();
        std::deque<std::string> recvQueue();

        int fd;

    public:

        clientConn(int socketFD);
        ~clientConn();

        /**
         * Control Flow:
         * While True:
         * Lock access to sendQueue (blocks until access acquired)
         * send whole sendqueue to client
         * unlock sendQueue
         * 
         * Lock access to recvQueue (blocks until access acquired)
         * while read socket not empty
         * non-blocking read of file descriptor
         ** If no messages recieved, read socket empty
         ** else add message to recvQueue for server processing
         * after broken out of while: unlock recvQueue
        */
        void processMessages(); // function passed to thread for reading and writing messages

        /**
         * Functions below NEED to mutex access to recvQueue and sendQueue. They are functions for the server to get and send messages to this client
         * These will run in the main thread while the processMessages() function will have its own.
        */
        std::string getNextMessage(); // send message on top of recv queue to server
        std::string queueSendMessage(); // let server queue another message to send

}