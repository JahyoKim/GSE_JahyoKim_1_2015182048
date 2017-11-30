#include "stdafx.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr()
{
}

SceneMgr::SceneMgr(int width, int height)
{
	m_renderer = new Renderer(width, height);

	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		m_objects[i] = NULL;
	}
}
SceneMgr::~SceneMgr()
{
}

void SceneMgr::initObject(float x, float y)
{


	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		if (m_objects[i] == NULL) {
			m_objects[i] = new Object;
			m_objects[i]->SetPosition(x, y, 0.0);
			m_objects[i]->SetSize(10.0);
			m_objects[i]->SetColor(1.0, 1.0, 1.0);
			break;
		}
		
	}
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
				m_objects[i]->GetColor().b, 1.0, 0);
		}
	}
}

void SceneMgr::updateObject(float elapsedTime)
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		if (m_objects[i] != NULL)
		{
			m_objects[i]->update(elapsedTime);
		}
	}

}

void SceneMgr::collision()
{
	initColor();
	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		for (int j = i + 1; j < MAX_OBJECTS_COUNT; j++)
		{
			if (m_objects[i] != NULL && m_objects[j] != NULL)
			{
				float minX, minY, maxX, maxY;
				float minX1, minY1, maxX1, maxY1;

				minX = m_objects[i]->GetPosition().x - m_objects[i]->GetSize().s / 2.f;
				minY = m_objects[i]->GetPosition().y - m_objects[i]->GetSize().s / 2.f;
				maxX = m_objects[i]->GetPosition().x + m_objects[i]->GetSize().s / 2.f;
				maxY = m_objects[i]->GetPosition().y + m_objects[i]->GetSize().s / 2.f;
				minX1 = m_objects[j]->GetPosition().x - m_objects[i]->GetSize().s / 2.f;
				minY1 = m_objects[j]->GetPosition().y - m_objects[i]->GetSize().s / 2.f;
				maxX1 = m_objects[j]->GetPosition().x + m_objects[i]->GetSize().s / 2.f;
				maxY1 = m_objects[j]->GetPosition().y + m_objects[i]->GetSize().s / 2.f;

				if (AABBCollision(minX, minY, maxX, maxY, minX1, minY1, maxX1, maxY1)) {
					m_objects[i]->SetColor(1, 0, 0);
					m_objects[j]->SetColor(1, 0, 0);
				}
				


			}
		}
	}
	
}

void SceneMgr::initColor()
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		if (m_objects[i] != NULL)
		{
			m_objects[i]->SetColor(1, 1, 1);
		}
	}
}

bool SceneMgr::AABBCollision(float minX, float minY, float maxX, float maxY, float minX1, float minY1, float maxX1, float maxY1)
{
	if (minX > maxX1) return false;
	if (maxX < minX1) return false;
	if (minY > maxY1) return false;
	if (maxY < minY1) return false;

	return true;
}

