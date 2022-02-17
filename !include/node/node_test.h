#ifndef NODE_TEST_H
#define NODE_TEST_H
#include "node.h"

node<int>* _get_list1();
//list of 90,80,70,60,50,40,30,20,10
node<int>* _get_list2();
//list of 1,2,3,4,5,6,7,8,9

void _test_print_backward();
//test of print backward
void _test_insert_head();
//test of insert head
void _test_insert_after();
//test of insert after
void _test_search_list();
//test of search list
void _test_next();
//test of next
void _test_previous();
//test of previous
void _test_insert_before();
//test of insert before
void _test_copy_list();
//test the copy list function
void _test_clear_list();
//test the clear list function
void _test_at();
//test at (index) function
void _test_delete_node();
//test the delete node
void _test_remove_head();
//test the remove head
void _test_last_node();
//test the last node
void _test_where_this_goes();
//test where this goes
void _test_insert_sorted();
//test insert the sorted list


void _test_general();
//test for all test

#endif // NODE_TEST_H
