#include "stdafx.h"
#include "Object.h"


Object::Object()
{
	memset(&m_Position,0,sizeof(m_Position));
	memset(&m_Size, 0, sizeof(m_Size));
	memset(&m_Color, 0, sizeof(m_Color));

	m_Velocity.x = 20.0f;
	m_Velocity.y = 10.0f;
	m_Velocity.z = 0.0f;
}
Object::~Object()
{

}

void Object::update()
{
	m_Position.x += m_Velocity.x;
	m_Position.y += m_Velocity.y;
	m_Position.z += m_Velocity.z;
}


