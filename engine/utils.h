#pragma once


extern void win32_Printf(HWND hWnd, TCHAR *fmt, ...);
extern void DisplayLog(HDC hdc);
void win32_Scanf(const TCHAR *szBuf, const TCHAR *fmt, ...);