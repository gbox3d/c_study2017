// exam9.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[5] = { 10,20,30,40,50 };
	int *pAry;

	pAry = ary;

	for (int i = 0; i < 5; i++) {
		printf("%d %d %d \n", pAry[i], *(pAry+i), *(ary+i) );
	}

    return 0;
}

