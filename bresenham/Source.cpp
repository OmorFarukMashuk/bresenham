#include <iostream>
//#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

int x = 0;
int y = 0;

int p1 = 100;
int p2 = 200;
int q1 = 200;
int q2 = 300;


void midpointline(void)
{
	int dx = p2-p1, dy = q2-q1;
	int d = 2*dy - dx;
	int incrE = 2* dy;
	int incrNE = 2 * (dy -dx);
	int x = p1, y = q1;
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(1.0);
	
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();

	while(x<p2)
	{
		if(d<=0)
			d = d + incrE;
		else
		{
			d = d + incrNE;
			++y;
		}
		++x;


		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
		glFlush();
		

	}

	//glFlush();

}





void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	glClear (GL_COLOR_BUFFER_BIT);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("bresenham");


	glutDisplayFunc(midpointline);
	myInit();
	glutMainLoop();

}




