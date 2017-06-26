// exam11.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int nNum, nAge;
	double dbHitRate;

	printf("등번호를 입력하세요 "); scanf_s("%d", &nNum);
	printf("타율을 입력하세요 "); scanf_s("%lf", &dbHitRate);
	printf("나이를 입력하세요 "); scanf_s("%d", &nAge);

	printf(" %d번 선수의 타율은 %lf 나이는 %d 입니다. \n",nNum,dbHitRate,nAge);


    return 0;
}

