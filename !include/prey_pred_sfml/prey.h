#ifndef PREY_H
#define PREY_H

#include "creature.h"

class Prey : public creature
{
public:
    Prey(int row, int col);     //CTOR
    Prey(const Prey& copy_this);    //copy CTOR
    int get_type();    //get the type of Prey
    void move(creature* grid[][MAX]);   //move function
    void breed(creature* grid[][MAX]);   //breed function
    void print(ostream& outs) const;    //print function
    void draw(sf::RenderWindow& window, int xpos, int ypos);
    //draw function for prey


private:
    int move_step;   //step move
};

#endif // PREY_H
