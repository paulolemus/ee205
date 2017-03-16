/* File: main-queue.cpp
 * Name: Paulo Lemus
 * Date: 3/13/2017
 */

#include <exception>
#include <iostream>
#include "queue-array.h"
#include "queue-list.h"

int main(){

    ///////////////////////////////////////////
    //             TEST CASES                //
    ///////////////////////////////////////////

    // queue objects from both implementations
    ee::array::queue<int> arrayQueue(5);
    ee::list::queue<int>  listQueue(5);

    // Verify size and capacity functions are working
    std::cout << "arrayQueue capacity: " << arrayQueue.capacity() << std::endl;
    std::cout << "arrayQueue size: "     << arrayQueue.size()     << std::endl;
    std::cout << "listQueue capacity: "  << listQueue.capacity()  << std::endl;
    std::cout << "listQueue size: "      << listQueue.size()      << std::endl;

    // Completely fill both queues
    arrayQueue.enqueue(1);
    arrayQueue.enqueue(2);
    arrayQueue.enqueue(3);
    arrayQueue.enqueue(4);
    arrayQueue.enqueue(5);
    arrayQueue.enqueue(6);
    listQueue.enqueue(1);
    listQueue.enqueue(2);
    listQueue.enqueue(3);
    listQueue.enqueue(4);
    listQueue.enqueue(5);
    listQueue.enqueue(6);

    // Cap and size should both be full
    std::cout << "arrayQueue capacity: " << arrayQueue.capacity() << std::endl;
    std::cout << "arrayQueue size: "     << arrayQueue.size()     << std::endl;
    std::cout << "listQueue capacity: "  << listQueue.capacity()  << std::endl;
    std::cout << "listQueue size: "      << listQueue.size()      << std::endl;
    std::cout << "Is arrayQueue full? "  << arrayQueue.isFull()   << std::endl;
    std::cout << "Is listQueue full? "   << listQueue.isFull()    << std::endl;

    // test print function, prints from base to top of queue
    arrayQueue.print();
    std::cout << std::endl;
    listQueue.print();
    std::cout << std::endl;

    // dequeue test, throws exception if you attempt to over dequeue
    // Intended usage is to check isEmpty before dequeueping
    for(int i = 0; i < arrayQueue.capacity() + 1; ++i) {
        try {
            std::cout << arrayQueue.dequeue() << std::endl;
        } catch(const std::runtime_error& err) {
            std::cout << "Error: " << err.what() << std::endl;
        }
    }
    for(int i = 0; i < listQueue.capacity() + 1; ++i) {
        try {
            std::cout << listQueue.dequeue() << std::endl;
        } catch(const std::runtime_error& err) {
            std::cout << "Error: " << err.what() << std::endl;
        }
    }

    // Check isEmpty function, should be true
    std::cout << "Is arrayQueue empty? " << arrayQueue.isEmpty() << std::endl;
    std::cout << "Is listQueue empty? "  << listQueue.isEmpty()  << std::endl;
    std::cout << "DONE!" << std::endl;


    //////////////////////////////////////////////////////////
    //                    USER TESTING                      //
    //////////////////////////////////////////////////////////

    ee::array::queue<int> arrayQue(10);
    ee::list::queue<int>  listQue(10);
    bool running = true;
    bool usingArray = false;

    std::cout << "\n\nNote that input is UNPROTECTED, enter values correctly" << std::endl;

    while(running){

        int select;
        int data;
        std::cout << "\n\nEnter 1 to enqueue an int" << std::endl;
        std::cout << "Enter 2 to dequeue an int"     << std::endl;
        std::cout << "Enter 3 to get size"           << std::endl;
        std::cout << "Enter 4 to get capacity"       << std::endl;
        std::cout << "Enter 5 to check isFull"       << std::endl;
        std::cout << "Enter 6 to check isEmpty"      << std::endl;
        std::cout << "Enter 7 to print"              << std::endl;
        std::cout << "Enter 8 to switch structure"   << std::endl;

        if(usingArray) {
            std::cout << "Currently editing arrayQueue" << std::endl;
            std::cin >> select;

            switch(select) {
                case 1: 
                    std::cout << "Enter an int: ";
                    std::cin >> data;
                    arrayQue.enqueue(data);
                    break;
                case 2:
                    try {
                        arrayQue.dequeue();
                    } catch(...) {
                        std::cout << "Caught an error" << std::endl;
                    }
                    break;
                case 3:
                    std::cout << "Size: " << arrayQue.size() << std::endl;
                    break;
                case 4:
                    std::cout << "Capacity: " << arrayQue.capacity() << std::endl;
                    break;
                case 5:
                    std::cout << "isFull: " << arrayQue.isFull() << std::endl;
                    break;
                case 6:
                    std::cout << "isEmpty: " << arrayQue.isEmpty() << std::endl;
                    break;
                case 7: 
                    arrayQue.print();
                    break;
                case 8:
                    usingArray = !usingArray;
                    break;
                default:
                    std::cout << "Did nothing" << std::endl;
                    break;
            }

        } else {

            std::cout << "Currently editing listQueue" << std::endl;
            std::cin >> select;

            switch(select) {
                case 1: 
                    std::cout << "Enter an int: ";
                    std::cin >> data;
                    listQue.enqueue(data);
                    break;
                case 2:
                    try {
                        listQue.dequeue();
                    } catch(...) {
                        std::cout << "Caught an error" << std::endl;
                    }
                    break;
                case 3:
                    std::cout << "Size: " << listQue.size() << std::endl;
                    break;
                case 4:
                    std::cout << "Capacity: " << listQue.capacity() << std::endl;
                    break;
                case 5:
                    std::cout << "isFull: " << listQue.isFull() << std::endl;
                    break;
                case 6:
                    std::cout << "isEmpty: " << listQue.isEmpty() << std::endl;
                    break;
                case 7: 
                    listQue.print();
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
