#include "stdafx.h"

Pen *g_pBlackPen;

struct S_Player {
	irr::core::vector2df m_vPos;
};

S_Player g_RemotePlayer;

void OnUpdate(double fDelta)
{

}

void OnRender(double fDelta,Graphics *grp)
{
	grp->Clear(Color(200, 191, 231));

	
	//화면 눈금표시 
	grp->DrawLine(g_pBlackPen, 0, 120, 320, 120);
	grp->DrawLine(g_pBlackPen, 160, 0, 160, 240);
	grp->DrawRectangle(g_pBlackPen, 0, 0, 320, 240);
	Matrix orginMat(1, 0, 0, 1, 160, 120);
	grp->SetTransform(&orginMat);

	{
		Matrix _tempMat;
		grp->GetTransform(&_tempMat);

		grp->TranslateTransform(g_RemotePlayer.m_vPos.X, g_RemotePlayer.m_vPos.Y);

		grp->DrawEllipse(g_pBlackPen, Rect(-4, -4, 8, 8));

		grp->SetTransform(&_tempMat);

	}
	

	grp->ResetTransform();

}

#define BUFLEN 1024

struct S_UDPObject {

	SOCKET m_socket;
	sockaddr_in m_serverAddr, m_si_otherAddr;
	int m_recv_len,m_slen;
	char m_buf[BUFLEN];
	WSADATA m_wsa;
};

S_UDPObject g_udpObject;


DWORD ThreadID;
HANDLE hThread;
DWORD WINAPI ThreadFunc(LPVOID temp)
{
	//S_UDPObject *pUdp = (S_UDPObject *)&temp;
	S_UDPObject *pUdp = &g_udpObject;

	OutputDebugString(L"Start recv Thread \n");
	//int slen;
	while (1)
	{
		//clear the buffer by filling null, it might have previously received data
		memset(pUdp->m_buf, '\0', BUFLEN);
		OutputDebugString(L"Waiting for data...\n");
		//try to receive some data, this is a blocking call
		if ((pUdp->m_recv_len = recvfrom(pUdp->m_socket, pUdp->m_buf, BUFLEN, 0, 
			(sockaddr *) &pUdp->m_si_otherAddr, &pUdp->m_slen)) 
			== SOCKET_ERROR)
		{
			OutputDebugString(L"recvfrom() failed with error.\n");	
		}
		else {
			pUdp->m_buf[pUdp->m_recv_len] = 0x00;
			OutputDebugString(L"recv Data \n");
			OutputDebugStringA(pUdp->m_buf);
			OutputDebugString(L"\n");

			cJSON * root = cJSON_Parse(pUdp->m_buf);
			cJSON *xpos = cJSON_GetObjectItemCaseSensitive(root, "xpos");
			cJSON *ypos = cJSON_GetObjectItemCaseSensitive(root, "ypos");

			g_RemotePlayer.m_vPos.X = xpos->valueint - 160;
			g_RemotePlayer.m_vPos.Y = ypos->valueint - 120;


		}
		
	}
	return 0;
}


int openNetWork(S_UDPObject *pUdp,int nPort)
{
	pUdp->m_slen = sizeof(pUdp->m_si_otherAddr);

	if (WSAStartup(MAKEWORD(2, 2), &pUdp->m_wsa) != 0)
	{
		//return
		//printf("Failed. Error Code : %d", WSAGetLastError());
		//exit(EXIT_FAILURE);
		OutputDebugString(L"WSAStartup Failed.\n");
		return WSAGetLastError();
	}
	OutputDebugString(L"Initialised.\n");

	//Create a socket
	if ((pUdp->m_socket = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
	{
		//printf("Could not create socket : %d", WSAGetLastError());
		OutputDebugString(L"Could not create socket\n");
		return WSAGetLastError();
	}	
	OutputDebugString(L"Socket created..\n");
	
	//Prepare the sockaddr_in structure
	pUdp->m_serverAddr.sin_family = AF_INET;
	pUdp->m_serverAddr.sin_addr.s_addr = INADDR_ANY;
	pUdp->m_serverAddr.sin_port = htons(nPort);

	//Bind
	if (bind(pUdp->m_socket, ( sockaddr *)&pUdp->m_serverAddr, sizeof(pUdp->m_serverAddr)) == SOCKET_ERROR)
	{
		OutputDebugString(L"Bind failed with error code.\n");
		return  WSAGetLastError();
	}
	OutputDebugString(L"binding port..3333 \n");

	hThread = CreateThread(NULL, 0, ThreadFunc, &g_udpObject, 0, &ThreadID);

	return 0;
	
}
void closeNetwork(S_UDPObject *pUdp)
{
	closesocket(pUdp->m_socket);
	WSACleanup();
}

void initGame()
{	
	g_pBlackPen = new Pen(Color(0, 0, 0));

	plusEngine::fpOnLoop = OnUpdate;
	plusEngine::fpOnRender = OnRender;

	openNetWork(&g_udpObject,3333);

}

void finishGame()
{
	closeNetwork(&g_udpObject);
	delete g_pBlackPen;
}