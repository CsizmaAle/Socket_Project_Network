#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>


int main() {

    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    int networkSocket= socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serverAddr, srcAddr, destAddr;
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons(9806);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    int connectioinStatus=connect(networkSocket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));

    int len = sizeof(struct sockaddr_in);

    getpeername(networkSocket, (struct sockaddr*)&srcAddr, &len);
    getsockname(networkSocket, (struct sockaddr*)&destAddr, &len);

    char *scrIp=inet_ntoa(srcAddr.sin_addr);
    char *destIp=inet_ntoa(destAddr.sin_addr);

    int scrPort=ntohs(srcAddr.sin_port);
    int destPort=ntohs(destAddr.sin_port);

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

        send(networkSocket, buffer, strlen(buffer), 0);
        if(stricmp(buffer,"exit")==0)
            break;

        bytesReceived=recv(networkSocket, recvBuffer, sizeof(recvBuffer), 0);
        recvBuffer[bytesReceived] = '\0';
        printf("From server: %s; port sursa: %d, port destinatie: %d; adresa IP sursa: %s, adresa IP destinatie: %s\n", recvBuffer, scrPort, destPort, scrIp, destIp);

    }while(strcmp(buffer,"exit")!=0);

    closesocket(networkSocket);
    WSACleanup();

    return 0;
}