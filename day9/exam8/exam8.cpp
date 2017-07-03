// exam8.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char *strItems = "pike,plate amor,lather grove,sword,dager";

	int nIndexTable[32];

	//인덱스 테이블 생성
	int nCount = 0;
	int i;
	for (i = 0; strItems[i] != 0x00; i++) {
		if (strItems[i] == ',') {
			nIndexTable[nCount++] = i;
		}
	}
	nIndexTable[nCount] = i;

	int nIndex = 0;
	printf("select index : ");
	scanf("%d", &nIndex);

	//printf("%s\n",&(strItems[nIndexTable[nIndex] ]) );

	char *pTemp = &(strItems[nIndexTable[nIndex]]);
	int nSize = (nIndexTable[nIndex + 1] - nIndexTable[nIndex])-1;
	pTemp += 1;
	
	for (int i = 0; i < nSize; i++) {
		printf("%c", pTemp[i]);
	}

	printf("\n");
    return 0;
}

