#include "DXUT.h"
#include "CImageManager.h"
#include "CSingleSprite.h"
#include "CMultiSprite.h"

CImageManager::CImageManager()
{
	D3DXCreateSprite(g_Device, &m_pSprite);
}


CImageManager::~CImageManager()
{
	for (auto iter : m_MapTexture)
	{
		SAFE_DELETE(iter.second);
	}

	m_MapTexture.clear();

	SAFE_RELEASE(m_pSprite);
}

void CImageManager::AddImage(const string& Key, const TCHAR* path, int iCnt)
{
	auto iter = m_MapTexture.find(Key);

	if (iter == m_MapTexture.end())
	{
		CSprite* pSprite;

		if (iCnt == 0)
			pSprite = new CSingleSprite;
		else
			pSprite = new CMultiSprite;

		m_MapTexture.insert(make_pair(Key, pSprite->AddImage(path, iCnt)));
	}
}

CSprite* CImageManager::FindImage(const string& Key, int iCnt)
{
	auto iter = m_MapTexture.find(Key);

	if (iter != m_MapTexture.end())
	{
		return iter->second->GetImage(iCnt);
	}

	else
		return nullptr;
}

void CImageManager::Render(CSprite* pTexture, const D3DXVECTOR3& m_Info,
	float fRot, D3DCOLOR m_Color)
{
	D3DXMATRIXA16 mat;
	D3DXVECTOR3 vCenter = D3DXVECTOR3(pTexture->m_Info.Width / 2, pTexture->m_Info.Height / 2, 0);
	D3DXMatrixAffineTransformation2D(&mat, 1.f, nullptr, D3DXToRadian(fRot), &D3DXVECTOR2(m_Info.x, m_Info.y));
	m_pSprite->SetTransform(&mat);
	m_pSprite->Draw(pTexture->m_pTex, nullptr, &vCenter, nullptr, m_Color);
}

void CImageManager::ScaleRender(CSprite* pTexture, const D3DXVECTOR3& m_Info,
	float fScale, float m_fRot)
{

	//D3DXMatrixAffineTransformation2D(&mat, fScale, nullptr, 0.f, &D3DXVECTOR2(m_Info.x, m_Info.y));
	
	D3DXMATRIX mat;
	D3DXMATRIX matScale, matTrans, matRot;
	D3DXVECTOR3 vCenter = D3DXVECTOR3(pTexture->m_Info.Width / 2, pTexture->m_Info.Height / 2, 0);
	D3DXMatrixRotationZ(&matRot, D3DXToRadian(m_fRot));
	D3DXMatrixTranslation(&matTrans, m_Info.x, m_Info.y, 0);
	D3DXMatrixScaling(&matScale, -1, 1, 1);

	mat = matScale * matRot * matTrans;

	m_pSprite->SetTransform(&mat);
	m_pSprite->Draw(pTexture->m_pTex, nullptr, &vCenter, nullptr, D3DCOLOR_XRGB(255, 255, 255));
}

void CImageManager::CenterRender(CSprite* pTexture, const D3DXVECTOR3& m_Info,
	const D3DXVECTOR3& vCenter, float fRot)
{
	D3DXMATRIXA16 mat;
	D3DXMatrixAffineTransformation2D(&mat, 1.f, nullptr, D3DXToRadian(fRot), &D3DXVECTOR2(m_Info.x, m_Info.y));
	m_pSprite->SetTransform(&mat);
	m_pSprite->Draw(pTexture->m_pTex, nullptr, &vCenter, nullptr, D3DCOLOR_XRGB(255,255,255));
}

void CImageManager::RenderText(const D3DXVECTOR3& vPos, const TCHAR* str)
{

}

void CImageManager::Lost()
{
	m_pSprite->OnLostDevice();
}

void CImageManager::Reset()
{
	m_pSprite->OnResetDevice();
}

void CImageManager::Render_Begin(bool bInterface)
{
	if (bInterface)
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	else
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
}

void CImageManager::Render_End()
{
	m_pSprite->End();
}