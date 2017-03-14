/* File: stack-list.h
 * Name: Paulo Lemus
 * Date: 3/13/2017
 */

#ifndef EE_STACK_LIST_H_
#define EE_STACK_LIST_H_

#include <exception>
#include <iostream>

namespace ee {
namespace list {

template <typename T>
struct node {
    T data;
    node* next;
    node* prev;

    node(const T& data);
};

template <typename T>
class stack {

    node<T>* top;
    int sz;
    int cap;

    public:
    stack(int capacity);
    int  size();
    int  capacity();
    bool isEmpty();
    bool isFull();
    bool push(const T& data);
    T    pop();
    void print();
};

////////////////////////////////////
//       Implementations          //
////////////////////////////////////

template <typename T>
node<T>::node(const T& data) : data(data), next(nullptr), prev(nullptr) {}

template <typename T>
stack<T>::stack(int capacity) : cap(capacity), sz(0), top(nullptr) {}
template <typename T>
int stack<T>::size() { return sz; }
template <typename T>
int stack<T>::capacity() { return cap; }
template <typename T>
bool stack<T>::isEmpty() { return (sz <= 0); }
template <typename T>
bool stack<T>::isFull() { return (sz >= cap); }

template <typename T>
bool stack<T>::push(const T& data) {
    if(sz < cap) {
        if(top == nullptr) {
            top = new node<T>(data);
        }
        else {
            node<T>* ptr = new node<T>(data);
            top->next = ptr;
            ptr->prev = top;
            top = ptr;
        }
        sz++;
        return true;
    }
    else return false;
}
template <typename T>
T stack<T>::pop() {
    if(sz > 0) {
        node<T>* ptr = top;
        T data = top->data;
        top = top->prev;
        sz--;
        delete ptr;
        return data;
    }
    throw std::runtime_error("Popped from empty stack");
}

template <typename T>
void stack<T>::print() {
    node<T>* ptr = top;
    while(ptr && ptr->prev) ptr = ptr->prev;
    while(ptr) {
        std::cout << ptr->data << std::endl;
        ptr = ptr->next;
    }
}

} // list namespace
} // ee namespace

#endif
