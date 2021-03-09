#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "models.hpp"

#include <math.h>
#include "tinyxml2.h"
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>


Models models;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

void drawAxis(){
	glBegin(GL_LINES);
		// X axis in red
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(100.0f, 0.0f, 0.0f);
		// Y Axis in Green
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f,0.0f, 0.0f);
		glVertex3f(0.0f,100.0f, 0.0f);
		// Z Axis in Blue
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f,0.0f);
		glVertex3f(0.0f, 0.0f,100.0f);
	glEnd();
}

void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLoadIdentity();
	gluLookAt(5.0,5.0,5.0, 0.0,0.0,0.0, 0.0f,1.0f,0.0f);
	
	drawAxis();
	models.drawModels();
	
	// End of frame
	glutSwapBuffers();
}

void reage(unsigned char key, int x, int y) {
	switch (key) {
		//Não tem nada ainda, só quero isto pelo glutPostRedisplay.
	}
	glutPostRedisplay();
}

int main(int argc, char **argv) {
		
	models.readFile(argv[1]);
	//models.readFile("builddumb/teste.xml");

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG Assignment Engine");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(reage);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
