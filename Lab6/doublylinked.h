/* File: doublylinked.h
 * Name: Paulo Lemus
 * Date: 2/21/2017
 */

#ifndef EE_DOUBLYLINKED_H_
#define EE_DOUBLYLINKED_H_

/* The declaration for Doubly Linked List elements.
 * This file contains two classes, a DoublyLinkedList, and the
 * DNode class to populate the list.
 */

struct DNode{
    int value;
    DNode* next;
    DNode* prev;

    DNode(int value, DNode* n = NULL, DNode* p = NULL);
    friend std::ostream& operator<<(std::ostream& output, const DNode& dn);
};

class DLinkedList{
    DNode* head;
    DNode* tail;

    public:
    DLinkedList();
    DNode* insert(DNode* n, DNode* p); // insert n before p, return n pointer
    DNode* add(DNode* p, DNode* n);    // add n after p, return n pointer
    DNode* erase(DNode* p);            // erase node p
    DNode* find(DNode* b, int s);      // from b to null, return node with s
    DNode* find(int s);                // seach whole list for s
    DNode* advance(DNode* p, int n);   // Return the node n away from p
    void   append(DNode* p);           // add a to end of list
    void   printAll(DNode* p);         // Print list values from node p

    /* Getters and setters */
    DNode* getTail();
    DNode* setTail(DNode* p);
    DNode* getHead();
    DNode* setHead(DNode* p);
};

#endif
