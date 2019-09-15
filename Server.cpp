#include "Server.hpp"

void Server::run(){

    TCPsocket server, client;
    IPaddress ip;
    if (SDLNet_ResolveHost(&ip, NULL, 9999) == -1) {
      printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
      exit(1);
    }
    server = SDLNet_TCP_Open(&ip);
    if (!server) {
      printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
      exit(2);
    }
    while (!done) {
      /* try to accept a connection */
      client = SDLNet_TCP_Accept(server);
      if (!client) { /* no connection accepted */
        //printf("SDLNet_TCP_Accept: %s\n",SDLNet_GetError());
        SDL_Delay(100); /*sleep 1/10th of a second */
        continue;
      }

      /* get the clients IP and port number */
      IPaddress *remoteip;
      remoteip = SDLNet_TCP_GetPeerAddress(client);
      if (!remoteip) {
        printf("SDLNet_TCP_GetPeerAddress: %s\n", SDLNet_GetError());
        continue;
      }

      /* print out the clients IP and port number */
      Uint32 ipaddr;
      ipaddr = SDL_SwapBE32(remoteip->host);
      printf("Accepted a connection from %d.%d.%d.%d port %hu\n", ipaddr >> 24,
             (ipaddr >> 16) & 0xff, (ipaddr >> 8) & 0xff, ipaddr & 0xff,
             remoteip->port);

    char message[1024];
    int len = SDLNet_TCP_Recv(client, message, 1024);
    /* print out the message */
    printf("Received: %.*s\n", len, message);

    SDLNet_TCP_Close(client);

}