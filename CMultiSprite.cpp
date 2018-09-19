#include "DXUT.h"
#include "CMultiSprite.h"
#include "CSingleSprite.h"


CMultiSprite::CMultiSprite()
{
}


CMultiSprite::~CMultiSprite()
{
	for (auto iter : m_vecTexture)
	{
		SAFE_DELETE(iter);
	}

	m_vecTexture.clear();
}

CSprite* CMultiSprite::AddImage(const TCHAR* path, int iCnt)
{
	TCHAR sz[128] = L"";

	for (int i = 1; i <= iCnt; i++)
	{
		wsprintf(sz, path, i);

		CSprite* pTexture = new CSingleSprite;
		pTexture->AddImage(sz);
		m_vecTexture.push_back(pTexture);
	}

	return this;
}

CSprite* CMultiSprite::GetImage(int iCnt)
{
	if (iCnt == -1)
		return this;

	else
		return m_vecTexture[iCnt];
}