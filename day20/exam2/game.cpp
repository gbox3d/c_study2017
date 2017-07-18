#include "stdafx.h"

Pen *g_pBlackPen;

struct S_PlayerGhost
{
	irr::core::vector2df m_pos;
};

S_PlayerGhost g_RemotePlayer;

void OnUpdate(double fDelta)
{

}

void OnRender(double fDelta, Graphics *pGrp)
{
	pGrp->Clear(Color(200,191,231));

	Matrix originMat(1,0,0,1,160,120);
	pGrp->SetTransform(&originMat);

	{
		Matrix tempMat;
		pGrp->GetTransform(&tempMat);

		pGrp->TranslateTransform(g_RemotePlayer.m_pos.X, g_RemotePlayer.m_pos.Y);
		pGrp->DrawEllipse(g_pBlackPen, Rect(-8,-8,16,16));

		pGrp->SetTransform(&tempMat);
	}

	pGrp->ResetTransform();

}


#define BUFLEN 1024

struct S_UDPObject {

	SOCKET m_socket;
	sockaddr_in m_serverAddr, m_si_otherAddr;
	int m_recv_len, m_slen;
	char m_buf[BUFLEN];
	WSADATA m_wsa;

};

S_UDPObject g_udpObject;

DWORD ThreadID;
HANDLE hThread;

DWORD WINAPI ThreadFunc(LPVOID temp)
{
	S_UDPObject *pUdp = (S_UDPObject *)temp;

	OutputDebugStringA("start recv thread");

	while (1) {
		memset(pUdp->m_buf, '\0', BUFLEN);
		OutputDebugStringA("waiting for data.....\n");
		if ( (pUdp->m_recv_len = recvfrom(pUdp->m_socket, pUdp->m_buf, BUFLEN, 0,
			(sockaddr *)&pUdp->m_si_otherAddr, &pUdp->m_slen) ) == SOCKET_ERROR) {
			OutputDebugStringA("recvfrom error\n");
		}
		else {
			OutputDebugStringA("success recv data \n");
			OutputDebugStringA(pUdp->m_buf);
			OutputDebugStringA("\n");

			cJSON *root = cJSON_Parse(pUdp->m_buf);
			cJSON *xpos = cJSON_GetObjectItemCaseSensitive(root, "xpos");
			cJSON *ypos = cJSON_GetObjectItemCaseSensitive(root, "ypos");

			g_RemotePlayer.m_pos.X = xpos->valueint-160;
			g_RemotePlayer.m_pos.Y = ypos->valueint-120;


		}
	}

}


int openNetWork(S_UDPObject *pUdp, int nPort)
{
	pUdp->m_slen = sizeof(pUdp->m_si_otherAddr);
	if (WSAStartup(MAKEWORD(2, 2), &pUdp->m_wsa) != 0) {
		OutputDebugStringA("WSAStartup failed\n");
		return WSAGetLastError();
	}
	OutputDebugStringA("WSAStartup success\n");

	if ((pUdp->m_socket = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
		OutputDebugStringA("create socket failed\n");
		return WSAGetLastError();
	}
	OutputDebugStringA("create socket success\n");

	pUdp->m_serverAddr.sin_family = AF_INET;
	pUdp->m_serverAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	pUdp->m_serverAddr.sin_port = htons(nPort);

	if (bind(pUdp->m_socket, (sockaddr *)&pUdp->m_serverAddr, sizeof(pUdp->m_serverAddr)) == SOCKET_ERROR) {
		OutputDebugStringA("bind failed\n");
		return WSAGetLastError();
	}

	OutputDebugStringA("bind success\n");

	hThread = CreateThread(NULL, 0, ThreadFunc, &g_udpObject, 0, &ThreadID);


	return 0;
}

void closeNetWork(S_UDPObject *pUdp)
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
	delete g_pBlackPen;

	closeNetWork(&g_udpObject);

}