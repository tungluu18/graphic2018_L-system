#include "Turtle.h"

void drawLine(Point start, Point end, Colour colour, double thickness)
{
    glColor3f(colour.R, colour.G, colour.B); //green color
    
    glLineWidth(thickness);
    glBegin(GL_LINES);
        glVertex3f(start.x, start.y, start.z);
        glVertex3f(end.x, end.y, end.z);
    glEnd();
}