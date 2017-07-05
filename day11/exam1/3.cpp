#include "stdafx.h"

extern void win32_Printf(HWND hWnd, TCHAR *fmt, ...);

void test()
{
	int a = 5;
	int b = 6;
	{
		int a = 7;
		int b = 8;
	}
}

void testProc3(HWND hWnd)
{
	int a = 1;
	{
		int a = 1;
		int b = 2;
		{
			int a = 3;
			int b = 4;

		}
	}

	test();

}