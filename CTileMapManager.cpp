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
}

LPTILEMAP CTileMapManager::LoadTileMapFromFile(const wstring & wFileName,
	const string& _sTileMapName)
{
	// ==================================================
	// 파싱
	// ==================================================

	// 좌표평면위의 좌표 표현용 임시 객체
	struct COORDICATE
	{
		INT X;
		INT Y;
	};

	// 여기서 타일맵 데이터 파일을 파싱 후
	// 이중 vector에 저장
	std::vector<std::vector<CTile*>*>* vecTileMap = new std::vector<std::vector<CTile*>*>;

	// 파일 스트림, 임시 저장 리스트
	std::ifstream ifile;
	std::list<CTile*> temporary;


	// 각 줄을 저장할 변수, 임시 좌표계
	char line[MAX_PATH];
	COORDICATE coordPos = { 0,0 };

	ifile.open(wFileName.c_str());

	if (ifile.is_open())
	{
		while (ifile.getline(line, sizeof(line)))
		{
			// 주석처리
			if (line[0] == '#')
				continue;
			if (line[0] == '\0')
				continue;

			// 좌표, 타일 타입, 지나갈 수 있는가
			INT type, is_canPass;

			sscanf(line, "X:%d Y:%d TYPE:%d %d", &coordPos.X, &coordPos.Y, &type, &is_canPass);

			// 타일 생성
			CTile* pTile = new CTile(coordPos.X, coordPos.Y, is_canPass);

			// 이미지 삽입 (타입 추론해서)
			switch (type)
			{
			case E_TEST_TILE:
				pTile->SetSprite(IMAGEMANAGER->FindImage("TEST_TILE"));
				break;

			case E_TEST_WALL_1:
				pTile->SetSprite(IMAGEMANAGER->FindImage("TEST_WALL_1"));
				break;

			case E_TEST_WALL_2:
				pTile->SetSprite(IMAGEMANAGER->FindImage("TEST_WALL_2"));
				break;

			default:
				SAFE_DELETE(pTile);
				DEBUG_LOG("이미지 로드 실패");
				break;
			}

			temporary.push_back(pTile);
		}
	}

	ifile.close();

	// ==================================================
	// 배열 크기 조정
	// ==================================================

	// 배열의 최대 크기를 알아냄
	int _max_X = 0, _max_Y = 0;
	for (auto iter : temporary)
	{
		int cur = 0;
		if ((cur = iter->GetTileInfo().Coordinate.X) > _max_X)
			_max_X = cur;
		if ((cur = iter->GetTileInfo().Coordinate.Y) > _max_Y)
			_max_Y = cur;
	}

	// Y 생성
	for (int i = 0; i < _max_Y + 1; i++)
		vecTileMap->push_back(new std::vector<CTile*>);

	// X 생성
	for (auto iter : *vecTileMap)
		for (int i = 0; i < _max_X + 1; i++)
			iter->push_back(nullptr);

	// ==================================================
	// 각 위치에 타일 배치
	// ==================================================

	for (auto iter : temporary) {
		(*(*vecTileMap)[iter->GetTileInfo().Coordinate.Y])[iter->GetTileInfo().Coordinate.X] = iter;
		DEBUG_LOG(iter->GetTileInfo().Coordinate.X << iter->GetTileInfo().Coordinate.Y);
	}

	// 임시 리스트 초기화
	temporary.clear();

	// 그 벡터를 가진 타일맵 생성
	CTileMap* tileMap = new CTileMap(vecTileMap, _sTileMapName);

	return tileMap;
}

LPTILEMAP CTileMapManager::LoadTileMapFromFileA(const string & fileName,
	const string& _sTileMapName)
{
	// ==================================================
	// 파싱
	// ==================================================

	// 좌표평면위의 좌표 표현용 임시 객체
	struct COORDICATE
	{
		INT X;
		INT Y;
	};

	// 여기서 타일맵 데이터 파일을 파싱 후
	// 이중 vector에 저장
	std::vector<std::vector<CTile*>*>* vecTileMap = new std::vector<std::vector<CTile*>*>;

	// 파일 스트림, 임시 저장 리스트
	std::ifstream ifile;
	std::list<CTile*> temporary;


	// 각 줄을 저장할 변수, 임시 좌표계
	char line[MAX_PATH];
	COORDICATE coordPos = { 0,0 };

	ifile.open(fileName.c_str());

	if (ifile.is_open())
	{
		while (ifile.getline(line, sizeof(line)))
		{
			// 주석처리
			if (line[0] == '#') 
				continue;
			if (line[0] == '\0')
				continue;

			// 좌표, 타일 타입, 지나갈 수 있는가
			INT type, is_canPass;
			
			sscanf(line, "X:%d Y:%d TYPE:%d %d", &coordPos.X, &coordPos.Y, &type, &is_canPass);

			// 타일 생성
			CTile* pTile = new CTile(coordPos.X, coordPos.Y, is_canPass);

			// 이미지 삽입 (타입 추론해서)
			switch (type)
			{
			case E_TEST_TILE:
				pTile->SetSprite(IMAGEMANAGER->FindImage("TEST_TILE"));
				break;

			case E_TEST_WALL_1:
				pTile->SetSprite(IMAGEMANAGER->FindImage("TEST_WALL_1"));
				break;

			case E_TEST_WALL_2:
				pTile->SetSprite(IMAGEMANAGER->FindImage("TEST_WALL_2"));
				break;

			default:
				SAFE_DELETE(pTile);
				DEBUG_LOG("이미지 로드 실패");
				break;
			}

			temporary.push_back(pTile);
		}
	}

	ifile.close();

	// ==================================================
	// 배열 크기 조정
	// ==================================================

	// 배열의 최대 크기를 알아냄
	int _max_X = 0, _max_Y = 0;
	for (auto iter : temporary)
	{
		int cur = 0;
		if ((cur = iter->GetTileInfo().Coordinate.X) > _max_X)
			_max_X = cur;
		if ((cur = iter->GetTileInfo().Coordinate.Y) > _max_Y)
			_max_Y = cur;
	}

	// Y 생성
	for (int i = 0; i < _max_Y + 1; i++)
		vecTileMap->push_back(new std::vector<CTile*>);

	// X 생성
	for (auto iter : *vecTileMap)
		for (int i = 0; i < _max_X + 1; i++)
			iter->push_back(nullptr);

	// ==================================================
	// 각 위치에 타일 배치
	// ==================================================

	for (auto iter : temporary) {
		(*(*vecTileMap)[iter->GetTileInfo().Coordinate.Y])[iter->GetTileInfo().Coordinate.X] = iter;
		DEBUG_LOG(iter->GetTileInfo().Coordinate.X << iter->GetTileInfo().Coordinate.Y);
	}

	// 임시 리스트 초기화
	temporary.clear();

	// 그 벡터를 가진 타일맵 생성
	CTileMap* tileMap = new CTileMap(vecTileMap, _sTileMapName);

	return tileMap;
}