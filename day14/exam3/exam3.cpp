// exam3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>

int main()
{
	//int ary[5] = {23,24,21,25,31}
	int *ip;
	//sizeof(int) * 5 = 20
	ip = (int *)malloc(20);
	ip[0] = 23;
	ip[1] = 24;
	ip[2] = 21;
	ip[3] = 25;
	ip[4] = 31;

	int avr=0;
	for (int i = 0; i < 5; i++) {
		avr += ip[i];
	}
	printf("%d\n", avr / 5);

    return 0;
}

