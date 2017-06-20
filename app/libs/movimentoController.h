#ifndef movimentoController
#define movimentoController
#include <GL/glut.h>
#include<iostream>
#include <time.h>

void movimentaPlayer(GLdouble xc, GLdouble yc){
	glPushMatrix();
		glColor3f(1, 1, 1); 
		glTranslatef(xc, yc, 0);
		glutWireCube(3);
	glPopMatrix();	
}

unsigned long mix(unsigned long a, unsigned long b, unsigned long c){
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

unsigned int criaSeed() {
	unsigned long seed = mix(clock(), time(NULL), getpid());
	return seed;
}

int pontoPartidaX() {
	srand(criaSeed());
	int r = (rand() % 98) - 48;
	return r;
}

int pontoPartidaY() {
	srand(criaSeed());
	int r = (rand() % 60);
	if(r < 52){
		r += 60 - r;
	}
	return r;
}
	
#endif
