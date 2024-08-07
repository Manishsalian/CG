#include <stdio.h>
#include<GL/glut.h>

float r=1.0, g=0.0, b=0.0;

float sx=1.0, sy=1.0, tx=0.0, ty=0.0, angle=0.0;

void display()
{
    	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	
	glTranslatef(tx,ty,0.0);
	glRotatef(angle,0.0,0.0,1.0);
	glScalef(sx,sy,1.0); // Error: This should be (sx, sy, 1.0), not (sx, sy, 0.0)
	
	glColor3f(r,g,b);
	
	glBegin(GL_POLYGON);
	
	glVertex2f(-0.5,-0.5);
	glVertex2f(0.5,-0.5);
	glVertex2f(0.5,0.5);
	glVertex2f(-0.5,0.5);
	
	glEnd();
	
	glPopMatrix();
	
	glFlush();
}

void menu(int option)
{
	switch(option)
	{
		case 1: r=1.0, g=0.0, b=0.0; break; // Red
		case 2: r=0.0, g=1.0, b=0.0; break; // Green
		case 3: r=0.0, g=0.0, b=1.0; break; // Blue
		case 4: r=0.7, g=0.0, b=0.5; break; // Random Purple
        // Error: Menu option 4 should have been 4 instead of 3 in the AddMenuEntry function
	}
	
	glutPostRedisplay();
}

void createmenu()
{
	glutCreateMenu(menu);
	glutAddMenuEntry("Red",1);
	glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);
    glutAddMenuEntry("Random", 4); // Error: The menu option here should be 4, not 3
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void keyboard(unsigned char key, int x , int y)
{
	switch(key)
	{
		case 'a': tx-=0.1; break; // Translate left
		case 's':  tx+=0.1; break; // Translate right
		case 'w': ty+=0.1; break; // Translate up
		case 'q': ty-=0.1; break; // Translate down
		case 'e': angle-=5.0; break; // Rotate counterclockwise
		case 'r':  angle+=5.0; break; // Rotate clockwise
		case 'm': sx-=0.1; break; // Scale down x
		case 'n': sx+=0.1; break; // Scale up x
		case 'z': sy-=0.1; break; // Scale down y
		case 'x': sy+=0.1; break; // Scale up y
        // Error: The cases w and q were inverted in functionality compared to the explanation.
	}
	
	glutPostRedisplay();
}

void init()
{
	glClearColor(1.0,1.0,1.0,1.0); // White background
    // Error: The parameters in gluOrtho2D were reversed
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(100, 100);
    
    glutCreateWindow("2D operations");
    init();
    createmenu();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
