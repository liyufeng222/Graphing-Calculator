#include "node_test.h"

node<int>* _get_list1(){
    node<int>* head_ptr = nullptr;
    for(int i = 1; i < 10; i++){
        _insert_head(head_ptr, i*10);
    }
    return head_ptr;
}
node<int>* _get_list2(){
    node<int>* head_ptr = nullptr;
    for(int i = 9; i > 0; i--){
        _insert_head(head_ptr, i);
    }
    return head_ptr;
}

void _test_print_backward(){
    cout<<"--------- TEST_PRINT_BACKWARD ------------"<<endl;
    node<int>* head_ptr = _get_list2();
    cout<<"\n\nUsing get list1, insert 9,8,7,...1 into list head"<<endl;
    cout<<"Except: 1-2-3-4-5-6-7-8-9" << endl;
    _print_list(head_ptr);
    cout<<"Then, Print it from backward";
    cout<<"Except: 9-8-7-6-5-4-3-2-1" << endl;
    cout<<"H->";
    _print_list_backward(head_ptr);
    cout<<"|||"<<endl;
    cout<<"--------- END_TEST_PRINT_BACKWARD ------------"<<endl<<endl;
}
void _test_insert_head(){
    cout<<"--------- TEST_INSERT_HEAD ------------"<<endl;
    node<int>* head_ptr = _get_list1();
    cout<<"\n\nUsing get list1, insert 10, 20 ... 90 into list head"<<endl;
    cout<<"Except: 90-80-70-60-50-40-30-20-10" << endl;
    _print_list(head_ptr);
    cout<<"--------- END_TEST_INSERT_HEAD ------------"<<endl<<endl;
}

void _test_insert_after(){
    cout<<"--------- TEST_INSERT_AFTER ------------"<<endl;
    node<int>* head_ptr = _get_list2();
    cout<<"\n\nUsing get list1, insert 9,8,7,...1 into list head"<<endl;
    cout<<"Except: 1-2-3-4-5-6-7-8-9" << endl;
    _print_list(head_ptr);

    cout << "Let the cursor in the begining, then move it to next." << endl;
    node<int>* cursor = head_ptr;  //make a cursor to the begin
    cursor = Next(cursor);

    cout << "Insert 66 after the second item." << endl;
    _insert_after(head_ptr, cursor, 66);
    cout<<"Except: 1-2-66-3-4-5-6-7-8-9" << endl;
    _print_list(head_ptr);

    cout<<"--------- END_TEST_INSERT_AFTER ------------"<<endl<<endl;
}

void _test_search_list(){
    cout<<"--------- TEST_SEARCH_LIST ------------"<<endl;
    node<int>* head_ptr = _get_list1();
    cout<<"\n\nUsing get list1, insert 10, 20 ... 90 into list head"<<endl;
    cout<<"Except: 90-80-70-60-50-40-30-20-10" << endl;
    _print_list(head_ptr);
    cout<<"Search number 50, then print the number next to it to verify.\n";
    cout<<"Expect: 40"<<endl;
    node<int>* target = _search_list(head_ptr, 50);
    target = target->_next;    //get to the next number
    cout << "The number next to 50: " << target->_item << endl;
    cout<<"--------- END_TEST_SEARCH_LIST ------------"<<endl<<endl;
}

void _test_next(){
    cout<<"--------- TEST_NEXT ------------"<<endl;
    node<int>* head_ptr = _get_list2();
    cout<<"\n\nUsing get list1, insert 9,8,7,...1 into list head"<<endl;
    cout<<"Except: 1-2-3-4-5-6-7-8-9" << endl;
    _print_list(head_ptr);

    cout << "Let the cursor in the begining, then call next twice." << endl;
    node<int>* cursor = head_ptr;  //make a cursor to the begin
    cursor = Next(cursor);
    cursor = Next(cursor);

    cout << "Print the cursor item:" << endl;
    cout<<"Except: 3" << endl;
    cout<<"Item: " << cursor->_item<<endl;

    cout<<"--------- END_TEST_NEXT ------------"<<endl<<endl;
}

void _test_previous(){
    cout<<"--------- TEST_PREVIOUS ------------"<<endl;
    node<int>* head_ptr = _get_list2();
    cout<<"\n\nUsing get list1, insert 9,8,7,...1 into list head"<<endl;
    cout<<"Except: 1-2-3-4-5-6-7-8-9" << endl;
    _print_list(head_ptr);

    cout << "Let the cursor in the begining, then call next five." << endl;
    node<int>* cursor = head_ptr;  //make a cursor to the begin
    for(int i =0; i < 5; i++){
        cursor = Next(cursor);
    }
    cout << "Then call the previous once:" << endl;
    cursor = _previous(head_ptr, cursor);
    cout<<"Except: 5" << endl;
    cout<<"Item: " << cursor->_item<<endl;

    cout<<"--------- END_TEST_PREVIOUS ------------"<<endl<<endl;
}

void _test_insert_before(){
    cout<<"--------- TEST_INSERT_BEFORE ------------"<<endl;
    node<int>* head_ptr = _get_list2();
    cout<<"\n\nUsing get list1, insert 9,8,7,...1 into list head"<<endl;
    cout<<"Except: 1-2-3-4-5-6-7-8-9" << endl;
    _print_list(head_ptr);

    cout << "Let the cursor in the begining, then move it to next." << endl;
    node<int>* cursor = head_ptr;  //make a cursor to the begin
    cursor = Next(cursor);

    cout << "Insert 66 before the second item." << endl;
    _insert_before(head_ptr, cursor, 66);
    cout<<"Except: 1-66-2-3-4-5-6-7-8-9" << endl;
    _print_list(head_ptr);

    cout<<"--------- END_TEST_INSERT_BEFORE ------------"<<endl<<endl;
}

void _test_copy_list(){
    cout<<"--------- TEST_COPY_LIST ------------"<<endl;
    node<int>* head_ptr = _get_list1();
    cout<<"\n\nUsing get list1, insert 10, 20 ... 90 into list head"<<endl;
    cout<<"Except: 90-80-70-60-50-40-30-20-10" << endl;
    cout << "List 1: ";
    _print_list(head_ptr);
    cout<<"Copy the list to another list.\n";
    cout<<"Except: 90-80-70-60-50-40-30-20-10" << endl;
    node<int>* head_ptr_copy = _copy_list(head_ptr);
    cout << "List 2: ";
    _print_list(head_ptr_copy);

    cout << "Let the cursor in the begining, then move it to next." << endl;
    node<int>* cursor = head_ptr_copy;  //make a cursor to the begin
    cursor = Next(cursor);

    cout << "Insert 66 before the second item." << endl;
    _insert_before(head_ptr_copy, cursor, 66);
    cout<<"Except: 90-66-80-70-60-50-40-30-20-10" << endl;
    cout << "List 2: ";
    _print_list(head_ptr_copy);
    cout<<"Except: 90-80-70-60-50-40-30-20-10" << endl;
    cout << "List 1: ";
    _print_list(head_ptr);
    cout<<"--------- END_TEST_COPY_LIST ------------"<<endl<<endl;
}

void _test_clear_list(){
    cout<<"--------- TEST_CLEAR_LIST ------------"<<endl;
    node<int>* head_ptr = _get_list2();
    cout<<"\n\nUsing get list1, insert 9,8,7,...1 into list head"<<endl;
    cout<<"Except: 1-2-3-4-5-6-7-8-9" << endl;
    _print_list(head_ptr);

    cout << "Let clear the list." << endl;
    _clearList(head_ptr);

    cout<<"Except: (null)" << endl;
    _print_list(head_ptr);

    cout<<"--------- END_CLEAR_LIST ------------"<<endl<<endl;
}

void _test_at(){
    cout<<"-------------- TEST_AT ------------------"<<endl;
    node<int>* head_ptr = _get_list2();
    cout<<"\n\nUsing get list1, insert 9,8,7,...1 into list head"<<endl;
    cout<<"Except: 1-2-3-4-5-6-7-8-9" << endl;
    _print_list(head_ptr);
    cout<<"Except: 3" << endl;
    cout << "The item in index 2 is: " << _at(head_ptr, 2) << endl;
    cout<<"------------- END_TEST_AT --------------"<<endl<<endl;
}

void _test_delete_node(){
    cout<<"--------- TEST_DELETE_NODE ------------"<<endl;
    node<int>* head_ptr = _get_list2();
    cout<<"\n\nUsing get list1, insert 9,8,7,...1 into list head"<<endl;
    cout<<"Except: 1-2-3-4-5-6-7-8-9" << endl;
    _print_list(head_ptr);

    cout << "Let the cursor in the begining, then move it to next." << endl;
    node<int>* cursor = head_ptr;  //make a cursor to the begin
    cursor = Next(cursor);

    cout << "Delete the second item." << endl;
    _delete_node(head_ptr, cursor);
    cout<<"Except: 1-3-4-5-6-7-8-9" << endl;
    _print_list(head_ptr);

    cout<<"--------- END_TEST_DELETE_NODE ------------"<<endl<<endl;
}
//test the delete node
void _test_remove_head(){
    cout<<"--------- TEST_REMOVE_HEAD ------------"<<endl;
    node<int>* head_ptr = _get_list1();
    cout<<"\n\nUsing get list1, insert 10, 20 ... 90 into list head"<<endl;
    cout<<"Except: 90-80-70-60-50-40-30-20-10" << endl;
    _print_list(head_ptr);
    cout<<"Remove the head.\n";
    _remove_head(head_ptr);
    cout<<"Expect: 80-70-60-50-40-30-20-10" << endl;
    _print_list(head_ptr);
    cout<<"--------- END_TEST_REMOVE_HEAD ------------"<<endl<<endl;
}
//test the remove head
void _test_last_node(){
    cout<<"--------- TEST_LAST_NODE ------------"<<endl;
    node<int>* head_ptr = _get_list1();
    cout<<"\n\nUsing get list1, insert 10, 20 ... 90 into list head"<<endl;
    cout<<"Except: 90-80-70-60-50-40-30-20-10" << endl;
    _print_list(head_ptr);
    cout<<"Expect: 10" << endl;
    node<int>* last = _last_node(head_ptr);
    cout<<"The last node is: " << last->_item <<endl;
    cout<<"--------- END_TEST_LAST_NODE ------------"<<endl<<endl;
}
//test the last node
void _test_where_this_goes(){
    cout<<"--------- TEST_WHERE_THIS_GOES ------------"<<endl;
    node<int>* head_ptr = _get_list1();
    cout<<"\n\nUsing get list1, insert 10, 20 ... 90 into list head"<<endl;
    cout<<"Except: 90-80-70-60-50-40-30-20-10" << endl;
    _print_list(head_ptr);
    cout << "Let enter 68, and it is descending." << endl;
    node<int>* target = _whereThisGoes(head_ptr, 68, false);
    cout<<"Except: 70" << endl;
    cout << "It should insert after: " << target->_item <<endl;
    cout<<"--------- END_TEST_WHERE_THIS_GOES ------------"<<endl<<endl;
}
//test where this goes
void _test_insert_sorted(){
    cout<<"--------- TEST_INSERT_SORTED ------------"<<endl;
    node<int>* head_ptr = _get_list1();
    cout<<"\n\nUsing get list1, insert 10, 20 ... 90 into list head"<<endl;
    cout<<"Except: 90-80-70-60-50-40-30-20-10" << endl;
    _print_list(head_ptr);
    cout << "Let insert 58, and it is descending." << endl;
    _insertSorted(head_ptr, 58, false);
    cout<<"Except: 90-80-70-60-58-50-40-30-20-10" << endl;
    _print_list(head_ptr);
    cout<<"--------- END_TEST_INSERT_SORTED ------------"<<endl<<endl;
}
//test insert the sorted list

void _test_general(){
    cout << "======================= TEST NODE======================"<<endl;
    _test_print_backward();
    _test_insert_head();
    _test_insert_after();
    _test_search_list();
    _test_next();
    _test_previous();
    _test_insert_before();
    _test_copy_list();
    _test_clear_list();
    _test_at();
    _test_delete_node();
    _test_remove_head();
    _test_last_node();
    _test_where_this_goes();
    _test_insert_sorted();
    cout << "======================= END NODE======================"<<endl;
    cout <<endl<<endl;
}

