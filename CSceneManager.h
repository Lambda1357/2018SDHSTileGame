#pragma once

class CScene;
class CSceneManager : public CSingleton<CSceneManager>
{
private:

	map<string, CScene*> m_mapScene;
	CScene* m_curScene;
	CScene* m_nextScene;

public:

	void AddScene(string str, CScene* pScene);
	void ChangeScene(string str);

	void Update();
	void Render();
	void UI_Render();
	void Destroy();

public:

	CSceneManager();
	~CSceneManager();

};

#define SCENEMANAGER CSceneManager::GetInstance()