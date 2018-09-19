#include "DXUT.h"
#include "CBullet.h"

CBullet::CBullet(const D3DXVECTOR3& _startPos, const D3DXVECTOR3 & vGovec, float fSpeed)
	: m_vGoVector(vGovec),
	m_fSpeed(fSpeed)
{
	m_tInfo.vPos = _startPos;
}

CBullet::~CBullet()
{
}

void CBullet::Init()
{
	m_pSprite = IMAGEMANAGER->FindImage("BULLET");
}

void CBullet::Update()
{
	m_tInfo.vPos += m_vGoVector * m_fSpeed;

	m_fRot = D3DXToDegree(atan2f(m_tInfo.vPos.y, m_tInfo.vPos.x));
}

void CBullet::Render()
{
	IMAGEMANAGER->Render(m_pSprite, m_tInfo.vPos, m_fRot);
}

void CBullet::Destroy()
{

}
