#pragma once
#include "CScene.h"
class CLoading :
	public CScene
{
public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void UI_Render();
	virtual void Destroy();
public:
	CLoading();
	virtual ~CLoading();
};

