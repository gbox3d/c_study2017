// exam5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[2] = { 3,4 };
	int nTemp;

	nTemp = ary[0];
	ary[0] = ary[1];
	ary[1] = nTemp;

    return 0;
}

