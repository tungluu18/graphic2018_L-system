#ifndef TURTLE_H
#define TURTLE_H

#include <bits/stdc++.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include "Point.h"
#include "Colour.h"

using namespace std;

void drawLine(Point start, Point end, Colour colour, double thickness = 1.0f);

#endif 