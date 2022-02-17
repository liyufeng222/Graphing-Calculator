#include "token.h"

token::token()
{
    //blank no private variable
}

int token::type(){
    return -1;     //-1 stand for a regular token
}
ostream& token::print(ostream& outs) const{
    outs << "Token";      //output
    return outs;
}
token::~token(){
    //no dynamic space
}
ostream& operator<<(ostream& outs, token* t){
    return t->print(outs);
}
