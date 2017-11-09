#include "stdafx.h"
#include "Object.h"
#include <random>


Object::Object()
{
	memset(&m_Position,0,sizeof(m_Position));
	memset(&m_Size, 0, sizeof(m_Size));
	memset(&m_Color, 0, sizeof(m_Color));

	m_velocity.vX = 20.0f * (float)(rand() % 100);
	m_velocity.vY = 20.0f * (float)(rand() % 100);
	m_velocity.vZ = 0.0;
}
Object::~Object()
{

}

void Object::update(float elapsedTime)
{
	float ElapsedPerSecond = elapsedTime / 1000.f;

	m_Position.x += m_velocity.vX * ElapsedPerSecond;
	m_Position.y += m_velocity.vY * ElapsedPerSecond;
	m_Position.z = 0.0;

	if (m_Position.x > 250) { m_velocity.vX = -m_velocity.vX; }
	if (m_Position.x < -250) { m_velocity.vX = -m_velocity.vX; }
	if (m_Position.y > 250) { m_velocity.vY = -m_velocity.vY; }
	if (m_Position.y < -250) { m_velocity.vY = -m_velocity.vY; }

}


