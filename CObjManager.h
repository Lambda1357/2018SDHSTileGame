#pragma once
#include "Singleton.h"

class CObj;

class CObjManager :
	public CSingleton<CObjManager>
{
private:

	std::map<int, std::list<CObj*>*> m_MapObjs;
	std::list<CObj*> m_UIList;

public:

	CObjManager();
	virtual ~CObjManager();

public:

	CObj * GetEntityFromID(const string &entity_id);
	CObj * AddEntity(int key, CObj* entity_ptr);
	CObj * AddUIEntity(CObj* entity_ptr);

	list<CObj*>* GetEntityList(int key);

public:

	void Update();
	void Render();
	void UI_Render();
	void Destroy();

public:

	void ListClear(int key);
	void ResetLists();
};

#define OBJMANAGER CObjManager::GetInstance()
