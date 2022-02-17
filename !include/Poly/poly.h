#ifndef POLY_H
#define POLY_H

#include <iostream>
#include "../../!include/term/term.h"
#include "../../!include/sorted_list/sorted_list.h"
using namespace std;

class Poly
{
public:

    Poly();    //default constructor
    Poly(double term_array[], int order);
    //contructor with a coefficient list

    //DO not need big three, because it base on sort list, and the only
    //member variable is sort list

    friend bool operator ==(const Poly& lhs, const Poly& rhs);
    //compare operator, true if the left poly equal right

    Poly& operator +=(const Term& t);  //addition, poly += term
    Poly& operator *=(const Term& t);  //multiplication, poly *= term
    Poly& operator -=(const Term& t);  //subtraction, poly -= term
    Poly& operator /=(const Term& t);  //diviation, poly /= term


    Poly& operator +=(const Poly& RHS);  //addition, poly += poly
    Poly& operator *=(const Poly& RHS);  //multiplication, poly *= poly
    Poly& operator -=(const Poly& RHS);  //subtraction, poly -= poly
    Poly& operator /=(const Poly& RHS);  //diviation, poly /= poly



    friend Poly operator + (const Poly& left, const Poly& right);
    //High level addition, Poly + poly return a new poly
    friend Poly operator -(const Poly& left, const Poly& right);
    //High level substraction, Poly - poly return a new poly
    friend Poly operator * (const Poly& left, const Poly& right);
    //High level multiplication, Poly * poly return a new poly
    friend Poly operator / (const Poly& left, const Poly& right);
    //High level diviation, Poly / poly return a new poly
    friend Poly operator % (const Poly& left, const Poly& right);
    //High level reminder, Poly % poly return a new poly


    Poly operator -() const;           //Unary Munus


    friend Poly operator + (const Poly& left, const Term& t);
    //addition, poly + term, return a new poly
    friend Poly operator * (const Poly& left, const Term& t);
    //multiplication, poly * term, return a new poly

    friend ostream& operator << (ostream& outs, const Poly& print_me);
    //Out put ostream method
    friend istream& operator >> (istream& ins, Poly& p);
    //Input insertion method

private:
    Sorted_List<Term> _poly; //descending sorted list

    void fix_poly();    //delete the coefficient is 0 term in the poly
};

#endif // POLY_H
