// exam6.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int a, b, c;
	a = 1;
	b = 1;
	c = 1;

	printf_s("%d,%d,%d \n",a++,a++,a++);
	printf_s("%d \n", a);

	// ("%d,%d,%d \n",++a,++a,++a);
	//printf_s("%d \n", a);

    return 0;
}

