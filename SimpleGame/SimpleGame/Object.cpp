#include "stdafx.h"
#include "Object.h"


Object::Object()
{
	memset(&m_Position,0,sizeof(m_Position));
	memset(&m_Size, 0, sizeof(m_Size));
	memset(&m_Color, 0, sizeof(m_Color));

	m_Move.moveX = 20.0f;
	m_Move.moveY = 10.0f;
	m_Move.moveZ = 0.0f;
}
Object::~Object()
{

}

void Object::update()
{
	m_Position.x += m_Move.moveX;
	m_Position.y += m_Move.moveY;
	m_Position.z += m_Move.moveZ;
}


