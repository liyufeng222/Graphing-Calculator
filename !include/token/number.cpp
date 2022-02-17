#include "number.h"

number::number(double value) : token ()
{
    _value = value;      //assign the value
}

int number::type(){
    return 1;         //1 for number type
}
ostream& number::print(ostream& outs) const{
    outs << _value;      //print the number
    return outs;
}

double number::get_num(){
    return _value;     //return the number
}
