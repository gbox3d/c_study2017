#include "stdafx.h"
#include "../../engine/utils.h"

void procTest4(HWND hWnd)
{
	/*
	TCHAR animal[][20] = {
		L"사자",
		L"고양이",
		L"호랑이",
		L"여우",
		L"반달곰"
	};
	*/

	TCHAR *animals[5] = {
		L"사자",
		L"고양이",
		L"호랑이",
		L"여우",
		L"반달곰"
	};

	for (int i = 0; i < 5; i++) {
		win32_Printf(hWnd,L"%s", animals[i]);
	}

	win32_Printf(hWnd, L"%c", animals[0][1]);
	win32_Printf(hWnd, L"%c", animals[0][2]);

	win32_Printf(hWnd, L"%c", animals[1][1]);
	win32_Printf(hWnd, L"%c", animals[1][2]);

	win32_Printf(hWnd, L"%s", (*(animals + 2)));
	win32_Printf(hWnd, L"%c", *( (*(animals+2)) + 1 ) );

	win32_Printf(hWnd, L"%c", animals[4][2] );


}