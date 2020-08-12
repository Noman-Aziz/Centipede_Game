//============================================================================
// Name        : Centipede.cpp
// Author      : Noman Aziz
// Version     : 2.0
// Copyright   : (XD) Reserved
// Description : OOP Final Project
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include "Board.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

void SetCanvasSize(int width, int height)
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

//Objects Variables
Board *b ;

void GameDisplay()
{
	glClearColor(0, 0.1, 0.0, 0);
	glClear (GL_COLOR_BUFFER_BIT) ;

	b->Draw() ;
	
	glutPostRedisplay();
	glutSwapBuffers();
}	

void NonPrintableKeys(int key, int x, int y)
{
	if (key	== GLUT_KEY_LEFT)
	{
		b->player.decX(b->mushrooms) ;
	}

	else if (key == GLUT_KEY_RIGHT)
	{
		b->player.incX(b->mushrooms) ;
	}

	else if (key == GLUT_KEY_UP)
	{
		b->player.incY(b->mushrooms) ;
	}

	else if (key == GLUT_KEY_DOWN)
	{
		b->player.decY(b->mushrooms) ;
	}

	glutPostRedisplay();
}

void PrintableKeys(unsigned char key, int x, int y)
{
	if (key == 27)
	{
		exit(1);
	}

	if (key == 32)
	{
		if ( b->ammo >= 5 )
			b->ammo = 0 ;

	   	cout << "Laser Fired" << endl;

		b->bomb[b->ammo].setFire(b->player) ;

		b->ammo++ ;
	}

	glutPostRedisplay();
}

void Timer(int m)
{
	b->flee.setTimer( b->flee.getTimer() + 10 ) ;

	glutTimerFunc(1000.0, Timer, 0);
}

void MousePressedAndMoved(int x, int y)
{
	cout << x << " " << y << endl;
	glutPostRedisplay();
}

void MouseMoved(int x, int y)
{
	glutPostRedisplay();
}

void MouseClicked(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;
	}

	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{

	}

	glutPostRedisplay();
}

int main(int argc, char*argv[])
{
	srand(time(0)) ;

	b = new Board(10, 10); 							 // create a new board object to use in the Display Function ...

	int width = 600, height = 600; 					 // i have set my window size to be 800 x 600

	b->InitalizeBoard(width, height);

	InitRandomizer(); 								 // seed the random number generator...

	glutInit(&argc, argv); 							 // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);	 // we will be using color display mode
	glutInitWindowPosition(50, 50);					 // set the initial position of our window
	glutInitWindowSize(width, height);				 // set the size of our window
	glutCreateWindow("Centipede");					 // set the title of our game window

	SetCanvasSize(width, height);					 // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	// glutDisplayFunc(display);					 // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay);					 // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys);				 // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys);				 // tell library which function to call for printable ASCII characters

	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...

	glutTimerFunc(1000.0, Timer, 0);
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved);				 // Mouse
	glutMotionFunc(MousePressedAndMoved);			 // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...

	glutMainLoop();

	return 1;
}

#endif
