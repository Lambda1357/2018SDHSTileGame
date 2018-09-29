#include "DXUT.h"
#include "CRevolver.h"

#include "CTelegram.h"
#include "CBullet.h"

CRevolver::CRevolver( D3DXVECTOR3 &_targetPos)
	:CGun(_targetPos)
{
	m_tInfo.vPos = _targetPos;
}


CRevolver::~CRevolver()
{
}

bool CRevolver::HandleMessage(const CTelegram & msg)
{
	bool result = false;

	switch (msg.Msg) {

	case E_MSG_SHOOT:

		if (msg.ExtraInfo)
		{

			D3DXVECTOR3 curVec = *(D3DXVECTOR3*)msg.ExtraInfo;

			//DEBUG_LOG("Shoot : " << curVec.x << " : ");
			//DEBUG_LOG(curVec.y << " : " << curVec.z);

			OBJMANAGER->AddEntity(0, new CBullet(m_tInfo.vPos,curVec, 750.0f));

			result = true; break;
		}
		else break;

	default:
		return HandleBasicMessage(msg);
	}

	if (msg.ExtraInfo)
		delete msg.ExtraInfo;

	return result;
}


void CRevolver::Init()
{
	m_pSprite = IMAGEMANAGER->FindImage("GUN");
}

void CRevolver::Update()
{
}

void CRevolver::Render()
{
	m_tInfo.vPos = D3DXVECTOR3(20, 20, 0) + m_targetPos;

	if (bFlip)
	{
		m_fRot += 180;
		IMAGEMANAGER->ScaleRender(m_pSprite, m_tInfo.vPos, 1.f, m_fRot);
	}
	else
		IMAGEMANAGER->Render(m_pSprite, m_tInfo.vPos, m_fRot);
}

void CRevolver::Destroy()
{
	
}