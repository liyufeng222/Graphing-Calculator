#include "prey.h"

Prey::Prey(int row, int col) : creature(row, col)
{
    move_step = 0;   //default move step
}
Prey::Prey(const Prey& copy_this) : creature(copy_this)
{
    move_step = copy_this.move_step;    //copy the move step value
}

int Prey::get_type(){
    return 2;     //2 stand for prey
}
void Prey::move(creature* grid[][MAX]){
    if(!get_moved()){     //when it not move yet
        creature::move(grid);    //move itself
        move_step++;    //move step add one
    }
}
void Prey::breed(creature* grid[][MAX]){
    if(move_step == 3){    //when the move step reach 3
        Location target = find_blank(grid);   //find a empty space around it
        if(target.row != -1){   //if found
            grid[target.row][target.col] = new Prey(target.row, target.col);
            //make a new prey in that location
        }
        move_step = 0;    //move step become defalut
    }
}
void Prey::print(ostream& outs) const{
    outs << "O";    //"O" stand for prey
}
void Prey::draw(sf::RenderWindow& window, int xpos, int ypos){
    sf::CircleShape shape; //create circle
    shape = sf::CircleShape(SINGLE_SPACE/2);   //size
    shape.setPosition(sf::Vector2f(xpos, ypos));  //postion
    shape.setFillColor(sf::Color(0, 255, 0));  //color
    window.draw(shape);  //draw in window
}
