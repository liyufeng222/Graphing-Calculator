#ifndef GRAPH_H
#define GRAPH_H

#include "../../!include/vector/vector.h"
#include <SFML/Graphics.hpp>
#include "graph_info.h"
#include "plot.h"


class Graph
{
public:
    Graph(Graph_info* graph_info);   //constructor with info
    void update();   //(Graph_info graph_info);  //update graph info
    void draw(sf::RenderWindow& window);   //draw the grap

private:
    Graph_info* _info;
    Plot _plotter;    //plot class as tool to graph
    Vector<sf::Vector2f> _points;    //points coordinate in screen
    sf::Font font;                      //font to draw on main screen
};

#endif // GRAPH_H
