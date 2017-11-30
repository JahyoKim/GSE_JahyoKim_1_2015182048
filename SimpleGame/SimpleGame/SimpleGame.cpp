/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include "Object.h"
#include "SceneMgr.h"
#include <iostream>
#include <Windows.h>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "Renderer.h"

using namespace std;

Renderer *g_Renderer = NULL;
SceneMgr *g_SceneMgr = NULL;

auto g_start = 0;

void RenderScene(void) // 프레임당 1회 호출
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test
	//g_Renderer->DrawSolidRect(0, 0, 0, 20, 1, 0, 1, 1);

	auto currentTime = timeGetTime();
	auto elapsedTime = currentTime - g_start;
	g_start = currentTime;

	g_SceneMgr->collision();
	g_SceneMgr->updateObject(elapsedTime);
	g_SceneMgr->drawObject();


	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		cout << x << "\t" << y << endl;

		
		g_SceneMgr->initObject(x - 250, -y + 250);
		
	
		 // pObject->SetPosition(x-250, -y+250, 0);
		
	
	}
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

void Update(int value)
{
	glutTimerFunc(1000, Update, 1);
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize Renderer
	g_Renderer = new Renderer(500, 500);
	g_SceneMgr = new SceneMgr(500, 500);

	
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}
	
	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	g_start = timeGetTime();

	glutMainLoop();

	delete g_Renderer;
	delete g_SceneMgr;

	return 0;
}

