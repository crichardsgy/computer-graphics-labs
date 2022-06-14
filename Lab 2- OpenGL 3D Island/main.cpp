#include <GLUT/glut.h>

int x_rotation, y_rotation, z_rotation;

// vertex coords array
GLfloat vertices[] = {1,1,1,  -1,1,1,  -1,-1,1,  1,-1,1,        // v0-v1-v2-v3
                      1,1,1,  1,-1,1,  1,-1,-1,  1,1,-1,        // v0-v3-v4-v5
                      1,1,1,  1,1,-1,  -1,1,-1,  -1,1,1,        // v0-v5-v6-v1
                      -1,1,1,  -1,1,-1,  -1,-1,-1,  -1,-1,1,    // v1-v6-v7-v2
                      -1,-1,-1,  1,-1,-1,  1,-1,1,  -1,-1,1,    // v7-v4-v3-v2
                      1,-1,-1,  -1,-1,-1,  -1,1,-1,  1,1,-1};   // v4-v7-v6-v5
                      
// normal array
GLfloat normals[] = {0,0,1,  0,0,1,  0,0,1,  0,0,1,             // v0-v1-v2-v3
                     1,0,0,  1,0,0,  1,0,0, 1,0,0,              // v0-v3-v4-v5
                     0,1,0,  0,1,0,  0,1,0, 0,1,0,              // v0-v5-v6-v1
                     -1,0,0,  -1,0,0, -1,0,0,  -1,0,0,          // v1-v6-v7-v2
                     0,-1,0,  0,-1,0,  0,-1,0,  0,-1,0,         // v7-v4-v3-v2
                     0,0,-1,  0,0,-1,  0,0,-1,  0,0,-1};        // v4-v7-v6-v5
// color array
GLfloat colors[] = {1,1,1,  1,1,1,  1,1,1,  1,1,1,              // v0-v1-v2-v3
                    1,1,0,  1,1,0,  1,1,0,  1,1,0,              // v0-v3-v4-v5
                    1,0,1,  1,0,1,  1,0,1,  1,0,1,              // v0-v5-v6-v1
                    0,1,0,  0,1,0,  0,1,0,  0,1,0,              // v1-v6-v7-v2
                    0,1,1,  0,1,1,  0,1,1,  0,1,1,              // v7-v4-v3-v2
                    0,0,1,  0,0,1,  0,0,1,  0,0,1};             // v4-v7-v6-v5

void drawDECube(void)
{
     ///////////////////////////////////////////////////////////////////////////////
// draw cube with glDrawArrays
///////////////////////////////////////////////////////////////////////////////

    // enble and specify pointers to vertex arrays
    glEnableClientState(GL_NORMAL_ARRAY); //for lighting....
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glNormalPointer(GL_FLOAT, 0, normals);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
 //-------------------------------------
}

void changeCubeColour(float red,float green,float blue)
{
    for (int i=0; i<=71; i++)
    {
        if (i%3 == 0)
        {
            colors[i] = red;
        }
        else if (i%3 == 1)
        {
            colors[i] = green;
        }
        else if (i%3 == 2)
        {
            colors[i] = blue;
        }
    }
}

void drawTetrahedron(void)
{
    glBegin(GL_TRIANGLE_STRIP);
      glVertex3f(0, 2, 0);
      glVertex3f(-1, 0, 1);
      glVertex3f(1, 0, 1);
      glVertex3f(0, 0, -1.4);
      glVertex3f(0, 2, 0);
      glVertex3f(-1, 0, 1);
    glEnd();
    glFlush();
}

void init(void)
{
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_shininess[] = { 100.0 };
//    glEnable(GL_COLOR_MATERIAL);
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//    GLfloat light_position[] = { -35, -3.0, 0, 1.0 };
//
//    glClearColor (0.0, 0.0, 0.0, 0.0);
//    glShadeModel (GL_SMOOTH);
//    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
    glEnable (GL_DEPTH_TEST);

}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
 glPushMatrix(); //main push
 
 glRotatef((GLfloat) x_rotation, 1, 0 ,0);
 glRotatef((GLfloat) y_rotation, 0, 1 ,0);
 glRotatef((GLfloat) z_rotation, 0, 0 ,1);
    
    
    //ball
    glColor3f(0.941, 0.973, 1.000);
    glPushMatrix();
        glTranslatef(3.0, -2.1, -5.0);
        glScalef(0.5, 0.5, 0.5);
        glutSolidSphere(1.0, 30, 30);
    glPopMatrix();

    
    //swingset
    //pole1
    glColor3f(0.184, 0.310, 0.310);
    glPushMatrix();
        glTranslatef(0.0, -3.0, 4.0);
        glScalef(0.8, 3.5, 0.4);
        drawTetrahedron();
    glPopMatrix();

    //pole2
    glColor3f(0.184, 0.310, 0.310);
    glPushMatrix();
        glTranslatef(0.0, -3.0, -4.0);
        glScalef(0.8, 3.5, 0.4);
        drawTetrahedron();
    glPopMatrix();

    //top bar
    changeCubeColour(0.545, 0.271, 0.075);
    glPushMatrix();
                 glTranslatef(0.0, 4.0, 0.0);
                 glScalef(0.8, 0.4, 5.5);
                 drawDECube();
    glPopMatrix();
    //swing 1
    //rope 1
    changeCubeColour(0.439, 0.502, 0.565);
    glPushMatrix();
                 glTranslatef(0.0, 1.0, 2.5);
                 glScalef(0.05, 2.6, 0.05);
                 drawDECube();
    glPopMatrix();
    //rope 2
    glPushMatrix();
                 glTranslatef(0.0, 1.0, 0.8);
                 glScalef(0.05, 2.6, 0.05);
                 drawDECube();
    glPopMatrix();
    //seat1
    changeCubeColour(0.545, 0.271, 0.075);
    glPushMatrix();
                 glTranslatef(0.0, -1.5, 1.7);
                 glScalef(0.4, 0.1, 1.2);
                 drawDECube();
    glPopMatrix();
    //swing 2
    //rope 1
    changeCubeColour(0.439, 0.502, 0.565);
    glPushMatrix();
                 glTranslatef(0.0, 1.0, -2.5);
                 glScalef(0.05, 2.6, 0.05);
                 drawDECube();
    glPopMatrix();
    //rope 2
    glPushMatrix();
                 glTranslatef(0.0, 1.0, -0.8);
                 glScalef(0.05, 2.6, 0.05);
                 drawDECube();
    glPopMatrix();
    //seat2
    changeCubeColour(0.545, 0.271, 0.075);
    glPushMatrix();
                 glTranslatef(0.0, -1.5, -1.7);
                 glScalef(0.4, 0.1, 1.2);
                 drawDECube();
    glPopMatrix();
    
    //island
    glColor3f(1.000, 0.871, 0.678);
    glPushMatrix();
        glTranslatef(0, -3.0, 0);
        glScalef(10.5, 0.5, 10.5);
        glutSolidSphere(1.0, 30, 30);
    glPopMatrix();
     

    //ocean
    glPushMatrix();
    glColor3f(0.000, 0.749, 1.000);
    glBegin(GL_QUADS);
        glNormal3f(-35, -3.0, -35);
        glVertex3f(-35, -3.0, -35);
        glVertex3f(-35, -3.0, 35);
        glVertex3f(35, -3.0, 35);
        glVertex3f(35,-3.0, -35);
     glEnd();
     glPopMatrix();
    
    //sun
    glColor3f(1.000, 0.843, 0.000);
    glPushMatrix();
        glTranslatef(-35, -3.0, 0);
        glScalef(0.5, 20.5, 20.5);
        glutSolidSphere(1.0, 30, 30);
    glPopMatrix();
    
    //skybox
    changeCubeColour(0.529, 0.808, 0.980);
    glPushMatrix();
                 glTranslatef(0.0, 0.0, 0.0);
                 glScalef(35, 35, 35);
                 drawDECube();
    glPopMatrix();

 glPopMatrix(); /// main pop
   
 glutSwapBuffers();
}

void reshape(int w, int h)
{
     glViewport(0,0, (GLsizei)w, (GLsizei)h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity(); //clear the main matrix
     gluLookAt(15,5,0,0,0,0,0,1,0);
 }

void keyboard (unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'z':
        x_rotation++;
        glutPostRedisplay();
        break;
        case 'a':
        y_rotation++;
        glutPostRedisplay();
        break;
        case 'q':
        z_rotation++;
        glutPostRedisplay();
        break;
        case 'x':
        x_rotation--;
        glutPostRedisplay();
        break;
        case 's':
        y_rotation--;
        glutPostRedisplay();
        break;
        case 'w':
        z_rotation--;
        glutPostRedisplay();
        break;
        default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Lab #2");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
