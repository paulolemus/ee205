/* File: main-stack.cpp
 * Name: Paulo Lemus
 * Date: 3/13/2017
 */

#include <exception>
#include <iostream>
#include "stack-array.h"
#include "stack-list.h"

int main(){

    // Stack objects from both implementations
    ee::array::stack<int> arrayStk(5);
    ee::list::stack<int>  listStk(5);

    // Verify size and capacity functions are working
    std::cout << "arrayStk capacity: " << arrayStk.capacity() << std::endl;
    std::cout << "arrayStk size: "     << arrayStk.size()     << std::endl;
    std::cout << "listStk capacity: "  << listStk.capacity()  << std::endl;
    std::cout << "listStk size: "      << listStk.size()      << std::endl;

    // Completely fill both stacks
    arrayStk.push(1);
    arrayStk.push(2);
    arrayStk.push(3);
    arrayStk.push(4);
    arrayStk.push(5);
    arrayStk.push(6);
    listStk.push(1);
    listStk.push(2);
    listStk.push(3);
    listStk.push(4);
    listStk.push(5);
    listStk.push(6);

    // Cap and size should both be full
    std::cout << "arrayStk capacity: " << arrayStk.capacity() << std::endl;
    std::cout << "arrayStk size: "     << arrayStk.size()     << std::endl;
    std::cout << "listStk capacity: "  << listStk.capacity()  << std::endl;
    std::cout << "listStk size: "      << listStk.size()      << std::endl;
    std::cout << "Is arrayStk full? "  << arrayStk.isFull()   << std::endl;
    std::cout << "Is listStk full? "   << listStk.isFull()    << std::endl;

    // test print function, prints from base to top of stack
    arrayStk.print();
    std::cout << std::endl;
    listStk.print();
    std::cout << std::endl;

    // Pop test, throws exception if you attempt to over pop
    // Intended usage is to check isEmpty before popping
    for(int i = 0; i < arrayStk.capacity() + 1; ++i) {
        try {
            std::cout << arrayStk.pop() << std::endl;
        } catch(const std::runtime_error& err) {
            std::cout << "Error: " << err.what() << std::endl;
        }
    }
    for(int i = 0; i < listStk.capacity() + 1; ++i) {
        try {
            std::cout << listStk.pop() << std::endl;
        } catch(const std::runtime_error& err) {
            std::cout << "Error: " << err.what() << std::endl;
        }
    }

    // Check isEmpty function, should be true
    std::cout << "Is arrayStk empty? " << arrayStk.isEmpty() << std::endl;
    std::cout << "Is listStk empty? "  << listStk.isEmpty()  << std::endl;
    std::cout << "DONE!" << std::endl;
    return 0;
}
