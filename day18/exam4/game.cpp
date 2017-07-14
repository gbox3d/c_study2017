#include "stdafx.h"

HWND g_hWnd;

BYTE g_KeyStatus[256];
S_ObjectPlayer g_objPlayer;
S_ObjectBullet g_TestBullet;
S_ObjectBullet g_Bullet_list[16];

void OnLoop(double fDelta)
{
	S_ObjectPlayer_OnApply(&g_objPlayer, fDelta);
	//ObjectBullet_OnApply(&g_TestBullet, fDelta);
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
	//ObjectBullet_OnRender(&g_TestBullet, pGrp);
	
	pGrp->ResetTransform();

}

Image *g_pImgSpaceShip;
void OnCreate(HWND hWnd)
{
	g_hWnd = hWnd;
	plusEngine::fpOnLoop = OnLoop;
	plusEngine::fpOnRender = OnRender;
	//키상태 초기화 
	for (int i = 0; i < 256; i++) {
		g_KeyStatus[i] = 0;
	}

	g_pImgSpaceShip = new Image(L"../../res/spaceship_crop.png");

	S_ObjectPlayer_Setup(&g_objPlayer, irr::core::vector2df(0, 0), g_pImgSpaceShip);
	//ObjectBullet_Setup(&g_TestBullet, irr::core::vector2df(-160, -120), g_objPlayer.m_vPosition, 8, 30);

}

void OnDestory(HWND hWnd)
{
	delete g_pImgSpaceShip;
}
