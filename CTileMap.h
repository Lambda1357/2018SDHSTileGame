#pragma once
#include "CObj.h"

class CTile;

class CTileMap : public CObj {

public:
	std::vector<std::vector<CTile*>*>* m_vecTileMap;

public:
	CTileMap() {}
	CTileMap(std::vector<std::vector<CTile*>*>* _vecTileMap)
		: m_vecTileMap(_vecTileMap) {}
	virtual ~CTileMap();

	CTile* GetTileToCoord(int _x, int _y) { return (*((*m_vecTileMap)[_y]))[_x]; }

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;

	bool RectCollision(const RECT& _characterRect);
	bool CircleCollision(const D3DXVECTOR3& _centerPos, float _radius);

public:

	virtual bool HandleMessage(const CTelegram& msg);
};

typedef CTileMap *LPTILEMAP;