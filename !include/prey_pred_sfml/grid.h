#ifndef GRID_H
#define GRID_H
#include "creature.h"
#include "wall.h"
#include "predator.h"
#include "prey.h"
#include <SFML/Graphics.hpp>
#include "constants_grid.h"


class grid
{
public:
    grid();   //CTOR
    void fill_grid();   //fill the grid with wall, prey, predator
    void build_wall();   //build the wall in the grid
    void fill_prey();    //fill amount of prey in grid
    void fill_predator();   //fill amount of predator in grid
    void step();   //step in one round
    void Draw(sf::RenderWindow& window);
    void command(int _command, int row = -1, int col = -1);
    //pass command from out side,  give default row and col, because may not
    //use them in some cases
    bool status() const;    //return the status of the grid pause or going

    void move();    //move all creature
    void breed();    //let creatures breed
    void kill();    //check creature is being killed

    void killOrBreed(int type, int row, int col);
    //kill or breed a prey or predator in a specific space

    int get_prey_num();     //return prey number in grid
    int get_predator_num();    //return the predator number in grid
    int get_round_num();     //return the round numebr
    bool check_end();  //true if the whole grid are empty or all prey
    void set_up();     //set up the whole grid in default

    void reset_moved();    //reset the moved status
    friend ostream& operator <<(ostream& outs, const grid& g);
    //out put operator, out put the grid

private:
    creature* _grid[MAX][MAX];    //2d creature pointers of the grid
    int round;    //the round of the grid
    int prey_number;
    int predator_number;
    bool keepGoing;
};

#endif // GRID_H
