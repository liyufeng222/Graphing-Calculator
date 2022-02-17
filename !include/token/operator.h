#ifndef OPERATOR_H
#define OPERATOR_H
#include "token.h"
#include <math.h>


class Operator : public token
{
public:
    Operator(string op);    //Constructor
    int type();      //type number
    ostream& print(ostream& outs = cout) const;      //print the numebr
    string op() const; // return the string of that operator
    int get_prec() const;  //get the prec value
    void set_prec(int prec);    //set the prec

    double calculate(double num_1, double num_2);

private:
    string _op;
    int _prec;
    virtual int prec();

};

#endif // OPERATOR_H
