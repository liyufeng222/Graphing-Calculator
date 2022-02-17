#include "rparen.h"

Rparen::Rparen() : token ()
{
    //blank no private member
}

int Rparen::type(){
    return 3;         //3 for right prenthese type
}
ostream& Rparen::print(ostream& outs) const{
    outs << ")";      //print the right prenthese
    return outs;
}
