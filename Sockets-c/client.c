#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>


int main() {

    int networkSocket= socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons(9806);
    serverAddr.sin_addr.s_addr=INADDR_ANY;
    int connectioinStatus=connect(networkSocket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));

    if(connectioinStatus==-1){
        printf("Error: Connection Failed.\n");
        return -1;
    }
    printf("Connected to Server.\n");

    char buffer[1024];
    char recvBuffer[1024];
    int bytesReceived;
    do{
        printf("Enter message:");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; 

        if(strcmp(buffer,"exit")==0)
            break;

        send(networkSocket, buffer, strlen(buffer), 0);
        
        bytesReceived=recv(networkSocket, recvBuffer, sizeof(recvBuffer), 0);
        recvBuffer[bytesReceived] = '\0';
        printf("Server: %s\n", recvBuffer);

    }while(strcmp(buffer,"exit")!=0);

    return 0;
}