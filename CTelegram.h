#pragma once

class CObj;

class CTelegram
{
public:

	// ������ ������ ��ü
	string Sender;


	// ������ �޴� ��ü
	string Receiver;

	// �޽��� ��ü
	// ���������� ���� 
	MessageType Msg;

	// �޽����� ���� ���� �������ų�
	// ���� �ð���ŭ �����ȴ�.
	// ������ �ʿ��ϸ�, �ʿ��� ��ŭ �� �ʵ忡 ���� �ð��� �����Ѵ�. ( 0 ���ϴ� ��� �߼� )
	DWORD DispatchTime;

	// �߰����� ���� ����
	LPVOID ExtraInfo;

public:

	// ���ʺ���  �߼� ��ü Ű,  ���� ��� ��ü Ű,  �޽���,  �߰� ����,  ���� �ð� 
	CTelegram(const string& sender, const string& receiver, MessageType msg, void * extraInfo = NO_ADDITIONAL_INFO, DWORD delay = 0.f);
	virtual ~CTelegram();

	// Set �ڷ����� ����ϱ� ���� ������ �����ε�
	bool operator < (CTelegram tel) const { return DispatchTime < tel.DispatchTime; }
};