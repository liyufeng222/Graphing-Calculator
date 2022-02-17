#include "function.h"

Function::Function(string function) : Operator(function)
{
    set_prec(9);     //let the prec for function is biggest
}

double Function::calculate(double num_1){
    //if else statement to see which function to use
    if(op() == "sin"){
        return sin(num_1);
    }else if(op() == "cos"){
        return cos(num_1);
    }else if(op() == "tan"){
        return tan(num_1);
    }else if(op() == "ln"){
        return log(num_1);
    }else if(op() == "log"){
        return log10(num_1);
    }
    return 0;
}
