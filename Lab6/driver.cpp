/* File: driver.cpp
 * Name: Paulo Lemus
 * Date: 2/19/2017
 */

#include <iostream>
#include "singlylinked.h"
#include "doublylinked.h"

int main(){

    SLinkedList list;

    SNode* test0;
    SNode* test1;
    SNode* test2;
    SNode node0(100);
    SNode node1(99);
    SNode node2(98);

    // Append - WORKS / printAll - WORKS
    list.append(&node0);
    list.append(&node1);
    list.append(&node2);
    list.printAll(list.getHead());

    // Find - WORKS
    test0 = list.find(99);
    std:: cout << test0->value << std::endl;

    // Add - WORKS
    SNode addnode(5000);
    test2 = list.add(&node0, &addnode);
    list.printAll(list.getHead());
    std::cout << test2->value << std::endl;

    // Insert - WORKS
    SNode insertnode0(1);
    SNode insertnode1(2);
    SNode insertnode2(3);
    test0 = list.insert(&insertnode0, list.getHead());//insert new head
    test1 = list.insert(&insertnode1, list.getTail());// insert before tail
    test2 = list.insert(&insertnode2, test2);         // insert before 5000
    list.printAll(list.getHead());
    std::cout << "Test0: " << *test0 << std::endl;
    std::cout << "Test1: " << *test1 << std::endl;
    std::cout << "Test2: " << *test2 << std::endl;
    std::cout << "HEAD : " << list.getHead()->value << std::endl;
    std::cout << "TAIL : " << list.getTail()->value << std::endl;

    // Erase - WORKS
    list.erase(list.getHead());
    list.printAll(list.getHead());
    list.erase(list.getTail());
    list.printAll(list.getHead());
    list.erase(test2);
    list.printAll(list.getHead());

    // Advance - WORKS
    test2 = list.advance(list.getHead(), 1); // Should be 5000
    std::cout << "Value = " << *test2 << std::endl;


    std::cout << "------------------------------------------" << std::endl;

    DLinkedList dlist;

    DNode* test3;
    DNode* test4;
    DNode* test5;
    DNode node3(1000);
    DNode node4(2000);
    DNode node5(3000);

    // Append - WORKS / printAll - WORKS
    dlist.append(&node3);
    dlist.append(&node4);
    dlist.append(&node5);
    dlist.printAll(dlist.getHead());

    // Find - WORKS
    test3 = dlist.find(2000);
    std:: cout << test3->value << std::endl;

    // Add - WORKS
    DNode addNode(50000);
    test5 = dlist.add(&node3, &addNode);
    dlist.printAll(dlist.getHead());
    std::cout << test5->value << std::endl;

    // Insert - WORKS
    DNode insertnode3(1);
    DNode insertnode4(2);
    DNode insertnode5(3);
    test3 = dlist.insert(&insertnode3, dlist.getHead());//insert new head
    test4 = dlist.insert(&insertnode4, dlist.getTail());// insert before tail
    test5 = dlist.insert(&insertnode5, test5);         // insert before 5000
    dlist.printAll(dlist.getHead());
    std::cout << "Test0: " << *test3 << std::endl;
    std::cout << "Test1: " << *test4 << std::endl;
    std::cout << "Test2: " << *test5 << std::endl;
    std::cout << "HEAD : " << dlist.getHead()->value << std::endl;
    std::cout << "TAIL : " << dlist.getTail()->value << std::endl;

    // Erase - WORKS
    dlist.erase(dlist.getHead());
    dlist.printAll(dlist.getHead());
    dlist.erase(dlist.getTail());
    dlist.printAll(dlist.getHead());
    dlist.erase(test5);
    dlist.printAll(dlist.getHead());

    // Advance - WORKS
    test5 = dlist.advance(dlist.getHead(), 1); // Should be 5000
    std::cout << "Value = " << *test5 << std::endl;
    test5 = dlist.advance(dlist.getTail(), -1); // Should be 2000
    std::cout << "Value = " << *test5 << std::endl;


    return 0;
}
