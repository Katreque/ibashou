#include <stdio.h>
#include <cstdlib>
#include <GL/glut.h>
#include <movimentoController.h>
#include <bulletsController.h>

struct PlayerOne {
	GLdouble x;
	GLdouble y;
};

struct Normalbullet {
	GLdouble x;
	GLdouble y;
};

PlayerOne player1;
Normalbullet normalbullet[5] = {0};

void inicializacao() {
	player1.x = 0;
	player1.y = 0;
}

void myReshape(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void myDisplay(void){
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    movimentaPlayer(player1.x, player1.y); 
    for(int i = 0; i < 5; i++){
    	normalBullet(normalbullet[i].x, normalbullet[i].y);	
	}
		
    glutSwapBuffers();
}

void controlesPlayer(int key, int x, int y){
	player1.x = 0;
	player1.y = 0;
	
	switch(key){
		case 102:
			player1.x += 1.5;
		break;
		
		case 103:
			player1.y += -1.5;
		break;
		
		case 100:
			player1.x += -1.5;
		break;
		
		case 101:
			player1.y += 1.5;
		break;
	}

	glutPostRedisplay();
}

void mov(){
	for(int i = 0; i < 5; i++){
		normalbullet[i].y += tiroLinear();
	}
}

void time(int id){
	
	mov();
    glutPostRedisplay();
    glutTimerFunc(60, time, 1);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(700,700);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-700)/2, (glutGet(GLUT_SCREEN_HEIGHT)-800)/2);
    glutCreateWindow(argv[0]);
    inicializacao();

	glutSpecialFunc(controlesPlayer);
	glutTimerFunc(60, time, 0);
	
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    glutMainLoop();
    return 0;
}
