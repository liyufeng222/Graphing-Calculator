#include "plot.h"

Plot::Plot(Graph_info* info)
{
    _info = info;    //set info
}

Vector<sf::Vector2f> Plot::operator ()(){
    tokenizer tk(_info->equation);   //tokenizer translate the string in info
    Queue<token*> infix = tk.infix();   //get infix

    shunting_yard sy(infix);    //shunting yard for infix from info
    _postfix = sy.postfix();   //get the postfix

    rpn _rpn(_postfix);      //rpn for this postfix

    Vector<sf::Vector2f> result;     //vector points list for result empty
    translate_coor tr(_info);     //translate tool class

    float start = _info->domain.x;   //domain min
    float end = _info->domain.y;     //domain max
    float space = (end - start)/(_info->number_points - 1);
    //each two point's distence

    for(int i = 0; i < _info->number_points; i++){
        float x_value = start + i*space;
        sf::Vector2f temp(x_value, _rpn.eval(x_value));
        //point coordinate in xy-coordinate
        sf::Vector2f single_point = tr.translate(temp);
        //translate the xy-coordinate to screen coordinate
        result.push_back(single_point);
        //push that screen coordinate to result list
    }
    return result;
}
