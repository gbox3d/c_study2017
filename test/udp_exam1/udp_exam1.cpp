// udp_exam1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

//보내고 받는 버전 bind가 없다.

#define SERVER "192.168.0.7"  //ip address of udp server
#define BUFLEN 512  //Max length of buffer
#define PORT 3333   //The port on which to listen for incoming data

int main(void)
{
	struct sockaddr_in si_other;
	int s, slen = sizeof(si_other);
	char buf[BUFLEN];
	char message[BUFLEN];
	WSADATA wsa;

	//Initialise winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	printf("Initialised.\n");

	//create socket
	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR)
	{
		printf("socket() failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}

	//setup address structure
	memset((char *)&si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);
	si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);

	//start communication
	while (1)
	{
		int xpos,ypos;
		printf("Enter message : ");
		
		//gets(message);
		scanf("%d %d", &xpos,&ypos);
		
		cJSON *root = NULL;
		root = cJSON_CreateObject();
		cJSON_AddNumberToObject(root, "xpos", xpos);
		cJSON_AddNumberToObject(root, "ypos", ypos);
		char szBuf[512];
		cJSON_PrintPreallocated(root, message, BUFLEN, 0);

		printf("send message : \n %s \n", message);

		//send the message
		if (sendto(s, message, strlen(message), 0, (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}

		//receive a reply and print it
		//clear the buffer by filling null, it might have previously received data
		memset(buf, '\0', BUFLEN);
		//try to receive some data, this is a blocking call
		if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == SOCKET_ERROR)
		{
			printf("recvfrom() failed with error code : %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}

		puts(buf);
	}

	closesocket(s);
	WSACleanup();

	return 0;
}