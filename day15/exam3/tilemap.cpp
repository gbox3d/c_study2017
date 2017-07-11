#include "stdafx.h"

//0,177


struct S_GAMEMAP {
	int m_nWidth, m_nHeight;
	Image *m_ImageObj;
	int m_Map[1024];
};

void InitMap(S_GAMEMAP *pMap, int width, int height,TCHAR *szImgFile)
{
	pMap->m_nWidth = width;
	pMap->m_nHeight = height;	
	pMap->m_ImageObj = new Image(szImgFile);
	memset(pMap->m_Map, 0, sizeof(int) * 1024);
}

void SetMapIndex(S_GAMEMAP *pMap,int x, int y, int index)
{
	pMap->m_Map[pMap->m_nWidth*y + x] = index;
}

void DrawMap(S_GAMEMAP *pMap, Graphics *pGrp, int xOrg, int yOrg)
{
	for (int i = 0; i < pMap->m_nHeight; i++) {
		for (int j = 0; j < pMap->m_nWidth; j++) {
			//...
			//pGrp->DrawImage(img,)
			//pGrp->DrawImage(pMap->m_ImageObj,Rect())
		}
	}

}