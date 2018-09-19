#pragma once
#include "CGun.h"
class CRevolver :
	public CGun
{
public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();
public:
	CRevolver(D3DXVECTOR3 &_targetPos);
	virtual ~CRevolver();

public:

	virtual bool HandleMessage(const CTelegram& msg);
};

