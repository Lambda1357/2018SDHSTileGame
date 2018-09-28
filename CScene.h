#pragma once
typedef class CScene
{
public:
	virtual void Init()		PURE;
	virtual void Update()	PURE;
	virtual void Render()	PURE;
	virtual void UI_Render()PURE;
	virtual void Destroy()	PURE;
public:
	CScene();
	virtual ~CScene();
} *LPSCENE;

