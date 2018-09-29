#include "DXUT.h"
#include "CTile.h"

#include "CSprite.h"

CTile::CTile()
{
	Init();
}

CTile::CTile(INT _coordX, INT _coordY, bool _canPass)
{
	Init();
	m_tTileInfo.Coordinate.X = _coordX;
	m_tTileInfo.Coordinate.Y = _coordY;
	m_tTileInfo.bCanPass = _canPass;
	m_tTileInfo.bIsInScreen = false;
}


CTile::~CTile()
{
	Destroy();
}

void CTile::Init()
{

}

void CTile::Update()
{
	if (m_tInfo.vPos.x - (m_pSprite->m_Info.Width / 2.f) < (WINSIZEX / 2.f) + CAMERAMANAGER->GetCameraPos().x  &&
		m_tInfo.vPos.x + (m_pSprite->m_Info.Width / 2.f) > CAMERAMANAGER->GetCameraPos().x - (WINSIZEX / 2.f)  &&
		m_tInfo.vPos.y - (m_pSprite->m_Info.Height / 2.f) < (WINSIZEY / 2.f) + CAMERAMANAGER->GetCameraPos().y &&
		m_tInfo.vPos.y + (m_pSprite->m_Info.Height / 2.f) > CAMERAMANAGER->GetCameraPos().y - (WINSIZEY / 2.f))
		m_tTileInfo.bIsInScreen = true;
	else
		m_tTileInfo.bIsInScreen = false;

	SetRectColToImg(m_tInfo.vPos);
}

void CTile::Render()
{
	if (m_tTileInfo.bIsInScreen)
		IMAGEMANAGER->Render(m_pSprite, m_tInfo.vPos);
}

void CTile::Destroy()
{

}

bool CTile::HandleMessage(const CTelegram & msg)
{
	return HandleBasicMessage(msg);
}
