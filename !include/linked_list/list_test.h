#ifndef LIST_TEST_H
#define LIST_TEST_H
#include "linked_list.h"

List<int> get_list1();
//list of 10,20,30,40,50,60,70,80,90
List<int> get_list2();
//list of 9,8,7,6,5,4,3,2,1
void test_insert_head();
//test of insert head
void test_begin();
//test of begin;
void test_insert_after();
//test of insert after
void test_insert_before();
//test of insert after
void test_insert_sorted();
//test insert sort
void test_delete_node();
//test delete node
void test_bracket_operator();
//test [] operator
void test_end();
//test end;
void test_copy_operator();
//test = operator
void test_search_list();
//test of search list
void test_next();
//test of next
void test_previous();
//test of previous
void test_copy_constructor();
//test the copy constructor
void test_general();
//test foe all test

//=====================Interactive Test Application==================
void menu();
//the menu option
void nav_app();
//the application that ask user to choic option, and do option
void print_with_cursor(const List<int>& list, List<int>::Iterator cursor);
//print function with the cursor
/* Since this print method is only for this application with cursor
 * Thus, I put in in the test class file
 */
int random_number();
//generate a random number
List<int> init_list();
//initialize a list with five number




#endif // LIST_TEST_H
