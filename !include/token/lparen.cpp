#include "lparen.h"

Lparen::Lparen() : token ()
{
    //blank no private member
}

int Lparen::type(){
    return 2;         //2 for left prenthese type
}
ostream& Lparen::print(ostream& outs) const{
    outs << "(";      //print the left prenthese
    return outs;
}
