#include "Client.hpp"
#include<sstream>

void Client::run(string playername, int time, int location){

    printf("Starting client...\n");
    IPaddress ip;
    TCPsocket tcpsock;

    if (SDLNet_ResolveHost(&ip, "192.168.43.161", 9999) == -1) {
      printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
      exit(1);
    }

    tcpsock = SDLNet_TCP_Open(&ip);
    if (!tcpsock) {
      printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
      exit(2);
    }

    string message,t,loc;
    stringstream ss;
    ss<<time;
    t = ss.str();
    ss.str("");
    ss<<location;
    loc = ss.str();
    ss.str("");
    
    message = playername+" "+t+" "+loc;
    int len = message.length();

    if (len) {
        int result;

        /* print out the message */
        printf("Sending: %.*s\n", len, message);

        result =
            SDLNet_TCP_Send(tcpsock, message.c_str(), len); /* add 1 for the NULL */
        if (result < len)
          printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
    }

    SDLNet_TCP_Close(tcpsock);
}