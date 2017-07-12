
1. stdafx.h 파일에 다음 추가 하기
#include "../../engine/irrlicht/include/irrlicht.h"
#include "../../engine/plusEngine.h"

2." shift + alt(option) + a " 한 다음 plusEngine.h plusEngine.cpp 추가하기

3. winMain 함수에 아래코드추가 

윈도우 초기화전에..
plusEngine::startUpGdiPlus();
메씨지 루프 다음에...
plusEngine::CloseGdiPlus();

4. WM_PAINT 에서 gdiplus 함수 사용.
