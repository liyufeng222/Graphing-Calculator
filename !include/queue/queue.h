#ifndef QUEUE_H
#define QUEUE_H

#include "../../!include/linked_list/linked_list.h"

#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class Queue{
public:
    class Iterator{      //nest class
    public:
        friend class Queue;
        Iterator(){
            _ptr = typename List<T>::Iterator();
        }                        //default ctor
        Iterator(typename List<T>::Iterator ptr){
            _ptr = ptr;
        }          //Point Iterator to where ptr is pointing to
        T& operator *(){
            assert(_ptr);
            return *_ptr;
        }                        //dereference operator
        T* operator ->(){
            assert(_ptr);
            return *(_ptr->_item);
        }                 //member access operator
        const T& operator *() const{
            assert(_ptr);
            return *_ptr;
        }
        const T* operator ->() const{
            assert(_ptr);
            return &(*_ptr);
        }
        operator bool() const{
            return _ptr != NULL;
        }           //casting operator: true if _ptr not NULL
                                     //      this turned out to be a pain!
        bool is_null(){
            return _ptr.is_null();
        }                                //true if _ptr is NULL
        friend bool operator !=(const Iterator& left, const Iterator& right){
            return left._ptr != right._ptr;
        } //true if left != right

        friend bool operator ==(const Iterator& left, const Iterator& right){
            return left._ptr == right._ptr;
        } //true if left == right

        Iterator& operator++(){
            assert(_ptr);
            _ptr++;
            return *this;
        }                         //member operator: ++it; or ++it = new_value
        friend Iterator operator++(Iterator& it, int unused){
            assert(it._ptr);
            Iterator temp;
            temp = it;
            ++it;
            return temp;
        }        //friend operator: it++

    private:
        typename List<T>::Iterator _ptr;
        //pointer being encapsulated
    };


    Queue();     //default constructor

    //BIG 3
    Queue(const Queue& other);    //copy Constructor
    Queue& operator =(const Queue& rhs);  //copy assignment
    ~Queue();     //destructor

    template<typename U>
    friend ostream& operator<<(ostream& outs, const Queue<U>& queue);
    // print queue function but use << operator

    void push(const T& item);   //push item in from rear
    T pop();          //pop the item from front
    bool empty();     //return if the list empty
    T front();        //return the front item
    Iterator begin();     //the begin iterator of the list
    Iterator end();       //the end iterator of the list

private:
    List<T> _queue;                       //the queue list
    typename List<T>::Iterator rear;      //Iterator for rear
};

template <typename T>
Queue<T>::Queue(){
    _queue = List<T>();     //assign the list to a default list
    rear = NULL;    //assign the rear to default (empty queue, rear is NULL)
}

template <typename T>
Queue<T>::Queue(const Queue& other){
    _queue = List<T>(other._queue);         //list copy CROT
    rear = other.rear;    //copy the rear
}

template <typename T>
Queue<T>& Queue<T>::operator =(const Queue& rhs){
    //1. check for self-reference
    if(this == &rhs){
        return *this;
    }

    //2. use list copy assignment(list class has), and copy rear
    _queue = rhs._queue;  //copy the list
    rear = rhs.rear;

    //3. return this object
    return *this;
}

template <typename T>
Queue<T>::~Queue(){
    //Blank (list has itself destractor to delete dynamic space)
    //rear._ptr is in the list, when list destract, it will delete
}

template <typename T>
void Queue<T>::push(const T& item){
    rear = _queue.insert_after(rear, item);   //in from the rear, rear update
}

template <typename T>
T Queue<T>::pop(){
    return _queue.delet_node(_queue.Begin());  //front out
}

template <typename T>
bool Queue<T>::empty(){
    return _queue.Begin().is_null();   //chack if the begin iterator is null
}

template <typename T>
T Queue<T>::front(){
    return *_queue.Begin();   //*iterator get the item
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::begin(){
    return Iterator(_queue.Begin());    //_queue.begin() is the iterator
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::end(){
    return Iterator(nullptr);   //end always null
}

template<typename U>
ostream& operator<<(ostream& outs, const Queue<U>& queue){
    outs << queue._queue;   //list has operator << function
    return outs;
}

#endif // QUEUE_H
