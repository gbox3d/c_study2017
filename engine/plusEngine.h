#pragma once

#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

namespace plusEngine {
	extern void startUpGdiPlus();
	extern void CloseGdiPlus();
	extern void printf(Graphics *grp, int x, int y, TCHAR *fmt, ...);

	//루프제어 
	extern void(*fpOnLoop)(double);
	extern void(*fpOnRender)(double, Graphics*);
	extern void GDIPLUS_Loop(MSG &msg, Gdiplus::Rect rectScreen);

	namespace util {

		inline PointF irr2Point(irr::core::vector2df &a)
		{
			PointF b;
			b.X = a.X;
			b.Y = a.Y;

			return b;
		}
		inline PointF irr2Point(irr::core::vector3df &a)
		{			
			return irr2Point(irr::core::vector2df(a.X,a.Y));
		}

	}
}