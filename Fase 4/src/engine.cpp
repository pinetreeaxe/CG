#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include <IL/il.h>

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
float camAlfa = 0.75f, camBeta = 0.5f, camRadius = 200.0f;
//float camAlfa = 0.0f, camBeta = 0.0f, camRadius = 20.0f;
float camX, camY, camZ;
float centerX = 0.0f, centerY = 0.0f, centerZ = 0.0f;
float timestamp = 0.0f;
int timebase = 0, frame = 0;
float savedMod,timeMod = 0.0001f;
bool isPaused = false;	
GLfloat dark[4] = { 0.2,0.2,0.2,1.0 };
GLfloat white[4] = { 1.0,1.0,1.0,1.0 };

GLuint vertexCount, buffers[2];



void spherical2Cartesian() {

	camX = centerX + camRadius * cos(camBeta) * sin(camAlfa);
	camY = centerY + camRadius * sin(camBeta);
	camZ = centerZ + camRadius * cos(camBeta) * cos(camAlfa);
}


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
	char s[64];
	// clear buffers
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(camX,camY,camZ,
			  centerX,centerY,centerZ,
			  0.0f,1.0f,0.0f);
	glPolygonMode(GL_FRONT_AND_BACK, mode);

	//drawAxis();
	glRotatef(angleX,1.0,0.0,0.0);
	glRotatef(angleY,0.0,1.0,0.0);
	glRotatef(angleZ,0.0,0.0,1.0);

	models.drawModels(timestamp);
	frame++;
	int timet=glutGet(GLUT_ELAPSED_TIME); 
	if (timet - timebase > 1000) { 
		float fps = frame*1000.0/(timet-timebase); 
		timebase = timet; 
		frame = 0; 
		sprintf(s, "FPS: %f6.2", fps);
		glutSetWindowTitle(s);
	} 
	timestamp += timeMod;
	
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
		case '+':
			camRadius -= 1.0f;
			if (camRadius < 30.0f)
				camRadius = 30.0f;
			break;
		case '-':
			camRadius += 1.0f;
			break;
		case 'w':
			camBeta += 0.1f;
			if (camBeta > 1.5f)
				camBeta = 1.5f;
			break;
		case 's':
			camBeta -= 0.1f;
			if (camBeta < -1.5f)
				camBeta = -1.5f;
			break;
		case 'a':
			camAlfa -= 0.1; break;
			break;
		case 'd':
			camAlfa += 0.1; break;
			break;
		case 'r':
			camAlfa = 0.75f;
			camBeta = 0.5f;
			camRadius = 200.0f;
			centerX = 0.0f;
			centerY = 0.0f;
			centerZ = 0.0f;
			timestamp = 0.0f;
			timeMod = 0.0001f;
			mode = GL_FILL;
			break;
		case 'p':
			if(!isPaused){
				isPaused = true;
				savedMod = timeMod;
				timeMod = 0.0f;
			}else{
				isPaused = false;
				timeMod = savedMod;
			}
			break;
		case 'i':
			timeMod *= 10;
			break;
		case 'o':
			timeMod /= 10;
			break;
	}
	spherical2Cartesian();
	glutPostRedisplay();
}

void specialKeyReaction(int key, int xx, int yy) {

	switch (key) {

	case GLUT_KEY_RIGHT:
		centerX += 0.5f; break;

	case GLUT_KEY_LEFT:
		centerX -= 0.5f; break;

	case GLUT_KEY_UP:
		centerZ -= 0.5f; break;

	case GLUT_KEY_DOWN:
		centerZ += 0.5f; break;
	}
	spherical2Cartesian();
	glutPostRedisplay();

}

void initGL() {

// OpenGL settings 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);

// init
	spherical2Cartesian();
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glEnable(GL_TEXTURE_2D);
	ilInit();
    ilEnable(IL_ORIGIN_SET);
    ilOriginFunc(IL_ORIGIN_UPPER_LEFT);

}

int main(int argc, char **argv) {
		
	//models.readFile("builddumb/teste.xml");

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG Assignment Engine");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(keyReaction);
	glutSpecialFunc(specialKeyReaction);
	glewInit();

//  OpenGL settings
	initGL();
	


	models.readFile(argv[1]);

// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
