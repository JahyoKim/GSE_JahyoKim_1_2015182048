#include "stdafx.h"
#include "Object.h"


Object::Object()
{
	memset(&m_Position,0,sizeof(m_Position));
	memset(&m_Color, 0, sizeof(m_Color));

	m_Velocity.x = 10.0f;
	m_Velocity.y = 0.0f;
	m_Velocity.z = 0.0f;
	

}
Object::~Object()
{

}
FLOAT3 Object::GetPosition()
{
	return m_Position;
}
FLOAT4 Object::GetColor()
{
	return m_Color;

}

void Object::update()
{

	m_Position.x += m_Velocity.x;
	m_Position.y += m_Velocity.y;
	m_Position.z += m_Velocity.z;


}


