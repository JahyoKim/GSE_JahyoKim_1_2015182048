#include "stdafx.h"
#include "SceneMgr.h"



SceneMgr::SceneMgr(int width, int height)
{
	m_renderer = new Renderer(width, height);

	//for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	//{
	//	m_objects[i] = new Object;
	//	m_objects[i]->SetPosition(rand()%500 - 250, rand() % 500 - 250, 0.0);
	//	m_objects[i]->SetSize(10.0);
	//	m_objects[i]->SetColor(1.0, 1.0, 1.0);
	//	m_objects[i]->update(100.0);
	//	
	//
	//}

	m_windowWidth = width;
	m_windowHeight = height;

	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		m_objects[i] = NULL;
	}

}
SceneMgr::~SceneMgr()
{
}

void SceneMgr::drawObject()
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{ 
		if (m_objects[i] != NULL)
		{
			m_renderer->DrawSolidRect(m_objects[i]->GetPosition().x, m_objects[i]->GetPosition().y,
				m_objects[i]->GetPosition().z, m_objects[i]->GetSize().s,
				m_objects[i]->GetColor().r, m_objects[i]->GetColor().g,
				m_objects[i]->GetColor().b, 1.0);
		}
	}
}

void SceneMgr::updateObject()
{

}

