#include <windows.h>
#include <GL/glut.h>
#include<iostream>
#include<stdlib.h>

#ifdef __APPLE__
#include<openGL/openGL.h>
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

using namespace std;

float ballX = -0.3f;
float ballY = 0.0f;
float ballZ = -1.0f;

static int flag=1;

void drawBall(void) {

        glColor3f(0.0, 0.0, 1.0);
        glTranslatef(ballX,ballY,ballZ);
        glutSolidSphere (0.1, 10, 10);

}

void keyPress(int key, int x, int y)
{
      if(key==GLUT_KEY_RIGHT)
        ballX -= 0.05f;
    if(key==GLUT_KEY_LEFT)
        ballX  += 0.05f;

    glutPostRedisplay();
}

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}


void handleResize(int w, int h) {

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);


    glLoadIdentity();
    gluPerspective(45.0,
                   (double)w / (double)h,
                   1.0,
                   200.0);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    drawBall();


    glutSwapBuffers();
}


void update(int value) {
    if(flag)
    {
    ballX += 0.001f;
       if(ballX>0.3)
       {
           flag=0;

       }
    }
    if (!flag)
    {
        ballX -= 0.001f;
        if(ballX<-0.3)
       {
           flag=1;

       }
    }

    glutPostRedisplay();


    glutTimerFunc(25, update, 0);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(600,600);

    glutCreateWindow("Moving Object");

    initRendering();

    glutDisplayFunc(drawScene);

    glutSpecialFunc(keyPress);
    glutReshapeFunc(handleResize);


    glutTimerFunc(25, update, 0);

    glutMainLoop();

    return(0);
}
