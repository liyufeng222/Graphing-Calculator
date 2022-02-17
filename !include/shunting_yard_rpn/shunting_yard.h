#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include "../../!include/token/token.h"
#include "../../!include/token/lparen.h"
#include "../../!include/token/number.h"
#include "../../!include/token/operator.h"
#include "../../!include/token/rparen.h"
#include "../../!include/token/variable.h"
#include "../../!include/token/function.h"
#include "../../!include/stack/stack.h"
#include "../../!include/queue/queue.h"

class shunting_yard
{
public:
    shunting_yard(Queue<token*> infix);    //constructor with a infix
    Queue<token*> postfix();     //return the postfix

private:
    Queue<token*> _postfix;      //the postfix form
    Queue<token*> _get_postfix(Queue<token*> infix);
    //transfer the infix to postfix
};

#endif // SHUNTING_YARD_H
