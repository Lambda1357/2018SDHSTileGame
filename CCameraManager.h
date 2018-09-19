#pragma once
#include "Singleton.h"
class CCameraManager :
	public CSingleton<CCameraManager>
{
public:
	CCameraManager();
	~CCameraManager();

private:
	D3DXMATRIX m_matProj, m_matView;

	D3DXVECTOR2 m_vCameraPos;
	D3DXVECTOR2 m_vViewSize;

	D3DXVECTOR3 m_vScale;
	D3DXVECTOR3 m_vTarget;

	CObj* m_pFollowObj;
	bool m_bFollowActive;

	float m_fAngle;

	void Init();
	void Release();

public:

	void SetTransform();

	void SetFollowObj(CObj* pFollow);
	void MoveCamera(const D3DXVECTOR2& vPlusPos);
	void SetCamera(const D3DXVECTOR2& vSetPos);

	D3DXVECTOR2& GetCameraPos() { return m_vCameraPos; }
	D3DXVECTOR3& GetCameraScale() { return m_vScale; }

	float GetCameraAngle() { return m_fAngle; }

	void Update();
};

#define CAMERAMANAGER CCameraManager::GetInstance()