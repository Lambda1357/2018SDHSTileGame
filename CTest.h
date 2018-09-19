#pragma once
#include "CScene.h"

class CPlayer;
class CCursor;
class CTest :
	public CScene
{
private:
	CPlayer * m_pPlayer;
public:
	virtual void Init()	;
	virtual void Update();
	virtual void Render();
	virtual void UI_Render();
	virtual void Destroy();
public:
	CTest();
	virtual ~CTest();
};

