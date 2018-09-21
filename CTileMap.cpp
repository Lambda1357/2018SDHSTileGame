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

}

void CTileMap::Update()
{
	for (auto iter : *m_vecTileMap)
	{
		for (auto _iter : *iter)
		{
			if (_iter) {
				_iter->UpdatePos(this->m_tInfo.vPos);
				_iter->Update();
			}
		}
	}
}

void CTileMap::Render()
{
	for (auto iter : *m_vecTileMap)
	{
		for (auto _iter : *iter)
		{
			if (_iter) {
				if (_iter->GetInfo().vPos.x - (_iter->GetSprite()->m_Info.Width / 2.f) < (WINSIZEX/2.f) + CAMERAMANAGER->GetCameraPos().x - 50 &&
					_iter->GetInfo().vPos.x + (_iter->GetSprite()->m_Info.Width / 2.f) > CAMERAMANAGER->GetCameraPos().x - (WINSIZEX/2.f) + 50 &&
					_iter->GetInfo().vPos.y - (_iter->GetSprite()->m_Info.Height / 2.f) < (WINSIZEY/2.f) + CAMERAMANAGER->GetCameraPos().y - 50 &&
					_iter->GetInfo().vPos.y + (_iter->GetSprite()->m_Info.Height / 2.f) > CAMERAMANAGER->GetCameraPos().y - (WINSIZEY/2.f) + 50)
				{
					_iter->Render();
				}
			}
		}
	}
}

void CTileMap::Destroy()
{
	if (!m_vecTileMap)
		return;

	for (auto iter : *m_vecTileMap)
	{
		for (auto iter_ : *iter)
		{
			if (iter_)
			{
				iter_->Destroy();
				delete iter_;
				iter_ = nullptr;
			}
		}
		if (iter) {
			iter->clear();
			delete iter;
			iter = nullptr;
		}
	}
	if (m_vecTileMap) {
		m_vecTileMap->clear();
		delete m_vecTileMap;
		m_vecTileMap = nullptr;
	}
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