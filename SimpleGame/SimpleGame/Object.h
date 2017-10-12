#pragma once

struct FLOAT3 // 좌표
{
	float x;
	float y;
	float z;
};

struct FLOAT4 // 크기 및 색
{
	float x;
	float y;
	float z;
	float a;

};


class Object 
{
private:
	FLOAT3 m_Position;
	FLOAT4 m_Color;

	FLOAT3 m_Velocity; // 속도

public:
	Object();
	~Object();
	
	FLOAT3 GetPosition();
	FLOAT4 GetColor();

	FLOAT3 GetVelocity;
	
	void SetPosition(int x, int y, int z) { m_Position.x = x, m_Position.y = y, m_Position.z = z; }
	void update();

};