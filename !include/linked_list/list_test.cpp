#include "list_test.h"
#include <cstdlib>
#include <ctime>

List<int> get_list1(){
    List<int> list;
    for(int i = 9; i > 0; i--){
        list.Insert_head(i*10);
    }
    return list;
}
List<int> get_list2(){
    List<int> list;
    for(int i = 1; i < 10; i++){
        list.Insert_head(i);
    }
    return list;
}

void test_insert_head(){
    cout<<"--------- TEST_INSERT_HEAD ------------"<<endl;
    List<int> list = get_list1();
    cout<<"\n\nUsing get list1, insert 90, 80 ... 10 into list"<<endl;
    cout<<"Except: 10-20-30-40-50-60-70-80-90" << endl;
    cout<<list<<endl;
    cout<<"--------- END_TEST_INSERT_HEAD ------------"<<endl<<endl;
}

void test_begin(){
    cout<<"------------ TEST_BEGIN ---------------"<<endl;
    List<int> list = get_list1();
    cout<<"\n\nUsing get list1, insert 90, 80 ... 10 into list"<<endl;
    cout<<"Except: 10-20-30-40-50-60-70-80-90" << endl;
    cout<<list<<endl;
    List<int>::Iterator begin = list.Begin();
    cout << "Expect: 10"<<endl;
    cout << "The begin(Head) of the list is: " << *begin <<endl;
    cout<<"--------- END_TEST_BEGIN ------------"<<endl<<endl;
}

void test_insert_after(){
    cout<<"--------- TEST_INSERT_AFTER ------------"<<endl;
    List<int> list = get_list2();
    cout<<"\n\nUsing get list2, insert 1,2,3 ... 9 into list"<<endl;
    cout<<"Except: 9-8-7-6-5-4-3-2-1" << endl;
    cout<<list<<endl;

    cout << "Let the cursor in the begining, then move it to next." << endl;
    List<int>::Iterator cursor = list.Begin();  //make a cursor to the begin
    cursor = list.next(cursor);

    cout << "Insert 88 after the second item." << endl;
    list.insert_after(cursor, 88);
    cout<<"Except: 9-8-88-7-6-5-4-3-2-1" << endl;
    cout<<list<<endl;

    cout<<"--------- END_TEST_INSERT_AFTER ------------"<<endl<<endl;
}

void test_search_list(){
    cout<<"--------- TEST_SEARCH_LIST ------------"<<endl;
    List<int> list = get_list1();
    cout<<"\n\nUsing get list1, insert 90, 80 ... 10 into list"<<endl;
    cout<<"Except: 10-20-30-40-50-60-70-80-90" << endl;
    cout<<list<<endl;
    cout<<"Search number 40, then print the number next to it to verify.\n";
    cout<<"Expect: 50"<<endl;
    List<int>::Iterator target = list.Search_list(40);
    target++;    //get to the next number
    cout << "The number next to 40: " << *target << endl;
    cout<<"--------- END_TEST_SEARCH_LIST ------------"<<endl<<endl;
}
void test_next(){
    cout<<"--------- TEST_NEXT ------------"<<endl;
    List<int> list = get_list2();
    cout<<"\n\nUsing get list2, insert 1,2,3 ... 9 into list"<<endl;
    cout<<"Except: 9-8-7-6-5-4-3-2-1" << endl;
    cout<<list<<endl;

    cout << "Let the cursor in the begining, then call next twice." << endl;
    List<int>::Iterator cursor = list.Begin();  //make a cursor to the begin
    cursor = list.next(cursor);
    cursor = list.next(cursor);

    cout << "Print the cursor item:" << endl;
    cout<<"Except: 7" << endl;
    cout<<"Item: " << *cursor<<endl;

    cout<<"--------- END_TEST_NEXT ------------"<<endl<<endl;
}
void test_previous(){
    cout<<"--------- TEST_PREVIOUS ------------"<<endl;
    List<int> list = get_list2();
    cout<<"\n\nUsing get list2, insert 1,2,3 ... 9 into list"<<endl;
    cout<<"Except: 9-8-7-6-5-4-3-2-1" << endl;
    cout<<list<<endl;

    cout << "Let the cursor in the begining, then call next six." << endl;
    List<int>::Iterator cursor = list.Begin();  //make a cursor to the begin
    for(int i =0; i < 6; i++){
        cursor = list.next(cursor);
    }
    cout << "Then call the previous once:" << endl;
    cursor = list.previous(cursor);
    cout<<"Except: 4" << endl;
    cout<<"Item: " << *cursor <<endl;

    cout<<"--------- END_TEST_PREVIOUS ------------"<<endl<<endl;
}

void test_copy_constructor(){
    cout<<"--------- TEST_COPY_COST ------------"<<endl;
    List<int> list = get_list2();
    cout<<"\n\nUsing get list2, insert 1,2,3 ... 9 into list"<<endl;
    cout<<"Except: 9-8-7-6-5-4-3-2-1" << endl;
    cout<<"[list]: " << list<<endl;

    List<int> list_copy(list);
    //list_copy = list;
    cout<<"Except: 9-8-7-6-5-4-3-2-1" << endl;
    cout<<"[list_copy]: " << list_copy<<endl;

    cout << "Let the cursor in the begining, then move it to next." << endl;
    List<int>::Iterator cursor = list_copy.Begin();
    //make a cursor to the begin
    cursor = list_copy.next(cursor);

    cout << "Insert 88 after the second item." << endl;
    list_copy.insert_after(cursor, 88);
    cout<<"Except: 9-8-88-7-6-5-4-3-2-1" << endl;
    cout<<"[list_copy]: " << list_copy<<endl;

    cout<<"Except: 9-8-7-6-5-4-3-2-1" << endl;
    cout<<"[list]: " << list<<endl;
    cout<<"--------- END_TEST_COPY_COST ------------"<<endl<<endl;
}

void test_insert_before(){
    cout<<"--------- TEST_INSERT_BEFORE ------------"<<endl;
    List<int> list = get_list2();
    cout<<"\n\nUsing get list2, insert 1,2,3 ... 9 into list"<<endl;
    cout<<"Except: 9-8-7-6-5-4-3-2-1" << endl;
    cout<<list<<endl;

    cout << "Let the cursor in the begining, then move it to next." << endl;
    List<int>::Iterator cursor = list.Begin();  //make a cursor to the begin
    cursor = list.next(cursor);

    cout << "Insert 66 before the second item." << endl;
    list.insert_before(cursor, 66);
    cout<<"Except: 9-66-8-7-6-5-4-3-2-1" << endl;
    cout<<list<<endl;

    cout<<"--------- END_TEST_INSERT_BEFORE ------------"<<endl<<endl;
}

void test_insert_sorted(){
    cout<<"--------- TEST_INSERT_SORTED ------------"<<endl;
    List<int> list = get_list1();
    cout<<"\n\nUsing get list1, insert 90, 80 ... 10 into list"<<endl;
    cout<<"Except: 10-20-30-40-50-60-70-80-90" << endl;
    cout<<list<<endl;
    cout<<"Insert 55 into the list with insert_sorted method.\n";
    cout<<"Except: 10-20-30-40-50-55-60-70-80-90" << endl;
    list.InsertSorted(55);
    cout<<list<<endl;
    cout<<"--------- END_TEST_INSERT_SORTED ------------"<<endl<<endl;
}

void test_delete_node(){
    cout<<"--------- TEST_DELETE_NODE ------------"<<endl;
    List<int> list = get_list2();
    cout<<"\n\nUsing get list2, insert 1,2,3 ... 9 into list"<<endl;
    cout<<"Except: 9-8-7-6-5-4-3-2-1" << endl;
    cout<<list<<endl;

    cout << "Let the cursor in the begining, then move it to next." << endl;
    List<int>::Iterator cursor = list.Begin();  //make a cursor to the begin
    cursor = list.next(cursor);

    cout << "DELETE the second item." << endl;
    list.delet_node(cursor);
    cout<<"Except: 9-7-6-5-4-3-2-1" << endl;
    cout<<list<<endl;

    cout<<"--------- END_TEST_DELETE_NODE ------------"<<endl<<endl;
}

void test_bracket_operator(){
    cout<<"--------- TEST_[]_OPERATOR ------------"<<endl;
    List<int> list = get_list2();
    cout<<"\n\nUsing get list2, insert 1,2,3 ... 9 into list"<<endl;
    cout<<"Except: 9-8-7-6-5-4-3-2-1" << endl;
    cout<<list<<endl;

    cout<<"Except: 4" << endl;
    cout << "The list[5] item is: " << list[5]<<endl;

    cout<<"--------- END_TEST_[]_OPERATOR ------------"<<endl<<endl;
}

void test_end(){
    cout<<"------------- TEST_END ----------------"<<endl;
    List<int> list = get_list2();
    cout<<"\n\nUsing get list2, insert 1,2,3 ... 9 into list"<<endl;
    cout<<"Except: 9-8-7-6-5-4-3-2-1" << endl;
    cout<<list<<endl;

    List<int>::Iterator end_item = list.Last_node();
    cout<<"Except: 1" << endl;
    cout << "The end item is: " << *end_item <<endl;

    cout<<"------------- END_TEST_[]_OPERATOR ---------------"<<endl<<endl;
}

void test_copy_operator(){
    cout<<"-------------- TEST_=_OPERATOR ---------------"<<endl;
    List<int> list = get_list2();
    cout<<"\n\nUsing get list2, insert 1,2,3 ... 9 into list"<<endl;
    cout<<"Except: 9-8-7-6-5-4-3-2-1" << endl;
    cout<<"[list]: " << list<<endl;

    cout <<"Initialize the copy list first." << endl;
    List<int> list_copy = get_list1();
    cout<<"Except: 10-20-30-40-50-60-70-80-90" << endl;
    cout<<"[list_copy]: " << list_copy<<endl;

    cout <<"list_copy = list"<<endl;
    list_copy = list;
    cout<<"Except: 9-8-7-6-5-4-3-2-1" << endl;
    cout<<"[list_copy]: " << list_copy<<endl;

    cout << "Let the cursor in the begining, then move it to next." << endl;
    List<int>::Iterator cursor = list_copy.Begin();
    //make a cursor to the begin
    cursor = list_copy.next(cursor);

    cout << "Insert 88 after the second item." << endl;
    list_copy.insert_after(cursor, 88);
    cout<<"Except: 9-8-88-7-6-5-4-3-2-1" << endl;
    cout<<"[list_copy]: " << list_copy<<endl;

    cout<<"Except: 9-8-7-6-5-4-3-2-1" << endl;
    cout<<"[list]: " << list<<endl;
    cout<<"-------------- END_TEST_=_OPERATOR ---------------"<<endl<<endl;
}

void test_general(){
    cout << "==================== TEST LINKED LIST===================="<<endl;
    test_insert_head();
    test_begin();
    test_insert_after();
    test_insert_before();
    test_insert_sorted();
    test_delete_node();
    test_bracket_operator();
    test_end();
    test_copy_constructor();
    test_copy_operator();
    test_search_list();
    test_next();
    test_previous();
    cout << "==================== END LINKED LIST====================="<<endl;
    cout <<endl<<endl;
}


//==========================================================================
//==================== Interactive Test Application ========================
//==========================================================================

void menu(){
    cout << "[R]andom [A]fter  [B]efore [D]elete [S]earch "
            << "[P] Previous  [N] Next  [H]ome  [E]nd  e[X]it" <<endl;
}

void nav_app(){
    List<int> list = init_list();
    List<int>::Iterator cursor = list.Begin();
    List<int>::Iterator save_postion;  //for some special case, it need stay the same
    char command;       //the command charactor
    int item;           //the item recieve

    print_with_cursor(list, cursor);     //print the list with cursor
    menu();
    cin >> command;

    while(toupper(command) != 'X'){
        switch (toupper(command)) {
            case 'R':        //case for random
                item = random_number();    //get the random number
                cursor = list.insert_after(cursor, item);
                break;
            case 'A':       //case for insert after
                cout << "Please enter you item: ";
                cin >> item;         //ask for item
                cursor = list.insert_after(cursor, item);    //insert
                break;
            case 'B':       //case for insert before
                cout << "Please enter you item: ";
                cin >> item;
                cursor = list.insert_before(cursor, item);
                break;
            case 'D':        //case to delete the cursor
                if(list.Begin() != nullptr){
                    //when empty, it will not delete
                    list.delet_node(cursor);
                }
                cursor = list.Begin();
                break;
            case 'S':          //search a item
                cout << "Please enter your item: ";
                cin >> item;
                save_postion = cursor;
                cursor = list.Search_list(item);
                if(cursor == nullptr){     //when it is not exist
                    cursor = save_postion;
                }
                break;
            case 'P':           //previous the cursor
                cursor = list.previous(cursor);
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

/* Since this print method is only for this application with cursor
 * Thus, I put in in the test class file
 */
void print_with_cursor(const List<int>& list, List<int>::Iterator cursor){
    cout <<"..    ..    ..    ..    ..    ..    ..    ..    ..    .."<<endl;
    List<int>::Iterator walker = list.Begin();   //walker go throught the list
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

int random_number(){
    srand(time(NULL));
    int number = (rand() % 100) + 1;   //random number from 1-100
    return number;
}

List<int> init_list(){
    srand(time(NULL));
    List<int> list;
    List<int>::Iterator cursor = list.Begin();    //cursor set to begin
    int item;
    for(int i = 0; i < 5; i++){
        //if use random_number(), will give out same number
        item = (rand() % 100) + 1;     //random number
        cursor = list.insert_after(cursor, item);    //insert it
    }
    return list;
}
