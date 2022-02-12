#ifndef ANIMATE_H
#define ANIMATE_H

#include <SFML/Graphics.hpp>
#include "system.h"
#include "constants.h"
#include "graph_info.h"
#include "sidebar.h"

class animate{
public:
    animate();    //CTR
    void run();      //basic run
    void processEvents();     //events in command and set_info
    void update();     //update sidebar, and the graph
    void render();    //clean draw display
    void Draw();      //draw the window, system and sidebar
private:
    sf::RenderWindow window;
    Graph_info* _info;    //have all the info
    //Sidebar _sidebar
    System system;                    //container for all the animated objects
    //Sidebar _sidebar;
    int command;                        //command to send to system
    //sf::Font font;                      //font to draw on main screen

    sf::CircleShape mousePoint;         //The little red dot
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    bool mouseIn;                       //mouse is in the screen
    bool function_input;       //the states of is going to input
    sf::Text input_text;       //the text in the input box
    string function_string;    //the function string
    bool in_info_screen;    //the state on which screen;
    sf::Text info_text;       //the text in the input box
    sf::Text guide_text;     //help text tell user

    Sidebar sidebar;     //sidebar

    void draw_box();     //draw the input box
    void information_box();      //draw the information box
};

string mouse_pos_string(sf::RenderWindow& window);    //mouse positoin str

#endif // ANIMATE_H
