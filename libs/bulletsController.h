#ifndef bulletsController
#define bulletsController
#include <GL/glut.h>

	void normalBullet(){		
		glPushMatrix();
			glTranslatef(25, 25, 0);
			glColor3f(1, 0, 0);
			glutSolidCube(2);
		glPopMatrix();
	}
	
	void masterBullet(){
		glPushMatrix();
			glTranslatef(75, 75, 0);
			glColor3f(1, 0.5, 0.5);
			glutSolidCube(2);
		glPopMatrix();
	}

#endif
