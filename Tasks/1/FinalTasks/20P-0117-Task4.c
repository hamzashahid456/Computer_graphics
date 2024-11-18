#include <GL/glut.h>
#include <math.h>

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 1.0, 100.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    // Radius of the sphere
    float radius = 25.0;

    // Number of slices and stacks (divisions along theta and phi)
    int slices = 36;
    int stacks = 18;

    // Angle increments for theta and phi
    float thetaIncrement = 2.0 * M_PI / slices;
    float phiIncrement = M_PI / stacks;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    for (int i = 0; i < slices; ++i) {
        float theta0 = i * thetaIncrement;
        float theta1 = (i + 1) * thetaIncrement;

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= stacks; ++j) {
            float phi = j * phiIncrement;

            // Vertex 1
            float x1 = radius * sin(phi) * cos(theta0);
            float y1 = radius * sin(phi) * sin(theta0);
            float z1 = radius * cos(phi);
            glVertex3f(x1, y1, z1);

            // Vertex 2
            float x2 = radius * sin(phi) * cos(theta1);
            float y2 = radius * sin(phi) * sin(theta1);
            float z2 = radius * cos(phi);
            glVertex3f(x2, y2, z2);
        }
        glEnd();
    }

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sphere Drawing - Polar Method");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

