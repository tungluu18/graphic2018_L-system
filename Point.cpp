#include "Point.h"
#include "Matrix.h"

/** 
 * Presenting Point in Homogeneous coordinate
 * Correspoding to each axis (x, y, and z) we rotate the point
 * around the axis by using particular rotate matrix in 
 * Homogeneous coordinate
*/

const double PI = 3.141592654;

Point Point::RotateX(double theta)
{    
    theta = theta * PI / 180.0;  // Converting Degree into Radian    
    // Rotate matrix around x-axis
    double RX[4][4] = {
        {1,      0,           0,      0},
        {0, cos(theta), -sin(theta),  0},
        {0, sin(theta),  cos(theta),  0},
        {0,      0,           0,      1}};
    double P[4][1] = {this->x, this->y, this->z, 1.0};
    Matrix M_RX(4, 4, RX), M_P(4, 1, P);
    Matrix res = M_RX * M_P;    
    return Point(
        res(0, 0) / res(3, 0),  // X-coordinate
        res(1, 0) / res(3, 0),  // Y-coordinate
        res(2, 0) / res(3, 0)   // Z-coordinate
    );
}

Point Point::RotateY(double theta)
{    
    theta = theta * PI / 180.0;  // Converting Degree into Radian    
    // Rotate matrix around y-axis
    double RX[4][4] = {
        { cos(theta), 0, sin(theta),  0},
        {      0,     1,      0,      0},
        {-sin(theta), 0, cos(theta),  0},
        {      0,     0,      0,      1}};
    double P[4][1] = {this->x, this->y, this->z, 1.0};
    Matrix M_RX(4, 4, RX), M_P(4, 1, P);
    Matrix res = M_RX * M_P;    
    return Point(
        res(0, 0) / res(3, 0),  // X-coordinate
        res(1, 0) / res(3, 0),  // Y-coordinate
        res(2, 0) / res(3, 0)   // Z-coordinate
    );
}

Point Point::RotateZ(double theta)
{    
    theta = theta * PI / 180.0;  // Converting Degree into Radian    
    // Rotate matrix around z-axis
    double RX[4][4] = {
        {cos(theta),  -sin(theta),  0,  0},
        {sin(theta),   cos(theta),  0,  0},
        {      0,           0,      1,  0},
        {      0,           0,      0,  1}};        
    double P[4][1] = {this->x, this->y, this->z, 1.0};
    Matrix M_RX(4, 4, RX), M_P(4, 1, P);
    Matrix res = M_RX * M_P;    
    return Point(
        res(0, 0) / res(3, 0),  // X-coordinate
        res(1, 0) / res(3, 0),  // Y-coordinate
        res(2, 0) / res(3, 0)   // Z-coordinate
    );
}

Point Point::translate(double distance) 
{   
    return Point(
        this->x + distance,
        this->y + distance,
        this->z + distance
    );
}