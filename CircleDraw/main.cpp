#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

float x=0,y,p,xc,yc;
int r;

void circleDraw(void)
{
    glClear (GL_COLOR_BUFFER_BIT);


    glBegin(GL_POINTS);

    printf("Starting point(x,y) : %0.2f , %0.2f \n",x,y);

    p=1-r;
    printf("Initial Decision Parameter: %0.2f \n",p);
    printf("\n");

    while((x<y))
    {

        if(p<0)
        {
            x=x+1;
            y=y;
            printf("Coordinates: Xk+1: %0.2f && Yk+1: %0.2f\n",x,y);
            p=p+(2*x)+1;
        }


        else
        {
            x=x+1;
            y=y-1;
            printf("Coordinates: Xk+1: %0.2f && Yk+1: %0.2f\n",x,y);
            p=p+(2*x)+1-(2*y);

        }
/*
        //Center Point Circle Draw
        glColor3f (0.0, 1.0, 0.0);
        glVertex3f (((x)), ((y)), 0.0);
        glVertex3f (((y)), ((x)), 0.0);
        glVertex3f ((-(x)), (-(y)), 0.0);
        glVertex3f ((-(x)), ((y)), 0.0);
        glVertex3f (((x)), (-(y)), 0.0);
        glVertex3f (((y)), (-(x)), 0.0);
        glVertex3f ((-(y)), (-(x)), 0.0);
        glVertex3f ((-(y)), ((x)), 0.0);

         //Given Point Circle Draw
        glColor3f (1.0, 0.0, 0.0);
        glVertex3f (((x+xc)), ((y+yc)), 0.0);
        glVertex3f (((y+xc)), ((x+yc)), 0.0);
        glVertex3f (((-x+xc)), ((-y+yc)), 0.0);
        glVertex3f (((-x+xc)), ((y+yc)), 0.0);
        glVertex3f (((x+xc)), ((-y+yc)), 0.0);
        glVertex3f (((y+xc)), ((-x+yc)), 0.0);
        glVertex3f (((-y+xc)), ((-x+yc)), 0.0);
        glVertex3f (((-y+xc)), ((x+yc)), 0.0);
        */

        //Create Moon
         glColor3f (1.0, 0.0, 0.0);


        glVertex3f (((-y+xc)), ((x+yc)), 0.0);
        glVertex3f (((-y+xc)), ((-x+yc)), 0.0);
        glVertex3f (((-x+xc)), ((-y+yc)), 0.0);
        glVertex3f (((x+xc)), ((-y+yc)), 0.0);

        glVertex3f ((-(y)), ((x)), 0.0);
        glVertex3f ((-(y)), (-(x)), 0.0);
        glVertex3f ((-(x)), (-(y)), 0.0);
        glVertex3f (((x)), (-(y)), 0.0);

    }

    glEnd();
    glFlush ();
}
void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0,-100.0, 100.0, -100.0, 100.0);
}
int main(int argc, char** argv)
{
    printf("Enter coordinate Xc:");
    scanf("%f",&xc);
    printf("Enter coordinate Yc:");
    scanf("%f",&yc);
    printf("Enter radius: ");
    scanf("%d",&r);
    y=r;


    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (500, 100);
    glutCreateWindow ("Mid Point Circle Draw(Center point(0,0)");

    init ();
    glutDisplayFunc(circleDraw);
    glutMainLoop();
    return 0;
}

