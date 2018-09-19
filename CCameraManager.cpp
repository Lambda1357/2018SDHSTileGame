#include "DXUT.h"
#include "CCameraManager.h"

#include "CObj.h"

CCameraManager::CCameraManager()
{
	Init();
}


CCameraManager::~CCameraManager()
{
	Release();
}

void CCameraManager::Init()
{
	m_vCameraPos = D3DXVECTOR2(0, 0);
	m_vViewSize = D3DXVECTOR2((float)WINSIZEX, (float)WINSIZEY);
	m_vScale = D3DXVECTOR3(1, 1, 1);

	m_fAngle = 0.0f;

	D3DXMatrixOrthoLH(&m_matProj, m_vViewSize.x, -m_vViewSize.y, 0, 1);

	m_pFollowObj = nullptr;
	m_bFollowActive = false;
}

void CCameraManager::Release()
{
}

void CCameraManager::SetTransform()
{
	DXUTGetD3D9Device()->SetTransform(D3DTS_VIEW, &m_matView);
	DXUTGetD3D9Device()->SetTransform(D3DTS_PROJECTION, &m_matProj);
}

void CCameraManager::SetFollowObj(CObj * pFollow)
{
	m_pFollowObj = pFollow;

	if (m_pFollowObj) 
		m_bFollowActive = true;
	else
		m_bFollowActive = false;
}

void CCameraManager::MoveCamera(const D3DXVECTOR2 & vPlusPos)
{
	m_vCameraPos += vPlusPos;
}

void CCameraManager::SetCamera(const D3DXVECTOR2 & vSetPos)
{
	m_vCameraPos = vSetPos;
}

void CCameraManager::Update()
{
	if (m_bFollowActive)
	{
		utility::lerp<D3DXVECTOR2>(&m_vCameraPos, m_vCameraPos, D3DXVECTOR2(m_pFollowObj->GetInfo().vPos), 0.08f);
	}

	this->m_matView = D3DXMATRIX(
		m_vScale.x * cosf(m_fAngle), m_vScale.x * sin(m_fAngle), 0, 0,
		-m_vScale.y * sin(m_fAngle), m_vScale.y * cos(m_fAngle), 0, 0,
		0, 0, m_vScale.z, 0,
		-m_vCameraPos.x * m_vScale.y * cos(m_fAngle) + m_vCameraPos.y * m_vScale.y * sin(m_fAngle),
		-m_vCameraPos.x * m_vScale.x * sin(m_fAngle) - m_vCameraPos.y * m_vScale.y * cos(m_fAngle), 0, 1);
}
