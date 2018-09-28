#pragma once
#include "Singleton.h"

class CTile;
class CTileMap;

class CTileMapManager :
	public CSingleton<CTileMapManager>
{
public:
	CTileMapManager();
	virtual ~CTileMapManager();

	void Init();
	void Destroy();

public:
	CTileMap* LoadTileMapFromFile(const wstring& wFileName,const string& _sTileMapName = "TileMap");
	CTileMap* LoadTileMapFromFileA(const string& fileName,const string& _sTileMapName = "TileMap");
};

#define TILEMANAGER CTileMapManager::GetInstance()