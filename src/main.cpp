#include <iostream>
#include <stdio.h>

#include <cstring>

#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <unistd.h>
#include <errno.h>

#include "SDL.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void ConnectToServer();

int main(int argc, char* args[])
{
    SDL_Window* window = NULL;
    SDL_Surface* surface = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        //Error Occurred initialising SDL
        printf("Error: Failed to Initialise SDL >> %s\n", SDL_GetError());
        exit(-1);
    }

    printf("SDL Initialised...\n");

    window = SDL_CreateWindow("Mr Mollusc", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if(window == NULL)
    {
        //Error occurred creating window
        printf("Error: Failed to create window >> %s\n", SDL_GetError());

        SDL_Quit();
        exit(-1);
    }

    surface = SDL_GetWindowSurface(window);

    if(surface == NULL)
    {
        //Error occurred getting window surface
        printf("Error: Failed to get window surface >> %s\n", SDL_GetError());

        SDL_Quit();
        exit(-1);
    }

    SDL_UpdateWindowSurface(window);

    SDL_Quit();
}

void ConnectToServer()
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
}
