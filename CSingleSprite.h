#pragma once
#include "CSprite.h"
class CSingleSprite :
	public CSprite
{
private:
	virtual CSprite* AddImage(const TCHAR* path, int iCnt = 0);
	virtual CSprite* GetImage(int iCnt = 0);
public:
	CSingleSprite();
	virtual ~CSingleSprite();
};

