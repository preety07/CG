using namespace std;
#include<iostream>
#include<GL/glut.h>

//end points for line
//float ax=100, ay=130, bx=200, by=100; //m=dy/dx=30/100=0.3
float ax,ay,bx,by;

void draw_pixel(float x, float y)
{
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
}

void bres()
{
float dx=bx-ax, dy=by-ay;
float m=dy/dx;
float inc=1; //for positive slope
if(m<0) //negative slope
inc=-1;

dx=abs(dx);
dy=abs(dy);

if(abs(m)<1)
{
//left to right
    if(bx<ax)
    {
    swap(ax,bx);
    swap(ay,by);
    }
    //set starting endpoint to leftmost point
    float x=ax, y=ay;
    draw_pixel(x,y); //plot the first point
    float p=2*dy-dx;
    while(x<bx)
    {
    //run loop for dx times
    if(p<0) //decision value is negative
    p+=2*dy;
    else
    {
    y+=inc;
    p+=2*dy-2*dx;
    }
    x++;
    draw_pixel(x,y);
    } //end while
} //end if |m|<1

else //|m|>1
{
//bottom to top
if(by<ay)
{
swap(ax,bx);
swap(ay,by);
}
//set starting endpoint to bottom most point
float x=ax, y=ay;
draw_pixel(x,y); //plot the first point
float p=2*dx-dy;
while(y<by)
{
//run loop for dy times
if(p<0) //decision value is negative
p+=2*dx;
else
{
x+=inc;
p+=2*dx-2*dy;
}
y++;
draw_pixel(x,y);
} //end while
}
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,0,1);
bres();

//give end points
glColor3f(1,0,0);
glPointSize(3);
draw_pixel(ax,ay);
draw_pixel(bx,by);
glFlush();
}

void myinit()
{
glClearColor(1,1,1,1);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,499,0,499);
glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv)
{
cout<<"Enter the points (x1,y1) and (x2,y2) : ";
cin>>ax>>ay>>bx>>by;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutInitWindowSize(500,500);
glutCreateWindow("Bresenham's Line Drawing Algorithm");
myinit();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}