#include "grid.h"
#include <ctime>


grid::grid()
{
    set_up();    //set up the grid in default way
    keepGoing = true;
}

bool grid::check_end(){
    if((prey_number == 0 && predator_number == 0) ||
            prey_number == (MAX-2)*(MAX-2)){
        //when the grid is empty or all prey
        return true;
    }
    return false;
}

void grid::set_up(){
    round = 1;
    prey_number = PREY_NUM;
    predator_number = PREDATOR_NUM;
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            _grid[i][j] = nullptr;
            //let all the space become empty(nullptr)
        }
    }
    fill_grid();     //fill the grid with default wall, preys, predators
}

void grid::fill_grid(){
    build_wall();     //build the wall
    fill_prey();     //fill preys in
    fill_predator();     //fill predator in
}
void grid::fill_prey(){
     srand(time(NULL));
    int prey_count = 0;
    while(prey_count < PREY_NUM){    //when it not reach the require number
        int row = rand() % MAX;
        int col = rand() % MAX;     //get random row, col in the MAX size
        if(_grid[row][col] == nullptr){
            //when that location is empty
            _grid[row][col] = new Prey(row, col);
            //create a new prey in there
            prey_count++;     //prey count add one
        }
    }
}
void grid::fill_predator(){
    srand(time(NULL));
    int predator_count = 0;
    while(predator_count < PREDATOR_NUM){
        //when it not reach the require number
        int row = rand() % MAX;
        int col = rand() % MAX;     //get random row, col in the MAX size
        if(_grid[row][col] == nullptr){
            //when that location is empty
            _grid[row][col] = new Predator(row, col);
            //create a new predator in there
            predator_count++;    //predator count add one
        }
    }
}
void grid::build_wall(){
    for(int i = 0; i < MAX; i++){    //row and col MAX number
        _grid[0][i] = new Wall(0, i);   //upper wall bound
        _grid[MAX-1][i] = new Wall(MAX-1, i);    //lower wall bound
        _grid[i][0] = new Wall(i, 0);    //left bound wall
        _grid[i][MAX-1] = new Wall(i, MAX-1);   //right bound wall
    }
}
bool grid::status() const{
    return keepGoing;    //return the status
}
void grid::command(int _command, int row, int col){
    switch (_command) {
    case 1:      //stop or continue the grid
        keepGoing = !keepGoing;
        break;
    case 2:      //case for kill or breed in a given location for predator
        killOrBreed(1, row, col);
        break;
    case 3:      //case for kill or breed in a given location for prey
        killOrBreed(2, row, col);
        break;
    default:
        break;
    }
}

void grid::step(){
    if(keepGoing){
        if(check_end()){
            set_up();      //when the grid is end, reset up the grid
        }
        move();     //first move them
        breed();     //to see if they can breed
        kill();       //check if them are being killed
        reset_moved();    //reset their move status
        round++;
    }
}

void grid::move(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(_grid[i][j] != nullptr){    //if there is a creature
                _grid[i][j]->move(_grid);   //let it move
            }
        }
    }
}
void grid::breed(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(_grid[i][j] != nullptr){    //if there is a creature
                _grid[i][j]->breed(_grid);  //let ti breed
            }
        }
    }
}
void grid::kill(){
    //NOTE: Prey kill is being processing when the predator move
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(_grid[i][j] != nullptr && _grid[i][j]->get_type() == 1){
                //if there is a predator
                static_cast<Predator*>(_grid[i][j])->die(_grid);
                //to see if the predator goin to die
            }
        }
    }
}

void grid::reset_moved(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(_grid[i][j] != nullptr){
                _grid[i][j]->set_moved(false);
                //make all creature moved status became fasle
            }
        }
    }
}
ostream& operator <<(ostream& outs, const grid& g){
    for(int i = 0; i < MAX; i++){
        outs << "|";
        for(int j = 0; j < MAX; j++){
            if(g._grid[i][j] != nullptr){
                cout << *g._grid[i][j] <<"|";    //out put every creature
            }else{
                outs << " |";       //empty then it is a space
            }
        }
        outs << endl;
    }
    return outs;
}

void grid::killOrBreed(int type, int row, int col){
    if(_grid[row][col] != nullptr){
        delete _grid[row][col];    //delet itself
        _grid[row][col] = nullptr;     //make the original location to nullptr
    }else{
        switch(type){
            case 1:    //when it is want predator
                _grid[row][col] = new Predator(row, col);
                break;
            case 2:     //when it want a prey
                _grid[row][col] = new Prey(row, col);
                break;
        }
    }
}

void grid::Draw(sf::RenderWindow& window){
    int prey_num = 0;
    int pred_num = 0;
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            //for loop go throught the grid
            if(_grid[i][j] != nullptr){
                _grid[i][j]->draw(window, i*SINGLE_SPACE, j*SINGLE_SPACE);
                //let the creature draw itself
                if(_grid[i][j]->get_type() == 2){   //when the type is prey
                    prey_num++;  //count add one
                }
                if(_grid[i][j]->get_type() == 1){  //when the type is predator
                    pred_num++;    //count add one
                }
            }
        }
    }
    prey_number = prey_num;  //assign final count to member variable
    predator_number = pred_num;
}

int grid::get_prey_num(){
    return prey_number;    //return prey number
}
int grid::get_predator_num(){
    return predator_number;    //return predator number
}

int grid::get_round_num(){
    return round;      //return round number
}
