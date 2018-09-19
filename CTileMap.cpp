#include "DXUT.h"
#include "CTileMap.h"

#include "CTile.h"

CTileMap::~CTileMap() {
	
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
			_iter->Update();
		}
	}
}

void CTileMap::Render()
{
	for (auto iter : *m_vecTileMap)
	{
		for (auto _iter : *iter)
		{
			_iter->Render();
		}
	}
}

void CTileMap::Destroy()
{
	for (auto iter : *m_vecTileMap)
	{
		for (auto iter_ : *iter)
		{
			if (iter_)
			{
				iter_->Destroy();
				delete iter;
			}
		}
		iter->clear();
		delete iter;
	}
	m_vecTileMap->clear();
	delete m_vecTileMap;
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
