#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
using namespace std;


class token
{
public:
    token();      //constructor

    virtual int type();     //type of the token
    virtual ostream& print(ostream& outs = cout) const;    //print the token
    virtual ~token();      //destructor

    friend ostream& operator<<(ostream& outs, token* t);
};

#endif // TOKEN_H
