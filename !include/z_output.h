#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H

/*
***** ALL RESULTS ARE VERIFIED ******
*****

======================= TEST NODE======================
--------- TEST_INSERT_HEAD ------------


Using get list1, insert 10, 20 ... 90 into list head
Except: 90-80-70-60-50-40-30-20-10
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->|||
--------- END_TEST_INSERT_HEAD ------------

--------- TEST_INSERT_AFTER ------------


Using get list1, insert 9,8,7,...1 into list head
Except: 1-2-3-4-5-6-7-8-9
H->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||
Let the cursor in the begining, then move it to next.
Insert 66 after the second item.
Except: 1-2-66-3-4-5-6-7-8-9
H->[1]->[2]->[66]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||
--------- END_TEST_INSERT_AFTER ------------

--------- TEST_SEARCH_LIST ------------


Using get list1, insert 10, 20 ... 90 into list head
Except: 90-80-70-60-50-40-30-20-10
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->|||
Search number 50, then print the number next to it to verify.
Expect: 40
The number next to 50: 40
--------- END_TEST_SEARCH_LIST ------------

--------- TEST_NEXT ------------


Using get list1, insert 9,8,7,...1 into list head
Except: 1-2-3-4-5-6-7-8-9
H->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||
Let the cursor in the begining, then call next twice.
Print the cursor item:
Except: 3
Item: 3
--------- END_TEST_NEXT ------------

--------- TEST_PREVIOUS ------------


Using get list1, insert 9,8,7,...1 into list head
Except: 1-2-3-4-5-6-7-8-9
H->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||
Let the cursor in the begining, then call next five.
Then call the previous once:
Except: 5
Item: 5
--------- END_TEST_PREVIOUS ------------

======================= END NODE======================


==================== TEST LINKED LIST====================
--------- TEST_INSERT_HEAD ------------
/n/nUsing get list1, insert 10, 20 ... 90 into list
Except: 10-20-30-40-50-60-70-80-90
H->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

--------- END_TEST_INSERT_HEAD ------------

------------ TEST_BEGIN ---------------
/n/nUsing get list1, insert 10, 20 ... 90 into list
Except: 10-20-30-40-50-60-70-80-90
H->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

Expect: 10
The begin(Head) of the list is: 10
--------- END_TEST_BEGIN ------------

--------- TEST_INSERT_AFTER ------------
/n/nUsing get list1, insert 9,8,7,...1 into list
Except: 9-8-7-6-5-4-3-2-1
H->[9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->|||

Let the cursor in the begining, then move it to next.
Insert 88 after the second item.
Except: 9-8-88-7-6-5-4-3-2-1
H->[9]->[8]->[88]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->|||

--------- END_TEST_INSERT_AFTER ------------

--------- TEST_SEARCH_LIST ------------
/n/nUsing get list1, insert 10, 20 ... 90 into list
Except: 10-20-30-40-50-60-70-80-90
H->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||

Search number 40, then print the number next to it to verify.
Expect: 50
The number next to 40: 50
--------- END_TEST_SEARCH_LIST ------------

--------- TEST_NEXT ------------
/n/nUsing get list1, insert 9,8,7,...1 into list
Except: 9-8-7-6-5-4-3-2-1
H->[9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->|||

Let the cursor in the begining, then call next twice.
Print the cursor item:
Except: 7
Item: 7
--------- END_TEST_NEXT ------------

--------- TEST_PREVIOUS ------------
/n/nUsing get list1, insert 9,8,7,...1 into list
Except: 9-8-7-6-5-4-3-2-1
H->[9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->|||

Let the cursor in the begining, then call next six.
Then call the previous once:
Except: 4
Item: 4
--------- END_TEST_PREVIOUS ------------

==================== END LINKED LIST=====================


------------------------END----------------------------
Press <RETURN> to close this window...



*/

#endif // Z_OUTPUT_H
