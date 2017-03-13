/* File: singlylinked.h
 * Name: Paulo Lemus
 * Date: 2/19/2017
 */

#ifndef EE_SINGLYLINKED_H_
#define EE_SINGLYLINKED_H_

/* This file contains code for a singly linked list.
 */

struct SNode{
    int value;
    SNode* next;
    SNode(int value, SNode* n = NULL);
    friend std::ostream& operator<<(std::ostream& output, const SNode& sn);
};

class SLinkedList{
    SNode* head;
    SNode* tail;

    public:
    SLinkedList();
    SNode* insert(SNode* n, SNode* p); // insert n before p, return n pointer
    SNode* add(SNode* p, SNode* n);    // add n after p, return n pointer
    SNode* erase(SNode* p);            // erase node p
    SNode* find(SNode* b, int s);      // from b to null, return node with s
    SNode* find(int s);                // seach whole list for s
    SNode* advance(SNode* p, int n);
    void   append(SNode* p);           // add a to end of list
    void   printAll(SNode* p);

    SNode* getTail();
    SNode* setTail(SNode* p);
    SNode* getHead();
    SNode* setHead(SNode* p);
};

#endif
