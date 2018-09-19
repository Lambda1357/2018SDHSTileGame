#pragma once

template <class entity_type>
class CState abstract
{
private:

public:
	CState() {}
	virtual ~CState() {}

	virtual void Enter	(entity_type*) PURE; // 현 상태 진입 호출 메소드
	virtual void Execute(entity_type*) PURE; // 현 상태 지속 호출 메소드
	virtual void Exit	(entity_type*) PURE; // 상태 탈출 호출 메소드

public:

	// 메시지 처리기
	virtual bool OnMessage(entity_type*, const CTelegram&) PURE;
};