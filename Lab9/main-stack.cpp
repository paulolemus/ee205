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


    //////////////////////////////////////////////////////////
    //                    USER TESTING                      //
    //////////////////////////////////////////////////////////
    ee::array::stack<int> arrayStack(10);
    ee::list::stack<int>  listStack(10);
    bool running = true;
    bool usingArray = false;

    std::cout << "\n\nNote that input is UNPROTECTED, enter values correctly" << std::endl;

    while(running){

        int select;
        int data;
        std::cout << "\n\nEnter 1 to push/enqueue an int" << std::endl;
        std::cout << "Enter 2 to pop/dequeue an int" << std::endl;
        std::cout << "Enter 3 to get size" << std::endl;
        std::cout << "Enter 4 to get capacity" << std::endl;
        std::cout << "Enter 5 to check isFull" << std::endl;
        std::cout << "Enter 6 to check isEmpty" << std::endl;
        std::cout << "Enter 7 to print" << std::endl;
        std::cout << "Enter 8 to switch structure" << std::endl;

        if(usingArray) {
            std::cout << "Currently editing arrayStack" << std::endl;
            std::cin >> select;

            switch(select) {
                case 1: 
                    std::cout << "Enter an int: ";
                    std::cin >> data;
                    arrayStack.push(data);
                    break;
                case 2:
                    try {
                        arrayStack.pop();
                    } catch(...) {
                        std::cout << "Caught an error" << std::endl;
                    }
                    break;
                case 3:
                    std::cout << "Size: " << arrayStack.size() << std::endl;
                    break;
                case 4:
                    std::cout << "Capacity: " << arrayStack.capacity() << std::endl;
                    break;
                case 5:
                    std::cout << "isFull: " << arrayStack.isFull() << std::endl;
                    break;
                case 6:
                    std::cout << "isEmpty: " << arrayStack.isEmpty() << std::endl;
                    break;
                case 7: 
                    arrayStack.print();
                    break;
                case 8:
                    usingArray = !usingArray;
                    break;
                default:
                    std::cout << "Did nothing" << std::endl;
                    break;
            }

        } else {

            std::cout << "Currently editing listStack" << std::endl;
            std::cin >> select;

            switch(select) {
                case 1: 
                    std::cout << "Enter an int: ";
                    std::cin >> data;
                    listStack.push(data);
                    break;
                case 2:
                    try {
                        listStack.pop();
                    } catch(...) {
                        std::cout << "Caught an error" << std::endl;
                    }
                    break;
                case 3:
                    std::cout << "Size: " << listStack.size() << std::endl;
                    break;
                case 4:
                    std::cout << "Capacity: " << listStack.capacity() << std::endl;
                    break;
                case 5:
                    std::cout << "isFull: " << listStack.isFull() << std::endl;
                    break;
                case 6:
                    std::cout << "isEmpty: " << listStack.isEmpty() << std::endl;
                    break;
                case 7: 
                    listStack.print();
                    break;
                case 8:
                    usingArray = !usingArray;
                    break;
                default:
                    std::cout << "Did nothing" << std::endl;
                    break;
            }

        }

    }

    return 0;
}
