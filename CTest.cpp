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
	OBJMANAGER->AddEntity(0,
		TILEMANAGER->LoadTileMapFromFileA("TEST_MAP", "./Assets/Map_Info/TestMap.mif")
	)->GetInfo().vPos = D3DXVECTOR3(0, 0, 0);

	auto player = OBJMANAGER->AddEntity(0, new CPlayer);

	OBJMANAGER->AddUIEntity(new CCursor);

	CAMERAMANAGER->SetFollowObj(player);
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
}