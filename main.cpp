#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <bits/stdc++.h> 

#include "Point.h"
#include "lsystem.h"
#include "Colour.h"

using namespace std;

const char TITLE[] = "Drawing Cube";
const double GL_PI = 3.14159f;
const double deltaRotate = 5.0;

// Global Variables
static double rotateScreen = 0.0f;
static double distanceView = 5.0f;

static LSystem Tree;

void init();
void Display();
void KeyPressed(int key, int x, int y);
void Reshape(int w, int h);

LSystem BuildTree() 
{   
    // Initial L-System by axiom and rules
    map <char, string> rules;    
    rules['F'] = "FF[<[<F>F]{{{{[<F>F]{{{{[<F>F]{{{F<F}}}]F[<[<F>F]{{{{[<F>F]]";
    LSystem lsystem("F", rules);

    // Adding Phenotype to L-System    

    const double delta = 18.5f;//22.5f;
    lsystem.addPhenotype('F', Phenotype(DRAW_FORWARD, 0.7, _GREEN_));
    lsystem.addPhenotype('[', Phenotype(SAVE));
    lsystem.addPhenotype(']', Phenotype(RETURN));
    lsystem.addPhenotype('+', Phenotype(ROTATE_Z, delta));
    lsystem.addPhenotype('-', Phenotype(ROTATE_Z, -delta));
    lsystem.addPhenotype('{', Phenotype(ROTATE_Y, delta));
    lsystem.addPhenotype('}', Phenotype(ROTATE_Y, -delta));
    lsystem.addPhenotype('<', Phenotype(ROTATE_X, delta));
    lsystem.addPhenotype('>', Phenotype(ROTATE_X, -delta));
    lsystem.addPhenotype('|', Phenotype(TURN_AROUND));
    // Drawing Genotype
    for (int i = 0; i < 3; ++i) lsystem.generateNext();
    // cerr << lsystem.getCurrentGenotype() << endl;
    return lsystem;
}

void Display()
{    
    // const GLfloat halfWidt h =
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glColor3f( 0.6f, 0.6f, 0.6f );
    glColor3f(0.0, 1.0, 0.0); //green color
    glLoadIdentity();

    glFrustum(
        -1.0, 1.0, -1.0, 1.0, // left, right, bottom, top of clipping plane
        1.5, 20.0             // distance to near and far depth clipping planes
    );
    
    gluLookAt(
        0, 1, distanceView,
        0, 1, 0,
        0, 1, 0);

    glRotated(rotateScreen, 0.0f, 1.0f, 0.0f);
        
    Tree.draw();
    glFlush();
}

void _Display(void);

int main(int argc, char **argv)
{    
    ios_base::sync_with_stdio(false);
    // Init stuffs
    glutInit(&argc, argv);
    init();
    Tree = BuildTree();
    // cerr << "Tree' s Genotype: " << Tree.getCurrentGenotype() << endl;
    // Display Func
    glutDisplayFunc(Display);
    glutSpecialFunc(KeyPressed);
    // glutReshapeFunc(Reshape);
    glutMainLoop();
    return 0;
}

void init()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(TITLE);
    glClear(GL_COLOR_BUFFER_BIT);          // clear the color buffer
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // set up background color
    glEnable(GL_DEPTH_TEST | GL_LIGHTING); // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);                // Set the type of depth-test
    glShadeModel(GL_SMOOTH);               // Enable smooth shading
    glMatrixMode(GL_PROJECTION);            
}

void _Display(void)
{
    // const GLfloat halfWidt h =
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glColor3f( 0.6f, 0.6f, 0.6f );
    glColor3f(0.0, 1.0, 0.0); //green color
    glLoadIdentity();

    glFrustum(
        -1.0, 1.0, -1.0, 1.0, // left, right, bottom, top of clipping plane
        1.5, 20.0             // distance to near and far depth clipping planes
    );

    gluLookAt(
        0, 1, distanceView,
        0, 1, 0,
        0, 1, 0);

    glRotated(rotateScreen, 0.0f, 1.0f, 0.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINES);
    Point P[3] = {
        Point(0.0f, 0.0f, 0.0f),
        Point(1.0f, 1.0f, 0.0f),
        Point(0.0f, 2.0f, -1.0f)};
    for (int i = 1; i < 3; ++i)
    {
        glLineWidth(2.0f);
        glVertex3f(P[i - 1].x, P[i - 1].y, P[i - 1].z);
        glVertex3f(P[i].x, P[i].y, P[i].z);
    }
    glEnd();

    // glRotatef( rotateX, 0.0f, 1.0f, 0.0f );
    // const GLfloat z = 0.0;

    // glutWireCube( 1.0f );

    glFlush();
}

void KeyPressed(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_RIGHT:
        rotateScreen += deltaRotate;
        if (rotateScreen >= 360) rotateScreen -= 360;
        Display();
        break;
    case GLUT_KEY_LEFT:
        rotateScreen -= deltaRotate;
        if (rotateScreen <= 0) rotateScreen += 360;
        Display();
        break;
    case GLUT_KEY_DOWN:
        distanceView += 0.1;
        Display();
        break;
    case GLUT_KEY_UP:
        distanceView -= 0.1;
        Display();
        break;
    }
}

void Reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_PROJECTION);
}
