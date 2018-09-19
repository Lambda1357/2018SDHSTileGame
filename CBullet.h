#pragma once
#include "CObj.h"
class CBullet :
	public CObj
{
private:

	D3DXVECTOR3 m_vGoVector;
	float		m_fSpeed;
	float		m_fRot;

public:
	CBullet(const D3DXVECTOR3& _startPos, const D3DXVECTOR3& vGovec, float fSpeed = 1.0f);
	virtual ~CBullet();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;
};

