// exam1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ages[5];
	int avg = 0;
	//ages[2] = 20;
	 
	for (int i = 0; i < 5; i++) {
		printf("%d 번째 데이터를 입력하세요. : ",i);
		scanf("%d", &ages[i]);
	}

	//avg = ages[0] + ages[1] + ages[2] + ages[3] + ages[4];
	for (int i = 0; i < 5; i++) {
		avg += ages[i];
	}
	avg /= 5;

	printf("%d", avg);

	int max = 0;
	for (int i = 0; i < 5; i++) {
		if (max < ages[i]) {
			max = ages[i];
		}
	}

	int min = 0x7ffffff;
	for (int i = 0; i < 5; i++) {
		if (min > ages[i]) {
			min = ages[i];
		}
	}

	printf("\n 최대값은 : %d 최소값은 : %d\n", max,min);

    return 0;
}

