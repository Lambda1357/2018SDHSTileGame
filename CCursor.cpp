#include "DXUT.h"
#include "CCursor.h"


CCursor::CCursor()
{
}


CCursor::~CCursor()
{
}

void CCursor::Init()
{
	::ShowCursor(FALSE);
	m_pSprite = IMAGEMANAGER->FindImage("CURSOR");
}

void CCursor::Update()
{

}

void CCursor::Render()
{
	D3DXVECTOR3 &vMousePos = INPUTMANAGER->GetvScreenMousePos();
	IMAGEMANAGER->Render(m_pSprite, vMousePos);
}

void CCursor::Destroy()
{
}
