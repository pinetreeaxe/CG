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
float angleX = 0;
float angleY = 0;
float angleZ = 0;
GLenum mode = GL_FILL;

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
	glLoadIdentity();
	gluLookAt(5.0,5.0,5.0, 0.0,0.0,0.0, 0.0f,1.0f,0.0f);
	glPolygonMode(GL_FRONT_AND_BACK, mode);

	drawAxis();
	glRotatef(angleX,1.0,0.0,0.0);
	glRotatef(angleY,0.0,1.0,0.0);
	glRotatef(angleZ,0.0,0.0,1.0);
	models.drawModels();
	
	// End of frame
	glutSwapBuffers();
}

void keyReaction(unsigned char key, int x, int y){
	switch(key){
		case '1':
			mode = GL_LINE;
			break;
		case '2':
			mode = GL_POINT;
			break;
		case '3':
			mode = GL_FILL;
			break;
		case 'z':
			angleX += 10;
			break;
		case 'x':
			angleX -= 10;
			break;
		case 'c':
			angleZ += 10;
			break;
		case 'v':
			angleZ -= 10;
			break;	
		case 'a':
			angleY -= 10;
			break;
		case 'd':
			angleY += 10;
			break;
		case 'r':
			angleX = 0;
			angleY = 0;
			angleZ = 0;
			mode = GL_FILL;
			break;
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
	glutKeyboardFunc(keyReaction);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
