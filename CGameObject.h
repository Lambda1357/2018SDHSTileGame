#pragma once
#include "CObj.h"
class CGameObject abstract :
	public CObj
{
protected:
	RECT m_rcCol;
public:
	CGameObject();
	CGameObject(const string& id) { SetID(id); }
	virtual ~CGameObject();

	virtual void Init()    PURE;
	virtual void Update()  PURE;
	virtual void Render()  PURE;
	virtual void Destroy() PURE;

	virtual const RECT& GetCollider() override { return m_rcCol; }

	void AddVector(const D3DXVECTOR3& _plusV);
	void SetRectColToImg(const D3DXVECTOR3& _center);
};

