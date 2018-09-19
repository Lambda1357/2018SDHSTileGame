#pragma once
#include "CState.h"

template <class entity_type> class CState;

class CTelegram;

template <class entity_type>
class CStateMachine
{
private:

	entity_type * m_pOwner; // ���� �ӽ� ���� ��ü ������


	CState<entity_type> * m_pCurrentState;	// ���� ����

	CState<entity_type> * m_pPreviousState;	// ���� �־��� ������ ������ ���

	CState<entity_type> * m_pGlobalState;	// �� ���´� FSM�� ���ŵ� ������ ȣ��



public:

	CStateMachine(entity_type* Owner)
		:	m_pOwner		(Owner),
			m_pCurrentState	(nullptr),
			m_pPreviousState(nullptr),
			m_pGlobalState	(nullptr) {}

	virtual ~CStateMachine() {}

public:

	// FSM �� �ʱ�ȭ�ϴµ� ���� �޼ҵ���� ����Ѵ�.

	void SetCurrentState	(CState<entity_type>* state)
	{
		m_pCurrentState = state;
	}
	void SetPreviousState	(CState<entity_type>* state)
	{
		m_pPreviousState = state;
	}
	void SetGlobalState		(CState<entity_type>* state)
	{
		m_pGlobalState = state;
	}

public:

	void Update() const 
	{
		// ���� ���� ( GlobalState ) �� �����ϸ� ���� ������ Execute�� ȣ���Ѵ�.
		if (m_pGlobalState)
			m_pGlobalState->Execute(m_pOwner);

		// ���� ������ Execute ȣ��
		if (m_pCurrentState)
			m_pCurrentState->Execute(m_pOwner);
	}

public:

	void ChangeState(CState<entity_type> *pNewState) {
		// nullptr �˻�
		assert(pNewState && "<StateMachine::ChangeState> trying to change to a null change");

		// ���� ���¸� previous�� ���
		if (m_pCurrentState)
			m_pPreviousState = m_pCurrentState;

		// ���� ������ Exit �޼ҵ� ȣ��
		if (m_pCurrentState)
			m_pCurrentState->Exit(m_pOwner);

		// ���¸� ���ο� ���·� ��ȯ��Ű��
		// Enter �޼ҵ带 ȣ���Ѵ�.
		m_pCurrentState = pNewState;
		m_pCurrentState->Enter(m_pOwner);
	}

	// ����� �ξ��� ���� ���·� ����
	void RevertToPreviousState() {
		ChangeState(m_pPreviousState);
	}

public:

	CState<entity_type>* GetCurrentState	()	const { return m_pCurrentState;		}
	CState<entity_type>* GetPreviousState	()	const { return m_pPreviousState;	}
	CState<entity_type>* GetGlobalState		()	const { return m_pGlobalState;		}

	// ���ڷ� ���� ���İ� ���� ���°� ������ �˻��ϴ� �޼ҵ�
	bool IsInState(const CState<entity_type> &state) const
	{
		return ( typeid(state) == typeid(*m_pCurrentState) );
	}

public:

	// �޽��� ó����
	virtual bool HandleMessage(const CTelegram& msg)
	{
		// �켱 ���� ���°� ��ȿ���� , �޽����� ó���� �� �ִ����� �˻��Ѵ�.
		if (m_pCurrentState && m_pCurrentState->OnMessage(m_pOwner, msg))
		{
			return true;
		}

		// ó���Ҽ� ���� ���� ���°� �ִٸ� , �޽����� ���� ���·� �����Ѵ�.
		if (m_pGlobalState && m_pGlobalState->OnMessage(m_pOwner, msg))
		{
			return true;
		}


		// ó�� ����
		return false;
	}
};

