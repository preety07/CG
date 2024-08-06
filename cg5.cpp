#include<GL/glut.h>

float thetax=0,thetay=0,thetaz=0;
int flag=0;
int axis=0;

void car(){
	glColor3f(1,0,0);
	glutWireCube(1);
	glColor3f(1,1,0);
	
	glColor3f(1,1,0);
	glPushMatrix();
	glTranslatef(0.75,-0.25,0);
	glScalef(0.5,0.5,1);
	glutWireCube(1);
	glPopMatrix();
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
		glRotatef(thetax,1,0,0);
		glRotatef(thetay,0,1,0);
		glRotatef(thetaz,0,0,1);
		car();
	glPopMatrix();
	
	
	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glOrtho(-2,2,-2,2,-2,2);
	glMatrixMode(GL_MODELVIEW);
}
void mouse(int button, int state, int x, int y){
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		thetax+=0.4;
	else if(button==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
		thetay+=0.4;
	else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
		thetaz+=0.4;
		
	if(thetax>=360) thetax-=360;
	if(thetay>=360) thetay-=360;
	if(thetaz>=360) thetaz-=360;
	glutPostRedisplay();
	
}
int main(int argc,char  **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("3D Transformation");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}