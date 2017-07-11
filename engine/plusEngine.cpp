#include "stdafx.h"
#include "plusEngine.h"

namespace plusEngine {
	//gdi plus 초기화 코드 
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	
	void startUpGdiPlus()
	{
		//----------------------------------------------------------------------
		// Initialize GDI+.
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
		//----------------------------------------------------------------
				

	}
	void CloseGdiPlus()
	{
		//--------------------------------------
		//gdi plus 종료코드 
		GdiplusShutdown(gdiplusToken);
		//--------------------------------------
	}

	void printf(Graphics *grp, int x, int y, TCHAR *fmt, ...)
	{
		va_list ap;
		va_start(ap, fmt);
		static TCHAR szBuf[1024];
		vswprintf_s(szBuf, 1024, fmt, ap);
		
		Pen pen(Color(255, 0, 0));
		Gdiplus::SolidBrush brushBlack(Color(0, 0, 0));
		Gdiplus::SolidBrush brushWhite(Color(255, 255, 255));
		FontFamily  fontFamily(L"굴림");
		Font        font(&fontFamily, 12, FontStyleRegular, UnitPixel);

		//TCHAR szBuf[256];
		//swprintf_s(szBuf, L" %f", 45);
		grp->DrawString(szBuf, -1, &font, PointF(x, y), &brushBlack);

		//grp->DrawString(L"hello", -1, g_pDebugFont, PointF(x, y), &g_brushBlack);


		va_end(ap);
	}
}