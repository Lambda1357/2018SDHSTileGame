#pragma once

typedef class CObj
{
protected:
	INFO m_tInfo;
	CSprite* m_pSprite;
public:
	virtual void Init()    PURE;
	virtual void Update()  PURE;
	virtual void Render()  PURE;
	virtual void Destroy() PURE;
public:
	CObj() {}
	CObj(const string& id) { SetID(id); }
	virtual ~CObj() {}

public:

	void SetID(const string& id) { m_tInfo.sID = id; }
	INFO& GetInfo() { return m_tInfo; }
	CSprite* GetSprite() { return m_pSprite; }
	void SetSprite(CSprite* pSprite) { m_pSprite = pSprite; }

public:

	virtual bool HandleMessage(const CTelegram& msg);
	bool		 HandleBasicMessage(const CTelegram& msg);

public:

	virtual const RECT& GetCollider() { return {}; }

public:

	static bool CompareZ(CObj* pDest, CObj* pSour)
	{
		return (pDest->m_tInfo.vPos.z < pSour->m_tInfo.vPos.z);
	}

	static bool CompareY(CObj* pDest, CObj* pSour)
	{
		if (pDest->m_tInfo.vPos.z == pSour->m_tInfo.vPos.z)
			return pDest->m_tInfo.vPos.y < pSour->m_tInfo.vPos.y;
		else
			return false;
	}
} *LPOBJ;

