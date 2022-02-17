#ifndef WALL_H
#define WALL_H

#include "creature.h"

class Wall : public creature
{
public:
    Wall(int row, int col);   //CTOR
    int get_type();    //get the type of wall
    void move(creature* grid[][MAX]);  //move function
    void breed(creature* grid[][MAX]);    //breed function
    void print(ostream& outs) const;      //print function
    void draw(sf::RenderWindow& window, int xpos, int ypos);
    //draw for wall


};

#endif // WALL_H
