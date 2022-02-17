#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <assert.h>
#include "../one_d_pointer/one_d_pointer_tool.h"
#include "../add_entry/add_entry.h"

using namespace std;

template <class T>
class Vector{
public:

    Vector(unsigned int capacity = 3);   //default constructor

    // big three:
    Vector(const Vector& other);   //copy constructor
    Vector& operator=(const Vector& other);    //copy assignment
    ~Vector();    //destructor

    //member access functions:
    T operator [](const unsigned int index) const;   //return theindex element
    T& operator [](const unsigned int index);
    //return the index element reference
    T& at(int index);             //return reference to item at position index
    T at(int index) const;  //return a const item at position index
    T& front() const;             //return item at position 0.
    T& back() const;              //return item at the last position


    //Push and Pop functions:
    Vector& operator +=(const T& item); //push_back
    void push_back(const T& item);      //append to the end
    T pop_back();                       //remove last item and return it


    //Insert and Erase:
    void insert(int insert_here, const T& insert_this); //insert at pos
    void erase(int erase_index);        //erase item at position
    int index_of(const T& item);        //search for item. retur index.

    //size and capacity:
    void set_size(int size, T initial_value = T());
    //enlarge the vector to this size
    void set_capacity(int capacity);    //allocate this space
    int size() const; //return _size
    int capacity() const; //return _capacity

    bool empty() const;                 //return true if vector is empty

    //Error handling:
    int is_error() const;   //check if error exist
    int error() const;   //return error
    void clear();      //reset the error
    string error_description(int e) const;
    //error description of specific error
    string error_description() const;

    //OUTPUT:
    //template <class U>
    //friend ostream& operator <<(ostream& outs, const Vector<U>& _list);
    //output format
private:
    T* _vector;
    int _size;
    int _capacity;
    int _error;
};

//=========================================================================
//===========================Function definetion===========================
//=========================================================================
template <typename T>
Vector<T>::Vector(unsigned int capacity){
    /*const bool debug = true;
    if (debug){
        cout<<"Vector CTOR()"<<endl;
    }*/
    assert(capacity > 0);
    _vector = allocate<T>(_capacity);   //new dynamic array
    _size = 0;         //size to 0
    _capacity = capacity;    //size
}

// big three:
template <typename T>
Vector<T>::Vector(const Vector& other){
    /*const bool debug = true;
    if (debug){
        //cout<<"Vector CTOR("<<other<<")"<<endl;
    }*/
    _size = other.size();
    _capacity = other.capacity();
    _vector = allocate<T>(_capacity);

    copy_list(_vector,other._vector,_size);   //copy other list to it
    _error = is_error();
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other){

    //const bool debug = true;
    /*if (debug){
        //cout<<"Vector =("<<other<<")"<<endl;
    }*/
    //1. check for self-reference
    if(this == &other){
        return *this;
    }
    //2. dealloate existing space;
    delete[] _vector;

    //3. allocate space for new string
    _vector = allocate<T>(other._capacity);
    _size = other.size();
    _capacity = other.capacity();

    //4. copy everything over
    copy_list(_vector,other._vector,other.size());

    //5. return this object
    _error = is_error();   //check if error
    return *this;
}
template <typename T>
Vector<T>::~Vector(){
    //const bool debug = true;
    /*if (debug){
        cout<<"~Vector: ";

        //cout<< *this <<endl;
    }*/
    delete [] _vector;   //delete the dynamic allocation
}

//member access functions:
template <typename T>
T Vector<T>::operator [](const unsigned int index) const{
    //at function has checked error
    return at(index);    //use at() method
}
template <typename T>
T& Vector<T>::operator [](const unsigned int index){
    //at function has checked error
    return at(index);    //use at() method
}
template <typename T>
T& Vector<T>::at(int index){
    assert(index < _size);
    T* walker = _vector + index;   //move to index element
    return *walker;
}
template <typename T>
T Vector<T>::at(int index) const{
    //at function has checked error
    return at(index);       //use the previous one get the index element
}
template <typename T>
T& Vector<T>::front() const{
    return *_vector;       //return first element
}
template <typename T>
T& Vector<T>::back() const{
    T* walker = _vector + _size - 1;    //move to last element
    return *walker;
}


//Push and Pop functions:
template <typename T>
Vector<T>& Vector<T>::operator +=(const T& item){
    //add item to the end
    _vector = add_entry(_vector, item, _size, _capacity);
    return *this;
}
template <typename T>
void Vector<T>::push_back(const T& item){
    //add item to the end
    _vector = add_entry(_vector, item, _size, _capacity);
}
template <typename T>
T Vector<T>::pop_back(){
    T* last_element = _vector + _size - 1;
    //remove last element
    remove_at_index(_vector, _size - 1, _size, _capacity);
    return *last_element;
}


//Insert and Erase:
template <typename T>
void Vector<T>::insert(int insert_here, const T& insert_this){
    assert(insert_here >= 0 && insert_here <= _size); //may insert at the end
    //use the insert index function in add_entry
    _vector = insert_at_index(_vector,insert_this,insert_here,_size,_capacity);
}
template <typename T>
void Vector<T>::erase(int erase_index){
    assert(erase_index >= 0 && erase_index < _size);
    //use the remove index in add_entry library
    _vector = remove_at_index(_vector,erase_index,_size,_capacity);
}
template <typename T>
int Vector<T>::index_of(const T& item){
    int index;   //the index of the element
    search_entry(_vector,item,_size,index);   //if not found, index = -1
    return index;
}

//size and capacity:
template <typename T>
void Vector<T>::set_size(int size, T initial_value){
    assert(size >= 0);
    if(size > _size){
        //check_capacity until the size less then capacity
        while(size > _capacity){
            _vector = check_capacity(_vector, size, _size, _capacity);
        }
        //initial the rest size to default value
        init1D(_vector + _size, size - _size, initial_value);
        _size = size;
    }else if(size < _size){
        _size = size;
        //check and recapacity until the size more then 1/4 of the capacity
        while(size <= _capacity / 4){
            _vector = check_capacity(_vector, size, _size, _capacity);
        }
    }
    _error = is_error();  //double check if error exist
}
template <typename T>
void Vector<T>::set_capacity(int capacity){
    assert(capacity > 0);
    _capacity = capacity;   //set capacity
}

/*//=========================================================================
template <typename U>
ostream& operator <<(ostream& outs, const Vector<U>& _list){
    U* walker = _list._vector;
    for (int i=0; i<_list.size(); i++){
        outs<<*walker<<" ";   //print out all the element
        walker++;
    }
    return outs;
}
//=========================================================================
*/
//Return functions
template <typename T>
int Vector<T>::size() const{
    return _size;    //return size
}
template <typename T>
int Vector<T>::capacity() const{
    return _capacity;    //return capacity
}
template <typename T>
bool Vector<T>::empty() const{
    return _size == 0;    //check size if is zero
}

//Error handling function
template<typename T>
int Vector<T>::is_error() const{
    if(_size > _capacity){    //size can't not greater then capacity
        return -1;
    }else if(_capacity <= 0){   //capacity should be positive
        return -2;
    }else if(_size < 0){     //size can not be negative
        return  -3;
    }
    return 0;
}

template<typename T>
int Vector<T>::error() const{
    return _error;
}

template<typename T>
void Vector<T>::clear(){
    _error = 0;   //set to no error
}

template<typename T>
string Vector<T>::error_description(int e) const{
    switch (e) {       //check error cases
        case 0:
            return "No Error";
        case -1:
            return "Size cannot greater then capacity.";
        case -2:
            return "Capacity should not be less that 0.";
        case -3:
            return "Size can not be negative.";
        default:
            return "Unknow_Error!";
    }
}

template<typename T>
string Vector<T>::error_description() const{
    return error_description(_error);   //return the current _error status
}

#endif // VECTOR_H
