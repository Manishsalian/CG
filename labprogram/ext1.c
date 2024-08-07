#include<stdio.h>
#include<GL/glut.h>

GLint xstart,ystart,xend,yend;

void setPixel(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}

void bresnamsAlgorithm(int X_Start,int Y_Start,int X_End,int Y_End)
{
	int dx=X_End-X_Start;
	int dy=Y_End-Y_Start;
	int D=2*dy-dx;
	int y=Y_Start;
	
	for(int x=X_Start; x<=X_End;x++)
	{
		setPixel(x,y);
		
		if(D>0)
		{
			y++;
			D=D+(2*(dy-dx));
			
		}
		else
		{
			D=D+2*dy;
		}
																								 																																																																																																																																																																																																																																																																																											
	}
}	
	
	void init()
	{
		glClearColor(1.0,1.0,1.0,1.0);
		glColor3f(0.0,0.0,0.0);
		gluOrtho2D(0,200.0,0,200.0);
		
	}	
	
	void display()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		bresnamsAlgorithm(xstart,ystart,xend,yend);
		glFlush();
		
	}

int main(int argc ,char** argv)
{
	printf("Line Drawing algorithm");
	printf("Enter value for X0 and YO");
	scanf("%d%d",&xstart,&ystart);
	printf("Enter value for X1 and Y1");
	scanf("%d%d",&xend,&yend);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Bresnhams line drawing algorithm");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
																																																						
	
																																																																																																																																
