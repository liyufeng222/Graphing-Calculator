#include "creature.h"
#include "../!include/add_entry/add_entry.h"
#include <ctime>

#include <iostream>
using namespace std;

creature::creature(int row, int col)
{
    _location = Location(row, col);   //initial the location
    _moved = false;     //creature did not move yet
}
creature::creature(const creature& copy_this){
    _moved = copy_this._moved;   //copy the moved status
    _location = copy_this._location;    //copy the current location

}
void creature::draw(sf::RenderWindow& window, int xpos, int ypos){
    sf::RectangleShape shape;    //create rectangle
    shape = sf::RectangleShape(sf::Vector2f(SINGLE_SPACE, SINGLE_SPACE));
    //size
    shape.setPosition(sf::Vector2f(xpos, ypos));   //postion
    shape.setFillColor(sf::Color(0, 0, 0));   //color
    window.draw(shape);   //draw in window
}

void creature::set_moved(bool moved){
    _moved = moved;    //set the moved status
}
bool creature::get_moved(){
    return _moved;    //return the moved status
}
void creature::move_to(creature* grid[][MAX], Location location){
    grid[location.row][location.col] = this;
    //let the move_to location became itself
    _moved = true;    //set itself moved status to true
    grid[_location.row][_location.col] = nullptr;
    //set the previous location to nullptr, means empty
    _location = location;
    //set itself location to current location
}
Location creature::find_blank(creature* grid[][MAX]){
    int capacity = 3;  //use to build the array
    int size = 0;      //initial size
    Location* list = allocate<Location>(capacity);
    //allocate a list for location
    int row = _location.row;
    int col = _location.col;    //get the creature current row and col
    for(int i = row - 1; i <= row + 1; i++){
        for(int j = col - 1; j <= col + 1; j++){
            //double for loop thorght the spcae around it
            if(grid[i][j] == nullptr){  //when the space is empty
                list = add_entry(list, Location(i, j), size, capacity);
                //add the location to the list
            }
        }
    }
    if(size == 0){     //if there are no space found
        return Location(-1, -1);    //return a negative location
    }
    //when it found
    srand(time(NULL));
    int random = rand() % size;    //get a random number in the size
    Location result = list[random];  //get that location
    delete [] list;       //clear the dynamic list
    return result;      //return this random location
}
Location creature::find_this_creature(creature* grid[][MAX], int type){
    int capacity = 3;  //use to build the array
    int size = 0;      //initial size
    Location* list = allocate<Location>(capacity);
    //allocate a list for location
    int row = _location.row;
    int col = _location.col;    //get the creature current row and col
    for(int i = row - 1; i <= row + 1; i++){
        for(int j = col - 1; j <= col + 1; j++){
            //double for loop thorght the spcae around it
            if(grid[i][j] != nullptr &&
                    grid[i][j]->get_type() == type){
                //when the space is not empty, and with specific type
                list = add_entry(list, Location(i, j), size, capacity);
                //add to the list
            }
        }
    }
    if(size == 0){      //if there are no space found
        return Location(-1, -1);     //return a negative location
    }
    srand(time(NULL));
    int random = rand() % size;    //get a random number in the size
    Location result = list[random];  //get that location
    delete [] list;       //clear the dynamic list
    return result;      //return this random location
}
Location creature::find_not_this(creature* grid[][MAX], int type){
    int capacity = 3;  //use to build the array
    int size = 0;      //initial size
    Location* list = allocate<Location>(capacity);
    //allocate a list for location
    int row = _location.row;
    int col = _location.col;    //get the creature current row and col
    for(int i = row - 1; i <= row + 1; i++){
        for(int j = col - 1; j <= col + 1; j++){
            //double for loop thorght the spcae around it
            if(grid[i][j] != nullptr &&
                    grid[i][j]->get_type() != type){
                //when the space is not empty, and not the specific type
                list = add_entry(list, Location(i, j), size, capacity);
                //add to the list
            }
        }
    }
    if(size == 0){      //if there are no space found
        return Location(-1, -1);     //return a negative location
    }
    srand(time(NULL));
    int random = rand() % size;    //get a random number in the size
    Location result = list[random];  //get that location
    delete [] list;       //clear the dynamic list
    return result;      //return this random location
}
int creature::get_type(){
    return 0;      //0 stand for creature
}
void creature::move(creature* grid[][MAX]){
    if(!_moved){       //when it not moved
        srand(time(NULL));
        int row_step;      //step going to move on col
        int col_step;     //step going to move on col
        do{
            int random = rand() % 3 - 1;   //get number in -1, 0, 1
            row_step = random;        //put that into step on row
            random = rand() % 3 - 1;
            col_step = random;      //same as the row step
        }while(row_step == 0 && col_step == 0);
        //make sure the step move itself
        int row = _location.row + row_step;    //get the new row
        int col = _location.col + col_step;     //get the new col
        if(grid[row][col] == nullptr){     //if the new coordinate is empty
            move_to(grid, Location(row, col));    //move to that place
        }
    }
}
void creature::breed(creature* grid[][MAX]){
    Location target = find_blank(grid);    //find a empty space
    if(target.row != -1){      //when the location do exist empty
        grid[target.row][target.col] = new creature (target.row, target.col);
        //make a new creature in that place
    }
}
void creature::kill(creature* grid[][MAX]){
    int row = _location.row;
    int col = _location.col;    //get itself coordination
    delete grid[_location.row][_location.col];    //delet itself
    grid[row][col] = nullptr;     //make the original location to nullptr
}
void creature::print(ostream& outs) const{
    outs << "C";      //C for a creature
}
creature::~creature(){
    //blank no dynamic space
}
ostream& operator <<(ostream& outs, const creature& c){
    c.print(outs);      //use the print function
    return outs;
}
