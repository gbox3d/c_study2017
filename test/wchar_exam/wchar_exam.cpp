// wchar_exam.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


#include <comdef.h>  // you will need this

int main()
{
	TCHAR *wc_test = L"안녕하슈";
	_bstr_t conv_sz(wc_test);
	printf("%s \n", (char *)conv_sz);
	

	char *szTest = "hello 안녕이라고했나?";

	TCHAR szBuf[256];
	mbstowcs(szBuf, szTest, 256);

	wprintf(L"%ws \n", szBuf);

	
    return 0;
}

