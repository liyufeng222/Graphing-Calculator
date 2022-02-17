#include "variable.h"

variable::variable() : token ()
{
    //blank no member variable
}

int variable::type(){
    return 0;         //0 for number and variable type
}
ostream& variable::print(ostream& outs) const{
    outs << "x";      //print the number
    return outs;
}
