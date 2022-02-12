#ifndef SIDEBAR_H
#define SIDEBAR_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


class Sidebar
{
public:
    Sidebar();    //construct the sidebar
    Sidebar(float left, float width);    //constructor with lenght, width
    void read_functions();   //read function from file
    void save_functions();    //save the list functions to file
    void draw(sf::RenderWindow& window);   //draw the sidebar
    string& operator [](int index);   //item index return
    void add_function(string function);    //add function to the list
    bool is_exist(string);       //check id the string exist in list
    string click_on_sidebar(float height);   //when click on sidebar
private:
    sf::RectangleShape rect;            //sidebar rectangle
    vector<string> items;               //strings to place on the sidebar
    sf::Font font;                      //used to draw text
    sf::Text sb_text;              //used to draw strings on the window object
    vector<string> equations;     //equation list

    float _left;      //left screen width
    float _width;     //width of sidebar

};

#endif // SIDEBAR_H
