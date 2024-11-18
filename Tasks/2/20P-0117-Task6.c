#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

float dx = 0.0; // Change in x
float dy = 0.0; // Change in y
float sx = 1.0; // Scale factor along x-axis
float sy = 1.0; // Scale factor along y-axis

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 1.0, 100.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(5.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Combined Transformation Matrix
    GLfloat combinedMatrix[16] = {
        sx, 0, 0, dx,
        0, sy, 0, dy,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    glMultMatrixf(combinedMatrix);

    // Radius and height of the cylinder
    float radius = 1.0;
    float height = 2.0;

    // Number of vertices to create the circles
    int numVertices = 50;

    // Angle increment for generating circle points
    float angleIncrement = 2 * PI / numVertices;

    // Drawing the top circle
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numVertices; ++i) {
        float angle = i * angleIncrement;
        glVertex3f(radius * cos(angle), height / 2, radius * sin(angle));
    }
    glEnd();

    // Drawing the bottom circle
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numVertices; ++i) {
        float angle = i * angleIncrement;
        glVertex3f(radius * cos(angle), -height / 2, radius * sin(angle));
    }
    glEnd();

    // Drawing the side lines
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    for (int i = 0; i < numVertices; ++i) {
        float angle1 = i * angleIncrement;
        float angle2 = (i + 1) * angleIncrement;

        // Top side face
        glVertex3f(radius * cos(angle1), height / 2, radius * sin(angle1));
        glVertex3f(radius * cos(angle2), height / 2, radius * sin(angle2));

        // Bottom side face
        glVertex3f(radius * cos(angle1), -height / 2, radius * sin(angle1));
        glVertex3f(radius * cos(angle2), -height / 2, radius * sin(angle2));

        // Connect top and bottom circles
        glVertex3f(radius * cos(angle1), height / 2, radius * sin(angle1));
        glVertex3f(radius * cos(angle1), -height / 2, radius * sin(angle1));
    }
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            dy += 0.1;
            break;
        case GLUT_KEY_DOWN:
            dy -= 0.1;
            break;
        case GLUT_KEY_LEFT:
            dx -= 0.1;
            break;
        case GLUT_KEY_RIGHT:
            dx += 0.1;
            break;
    }
    glutPostRedisplay();
}

void keyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
        case '+':
            sx += 0.1;
            sy += 0.1;
            break;
        case '-':
            sx -= 0.1;
            sy -= 0.1;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Cylinder Transformation");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboardFunc);
    glutMainLoop();
    return 0;
}

