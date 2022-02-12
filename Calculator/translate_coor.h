#ifndef TRANSLATE_COOR_H
#define TRANSLATE_COOR_H
#include "graph_info.h"
#include <SFML/Graphics.hpp>



class translate_coor
{
public:
    translate_coor(Graph_info* info);    //constructor with info
    sf::Vector2f translate(sf::Vector2f point);
    //translate the single point to screen coordinate

private:
    Graph_info* _info;
};

#endif // TRANSLATE_COOR_H
