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
Normalbullet normalbullet[10];

void inicializacao() {
	player1.x = 0;
	player1.y = -45;
}

void myReshape(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective (90, float(w)/h, 1, 100);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void myDisplay(void){
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
     gluLookAt(0, 0, 50,
              0, 0, 0,
              0, 1, 0);
 	
    movimentaPlayer(player1.x, player1.y); 
    for(int i = 0; i < 1; i++){
    	normalBullet(normalbullet[i].x, normalbullet[i].y);			
	}
    
	glutSwapBuffers();
}

void controlesPlayer(int key, int x, int y){
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
	
	if(player1.x < -48){ 
		player1.x += 1.5;
	}
	
	if(player1.x > 48){ 
		player1.x -= 1.5;
	}
	
	if(player1.y < -48){ 
		player1.y += 1.5;
	}
	
	if(player1.y > 48){ 
		player1.y -= 1.5;
	}
	
	glutPostRedisplay();
}

void calcTiro(){
	for(int i = 0; i < 1; i+=3){
		int r = tiroLinear();
		
		normalbullet[i].x = r;
		normalbullet[i].y -= 1;
	}
}

void mov(){
	for(int i = 0; i < 1; i+=3){	
		normalbullet[i].x += -1;
	}
}

void time(int id){
	
	mov();
    glutPostRedisplay();
    glutTimerFunc(60, time, 1);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);
    
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    
    inicializacao();
	glutSpecialFunc(controlesPlayer);
	calcTiro();
	glutTimerFunc(60, time, 0);
	
    glutMainLoop();
    return 0;
}
