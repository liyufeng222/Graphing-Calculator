#ifndef FUNCTION_H
#define FUNCTION_H

#include "operator.h"


class Function : public Operator
{
public:
    Function(string function);    //constructor
    double calculate(double num_1);
};

#endif // FUNCTION_H
