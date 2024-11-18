#include <GL/glut.h>

float rotate1 = 0.0; // Angle for rotation of the sun
float rotate2 = 0.0; // Angle for rotation of the Earth
float rotate3 = 0.0; // Angle for rotation of the moon

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Set up the camera position
    gluLookAt(0.0, 0.0, 5.0, // Eye position (x, y, z)
              0.0, 0.0, 0.0, // Look-at position (x, y, z)
              0.0, 1.0, 0.0); // Up direction (x, y, z)

    // Disable lighting
    glDisable(GL_LIGHTING);

    // Set clear color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Draw the sun (spherical object)
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.0f); // Orange color for sun
    glRotatef(rotate1, 0, 0, 1); // Rotate the sun along its own axis
    glutWireSphere(0.4, 25, 25); // Draw a wireframe sphere for the sun
    glPopMatrix();

    // Draw the Earth
    glPushMatrix();
    glColor3f(0.f, 0.f, 1.f); // Blue color for Earth
    glRotatef(rotate2, 0, 0, 1); // Rotate the Earth along its own axis
    glTranslatef(0.4, 0.4, 0); // Translate the Earth to the orbit radius
    glRotatef(rotate2, 0, 0, 1); // Rotate the Earth around the sun
    glutWireSphere(.1, 20, 20); // Draw a wireframe sphere for the Earth
    glPopMatrix();

    // Draw the moon
    glPushMatrix();
    glColor3f(0.5f, 0.5f, 0.5f); // Gray color for moon
    glRotatef(rotate3, 0, 0, 1); // Rotate the moon along its own axis
    glTranslatef(0.5, 0.5, 0); // Translate the moon to the orbit radius
    glRotatef(rotate3, 0, 0, 1); // Rotate the moon around the Earth
    glutWireSphere(.05, 20, 20); // Draw a wireframe sphere for the moon
    glPopMatrix();

    glutSwapBuffers();
}

void timer(int value) {
    rotate1 += 1.0; // Increment rotation angle for the sun
    rotate2 += 5.0; // Increment rotation angle for the Earth (adjust speed as needed)
    rotate3 += 10.0; // Increment rotation angle for the moon (adjust speed as needed)
    if (rotate1 > 360.0) {
        rotate1 -= 360.0; // Keep rotation angle within 0 to 360 degrees
    }
    if (rotate2 > 360.0) {
        rotate2 -= 360.0; // Keep rotation angle within 0 to 360 degrees
    }
    if (rotate3 > 360.0) {
        rotate3 -= 360.0; // Keep rotation angle within 0 to 360 degrees
    }
    glutPostRedisplay(); // Request a redraw
    glutTimerFunc(16, timer, 0); // Call timer function again after 16 milliseconds (for smooth animation)
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0); // Set perspective projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Solar System Simulation");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0); // Start timer immediately
    glutMainLoop();
    return 0;
}

