#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float x1,y1,x2,y2,m,i,j,p;
int dx,dy;
void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POINTS);

    p=(2*dy)-dx;

    for(i=x1, j=y1; i<x2,j>y2; )
    {
        if(p>=0)
        {
            i=i+1;
            j=j+1;

            printf("\tValue of X1 : %0.2f && Value of Y1: %0.2f\n",i,j);
            glVertex3f ((i), (j), 0.0);
            p=p+(2*dy)-(2*dx);
        }
        else if(p<0)
        {
            i=i+1;
            if(i>x2)
            {
                break;
            }
            printf("\tValue of X1 : %0.2f && Value of Y1: %0.2f\n",i,j);
            glVertex3f (i,j, 0.0);
            p=p+(2*dy);

        }
    }
    glEnd();

    glFlush ();
}
void init (void)
{

    glClearColor (1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 400, 0.0, 400.0,-400.0,400.0);
}


int main(int argc, char** argv)
{
    printf("Enter first point X1: ");
    scanf("%f",&x1);
    printf("Enter first point Y1: ");
    scanf("%f",&y1);

    printf("Enter End point X2: ");
    scanf("%f",&x2);
    printf("Enter End point Y1: ");
    scanf("%f",&y2);
    dx=x2-x1;
    dy=y2-y1;
    printf("Show dx: %d\n",dx);
    printf("Show dy: %d\n",dy);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 700);
    glutInitWindowPosition (500, 100);
    glutCreateWindow ("Bresenham Line Drawing Algorithm (Task-3)");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

