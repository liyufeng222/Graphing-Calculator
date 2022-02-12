#include "animate.h"
#include <iostream>
#include <string>
using namespace std;

animate::animate():_info(new Graph_info()), system(_info),
    sidebar(WORK_PANEL, SIDE_BAR)

{
    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
                  "Graphing Calculator");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will
    window.setFramerateLimit(60);

    mouseIn = true;
    function_input = false;      //default input state false
    in_info_screen = false;       //not in the help screen

    //set front size color for text
    input_text.setFont(font);
    input_text.setCharacterSize(30);
    input_text.setColor(sf::Color::White);

    //set front size color for text
    info_text.setFont(font);
    info_text.setCharacterSize(28);
    info_text.setColor(sf::Color::Black);

    //set front size color for text
    guide_text.setFont(font);
    guide_text.setCharacterSize(20);
    guide_text.setColor(sf::Color::Green);
    guide_text.setString("Press H for help");
    guide_text.setPosition(1300, 0);

    //mouse point
    mousePoint = sf::CircleShape();
    mousePoint.setRadius(2.0);
    mousePoint.setFillColor(sf::Color::Red);

    cout<<"Geme CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    //sidebar infomation
    sidebar[SB_CURRENT_FUN_DES] = "Current Funtion:";
    sidebar[SB_CURRENT_FUNTION] = _info->equation;
    sidebar[SB_LIST_DES] = "Save function list:";
    sidebar[SB_INPUT_STATE] = "Press F to input.";

    command = -1; //default command (update)
    cout<<"animate instantiated successfully."<<endl;
}

void animate::Draw(){
    //call system to draw the graph
    system.Draw(window);
    if (mouseIn){
        window.draw(mousePoint);    //draw the mouse point
    }

    sidebar.draw(window);    //sidebar

    if(function_input){
        draw_box();      //input box open
    }
    if(in_info_screen){
        information_box();    //open the help screen
    }
    window.draw(guide_text);     //"press h for help
    //- - - - - - - - - - - - - - - - - - -
}

void animate::update(){
    cout << "updating"<<endl;
    //cause changes to the data for the next frame
    if(command != 0){
        system.Step(command, _info);   //call system to update the step
        command = 0;
    }
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

        //mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);
    }
}
void animate::render(){
    cout << "rendering"<<endl;
    window.clear();    //clear the window
    Draw();           //draw the staff
    window.display();     //display it
}



void animate::processEvents()
{
    cout << "processEvent"<<endl;
    sf::Event event;
    float mouseX, mouseY;
    bool save_to_list = true;      //if the function need to save
    while(window.pollEvent(event))//or waitEvent
        {
        // check the type of the event...
            switch (event.type)
            {
            // window closed
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::TextEntered:
                if(function_input)    //when it is inputing
                {
                    if(event.text.unicode < 128)    //input charactor range
                    {
                        if(event.text.unicode == '\b')   //backspace
                        {
                            if(function_string.size() > 0)  //have element
                            {    //delete one element
                                function_string.pop_back();
                            }
                        }else{
                            function_string +=
                                    static_cast<char>(event.text.unicode);
                            //add single char
                        }
                        input_text.setString(function_string);
                        //set text
                    }
                }
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code){
                    case sf::Keyboard::Enter:
                    if(function_input){    //when inputing
                        function_input = false;    //end input
                        sidebar[SB_INPUT_STATE] = "Function Input end.";
                        if(function_string == ""){   //when empty
                            function_string = _info->equation;
                            //when empty input
                            save_to_list = false;   //not need to save
                        }
                        _info->equation = function_string;
                        if(save_to_list){
                            sidebar.add_function(function_string);
                            //save the function to sidebar
                        }
                        function_string = "";   //clear the input
                        sidebar[SB_CURRENT_FUNTION] = _info->equation;
                        command = -1;     //default update
                    }else if(event.key.shift){
                       command = 1;   //zoom in
                    }else{
                        command = 2;   //zoom out
                    }
                       break;
                    case sf::Keyboard::Left:
                       command = 3;   //pan left
                       break;
                    case sf::Keyboard::Right:
                       command = 4;   //pan right
                       break;
                    case sf::Keyboard::Up:
                       command = 5;   //pan left
                       break;
                    case sf::Keyboard::Down:
                       command = 6;   //pan right
                       break;
                    case sf::Keyboard::R:
                       command = 7;   //re_set the domain stuff
                       break;
                    case sf::Keyboard::Escape:
                        if(in_info_screen){
                            in_info_screen = false;   //close the help screen
                        }else{
                            window.close();
                        }
                        break;
                    case sf::Keyboard::F:
                        sidebar[SB_INPUT_STATE] = "Function Inputing";
                        input_text.setString("f(x)=");
                        function_input = true;
                        window.pollEvent(event);
                        break;
                    case sf::Keyboard::F2:
                        //save the functions;
                        sidebar.save_functions();
                        break;
                    case sf::Keyboard::H:
                        in_info_screen = true;    //make the info screen true
                        break;
                    default:
                        command = 0;
                        break;
                }
                break;
            case sf::Event::MouseWheelMoved:     //mouse wheel
                switch (event.mouseWheel.delta){
                    case 1:
                        command = 1;   //zoom in
                        break;
                    case -1:
                        command = 2;   //zoom out
                        break;
                 }
                 break;
            case sf::Event::MouseEntered:
                mouseIn = true;
                break;

            case sf::Event::MouseLeft:
                mouseIn = false;
                break;

            case sf::Event::MouseMoved:
                 mouseX = event.mouseMove.x;
                 mouseY = event.mouseMove.y;
                 //Do something with it if you need to...
                break;
            case sf::Event::MouseButtonReleased:
                    if(sf::Mouse::getPosition(window).x > WORK_PANEL &&
                            sf::Mouse::getPosition(window).x < SCREEN_WIDTH){
                        //when click inside the sidebar
                        function_string = sidebar.click_on_sidebar(
                                    sf::Mouse::getPosition(window).y);
                        //get the string in the sidebar
                        if(function_string == ""){
                            //null happen, set as current one
                            function_string = _info->equation;
                        }
                        _info->equation = function_string;
                        function_string = "";
                        sidebar[SB_CURRENT_FUNTION] = _info->equation;
                        command = -1;     //default update
                    }
                    break;

            default:
                break;
            }
        }
}
void animate::run()
{
    //the whole process loop
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

void animate::draw_box(){
    //input box
    sf::RectangleShape box(sf::Vector2f(600, 100));
    box.setFillColor(sf::Color::Blue);
    box.setPosition(sf::Vector2f(500, 10));
    box.setOutlineThickness(4);    //the around line
    box.setOutlineColor(sf::Color::Yellow);
    input_text.setPosition(sf::Vector2f(550, 40));
    window.draw(box);
    window.draw(input_text);    //draw text after the box
}

void animate::information_box(){
    //the help screen
    sf::RectangleShape box(sf::Vector2f(800, 600));
    box.setFillColor(sf::Color::White);
    box.setPosition(sf::Vector2f(10, 10));
    box.setOutlineThickness(4);
    box.setOutlineColor(sf::Color::Green);

    //tutorial
    info_text.setString("1) Use arrow key to pan the screen up down "
                        "right and left\n"
                        "2) Press F for input the function, enter to end\n"
                        "3) Every function enter in will save in sidebar\n"
                        "4) F2 to save the function in the sidebar\n"
                        "5) click on any function in sidebar can draw that "
                        "function\n"
                        "6) Shift+enter for zoom in, enter for zoom out, \n"
                        "  also can use mouse wheel to zoom in and zoom out\n"
                        "7) Press R to make the graph return to default"
                        " domain\n"
                        "8) Press Esc to exit this help screen, if in the\n"
                        "main screen Esc will end the program");

    info_text.setPosition(sf::Vector2f(15, 15));
    window.draw(box);
    window.draw(info_text);    //draw text after the box
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}
