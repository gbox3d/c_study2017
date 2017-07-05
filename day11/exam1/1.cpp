#include "stdafx.h"

TCHAR g_szaMsgLog[1024][256];
int g_nMsgLogTailIndex = 0;

void test1(HWND hWnd)
{
	//wcscpy(g_szaMsgLog[g_nMsgLogTailIndex++], L"hello");
	swprintf_s(g_szaMsgLog[g_nMsgLogTailIndex], 256, L"%d ¹ø ¸Þ¾¾Áö", g_nMsgLogTailIndex);
	g_nMsgLogTailIndex++;

	InvalidateRect(hWnd, NULL, TRUE);

}

void DisplayLog(HDC hdc)
{
	for (int i = 0; i < g_nMsgLogTailIndex; i++) {
		TextOut(hdc, 0, i * 24, g_szaMsgLog[i], wcslen(g_szaMsgLog[i]));
	}
}