#ifndef LPAREN_H
#define LPAREN_H
#include "token.h"


class Lparen : public token
{
public:
    Lparen();      //contructor
    int type();      //type left parenthese
    ostream& print(ostream& outs = cout) const;    //print the left parenthese
};

#endif // LPAREN_H
