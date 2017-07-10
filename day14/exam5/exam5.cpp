// exam5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <Windows.h>
#include <stdlib.h>

int main()
{
	//char,double,int
	//BYTE buffer[256];
	void *pBuf = malloc(13);

	*((BYTE *)pBuf) = 'c';
	*(double *)((BYTE *)pBuf + 1) = 3.14;
	*(int *)((BYTE *)pBuf + 1 + 8) = 7;


	printf("%c %lf %d \n",
		*((BYTE *)pBuf),
		*(double *)((BYTE *)pBuf + 1),
		*(int *)((BYTE *)pBuf + 1 + 8)
	);

	free(pBuf);

    return 0;
}

