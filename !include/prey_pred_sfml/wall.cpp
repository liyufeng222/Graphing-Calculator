#include "wall.h"

Wall::Wall(int row, int col) : creature(row, col)
{
    //blank because wall has no extra variable
}

int Wall::get_type(){
    return 3;    //3 stand for wall
}
void Wall::move(creature* grid[][MAX]){
    //blank   becasue wall never move
}
void Wall::breed(creature* grid[][MAX]){
    //blank    becasue wall never breed
}
void Wall::print(ostream& outs) const{
    outs << "Z";    //Z stand for wall
}
void Wall::draw(sf::RenderWindow& window, int xpos, int ypos){
    sf::RectangleShape shape;   //create rectangle
    shape = sf::RectangleShape(sf::Vector2f(SINGLE_SPACE, SINGLE_SPACE));
    //size
    shape.setPosition(sf::Vector2f(xpos, ypos));   //postion
    shape.setFillColor(sf::Color(0, 0, 255));    //color
    window.draw(shape);   //draw in window
}
