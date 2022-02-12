#include "translate_coor.h"

translate_coor::translate_coor(Graph_info* info)
{
    _info = info;  //set default
}
sf::Vector2f translate_coor::translate(sf::Vector2f point){
    float x = point.x*_info->scale + _info->origin.x;    //move the x value
    float y = -point.y*_info->scale + _info->origin.y;   //move the y value
    return sf::Vector2f(x,y);     //return the point
}
