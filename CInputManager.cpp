#include "DXUT.h"
#include "CInputManager.h"


CInputManager::CInputManager()
{
}


CInputManager::~CInputManager()
{
}

void CInputManager::KeyUpdate()
{
	memcpy(m_oldKeyState, m_curKeyState, 256);

	for (int i = 0; i < 256; i++)
	{
		if (HIBYTE(GetAsyncKeyState(i)))
			m_curKeyState[i] = 1;

		else
			m_curKeyState[i] = 0;
	}
}

POINT CInputManager::GetpMousePos()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	return pt;
}
D3DXVECTOR3 CInputManager::GetvScreenMousePos()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	D3DXVECTOR3 vMousePos = D3DXVECTOR3((float)pt.x, (float)pt.y, 0);

	return vMousePos;
}
D3DXVECTOR3 CInputManager::GetvScrollMousePos()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	pt.x = (pt.x - WINSIZEX / 2);
	pt.y = (pt.y - WINSIZEY / 2);

	D3DXVECTOR2 vScroll = CAMERAMANAGER->GetCameraPos();
	D3DXVECTOR3 vMousePos = D3DXVECTOR3((float)pt.x + vScroll.x, (float)pt.y + vScroll.y, 0);

	return vMousePos;
}