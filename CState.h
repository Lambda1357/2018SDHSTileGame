#pragma once

template <class entity_type>
class CState abstract
{
private:

public:
	CState() {}
	virtual ~CState() {}

	virtual void Enter	(entity_type*) PURE; // �� ���� ���� ȣ�� �޼ҵ�
	virtual void Execute(entity_type*) PURE; // �� ���� ���� ȣ�� �޼ҵ�
	virtual void Exit	(entity_type*) PURE; // ���� Ż�� ȣ�� �޼ҵ�

public:

	// �޽��� ó����
	virtual bool OnMessage(entity_type*, const CTelegram&) PURE;
};