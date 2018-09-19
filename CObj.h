#pragma once

class CObj
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

public:

	virtual bool HandleMessage(const CTelegram& msg);
	bool		 HandleBasicMessage(const CTelegram& msg);

public:

	static bool Compare(CObj* pDest, CObj* pSour)
	{
		return (pDest->m_tInfo.vPos.z < pSour->m_tInfo.vPos.z);
	}
};

