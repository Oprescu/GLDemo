#include <GL/glut.h>
/**
	This is our only draw function.
**/

float houseRoofColours[20*3];
float cloudCoords[20];
void calculateHouseColors(){
	for(int i=0;i<20*3;i++)
		houseRoofColours[i]=(float)rand()/(float)(RAND_MAX/1.0);
}
void calculateCloudCoords(){
	for(int i=0;i<20*3;i++)
		cloudCoords[i]=(float)rand()/(float)(RAND_MAX/20.0);
}
int coronavirus = 0;

void toggleCoronaVirus(){
	if(coronavirus==0)
		coronavirus=1;
		else
		{
		coronavirus=0;
		}
}

void drawCubeModel() {
	
	// Scale and translate values

	float sx = 1.2; 
	float tx = -20.0;
	float sy = 1.2;
	float ty = 0.1;
	float sz = 1.2;
	float tz = 1.0;
	if(coronavirus==0)
	for(int i=0;i<20;i++)
	{/* Front */
	glBegin(GL_POLYGON);
	glColor3f(   0.96,  0.96,  0.83 );
	glVertex3f(  0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glEnd();
	/* Door */
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  0.0 );
	glVertex3f(  0.15*sx+tx, -0.50*sy+ty, -0.51*sz+tz );
	glVertex3f(  0.15*sx+tx,  0.0*sy+ty, -0.51*sz+tz );
	glVertex3f( -0.15*sx+tx,  0.0*sy+ty, -0.51*sz+tz );
	glVertex3f( -0.15*sx+tx, -0.50*sy+ty, -0.51*sz+tz );
	glEnd();
	/* Window Right*/
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  1.0 );
	glVertex3f(  0.37*sx+tx,  0.15*sy+ty, -0.51*sz+tz );
	glVertex3f(  0.37*sx+tx,  0.35*sy+ty, -0.51*sz+tz );
	glVertex3f(  0.17*sx+tx,  0.35*sy+ty, -0.51*sz+tz );
	glVertex3f(  0.17*sx+tx,  0.15*sy+ty, -0.51*sz+tz );
	glEnd();
	/* Window Left*/
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  1.0 );
	glVertex3f(  -0.37*sx+tx,  0.15*sy+ty, -0.51*sz+tz );
	glVertex3f(  -0.37*sx+tx,  0.35*sy+ty, -0.51*sz+tz );
	glVertex3f(  -0.17*sx+tx,  0.35*sy+ty, -0.51*sz+tz );
	glVertex3f(  -0.17*sx+tx,  0.15*sy+ty, -0.51*sz+tz );
	glEnd();
	/* Back */
	glBegin(GL_POLYGON);
	glColor3f(   0.96,  0.96,  0.83 );
	glVertex3f(  0.5*sx+tx, -0.5*sy+ty, 0.5*sz+tz );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty, 0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty, 0.5*sz+tz );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty, 0.5*sz+tz );
	glEnd();
	/* Right */
	glBegin(GL_POLYGON);
	glColor3f(   0.96,  0.96,  0.83 );
	glVertex3f( 0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( 0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( 0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glVertex3f( 0.5*sx+tx, -0.5*sy+ty,  0.5*sz+tz );
	glEnd();
	/* Left */
	glBegin(GL_POLYGON);
	glColor3f(   0.96,  0.96,  0.83 );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty,  0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glEnd();
	/* Top */
	glBegin(GL_POLYGON);
	glColor3f(   0.96,  0.96,  0.83 );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glEnd();
	// Draw four side triangles
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(houseRoofColours[i], houseRoofColours[i+1], houseRoofColours[i+2]);
	// the common point of the four triangles
	glVertex3f(0*sx+tx, 1*sy+ty, 0*sz+tz);

	// Base points of each triangle
	glVertex3f(-0.5*sx+tx, 0.5*sy+ty, -0.5*sz+tz);
	glVertex3f(-0.5*sx+tx, 0.5*sy+ty,  0.5*sz+tz);
	glVertex3f(-0.5*sx+tx, 0.5*sy+ty,  0.5*sz+tz);
	glVertex3f( 0.5*sx+tx, 0.5*sy+ty,  0.5*sz+tz);
	glVertex3f( 0.5*sx+tx, 0.5*sy+ty,  0.5*sz+tz);
	glVertex3f( 0.5*sx+tx, 0.5*sy+ty, -0.5*sz+tz);
	glVertex3f( 0.5*sx+tx, 0.5*sy+ty, -0.5*sz+tz);
	glVertex3f(-0.5*sx+tx, 0.5*sy+ty, -0.5*sz+tz);
	glEnd();
	/* Bottom */
	glBegin(GL_POLYGON);
	glColor3f(   0.96,  0.96,  0.83 );
	glVertex3f(  0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glVertex3f(  0.5*sx+tx, -0.5*sy+ty,  0.5*sz+tz );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty,  0.5*sz+tz );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glEnd();
	tx+=2.5;
	}
}

void drawRoadLines(){
	float sx = 0.5; 
	float tx = 0.0;
	float sy = 0.02;
	float ty = -0.438;
	float sz = 0.1;
	float tz = -1.5;


	for(int i=0;i<50;i++){
	/* Top */
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0,  0.0 );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glEnd();
	tx+=0.9;
	}
	tx = 0.0;
	for(int i=0;i<50;i++){
	/* Top */
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0,  0.0 );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glEnd();
	tx-=0.9;
	}

}

void drawRoadModel() {
	// Scale and translate values

	float sx = 115.0; 
	float tx = 0.0;
	float sy = 0.02;
	float ty = -0.44;
	float sz = 1.5;
	float tz = -1.5;

	/* Front */
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  0.0 );
	glVertex3f(  0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glEnd();
	/* Door */
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  0.0 );
	glVertex3f(  0.15*sx+tx, -0.50*sy+ty, -0.51*sz+tz );
	glVertex3f(  0.15*sx+tx,  0.0*sy+ty, -0.51*sz+tz );
	glVertex3f( -0.15*sx+tx,  0.0*sy+ty, -0.51*sz+tz );
	glVertex3f( -0.15*sx+tx, -0.50*sy+ty, -0.51*sz+tz );
	glEnd();
	/* Window Right*/
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  0.0 );
	glVertex3f(  0.37*sx+tx,  0.15*sy+ty, -0.51*sz+tz );
	glVertex3f(  0.37*sx+tx,  0.35*sy+ty, -0.51*sz+tz );
	glVertex3f(  0.17*sx+tx,  0.35*sy+ty, -0.51*sz+tz );
	glVertex3f(  0.17*sx+tx,  0.15*sy+ty, -0.51*sz+tz );
	glEnd();
	/* Window Left*/
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  0.0 );
	glVertex3f(  -0.37*sx+tx,  0.15*sy+ty, -0.51*sz+tz );
	glVertex3f(  -0.37*sx+tx,  0.35*sy+ty, -0.51*sz+tz );
	glVertex3f(  -0.17*sx+tx,  0.35*sy+ty, -0.51*sz+tz );
	glVertex3f(  -0.17*sx+tx,  0.15*sy+ty, -0.51*sz+tz );
	glEnd();
	/* Back */
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  0.0 );
	glVertex3f(  0.5*sx+tx, -0.5*sy+ty, 0.5*sz+tz );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty, 0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty, 0.5*sz+tz );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty, 0.5*sz+tz );
	glEnd();
	/* Right */
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  0.0 );
	glVertex3f( 0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( 0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( 0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glVertex3f( 0.5*sx+tx, -0.5*sy+ty,  0.5*sz+tz );
	glEnd();
	/* Left */
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  0.0 );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty,  0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glEnd();
	/* Top */
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  0.0 );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glEnd();
	/* Bottom */
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  0.0 );
	glVertex3f(  0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glVertex3f(  0.5*sx+tx, -0.5*sy+ty,  0.5*sz+tz );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty,  0.5*sz+tz );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glEnd();

	drawRoadLines();
}

void drawGrassModel() {
	// Scale and translate values

	float sx = 115.0; 
	float tx = 0.0;
	float sy = 0.02;
	float ty = -0.47;
	float sz = 115.0;
	float tz = -1.5;
	
	/* Top */
	glBegin(GL_POLYGON);
	glColor3f(0,1,0);
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glEnd();
	/* Bottom */
}

void drawClouds(){

	glColor3f(1.0,1.0,1.0);

	for(float i=0;i<20;i++){
	glPushMatrix();
	glTranslatef(i*9-90,0,cloudCoords[(int) i]);
	glPushMatrix();
	glTranslatef(-1.0,7,20);
	glutSolidSphere(2,100,5);
	glTranslatef(+2.0,2,2);
	glutSolidSphere(2,100,5);
	glTranslatef(-4,0,-2);
	glutSolidSphere(2,100,5);
	glTranslatef(+2.0,2,2);
	glutSolidSphere(2,100,5);
	glPopMatrix();
	glPopMatrix();
    glFlush();
	}
}

void drawFence(){
	// Scale and translate values

	float sx = 0.1; 
	float tx = -30.0;
	float sy = 0.5;
	float ty = -0.2;
	float sz = 0.1;
	float tz = -.4;
	for(int i=0;i<120;i++)
	{/* Front */
	glBegin(GL_POLYGON);
	glColor3f(   0.39,  0.26,  0.12 );
	glVertex3f(  0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glEnd();
	/* Back */
	glBegin(GL_POLYGON);

	glVertex3f(  0.5*sx+tx, -0.5*sy+ty, 0.5*sz+tz );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty, 0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty, 0.5*sz+tz );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty, 0.5*sz+tz );
	glEnd();
	/* Right */
	glBegin(GL_POLYGON);

	glVertex3f( 0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( 0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( 0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glVertex3f( 0.5*sx+tx, -0.5*sy+ty,  0.5*sz+tz );
	glEnd();
	/* Left */
	glBegin(GL_POLYGON);
	
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty,  0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glEnd();
	/* Top */
	glBegin(GL_POLYGON);

	glVertex3f(  0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glVertex3f(  0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty, -0.5*sz+tz );
	glVertex3f( -0.5*sx+tx,  0.5*sy+ty,  0.5*sz+tz );
	glEnd();
	// Draw four side triangles
	/* Bottom */
	glBegin(GL_POLYGON);

	glVertex3f(  0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glVertex3f(  0.5*sx+tx, -0.5*sy+ty,  0.5*sz+tz );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty,  0.5*sz+tz );
	glVertex3f( -0.5*sx+tx, -0.5*sy+ty, -0.5*sz+tz );
	glEnd();
	tx+=0.5;
	}
}