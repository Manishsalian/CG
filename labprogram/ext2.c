#include<GL/glut.h>

GLfloat red=1.0, green=0.0,blue=0.0;


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(red,green,blue);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5,-0.5);
	glVertex2f(0.5,-0.5);
	glVertex2f(0.0,0.5);
	glEnd();
	glFlush();
}

void menu(int option)
{
	switch(option)
	{
		case 1:
		red=1.0, green=0.0,blue=0.0;
		break;
		
		case 2:
		red=0.0, green=1.0,blue=0.0;
		break;
		
		case 3:
		red=0.0, green=0.0,blue=1.0;
		break;
		
		case 4:
		red=1.0, green=1.0,blue=0.0;
		break;
		
		case 5:
		exit(0);
		
	}
	
	glutPostRedisplay(); // Request a redraw
	
}

void createmenu()
{
	int submenu_id=glutCreateMenu(menu);
	glutAddMenuEntry("red",1);
	glutAddMenuEntry("Green",2);
	glutAddMenuEntry("blue",3);
	glutAddMenuEntry("Yellow",4);
	
	int menu_id=glutCreateMenu(menu);
	
	glutAddSubMenu("Change Color",submenu_id);
	glutAddMenuEntry("exit",5);
	
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
}

int main(int argc, char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("2D operations");
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
    	createmenu(); // Create the menu
    	glutDisplayFunc(display); // Set the display callback
    	glutMainLoop(); // Enter the GLUT event processing loop
    	return 0;
}



















































