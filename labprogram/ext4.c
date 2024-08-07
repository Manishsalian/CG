#include<GL/glut.h>

float vertices[8][3] ={ {-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}

};

float colors[8][3] ={ {1.0,0.0,0.0}, {0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,1.0,0.0},{1.0,0.0,1.0},{0.0,1.0,1.0},{1.0,1.0,1.0},{0.5,0.9,0.1}

};
float tx=0.0, ty=0.0, tz=-5.0, sx=1.0, sy=1.0, sz=1.0, anglex=0.0, angley=0.0, anglez=0.0;
void polygon(int a, int b,int c,int d)
{
	glBegin(GL_POLYGON);
	glColor3fv(colors[a]);
	glVertex3fv(vertices[a]);
	
	glColor3fv(colors[b]);
	glVertex3fv(vertices[b]);
	
	glColor3fv(colors[c]);
	glVertex3fv(vertices[c]);
	
	glColor3fv(colors[d]);
	glVertex3fv(vertices[d]);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	glTranslatef(tx,ty,tz);
	glRotatef(anglex,1.0,0.0,0.0);
	glRotatef(angley,0.0,1.0,0.0);
	glRotatef(anglez,0.0,0.0,1.0);
	glScalef(sx,sy,sz);
	
	polygon(0,3,2,1);
	polygon(2,3,7,6);
	polygon(0,4,7,3);
	polygon(1,2,6,5);
	polygon(4,5,6,7);
	polygon(0,1,5,4);
	
	glFlush();
	
}

void changeColors(int option) {
    switch(option) {
        case 1:
            colors[0][0] = 1.0; colors[0][1] = 0.0; colors[0][2] = 0.0;
            colors[1][0] = 0.0; colors[1][1] = 1.0; colors[1][2] = 0.0;
            colors[2][0] = 1.0; colors[2][1] = 1.0; colors[2][2] = 0.0;
            colors[3][0] = 1.0; colors[3][1] = 0.0; colors[3][2] = 1.0;
            colors[4][0] = 1.0; colors[4][1] = 1.0; colors[4][2] = 1.0;
            colors[5][0] = 0.9; colors[5][1] = 0.5; colors[5][2] = 0.1;
            break;
        case 2:
            colors[0][0] = 1.0; colors[0][1] = 0.0; colors[0][2] = 0.0;
            colors[1][0] = 0.0; colors[1][1] = 1.0; colors[1][2] = 0.0;
            colors[2][0] = 0.0; colors[2][1] = 0.0; colors[2][2] = 1.0;
            colors[3][0] = 1.0; colors[3][1] = 0.0; colors[3][2] = 1.0;
            colors[4][0] = 1.0; colors[4][1] = 1.0; colors[4][2] = 0.0;
            colors[5][0] = 0.0; colors[5][1] = 1.0; colors[5][2] = 1.0;
            break;
    }
    glutPostRedisplay();
}
void createMenu() {
    glutCreateMenu(changeColors);
    glutAddMenuEntry("Color Combination 1", 1);
    glutAddMenuEntry("Color Combination 2", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'a': tx -= 0.1; break;
        case 'd': tx += 0.1; break;
        case 'w': ty += 0.1; break;
        case 's': ty -= 0.1; break;
        case 'q': tz += 0.1; break;
        case 'e': tz -= 0.1; break;
        case 'j': anglex -= 5.0; break;
        case 'l': anglex += 5.0; break;
        case 'i': angley -= 5.0; break;
        case 'k': angley += 5.0; break;
        case 'u': anglez -= 5.0; break;
        case 'o': anglez += 5.0; break;
        case 'z': sx -= 0.1; break;
        case 'x': sx += 0.1; break;
        case 'c': sy -= 0.1; break;
        case 'v': sy += 0.1; break;
        case 'b': sz -= 0.1; break;
        case 'n': sz += 0.1; break;
    }
    glutPostRedisplay();
}

void init() {
    glClearColor(1.0,1.0,1.0,1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,1.0,1.0,100);
    glMatrixMode(GL_MODELVIEW);
    
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Cube with Color Menu and Transformations");
    init();
    glutDisplayFunc(display);
    createMenu();
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
