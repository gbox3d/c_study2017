// exam8.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int main()
{
	int nNum = 0x11223344;
	unsigned char *pTest;

	pTest = (unsigned char *)&nNum;

	for (int i = 0; i < 4; i++) {
		printf("%x\n", *(pTest + i));
	}

	nNum = 0;
	*pTest = 8;
	/*
	*(pTest+1) = 1;
	*(pTest + 2) = 2;
	*(pTest + 3) = 3;*/

	printf("nNum : %x \n", nNum);


    return 0;
}

