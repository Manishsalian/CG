#include <GL/glut.h>
#include <math.h>

float angle = 0.0;
float posX = -0.8, posY = 0.0;
float speedX = 0.01;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(posX, posY, 0.0);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.1, -0.1);
    glVertex2f(0.1, -0.1);
    glVertex2f(0.0, 0.1);
    glEnd();
    glPopMatrix();
    glPushMatrix();
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

void update(int value) {
    angle += 2.0;
    if (angle > 360) {
        angle -= 360;
    }
    posX += speedX;
    if (posX > 0.8 || posX < -0.8) {
        speedX = -speedX;
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simple Animation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutMainLoop();
    return 0;
}

