#pragma once
#include "CObj.h"
typedef class CTile :
	public CObj
{
private:
	TILE_INFO m_tTileInfo;
	D3DXVECTOR3 m_vMapPos;
public:
	CTile();
	CTile(INT _coordX, INT _coordY, bool _canPass = true);
	virtual ~CTile();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;

	TILE_INFO& GetTileInfo() { return m_tTileInfo; }
	
	void UpdatePos(const D3DXVECTOR3& _vMapPos) {
		m_tInfo.vPos = D3DXVECTOR3(_vMapPos.x + m_tTileInfo.Coordinate.X * TILE_INFO::tileSizeX * 0.5f
			+ m_tTileInfo.Coordinate.Y * (TILE_INFO::tileSizeX * 0.5f),
			_vMapPos.y + m_tTileInfo.Coordinate.Y * (TILE_INFO::tileSizeY*0.5f) - m_tTileInfo.Coordinate.X * (TILE_INFO::tileSizeY*0.5f), _vMapPos.z);
	}

public:

	virtual bool HandleMessage(const CTelegram& msg);
} *LPTILE;