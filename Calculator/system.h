#ifndef SYSTEM_H
#define SYSTEM_H
#include <SFML/Graphics.hpp>
#include "graph_info.h"
#include "graph.h"


class System
{
public:
    System(Graph_info* _info);    //constructor with info
    //void set_info(Graph_info* _info);
    void Step(int command, Graph_info* _info);  //step to update the staff
    void Draw(sf::RenderWindow& window);
    //draw the staff in graph

private:
    Graph _g;
};

#endif // SYSTEM_H
