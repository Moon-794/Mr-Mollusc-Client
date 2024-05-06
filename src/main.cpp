#include <iostream>

#include <cstring>

#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <unistd.h>
#include <errno.h>

int main()
{
    struct addrinfo hints, *res;
    int socketfd;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo("127.0.0.0", "3500", &hints, &res);

    socketfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    
    if(connect(socketfd, res->ai_addr, res->ai_addrlen) == -1)
    {
        close(socketfd);
        std::cout << res->ai_addr << "\n";
        perror("client: connect");
    }

    return 0;
}
