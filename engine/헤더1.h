#pragma once



namespace myGdiplusGame {
	
	const int g_nTileSize = 16;
	const int g_nTileXCount = 8;

	void drawTile(Graphics *pGrp, Image *pImgBasicTile, int nPosX, int nPosY, int nTileIndex)
	{
		//int nTileIndex = 14;
		pGrp->DrawImage(pImgBasicTile,
			Rect(nPosX, nPosY, g_nTileSize, g_nTileSize),
			g_nTileSize * (nTileIndex % g_nTileXCount), //원본 x 위치
			g_nTileSize * (nTileIndex / g_nTileXCount),  //원본 y 위치
			g_nTileSize, g_nTileSize,
			UnitPixel);
	}

}
