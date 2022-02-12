#include "graph_info.h"

Graph_info::Graph_info()
{
    equation = "sin ( x )";
    //assign all the dfault value from constant
    domain = sf::Vector2f(DOMAIN_MIN,DOMAIN_MAX);
    number_points = POINT_NUM;

    screen_width = WORK_PANEL;
    screen_height = SCREEN_HEIGHT;

    origin.y = screen_height/2;

    update();
}

void Graph_info::update(){
    scale = screen_width/(domain.y-domain.x);
    //scale value that graph size compare to screen size

    float distance_to_o_x = (0-domain.x)*scale;
    //the distance to origin from the domain min
    origin = sf::Vector2f(distance_to_o_x, origin.y);
    //assign the origin

    x_move_unit = (screen_width/8)/scale;   //move 1/8 of the screen
    //x unit to move in graph coordinate
    y_move_unit = (screen_height/8)/scale;    //move 1/8 of the screen
    //y unit to move in graph coordinate
}

void Graph_info::re_set(){
    //default domain
    domain = sf::Vector2f(DOMAIN_MIN,DOMAIN_MAX);
    origin.y = screen_height/2;     //default y for origin
    update();     //update origin
}
