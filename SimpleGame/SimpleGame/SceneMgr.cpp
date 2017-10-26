#include "stdafx.h"
#include "SceneMgr.h"



SceneMgr::SceneMgr()
{
	m_renderer = new Renderer(500, 500);
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		m_objects[i] = new Object;
		m_objects[i]->SetPosition(rand()%500 - 250, rand() % 500 - 250, 0.0);
		m_objects[i]->SetSize(10.0);
		m_objects[i]->SetColor(1.0, 1.0, 1.0);
		m_objects[i]->SetMove(10.0f, 10.0f, 0.0f);
		

		// m_Position.x += m_Move.moveX;
		// m_Position.y += m_Move.moveY;
		// m_Position.z += m_Move.moveZ;
		

	}

	

}
SceneMgr::~SceneMgr()
{
	delete m_objects;
	delete m_renderer;
}

void SceneMgr::drawObject()
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{ 
		m_renderer->DrawSolidRect(m_objects[i]->GetPosition().x, m_objects[i]->GetPosition().y,
									m_objects[i]->GetPosition().z, m_objects[i]->GetSize().s, 
									m_objects[i]->GetColor().r, m_objects[i]->GetColor().g, 
									m_objects[i]->GetColor().b, 1.0);
	}
}

void SceneMgr::update()
{

}

