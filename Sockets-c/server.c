#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

typedef struct {
    int id;
    SOCKET clientSocket;
} ClientInfo;

DWORD WINAPI clientHandler(LPVOID arg) {
    ClientInfo *clientInfo = (ClientInfo*)arg;
    int id = clientInfo->id;
    SOCKET clientSocket = clientInfo->clientSocket;
    int bytesReceived;
    char recvBuffer[1024];

    while(1){
        bytesReceived=recv(clientSocket, recvBuffer, sizeof(recvBuffer), 0);
        recvBuffer[bytesReceived] = '\0';

        printf("Client %d: %s\n", id, recvBuffer);
        if (stricmp(recvBuffer, "exit") == 0)
        {
            printf("Client %d disconnected.\n", id);
            closesocket(clientSocket);
            free(arg);
            return 0;

        }else
        {
            send(clientSocket, recvBuffer, bytesReceived, 0);
        }
    }
    
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
    if(listen(serverSocket, 3) == SOCKET_ERROR) {
        printf("Listen failed with error: %d\n", WSAGetLastError());
        return 1;
    }

    int newSocket, id=0;

    while(1){
         newSocket = accept(serverSocket, (struct sockaddr*)&serverStorage, &addr_size);
         SOCKET *pclient=malloc(sizeof(SOCKET));
         *pclient=newSocket;
         printf("Client %d connected.\n", id);
         ClientInfo *clientInfo = malloc(sizeof(ClientInfo));
            clientInfo->id = id;
            clientInfo->clientSocket = newSocket;
         CreateThread(NULL, 0, clientHandler, clientInfo, 0, NULL);
         id++;
        
    }

    return 0;
}

