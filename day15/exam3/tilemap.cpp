#include "stdafx.h"
#include "tilemap.h"
//0,177


void InitMap(S_GAMEMAP *pMap, int width, int height,TCHAR *szImgFile,
	int nTileWidth,int nTileHeight
	)
{
	pMap->m_nWidth = width;
	pMap->m_nHeight = height;	
	
	memset(pMap->m_Map, 0, sizeof(int) * 1024);

	pMap->m_TileWidth = nTileWidth;
	pMap->m_TileHeight = nTileHeight;
	pMap->m_ImageObj = new Image(szImgFile);
}

void SetTilePosition(S_GAMEMAP *pMap, int x, int y, int index)
{
	pMap->m_TilePositions[index] = irr::core::vector2di(x, y);
}

void SetMapIndex(S_GAMEMAP *pMap,int x, int y, int index)
{
	pMap->m_Map[pMap->m_nWidth*y + x] = index;
}

void DrawTile(S_GAMEMAP *pMap, Graphics *pGrp,int x, int y,int nTileIndex)
{
	int cutx = pMap->m_TilePositions[nTileIndex].X;
	int cuty = pMap->m_TilePositions[nTileIndex].Y;
	pGrp->DrawImage(pMap->m_ImageObj,
		Rect(x * pMap->m_TileWidth, y * pMap->m_TileHeight, pMap->m_TileWidth, pMap->m_TileHeight),
		cutx,  //원본 x 위치
		cuty,  //원본 y 위치
		pMap->m_TileWidth, pMap->m_TileHeight,
		UnitPixel);
}

void DrawMap(S_GAMEMAP *pMap, Graphics *pGrp, int xOrg, int yOrg)
{
	for (int i = 0; i < pMap->m_nHeight; i++) {
		for (int j = 0; j < pMap->m_nWidth; j++) {
			//...
			int nTileIndex = pMap->m_Map[j + (i*pMap->m_nWidth)];
			if (nTileIndex > 0) {
				DrawTile(pMap, pGrp, xOrg + j, yOrg + i, nTileIndex-1);
			}
			else {

			}			
			//pGrp->DrawImage(img,)
			//pGrp->DrawImage(pMap->m_ImageObj,Rect())
		}
	}
}

void DrawTilePalette(S_GAMEMAP *pMap, Graphics *pGrp, int xOrg, int yOrg)
{
	for (int i = 0; i < 8; i++) {
		DrawTile(pMap, pGrp, xOrg + i, yOrg, i );
	}
}