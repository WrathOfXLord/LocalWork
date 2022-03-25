#include <iostream>
#include "GL/freeglut.h"
#include <vector>
#include <numbers>
#include <cmath>
#include <iomanip>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;
using numbers::pi;

const int WIDTH {500}, HEIGHT {500};

int oldX, oldY, dx, dy;
double scale {1};

typedef std::chrono::high_resolution_clock::time_point timer_point;

void drawSphere(double radius, double xPos, double yPos, double zPos)
{
    glBegin(GL_TRIANGLES);
    for(size_t i {0}; i < 360; ++i)
    {
        for(size_t j {0}; j < 180; ++j)
        {
            double x {radius * cos(i * pi / 180) * sin(j * pi / 180) + xPos};
            double y {radius * sin(i * pi / 180) * sin(j * pi / 180) + yPos};
            double z {radius * cos(j * pi / 180) + zPos};
            
            glVertex3d(x, y, z);
        }
    }
    glEnd();
}

void drawRect()
{
    glColor4d(1.0, 1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3d(-3, -3, -3);
    glVertex3d(-3, 3, -3);
    glVertex3d(3, 3, -3);
    glVertex3d(3, -3, -3);
    glVertex3d(3, -3, 3);
    glVertex3d(3, 3, 3);
    glVertex3d(-3, 3, 3);
    glVertex3d(-3, -3, 3);

    glEnd();

}

void showScreen()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
    // glEnable(GL_LIGHTING);
    // glEnable(GL_LIGHT0);
    // glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, 5/3, 1, 20);
    glPushMatrix();
    glLoadIdentity();
    glScaled(scale , scale, scale);
    glRotated(dx, 0, 1, 0);
    glRotated(dy, 1, 0, 0);
    glColor4d(1, 1, 1, 1);
    //drawRect();
    timer_point t1 {high_resolution_clock::now()};
    //glutSolidSphere(1, 180, 360);
    drawSphere(1, 0, 0, 0);
    timer_point t2 {high_resolution_clock::now()};
    duration <double> elapsed_time = duration_cast <duration<double>>(t2 - t1);
    cout << "elapsed time is : " << elapsed_time.count() << " seconds" << endl;
    glPopMatrix();
    glutSwapBuffers();
}

void motion(int x, int y)
{
    dx += x - oldX;
    dy += y - oldY;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    oldX = x;
    oldY = y;
    glutMotionFunc(motion);
}

void mouseWheel(int wheel, int direction, int x, int y)
{
    if(direction == 1)
        scale += 0.05;
    else if(direction == -1)
        scale -= 0.05;

    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sphere by Formula");
    glutDisplayFunc(showScreen);
    glutIdleFunc(showScreen);
    glutMouseFunc(mouse);
    glutMouseWheelFunc(mouseWheel);
    glutMainLoop();

    return 0;
}