#include<GL/glut.h>


float posx=-0.8 , posy=0.0, angle=0.0, speedx=0.01;

void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPushMatrix();
	
	glTranslatef(posx,posy,0.0);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,0.5,0.1);
	glVertex2f(-0.1,-0.1);
	glVertex2f(0.1,-0.1);
	glVertex2f(0.0,0.1);
	glEnd();
	
	glPopMatrix();
	
	glPushMatrix();

    // Rotate and draw the square
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.1, -0.1);
    glVertex2f(0.1, -0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(-0.1, 0.1);
    glEnd();
	
	glPopMatrix();
	
	glutSwapBuffers();
	
	
}

void update()
{

	posx+=speedx;
	
	if(posx>0.8 || posx<-0.8)
	{
		speedx=-speedx;
	}
	
	angle+=2.0;
	
	if(angle>360)
	{
	angle-=360;
	}
	
	glutPostRedisplay();
	
	glutTimerFunc(16,update,0);
	
}
	
	
int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);

    // Create the window
    glutCreateWindow("Simple Animation");

    // Initialize OpenGL
    init();

    // Set the display function
    glutDisplayFunc(display);

    // Set the update function
    glutTimerFunc(16, update, 0);

    // Start the main loop
    glutMainLoop();

    return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
