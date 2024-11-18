#include <GL/glut.h>
#include <math.h>

float angle1 = 0.0; // Angle for object 1 rotation
float angle2 = 0.0; // Angle for object 2 rotation

void drawCube() {
    // Define vertices of the cube
    GLfloat vertices[][3] = {
        {-0.15, -0.15, 0.15},
        {0.15, -0.15, 0.15},
        {0.15, 0.15, 0.15},
        {-0.15, 0.15, 0.15},
        {-0.15, -0.15, -0.15},
        {0.15, -0.15, -0.15},
        {0.15, 0.15, -0.15},
        {-0.15, 0.15, -0.15}
    };

    // Define edges of the cube
    GLint edges[][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0},
        {4, 5}, {5, 6}, {6, 7}, {7, 4},
        {0, 4}, {1, 5}, {2, 6}, {3, 7}
    };

    // Draw edges of the cube
    glBegin(GL_LINES);
    for (int i = 0; i < 12; ++i) {
        glVertex3fv(vertices[edges[i][0]]);
        glVertex3fv(vertices[edges[i][1]]);
    }
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw object 1
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0); // Red color
    glTranslatef(-0.5, 0.0, 0.0); // Move object 1 to the left
    glRotatef(angle1, 0.0, 0.0, 1.0); // Rotate object 1 clockwise along z-axis
    drawCube();
    glPopMatrix();

    // Draw object 2
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0); // Green color
    glTranslatef(0.5, 0.0, 0.0); // Move object 2 to the right
    glRotatef(-angle2, 0.0, 0.0, 1.0); // Rotate object 2 counter-clockwise along z-axis
    drawCube();
    glPopMatrix();

    // Draw object 3 (in y-axis)
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glTranslatef(0.0, 0.5, 0.0); // Move object 3 upward
    glRotatef(angle1, 0.0, 0.0, 1.0); // Rotate object 3 clockwise along z-axis
    drawCube();
    glPopMatrix();

    // Draw object 4 (in y-axis)
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0); // Yellow color
    glTranslatef(0.0, -0.5, 0.0); // Move object 4 downward
    glRotatef(-angle2, 0.0, 0.0, 1.0); // Rotate object 4 counter-clockwise along z-axis
    drawCube();
    glPopMatrix();

    glutSwapBuffers();
}

void timer(int value) {
    angle1 += 1.0; // Increment angle for object 1 rotation
    angle2 += 1.0; // Increment angle for object 2 rotation
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // Update rotation every 16 milliseconds (60 frames per second)
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotating Cubes");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0); // Start timer immediately
    glutMainLoop();
    return 0;
}

