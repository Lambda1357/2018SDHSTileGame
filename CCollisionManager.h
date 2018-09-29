#pragma once
#include "Singleton.h"

class CTileMap;
class CGameObject;

class CCollisionManager :
	public CSingleton<CCollisionManager>
{
private:
	CTileMap * m_pTileMap;
	list<CGameObject*> m_objList;
public:
	CCollisionManager();
	virtual ~CCollisionManager();

	void CollisionCheck();
	void ListClear();

	CGameObject* InsertObj(CGameObject* _insert);
	CTileMap* SetTileMap(CTileMap* _target);
};

#define COLMANAGER CCollisionManager::GetInstance()