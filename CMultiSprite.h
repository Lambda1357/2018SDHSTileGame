#pragma once
#include "CSprite.h"
class CMultiSprite :
	public CSprite
{
private:
	vector<CSprite*> m_vecTexture;
public:
	virtual CSprite* AddImage(const TCHAR* path, int iCnt = 0);
	virtual CSprite* GetImage(int iCnt = 0);
public:
	CMultiSprite();
	virtual ~CMultiSprite();
};

