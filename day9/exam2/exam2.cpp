// exam2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	double ary[] = { 1.5, 20.1, 16.4, 2.3, 3.5 };
	double *ap = ary;
	//ap = ary;
	double tot=0;

	for (int i = 0; i < 5; i++) {
		//tot += ary[i];
		//tot += *(ary + i);
		tot += *(ap + i);
		//tot += *(&ary[0]+i);
	}

	printf("%lf \n", tot / 5);

    return 0;
}

