#include "DXUT.h"
#include "OnPlayerControl.h"

#include "CPlayer.h"

OnPlayerControl::OnPlayerControl()
{

}


OnPlayerControl::~OnPlayerControl()
{

}

void OnPlayerControl::Enter(CPlayer * pPlayer)
{

}

void OnPlayerControl::Execute(CPlayer *pPlayer)
{
	if (INPUTMANAGER->PUSH_KEY('D'))
		pPlayer->GetInfo().vPos.x += 500 * DXUTGetElapsedTime();

	if (INPUTMANAGER->PUSH_KEY('A'))
		pPlayer->GetInfo().vPos.x -= 500 * DXUTGetElapsedTime();

	if (INPUTMANAGER->PUSH_KEY('W'))
		pPlayer->GetInfo().vPos.y -= 500 * DXUTGetElapsedTime();

	if (INPUTMANAGER->PUSH_KEY('S'))
		pPlayer->GetInfo().vPos.y += 500 * DXUTGetElapsedTime();

	if (INPUTMANAGER->DOWN_KEY(VK_LBUTTON))
	{
		D3DXVECTOR3* curVec = new D3DXVECTOR3(0, 0, 0);
		*curVec = INPUTMANAGER->GetvScrollMousePos() - pPlayer->GetInfo().vPos;

		D3DXVec3Normalize(curVec, curVec);
		
		MESSAGEMANAGER->DispatchMsg(20, pPlayer->GetInfo().sID, "Revolver", E_MSG_SHOOT, (LPVOID)curVec);
	}

	//DEBUG_LOG(pPlayer->GetInfo().vPos.x << " " <<  pPlayer->GetInfo().vPos.y);
}

void OnPlayerControl::Exit(CPlayer *pPlayer)
{

}

bool OnPlayerControl::OnMessage(CPlayer *pPlayer, const CTelegram &msg)
{
	return pPlayer->HandleBasicMessage(msg);
}
