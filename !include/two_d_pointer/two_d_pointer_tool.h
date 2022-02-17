#ifndef TWO_D_POINTER_TOOL_H
#define TWO_D_POINTER_TOOL_H

#include <iostream>
#include <cassert>
#include "../../!include/one_d_pointer/one_d_pointer_tool.h"

//===========================template Funtion===============================

template<typename T>
void init2D(T** two_D, int* size, const T& entry);
//initial a 2 D pointer to the entry value

template<typename T>
void print2D(T** two_D, int* size);
//print the 2 D array

template<typename T>
void deallocate(T** two_D, int* size);
//deallocate the 2 D array

template<typename T>
T** allocate2D(int* size);
//allocate the 2 D with sizes

template<typename T>
T read(T** two_D, int* size, int row, int col);
//read the element in row column

template<typename T>
void write(T** two_D, int* size, int row, int col, const T& entry);
//write the entry into the row col

template<typename T>
T* search_twod(T** two_d, int* sizes, const T& key);
//search the key in the 2 d array, if found return its ptr, otherwise, nullptr

template<class T>
bool search_twod(T** twod, int* sizes, const T& key, int& row, int& col);
//search the key in the 2 d array, if found return true, otherwise false
//Row and col is pass by reference, if found, row and col of the element will
//pass out, otherwise set it to -1

template <class T>
T& get_twod(T** twod, int row, int col);
//get the element in the row col;

//==========================Non-template Function=========================

void init2D_dbug(int** two_D, int* size);
//initial the 2d array with dbug purpose

bool is_valid(int* sizes, int row, int col);
//check if the row and col valid in this 2 D sizes

int get_size(int* sizes);
//get the row number of the 2 D array which is the size of the 2 D

int get_biggest(int* sizes);
//find the biggest size in the sizes

//=======================Function definition==============================

template<typename T>
void init2D(T** two_D, int* size, const T& entry){
    int size_2D = get_size(size);     //get row number
    for(int i = 0; i < size_2D; i++, size++, two_D++){
        init1D(*two_D, *size, entry);    //initial 1 D
    }
}

template<typename T>
void print2D(T** two_D, int* size){
    while(*size > 0){
        print_list(*two_D, *size);    //print the 1 D array
        two_D++;    //move to next 1 D array
        size++;     //next row size
    }
}

template<typename T>
void deallocate(T** two_D, int* size){
    T** walker = two_D;      //walker for 2D array
    while(*size > 0){
        delete[] *walker;    //delete walker pointing row array
        size++;             //next row size
        walker++;           //move to next 1 D array
    }
    delete[] two_D;          //delete the outside array
}

template<typename T>
T** allocate2D(int* size){
    T** list = new T*[get_size(size) + 1];     //create size 2 D array
    T** walker = list;    //walker for 2 D
    int* size_walker = size;        // walker for size array
    for(int i = 0; i < get_size(size); i++, size_walker++, walker++){
        *walker = allocate<T>(*size_walker);  //allocate the 1 D in walker row
    }
    return list;
}

template<typename T>
T read(T** two_D, int* size, int row, int col){
    assert(is_valid(size,row,col));       //assert when is valid false
    return get_twod(two_D,row,col);
}

template<typename T>
void write(T** two_D, int* size, int row, int col, const T& entry){
    assert(is_valid(size,row,col));        //assert when is valid false
    get_twod(two_D,row,col) = entry;                  //write to the element
}

template <class T>
T& get_twod(T** twod, int row, int col){
    T** walker_2D = twod;       //walker for 2 D
    walker_2D += row;              //walker go to the row
    T* walker = *walker_2D;          //walker for 1 D
    walker += col;                 //go to the col
    return *walker;
}

template<typename T>
T* search_twod(T** two_d, int* sizes, const T& key){
    T* target = nullptr;
    while(target == nullptr && *sizes > 0){
        target = search_entry(*two_d, *sizes, key);  //seach on 1d array
        sizes++;
        two_d++;
    }
    return target;    //if not found target keep nullptr
}

template<class T>
bool search_twod(T** two_d, int* sizes, const T& key, int& row, int& col){
    T** walker = two_d;
    while(*sizes > 0){
        if(search_entry(*walker, key, *sizes, col)){
            //if pass, col will be set
            row = walker - two_d; //row is distance of walker to two_d address
            return true;
        }
        sizes++;      //sizes to next
        walker++;        //2 D walker to next
    }
    row = -1;   //false to find, set to -1
    col = -1;   //false to find, set to -1
    return false;
}

#endif // TWO_D_POINTER_TOOL_H
