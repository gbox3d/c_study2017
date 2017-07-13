#include "stdafx.h"


void GameObject_Apply(GameObject *pThis,irr::f64 fDelta)
{
	irr::core::vector2df vDir(1, 0);

	vDir.rotateBy(pThis->m_fRotation);

	pThis->m_vPosition += (vDir * (pThis->m_fSpeed * fDelta) );

}

void GameObject_Draw(GameObject *pThis, Graphics &grp)
{
	grp.DrawImage(pThis->m_pImg, 
		pThis->m_vPosition.X-32, pThis->m_vPosition.Y-16, 
		pThis->m_pImg->GetWidth(), pThis->m_pImg->GetHeight());
}