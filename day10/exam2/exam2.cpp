// exam2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char *pTest = "123456789";	

	char *ptr1 = pTest;

	printf("%s \n",ptr1);
	ptr1 += 1;
	printf("%s \n", ptr1);

	ptr1 += 4;
	printf("%s \n", ptr1);

	//ptr1[0] = '*';

	//printf("%s \n", pTest);

    return 0;
}

