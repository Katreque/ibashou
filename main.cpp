#include <cstdlib>
#include <GL/glut.h>

void myReshape(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void myDisplay(void){
    glClearColor(0.5,0.5,0.5,1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(0,0);
    glutCreateWindow(argv[0]);

    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    glutMainLoop();
    return 0;
}
