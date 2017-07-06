#include "stdafx.h"



void testPrintf(HDC hdc, TCHAR *fmt, ...)
{
	va_list ap;
	TCHAR szBuf[256];
	va_start(ap, fmt);
	//swprintf_s(szBuf, fmt, ap);
	vswprintf_s(szBuf, fmt, ap);
	va_end(ap);

	TextOut(hdc, 0, 0, szBuf, wcslen(szBuf));

}

void testScanf(const TCHAR *szBuf,const TCHAR *fmt,...)
{
	va_list ap;
	//TCHAR szBuf[256];
	va_start(ap, fmt);
	vswscanf(szBuf, fmt, ap);
	va_end(ap);
}