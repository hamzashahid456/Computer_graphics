#include <GL/glut.h>

#define WIDTH 8
#define HEIGHT 8

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    int color = 0; // 0 for white, 1 for black

    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            if (color == 0)
                glColor3f(1.0, 1.0, 1.0); // White
            else
                glColor3f(0.0, 0.0, 0.0); // Black

            glBegin(GL_QUADS);
            glVertex2i(i, j);
            glVertex2i(i + 1, j);
            glVertex2i(i + 1, j + 1);
            glVertex2i(i, j + 1);
            glEnd();

            color = 1 - color; // Toggle color
        }
        color = 1 - color; // Start each row with opposite color
    }

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Chessboard");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

