#ifndef NUMBER_H
#define NUMBER_H
#include "token.h"


class number : public token
{
public:
    number(double value);    //Constructor
    int type();      //type number
    double get_num();   //return the value
    ostream& print(ostream& outs = cout) const;      //print the numebr

private:
    double _value;
};

#endif // NUMBER_H
