/* File: queue-list.h
 * Name: Paulo Lemus
 * Date: 3/13/2017
 */

#ifndef EE_QUEUE_LIST_H_
#define EE_QUEUE_LIST_H_

#include <exception>
#include <iostream>

namespace ee {
namespace list {

template <typename T>
struct node {
    T data;
    node* next;

    node(const T& data);
};

template <typename T>
class queue {

    node<T>* head;
    node<T>* tail;
    int sz;
    int cap;

    public:
    queue(int capacity);
    int  size();
    int  capacity();
    bool isEmpty();
    bool isFull();
    bool push(const T& data);
    T    pop();
    T    peek();
    void print();
};

////////////////////////////////////
//       Implementations          //
////////////////////////////////////

template <typename T>
node<T>::node(const T& data) : data(data), next(nullptr) {}

template <typename T>
queue<T>::queue(int capacity) : cap(capacity), sz(0), tail(nullptr), head(nullptr) {}
template <typename T>
int queue<T>::size() { return sz; }
template <typename T>
int queue<T>::capacity() { return cap; }
template <typename T>
bool queue<T>::isEmpty() { return (sz <= 0); }
template <typename T>
bool queue<T>::isFull() { return (sz >= cap); }

template <typename T>
bool queue<T>::push(const T& data) {
    if(sz < cap) {
        if(head == nullptr) {
            head = new node<T>(data);
            tail = head;
        }
        else {
            node<T>* ptr = new node<T>(data);
            tail->next = ptr;
            tail = ptr;
        }
        sz++;
        return true;
    }
    else return false;
}
template <typename T>
T queue<T>::pop() {
    if(sz > 0) {
        T data = head->data;
        node<T>* ptr = head;
        head = head->next;
        sz--;
        delete ptr;
        return data;
        }
    throw std::runtime_error("Popped from empty queue");
}

template <typename T>
T queue<T>::peek() {
    if(sz > 0) {
        return head->data;
    }
    throw std::runtime_error("Peeked on empty queue");
}

template <typename T>
void queue<T>::print() {
    node<T>* ptr = head;
    while(ptr) {
        std::cout << ptr->data << std::endl;
        ptr = ptr->next;
    }
}

} // list namespace
} // ee namespace

#endif
