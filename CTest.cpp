#include "DXUT.h"
#include "CTest.h"
#include "CPlayer.h"
#include "CCursor.h"

#include "CTileMap.h"

CTest::CTest()
{
}


CTest::~CTest()
{
	Destroy();
}

void CTest::Init()
{
	auto tileMap = OBJMANAGER->AddEntity(0, TILEMANAGER->LoadTileMapFromFileA("./Assets/Map_Info/TestMap.mif", "FirstTileMap"));

	auto player = OBJMANAGER->AddEntity(0, new CPlayer);

	OBJMANAGER->AddUIEntity(new CCursor);

	CAMERAMANAGER->SetFollowObj(player);
	tileMap->GetInfo().vPos = D3DXVECTOR3(-TILE_INFO::tileSizeX*5, 0, -1);

	COLMANAGER->InsertObj(reinterpret_cast<CGameObject*>(player));
	COLMANAGER->SetTileMap(reinterpret_cast<CTileMap*>(tileMap));
}

void CTest::Update()
{
	OBJMANAGER->Update();
	COLMANAGER->CollisionCheck();
}

void CTest::Render()
{
	OBJMANAGER->Render();
}

void CTest::UI_Render()
{
	OBJMANAGER->UI_Render();
}

void CTest::Destroy()
{
	COLMANAGER->ListClear();
	OBJMANAGER->Destroy();
}