#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
struct node{
    T _item;
    node<T>* _next;

    node(const T& item=T(), node<T>* next = nullptr)
        : _item(item), _next(next){   //assign item to _item, next to _next
        //Blank
    }

    template<typename U>
    friend ostream& operator<<(ostream& outs, const node<U>& object);
};

template <typename U>
ostream& operator<<(ostream&outs, const node<U>& object){
    outs<<object._item;    //output the item
    return outs;
}

template <typename T>
node<T>* _insert_head(node<T>*& head_ptr, const T& item);
//insert a new item to the head of the linked list

template <typename T>
ostream& _print_list(node<T>* head_ptr, ostream& outs = cout);
//print the linked list

template <typename T>
void _print_list_backward(node<T>* head_ptr);
//print the list in backward

template <typename T>
node<T>* _insert_after(node<T>*& head_ptr, node<T>* afterThis, const T& item);
//insert the item after the after this position

template <typename T>
node<T>* _insert_before(node<T>*& head_ptr, node<T>* beforeThis,
                        const T& item);
//insert the item before the before this position

template <typename T>
node<T>* _search_list(node<T>* head_ptr, const T& item);
//search the item in the list, return its ptr, otherwise null ptr

template <typename T>
node<T>* Next(node<T>* nextToThis);
//return the next node pointer of the given pointer

template <typename T>
node<T>* _previous(node<T>* head_ptr, node<T>* prevToThis);
//return the previous node pointer of the given pointer

template <typename T>
node<T>* _copy_list(node<T>* head_ptr);
//retrn a new list head_ptr with all the items in head_ptr

template <typename T>
T _remove_head(node<T>*& head_ptr);
//remove the head node, return the item that it just remove

template <typename T>
T _delete_node(node<T>*& head_ptr, node<T>* remove_this);
//deletem or remove the item in the list

template <typename T>
void _clearList(node<T>*& head_ptr);
//delete all the elements in the list

template <typename T>
T& _at(node<T>* head_ptr, int pos);
//item at this position

template <typename T>
node<T>* _last_node(node<T>* head_ptr);
//return the position of the last node

template <typename T>
node<T>* _whereThisGoes(node<T>* head_ptr,const T& item,bool ascending=true);
//find the position, when the item should insert after

template <typename T>
node<T>* _insertSorted(node<T>*& head_ptr,const T& item,bool ascending=true);
//insert the item in the sorted list


//========================================================================

template<typename T>
node<T>* _insert_head(node<T>*& head_ptr, const T& item){
    //1. create the new node for the item
    node<T>* temp = new node<T>(item);
    //2. assign next of the new node to the original head_ptr
    temp->_next = head_ptr;
    //3. assign the head_ptr to new head
    head_ptr = temp;
    //4. return new head_ptr
    return head_ptr;
}

template<typename T>
ostream& _print_list(node<T>* head_ptr, ostream& outs){
    node<T>* walker = head_ptr;   //walker go throught the list
    outs << "H->";
    while(walker != nullptr){
        outs <<"["<< *walker<<"]->";         //print the single node
        walker = walker->_next;
    }
    outs << "|||" << endl;
    return outs;
}

template <typename T>
void _print_list_backward(node<T>* head_ptr){
    node<T>* walker = head_ptr;
    node<T>* next_one = walker->_next;
    if(next_one != nullptr){
        //not end, then keep recursion to the end
        _print_list_backward(next_one);      //next walker check
    }
    cout <<"["<< *walker<<"]->";
}

template <typename T>
node<T>* _insert_after(node<T>*& head_ptr, node<T>* afterThis, const T& item){
    //1. create the new node for the item
    node<T>* temp = new node<T>(item);
    //2.(a)if head_ptr is nullptr
    if(head_ptr == nullptr){
        return _insert_head(head_ptr, item);
    }
    //2(b). assign next of the new node to the afterThis next pointing to
    temp->_next = afterThis->_next;
    //3. assign the next of the afterThis to new head
    afterThis->_next = temp;
    //4. return new node position
    return temp;
}

template <typename T>
node<T>* _insert_before(node<T>*& head_ptr, node<T>* beforeThis,
                        const T& item){
    //1. get the previous element
    //using _previous() will check error
    node<T>* pre_this = _previous(head_ptr, beforeThis);
    //2. when it is the head
    if(pre_this == nullptr){
        return _insert_head(head_ptr, item);
    }
    //3. create new node for item
    node<T>* temp = new node<T>(item);
    //4. let the prev node point to it
    pre_this->_next = temp;
    //5. let the new node point to the beforeThis element
    temp->_next = beforeThis;
    //6. return the new node position
    return temp;

}

template <typename T>
node<T>* _search_list(node<T>* head_ptr, const T& item){
    node<T>* walker = head_ptr;   //walker go throught the list
    while(walker != nullptr){
        if(walker->_item == item){     //if found, the return
            return walker;
        }
        walker = walker->_next;     //next node
    }
    return nullptr;      //not found
}

template <typename T>
node<T>* Next(node<T>* nextToThis){
    return nextToThis->_next;   //return the next ptr of this
}
//return the next node pointer of the given pointer

template <typename T>
node<T>* _previous(node<T>* head_ptr, node<T>* prevToThis){
    //check if the mark is the head element
    if(head_ptr == prevToThis){
        return nullptr;
    }
    bool is_found = false;
    node<T>* walker = head_ptr;   //walker go throught the list
    node<T>* walker_next = walker->_next; //the next one to compare
    while(walker != nullptr){
        if(walker_next == prevToThis){    //if walker next is the prevToThis
            is_found = true;
            return walker;                  //the return the walker
        }
        walker = walker->_next;     //next node
        walker_next = walker->_next;   //move next
    }
    //not found, so that it pass the assert not found
    assert(is_found);
    return nullptr;
}


template <typename T>
node<T>* _copy_list(node<T>* head_ptr){
    node<T>* temp_head = nullptr;    //create the new list
    node<T>* walker = head_ptr;    //walker for src list
    node<T>* temp_walker = temp_head;    //walker for new list
    while(walker != nullptr){
        //keep insert the item in the src list to new list
        temp_walker = _insert_after(temp_head, temp_walker, walker->_item);
        walker = walker->_next;
    }
    return temp_head;
}

template <typename T>
T _remove_head(node<T>*& head_ptr){
    assert(head_ptr != nullptr);    //it should not be a empty list
    node<T>* remove_this = head_ptr;    //put a mark to the head_ptr
    head_ptr = head_ptr->_next;        //let the head_ptr point to the next
    T item_remove = remove_this->_item;    //hold he item going to remove
    delete remove_this;        //delete the original head
    return item_remove;
}

template <typename T>
T _delete_node(node<T>*& head_ptr, node<T>* remove_this){
    //1. get the previous element
    //_previous() function will check error, and assert out
    node<T>* pre_this = _previous(head_ptr, remove_this);
    //2. check if it is head
    if(pre_this == nullptr){
        return _remove_head(head_ptr);
    }
    //3. make the previous element point next to the remove_this next
    pre_this->_next = remove_this->_next;
    //4. hold the item being removed
    T item = remove_this->_item;
    //5. delete the item
    delete remove_this;
    return item;
}

template <typename T>
void _clearList(node<T>*& head_ptr){
    while(head_ptr != nullptr){
        //_remove_head() head_ptr pass by reference
        _remove_head(head_ptr);     //keep deleting head element
    }
}

template <typename T>
T& _at(node<T>* head_ptr, int pos){
    assert(pos >= 0);
    int count = 0;    //count for the size
    node<T>* walker = head_ptr;
    while(walker != nullptr){
        count++;     //count of size add one
        if(pos == count - 1){    //current size - 1, is the current index
            return walker->_item;   //then return the item
        }
        walker = walker->_next;    //walker to next
    }
    //pos has to be less or equal to the last index of the list
    assert(pos < count -1 || pos == count - 1);
    //unuseful, but need to return at the end for ensure
    return walker->_item;
}


template <typename T>
node<T>* _whereThisGoes(node<T>* head_ptr,const T& item,bool ascending){
    if(head_ptr == nullptr){
        return nullptr;
    }
    node<T>* bound_front = nullptr;   //the item mayplace before the first
    node<T>* bound_back = head_ptr;   //so set it compare with null - first
    while(bound_back != nullptr){
        //must check nullptr first, if it is nullptr, it will not call _item
        if((bound_front == nullptr || item == bound_front->_item ||
            item > bound_front->_item) &&
           (bound_back == nullptr || item < bound_back->_item) &&
            ascending){
            // nullptr <= item < back OR front <= item < back
            // OR front <= item <nullptr
            return  bound_front;   // when in the bound return the front one
        }else if((bound_front == nullptr || item == bound_front->_item ||
                  item < bound_front->_item) &&
                 (bound_back == nullptr || item > bound_back->_item) &&
                 !ascending){
            // nullptr >= item > back OR front >= item > back
            // OR front >= item > nullptr
            return bound_front;   // when in the bound return the front one
        }
        bound_front = bound_back;
        bound_back = bound_back->_next;   //move to next
    }
    return bound_front;    //the last item, after it
}

template <typename T>
node<T>* _insertSorted(node<T>*& head_ptr,const T& item,bool ascending){
    node<T>* target = _whereThisGoes(head_ptr, item, ascending);
    if(target == nullptr){
        //null means may emtpy list or before the first one
        return _insert_head(head_ptr, item);
    }
    //insert after the target
    return _insert_after(head_ptr, target, item);
}

template <typename T>
node<T>* _insertSorted_and_add(node<T>*& head_ptr,const T& item,
                               bool ascending){
    node<T>* target = _whereThisGoes(head_ptr, item, ascending);
    if(target == nullptr){
        //null means may emtpy list or before the first one
        return _insert_head(head_ptr, item);
    }
    if(target->_item == item){    //when the item has been in the list
        target->_item += item;    //add the item to the one in the list
        return target;     //return the postion where it add
    }
    //when item is new, that add it after the target
    return _insert_after(head_ptr, target, item);
}

template <typename T>
node<T>* _last_node(node<T>* head_ptr){
    if(head_ptr == nullptr){
        return nullptr;
    }
    node<T>* walker = head_ptr;   //walker go throught the list
    while(walker->_next != nullptr){   //while is not the last one
        walker = walker->_next;     //next node
    }
    return walker;      //not found
}

#endif // NODE_H
