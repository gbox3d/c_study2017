#include "stdafx.h"

HWND g_hWnd;

BYTE g_KeyStatus[256];
S_ObjectPlayer g_objPlayer;
S_ObjectBullet *g_pBullet_List[16];

Image *g_pImgSpaceShip;

irr::f64 g_fAcctick = 0;

void OnLoop(double fDelta)
{
	if (fDelta < 0 || fDelta > 1.0) {
		fDelta = 0;
	}
	//총알시체처리
	{
		int i;
		for (i = 0; i < 16; i++) {
			
			if (g_pBullet_List[i] != NULL && g_pBullet_List[i]->m_nFSM == 999  ) {
				free(g_pBullet_List[i]);
				g_pBullet_List[i] = NULL;
			}
		}
	}
	//총알 발사
	g_fAcctick += fDelta;
	if (g_fAcctick > 3.0) {
		g_fAcctick = 0.0;

		int i;
		for (i = 0; i < 16; i++) {
			if (g_pBullet_List[i] == NULL) {
				S_ObjectBullet *ptr = (S_ObjectBullet *)malloc(sizeof(S_ObjectBullet));
				ObjectBullet_Setup(ptr, irr::core::vector2df(0, -120), g_objPlayer.m_vPosition, 8, rand() % 50 + 20);
				g_pBullet_List[i] = ptr;
				break;
			}
		}
	}

	S_ObjectPlayer_OnApply(&g_objPlayer, fDelta);
	
	for (int i = 0; i < 16; i++) {
		
		S_ObjectBullet *ptr = g_pBullet_List[i];
		if (ptr != NULL) {
			ObjectBullet_OnApply(ptr, fDelta);
		}
	}
}

void OnRender(double fDelta,Graphics *pGrp)
{
	pGrp->Clear(Color(200, 191, 231));
	if (fDelta > 0) {
		plusEngine::printf(pGrp, 0, 0, L"fps : %lf", 1.0 / fDelta);
	}
	else {
		plusEngine::printf(pGrp, 0, 0, L"fps : %lf", 1000.f);
	}
	Pen pen(Color(0, 0, 0));
	//Pen pen2(Color(255, 0, 0));
	pGrp->DrawRectangle(&pen, 0, 0, 320, 240);
	pGrp->DrawLine(&pen, 0, 120, 320, 120);
	pGrp->DrawLine(&pen, 160, 0, 160, 240);

	Matrix originMat(1, 0, 0, 1, 160, 120);
	pGrp->SetTransform(&originMat);	

	S_ObjectPlayer_OnRender(&g_objPlayer, pGrp);
	
	for (int i = 0; i < 16; i++) {
		S_ObjectBullet *ptr = g_pBullet_List[i];
		if (ptr != NULL) {
			ObjectBullet_OnRender(ptr, pGrp);
		}
	}
	
	pGrp->ResetTransform();

}

void OnCreate(HWND hWnd)
{
	g_hWnd = hWnd;
	plusEngine::fpOnLoop = OnLoop;
	plusEngine::fpOnRender = OnRender;
	//키상태 초기화 
	for (int i = 0; i < 256; i++) {
		g_KeyStatus[i] = 0;
	}

	for (int i = 0; i < 16; i++) {
		g_pBullet_List[i] = NULL;
	}

	g_pImgSpaceShip = new Image(L"../../res/spaceship_crop.png");

	S_ObjectPlayer_Setup(&g_objPlayer, irr::core::vector2df(0, 0), g_pImgSpaceShip);
	//ObjectBullet_Setup(&g_TestBullet, irr::core::vector2df(-160, -120), g_objPlayer.m_vPosition, 8, 30);

}

void OnDestory(HWND hWnd)
{
	delete g_pImgSpaceShip;
}
