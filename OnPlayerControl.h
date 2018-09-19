#pragma once
#include "CState.h"

class CPlayer;

class OnPlayerControl :
	public CState<CPlayer>
{
public:
	OnPlayerControl();
	virtual ~OnPlayerControl();

public:

	virtual void Enter(CPlayer*) override; // 현 상태 진입 호출 메소드
	virtual void Execute(CPlayer*) override; // 현 상태 지속 호출 메소드
	virtual void Exit(CPlayer*) override; // 상태 탈출 호출 메소드

	static CState<CPlayer>* GetInstance()
	{
		static OnPlayerControl instance;
		return &instance;
	}

public:

	// 메시지 처리기
	virtual bool OnMessage(CPlayer*, const CTelegram&) override;
};

