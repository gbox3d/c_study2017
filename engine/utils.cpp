#include "stdafx.h"

TCHAR g_szaMsgLog[1024][256];
int g_nMsgLogTailIndex = 0;

void win32_Printf(HWND hWnd, TCHAR *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	//swprintf_s(g_szaMsgLog[g_nMsgLogTailIndex], 256, L"%d ¹ø ¸Þ¾¾Áö", g_nMsgLogTailIndex);
	vswprintf_s(g_szaMsgLog[g_nMsgLogTailIndex], 256, fmt, ap);
	g_nMsgLogTailIndex++;
	va_end(ap);
	InvalidateRect(hWnd, NULL, TRUE);
}
void DisplayLog(HDC hdc)
{
	for (int i = 0; i < g_nMsgLogTailIndex; i++) {
		TextOut(hdc, 0, i * 24, g_szaMsgLog[i], wcslen(g_szaMsgLog[i]));
	}
}