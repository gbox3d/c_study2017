// exam7.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

int main()
{
	/*
	char szBuf[64];
	gets_s(szBuf, 64);
	puts(szBuf);

	char c;
	c = getchar();
	putchar(c);
	*/

	char szTemp[64] = "apple[seed]tree";

	/*
	char *pTemp = szTemp + 5;
	char *pTemp2 = szTemp + 11;
	for (int i = 0; i < 5; i++) {
		*pTemp = *pTemp2;
		pTemp++;
		pTemp2++;
	}
	*/
	//strcpy(szTemp + 5, szTemp + 11);
	szTemp[5] = 0x00;
	strcat(szTemp, szTemp + 11);

	printf("%s \n", szTemp);

    return 0;
}

