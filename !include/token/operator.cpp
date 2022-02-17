#include "operator.h"
#include <assert.h>

Operator::Operator(string op) : token ()
{
    _op = op;      //assign the operator value
    _prec = prec();
}

int Operator::type(){
    return 4;         //4 for operator type
}
ostream& Operator::print(ostream& outs) const{
    outs << _op;      //print the Operator
    return outs;
}

string Operator::op() const{
    return _op;    //return the _op
}
int Operator::get_prec() const{
    return _prec;      //return the _prec
}
void Operator::set_prec(int prec){
    _prec = prec;
}

int Operator::prec(){
    if(_op == "+" || _op == "-"){
        return 1;     // 1 for + and -
    }else if(_op == "*" || _op == "-"){
        return 2;      //2 for * and -
    }else if(_op == "^"){
        return 3;       //3 for ^
    }else{
        return -1;      //unknow operator status
    }
}

double Operator::calculate(double num_1, double num_2){
    //base on the sign to see that operator to use
    if(_op == "+"){
        return num_1 + num_2;
    }else if(_op == "-"){
        return num_1 - num_2;
    }else if(_op == "*"){
        return num_1 * num_2;
    }else if(_op == "/"){
        //assert(num_2 != 0.0);
        if(num_2 == 0.0){
            return 0;
        }
        return num_1 / num_2;
    }else{
        return pow(num_1,num_2);
    }
}

