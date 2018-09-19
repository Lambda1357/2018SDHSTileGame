#include "DXUT.h"
#include "CMessageManager.h"

#include "CTelegram.h"
#include "CObj.h"

CMessageManager::CMessageManager()
{
}


CMessageManager::~CMessageManager()
{
	for (auto iter : PriorityQ)
		SAFE_DELETE(iter.ExtraInfo);

	if (PriorityQ.size() >= 0)
		PriorityQ.clear();
}


void CMessageManager::Discharge(CObj * pReceiver, const CTelegram & msg)
{
	if (pReceiver)
		pReceiver->HandleMessage(msg);
}


void CMessageManager::DispatchMsg(DWORD delay, const string& sender, const string& receiver, MessageType msg, void * extraInfo)
{
	CObj* pReceiver = OBJMANAGER->GetEntityFromID(receiver);

	CTelegram telegram(sender, receiver, msg, extraInfo);

	if (delay <= 0.f)
	{
		Discharge(pReceiver, telegram);
	}
	else
	{
		DWORD CurrentTime = timeGetTime();

		telegram.DispatchTime = CurrentTime + delay;

		// ť�� �����Ѵ�.
		PriorityQ.insert(telegram);
	}
}


void CMessageManager::DispatchDelayedMessages()
{
	DWORD CurrentTime = timeGetTime();

	for (auto &iter : PriorityQ) {
		if (iter.DispatchTime < CurrentTime &&
			iter.DispatchTime > 0)
		{
			CTelegram telegram = *PriorityQ.begin();

			// ������ �˻�
			CObj* pReceiver = OBJMANAGER->GetEntityFromID(telegram.Receiver);

			// �����ڿ��� ������ ������.
			Discharge(pReceiver, telegram);
			PriorityQ.erase(PriorityQ.begin());
			return;
		}
	}
}
