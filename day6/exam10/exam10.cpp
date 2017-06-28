// exam10.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


void printSum(int a, int b)
{
	int sum = a + b;
	printf_s("sum : %d \n", sum);

}

int getSum(int a, int b)
{
	return a + b;
}


int main()
{
	int a, b;
	int sum;

	scanf("%d %d", &a, &b);
	printSum(a, b);

	sum = getSum(a, b); 

	printf_s("%d \n", sum);
	
    return 0;
}

