#include <SDL2\SDL.h>
#include <SDL2\SDL_net.h>
#include <cstdio>
#include <string>
#include <fstream>
#include<iostream>
using namespace std;

int main(int argc, char **argv) {

    char message[1024];

    if (SDL_Init(0) == -1) {
        printf("SDL_Init: %s\n", SDL_GetError());
        exit(1);
    }
    if (SDLNet_Init() == -1) {
        printf("SDLNet_Init: %s\n", SDLNet_GetError());
        exit(2);
    }

    bool done = false;

    printf("Starting server...\n");
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

    while(!done){
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

        /* read the buffer from client */
        int len = SDLNet_TCP_Recv(client, message, 1024);
        if (!len) {
            printf("SDLNet_TCP_Recv: %s\n", SDLNet_GetError());
            break;
        }

        /* print out the message */
        printf("Received: %.*s\n", len, message);
        SDLNet_TCP_Close(client);
        done = true;

    }

    string ms(message);
    string name,tim,loc;
    int sec = 0, point = 0;
    for(int i = 0; ms[i]; i++){
        if(ms[i]=' '){
            if(sec == 0)
                name = ms.substr(0,i);
            else if(sec == 1)
                tim = ms.substr(point,i);
            point = i+1;
            sec++;
        }
    }
    loc = ms.substr(point,ms.length()-1);

    cout<<name<<tim<<loc;

    fstream fin("Leaderboard.dat",fstream::in);
    fstream fout("Temp.dat",fstream::out);
    string temp;

    for(int i = 0; i < 3; i++){
        getline(fin,temp,'\n');
        cout<<temp;
        if(temp == ""){
            fout<<"       "<<name<<"                                      "<<tim<<'\n';
        }
        else{
            if(temp.substr(34) >= tim){
                fout<<"       "<<name<<"                                      "<<tim<<'\n';
                fout<<temp;
            }
            else{
                fout<<temp;
            }
        }
    }

    fin.close();
    fout.close();

    remove("Leaderboard.dat");
    rename("Temp.dat","Leaderboard.dat");

    SDLNet_Quit();
    SDL_Quit();
}