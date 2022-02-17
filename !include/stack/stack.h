#ifndef STACK_H
#define STACK_H

#include "../../!include/node/node.h"

#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class Stack{
public:
    class Iterator{   //nest class
    public:
        friend class Stack;
        Iterator next(){
            node<T>* temp = _ptr->_next;    //get to next ptr
            return Iterator(temp);
        }
        Iterator(){
            _ptr = NULL;
        }                        //default ctor
        Iterator(node<T>* p): _ptr(p){
            //blank
        }                  //Point Iterator to where p is pointing to
        T& operator *(){
            assert(_ptr);
            return _ptr->_item;
        }                        //dereference operator
        T* operator ->(){
            assert(_ptr);
            return *(_ptr->_item);
        }                 //member access operator
        const T& operator *() const{
            assert(_ptr);
            return _ptr->_item;
        }
        const T* operator ->() const{
            assert(_ptr);
            return *(_ptr->_item);
        }
        operator bool() const{
            return _ptr != NULL;
        }           //casting operator: true if _ptr not NULL
                                     //      this turned out to be a pain!
        bool is_null(){
            return _ptr == NULL;
        }                                //true if _ptr is NULL
        friend bool operator !=(const Iterator& left, const Iterator& right){
            return left._ptr != right._ptr;
        } //true if left != right

        friend bool operator ==(const Iterator& left, const Iterator& right){
            return left._ptr == right._ptr;
        } //true if left == right

        Iterator& operator++(){
            assert(_ptr);
            _ptr = _ptr->_next;
            return *this;
        }                         //member operator: ++it; or ++it = new_value
        friend Iterator operator++(Iterator& it, int unused){
            assert(it._ptr);
            Iterator temp;
            temp = it;
            it = it.next();
            return temp;
        }        //friend operator: it++

    private:
        node<T>* _ptr;                          //pointer being encapsulated
    };

    Stack();     //default constructor

    //BIG 3
    Stack(const Stack& other);       //copy Constructor
    Stack& operator =(const Stack& rhs);     //copy assignment
    ~Stack();       //destructor

    template<typename U>
    friend ostream& operator<<(ostream& outs, const Stack<U>& stack);
    // print stack function but use << operator


    void push(const T& item);    //push item in from the top
    T pop();                     //pop the item from the top
    bool empty();                //return if the stack empty
    T top();                     //return the top item
    Iterator begin();            //the begin iterator of the stack
    Iterator end();              //the end iterator of the stack

private:
    node<T>* head_ptr;           //stack head node

};

template <typename T>
Stack<T>::Stack(){
    head_ptr = nullptr;       //default value
}

template <typename T>
Stack<T>::Stack(const Stack& other){
    head_ptr = _copy_list(other.head_ptr);  //copy the list
}

template <typename T>
Stack<T>& Stack<T>::operator =(const Stack& rhs){
    //1. check for self-reference
    if(this == &rhs){
        return *this;
    }

    //2. dealloate existing space;
    _clearList(head_ptr);

    //3. copy rhs list to this list
    head_ptr = _copy_list(rhs.head_ptr);

    //4. return this object
    return *this;
}

template <typename T>
Stack<T>::~Stack(){
    _clearList(head_ptr);    //clear the dynamic list space
}

template <typename T>
void Stack<T>::push(const T& item){
    _insert_head(head_ptr, item);    //push item to the top
}

template <typename T>
T Stack<T>::pop(){
    return _delete_node(head_ptr, head_ptr);    //remove the item in the top
}

template <typename T>
bool Stack<T>::empty(){
    return head_ptr == nullptr;     //is the head is null then true
}

template <typename T>
T Stack<T>::top(){
    return head_ptr->_item;         //return the top item
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::begin(){
    return Iterator(head_ptr);       //the begin iterator
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::end(){
    return Iterator(nullptr);       //end iterator always nullptr
}

template<typename U>
ostream& operator<<(ostream& outs, const Stack<U>& stack){
    return _print_list(stack.head_ptr, outs);   //use node function
}


#endif // STACK_H
