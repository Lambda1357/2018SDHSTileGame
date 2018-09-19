#include "DXUT.h"
#include "CTileMapManager.h"

#include "CTile.h"
#include "CTileMap.h"

CTileMapManager::CTileMapManager()
{
	Init();
}


CTileMapManager::~CTileMapManager()
{
	Destroy();
}

void CTileMapManager::Init()
{

}

void CTileMapManager::Destroy()
{
	for (auto iter : m_MapTileMaps)
	{
		SAFE_DELETE(iter.second);
	}
	m_MapTileMaps.clear();
}

LPTILEMAP CTileMapManager::LoadTileMapFromFile(const string & key, const wstring & wFileName)
{
	auto find = m_MapTileMaps.find(key);

	if (find != m_MapTileMaps.end())
		return find->second;

	// ���⼭ Ÿ�ϸ� ������ ������ �Ľ� ��
	// ���� vector�� ����
	std::vector<std::vector<CTile*>*>* vecTileMap = new std::vector<std::vector<CTile*>*>;

	// �� ���͸� ���� Ÿ�ϸ� ����
	LPTILEMAP tileMap = new CTileMap(vecTileMap);

	// �ʿ� ����
	m_MapTileMaps.insert(make_pair(key, tileMap));
	return tileMap;
}

LPTILEMAP CTileMapManager::LoadTileMapFromFileA(const string& key, const string & fileName)
{
	auto find = m_MapTileMaps.find(key);

	if (find != m_MapTileMaps.end())
		return find->second;

	// ���⼭ Ÿ�ϸ� ������ ������ �Ľ� ��
	// ���� vector�� ����
	std::vector<std::vector<CTile*>*>* vecTileMap = new std::vector<std::vector<CTile*>*>;

	// �Ľ�

	// �� ���͸� ���� Ÿ�ϸ� ����
	LPTILEMAP tileMap = new CTileMap(vecTileMap);

	// �ʿ� ����
	m_MapTileMaps.insert(make_pair(key, tileMap));
	return tileMap;
}

LPTILEMAP CTileMapManager::FindTileMap(const string & key)
{
	auto find = m_MapTileMaps.find(key);

	if (find == m_MapTileMaps.end())
		return nullptr;

	return find->second;
}
