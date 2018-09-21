#include "DXUT.h"
#include "CMainGame.h"


CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
	Destroy();
}

void CMainGame::Init()
{
}

void CMainGame::Update()
{
	INPUTMANAGER->KeyUpdate();
	MESSAGEMANAGER->Update();
	SCENEMANAGER->Update();
}

void CMainGame::Render()
{
	IMAGEMANAGER->Render_Begin(false);

	CAMERAMANAGER->SetTransform();
	CAMERAMANAGER->Update();

	SCENEMANAGER->Render();
	IMAGEMANAGER->Render_End();

	IMAGEMANAGER->Render_Begin(true);
	SCENEMANAGER->UI_Render();
	IMAGEMANAGER->Render_End();
}

void CMainGame::Destroy()
{
	CSceneManager	::ReleaseInstance();
	CImageManager	::ReleaseInstance();
	CInputManager	::ReleaseInstance();
	CSoundManager	::ReleaseInstance();
	CObjManager		::ReleaseInstance();
	CMessageManager	::ReleaseInstance();
	CCameraManager	::ReleaseInstance();
	CTileMapManager	::ReleaseInstance();
}

void CMainGame::Lost()
{
	IMAGEMANAGER->Lost();
}

void CMainGame::Reset()
{
	IMAGEMANAGER->Reset();
}

