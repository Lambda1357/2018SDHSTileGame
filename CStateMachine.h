#pragma once
#include "CState.h"

template <class entity_type> class CState;

class CTelegram;

template <class entity_type>
class CStateMachine
{
private:

	entity_type * m_pOwner; // 상태 머신 소유 객체 포인터


	CState<entity_type> * m_pCurrentState;	// 현재 상태

	CState<entity_type> * m_pPreviousState;	// 속해 있었던 마지막 상태의 기록

	CState<entity_type> * m_pGlobalState;	// 이 상태는 FSM이 갱신될 때마다 호출



public:

	CStateMachine(entity_type* Owner)
		:	m_pOwner		(Owner),
			m_pCurrentState	(nullptr),
			m_pPreviousState(nullptr),
			m_pGlobalState	(nullptr) {}

	virtual ~CStateMachine() {}

public:

	// FSM 를 초기화하는데 다음 메소드들을 사용한다.

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
		// 전역 상태 ( GlobalState ) 가 존재하면 전역 상태의 Execute를 호출한다.
		if (m_pGlobalState)
			m_pGlobalState->Execute(m_pOwner);

		// 현재 상태의 Execute 호출
		if (m_pCurrentState)
			m_pCurrentState->Execute(m_pOwner);
	}

public:

	void ChangeState(CState<entity_type> *pNewState) {
		// nullptr 검사
		assert(pNewState && "<StateMachine::ChangeState> trying to change to a null change");

		// 이전 상태를 previous에 기록
		if (m_pCurrentState)
			m_pPreviousState = m_pCurrentState;

		// 기존 상태의 Exit 메소드 호출
		if (m_pCurrentState)
			m_pCurrentState->Exit(m_pOwner);

		// 상태를 새로운 상태로 변환시키고
		// Enter 메소드를 호출한다.
		m_pCurrentState = pNewState;
		m_pCurrentState->Enter(m_pOwner);
	}

	// 기억해 두었던 이전 상태로 복구
	void RevertToPreviousState() {
		ChangeState(m_pPreviousState);
	}

public:

	CState<entity_type>* GetCurrentState	()	const { return m_pCurrentState;		}
	CState<entity_type>* GetPreviousState	()	const { return m_pPreviousState;	}
	CState<entity_type>* GetGlobalState		()	const { return m_pGlobalState;		}

	// 인자로 받은 형식과 현재 상태가 같은지 검사하는 메소드
	bool IsInState(const CState<entity_type> &state) const
	{
		return ( typeid(state) == typeid(*m_pCurrentState) );
	}

public:

	// 메시지 처리기
	virtual bool HandleMessage(const CTelegram& msg)
	{
		// 우선 현재 상태가 유효한지 , 메시지를 처리할 수 있는지를 검사한다.
		if (m_pCurrentState && m_pCurrentState->OnMessage(m_pOwner, msg))
		{
			return true;
		}

		// 처리할수 없고 전역 상태가 있다면 , 메시지를 전역 상태로 전송한다.
		if (m_pGlobalState && m_pGlobalState->OnMessage(m_pOwner, msg))
		{
			return true;
		}


		// 처리 실패
		return false;
	}
};

