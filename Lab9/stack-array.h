/* File: stack-array.h
 * Name: Paulo Lemus
 * Date: 3/9/2017
 */

#ifndef EE_STACK_ARRAY_H_
#define EE_STACK_ARRAY_H_

#include <iostream>

namespace EE {

template <typename T>
class stack {
    T* array;
    int sz;
    int cap;

    public:
    stack(int capacity);
    int  size();
    int  capacity();
    bool push(T& data);
    T    pop();
    void print();
};

///////////////////////////////////////////
//           Implementations             //
///////////////////////////////////////////

template <typename T>
stack<T>::stack(int cap):sz(0), 
                 cap(cap), 
                 array(new T[cap]){}
template <typename T>
int stack<T>::size(){ return sz; }
template <typename T>
int stack<T>::capacity(){ return cap; }
template <typename T>
bool stack<T>::push(T& data){
    if(sz < cap){
        array[sz] = data;
        sz++;
        return true;
    }
    return false;
}
template <typename T>
T stack<T>::pop(){
    if(sz > 0){
        sz--;
        return array[sz];
    }
    return (T)nullptr;
}

template <typename T>
void stack<T>::print(){
    for(int i = 0; i < sz; ++i){
        std::cout << array[i] << std::endl;
    }
}

} // namespace EE

#endif
