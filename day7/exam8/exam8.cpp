// exam8.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

void dumpBuf(int nBuf[],int nSize)
{
	for (int i = 0; i < nSize; i++) {
		printf("%d", nBuf[i]);
	}

	printf("\n");
}

int main()
{
	int nBuf[] = {1,2,3,4,5,6,7,8};
	int nBufSize = sizeof(nBuf) / sizeof(nBuf[0]);

	dumpBuf(nBuf, nBufSize);

	bool bLoop = true;
	while (bLoop) {
		int nIndex;
		printf("삭제할 위치을 입력하세요 (나가시려면 8이상 입력하세요):");
		scanf("%d", &nIndex);
		if (nIndex >= 8) {
			bLoop = false;
		}

		for (int i = nIndex; i < (nBufSize-1); i++) {
			nBuf[i] = nBuf[i + 1];
		}

		dumpBuf(nBuf,nBufSize);

	}

	return 0;
}
