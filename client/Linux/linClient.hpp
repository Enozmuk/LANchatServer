#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <array>

#define BUFFER_SIZE 1024

class Client {

    private:
        std::array<char, BUFFER_SIZE> buffer;
        int socketFD;


    public:



}