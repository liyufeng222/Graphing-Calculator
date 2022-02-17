#ifndef RPN_H
#define RPN_H
#include "../../!include/vector/vector.h"
#include "shunting_yard.h"


class rpn
{
public:
    rpn(Queue<token*> post_fix);     //constructor with postfix

    double eval(double x_value = 0);  //calculate the rpn

private:
    Queue<token*> _post_fix;
};

#endif // RPN_H
