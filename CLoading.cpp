#include "DXUT.h"
#include "CLoading.h"


CLoading::CLoading()
{
}


CLoading::~CLoading()
{
}

void CLoading::Init()
{
	IMAGEMANAGER->AddImage("PLAYER", L"./Assets/Sprites/Player.png");
	IMAGEMANAGER->AddImage("GUN", L"./Assets/Sprites/Gun.png");
	IMAGEMANAGER->AddImage("BULLET", L"./Assets/Sprites/Bullet.png");
	IMAGEMANAGER->AddImage("CURSOR", L"./Assets/Sprites/Cursor.png");

	IMAGEMANAGER->AddImage("TEST_TILE", L"./Assets/Sprites/Tiles/TestTile.png");
	IMAGEMANAGER->AddImage("TEST_WALL_1", L"./Assets/Sprites/Tiles/TestWall1.png");
	IMAGEMANAGER->AddImage("TEST_WALL_2", L"./Assets/Sprites/Tiles/TestWall2.png");
}

void CLoading::Update()
{
	SCENEMANAGER->ChangeScene("TEST");
}

void CLoading::Render()
{
}

void CLoading::UI_Render()
{
}

void CLoading::Destroy()
{

}