#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

DWORD WINAPI clientHandler(LPVOID arg) {
    int id = *(int*)arg;
    SOCKET clientSocket = *(SOCKET*)arg;
    int bytesReceived;
    char recvBuffer[1024];

    while(1){
        bytesReceived=recv(clientSocket, recvBuffer, sizeof(recvBuffer), 0);
        recvBuffer[bytesReceived] = '\0';

        printf("Client %d: %s\n", id, recvBuffer);
        send(clientSocket, recvBuffer, bytesReceived, 0);
    }
    
    closesocket(clientSocket);
    return 0;
}


int main(){

    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    int serverSocket= socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons(9806);
    serverAddr.sin_addr.s_addr=INADDR_ANY;

    struct sockaddr_storage serverStorage;
    socklen_t addr_size=sizeof(serverStorage);

    bind(serverSocket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));

    listen(serverSocket,3);

    int newSocket, id=0;

    while(1){
         newSocket = accept(serverSocket, (struct sockaddr*)&serverStorage, &addr_size);
         SOCKET *pclient=malloc(sizeof(SOCKET));
         *pclient=newSocket;

         CreateThread(NULL, 0, clientHandler, pclient, 0, NULL);
    }

    return 0;
}

