#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "../../!include/shunting_yard_rpn/shunting_yard.h"


struct Graph_info      //not complate yet phase 3 will done
{
    Graph_info();     //default constructor

    void update();   //update the the staff in info

    void re_set();  //reset the info

    string equation;    //equation

    sf::Vector2f domain;    //domain
    sf::Vector2f range;    //domain
    sf::Vector2f origin;   //the position of origin
    int number_points;    //number of point
    float scale; //the scale from xy to screen coor
    float screen_height;    //screen size
    float screen_width;

    float x_move_unit;    //the x value move unit in graph
    float y_move_unit;    //the y value move unit in graph

};

#endif // GRAPH_INFO_H
