using namespace std;
#include<iostream>
#include<GL/glut.h>
float v[4][3]={{0,0,1},{-1,-1,-1},{1,-1,-1},{0,1,-1}};
int k=0;
void triangle(float a[3],float b[3], float c[3]){
	glBegin(GL_TRIANGLES);
		glVertex3fv(a);
		glVertex3fv(b);
		glVertex3fv(c);
		glEnd();
}

void divide_triangle(float a[3],float b[3], float c[3], int k){
	if(k>0){
		//subdivide
		//mid point
		float m1[3],m2[3],m3[3];
		for(int i=0;i<3; i++){
			m1[i]=(a[i]+b[i]) /2; //a+b
			m2[i]=(a[i]+c[i])/2; //a+c
			m3[i]=(b[i]+c[i])/2; //b+c
		}
		divide_triangle(a,m1,m2,k-1);
		divide_triangle(b,m1,m3,k-1);
		divide_triangle(c,m2,m3,k-1);
	}
	else{
		triangle(a,b,c);
	}
	
}

void tetrahedron(){
	//bottom face
	glColor3f(0,0,0);
	divide_triangle(v[1],v[2],v[3],k);
	//red face
	glColor3f(1,0,0);
	divide_triangle(v[0],v[1],v[3],k);
	//blue face
	glColor3f(0,0,1);
	divide_triangle(v[0],v[2],v[3],k);
	//yellow face
	glColor3f(1,1,0);
	divide_triangle(v[0],v[1],v[2],k);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	//glRotatef(45,1,0,0); //45 about x
	tetrahedron();
	glPopMatrix();
	glFlush();

}
void myinit(){
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-2,2,-2,2,-2,2);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv){
	//get input from user here
	cout<<"Enter subdivisions:";
	cin>>k;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("3D Tansformation");	
	myinit();
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
