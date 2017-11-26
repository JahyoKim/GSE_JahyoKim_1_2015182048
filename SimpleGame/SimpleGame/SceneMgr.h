#pragma once
#include "Object.h"
#include "Renderer.h"

#define MAX_OBJECTS_COUNT 50

class SceneMgr {
private:
	Object *m_objects[MAX_OBJECTS_COUNT];
	Renderer *m_renderer;

	int m_windowWidth;
	int m_windowHeight;

public:
	SceneMgr();
	SceneMgr(int width, int height);
	~SceneMgr();

	void initObject(float x, float y);
	void drawObject();
	void updateObject(float elapsedTime);

};
