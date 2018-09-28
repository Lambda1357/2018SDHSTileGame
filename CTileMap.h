#pragma once
#include "CObj.h"

class CTile;

typedef class CTileMap : public CObj {

public:
	std::vector<std::vector<CTile*>*>* m_vecTileMap;

public:
	CTileMap() { Init(); }
	CTileMap(std::vector<std::vector<CTile*>*>* _vecTileMap, const string& _sTileMapName = "TileMap")
		: m_vecTileMap(_vecTileMap) {
		Init(); m_tInfo.sID = _sTileMapName;
	}
	virtual ~CTileMap();

	CTile* GetTileToCoord(int _x, int _y) { return (*((*m_vecTileMap)[_y]))[_x]; }

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;

	bool RectCollision(const RECT& _characterRect);
	bool CircleCollision(const D3DXVECTOR3& _centerPos, float _radius);

private:

	void SetTilesPosition();

public:

	virtual bool HandleMessage(const CTelegram& msg);
} *LPTILEMAP;
