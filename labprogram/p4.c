#include <GL/glut.h>
#include <math.h>

// Angle for rotating the object
float angle = 0.0f;

// Scaling factor for the object
float scale = 1.0f;

// Translation values for the object
float translateX = 0.0f;
float translateY = 0.0f;

// Current object to transform: 0 for square, 1 for triangle
int currentObject = 0;

// Function to initialize OpenGL settings
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Function to handle rendering the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Apply translation
    glTranslatef(translateX, translateY, 0.0f);

    // Apply rotation
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    // Apply scaling
    glScalef(scale, scale, 1.0f);

    if (currentObject == 0) {
        // Draw a simple square
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(-0.5f, 0.5f);
        glEnd();
    } else if (currentObject == 1) {
        // Draw a simple triangle
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glEnd();
    }

    glutSwapBuffers();
}

// Function to handle window resize
void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
}

// Function to handle key press events
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            angle += 5.0f;
            break;
        case 'd':
            angle -= 5.0f;
            break;
        case 'w':
            scale += 0.1f;
            break;
        case 's':
            scale -= 0.1f;
            break;
        case 'x':
            translateX += 0.1f;
            break;
        case 'z':
            translateX -= 0.1f;
            break;
        case 'y':
            translateY += 0.1f;
            break;
        case 'h':
            translateY -= 0.1f;
            break;
        case 'q':
            exit(0);
        case '1':
            currentObject = 0;
            break;
        case '2':
            currentObject = 1;
            break;
    }
    glutPostRedisplay();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("2D Transformations on Basic Objects");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    initGL();
    glutMainLoop();
    return 0;
}

