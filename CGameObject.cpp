#include "DXUT.h"
#include "CGameObject.h"

#include "CSprite.h"

CGameObject::CGameObject()
{
}


CGameObject::~CGameObject()
{
}

void CGameObject::AddVector(const D3DXVECTOR3 & _plusV)
{
	DEBUG_LOG(_plusV, x << " " << _plusV.y);
	m_tInfo.vPos += _plusV;
}

void CGameObject::SetRectColToImg(const D3DXVECTOR3 & _center)
{
	m_rcCol.left = _center.x - m_pSprite->m_Info.Width / 2.f;
	m_rcCol.top = _center.y - m_pSprite->m_Info.Height / 2.f;
	m_rcCol.right = _center.x + m_pSprite->m_Info.Width / 2.f;
	m_rcCol.bottom = _center.y + m_pSprite->m_Info.Height / 2.f;
}
