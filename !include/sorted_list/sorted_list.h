#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include "../../!include/node/node.h"

template <typename T>
class Sorted_List
{
public:
    class Iterator{
    public:
        friend class Sorted_List;      //give access to list to access _ptr
        Iterator(){
            _ptr = NULL;
        }                        //default ctor
        Iterator(node<T>* p): _ptr(p){
            //blank
        }                  //Point Iterator to where p is pointing to
        T& operator *(){
            //I didn't do assert at here, becasue I think, default iterator
            //still have _ptr, but just nullptr, it make sense, but just can't
            //do anything to it, this method will not
            assert(_ptr);
            return _ptr->_item;
        }                        //dereference operator
        T* operator ->(){
            assert(_ptr);
            return *(_ptr->_item);
        }                 //member access operator
        //operator bool();           //casting operator: true if _ptr not NULL
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
            it = ++it;
            return temp;
        }        //friend operator: it++

    private:
        node<T>* _ptr;                          //pointer being encapsulated
    };

    Sorted_List(bool order=true, bool unique=false);
    //CTOR with default args

    //BIG 3:
    ~Sorted_List();
    Sorted_List(const Sorted_List<T> &copyThis);   //copy CTOR
    Sorted_List& operator =(const Sorted_List& RHS);
    //copy assignment operator

    Iterator Insert(const T& i);
    //Insert i in a sorted manner

    T Delete(Sorted_List<T>::Iterator iMarker);
    //delete node pointed to by marker
    void Print() const;
    //the print function for list
    Iterator Search(const T &key) const;
    //return Iterator to node [key]
    Iterator Prev(Iterator iMarker);
    //previous node to marker

    const T& operator[](int index) const;
    //const version of the operator [ ]
    T& operator[](int index);
    //return item at position index
    Iterator Begin() const;
    //Iterator to the head node
    Iterator Last_node() const;
    //Iterator for the last node
    Iterator End() const;
    //Iterator to NULL
    template <class U>
    //Note the template arg U
    friend ostream& operator <<(ostream& outs, const Sorted_List<U>& l);
private:
    node<T>* _head_ptr;
    bool _order;        //asscending is true, descending is false
    bool _unique;

};

template <typename T>
Sorted_List<T>::Sorted_List(bool order, bool unique){
    _head_ptr = NULL;    //default value
    _order = order;
    _unique = unique;
}

template <typename T>
Sorted_List<T>::~Sorted_List(){
    _clearList(_head_ptr);    //clear the dynamic list space
}

template <typename T>
Sorted_List<T>::Sorted_List(const Sorted_List<T> &copyThis){
    _head_ptr = _copy_list(copyThis._head_ptr);  //copy the list
    _order = copyThis._order;      //copy the order
    _unique = copyThis._unique;      //copy the unique
}

template <typename T>
Sorted_List<T>& Sorted_List<T>::operator =(const Sorted_List& RHS){
    //1. check for self-reference
    if(this == &RHS){
        return *this;
    }

    //2. dealloate existing space;
    _clearList(_head_ptr);

    //3. copy rhs list to this list, also, the order, the unique
    _head_ptr = _copy_list(RHS._head_ptr);
    _order = RHS._order;
    _unique = RHS._unique;

    //4. return this object
    return *this;
}

template <typename T>
typename Sorted_List<T>::Iterator Sorted_List<T>::Insert(const T& item){
    if(_unique){     //when in the case of unique
        //use the insert and add
        return Iterator(_insertSorted_and_add(_head_ptr, item, _order));
    }
    //not unique
    return Iterator(_insertSorted(_head_ptr, item, _order));
    //use node function
}

template <typename T>
T Sorted_List<T>::Delete(typename Sorted_List<T>::Iterator iMarker){
    return _delete_node(_head_ptr, iMarker._ptr);   //use node function
}
template <typename T>
void Sorted_List<T>::Print() const{
    return _print_list(_head_ptr);   //print function
}

template <typename T>
typename Sorted_List<T>::Iterator Sorted_List<T>::Search(const T &key) const{
    return Iterator(_search_list(_head_ptr, key));   //use node function
}
template <typename T>
typename Sorted_List<T>::Iterator Sorted_List<T>::Prev(
        Sorted_List<T>::Iterator iMarker){
    return Iterator(_previous(_head_ptr, iMarker._ptr));   //use node function
}

template <typename T>
const T& Sorted_List<T>::operator[](int index) const{
    return _at(_head_ptr, index);     //use node function
}

template <typename T>
T& Sorted_List<T>::operator[](int index){
    return _at(_head_ptr, index);     //use node function
}

template <typename T>
typename Sorted_List<T>::Iterator Sorted_List<T>::Begin() const{
    return Iterator(_head_ptr);      //the begin
}

template <typename T>
typename Sorted_List<T>::Iterator Sorted_List<T>::Last_node() const{
    return Iterator(_last_node(_head_ptr));      //the last node
}

template <typename T>
typename Sorted_List<T>::Iterator Sorted_List<T>::End() const{
    return Iterator(NULL);         //end always null
}

template <class U>
ostream& operator <<(ostream& outs, const Sorted_List<U>& list){
    return _print_list(list._head_ptr, outs);    //print method
}

#endif // SORTED_LIST_H
