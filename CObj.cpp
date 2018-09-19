#include "DXUT.h"
#include "CObj.h"

#include "CTelegram.h"

bool CObj::HandleMessage(const CTelegram & msg)
{
	return HandleBasicMessage(msg);
}

bool CObj::HandleBasicMessage(const CTelegram & msg)
{
	// 기본적인 메시지를 처리하는 구문.
	// Enum : MessageType 타입만 처리해야 한다.

	bool result = false;

	switch (msg.Msg) {

		// ExtraInfo 만큼 추가로 이동함.
	case E_MSG_MOVEPOS:

		if (msg.ExtraInfo)
		{
			m_tInfo.vPos += *(D3DXVECTOR3*)msg.ExtraInfo;
		}

		result = true; break;

		// ExtraInfo 로 위치를 이동함.
	case E_MSG_SETPOS:

		if (msg.ExtraInfo)
		{
			m_tInfo.vPos = *(D3DXVECTOR3*)msg.ExtraInfo;
		}

		result = true; break;

	default:
		
		DEBUG_LOG(typeid(this).name() << " (" << m_tInfo.sID << ") : 의 객체엔 (" << msg.Msg << ") 메시지의 처리기가 없습니다.");

		result = false; break;
	}

	if (msg.ExtraInfo)
		delete msg.ExtraInfo;

	return result;
}