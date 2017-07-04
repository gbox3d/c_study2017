// exam6.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

int main()
{
	char szBuf[32] = "disco";
	strcat(szBuf,"very");
	printf("%s \n", szBuf);
	strcat(szBuf, "-channel");
	printf("%s \n", szBuf);

	TCHAR wszBuf[32] = L"디스코";

	wcscat(wszBuf, L"배리");
	wcscat(wszBuf, L"체널");


    return 0;
}

