#include "stdafx.h"

extern void win32_Printf(HWND, TCHAR *, ...);

void testProc3(HWND hWnd)
{
	static int nCount = 0;

	win32_Printf(hWnd, L"%d", nCount);
	nCount++;
}