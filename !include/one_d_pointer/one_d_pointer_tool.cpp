#include "one_d_pointer_tool.h"

void init1D_dbug(int* one_D, int size, const int& start_value){
    for(int i = 0; i < size; i++, one_D++){
        *one_D = start_value + i;      //value for dbug purpose
    }
}
