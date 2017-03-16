/* File: queue-array.h
 * Name: Paulo Lemus
 * Date: 3/16/2017
 */

#ifndef EE_ARRAY_QUEUE_H_
#define EE_ARRAY_QUEUE_H_

#include <exception>

namespace ee {
namespace array {


//////////////////////////////
//       DECLARATIONS       //
//////////////////////////////

template <typename T>
class queue {

    T* array;
    int head;
    int tail;
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

/////////////////////////////
//     IMPLEMENTATION      //
/////////////////////////////

template <typename T>
queue<T>::queue(int capacity) : 
    cap(capacity), 
    head(0),
    tail(0),
    sz(0), 
    array(new T[capacity]) {}


template <typename T>
int queue<T>::size() { return sz; }
template <typename T>
int queue<T>::capacity() { return cap; }
template <typename T>
bool queue<T>::isEmpty() {
    return (sz <= 0);
}
template <typename T>
bool queue<T>::isFull() {
    return (sz >= cap);
}

template <typename T>
bool queue<T>::push(const T& data) {

    if(sz < cap) {

        if(sz > 0) {
            tail = (tail + 1) % cap;
        }
        array[tail] = data;
        sz++;
        return true;
    } 
    else return false;
}
template <typename T>
T queue<T>::pop() {

    if(sz > 0) {
        int position = head;
        sz--;
        if(head != tail) head = (head + 1) % cap;
        return array[position];
    }
    throw std::runtime_error("Popped from empty queue");
}
template <typename T>
T queue<T>::peek() {
    if(sz > 0) {
        return array[head];
    }
    throw std::runtime_error("Peeked on empty queue");
}

template <typename T>
void queue<T>::print() {
    if(head == tail && size > 0) std::cout << array[head] << std::endl;
    else if(sz > 0) {

        int index = head;
        while(index != tail) {
            std::cout << array[index] << std::endl;
            index = (index + 1) % cap;
        }
    }
}


} // array namespace
} // ee    namespace

#endif
