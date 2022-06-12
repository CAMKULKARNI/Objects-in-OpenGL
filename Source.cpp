#include <gl/glut.h>
#include <windows.h>
#include <random>
#define PI 3.141592

int window_width, window_height;
double shape1_r_x = 0;
double shape1_r_y = 0;
double shape1_r_z = 0;

double shape2_r_x = 0;
double shape2_r_y = 0;
double shape2_r_z = 0;

double shape3_r_x = 0;
double shape3_r_y = 0;
double shape3_r_z = 0;

double shape1_scale_x = 1;
double shape1_scale_y = 1;
double shape1_scale_z = 1;

double shape2_scale_x = 1;
double shape2_scale_y = 1;
double shape2_scale_z = 1;

double shape3_scale_x = 1;
double shape3_scale_y = 1;
double shape3_scale_z = 1;

double shape1_t_x = ((rand() % 3) - 1) * rand() % 3;
double shape1_t_y = ((rand() % 3) - 1) * rand() % 3;
double shape1_t_z = ((rand() % 3) - 1) * rand() % 3;

double shape2_t_x = ((rand() % 3) - 1) * rand() % 3;
double shape2_t_y = ((rand() % 3) - 1) * rand() % 3;
double shape2_t_z = ((rand() % 3) - 1) * rand() % 3;

double shape3_t_x = ((rand() % 3) - 1) * rand() % 3;
double shape3_t_y = ((rand() % 3) - 1) * rand() % 3;
double shape3_t_z = ((rand() % 3) - 1) * rand() % 3;

GLuint object_selection;

float t = 0.0;
float tempx = 0.0;
float tempy = 0.0;
float cx = 2.0;
float cy = 2.0;
float cz = 2.0;
float radius = 10;
float angle1 = 90 * PI / 180;
float angle2 = 90 * PI / 180;
int d = 3;

void setMaterial(GLfloat ambientR, GLfloat ambientG,
    GLfloat ambientB, GLfloat diffuseR, GLfloat diffuseG,
    GLfloat diffuseB, GLfloat specularR, GLfloat specularG,
    GLfloat specularB, int shine)
{
    float ambient[] = { ambientR, ambientG, ambientB };
    float diffuse[] = { diffuseR, diffuseG, diffuseB };
    float specular[] = { specularR, specularG, specularB };
    glGetMaterialfv(GL_FRONT_FACE, GL_AMBIENT, ambient);
    glGetMaterialfv(GL_FRONT_FACE, GL_DIFFUSE, diffuse);
    glGetMaterialfv(GL_FRONT_FACE, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_FACE, GL_SHININESS, shine);
}


void onMouse(int button, int state, int x, int y) {
    if (state != GLUT_DOWN)
        return;
    glReadPixels(x, glutGet(GLUT_WINDOW_HEIGHT) - y - 1, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &object_selection);
}

void myMouseMotion(int x, int y)
{
    float gain = 0.1;
    float dx = gain * (x - tempx);
    float dy = gain * (y - tempy);

    tempx = x;
    tempy = y;
    if (tempx != 0 && tempy != 0) {
        if (angle2 == 179 * PI / 180) {
            angle2 = 181 * PI / 180;
        }
        if (angle2 == 89 * PI / 180) {
            angle2 = 91 * PI / 180;
        }
        if (angle1 == 179 * PI / 180) {
            angle1 = 181 * PI / 180;
        }
        if (angle1 == 89 * PI / 180) {
            angle1 = 91 * PI / 180;
        }
        angle1 = angle1 + dx;
        angle2 = angle2 + dy;
        t = d * cos(angle2);  // distance to y-axis after being rotated up
        cy = d * sin(angle2);

        cx = t * cos(angle1);
        cz = t * sin(angle1);
    }

}

void myKeyboardFunc(unsigned char key, int x, int y)
{
    if (object_selection == 1)
    {
        switch (key)
        {
            case 'a': shape1_t_x -= 0.1; break;
            case 'd': shape1_t_x += 0.1; break;
            case 'w': shape1_t_y += 0.1; break;
            case 's': shape1_t_y -= 0.1; break;
            case 'e': shape1_t_z += 0.1; break;
            case 'q': shape1_t_z -= 0.1; break;
            case 'x': shape1_r_x += 0.4; break;
            case 'y': shape1_r_y += 0.4; break;
            case 'z': shape1_r_z += 0.4; break;
            case 'p': shape1_scale_x += 0.2; shape1_scale_y += 0.2; shape1_scale_z += 0.2; break;
            case 'm': shape1_scale_x -= 0.2; shape1_scale_y -= 0.2; shape1_scale_z -= 0.2; break;
            case 'r': shape1_scale_x = 1; shape1_scale_y = 1; shape1_scale_z = 1; break;
            default: break;
        }
        glutPostRedisplay();
    }
    if (object_selection == 2)
    {
        switch (key)
        {
        case 'a': shape2_t_x -= 0.1; break;
        case 'd': shape2_t_x += 0.1; break;
        case 'w': shape2_t_y += 0.1; break;
        case 's': shape2_t_y -= 0.1; break;
        case 'e': shape2_t_z += 0.1; break;
        case 'q': shape2_t_z -= 0.1; break;
        case 'x': shape2_r_x += 0.4; break;
        case 'y': shape2_r_y += 0.4; break;
        case 'z': shape2_r_z += 0.4; break;
        case 'p': shape2_scale_x += 0.2; shape2_scale_y += 0.2; shape2_scale_z += 0.2; break;
        case 'm': shape2_scale_x -= 0.2; shape2_scale_y -= 0.2; shape2_scale_z -= 0.2; break;
        case 'r': shape2_scale_x = 1; shape2_scale_y = 1; shape2_scale_z = 1; break;
        default: break;
        }
        glutPostRedisplay();
    }
    if (object_selection == 3)
    {
        switch (key)
        {
        case 'a': shape3_t_x -= 0.1; break;
        case 'd': shape3_t_x += 0.1; break;
        case 'w': shape3_t_y += 0.1; break;
        case 's': shape3_t_y -= 0.1; break;
        case 'e': shape3_t_z += 0.1; break;
        case 'q': shape3_t_z -= 0.1; break;
        case 'x': shape3_r_x += 0.4; break;
        case 'y': shape3_r_y += 0.4; break;
        case 'z': shape3_r_z += 0.4; break;
        case 'p': shape3_scale_x += 0.2; shape3_scale_y += 0.2; shape3_scale_z += 0.2; break;
        case 'm': shape3_scale_x -= 0.2; shape3_scale_y -= 0.2; shape3_scale_z -= 0.2; break;
        case 'r': shape3_scale_x = 1; shape3_scale_y = 1; shape3_scale_z = 1; break;
        default: break;
        }
        glutPostRedisplay();
    }
}

void update_shapes()
{
    if (object_selection != 1)
    {
        shape1_r_y += 0.2 * (rand() % 2);
        shape1_r_x += 0.2 * (rand() % 2);
        shape1_r_z += 0.2 * (rand() % 2);

        if (pow(shape1_t_x, 2) + pow(shape1_t_y, 2) + pow(shape1_t_z, 2) > 9)
        {
            if (shape1_t_x < 0) shape1_t_x += (rand() % 2) * 0.2;
            else if (shape1_t_x > 0) shape1_t_x -= (rand() % 2) * 0.2;

            if (shape1_t_y < 0) shape1_t_y += (rand() % 2) * 0.2;
            else if (shape1_t_y > 0) shape1_t_y -= (rand() % 2) * 0.2;

            if (shape1_t_z < 0) shape1_t_z += (rand() % 2) * 0.2;
            else if (shape1_t_z > 0) shape1_t_z -= (rand() % 2) * 0.2;

        }
        else if (pow(shape1_t_x, 2) + pow(shape1_t_y, 2) + pow(shape1_t_z, 2) <= 9)
        {
            shape1_t_x += ((rand() % 3) - 1) * 0.05;
            shape1_t_y += ((rand() % 3) - 1) * 0.05;
            shape1_t_z += ((rand() % 3) - 1) * 0.05;
        }
    }
    
    if (object_selection != 2)
    {
        shape2_r_y += 0.2 * (rand() % 2);
        shape2_r_x += 0.2 * (rand() % 2);
        shape2_r_z += 0.2 * (rand() % 2);

        if (pow(shape2_t_x, 2) + pow(shape2_t_y, 2) + pow(shape2_t_z, 2) > 9)
        {
            if (shape2_t_x < 0) shape2_t_x += (rand() % 2) * 0.2;
            else if (shape2_t_x > 0) shape2_t_x -= (rand() % 2) * 0.2;

            if (shape2_t_y < 0) shape2_t_y += (rand() % 2) * 0.2;
            else if (shape2_t_y > 0) shape2_t_y -= (rand() % 2) * 0.2;

            if (shape2_t_z < 0) shape2_t_z += (rand() % 2) * 0.2;
            else if (shape2_t_z > 0) shape2_t_z -= (rand() % 2) * 0.2;
        }
        else if (pow(shape2_t_x, 2) + pow(shape2_t_y, 2) + pow(shape2_t_z, 2) <= 9)
        {
            shape2_t_x += ((rand() % 3) - 1) * 0.05;
            shape2_t_y += ((rand() % 3) - 1) * 0.05;
            shape2_t_z += ((rand() % 3) - 1) * 0.05;
        }
    }

    if (object_selection != 3)
    {
        shape3_r_y += 0.2 * (rand() % 2);
        shape3_r_x += 0.2 * (rand() % 2);
        shape3_r_z += 0.2 * (rand() % 2);

        if (pow(shape3_t_x, 2) + pow(shape3_t_y, 2) + pow(shape3_t_z, 2) > 9)
        {
            if (shape3_t_x < 0) shape3_t_x += (rand() % 2) * 0.2;
            else if (shape3_t_x > 0) shape3_t_x -= (rand() % 2) * 0.2;

            if (shape3_t_y < 0) shape3_t_y += (rand() % 2) * 0.2;
            else if (shape3_t_y > 0) shape3_t_y -= (rand() % 2) * 0.2;

            if (shape3_t_z < 0) shape3_t_z += (rand() % 2) * 0.2;
            else if (shape3_t_z > 0) shape3_t_z -= (rand() % 2) * 0.2;

        }
        else if (pow(shape3_t_x, 2) + pow(shape3_t_y, 2) + pow(shape3_t_z, 2) <= 9)
        {
            shape3_t_x += ((rand() % 3) - 1) * 0.05;
            shape3_t_y += ((rand() % 3) - 1) * 0.05;
            shape3_t_z += ((rand() % 3) - 1) * 0.05;
        }
    }

    glutPostRedisplay();
}

void outer_sphere()
{
    glutWireSphere(4, 10, 10);
}

void shape_sphere()
{
    //GLfloat x, y, z, alpha, beta; // Storage for coordinates and angles        
    //GLfloat radius = 0.5;
    //int gradation = 100;

    //for (alpha = 0.0; alpha < PI; alpha += PI / gradation)
    //{
    //    glBegin(GL_TRIANGLES);
    //    for (beta = 0.0; beta < 2.01 * PI; beta += PI / gradation)
    //    {
    //        x = radius * cos(beta) * sin(alpha);
    //        y = radius * sin(beta) * sin(alpha);
    //        z = radius * cos(alpha);
    //        glVertex3f(x, y, z);
    //        x = radius * cos(beta) * sin(alpha + PI / gradation);
    //        y = radius * sin(beta) * sin(alpha + PI / gradation);
    //        z = radius * cos(alpha + PI / gradation);
    //        glVertex3f(x, y, z);
    //    }
    //    glEnd();
    //}
    glutSolidSphere(0.5, 100, 100);
    glFlush();
    glutSwapBuffers();
}

void shape_squarePyramid()
{
    //Yellow side - BOTTOM
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.5, 0.5, 1.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glNormal3f(0.0, 0.0, 0.5);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glEnd();

    // White side - BACK
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glNormal3f(0.0, 1.0, -1.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.0, 0.0, 0.5);
    glEnd();

    // Purple side - RIGHT
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 1.0);
    glNormal3f(-1.0, 0.0, -1.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.0, 0.0, 0.5);
    glEnd();

    // Turquoise side - LEFT
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 1.0, 1.0);
    glNormal3f(1.0, 0.0, -1.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(0.0, 0.0, 0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glNormal3f(0.0, -1.0, -1.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.0, 0.0, 0.5);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void shape_pentagonalPrism()
{
    //bottom face
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(-0.5, -1.0, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-0.5, -1.0, 0.0);
    glVertex3f(0.5, -1.0, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, -1.0, 0.0);
    glEnd();

    // side 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.5, -1.0, 0.0);
    glVertex3f(0.5, -1.0, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, -1.0, 0.0);
    glEnd();

    //side 2
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.5, -1.0, 0.0);
    glVertex3f(0.5, -1.0, 0.0);
    glVertex3f(0.5, -1.0, 0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-0.5, -1.0, 0.0);
    glVertex3f(-0.5, -1.0, 0.5);
    glVertex3f(0.5, -1.0, 0.5);
    glEnd();

    //side 3
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.0, 0.0, 0.5);
    glVertex3f(0.5, -0.5, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.5);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glEnd();

    //side 4
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();

    //side 5
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(-0.5, -1.0, 0.0);
    glVertex3f(-0.5, -1.0, 0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, -1.0, 0.5);
    glEnd();

    //top face
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.0, 0.0, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, -1.0, 0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.5);
    glVertex3f(-0.5, -1.0, 0.5);
    glVertex3f(0.5, -1.0, 0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, -1.0, 0.5);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void display() {
    glClearStencil(0); // this is the default value
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glEnable(GL_STENCIL_TEST);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cx, cy, cz, 0, 0, 0, 0, 1, 0);

    outer_sphere();

    glPushMatrix();
    glStencilFunc(GL_ALWAYS, 1, -1);

    glTranslatef(shape1_t_x, shape1_t_y, shape1_t_z);
    glutPostRedisplay();

    glRotatef(shape1_r_y, shape1_t_x, 0.0, 0.0);
    glRotatef(shape1_r_x, 0.0, shape1_t_y, 0.0);
    glRotatef(shape1_r_z, 0.0, 0.0, shape1_t_z);
    glutPostRedisplay();

    glScalef(shape1_scale_x, shape1_scale_y, shape1_scale_z);
    glutPostRedisplay();

    setMaterial(0.135, 0.2225, 0.1575, 0.54, 0.89, 0.63, 0.316228, 0.316228, 0.316228, 19);
    shape_sphere();

    glutSwapBuffers();
    glPopMatrix();

    glPushMatrix();
    glStencilFunc(GL_ALWAYS, 2, -1);

    glTranslatef(shape2_t_x, shape2_t_y, shape2_t_z);
    glutPostRedisplay();

    glRotatef(shape2_r_y, shape2_t_x, 0.0, 0.0);
    glRotatef(shape2_r_x, 0.0, shape2_t_y, 0.0);
    glRotatef(shape2_r_z, 0.0, 0.0, shape2_t_z);
    glutPostRedisplay();

    glScalef(shape2_scale_x, shape2_scale_y, shape2_scale_z);
    glutPostRedisplay();

    setMaterial(0.0215, 0.1745, 0.0215, 0.07568, 0.61424, 0.07568, 0.633, 0.727811, 0.633, 13);
    shape_squarePyramid();

    glutSwapBuffers();
    glPopMatrix();

    glPushMatrix();
    glStencilFunc(GL_ALWAYS, 3, -1);

    glTranslatef(shape3_t_x, shape3_t_y, shape3_t_z);
    glutPostRedisplay();

    glRotatef(shape3_r_y, shape3_t_x, 0.0, 0.0);
    glRotatef(shape3_r_x, 0.0, shape3_t_y, 0.0);
    glRotatef(shape3_r_z, 0.0, 0.0, shape3_t_z);
    glutPostRedisplay();

    glScalef(shape3_scale_x, shape3_scale_y, shape3_scale_z);
    glutPostRedisplay();

    setMaterial(0.1, 0.18725, 0.1745, 0.396, 0.74151, 0.69102, 0.297254, 0.30829, 0.306678, 31);
    shape_pentagonalPrism();

    glutSwapBuffers();
    glPopMatrix();
}


int main(int argc, char* argv[]) {

    //  Initialize GLUT and process user parameters
    glutInit(&argc, argv);

    glutInitWindowSize(640, 640);
    glutInitWindowPosition(10, 10);

    //  Request double buffered true color window with Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STENCIL | GLUT_RGBA);

    // Create window
    glutCreateWindow("ASSIGNMENT");

    //  Enable Z-buffer depth tests
    glEnable(GL_DEPTH_TEST | GL_STENCIL_TEST | GL_COLOR_MATERIAL);

    // Callback functions
    glutDisplayFunc(display);
    glutMouseFunc(onMouse);
    glutMotionFunc(myMouseMotion);
    glutIdleFunc(update_shapes);
    glutKeyboardFunc(myKeyboardFunc);

    //glMatrixMode(GL_PROJECTION); //Select Projection Matrix
    //glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);

    //  Pass control to GLUT for events
    glutMainLoop();
}
