// exam7.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

void assign(int *test)
{
	*test = 100;
}

void getSum(int a, int b, int *nSum)
{
	*nSum = a + b;

}

void exchange(int *a, int *b)
{
	int nTemp;
	nTemp = *a;
	*a = *b;
	*b = nTemp;
}

int main()
{
	int test = 0;
	assign(&test);
	printf("%d \n", test);
	getSum(5, 6, &test);
	printf("%d \n", test);
	
	int a = 7;
	int b = 8;
	exchange(&a, &b);
	printf("a:%d b:%d \n", a, b);
	// a:8  b:7

	return 0;
}
