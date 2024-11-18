#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 1.0, 100.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(5.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

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

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Cylinder Side View");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}


/*

In this implementation, I used 3 for loops:

Loop to generate vertices for the top circle.
Loop to generate vertices for the bottom circle.
Loop to generate vertices for the side faces of the cylinder.
You could potentially reduce the number of for loops by combining some of the operations. For example, you could generate both the top and bottom circles within a single loop. However, this would make the code less readable and harder to maintain. In this case, it's better to prioritize code clarity and readability over reducing the number of loops.

*/

