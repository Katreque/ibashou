#ifndef movimentoController
#define movimentoController
#include <GL/glut.h>
#include <stdio.h>

GLdouble x = 48, y = 5;
GLdouble storedx = 48, storedy = 5;

void movimentaPlayer(GLdouble xc, GLdouble yc){
	if(x+xc < -0.6 || x+xc > 96 || y+yc < -0.6 || y+yc > 96){
		glPushMatrix();
			glColor3f(1, 1, 1);
			glTranslatef(storedx, storedy, 0); 
			glBegin(GL_POLYGON); 
			  glVertex3f(0, 4, 0.0); 
			  glVertex3f(4, 4, 0.0); 
			  glVertex3f(4, 0, 0.0); 
			  glVertex3f(0, 0, 0.0); 
			glEnd();
		glPopMatrix();
	} else {
		glPushMatrix();
			glColor3f(1, 1, 1); 
			glTranslatef(x+xc, y+yc, 0);
			glBegin(GL_POLYGON); 
			  glVertex3f(0, 4, 0.0); 
			  glVertex3f(4, 4, 0.0); 
			  glVertex3f(4, 0, 0.0); 
			  glVertex3f(0, 0, 0.0); 
			glEnd();
		glPopMatrix();
		storedx = x+xc;
		storedy = y+yc;
		x = x+xc;
		y = y+yc;
	}
}
	
#endif
