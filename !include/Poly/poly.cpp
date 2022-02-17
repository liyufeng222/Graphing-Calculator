#include "poly.h"

Poly::Poly()
{
    Sorted_List<Term> temp(false, true);   //create the poly
    //descending, and unique
    _poly = temp;
    _poly.Insert(Term());     //get a default term to the _poly
}

Poly::Poly(double term_array[], int order){
    Sorted_List<Term> temp(false, true);    //create the poly
    //descending, and unique
    _poly = temp;
    for(int i = 0; i < order; i++){
        *this += Term(term_array[i], i);
        //enter all terms in the list to this list
    }
}

bool operator ==(const Poly& lhs, const Poly& rhs){
    Sorted_List<Term>::Iterator wker_lhs = lhs._poly.Begin();
    //walker for the left poly
    Sorted_List<Term>::Iterator wker_rhs = rhs._poly.Begin();
    //walker for the right poly

    while(wker_lhs != lhs._poly.End() && wker_rhs != rhs._poly.End()){
        if(!is_Same(*wker_lhs, *wker_rhs)){
            return false;    //false if one pair of them is not same
        }
        wker_lhs++;
        wker_rhs++;      //get to next pair
    }
    if(wker_lhs == lhs._poly.End() && wker_rhs == rhs._poly.End()){
        //when both list reach the end, the two poly are same
        return true;
    }
    //when one of it is not reach end, different size, then false
    return false;
}

Poly& Poly::operator +=(const Term& t){
    *this = *this + t;     //itself add a term
    return *this;
}
Poly& Poly::operator *=(const Term& t){
    *this = *this * t;    //itself times a term
    return *this;
}
Poly& Poly::operator -=(const Term& t){
    *this = *this + (-t);     //itself minus a term
    return *this;
}
Poly& Poly::operator /=(const Term& t){
    Poly temp;   //create a empty poly
    temp += t;    //add the temp in the poly
    *this = *this / temp;    //divide them
    return *this;
}

Poly& Poly::operator +=(const Poly& RHS){
    *this = *this + RHS;      //itself add a poly
    return *this;
}
Poly& Poly::operator *=(const Poly& RHS){
    *this = *this * RHS;       //itself times a poly
    return *this;
}
Poly& Poly::operator -=(const Poly& RHS){
    *this = *this - RHS;       //itself minus a poly
    return *this;
}
Poly& Poly::operator /=(const Poly& RHS){
    *this = *this / RHS;       //itself divid a term
    return *this;
}



Poly operator + (const Poly& left, const Poly& right){
    Poly result = left;      //new poly equal left
    for(Sorted_List<Term>::Iterator temp = right._poly.Begin();
        temp != left._poly.End(); temp++){
        //get a walker for right
        result += *temp;      //then add every term in right to result
    }
    result.fix_poly();        //fix the poly get rid off 0
    return result;
}
Poly operator -(const Poly& left, const Poly& right){
    Poly result = left + (-right);  //fix_poly will call in +
    return result;
}
Poly operator * (const Poly& left, const Poly& right){
    Poly result;       //new result for result
    for(Sorted_List<Term>::Iterator temp = right._poly.Begin();
        temp != right._poly.End(); temp++){
        //get a walker for right
        result += left*(*temp);
        //then every term times the left add to result
    }
    result.fix_poly();     //fix the poly
    return result;
}

Poly operator / (const Poly& left, const Poly& right){
    assert(!(right == Poly()));     //the divisor can not be a 0 polynomial.
    Poly result;       //empty result
    Poly temp = left;
    //temp is the long division the poly left by subtraction
    //keep looping when the temp still can be divide by the rhs
    Term single_result = *temp._poly.Begin() / *right._poly.Begin();
    //every time will have a temp result add to the whole result
    while((*temp._poly.Begin() > *right._poly.Begin() ||
           *temp._poly.Begin() == *right._poly.Begin()) &&
          single_result._coef != 0.0){
        //make sure the late term will exist the loop, so coef != 0
        single_result = *temp._poly.Begin() / *right._poly.Begin();
        //temp result
        result += single_result;   //add it to result
        temp = temp - right * single_result;
        //the next temp get from subtraction
    }
    return result;
}
Poly operator % (const Poly& left, const Poly& right){
    assert(!(right == Poly()));     //the divisor can not be a 0 polynomial.
    Poly div = left / right;    //the division
    return left - div * right;     //reminder is dividend - result
}

Poly Poly::operator -() const{
    Poly result;   //new poly for result
    for(Sorted_List<Term>::Iterator temp = _poly.Begin();
        temp != _poly.End(); temp++){
        //walker in the list, then make every term become negative
        result += (-*temp);
    }
    return result;
}


Poly operator + (const Poly& left, const Term& t){
    Poly result = left;   //result poly equal the left
    result._poly.Insert(t);   //add the term in to the poly list
    return result;
}
Poly operator * (const Poly& left, const Term& t){
    Poly result;    //result poly empty
    for(Sorted_List<Term>::Iterator temp = left._poly.Begin();
        temp != left._poly.End(); temp++){
        //walker in the left
        result += (*temp * t);  //result add each left term time the term
    }
    return result;
}

ostream& operator << (ostream& outs, const Poly& print_me){
    for(Sorted_List<Term>::Iterator temp = print_me._poly.Begin();
        temp != print_me._poly.End(); temp++){
        //walker throught the poly list
        outs << *temp;   //out put each term
    }
    return outs;
}
istream& operator >> (istream& ins, Poly& p){
    Poly temp;   //create a empty poly
    Term t;        //single term to recieve
    ins >> t;    //recieve a term
    temp += t;     //let the poly add the term
    while(t._exp > 0){      //keep loop to recieve term
        ins >> t;
        temp += t;   //temp add the term
    }
    p = temp;   //let the old poly to new poly
    p.fix_poly();
    return ins;
}

//==========================================================================
//============================Private function==============================
//==========================================================================

void Poly::fix_poly(){
    Sorted_List<Term>::Iterator temp = _poly.Begin();
    //walker in the poly
    Sorted_List<Term>::Iterator targer;     //the term going to be deleted
    while(temp != _poly.End()){
        if((*temp)._coef == 0.0){   //if term is 0
            targer = temp;
            _poly.Delete(targer);   //delete that term
        }
        temp++;
    }
    if(_poly.Begin().is_null()){    //make sure the poly could not be null
        _poly.Insert(Term());     //get a default term to the _poly
    }
}
