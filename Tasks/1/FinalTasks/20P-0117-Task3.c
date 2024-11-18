#include <GL/glut.h>
#include <math.h>

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_POINTS);

    // Radius of the circle
    float radius = 50.0;

    // Center of the circle
    float centerX = 0.0;
    float centerY = 0.0;

    // Number of points to draw the circle
    int numPoints = 360;

    for (int i = 0; i < numPoints; ++i) {
        // Calculate the angle
        float angle = 2.0 * 3.14159 * i / numPoints;

        // Calculate the x and y coordinates using polar method
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);

        // Plot the point
        glVertex2f(x, y);
    }

    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle Drawing - Polar Method");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

