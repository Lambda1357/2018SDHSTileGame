#pragma once
#include "Singleton.h"

class CTelegram;
class CObj;

class CMessageManager :
	public CSingleton<CMessageManager>
{
private:

	// std::set�� �ڵ� ���� & �ߺ� ȸ�� Ư���� ���� �ڷᱸ��
	// ������ �޽��� ( 0 �̻��� ���� �ð� ) �� ��� �뵵�� ����
	std::set<CTelegram> PriorityQ;

	// �޽����� ����� Receiver���� �����Ѵ�.
	void Discharge(CObj* pReceiver, const CTelegram& msg);

	// ������ ��� �޽����� �߼��Ѵ�.
	void DispatchDelayedMessages();

public:
	CMessageManager();
	virtual ~CMessageManager();

	// ������ ��󿡰� �޽����� �����ϴ�.
	void DispatchMsg(DWORD delay,	// ���� �ð�
		const string& sender,		// �߽���
		const string& receiver,		// ������
		MessageType msg,			// �޽��� ( Enum : MessageType�� ���ǵ� Ÿ�Ը� ��,�߽� ���� )
		void *extraInfo = nullptr);	// �߰����� ���� ����  ex) �̵��ϴ� �޽����� �̵� �Ÿ� ��.. 

	void Update() { DispatchDelayedMessages(); }
};

#define MESSAGEMANAGER CMessageManager::GetInstance()
