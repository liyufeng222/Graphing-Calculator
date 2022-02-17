#include "tokenizer.h"

tokenizer::tokenizer(string equation)
{
    _equation = equation;   //assign the equation
}

Queue<token*> tokenizer::infix(){
    return _get_infix();   //return the infix
}

Queue<token*> tokenizer::_get_infix(){
    Queue<token*> _result;   //result queue
    char *copy_equation = strdup(_equation.c_str());   //copy the c_s ctring
    char delimite[] = " ";     //delimitor
    char* token = strtok(copy_equation,delimite);    //use strtok
    while (token)          //while still have token
    {
        switch (get_type(token)) {
            case LPAREN:
                _result.push(new Lparen());    //add (
                break;
            case RPAREN:
                _result.push(new Rparen());    //add )
                break;
            case NUMBER:
                //atof:    string to double
                _result.push(new number(atof(token)));    //add the number
                break;
            case VARIABLE:
                _result.push(new variable());     //add x
                break;
            case OPERATOR:
                _result.push(new Operator(token));   //add operator
                break;
            case FUNCTION:
                _result.push(new Function(token));     //add function
                break;
            default:
                break;
        }
        token = strtok(NULL,delimite);       //next token
    }
    return _result;
}

TOKEN_TYPE tokenizer::get_type(char* token){
    //since char* can not use swith case, so that use if else to
    //determine type
    if(token[0] == '('){
        return LPAREN;
    }else if(token[0] == ')'){
        return RPAREN;
    }else if(isdigit(token[0])){
        return NUMBER;
    }else if(token[0] == 'x'||token[0] == 'X'){
        return VARIABLE;
    }else if(token[0] == '+'||token[0] == '-'||token[0] == '*'
             ||token[0] == '/'||token[0] == '^'){
        return OPERATOR;
    }else if(isalpha(token[0])){
        return FUNCTION;
    }
    return UNKNOW;      //unknow type error
}

