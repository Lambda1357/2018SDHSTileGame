#include "DXUT.h"
#include "CSceneManager.h"
#include "CLoading.h"
#include "CTest.h"


CSceneManager::CSceneManager() 
	: m_curScene(nullptr), m_nextScene(nullptr)
{
	AddScene("LOADING", new CLoading);
	AddScene("TEST", new CTest);
	ChangeScene("LOADING");
}


CSceneManager::~CSceneManager()
{
	Destroy();
}

void CSceneManager::AddScene(string str, CScene* pScene)
{
	auto iter = m_mapScene.find(str);

	if (iter == m_mapScene.end())
	{
		m_mapScene.insert(make_pair(str, pScene));
	}
}

void CSceneManager::ChangeScene(string str)
{
	auto iter = m_mapScene.find(str);

	if (iter != m_mapScene.end())
	{
		m_nextScene = iter->second;
	}
}

void CSceneManager::Update()
{
	if (m_nextScene)
	{
		if (m_curScene)
			m_curScene->Destroy();

		m_curScene = m_nextScene;
		m_curScene->Init();
		m_nextScene = nullptr;
	}

	if(m_curScene)
		m_curScene->Update();
}

void CSceneManager::Render()
{
	if (m_curScene)
		m_curScene->Render();
}

void CSceneManager::UI_Render()
{
	if (m_curScene)
		m_curScene->UI_Render();
}

void CSceneManager::Destroy()
{
	for (auto& iter : m_mapScene)
	{
		SAFE_DELETE(iter.second);
	}

	m_mapScene.clear();
}