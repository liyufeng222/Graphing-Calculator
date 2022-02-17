#ifndef SORTED_LIST_TEST_H
#define SORTED_LIST_TEST_H

#include "sorted_list.h"

void menu();
//the menu option
void nav_app();
//the application that ask user to choic option, and do option
void print_with_cursor(const Sorted_List<int>& list,
                       Sorted_List<int>::Iterator cursor);
//print function with the cursor
/* Since this print method is only for this application with cursor
 * Thus, I put in in the test class file
 */
int random_number();
//generate a random number
Sorted_List<int> init_list(bool order, bool unique);
//initialize a list with five number in sorted

#endif // SORTED_LIST_TEST_H
