#pragma once
#include "Singleton.h"
class CInputManager :
	public CSingleton<CInputManager>
{
private:
	char m_curKeyState[256];
	char m_oldKeyState[256];
public:
	void KeyUpdate();
	POINT GetpMousePos();
	D3DXVECTOR3 GetvScreenMousePos();
	D3DXVECTOR3 GetvScrollMousePos();
public:
	inline bool DOWN_KEY(int vk) { return m_curKeyState[vk] == 1 && m_oldKeyState[vk] == 0; }
	inline bool PUSH_KEY(int vk) { return m_curKeyState[vk] == 1 && m_oldKeyState[vk] == 1; }
	inline bool UP_KEY(int vk) { return m_curKeyState[vk] == 0 && m_oldKeyState[vk] == 1; }
public:
	CInputManager();
	virtual ~CInputManager();
};

#define INPUTMANAGER CInputManager::GetInstance()
