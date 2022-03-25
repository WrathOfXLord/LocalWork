#include <iostream>
#include <numbers>
#include <GL/freeglut.h>
#include <cmath>

using namespace std;
using numbers::pi;

const int WIDTH {500}, HEIGHT {500};
int key_press_axisY {0};
int key_press_axisX {0};
bool buffer[256] {true};

void draw_axis()
{
    //x-y axis
    glColor4d(1, 0.8, 0, 1);

    glPushMatrix();
    glBegin(GL_LINES);    
    glVertex3d(-19.0, 0.0, 0.0);
    glVertex3d(19.0, 0.0, 0.0);

    glVertex3d(0.0, -19.0, 0.0);
    glVertex3d(0.0, 19.0, 0.0);
    glEnd();
    glPopMatrix();

    //x-y axis points
    glPushMatrix();
    for(GLdouble i {-18}; i != 19; ++i)
    {
        glBegin(GL_LINES);
        glVertex3d(i, -0.125, 0);
        glVertex3d(i, 0.125, 0);
        glEnd();
    }

    for(GLdouble i {-18}; i != 19; ++i)
    {
        glBegin(GL_LINES);
        glVertex3d(-0.125, i, 0);
        glVertex3d(0.125, i, 0);
        glEnd();
    }
    glPopMatrix();

    //for axis arrows
    /************************************************************************
     * ötelemek istediğin şekli istediğin yerde oluşturmak yerine           *
     * şeklin pivot noktasını tam orijin üzerine yerleştirerek              *
     * istediğimiz yerin koordinatına öteliyoruz, ardından dönme açısını ve *
     * dönme eksenini veriyoruz. bu kadar.                                  *
     * **********************************************************************/
    
    glColor4d(1, 0.8, 0, 1);

    glPushMatrix();
    glTranslated(19, 0, 0);
    glRotated(-30, 0, 0, 1);
    glBegin(GL_LINES);
    glVertex3d(-2, 0, 0);
    glVertex3d(0, 0, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(19, 0, 0);
    glRotated(30, 0, 0, 1);
    glBegin(GL_LINES);
    glVertex3d(-2, 0, 0);
    glVertex3d(0, 0, 0);
    glEnd();
    glPopMatrix();

    glColor4d(1, 0.8, 0, 1);

    glPushMatrix();
    glTranslated(0, 19, 0);
    glRotated(30, 0, 0, 1);
    glBegin(GL_LINES);
    glVertex3d(0 ,-2 ,0);
    glVertex3d(0 ,0 ,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 19, 0);
    glRotated(-30, 0, 0, 1);
    glBegin(GL_LINES);
    glVertex3d(0 ,-2 ,0);
    glVertex3d(0 ,0 ,0);
    glEnd();
    glPopMatrix();

}

void draw_circle()
{
    const int X_POS {5};
    const int Y_POS {5};
    const unsigned int RADIUS {5};

    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslated(key_press_axisX, key_press_axisY, 0);
    glBegin(GL_POLYGON);
    for(GLdouble i {0}; i < 360; ++i)
    {
        double x {RADIUS * cos(i * pi / 180) + X_POS};
        double y {RADIUS * sin(i * pi / 180) + Y_POS};
        glVertex2d(x, y);
    }
    glEnd();
    glPopMatrix();

}

void draw_rect()
{
    glPushMatrix();
    glColor3f(1, 0, 0);
    //glTranslated(key_press_axisX, key_press_axisY, 0);
    glTranslated(-6, 10, 0);
    glRotated(-45, 0, 0, 1);
    glTranslated(6, -10, 0);
    glBegin(GL_QUADS);
    glVertex3d(-5, 9, 0);
    glVertex3d(-5, 11, 0);
    glVertex3d(-7, 11, 0);
    glVertex3d(-7, 9, 0);
    glEnd();
    glPopMatrix();
}

void showScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glLoadIdentity();
    gluOrtho2D(-20.0, 20.0, -20.0, 20.0);
    glViewport(0, 0, WIDTH, HEIGHT);
    draw_axis();
    draw_circle();
    draw_rect();
    glutSwapBuffers();
}

void resize(int height, int width)
{
    height = HEIGHT;
    width = WIDTH;
    
    if(height == 0)
        height = 1;    

    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, height, width);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    

    UCHAR input {tolower(key)}; //UCHAR unsigned char
    if(input == 'w')
        ++key_press_axisY;
    else if(input == 's')
        --key_press_axisY;
    else if(input == 'd')
        ++key_press_axisX;
    else if(input == 'a')
        --key_press_axisX;
    
    glutPostRedisplay();      
}

void keyboardUp(unsigned char key, int x, int y)
{
    buffer[key] = false;
}

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("simple circle");
    glutReshapeFunc(resize);
    glutDisplayFunc(showScreen);
    glutIdleFunc(showScreen);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutMainLoop();

    return 0;
}
