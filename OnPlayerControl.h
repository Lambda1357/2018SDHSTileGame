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

	virtual void Enter(CPlayer*) override; // �� ���� ���� ȣ�� �޼ҵ�
	virtual void Execute(CPlayer*) override; // �� ���� ���� ȣ�� �޼ҵ�
	virtual void Exit(CPlayer*) override; // ���� Ż�� ȣ�� �޼ҵ�

	static CState<CPlayer>* GetInstance()
	{
		static OnPlayerControl instance;
		return &instance;
	}

public:

	// �޽��� ó����
	virtual bool OnMessage(CPlayer*, const CTelegram&) override;
};

