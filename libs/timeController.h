#ifndef timeController
#define timeController
#include <GL/glut.h>

void time(int id){
	

    glutPostRedisplay();
    glutTimerFunc(60, time, 0);
}
		
#endif
