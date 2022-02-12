#include "system.h"

System::System(Graph_info* _info):_g(_info){
    //blank
}

void System::Draw(sf::RenderWindow& window){
    _g.draw(window);   //use graph class to draw
}

void System::Step(int command, Graph_info* _info){
    switch (command) {
        case 1:      //zoom in
        //expend the domain
            _info->domain.x = _info->domain.x + _info->x_move_unit;
            _info->domain.y = _info->domain.y - _info->x_move_unit;
        break;
        case 2:    //zoom out
        //minimize the domain
            _info->domain.x = _info->domain.x - _info->x_move_unit;
            _info->domain.y = _info->domain.y + _info->x_move_unit;
            break;
        case 3:  //move left
        //domain move left (-)
            _info->domain.x = _info->domain.x - _info->x_move_unit;
            _info->domain.y = _info->domain.y - _info->x_move_unit;
            break;
        case 4:    //move right
        //domain move right(+)
            _info->domain.x = _info->domain.x + _info->x_move_unit;
            _info->domain.y = _info->domain.y + _info->x_move_unit;
            break;
        case 5:    //move up
        //origin move down
            _info->origin.y = _info->origin.y +
                    _info->y_move_unit*_info->scale;
            break;
        case 6:    //move down
        //origin move up
            _info->origin.y = _info->origin.y -
                    _info->y_move_unit*_info->scale;
            break;
        case 7:    //reset the info
            _info->re_set();
            break;
        default:
            break;
    }
    _info->update();
    _g.update();    //no command yet, let graph to update
}
