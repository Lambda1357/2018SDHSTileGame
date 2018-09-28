#include "DXUT.h"
#include "CTileMapManager.h"

#include "CTile.h"
#include "CTileMap.h"

#include <fstream>

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
	// ==================================================
	// Ÿ�ϸ� ������ �߷�
	// ==================================================

	auto find = m_MapTileMaps.find(key);

	if (find != m_MapTileMaps.end())
		return find->second;

	// ==================================================
	// �Ľ�
	// ==================================================

	// ��ǥ������� ��ǥ ǥ���� �ӽ� ��ü
	struct COORDICATE
	{
		INT X;
		INT Y;
	};

	// ���⼭ Ÿ�ϸ� ������ ������ �Ľ� ��
	// ���� vector�� ����
	std::vector<std::vector<CTile*>*>* vecTileMap = new std::vector<std::vector<CTile*>*>;

	// ���� ��Ʈ��, �ӽ� ���� ����Ʈ
	std::ifstream ifile;
	std::list<CTile*> temporary;


	// �� ���� ������ ����, �ӽ� ��ǥ��
	char line[MAX_PATH];
	COORDICATE coordPos = { 0,0 };

	ifile.open(fileName.c_str());

	if (ifile.is_open())
	{
		while (ifile.getline(line, sizeof(line)))
		{
			// �ּ�ó��
			if (line[0] == '#') 
				continue;
			if (line[0] == '\0')
				continue;

			// ��ǥ, Ÿ�� Ÿ��, ������ �� �ִ°�
			INT type, is_canPass;
			
			sscanf(line, "X:%d Y:%d TYPE:%d %d", &coordPos.X, &coordPos.Y, &type, &is_canPass);

			// Ÿ�� ����
			CTile* pTile = new CTile(coordPos.X, coordPos.Y, is_canPass);

			// �̹��� ���� (Ÿ�� �߷��ؼ�)
			switch (type)
			{
			case E_TEST_TILE:
				pTile->SetSprite(IMAGEMANAGER->FindImage("TEST_TILE"));
				break;

			default:
				SAFE_DELETE(pTile);
				DEBUG_LOG("�̹��� �ε� ����");
				break;
			}

			temporary.push_back(pTile);
		}
	}

	ifile.close();

	// ==================================================
	// �迭 ũ�� ����
	// ==================================================

	// �迭�� �ִ� ũ�⸦ �˾Ƴ�
	int _max_X = 0, _max_Y = 0;
	for (auto iter : temporary)
	{
		int cur = 0;
		if ((cur = iter->GetTileInfo().Coordinate.X) > _max_X)
			_max_X = cur;
		if ((cur = iter->GetTileInfo().Coordinate.Y) > _max_Y)
			_max_Y = cur;
	}

	// Y ����
	for (int i = 0; i < _max_Y + 1; i++)
		vecTileMap->push_back(new std::vector<CTile*>);

	// X ����
	for (auto iter : *vecTileMap)
		for (int i = 0; i < _max_X + 1; i++)
			iter->push_back(nullptr);

	// ==================================================
	// �� ��ġ�� Ÿ�� ��ġ
	// ==================================================

	for (auto iter : temporary) {
		(*(*vecTileMap)[iter->GetTileInfo().Coordinate.Y])[iter->GetTileInfo().Coordinate.X] = iter;
		DEBUG_LOG(iter->GetTileInfo().Coordinate.X << iter->GetTileInfo().Coordinate.Y);
	}

	// �ӽ� ����Ʈ �ʱ�ȭ
	temporary.clear();

	// �� ���͸� ���� Ÿ�ϸ� ����
	CTileMap* tileMap = new CTileMap(vecTileMap);

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
