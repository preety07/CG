#include<GL/glut.h>
float theta[3]={0, 0, 0};
int axis=2;
void display(){
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glPushMatrix();
glColor3f(1, 0, 0);
glRotatef(theta[0], 1, 0, 0);
glRotatef(theta[1], 0, 1, 0);
glRotatef(theta[2], 0, 0, 1);
glutSolidCube(2);
glPopMatrix();
glutSwapBuffers();
}

void myinit(){
glMatrixMode(GL_PROJECTION);
glOrtho(-5, 5, -5, 5, -20, 20);
glMatrixMode(GL_MODELVIEW);
}

void idle(){
theta[axis] +=0.4;
if(theta[axis] >=360) theta[axis]-=360;
glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
axis=0;
else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
axis=1;
else if(button==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
axis=2;
glutPostRedisplay();
}

int main(int argc, char **argv){

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
glutInitWindowSize(500, 500);
glutCreateWindow("Annimation of simple objects");
myinit();
glutDisplayFunc(display);
glutIdleFunc(idle);
glutMouseFunc(mouse);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;
}