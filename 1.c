
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <GL/glut.h>
#include <time.h>
#include <math.h>
#include "primitive.h"
/* Global Variables */

#define initial_W 500
#define initial_H 500

int W = initial_W;
int H = initial_H;

int discomode = 0;

struct coords
{
	int x;			   //X-axis rotation
	int y;			   //Y-axis rotation
	int speed;		   //rotation speed
} cube = {0, 0, 5},	//where make movements here
	reset = {0, 0, 5}; //a copy of the original coordinates

// Position of the Camera
int eyeX = 0, eyeY = 0, eyeZ = 0;

// The coordinate to place in the center of the screen
int centerX = 0, centerY = 0, centerZ = -1;

// The up direction
int upX = 0, upY = 1, upZ = 0;

void processSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		cube.y = (cube.y + 20) % 360;
		break;
	case GLUT_KEY_RIGHT:
		cube.y = (cube.y - 20) % 360;
		break;
	case GLUT_KEY_UP:
	printf("%d\n", cube.x);
		if(cube.x<20)
		cube.x = (cube.x + 20) % 360;
		break;
	case GLUT_KEY_DOWN:
		if(cube.x>-160)
		cube.x = (cube.x - 20) % 360;
		break;
	}
}


GLfloat CloudLight[] = { 2, 0, -23.0, 6.0 };
GLfloat HouseLight[] = { 2, 1, -1, 1.5 };
GLfloat DistantLight[] = {90, 6, 71, 1};

void reshape(int, int);
void drawFrame();
void mouseClick(int, int, int, int);
void myMenu(int);
void drawCubeModel();

int main(int argc, char **argv)
{
	time_t t;
	srand((unsigned)time(&t));

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(W, H);
	glutInitWindowPosition(100, 150);
	glutCreateWindow(argv[0]);

	glutDisplayFunc(drawFrame);
	glutReshapeFunc(reshape);
	glutMouseFunc(&mouseClick);
	glutSpecialFunc(&processSpecialKeys);
	//  Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);\

	calculateCloudCoords();
	calculateHouseColors();
	
	/** 
		Add a menu when you right click, calls the function "myMenu".
		The "1" or "2" is the ID of the menu item.
		Then you can have an if/else condition for the ID
		when the "myMenu" is called.
	**/
	glutCreateMenu(myMenu);
	glutAddMenuEntry("Increment Z", 1);
	glutAddMenuEntry("Decrement Z", 2);			   //add more options as needed
	glutAddMenuEntry("Randomize Scene", 5); //add more options as needed
	glutAddMenuEntry("Toggle Disco-Mode", 6); //add more options as needed
	glutAddMenuEntry("Toggle House light", 7); //add more options as needed
	glutAddMenuEntry("Toggle Distant light", 8); //add more options as needed
	glutAddMenuEntry("Toggle Cloud light", 9); //add more options as needed
	glutAddMenuEntry("Toggle Coronavirus", 10);
	glutAddMenuEntry("Reset X Y", 4);
	glutAddMenuEntry("Exit", 3); //add more options as needed
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glColor3f(0, 0, 0);
	glPointSize(1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* This will change the camera position / center view / up direction */
	gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
	//lighting setup
	//glShadeModel(GL_SMOOTH);
	//glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	GLfloat qaAmbientLight[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat qaDiffuseLight[] = {0.8, 0.8, 0.8, 1.0};
	GLfloat qaSpecularLight[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat spot_direction[] = { 0.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, CloudLight);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.5);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.5);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.2);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 45.0);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.0);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	

	GLfloat spot_direction2[] = { 0.0, -1.0, 1.0 };
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecularLight);
	glLightfv(GL_LIGHT1, GL_POSITION, HouseLight);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 200.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.3);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction2);

	glEnable(GL_LIGHT2);
	glLightfv(GL_LIGHT2, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT2, GL_SPECULAR, qaSpecularLight);
	glLightfv(GL_LIGHT2, GL_POSITION, DistantLight);

	
	glutMainLoop();

	return 0;
}

/**
	This function handles the window resize event.
**/
void reshape(int w, int h)
{
	W = w;
	H = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 16 / 9, 0.1f, 100.0f);
	gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
}

/**
	This is the funtion called at each draw loop.
	We draw a cube and rotate is based on user inputs (arrow keys).
**/
void drawFrame()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75.0f, 16 / 9, 0.1f, 100.0f);
	gluLookAt(eyeX, eyeY + 2, eyeZ - 6, centerX, centerY, centerZ, upX, upY, upZ);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(cube.x, 1, 0, 0);
	glRotatef(cube.y, 0, 1, 0);
	if(discomode==1) calculateHouseColors();
	drawCubeModel();
	drawRoadModel();
	drawGrassModel();
	drawClouds();
	drawFence();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

/**
	This function is called each time the mouse is clicked.
**/
void mouseClick(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		eyeX = -((x - 250) / 100);
		eyeY = -((y - 250) / 100);
	}
}

void myMenu(int v)
{
	switch (v)
	{
	case 1: /* If the first menu item was clicked, we reset the cube */
		eyeZ++;
		break;
	case 2:
		eyeZ--;
		break;
	case 4:
		eyeX = 0;
		eyeY = 0;
		break;
	case 3:
		exit(0);
	case 5:
		calculateCloudCoords();
		calculateHouseColors();
		break;
	case 6:
		if(discomode==0) discomode=1;
		else discomode=0;
		break;
	case 7:
		if(glIsEnabled(GL_LIGHT1))
			glDisable(GL_LIGHT1);
		else
			glEnable(GL_LIGHT1);
		break;
	case 8:
		if(glIsEnabled(GL_LIGHT2))
			glDisable(GL_LIGHT2);
		else
			glEnable(GL_LIGHT2);
		break;
	case 9:
		if(glIsEnabled(GL_LIGHT0))
			glDisable(GL_LIGHT0);
		else
			glEnable(GL_LIGHT0);
		break;
	case 10:
		toggleCoronaVirus();
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		break;
	}
}
