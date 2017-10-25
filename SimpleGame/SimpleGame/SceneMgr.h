#pragma once
#include "Object.h"
#include "Renderer.h"

#define MAX_OBJECTS_COUNT 50

class SceneMgr {
private:
	Object *m_objects[MAX_OBJECTS_COUNT];
	Renderer *m_renderer;

public:
	SceneMgr();
	~SceneMgr();

	

	void drawObject();
	void update();

};
