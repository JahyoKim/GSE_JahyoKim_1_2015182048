#pragma once

struct FLOAT3 // 좌표
{
	float x;
	float y;
	float z;
};
struct FLOATCOLOR // 크기 및 색
{
	float s;
	float r;
	float g;
	float b;
};

struct FLOATMOVE {
	float moveX;
	float moveY;
	float moveZ;
};

class Object 
{
private:
	FLOAT3 m_Position;
	FLOATCOLOR m_Size;
	FLOATCOLOR m_Color; 

	FLOATMOVE m_Move; // 속도

public:
	Object();
	~Object();
	
	FLOAT3 GetPosition() { return m_Position; }
	FLOATCOLOR GetSize() { return m_Size; }
	FLOATCOLOR GetColor() { return m_Color; }

	FLOATMOVE GetMove() { return m_Move; }
	
	void SetPosition(float x, float y, float z) { m_Position.x = x, m_Position.y = y, m_Position.z = z; }
	void SetSize(float s) { m_Size.s = s; }
	void SetColor(float r, float g, float b) { m_Color.r = r, m_Color.g = g, m_Color.b = b;  }
	void SetMove(float mX, float mY, float mZ) { m_Move.moveX = mX, m_Move.moveY = mY, m_Move.moveZ = mZ; }
	void update();

};