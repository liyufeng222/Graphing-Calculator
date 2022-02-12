#include "graph.h"

Graph::Graph(Graph_info* graph_info) : _plotter(graph_info)
{
    _info = graph_info;   //set info
    if (!font.loadFromFile("Roboto-Thin.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
}

void Graph::update(){
    _points = _plotter();   //update the points from the plot
}
void Graph::draw(sf::RenderWindow& window){
    //draw the text for domain
    sf::Text domain;
    domain.setFont(font);
    domain.setCharacterSize(30);
    domain.setColor(sf::Color::Green);
    //get the domain from _info
    string domain_str = "Domain: ["+to_string(_info->domain.x)+", "+
            to_string(_info->domain.y)+"]";
    domain.setString(domain_str);
    domain.setPosition(1300, 1150);
    window.draw(domain);

    //draw the x,y axis make them red
    sf::RectangleShape x_axis(sf::Vector2f(_info->screen_width, 1));
    x_axis.setPosition(sf::Vector2f(0,_info->origin.y));
    x_axis.setFillColor(sf::Color::Red);
    window.draw(x_axis);      //draw x-axis
    if(_info->origin.x < _info->screen_width){
        sf::RectangleShape y_axis(sf::Vector2f(1,_info->screen_height));
        y_axis.setPosition(sf::Vector2f(_info->origin.x,0));
        y_axis.setFillColor(sf::Color::Red);
        window.draw(y_axis);      //draw y-aix
    }

    //loop all the points
    for(int i = 0; i < _info->number_points; i++){
        if(_points[i].x > 0 && _points[i].x <= _info->screen_width &&
                _points[i].y > 0 && _points[i].y <= _info->screen_height){
            sf::CircleShape point;
            point.setRadius(1);  //dot  small radius
            point.setFillColor(sf::Color::White);   //make them white
            point.setPosition(_points[i].x,_points[i].y);
            window.draw(point);   //draw the single point in window
        }
    }    
}
