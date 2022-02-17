#include "predator.h"

Predator::Predator(int row, int col) : creature(row, col)
{
    move_step = 0;   //default move step
    starve_step = 0;    //default starve step
}

Predator::Predator(const Predator& copy_this) : creature(copy_this){
    move_step = copy_this.move_step;
    starve_step = copy_this.starve_step;   //copy both step value
}

int Predator::get_type(){
    return 1;    //1 stand for predator
}
void Predator::move(creature* grid[][MAX]){
    if(!get_moved()){    //when it is not moved
        Location target = find_this_creature(grid, 2);
        //find if there are prey around it
        if(target.row != -1){    //when location is found
            eat(grid, target);   //eat the target location prey
            move_to(grid, target);    //move itself to that location
            starve_step = 0;    //starve_step become default
            move_step++;    //move step add one
        }else{
            creature::move(grid);  //move itself
            starve_step++;
            move_step++;    //each step add one
        }
    }
}
void Predator::eat(creature* grid[][MAX], Location target){
    grid[target.row][target.col]->kill(grid);
    //the target location prey killed
}
void Predator::breed(creature* grid[][MAX]){
    if(move_step == 8){  //when the move step reach 8
        Location target = find_blank(grid);   //find a empty space around
        if(target.row != -1){   //if found
            grid[target.row][target.col] =
                    new Predator(target.row, target.col);
            //make a new predator in that space
        }
        move_step = 0;    //move_step become defalut
    }
}
void Predator::die(creature* grid[][MAX]){
    if(starve_step == 3){   //when starve step reach 3
        kill(grid);    //kill itself
    }
}
void Predator::print(ostream& outs) const{
    outs << "X";    //"X" stand for predator
}
void Predator::draw(sf::RenderWindow& window, int xpos, int ypos){
    sf::CircleShape shape;   //create circle
    shape = sf::CircleShape(SINGLE_SPACE/2,3);   //size and shape triangle
    shape.setPosition(sf::Vector2f(xpos, ypos));   //postion
    shape.setFillColor(sf::Color(255, 0, 0));   //color
    window.draw(shape);     //draw in window
}

