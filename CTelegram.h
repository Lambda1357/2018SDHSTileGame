#pragma once

class CObj;

class CTelegram
{
public:

	// 정보를 보내는 객체
	string Sender;


	// 정보를 받는 객체
	string Receiver;

	// 메시지 자체
	// 열거형으로 생성 
	MessageType Msg;

	// 메시지는 지금 당장 보내지거나
	// 일정 시간만큼 지연된다.
	// 지연이 필요하면, 필요한 만큼 이 필드에 지연 시간을 적용한다. ( 0 이하는 즉시 발송 )
	DWORD DispatchTime;

	// 추가적인 전송 정보
	LPVOID ExtraInfo;

public:

	// 왼쪽부터  발송 객체 키,  전송 대상 객체 키,  메시지,  추가 정보,  지연 시간 
	CTelegram(const string& sender, const string& receiver, MessageType msg, void * extraInfo = NO_ADDITIONAL_INFO, DWORD delay = 0.f);
	virtual ~CTelegram();

	// Set 자료형을 사용하기 위한 연산자 오버로딩
	bool operator < (CTelegram tel) const { return DispatchTime < tel.DispatchTime; }
};