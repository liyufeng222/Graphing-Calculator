#include "poly_tester.h"

void test_div(const Poly& p, const Poly& q){
    Poly r = p / q;
    cout<<"["<<p<<"] / ["<<q<<"]"<<endl;
    cout<<"      = ["<<r<<"]";
    cout<<"  rem = ["<<p % q<<"]  ";
    //if r = p / q then r * q + p % q should be equal to p:
    if(r * q + p % q == p){
        cout<<"   VERIFIED"<<endl;
    }
    else{
        cout<<endl<<"   ***VERIFICATION FAILED"<<endl;
        cout<<"   r * q: "<<r * q<<endl;
        cout<<"   p % q: "<<p % q<<endl;
        cout<<"   r * q + p % q: "<<r * q + p % q<<"=/="<<p<<endl;
    }
}

void test_add(const Poly& p, const Poly& q){
    Poly r = p + q;
    cout<<"["<<p<<"] + ["<<q<<"]"<<endl;
    cout<<"      = ["<<r<<"]";
    //if r = p + q then r - q should be equal to p:
    if(r - q == p){
        cout<<"   VERIFIED"<<endl;
    }
    else{
        cout<<endl<<"   ***VERIFICATION FAILED"<<endl;
        cout<<"   r - q: "<<r - q<<"=/="<<p<<endl;
    }
}
void test_sub(const Poly& p, const Poly& q){
    Poly r = p - q;
    cout<<"["<<p<<"] - ["<<q<<"]"<<endl;
    cout<<"      = ["<<r<<"]";
    //if r = p - q then r + q should be equal to p:
    if(r + q == p){
        cout<<"   VERIFIED"<<endl;
    }
    else{
        cout<<endl<<"   ***VERIFICATION FAILED"<<endl;
        cout<<"   r + q: "<<r + q<<"=/="<<p<<endl;
    }
}
void test_mul(const Poly& p, const Poly& q){
    Poly r = p * q;
    cout<<"["<<p<<"] * ["<<q<<"]"<<endl;
    cout<<"      = ["<<r<<"]";
    //if r = p * q then r / q + r % q should be equal to p:
    if(r / q + r % q == p){
        cout<<"   VERIFIED"<<endl;
    }
    else{
        cout<<endl<<"   ***VERIFICATION FAILED"<<endl;
        cout<<"   r / q: "<<r / q<<endl;
        cout<<"   r % q: "<<r % q<<endl;
        cout<<"   r / q + r % q: "<<r / q + r % q<<"=/="<<p<<endl;
    }
}

void test_all(const Poly& p, const Poly& q){
    cout << "--------------------------------------" << endl;
    cout << "p: [" << p << "]" << endl;
    cout << "q: [" << q << "]" << endl;

    cout <<endl<<endl<< "------- p + q ----------------------" << endl;
    test_add(p,q);

    cout <<endl<<endl<< "------- q + p ----------------------" << endl;
    test_add(q,p);

    cout <<endl<<endl<< "------- p - q ----------------------" << endl;
    test_sub(p,q);

    cout <<endl<<endl<< "------- q - p ----------------------" << endl;
    test_sub(q,p);

    cout <<endl<<endl<< "------- p * q ----------------------" << endl;
    test_mul(p,q);

    cout <<endl<<endl<< "------- q * p ----------------------" << endl;
    test_mul(q,p);

    cout <<endl<<endl<< "------- p / q ----------------------" << endl;
    test_div(p,q);

    cout <<endl<<endl<< "------- q / p ----------------------" << endl;
    test_div(q,p);
}

void menu(){
    cout << "[P]  [Q]     e[X]it" << endl;
    cout << "(NOTE: Polynomial must end with (number x0), (EX: +0 x0)\n";
}

void demo(){
    Poly p;
    Term t1(3, 3);
    Term t2(2, 2);
    Term t3(1, 1);
    Term t4(5, 0);
    p += t1;
    p += t2;
    p += t3;
    p += t4;           // make the default polynomial p

    Poly q;
    Term a1(4, 4);
    q = q + p;
    q += a1;          // make the default polynomial q

    test_all(p,q);      //all the math: addition , subtraction, multiplication
                        //division

    char answer;
    menu();
    cin >> answer;      //the commond
    while(toupper(answer) != 'X'){
        switch (toupper(answer)) {
            case 'P':
                cout << "[P]: ";     //change polynomial p
                cin >> p;
                break;
            case 'Q':
                cout << "[Q]: ";      //change polynomial q
                cin >> q;
                break;
            default:
                cout << "Wrong option! Please choose again." << endl;
                break;
        }
        cout <<endl<<endl;
        test_all(p,q);
        menu();
        cin >> answer;
    }

    cout <<endl<<endl <<"------------------END-----------------" <<endl<<endl;
}


