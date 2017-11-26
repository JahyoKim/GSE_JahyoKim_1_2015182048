#include "stdafx.h"
#include "Object.h"
#include <random>


Object::Object()
{
	memset(&m_Position,0,sizeof(m_Position));
	memset(&m_Size, 0, sizeof(m_Size));
	memset(&m_Color, 0, sizeof(m_Color));

	m_dirX = (rand() % 20 * 0.1) - 1;
	m_dirY = (rand() % 20 * 0.1) - 1;

	// m_Position.x = (float)(rand() % 500 - 250);
	// m_Position.y = (float)(rand() % 500 - 250);
	// m_Position.z = 0.0;
	// 
	// m_Size.s = 10.0;
	// 
	// m_Color.r = 1.0;
	// m_Color.g = 1.0;
	// m_Color.b = 1.0;
	// m_Color.a = 1.0;
}

Object::~Object()
{

}

void Object::update(float elapsedTime)
{
	float ElapsedPerSecond = elapsedTime / 1000.f;

	m_Position.x += m_dirX * 100 * ElapsedPerSecond;
	m_Position.y += m_dirY * 100 * ElapsedPerSecond;
	m_Position.z = 0.0;

	if (m_Position.x > 250) { m_dirX = -m_dirX; }
	if (m_Position.x < -250) { m_dirX = -m_dirX; }
	if (m_Position.y > 250) { m_dirY = -m_dirY; }
	if (m_Position.y < -250) { m_dirY = -m_dirY; }

}


