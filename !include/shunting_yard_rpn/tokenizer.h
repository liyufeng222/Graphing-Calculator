#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "../../!include/token/token.h"
#include "../../!include/token/lparen.h"
#include "../../!include/token/number.h"
#include "../../!include/token/operator.h"
#include "../../!include/token/rparen.h"
#include "../../!include/token/variable.h"
#include "../../!include/token/function.h"
#include "../../!include/queue/queue.h"
#include <cstring>

enum TOKEN_TYPE{LPAREN, RPAREN, NUMBER, VARIABLE, OPERATOR, FUNCTION, UNKNOW};

class tokenizer
{
public:
    tokenizer(string equation);    //constructor with string
    //tokenizer(char* equation);    //constructor the equation
    Queue<token*> infix();   //return the infix

private:
    string _equation;
    Queue<token*> _get_infix();   //convert the string to infix
    TOKEN_TYPE get_type(char* token);   //get the type of that token
};

#endif // TOKENIZER_H

