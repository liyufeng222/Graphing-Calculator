#include "sorted_list_test.h"

#include <cstdlib>
#include <ctime>


void nav_app(){
    int option;
    cout << "Please enter if the sorted list ascending or descending."<<endl;
    cout << "1) Ascending      2) Descending"<<endl;
    cin >> option;
    bool order = option % 2;    // 1 % 2 = 1, true; 2 % 2 = 0, false;

    cout << "Please enter if the sorted list unique or Un-unique."<<endl;
    cout << "1) unique      2) un-unique"<<endl;
    cin >> option;
    bool unique = option % 2;    // 1 % 2 = 1, true; 2 % 2 = 0, false;

    Sorted_List<int> list = init_list(order, unique);
    Sorted_List<int>::Iterator cursor = list.Begin();
    Sorted_List<int>::Iterator save_postion;
    //for some special case, it need stay the same
    char command;       //the command charactor
    int item;           //the item recieve

    print_with_cursor(list, cursor);     //print the list with cursor
    menu();
    cin >> command;

    while(toupper(command) != 'X'){
        switch (toupper(command)) {
            case 'R':        //case for random
                item = random_number();    //get the random number
                cursor = list.Insert(item);
                break;
            case 'I':       //case for insert
                cout << "Please enter you item: ";
                cin >> item;         //ask for item
                cursor = list.Insert(item);    //insert
                break;
            case 'D':        //case to delete the cursor
                if(list.Begin() != nullptr){
                    //when empty, it will not delete
                    list.Delete(cursor);
                }
                cursor = list.Begin();
                break;
            case 'S':          //search a item
                cout << "Please enter your item: ";
                cin >> item;
                save_postion = cursor;
                cursor = list.Search(item);
                if(cursor == nullptr){     //when it is not exist
                    cursor = save_postion;
                }
                break;
            case 'P':           //previous the cursor
                cursor = list.Prev(cursor);
                if(cursor == nullptr){      //when it is at the head_ptr
                    cursor = list.Begin();    //keep it at begin
                }
                break;
            case 'N':         //next the cursor
                save_postion = cursor;
                cursor++;
                if(cursor == nullptr){     //when reach the end
                    cursor = save_postion;     //keep it at the end
                }
                break;
            case 'H':
                cursor = list.Begin();       //cursor to begin
                break;
            case 'E':
                cursor = list.Last_node();       //cursor to end
                break;
            default:
                cout << "Please enter a right command."<<endl;
        }
        print_with_cursor(list, cursor);   //print the list
        menu();
        cin >> command;         //ask again
    }
}

void menu(){
    cout << "[R]andom [I]nsert [D]elete [S]earch "
            << "[P] Previous  [N] Next  [H]ome  [E]nd  e[X]it" <<endl;
}
//the application that ask user to choic option, and do option
void print_with_cursor(const Sorted_List<int>& list,
                       Sorted_List<int>::Iterator cursor){
    cout <<"..    ..    ..    ..    ..    ..    ..    ..    ..    .."<<endl;
    Sorted_List<int>::Iterator walker = list.Begin();

    //walker go throught the list
    cout << "H->";
    while(walker != list.End()){
        if(walker == cursor){
            cout<<"{"<<*walker<<"}->";    //output format for cursor
        }else{
            cout<<"["<<*walker<<"]->";
        }
        walker++;
    }
    cout << "|||" << endl;
}
//print function with the cursor
/* Since this print method is only for this application with cursor
 * Thus, I put in in the test class file
 */
int random_number(){
    srand(time(NULL));
    int number = (rand() % 100) + 1;   //random number from 1-100
    return number;
}

//generate a random number
Sorted_List<int> init_list(bool order, bool unique){
    srand(time(NULL));
    Sorted_List<int> list(order, unique);
    int item;
    for(int i = 0; i < 5; i++){
        //if use random_number(), will give out same number
        item = (rand() % 100) + 1;     //random number
        list.Insert(item);    //insert it
    }
    return list;
}
//initialize a list with five number
