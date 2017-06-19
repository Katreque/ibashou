#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <movimentoController.h>
#include <bulletsController.h>

#define TOTALTIROS 20

struct PlayerOne {
	GLdouble x;
	GLdouble y;
};

struct Normalbullet {
	GLdouble x;
	GLdouble y;
};

int score = 0, finalScore;
GLdouble velocidadeTiros = 55;
bool fim = false;

unsigned char final[] = "Game Over!";

PlayerOne player1;
Normalbullet normalbullet[TOTALTIROS];

void inicializacao() {
	PlaySound("C:\\Users\\rveri_000\\Desktop\\Programacao\\ibashou\\MainTheme.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
	
	player1.x = 0;
	player1.y = -45;
	
	for(int i = 0; i < TOTALTIROS; i++){	
		normalbullet[i].x = pontoPartidaX();
		normalbullet[i].y = pontoPartidaY();
	}
}

void tiroSaiuDoMapa(){
	for(int i = 1; i < TOTALTIROS; i++){
		if(normalbullet[i].x < -70 || normalbullet[i].x > 70 || normalbullet[i].y < -70|| normalbullet[i].y > 70){
			normalbullet[i].x = pontoPartidaX();
			normalbullet[i].y = pontoPartidaY();
			
		score++;
		printf("%d\n", score);
		
			if(score > 20){
				velocidadeTiros = 45;
			}
			
			if(score > 50){
				velocidadeTiros = 30;
			}
			
			if(score > 100){
				velocidadeTiros = 20;
			}
			
			if(score > 250){
				velocidadeTiros = 10;
			}
			
			if(score > 400){
				velocidadeTiros = 5;
			}
		}	
	}
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
              
    char buffer[4] = {};
	itoa(score, buffer, 10);
              
    glRasterPos2i(40, 45);
	glColor3f(1, 1, 1);
	for(int i = 0; i < 5; i++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, buffer[i]);
	}
 	
    movimentaPlayer(player1.x, player1.y); 
    for(int i = 0; i < TOTALTIROS; i++){
    	normalBullet(normalbullet[i].x, normalbullet[i].y);			
	}
	
	if(score >= 0 && score < 8){
		unsigned char fase [] = "Use as setas do teclado para se movimentar e tente não MORRER!";
		glRasterPos2i(-47, 20);
		glColor3f(1, 1, 0);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, fase);
	}
	
	if(score > 20 && score < 25){
		unsigned char fase [] = "Fase 01 - Bronze 8";
		glRasterPos2i(-13, 20);
		glColor3f(1, 1, 0);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, fase);
	}
	
	if(score > 50 && score < 60){
		unsigned char fase [] = "Fase 02 - KappaPride";
		glRasterPos2i(-13, 20);
		glColor3f(1, 1, 0);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, fase);
	}
	
	if(score > 100 && score < 110){
		unsigned char fase [] = "Fase 03 - High elo Gameplay";
		glRasterPos2i(-17, 20);
		glColor3f(1, 1, 0);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, fase);
	}
	
	if(score > 250 && score < 270){
		unsigned char fase [] = "Fase 04 - God do God";
		glRasterPos2i(-13, 20);
		glColor3f(1, 1, 0);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, fase);
	}
	
	if(score > 400){
		unsigned char fase [] = "Final Boss - Katreque's mind";
		glRasterPos2i(-20, 20);
		glColor3f(1, 1, 0);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, fase);
	}
	
	if(fim) {
		glRasterPos2i(-8, 0);
		glColor3f(1, 1, 0);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, final);
		velocidadeTiros = -1;
	}
	
	tiroSaiuDoMapa();
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

void mov(){
	for(int i = 1; i < TOTALTIROS; i+=2){
		normalbullet[i].x += -0.3;	
		normalbullet[i].y += -0.5;
	}
	
	for(int i = 0; i < TOTALTIROS; i+=2){
		normalbullet[i].x += 0.2;	
		normalbullet[i].y += -0.5;
	}
	
	for(int i = 0; i < TOTALTIROS; i+=9){	
		normalbullet[i].y += -0.5;
	}
}

int bateu(){
	for(int i = 0; i < TOTALTIROS; i++){
		if( ((normalbullet[i].x >= player1.x - 2) && (normalbullet[i].x <= player1.x + 2)) &&
			((normalbullet[i].y >= player1.y - 2) && (normalbullet[i].y <= player1.y + 2))		
		){
			finalScore = score;
			fim = true;
			PlaySound("C:\\Users\\rveri_000\\Desktop\\Programacao\\ibashou\\GameOver2.wav", NULL, SND_ASYNC|SND_FILENAME);
		}
	}
}

void time(int id){
	
	mov();
	bateu();
    glutPostRedisplay();
    glutTimerFunc(velocidadeTiros, time, 1);
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
	glutTimerFunc(60, time, 0);
	
    glutMainLoop();
    return 0;
}
