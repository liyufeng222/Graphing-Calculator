#ifndef ONE_D_POINTER_TOOL_H
#define ONE_D_POINTER_TOOL_H

#include <iostream>
using namespace std;

//======================template Function============================

template<typename T>
void init1D(T* one_D, int size, const T& entry);
//initial a 1 D array in the 2 D array

template<typename T>
T* allocate(int capacity);
//allocate a new dynamic array

template<typename T>
void copy_list(T *dest, T* src, int many_to_copy);
//copy the size of elements in the src array to dest array

template<typename T>
void shift_left(T* array, int& size, T* current);
//shift all the elements after the current postion to left

template <typename T>
void shift_right(T* array, int& size, T* current);
//shift all the elements after the curent position to right

template<typename T>
T* search_entry(T* list, const T& find_me, int size);
//search the list to find the position of the entry

template<typename T>
bool search_entry(T* list, const T& find_me, int size, int& position);
//search the list to find the entry, if found return true, else false
//positon pass by reference

template<typename T>
void print_list(T* list, int size);
//print the list in format

template<typename T>
T* reallocate(T* list, int& capacity, int new_capacity, int size);
//reallocate the new array with the new_capacity and have size of the element
//in the previous list

template<typename T>
T* resize(T* src, int& old_capacity, int new_capacity, T init_value);
//resize means reallocate the src array to the new_capacity, fill the
//array with the init_value to the end

//=========================Non-template function=============================

void init1D_dbug(int* one_D, int size, const int& start_value);
//initial 1D for dbug purpose

//=========================Definition=========================================

template<typename T>
void init1D(T* one_D, int size, const T& entry){
    for(int i = 0; i < size; i++, one_D++){
        *one_D = entry;  //set every element in the 1 D to entry
    }
}

template<typename T>
T* allocate(int capacity){
    /*const bool debug = false;
    if (debug) cout<<"allocate: capacity: "<<capacity<<endl;*/
    return new T[capacity];      //new dynamic array with capacity
}

template<typename T>
void copy_list(T *dest, T* src, int many_to_copy){
    for(int i = 0; i < many_to_copy; i++){
        *dest = *src;      //assign the element to destination list
        dest++;
        src++;
    }
}

template<typename T>
void shift_left(T* array, int& size, T* current){
    T* end = array + size;        //initial the end pointer
    T* next = current + 1;         //initial the next pointer
    while(next < end){
        *current = *next;        //assign the next position element to current
        current++;
        next++;
    }
    size--;
}

template <typename T>
void shift_right(T* array, int& size, T* current){
    size++;
    T* walker = array + size - 1;  //initial the walker to last elment
    T* previous = walker - 1;         //initial the previous pointer
    while(walker > current){
        *walker = *previous;     //assign the left position element to right
        walker--;
        previous--;
    }
}

template<typename T>
T* search_entry(T* list, const T& find_me, int size){
    T* end = list + size;      //initial the end pointer
    T* current = list;          //initial the end pointer
    while(current < end){
        if(*current == find_me){      //current element match the target
            return current;
        }
        current++;
    }
    return nullptr;            //at the end none of them matching return null
}

template<typename T>
bool search_entry(T* list, const T& find_me, int size, int& position){
    T* end = list + size;      //initial the end pointer
    T* current = list;          //initial the end pointer
    while(current < end){
        if(*current == find_me){      //current element match the target
            position = current - list;   //position in the array
            return true;
        }
        current++;
    }
    position = -1;
    return false;
}

template<typename T>
void print_list(T* list, int size){
    for(int i = 0; i < size; i++){
        cout << *list << " ";  //format
        list++;
    }
    cout << endl;
}

template<typename T>
T* reallocate(T* list, int& capacity, int new_capacity, int size){
    T* new_list = allocate<T>(new_capacity);    //new list
    capacity = new_capacity;      //update size
    copy_list(new_list, list, size);    //copy the old elements to new
    delete[] list;
    return new_list;
}

template<typename T>
T* resize(T* src, int& old_capacity, int new_capacity, T init_value){
    T* new_list = allocate<T>(new_capacity);    //new list
    copy_list(new_list, src, old_capacity);    //copy the old elements to new
    init1D(new_list + old_capacity, new_capacity - old_capacity, init_value);
    //initialize the rest space to init_value
    old_capacity = new_capacity;      //update size
    delete[] src;
    return new_list;
}

#endif // ONE_D_POINTER_TOOL_H
