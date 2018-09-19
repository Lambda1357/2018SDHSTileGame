#pragma once
#include "CObj.h"
class CTile :
	public CObj
{
private:
	TILE_INFO m_tTileInfo;
public:
	CTile();
	CTile(INT _coordX, INT _coordY, bool _canPass = true);
	virtual ~CTile();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;

public:

	virtual bool HandleMessage(const CTelegram& msg);
};

	