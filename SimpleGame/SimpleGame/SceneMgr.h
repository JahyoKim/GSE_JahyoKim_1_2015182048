#pragma once
#include "Object.h"

class SceneMgr {
	Object m_objects;

	SceneMgr();
	~SceneMgr();

	void MaxObjectCount();
	void update();

};
