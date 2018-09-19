#pragma once
class CMainGame
{
public:
	void Init();
	void Update();
	void Render();
	void Destroy();

	void Lost();
	void Reset();
public:
	CMainGame();
	~CMainGame();
};

