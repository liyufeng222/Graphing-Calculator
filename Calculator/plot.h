#ifndef PLOT_H
#define PLOT_H
#include "../../!include/vector/vector.h"
#include <SFML/Graphics.hpp>
#include "graph_info.h"
#include "../../!include/shunting_yard_rpn/rpn.h"
#include "translate_coor.h"

#include "../../!include/shunting_yard_rpn/tokenizer.h"



class Plot
{
public:
    Plot(Graph_info* info);    //Constructor
    Vector<sf::Vector2f> operator ()();
    //function to get the point in screen coordinate

private:
    Graph_info* _info;   //info struct
    Queue<token*> _postfix;    //postfix form of the function
};

#endif // PLOT_H
