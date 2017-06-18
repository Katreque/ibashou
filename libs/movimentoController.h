#ifndef movimentoController
#define movimentoController
#include <GL/glut.h>

void movimentaPlayer(GLdouble xc, GLdouble yc){
	glPushMatrix();
		glColor3f(1, 1, 1); 
		glTranslatef(xc, yc, 0);
		glutWireCube(3);
	glPopMatrix();	
}

int tiroLinear() {
	int r = (rand() % 100) - 48;
	return r;
}

int tiroLinear1() {
	return -2;
}

int tiroLinear2() {
	return -4;
}
	
#endif
