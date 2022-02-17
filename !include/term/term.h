#ifndef TERM_H
#define TERM_H

#include <iostream>
#include <cassert>
#include <cmath>
#include <iomanip>

using namespace std;

struct Term{
    double _coef;     //coefficient
    int _exp;         //exponent

    Term();  //default construtor
    Term(double coef, int exp);     //construtor with coef, and exponent

    friend bool is_Same(const Term& lhs, const Term& rhs);

    friend bool operator ==(const Term& lhs, const Term& rhs);
    //comparison, if two terms are equal
    friend bool operator !=(const Term& lhs, const Term& rhs);
    //comparison, if two terms are unequal
    friend bool operator >(const Term& lhs, const Term& rhs);
    //comparison, if left terms is greater then the right
    friend bool operator <(const Term& lhs, const Term& rhs);
    //comparison, if left terms is greater then the right

    Term& operator +=(const Term& rhs);
    Term& operator -=(const Term& rhs);
    Term& operator *=(const Term& rhs);
    Term& operator /=(const Term& rhs);

    friend Term operator + (const Term& lhs, const Term& rhs);
    //Low level two term addition
    friend Term operator * (const Term& lhs, const Term& rhs);
    //low level two term multiplication
    friend Term operator - (const Term& lhs, const Term& rhs);
    //low level, terms subtraction
    //used in Poly division operator
    friend Term operator / (const Term& lhs, const Term& rhs);
    //low level, two term divison

    Term operator -() const; //unary operator
    //low level, negative a term

    friend ostream& operator <<(ostream& outs, const Term& t);
    //output format of a term
    friend istream& operator >>(istream& ins, Term& t);
    //input inserction format of a term
};

#endif // TERM_H
