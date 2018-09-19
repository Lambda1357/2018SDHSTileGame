#include "DXUT.h"
#include "CTile.h"


CTile::CTile()
{

}

CTile::CTile(INT _coordX, INT _coordY, bool _canPass)
{
	m_tTileInfo.Coordinate.X = _coordX;
	m_tTileInfo.Coordinate.Y = _coordY;
	m_tTileInfo.bCanPass = _canPass;
}


CTile::~CTile()
{

}

void CTile::Init()
{

}

void CTile::Update()
{

}

void CTile::Render()
{
	IMAGEMANAGER->Render(m_pSprite, m_tInfo.vPos);
}

void CTile::Destroy()
{

}

bool CTile::HandleMessage(const CTelegram & msg)
{
	return false;
}
