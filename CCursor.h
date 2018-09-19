#pragma once
#include "CObj.h"

class CCursor : public CObj
{
private:
	CSprite * m_pSprite;
public:
	void Init();
	void Update();
	void Render();
	void Destroy();
public:
	CCursor();
	virtual ~CCursor();
};

