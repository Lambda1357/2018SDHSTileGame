#include "DXUT.h"
#include "CTest.h"
#include "CPlayer.h"
#include "CCursor.h"

CTest::CTest()
{
}


CTest::~CTest()
{
	Destroy();
}

void CTest::Init()
{
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