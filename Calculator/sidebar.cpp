#include "sidebar.h"
#include "constants.h"
#include <string.h>
Sidebar::Sidebar(){

}

Sidebar::Sidebar(float left, float width):_left(left), _width(width){
    cout<<"Sidebar CTOR: TOP"<<endl;
    items.reserve(50);

    //set up the sidebar rectangle:
    rect.setFillColor(sf::Color(105,105,105)); //(192,192,192)); //silver
    rect.setPosition(sf::Vector2f(left, 0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));
    cout<<"Sidebar CTOR: about to load font."<<endl;

    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    //the font file must be in the "working directory"
    // check projects->run->working directory
    //      [Make sure it's not pointing to the app file]

    if (!font.loadFromFile("Roboto-Thin.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout<<"Sidebar CTOR: loaded font."<<endl;

    //. . . . . text / font problems: . . . . . . . .
    //initializing text object in this way caused problems
    // (hangs!)
    //only when sb_text was a private member and worked fine
    //when it was a public member. Probably not releavant,
    //but still strange!
    //
    //sb_text = sf::Text("Initial String for myTextLabel", font);
    //
    //. . . . . . . . . . . . . . . . . . . . . . . . .
    cout<<"Sidebar CTOR: Text object initialized."<<endl;
    sb_text.setFont(font);
    sb_text.setCharacterSize(30);
    sb_text.setStyle(sf::Text::Bold);
    sb_text.setColor(sf::Color::Yellow);

    items.push_back("sidebar sample text");
    //Fill the items vector with empty strings so that
    //we can use [] to read them:
    for (int i=0 ; i<30; i++){
        items.push_back("");
    }

    read_functions();   // get the function from file

    for(unsigned int i = 0; i < equations.size(); i++)
    {
        //put into the items
        items[SB_FUNCTION_LIST_HEAD+i] = equations[i];
    }

    cout<<"Sidebar: CTOR: Exit."<<endl;
}

void Sidebar::read_functions(){
    ifstream fin;    //file input
    string function;
    fin.open("Functions.txt");
    if(fin.fail())
    {
        cout << "Fail to open the file.\n";
        exit(1);
    }
    while (!fin.eof()) {    //read to end
        getline(fin, function);     //get line
        if(function != "")
            equations.push_back(function);    //add to list
    }
    fin.close();
}
void Sidebar::save_functions(){
    ofstream fout;     //file out
    fout.open("Functions.txt");
    if(fout.fail())
    {
        cout << "Fail to open the file.\n";
        exit(1);
    }
    for(unsigned int i = 0; i < equations.size(); i++)
    {
        fout << equations[i] << endl;    //write to the file
    }
    fout.close();
}

void Sidebar::draw(sf::RenderWindow& window){
    //draw thing in sidebar
    const double VERTICAL_LINE_SPACING = 5.0;
    const double LEFT_MARGIN = 10.0;

    window.draw(rect);
    float height = 10;

    for (vector<string>::iterator it = items.begin();
                                it!= items.end(); it++){
        bool blank = false;
        if (strlen(it->c_str()) == 0){
            //empty rows must be taken into account (getLocalBounds())
            //    but not drawn
            blank = true;
            sb_text.setString("BLANK");
        }
        else{
            sb_text.setString(it->c_str());
        }
        sb_text.setPosition(sf::Vector2f(_left+LEFT_MARGIN, height));
        height += sb_text.getLocalBounds().height+VERTICAL_LINE_SPACING;
        if (!blank)
            window.draw(sb_text);
    }
}

string& Sidebar::operator [](int index){
    return items[index];
}

bool Sidebar::is_exist(string function){
    for(unsigned int i = 0; i < equations.size(); i++){
        if(function == equations[i]){
            //when find
            return true;
        }
    }
    return false;
}

void Sidebar::add_function(string function){
    if(!is_exist(function)){   //if not exist
        //set the function to sidebar
        items[SB_FUNCTION_LIST_HEAD+equations.size()] = function;
        //and add to the list
        equations.push_back(function);
    }
}
string Sidebar::click_on_sidebar(float height){
    int index = height/SB_LINE_HEIGHT;    //the line index in sidebar
    int entry = index - SB_FUNCTION_LIST_HEAD;   //the entry of the list
    if(entry >= 0 && entry < equations.size()){   //when entry in the list
        return equations[entry];
    }
    return "";    //emtpy for not in the click range
}
