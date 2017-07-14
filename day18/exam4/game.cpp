#include "stdafx.h"

HWND g_hWnd;
void OnLoop(double fDelta)
{

}

void OnRender(double fDelta,Graphics *pGrp)
{
	pGrp->Clear(Color(200, 191, 231));

}

void OnCreate(HWND hWnd)
{
	g_hWnd = hWnd;
	plusEngine::fpOnLoop = OnLoop;
	plusEngine::fpOnRender = OnRender;
}
