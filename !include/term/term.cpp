#include "term.h"

Term::Term(){
    _coef = 0;    //default value
    _exp = 0;
}

Term::Term(double coef, int exp){
    assert(exp >= 0);
    _coef = coef;    //set soef and exp
    _exp = exp;
}

bool is_Same(const Term& lhs, const Term& rhs){
    return (fabs(lhs._coef - rhs._coef) < 0.0000001)
            && lhs._exp == rhs._exp;  //double cannot use == or != (coef);
    //fabs the distance to compare two floating point
}

//==========================Comparison Sign===============================
bool operator ==(const Term& lhs, const Term& rhs){
    return lhs._exp == rhs._exp;  //two exp same
}
bool operator !=(const Term& lhs, const Term& rhs){
    return !(lhs == rhs);   //true if different exp
}
bool operator >(const Term& lhs, const Term& rhs){
    return lhs._exp > rhs._exp;     //bigger exponent, bigger term
}
bool operator <(const Term& lhs, const Term& rhs){
    return lhs._exp < rhs._exp;     //smaller exponent, smaller term
}
//=======================================================================

Term& Term::operator +=(const Term& rhs){
    *this = *this + rhs;  //make itself be itself add rhs
    return *this;
}
Term& Term::operator -=(const Term& rhs){
    *this = *this - rhs;    //make itself be itself substract rhs
    return *this;
}
Term& Term::operator *=(const Term& rhs){
    *this = *this * rhs;     //make itself be itself times rhs
    return *this;
}
Term& Term::operator /=(const Term& rhs){
    *this = *this / rhs;      //make itself be itself divide rhs
    return *this;
}

//=======================Term Math Operation=============================
Term Term::operator -() const{
    //return term that the coefficient change sign
    return Term(-(_coef), _exp);
}

Term operator * (const Term& lhs, const Term& rhs){
    double coef = lhs._coef * rhs._coef;   //coef is multiplication
    int exp = lhs._exp + rhs._exp;     //exponent is addition
    return Term(coef, exp);
}

Term operator + (const Term& lhs, const Term& rhs){
    assert(lhs._exp == rhs._exp);
    //exp equal, coef do addition
    return  Term(lhs._coef + rhs._coef, lhs._exp);   //return the new term
}

Term operator - (const Term& lhs, const Term& rhs){
    assert(lhs._exp == rhs._exp);
    //exp equal, coef do subtraction
    return  Term(lhs._coef - rhs._coef, lhs._exp);    //return the new term
}

//used in Poly division operator
Term operator / (const Term& lhs, const Term& rhs){
    assert(rhs._coef != 0.0);  //Divisor could not be zero.
    double coef = lhs._coef / rhs._coef;   //coef is division
    int exp = lhs._exp - rhs._exp;         //exponent is subtraction
    if(exp < 0){
        return Term(0,0);   //means the result is 0, when lhs lower degree
                            //then the right
    }
    return Term(coef, exp);
}
//=======================================================================

//=========================Term Input and Output=========================
ostream& operator <<(ostream& outs, const Term& t){
    outs << std::fixed;
    outs << std::setprecision(1);
    if(t._coef != 0.0){             //only output when coef is not 0
        cout << (t._coef > 0 ? " +" : " ");  //coef > 0, out put " +" sign
        if(t._exp == 0){
            outs << t._coef;              //exp is 0
        }else{
            if(t._coef != 1.0){
                outs << t._coef;     //when coef is not 1, out put the coef
            }
            outs << "X";       //X
            if(t._exp != 1){
                outs <<"^" << t._exp;    //exp not 1, need print the exp
            }
        }
    }
    return outs;
}

istream& operator >>(istream& ins, Term& t){
    double coef;
    int exp;
    char x;
    ins >> coef >> x >> exp;    //cin format: +4 x4  (double>>char>>int)
    t = Term(coef, exp);
    return ins;
}
//======================================================================
