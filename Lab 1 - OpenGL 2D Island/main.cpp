//
//  main.c
//  CSE3200 Lab 1

#include<iostream>
#include <GLUT/glut.h>
#include <math.h>

#define DEG2RAD 3.14159/180.0

typedef float GLfloat;
typedef int GLint;

void drawFilledCircle(GLfloat,GLfloat,GLfloat);
void drawHalfFilledCircle(GLfloat,GLfloat,GLfloat);


//http://opengl.czweb.org/ch03/040-043.html - Website for OpenGL Basic Colors

using namespace std;

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    
    //sky
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
        //glColor3f(0.000, 0.749, 1.000);
        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(1,1);
        glVertex2f(-1,1);
        glColor3f(1.000, 0.549, 0.000);
        glVertex2f(-1,-0.2);
        glVertex2f(1,-0.2);
    glEnd();
    
    //sun
    glColor3f(1.000, 0.843, 0.000);
    drawFilledCircle(0,0,0.55);

    //water
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
        glColor3f(0.000, 0.749, 1.000);
        glVertex2f(-1,-0.2);
        glVertex2f(1,-0.2);
        glColor3f(0.125, 0.698, 0.667);
        glVertex2f(1,-1);
        glVertex2f(-1,-1);
    glEnd();
    
    //island
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
        glColor3f(1.000, 0.871, 0.678);
        glVertex2f(-1,-0.2);
        glVertex2f(-0.8,-0.3);
        glVertex2f(-0.6,-0.5);
        glVertex2f(-0.4,-0.4);
        glVertex2f(-0.2,-0.3);
        glVertex2f(0.0,-0.7);
        glVertex2f(0.2,-0.5);
        glVertex2f(0.4,-0.4);
        glVertex2f(0.6,-0.7);
        glVertex2f(0.8,-0.4);
        glVertex2f(1,-0.2);
    glEnd();
    
    //swingset
    //pillar 1
    glBegin(GL_TRIANGLES);
        glColor3f(0.184, 0.310, 0.310);
        glVertex2f(-0.3,0.3);
        glVertex2f(-0.25,-0.3);
        glColor3f(0.000, 0.502, 0.502);
        glVertex2f(-0.35,-0.3);
    glEnd();
    //pillar 2
    glBegin(GL_TRIANGLES);
        glColor3f(0.000, 0.502, 0.502);
        glVertex2f(0.3,0.3);
        glVertex2f(0.25,-0.3);
        glColor3f(0.184, 0.310, 0.310);
        glVertex2f(0.35,-0.3);
    glEnd();
    //top bar
    glBegin(GL_QUADS);
        glColor3f(0.545, 0.271, 0.075);
        glVertex2f(-0.40,0.3);
        glVertex2f(0.40,0.3);
        glColor3f(0.245, 0.051, 0.035);
        glVertex2f(0.40,0.25);
        glVertex2f(-0.40,0.25);
    glEnd();
    //swing1
    glBegin(GL_LINES);
        glColor3f(0.439, 0.502, 0.565);
        glVertex2f(-0.18,0.25);
        glVertex2f(-0.18,-0.2);
    glEnd();
    glBegin(GL_LINES);
        glColor3f(0.439, 0.502, 0.565);
        glVertex2f(-0.07,0.25);
        glVertex2f(-0.07,-0.2);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.545, 0.271, 0.075);
        glVertex2f(-0.20,-0.2);
        glVertex2f(-0.05,-0.2);
        glColor3f(0.245, 0.051, 0.035);
        glVertex2f(-0.07,-0.23);
        glVertex2f(-0.18,-0.23);
    glEnd();
    //swing2
    glBegin(GL_LINES);
        glColor3f(0.439, 0.502, 0.565);
        glVertex2f(0.18,0.25);
        glVertex2f(0.18,-0.2);
    glEnd();
    glBegin(GL_LINES);
        glColor3f(0.439, 0.502, 0.565);
        glVertex2f(0.07,0.25);
        glVertex2f(0.07,-0.2);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.545, 0.271, 0.075);
        glVertex2f(0.20,-0.2);
        glVertex2f(0.05,-0.2);
        glColor3f(0.245, 0.051, 0.035);
        glVertex2f(0.07,-0.23);
        glVertex2f(0.18,-0.23);
    glEnd();
    
    //ball
    glColor3f(0.941, 0.973, 1.000);
    drawFilledCircle(0.6,-0.4,0.05);
    glBegin(GL_LINE_STRIP);
        glColor3f(0.412, 0.412, 0.412);
        glVertex2f(0.57,-0.4);
        glVertex2f(0.60,-0.39);
        glVertex2f(0.63,-0.4);
    glEnd();
    
    glFlush();
}

//https://gist.github.com/linusthe3rd/803118
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle
    
    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.14;
    
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}

void drawHalfFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle
    
    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.14;
    
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); // center of circle
        for(i = 0; i <= triangleAmount/2;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}
    

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lab 1");
    glutDisplayFunc(displayMe);
    glutMainLoop();

    return 0;
}
