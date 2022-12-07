#include <array>
#include <string>
#include <deque>

#define BUFFER_SIZE 1024

/**
 * IMPLEMENTATION NOTES
 * Need to make sure no messages are waiting to be read before writing to socket, otherwise socket might read stuff I've sent?
 * 
*/

class clientConn {

    private:
        std::array<char, BUFFER_SIZE> recv;
        std::array<char, BUFFER_SIZE> send;

        std::deque<std::string> messageQueue();

        int fd;

    public:

        clientConn(int socketFD);
        ~clientConn();

        void readMessages(); // function to listen to communication socket, passed to thread 
        void sendMessage(); // function to send message on top of queue to client, passed to thread

        std::string getNextMessage(); // send message on top of recv queue to server
        std::string queueSendMessage(); // let server queue another message to send

}