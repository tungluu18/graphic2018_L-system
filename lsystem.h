#ifndef LSYSTEM_H
#define LSYSTEM_H

#include <bits/stdc++.h>

#include "Colour.h"
#include "Point.h"
#include "Turtle.h"

using namespace std;

enum phenotype {
    NOTHING, 
    MOVE_FORWARD, 
    DRAW_FORWARD, 
    DRAW_CIRCLE, 
    SAVE, 
    RETURN, 
    ROTATE,
    ROTATE_X,
    ROTATE_Y,
    ROTATE_Z,
    TURN_AROUND
};

class Phenotype 
{
public:
    phenotype ptype;
    double option;
    Colour colour;

    Phenotype();
    Phenotype(phenotype ptype, double option = 0.0, Colour colour = _GREEN_);
};

class LSystem
{
private:
    string axiom;
    int nGeneration;
    string currentGenotype;
    map <char, string> rules;  // Production rules
    map <char, Phenotype> phenotypes;  // Phenotypes of symbols
public:
    LSystem();
    LSystem(string axiom, map <char, string> rules);
    string generateNext();  // 
    string getCurrentGenotype();
    void addPhenotype(char symbol, Phenotype ptype);
    void draw(Colour _colour = _GREEN_);
};

#endif