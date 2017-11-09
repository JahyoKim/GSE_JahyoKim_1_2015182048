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
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "Renderer.h"
#include <chrono> // 함수를 수행하는데 걸리는 시간

using namespace std;

Renderer *g_Renderer = NULL;


SceneMgr *pSceneMgr = NULL;

auto start = chrono::system_clock::now();

void RenderScene(void) // 프레임당 1회 호출
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test

	// g_Renderer->DrawSolidRect(pObject->GetPosition().x, pObject->GetPosition().y, pObject->GetPosition().z, 
		//pObject->GetSize().s, pObject->GetColor().r, pObject->GetColor().g, pObject->GetColor().b, 1.0);
	
	g_Renderer->DrawSolidRect(0, 0, 0, 20, 1, 0, 1, 1);

	pSceneMgr->drawObject();

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	// if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	// {
	// 	cout << x << "\t" << y << endl;
	// 
	// 	 pObject->SetPosition(x-250, -y+250, 0);
	// 
	// }
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
	pSceneMgr = new SceneMgr;
	
	
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
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}
	pSceneMgr = new SceneMgr;
	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);
	//glutTimerFunc(100, Update, 1); // 1초 주기로 업데이트
	glutMainLoop();

	delete g_Renderer;

	delete pSceneMgr;

	return 0;
}

