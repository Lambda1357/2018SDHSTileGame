#include "DXUT.h"
#include "CObjManager.h"

#include "CObj.h"

CObjManager::CObjManager()
{
	// 엔티티 타입을 추가한다.

	m_MapObjs.insert(make_pair(E_TYPE_OBJ, new list<CObj*>));
}


CObjManager::~CObjManager()
{
	Destroy();
}

CObj * CObjManager::GetEntityFromID(const string & entity_id)
{
	// 엔티티의 ID로 검색해
	// 포인터를 반환한다.

	for (auto iter : m_MapObjs) {
		for (auto iter2 : *iter.second) {
			if (iter2->GetInfo().sID == entity_id) {
				return iter2;
			}
		}
	}

	return nullptr;
}

CObj * CObjManager::AddEntity(int key, CObj * entity_ptr)
{
	auto find = m_MapObjs.find(key);

	if (find == m_MapObjs.end())
		return nullptr;

	find->second->push_back(entity_ptr);
	entity_ptr->Init();

	return entity_ptr;
}

CObj * CObjManager::AddUIEntity(CObj * entity_ptr)
{
	m_UIList.push_back(entity_ptr);
	entity_ptr->Init();

	return  entity_ptr;
}

list<CObj*>* CObjManager::GetEntityList(int key)
{
	auto find = m_MapObjs.find(key);

	if (find == m_MapObjs.end())
		return nullptr;

	return find->second;
}

void CObjManager::Update()
{
	for (auto iter : m_MapObjs)
	{
		for (auto iter2 : *iter.second)
		{
			iter2->Update();
		}
	}
	for (auto iter : m_UIList)
		iter->Update();
}

void CObjManager::Render()
{
	std::list<CObj*> listData;

	for (auto iter : m_MapObjs)
	{
		for (auto iter2 : *iter.second)
		{
			listData.emplace_back(iter2);
		}
	}

	listData.sort(CObj::CompareZ);
	listData.sort(CObj::CompareY);

	for (auto iter : listData)
		iter->Render();
}

void CObjManager::UI_Render()
{
	for (auto iter : m_UIList)
	{
		iter->Render();
	}
}

void CObjManager::Destroy()
{
	for (auto iter : m_MapObjs)
	{
		for (auto iter2 : *iter.second)
		{
			if (iter2)
			{
				iter2->Destroy();
				delete iter2;
				iter2 = nullptr;
			}
		}
		delete iter.second;
		iter.second = nullptr;
	}

	for(auto iter : m_UIList)
		if (iter) { iter->Destroy(); delete iter; iter = nullptr; }

	m_MapObjs.clear();
	m_UIList.clear();
}

void CObjManager::ListClear(int key)
{
	auto find = m_MapObjs.find(key);

	if (find == m_MapObjs.end())
		return;

	for (auto iter : *find->second) {
		if (iter)
		{
			iter->Destroy();
			delete iter;
		}
	}
}

void CObjManager::ResetLists()
{
	for (auto iter : m_MapObjs)
	{
		for (auto iter2 : *iter.second)
		{
			if (iter2)
			{
				iter2->Destroy();
				delete iter2;
			}
		}
	}
	for (auto iter : m_UIList)
		if (iter) { iter->Destroy(); delete iter; }
}
