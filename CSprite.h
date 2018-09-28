#pragma once
typedef class CSprite
{
public:
	LPDIRECT3DTEXTURE9 m_pTex;
	D3DXIMAGE_INFO m_Info;
public:
	virtual CSprite* AddImage(const TCHAR* path, int iCnt = 0) PURE;
	virtual CSprite* GetImage(int iCnt = 0) PURE;
public:
	CSprite();
	virtual ~CSprite();

public:

	CSprite * operator [] (int index) { return GetImage(index); }
} *LPSPRITE;

