#pragma once
#include "Singleton.h"

class CTile;
class CTileMap;

class CTileMapManager :
	public CSingleton<CTileMapManager>
{
private:
	map<string, CTileMap*> m_MapTileMaps;
public:
	CTileMapManager();
	virtual ~CTileMapManager();

	void Init();
	void Destroy();

public:
	CTileMap* LoadTileMapFromFile(const string& key, const wstring& wFileName);
	CTileMap* LoadTileMapFromFileA(const string& key, const string& fileName);
	CTileMap* FindTileMap(const string& key);
};

#define TILEMANAGER CTileMapManager::GetInstance()