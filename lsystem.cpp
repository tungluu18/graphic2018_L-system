#include "lsystem.h"


using namespace std;

Phenotype::Phenotype() {}

Phenotype::Phenotype(phenotype ptype, double option, Colour colour)
{
    this->ptype = ptype;
    this->option = option;
    this->colour = colour;
}

LSystem::LSystem() {}

LSystem::LSystem(string axiom, map<char, string> rules)
{
    this->axiom = axiom;
    this->rules = rules;
    this->currentGenotype = axiom;
    this->nGeneration = 0;
}

string LSystem::generateNext()
{
    map<char, string>::iterator it;
    int len = this->currentGenotype.length();
    for (int i = len - 1; i >= 0; i--)
    {
        it = this->rules.find(this->currentGenotype[i]);
        if (it != this->rules.end())
            this->currentGenotype.replace(i, 1, it->second);
    }
    this->nGeneration++;
    return this->currentGenotype;
}

string LSystem::getCurrentGenotype()
{
    return this->currentGenotype;
}

void LSystem::addPhenotype(char symbol, Phenotype ptype)
{
    this->phenotypes[symbol] = ptype;
}

typedef pair<pair<Point, Point>, Colour> DrawState;
#define _position first.first
#define _direction first.second
#define _colour second

void LSystem::draw(Colour _colour)
{
    Point position(0.0, -2.0, 0.0);  // start draw position    
    Point direction(0.3, 1.0, 0.1); // direction is a unit vector lies on y-axis
    Colour colour = _GREEN_;        // initial colour to draw
    stack<DrawState> st;            // stack saves: position, direction and colour

    map<char, Phenotype>::iterator it;    
    for (auto c : this->currentGenotype)
    {
        if (this->phenotypes.find(c) == this->phenotypes.end())
            continue;
        Phenotype currentPhenotype = this->phenotypes[c];
        // cerr << currentPhenotype.ptype << endl;
        if (currentPhenotype.ptype == SAVE)       
        {        
            st.push({{position, direction}, colour});            
        } 
        else if (currentPhenotype.ptype == RETURN)
        {
            DrawState topStack = st.top();
            st.pop();
            position = topStack._position;
            direction = topStack._direction;
            colour = topStack._colour;
        }
        else if (currentPhenotype.ptype == ROTATE)
        {
            // cerr << direction.x << " " << direction.y << " "<< direction.z << endl;
            direction = direction.RotateX(currentPhenotype.option);
            direction = direction.RotateY(currentPhenotype.option);
            // direction = direction.RotateZ(currentPhenotype.option / 5);
            // cerr << direction.x << " " << direction.y << " "<< direction.z << endl;
        }
        else if (currentPhenotype.ptype == ROTATE_X)
        {
            direction = direction.RotateX(currentPhenotype.option);
        }
        else if (currentPhenotype.ptype == ROTATE_Y) 
        {
            direction = direction.RotateY(currentPhenotype.option);
        }
        else if (currentPhenotype.ptype == ROTATE_Z) 
        {
            direction = direction.RotateZ(currentPhenotype.option);
        }
        else if (currentPhenotype.ptype == TURN_AROUND) 
        {
            direction = direction.RotateX(180.0);
        }
        else if (currentPhenotype.ptype == DRAW_FORWARD)
        {      
            // cerr << position.x << " " << position.y << " " << position.z << endl;  
            double dist = currentPhenotype.option / 10.0;
            Point nextP(
                position.x + direction.x * dist,
                position.y + direction.y * dist,
                position.z + direction.z * dist
            );
            drawLine(position, nextP, colour);
            position = nextP;
        }
    }
}


#undef _position
#undef _direction
#undef _colour