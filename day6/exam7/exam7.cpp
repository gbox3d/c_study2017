// exam7.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int i;

	for (i = 0; i < 10; i++) {
		//....
		printf_s("%d \n", i);
	}

	printf_s("--------------------\n");
	for (i = 0; i <= 10; i++) {
		//....
		printf_s("%d \n", i);
	}

    return 0;
}

