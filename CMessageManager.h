#pragma once
#include "Singleton.h"

class CTelegram;
class CObj;

class CMessageManager :
	public CSingleton<CMessageManager>
{
private:

	// std::set은 자동 정렬 & 중복 회피 특성을 가진 자료구조
	// 지연된 메시지 ( 0 이상의 지연 시간 ) 를 담는 용도로 사용됨
	std::set<CTelegram> PriorityQ;

	// 메시지를 대상인 Receiver에게 전송한다.
	void Discharge(CObj* pReceiver, const CTelegram& msg);

	// 지연된 모든 메시지를 발송한다.
	void DispatchDelayedMessages();

public:
	CMessageManager();
	virtual ~CMessageManager();

	// 지정된 대상에게 메시지를 보냅니다.
	void DispatchMsg(DWORD delay,	// 지연 시간
		const string& sender,		// 발신자
		const string& receiver,		// 수신자
		MessageType msg,			// 메시지 ( Enum : MessageType에 정의된 타입만 수,발신 가능 )
		void *extraInfo = nullptr);	// 추가적인 전송 정보  ex) 이동하는 메시지의 이동 거리 등.. 

	void Update() { DispatchDelayedMessages(); }
};

#define MESSAGEMANAGER CMessageManager::GetInstance()
