// exam3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[5] = { 10,20,30,40,50 };
	int *ap = ary;

	printf("%d \n", *(ary+1));

	printf("%d \n", *(ap + 1));
	ap = ap + 1;
	printf("%d \n", *(ap + 1));

	//ary = ary + 1;  //쓰기가 되지않는다.

    return 0;
}

