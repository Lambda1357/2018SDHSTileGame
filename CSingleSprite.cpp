#include "DXUT.h"
#include "CSingleSprite.h"


CSingleSprite::CSingleSprite()
{
}


CSingleSprite::~CSingleSprite()
{
	SAFE_RELEASE(m_pTex);
}

CSprite* CSingleSprite::AddImage(const TCHAR* path, int iCnt)
{
	D3DXGetImageInfoFromFile(path, &m_Info);
	D3DXCreateTextureFromFileEx(g_Device, path, m_Info.Width, m_Info.Height, m_Info.MipLevels, 0,
		m_Info.Format, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_ARGB(10, 10, 10, 10), &m_Info,
		NULL, &m_pTex);

	return this;
}

CSprite* CSingleSprite::GetImage(int iCnt)
{
	return this;
}