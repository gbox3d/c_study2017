// exam3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[] = { 2,8,15,1,8,5,19,19,3,5,6,6,2,8,2,12 };
	int num;
	printf("값을 입력하세요 : ");
	scanf("%d", &num);

	int nCount = 0;
	for (int i=0; i < sizeof(ary) / sizeof(ary[0]); i++) {
		if (ary[i] == num) {
			nCount++;
		}
	}

	printf("%d \n", nCount);

    return 0;
}

