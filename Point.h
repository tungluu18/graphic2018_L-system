#ifndef POINT_H
#define POINT_H

#include <bits/stdc++.h>
#include <GL/gl.h>

class Point 
{
public:
    double x;
    double y;
    double z;
    Point() {}
    Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

    Point RotateX(double theta);    
    Point RotateY(double theta);    
    Point RotateZ(double theta);

    Point translate(double distance);
};

#endif 