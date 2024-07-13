#include <GL/glut.h>

// Function to initialize OpenGL
void initOpenGL() {
    glEnable(GL_DEPTH_TEST);
}

// Function to draw a 3D colored cube with gradient effect
void drawCube() {
    glBegin(GL_QUADS);

    // Front face (gradient)
    glColor3f(1.0, 0.0, 0.0); glVertex3f(-0.5, -0.5, 0.5);  // Bottom-left
    glColor3f(0.0, 1.0, 0.0); glVertex3f(0.5, -0.5, 0.5);   // Bottom-right
    glColor3f(0.0, 0.0, 1.0); glVertex3f(0.5, 0.5, 0.5);    // Top-right
    glColor3f(1.0, 1.0, 0.0); glVertex3f(-0.5, 0.5, 0.5);   // Top-left

    // Back face (gradient)
    glColor3f(1.0, 0.0, 1.0); glVertex3f(-0.5, -0.5, -0.5); // Bottom-left
    glColor3f(0.0, 1.0, 1.0); glVertex3f(0.5, -0.5, -0.5);  // Bottom-right
    glColor3f(0.5, 0.0, 0.5); glVertex3f(0.5, 0.5, -0.5);   // Top-right
    glColor3f(1.0, 1.0, 0.5); glVertex3f(-0.5, 0.5, -0.5);  // Top-left

    // Top face (gradient)
    glColor3f(0.5, 0.5, 0.5); glVertex3f(-0.5, 0.5, -0.5);  // Top-left
    glColor3f(0.5, 0.0, 0.0); glVertex3f(0.5, 0.5, -0.5);   // Top-right
    glColor3f(0.5, 0.5, 1.0); glVertex3f(0.5, 0.5, 0.5);    // Bottom-right
    glColor3f(0.0, 0.5, 0.5); glVertex3f(-0.5, 0.5, 0.5);   // Bottom-left

    // Bottom face (gradient)
    glColor3f(0.5, 0.5, 0.0); glVertex3f(-0.5, -0.5, -0.5); // Top-left
    glColor3f(1.0, 0.5, 0.0); glVertex3f(0.5, -0.5, -0.5);  // Top-right
    glColor3f(0.0, 0.5, 1.0); glVertex3f(0.5, -0.5, 0.5);   // Bottom-right
    glColor3f(0.5, 0.0, 0.5); glVertex3f(-0.5, -0.5, 0.5);  // Bottom-left

    // Right face (gradient)
    glColor3f(1.0, 0.0, 0.5); glVertex3f(0.5, -0.5, -0.5);  // Bottom-left
    glColor3f(0.0, 1.0, 0.5); glVertex3f(0.5, 0.5, -0.5);   // Top-left
    glColor3f(0.5, 1.0, 0.0); glVertex3f(0.5, 0.5, 0.5);    // Top-right
    glColor3f(0.5, 0.0, 1.0); glVertex3f(0.5, -0.5, 0.5);   // Bottom-right

    // Left face (gradient)
    glColor3f(0.5, 0.5, 0.5); glVertex3f(-0.5, -0.5, -0.5); // Bottom-left
    glColor3f(0.5, 0.0, 1.0); glVertex3f(-0.5, 0.5, -0.5);  // Top-left
    glColor3f(0.0, 1.0, 1.0); glVertex3f(-0.5, 0.5, 0.5);   // Top-right
    glColor3f(1.0, 0.5, 0.5); glVertex3f(-0.5, -0.5, 0.5);  // Bottom-right

    glEnd();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up the camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0,   // eye position
              0.0, 0.0, 0.0,   // center position (look at)
              0.0, 1.0, 0.0);  // up direction

    // Rotate the cube
    glRotatef(30.0, 1.0, 0.0, 0.0); // Rotate around x-axis
    glRotatef(45.0, 0.0, 1.0, 0.0); // Rotate around y-axis

    drawCube();
    glutSwapBuffers();
}

// Reshape callback function
void reshape(int width, int height) {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 10.0);

    glMatrixMode(GL_MODELVIEW);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Colored 3D Cube");

    initOpenGL();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}

