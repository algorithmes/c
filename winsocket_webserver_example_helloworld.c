#undef UNICODE
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#pragma comment (lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "80"
int __cdecl main(void) 
{
    WSADATA wsaData;
    int iResult;
	char str[512];
	FILE *fp;
    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;
    struct addrinfo *result = NULL;
    struct addrinfo hints;
    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    freeaddrinfo(result);
	while(1) {
	fp = fopen("index.html", "r");
    iResult = listen(ListenSocket, SOMAXCONN);
    ClientSocket = accept(ListenSocket, NULL, NULL);
		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
			while( fgets (str, 512, fp)!=NULL ){
				iSendResult = send( ClientSocket, str , strlen(str), 0 );
				printf("Bytes sent: %d\n", iSendResult);
			}
		}
		iResult = shutdown(ClientSocket, SD_SEND);
    }
    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}
