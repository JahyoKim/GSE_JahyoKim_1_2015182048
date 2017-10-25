#pragma once

struct FLOAT3 // 좌표
{
	float x;
	float y;
	float z;
};
struct FLOAT4 // 크기 및 색
{
	float s;
	float r;
	float g;
	float b;
};

class Object 
{
private:
	FLOAT3 m_Position;
	FLOAT4 m_Size;
	FLOAT4 m_Color; 

	FLOAT3 m_Velocity; // 속도

public:
	Object();
	~Object();
	
	FLOAT3 GetPosition() { return m_Position; }
	FLOAT4 GetSize() { return m_Size; }
	FLOAT4 GetColor() { return m_Color; }

	FLOAT3 GetVelocity;
	
	void SetPosition(float x, float y, float z) { m_Position.x = x, m_Position.y = y, m_Position.z = z; }
	void SetSize(float s) { m_Size.s = s; }
	void SetColor(float r, float g, float b) { m_Color.r = r, m_Color.g = g, m_Color.b = b;  }
	void update();

};