#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

void clientHandler();

int main(){

    int serverSocket= socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons(9806);
    serverAddr.sin_addr.s_addr=INADDR_ANY;
    bind(serverSocket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));

    struct sockaddr_storage serverStorage;
    socklen_t addr_size=sizeof(serverStorage);


    listen(serverSocket,3);

    int newSocket, bytesReceived;
    char recvBuffer[1024];

    while(1){
         newSocket = accept(serverSocket, (struct sockaddr*)&serverStorage, &addr_size);
         bytesReceived=recv(serverSocket, recvBuffer, sizeof(recvBuffer), 0);
         recvBuffer[bytesReceived] = '\0';
         printf("Server: %s\n", recvBuffer);
    }

    return 0;
}

void clientHandler(){

}