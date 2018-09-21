#include "DXUT.h"
#include "CPlayer.h"
#include "CRevolver.h"

#include "CTelegram.h"
#include "CStateMachine.h"
#include "CSprite.h"

// 플레이어 객체의 상태들

#include "OnPlayerControl.h"

//


CPlayer::CPlayer()
{
	m_tInfo.vPos = D3DXVECTOR3(0, 0, 0);
}


CPlayer::~CPlayer()
{
	Destroy();
}

bool CPlayer::HandleMessage(const CTelegram & msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

void CPlayer::Init()
{
	m_pSprite = IMAGEMANAGER->FindImage("PLAYER");
	SetID("Player");

	m_pGun = (CGun*)OBJMANAGER->AddEntity(0, new CRevolver(this->m_tInfo.vPos));
	m_pStateMachine = new CStateMachine<CPlayer>(this);
	m_pGun->SetID("Revolver");

	bFlip = false;
	m_pStateMachine->ChangeState(OnPlayerControl::GetInstance());
}

void CPlayer::Update()
{
	float fRot;
	D3DXVECTOR3 vDir = INPUTMANAGER->GetvScrollMousePos() - m_tInfo.vPos;
	fRot = D3DXToDegree(atan2f(vDir.y, vDir.x));

	m_pGun->SetRot(fRot);

	vDir.x >= 0 ? bFlip = false : bFlip = true;
	m_pGun->SetFlip(bFlip);

	m_pStateMachine->Update();
}

void CPlayer::Render()
{
	if(bFlip)
		IMAGEMANAGER->ScaleRender(m_pSprite, m_tInfo.vPos, -1);
	else
		IMAGEMANAGER->Render(m_pSprite, m_tInfo.vPos);
}

void CPlayer::Destroy()
{
	SAFE_DELETE(m_pStateMachine);
}
