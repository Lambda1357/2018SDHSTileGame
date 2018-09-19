#include "DXUT.h"
#include "CObj.h"

#include "CTelegram.h"

bool CObj::HandleMessage(const CTelegram & msg)
{
	return HandleBasicMessage(msg);
}

bool CObj::HandleBasicMessage(const CTelegram & msg)
{
	// �⺻���� �޽����� ó���ϴ� ����.
	// Enum : MessageType Ÿ�Ը� ó���ؾ� �Ѵ�.

	bool result = false;

	switch (msg.Msg) {

		// ExtraInfo ��ŭ �߰��� �̵���.
	case E_MSG_MOVEPOS:

		if (msg.ExtraInfo)
		{
			m_tInfo.vPos += *(D3DXVECTOR3*)msg.ExtraInfo;
		}

		result = true; break;

		// ExtraInfo �� ��ġ�� �̵���.
	case E_MSG_SETPOS:

		if (msg.ExtraInfo)
		{
			m_tInfo.vPos = *(D3DXVECTOR3*)msg.ExtraInfo;
		}

		result = true; break;

	default:
		
		DEBUG_LOG(typeid(this).name() << " (" << m_tInfo.sID << ") : �� ��ü�� (" << msg.Msg << ") �޽����� ó���Ⱑ �����ϴ�.");

		result = false; break;
	}

	if (msg.ExtraInfo)
		delete msg.ExtraInfo;

	return result;
}