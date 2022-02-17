#include "two_d_pointer_tool.h"

bool is_valid(int* sizes, int row, int col){
    int* walker = sizes + row;
    //go to the corresponding row size
    return row >-1 && row < get_size(sizes) && col > -1 && col < *walker;
}

int get_size(int* sizes){
    int count = 0;
    while(*sizes >= 0){
        count++;      //count for size
        sizes++;      //next row
    }
    return  count;
}

int get_biggest(int* sizes){
    int biggest = *sizes;      //set the first one
    int size_number = get_size(sizes);    //get the row number
    sizes++;    //second row size
    for(int i = 1; i < size_number; i++){
        if(*sizes > biggest){
            biggest = *sizes;     //set the biggest if the row size bigger
        }
    }
    return biggest;
}


void init2D_dbug(int** two_D, int* size){
    int start = 0;
    int size_2D = get_size(size);
    for(int i = 0; i < size_2D; i++, size++, two_D++){
        init1D_dbug(*two_D, *size, start);
        start = (start + 10) / 10 * 10;
    }
}
