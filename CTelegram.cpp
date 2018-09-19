#include "DXUT.h"
#include "CTelegram.h"


CTelegram::CTelegram(const string& sender, const string& receiver, MessageType msg, void * extraInfo, DWORD delay)
	:	Sender		(sender),
		Receiver	(receiver),
		Msg			(msg),
		ExtraInfo	(extraInfo),
		DispatchTime(delay + timeGetTime())
{
	
}

CTelegram::~CTelegram()
{
}
