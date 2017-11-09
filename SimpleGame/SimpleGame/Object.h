#pragma once

struct FLOAT3 // ��ǥ
{
	float x;
	float y;
	float z;
};
struct FLOATCOLOR // ũ�� �� ��
{
	float s;
	float r;
	float g;
	float b;
};

struct FLOATVELOCACITY {
	float vX;
	float vY;
	float vZ;
};

class Object 
{
private:
	FLOAT3 m_Position;
	FLOATCOLOR m_Size;
	FLOATCOLOR m_Color; 

	FLOATVELOCACITY m_velocity; // �ӵ�

public:
	Object();
	~Object();
	
	FLOAT3 GetPosition() { return m_Position; }
	FLOATCOLOR GetSize() { return m_Size; }
	FLOATCOLOR GetColor() { return m_Color; }

	FLOATVELOCACITY GetVelocity() { return m_velocity; }
	
	void SetPosition(float x, float y, float z) { m_Position.x = x, m_Position.y = y, m_Position.z = z; }
	void SetSize(float s) { m_Size.s = s; }
	void SetColor(float r, float g, float b) { m_Color.r = r, m_Color.g = g, m_Color.b = b;  }
	//void SetVelocity(float mX, float mY, float mZ) { m_velocity.vX = mX, m_velocity.vY = mY, m_velocity.vZ = mZ; }
	void update(float elapsedTime);

};