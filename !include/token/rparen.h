#ifndef RPAREN_H
#define RPAREN_H
#include "token.h"


class Rparen : public token
{
public:
    Rparen();      //contructor
    int type();      //type right parentheses
    ostream& print(ostream& outs = cout) const;  //print the right parentheses
};
#endif // RPAREN_H
