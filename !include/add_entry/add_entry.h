#ifndef ADD_ENTRY_H
#define ADD_ENTRY_H

#include <iostream>
#include <string>
#include "../../!include/one_d_pointer/one_d_pointer_tool.h"

template<typename T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity);
//add the new_entry to the list, if it reach the end of the capacity, then
//double the capacity

template<typename T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity);
//remove the detele_me in the list, if it below the 1/4 of the capacity, then
//cut the capacity to half

template<typename T>
T* insert_at_index(T* list, const T& new_entry, int index, int& size
                   , int& capacity);
//insert the new entry element to the index position in the list

template<typename T>
T* remove_at_index(T* list, int index, int& size, int& capacity);
//remove the element in the index position in the list

template<typename T>
T* check_capacity(T* list, int after_size, int current_size, int& capacity);
//check the after capacity if need to recallocate the list, if so, then
//reacllocate the list, if not, it will return back the old list


template<typename T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity){
    T* new_list;
    //check_capacity for new size
    new_list = check_capacity(list, size + 1, size, capacity);
    T* walker = new_list;
    walker += size;           //move walker to the last position
    *walker = new_entry;         //assign the new entry to the last position
    size++;
    return new_list;
}

template<typename T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity){
    T* new_list;
    T* target = search_entry(list, delete_me, size);
    if(target != nullptr){
        //check_capacity for new size
        new_list = check_capacity(list, size - 1, size, capacity);
        //shift left the list after the detele element position
        shift_left(new_list, size, target);
        return new_list;
    }else{
        return list;
    }
}

template<typename T>
T* insert_at_index(T* list, const T& new_entry, int index, int& size
                   , int& capacity){
    //check_capacity for new size
    list = check_capacity(list, size + 1, size, capacity);
    T* target = list + index;
    shift_right(list, size, target);    //shift element to left
    *target = new_entry;   //set the target index element to new entry
    return list;
}

template<typename T>
T* remove_at_index(T* list, int index, int& size, int& capacity){
    //check_capacity for new size
    list = check_capacity(list, size - 1, size, capacity);
    shift_left(list, size, list + index);    //shift element to left
    return list;
}

template<typename T>
T* check_capacity(T* list, int after_size, int current_size, int& capacity){
    T* new_list;
    if(after_size > capacity){   // if the size reach the capacity after add
        new_list = reallocate(list, capacity, 2 * capacity, current_size);
        //reallocate the list with double capacity
    }else if(after_size <= capacity / 4){      //size below the 1/4 capacity
        //reallocate the list with half capacity
        new_list = reallocate<T>(list, capacity, capacity / 2, current_size);
    }else{
        new_list = list;   //keep it same
    }
    return new_list;
}

#endif // ADD_ENTRY_H
