#ifndef PREDATOR_H
#define PREDATOR_H

#include "creature.h"


class Predator : public creature
{
public:
    Predator(int row, int col);     //CTOR
    Predator(const Predator& copy_this);   //copy CTOR
    int get_type();    //get the type of Predator
    void move(creature* grid[][MAX]);   //move function
    void breed(creature* grid[][MAX]);   //breed function
    void print(ostream& outs) const;    //print function
    void eat(creature* grid[][MAX], Location target);
    //eat the target location prey
    void die(creature* grid[][MAX]);
    //check if itself die because starve
    void draw(sf::RenderWindow& window, int xpos, int ypos);
    //draw funtion for predator

private:
    int move_step;   //step move
    int starve_step;   //step it starve
};

#endif // PREDATOR_H
