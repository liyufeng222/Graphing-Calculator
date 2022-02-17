#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "../../!include/node/node.h"

#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class List{
public:

    class Iterator{     //nest class
    public:
        friend class List;
        Iterator next(){
            node<T>* temp = _ptr->_next;  //go to next iterator
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


    List();  //default constructor

    //Big 3
    List(const List& other);      //copy constructor

    List& operator =(const List& rhs);     //copy sign

    ~List();       //destructor

    template<typename U>
    friend ostream& operator<<(ostream& outs, const List<U>& list);
    // print list function but use >> operator

    void print() const;
    //print function

    Iterator Insert_head(const T& item);
    //insert a new item to the head of the linked list

    Iterator insert_after(Iterator afterThis, const T& item);
    //insert the item after the after this position

    Iterator insert_before(Iterator beforeThis, const T& item);
    //insert the item before the before this position

    Iterator InsertSorted(const T& item);
    //insert the item into the sorted list

    T delet_node(Iterator deleteThis);
    //delet the item in the list

    T& operator[](int index);
    //return the item at the index

    Iterator Search_list(const T& item);
    //search the item in the list, return its ptr, otherwise null ptr

    Iterator next(Iterator nextToThis);
    //return the next node pointer of the given pointer

    Iterator previous(Iterator prevToThis);
    //return the previous node pointer of the given pointer

    Iterator Begin() const;
    //return the head of the list

    Iterator Last_node() const;
    //return the last node on the list

    Iterator End() const;
    //return the end of the list

    List copy_list(List src_list);
    //return a new copy of src list


private:
    node<T>* _head_ptr;

//===========================================================================
//=====================Private Helper function use node======================
//===========================================================================
    node<T>* insert_head(const T& item);
    //insert a new item to the head of the linked list

    node<T>* insert_after(node<T>* afterThis, const T& item);
    //insert the item after the after this position

    node<T>* insert_before(node<T>* beforeThis, const T& item);
    //insert the item before the before this position

    node<T>* insertSorted(const T& item);
    //insert the item into the sorted list

    T delet_node(node<T>* deleteThis);
    //delet the item in the list

    node<T>* search_list(const T& item);
    //search the item in the list, return its ptr, otherwise null ptr

    node<T>* next(node<T>* nextToThis);
    //return the next node pointer of the given pointer

    node<T>* previous(node<T>* prevToThis);
    //return the previous node pointer of the given pointer

    node<T>* begin() const;
    //return the head of the list

    node<T>* last_node() const;
    //return the last node of the list

    node<T>* end() const;
    //return the end of the list

};


template <typename T>
List<T>::List():_head_ptr(nullptr){     //default head ptr null
    //blank
}

template <typename T>
List<T>::List(const List& other){
    _head_ptr = _copy_list(other._head_ptr);
}
template <typename T>
List<T>& List<T>::operator =(const List& rhs){
    //1. check for self-reference
    if(this == &rhs){
        return *this;
    }

    //2. dealloate existing space;
    _clearList(_head_ptr);

    //3. copy rhs list to this list
    _head_ptr = _copy_list(rhs._head_ptr);

    //4. return this object
    return *this;
}
template <typename T>
List<T>::~List(){
    _clearList(_head_ptr);
}

template <typename T>
void List<T>::print() const{
    return _print_list(_head_ptr);   //print function

}

template<typename U>
ostream& operator<<(ostream& outs, const List<U>& list){
    return _print_list(list._head_ptr, outs);   //use node function
}

template <typename T>
List<T> List<T>::copy_list(List src_list){
    List new_list;
    //copy things from src list to the new list
    new_list._head_ptr = _copy_list(src_list._head_ptr);
    return new_list;
}

template <typename T>
T& List<T>::operator[](int index){
    return _at(_head_ptr, index);     //use node function
}

//=======================================================================
//==========================Iterator function============================
//=======================================================================

template <typename T>
typename List<T>::Iterator List<T>::Insert_head(const T& item){
    return Iterator(insert_head(item));
}
//insert a new item to the head of the linked list

template <typename T>
typename List<T>::Iterator List<T>::insert_after(Iterator afterThis,
                                                 const T& item){
    return Iterator(insert_after(afterThis._ptr, item));
}
//insert the item after the after this position

template <typename T>
typename List<T>::Iterator List<T>::insert_before(Iterator beforeThis,
                                                  const T& item){
    return Iterator(insert_before(beforeThis._ptr, item));
}
//insert the item before the before this position

template <typename T>
typename List<T>::Iterator List<T>::InsertSorted(const T& item){
    return Iterator(insertSorted(item));
}
//insert the item into the sorted list

template <typename T>
T List<T>::delet_node(typename List<T>::Iterator deleteThis){
    return delet_node(deleteThis._ptr);
}
//delet the item in the list

template <typename T>
typename List<T>::Iterator List<T>::Search_list(const T& item){
    return Iterator(search_list(item));
}
//search the item in the list, return its ptr, otherwise null ptr

template <typename T>
typename List<T>::Iterator List<T>::next(Iterator nextToThis){
    return Iterator(next(nextToThis._ptr));
}
//return the next node pointer of the given pointer

template <typename T>
typename List<T>::Iterator List<T>::previous(Iterator prevToThis){
    return Iterator(previous(prevToThis._ptr));
}
//return the previous node pointer of the given pointer

template <typename T>
typename List<T>::Iterator List<T>::Begin() const{
    return Iterator(_head_ptr);
}
//return the head of the list

template <typename T>
typename List<T>::Iterator List<T>::Last_node() const{
    return Iterator(last_node());
}
//return the last Iterator of the list

template <typename T>
typename List<T>::Iterator List<T>::End() const{
    return Iterator(end());
}
//return the end of the list


//==========================================================================
//=======================Private Function===================================
//==========================================================================


template <typename T>
node<T>* List<T>::insert_head(const T& item){
    return _insert_head(_head_ptr, item);   //use node function
}

template <typename T>
node<T>* List<T>::insert_after(node<T>* afterThis, const T& item){
    return _insert_after(_head_ptr, afterThis, item);   //use node function
}

template <typename T>
node<T>* List<T>::search_list(const T& item){
    return _search_list(_head_ptr, item);   //use node function
}

template <typename T>
node<T>* List<T>::next(node<T>* nextToThis){
    return Next(nextToThis);   //use node function
}

template <typename T>
node<T>* List<T>::previous(node<T>* prevToThis){
    return _previous(_head_ptr, prevToThis);   //use node function
}

template <typename T>
node<T>* List<T>::insert_before(node<T>* beforeThis, const T& item){
    return _insert_before(_head_ptr, beforeThis, item);  //use node function
}

template <typename T>
node<T>* List<T>::insertSorted(const T& item){
    return _insertSorted(_head_ptr, item);     //use node function
}

template <typename T>
T List<T>::delet_node(node<T>* deleteThis){
    return _delete_node(_head_ptr, deleteThis);    //use node function
}

template <typename T>
node<T>* List<T>::begin() const{
    return _head_ptr;   //begin node
}

template <typename T>
node<T>* List<T>::last_node() const{
    return _last_node(_head_ptr);      //the last node
}

template <typename T>
node<T>* List<T>::end() const{
    return nullptr;                  //end always NULL
}


#endif // LINKED_LIST_H
