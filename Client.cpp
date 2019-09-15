#include "Client.hpp"

void Client::run(string playername, int time, int location){

    printf("Starting client...\n");
    IPaddress ip;
    TCPsocket tcpsock;

    if (SDLNet_ResolveHost(&ip, "14.98.244.193", 9999) == -1) {
      printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
      exit(1);
    }

    tcpsock = SDLNet_TCP_Open(&ip);
    if (!tcpsock) {
      printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
      exit(2);
    }

    string message;


    if (len) {
        int result;

        /* print out the message */
        printf("Sending: %.*s\n", len, message);

        result =
            SDLNet_TCP_Send(tcpsock, message, len); /* add 1 for the NULL */
        if (result < len)
          printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
    }

    if (len == 2 && tolower(message[0]) == 'q') {
        break;
    }

    SDLNet_TCP_Close(tcpsock);
}