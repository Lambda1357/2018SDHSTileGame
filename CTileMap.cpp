#include "DXUT.h"
#include "CTileMap.h"

#include "CTile.h"
#include "CSprite.h"

CTileMap::~CTileMap()
{
	Destroy();
}

void CTileMap::Init()
{
	int iIdCount = 0;

	for (auto iter : *m_vecTileMap)
	{
		for (auto _iter : *iter)
		{
			OBJMANAGER->AddEntity(E_TYPE_TILES, _iter);
			_iter->GetInfo().sID = m_tInfo.sID + "_tile_" + to_string(iIdCount++);
		}
	}
}

void CTileMap::Update()
{
	for (auto iter : *m_vecTileMap)
	{
		for (auto _iter : *iter)
		{
			if (_iter) {
				_iter->UpdatePos(this->m_tInfo.vPos);
			}
		}
	}
}

void CTileMap::Render()
{
}

void CTileMap::Destroy()
{
	for (auto iter : *m_vecTileMap)
	{
		iter->clear();
		SAFE_DELETE(iter);
	}
	m_vecTileMap->clear();
}

bool CTileMap::RectCollision(const RECT & _characterRect)
{
	return false;
}

bool CTileMap::CircleCollision(const D3DXVECTOR3 & _centerPos, float _radius)
{
	return false;
}

bool CTileMap::HandleMessage(const CTelegram & msg)
{
	return HandleBasicMessage(msg);
}

void CTileMap::SetTilesPosition()
{
}