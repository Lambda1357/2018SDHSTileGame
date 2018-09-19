#pragma once
#include "CObj.h"

class CGun :
	public CObj
{
protected:
	bool bFlip;
	float m_fRot;

	const D3DXVECTOR3 &m_targetPos;
public:
	inline void SetRot(float _fRot) { m_fRot = _fRot; }
	inline void SetFlip(bool _Flip) { bFlip = _Flip; }
public: 
	virtual void Init()    PURE;
	virtual void Update()  PURE;
	virtual void Render()  PURE;
	virtual void Destroy() PURE;
public:
	CGun(D3DXVECTOR3 &_targetPos) : m_targetPos(_targetPos) {}
	virtual ~CGun();
};

