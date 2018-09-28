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
	tileMap->GetInfo().vPos = D3DXVECTOR3(0, 0, -1);
}

void CTest::Update()
{
	OBJMANAGER->Update();
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
	OBJMANAGER->Destroy();
}