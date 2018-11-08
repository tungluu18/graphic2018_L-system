#ifndef COLOUR_H
#define COLOUR_H

#include <bits/stdc++.h>

class Colour 
{
public:    
    double R, G ,B;
    Colour();
    Colour(double R, double G, double B);
};

const Colour _GREEN_ = Colour(0.0, 0.5, 0.0);

#endif 