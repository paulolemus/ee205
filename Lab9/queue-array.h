#ifndef EE_ARRAY_QUEUE_H_
#define EE_ARRAY_QUEUE_H_

namespace ee {
namespace list {

#include <exception>

//////////////////////////////
//       DECLARATIONS       //
//////////////////////////////

template <typename T>
class queue {

    T* array;
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
queue<T>::queue(int capacity) : cap(capacity), sz(0), array(new T[capacity]) {}

template <typename T>
int queue<T>::size() { return sz; }
template <typename T>
int queue<T>::capacity() { return cap; }
template <typename T>
bool queue<T>::isEmpty() {

}
template <typename T>
bool queue<T>::isFull() {

}

template <typename T>
bool queue<T>::push(const T& data) {


}
template <typename T>
T queue<T>::pop() {

}
template <typename T>
T queue<T>::peek() {

}

template <typename T>
void queue<T>::print() {

}


} // list namespace
} // ee   namespace

#endif
