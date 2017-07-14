#include "stdafx.h"

void S_ObjectPlayer_OnApply(S_ObjectPlayer *pThis, double fDelta)
{

}
void S_ObjectPlayer_OnRender(S_ObjectPlayer *pThis, Graphics *pGrp)
{
	//spaceship_crop.png
	pGrp->DrawImage(pThis->m_pImg, RectF(pThis->m_vPosition.X-43/2, pThis->m_vPosition.Y-35/2, 43, 35));

}
void S_ObjectPlayer_Setup(S_ObjectPlayer *pThis, irr::core::vector2df &startPos, Image *pImg)
{
	pThis->m_pImg = pImg;
	pThis->m_vPosition = startPos;

}