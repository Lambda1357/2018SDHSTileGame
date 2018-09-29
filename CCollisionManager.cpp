#include "DXUT.h"
#include "CCollisionManager.h"
#include "CTileMap.h"
#include "CTile.h"

CCollisionManager::CCollisionManager()
{
}


CCollisionManager::~CCollisionManager()
{
}

void CCollisionManager::CollisionCheck()
{
	// �ܺ� �ݺ��� : ���� ������Ʈ
	for (auto iter_target : m_objList)
	{
		// Ÿ�ϵ��� ������ ���� stl�� �ܺ�
		for (auto iter_tileLine : *m_pTileMap->m_vecTileMap)
		{
			// �� Ÿ�� iterator
			for (auto iter_targetTile : *iter_tileLine)
			{
				if (!iter_targetTile->GetTileInfo().bIsInScreen)
					continue;

				if (!iter_targetTile->GetTileInfo().bCanPass)
					continue;

				RECT rc;
				
				// �簢�� �浹ó�� ( �ӽ� )
				if (IntersectRect(&rc, &iter_target->GetCollider(), &iter_targetTile->GetCollider()))
				{
					D3DXVECTOR3 vReflectance = iter_targetTile->GetInfo().vPos - iter_target->GetInfo().vPos;

					D3DXVec3Normalize(&vReflectance, &vReflectance);

					iter_target->AddVector(vReflectance * -500 * DXUTGetElapsedTime());
				}
			}
		}
	}
}

void CCollisionManager::ListClear()
{
	m_objList.clear();
}

CGameObject * CCollisionManager::InsertObj(CGameObject * _insert)
{
	m_objList.push_back(_insert);

	return _insert;
}

CTileMap * CCollisionManager::SetTileMap(CTileMap * _target)
{
	return m_pTileMap = _target;
}
