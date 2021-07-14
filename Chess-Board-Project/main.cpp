#include<windows.h>
#include <GL/glut.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int x = 50, y = 50;
bool isBlack = true;

void whiteBox(int x, int y)
{
	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);
	glVertex2i(x, y + 50);
	glVertex2i(x + 50, y + 50);
	glVertex2i(x + 50, y);
	glEnd();
}

void blackBox(int x, int y)
{
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x, y + 50);
	glVertex2i(x + 50, y + 50);
	glVertex2i(x + 50, y);
	glEnd();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);

	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
		{
			isBlack = true;
		}
		else
		{
			isBlack = false;
		}

		for (int j = 0; j < 8; j++)
		{
			if (isBlack)
			{
				blackBox(x, y);
				isBlack = false;
			}
			else
			{
				whiteBox(x, y);
				isBlack = true;
			}
			x += 50;
		}
		y += 50;
		x = 50;
	}

	blackBox(100, 100);
	whiteBox(150, 100);
	glFlush();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);						// Initalise GLUT
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	// Set display mode

	glutInitWindowPosition(80, 100);				// Set window position
	glutInitWindowSize(900, 700);					// Set window size
	glutCreateWindow("Chess Board Project");	// Create display window

	init();							// Execute initialisation procedure
    glutDisplayFunc(myDisplay);// Send graphics to display window
	glutMainLoop();					// Display everything and wait

	return 0;
}

