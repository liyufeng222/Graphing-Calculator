#ifndef VARIABLE_H
#define VARIABLE_H
#include "token.h"


class variable : public token
{
public:
    variable();    //Constructor
    int type();      //type variable
    ostream& print(ostream& outs = cout) const;      //print the variable

};
#endif // VARIABLE_H
