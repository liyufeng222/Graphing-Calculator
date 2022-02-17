#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include "location.h"
#include <SFML/Graphics.hpp>
#include "constants_grid.h"

using namespace std;

class creature
{
public:
    creature(int row, int col);    //CTOR
    creature(const creature& copy_this);    //COPY CTOR
    void set_moved(bool moved);     //Set the moved status
    bool get_moved();     //get the moved status
    void move_to(creature* grid[][MAX], Location location);
    //move to a specific location
    Location find_blank(creature* grid[][MAX]);
    //find a random blank location around it
    Location find_this_creature(creature* grid[][MAX], int type);
    //find a random specific type creature location around it
    Location find_not_this(creature* grid[][MAX], int type);
    //find a random not that specific type creature location around it
    virtual int get_type();
    //virtual funcion get the type of creature, use number to stand for them
    virtual void move(creature* grid[][MAX]);
    //virtual function to move the creature
    virtual void breed(creature* grid[][MAX]);
    //virtual function to breed the creture
    void kill(creature* grid[][MAX]);
    //kill this creature itself
    virtual void print(ostream& outs) const;
    //virtual print function for itself in grid map
    virtual void draw(sf::RenderWindow& window, int xpos, int ypos);
    virtual ~creature();
    //virtual destractor
    friend ostream& operator <<(ostream& outs, const creature& c);
    //output operator for a creature
private:
    Location _location;    //its location coordinate
    bool _moved;     //moved status
};

#endif // CREATURE_H
