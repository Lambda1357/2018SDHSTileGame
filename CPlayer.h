#pragma once
#include "CObj.h"

class CGun;

template <class entity_type>
class CStateMachine;

class CPlayer :
	public CObj
{
private:
	CGun * m_pGun;
	CStateMachine<CPlayer>* m_pStateMachine;

	bool bFlip;
public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();
public:
	CPlayer();
	virtual ~CPlayer();

public:

	CStateMachine<CPlayer>* GetFSM() { return m_pStateMachine; }

public:
	// �޽��� ó�� �Լ�
	virtual bool HandleMessage(const CTelegram& msg);
};

