/* File: doublylinked.cpp
 * Name: Paulo Lemus
 * Date: 2/21/2017
 */


/* This file contains code for a doubly linked list.
 * It has the following functions:
 *
 * insert before a node
 * add after a node
 * erase given node
 * find node with a value
 * get node n away from given node
 * add node to end of list
 * print list starting from given node
 */

#include <iostream>
#include <cmath>
#include "doublylinked.h"

/* Over load << for ease of printing */
DNode::DNode(int value, DNode* n, DNode* p) :value(value), next(n), prev(p){}
std::ostream& operator<<(std::ostream& output, const DNode& dn){
    output << dn.value;
    return output;
}

DLinkedList::DLinkedList(){
    head = NULL;
    tail = NULL;
}
/* Insert n before p, return n pointer, assuming p is in list.
 * I first check for the head case, where n replaces head.
 * Otherwise, I get the previous node of p and insert n inbetween
 */
DNode* DLinkedList::insert(DNode* n, DNode* p){
    DNode* previous = NULL;
    if(p == head){ // headcase
        p->prev = n;
        n->next = p;
        head = n;
        return n;
    }
    previous       = p->prev;
    previous->next = n;
    n->prev        = previous;
    n->next        = p;
    p->prev        = n;
    return n;

}
/* Add n after p, return n pointer, assuming p is in list
 * I first check for the tail case, where I need to reassign the tail.
 * Otherwise I get the next node, and insert n between p and next.
 */
DNode* DLinkedList::add(DNode* p, DNode* n){
    DNode* after = p->next;
    if(p == tail){
        p->next = n;
        n->prev = p;
        tail = n;
        return n;
    }
    p->next     = n;
    n->next     = after;
    after->prev = n;
    n->prev     = p;
    return n;
}
/* Erase has three cases:
 * p is either the head, the tail, or an internal node.
 * First I check for head or tail cases, which require the
 * head or tail to be moved.
 * Otherwise I point the previous and next pointers to each other.
 */
DNode* DLinkedList::erase(DNode* p){ 
    DNode* previous = NULL;
    DNode* after    = NULL;

    if(p == head){
        head = head->next;
        previous = head;
    }
    else if (p == tail){
        tail = tail->prev;
        tail->next = NULL;
        previous = tail;
    }
    else{
        previous = p->prev;
        after    = p->next;
        previous->next = after;
        after->prev    = previous;
    }
    return previous;
}
/* Given a node and a value, iterate through list checking each node value
 * until one is equal to value, then return that node. Otherwise, return
 * null if not found.
 */
DNode* DLinkedList::find(DNode* b, int s){ 
    DNode* curr = b;
    while(curr){
        if(curr->value == s) return curr;
        if(curr == tail) break;
        curr = curr->next;
    }
    return NULL;
}
/* Same as above, except this searches the whole list from the head */
DNode* DLinkedList::find(int s){ 
    DNode* curr = head;
    while(curr){
        if(curr->value == s) return curr;
        if(curr == tail) break;
        curr = curr->next;
    }
    return NULL;
}
/* Given a node, return the node n nodes away from it.
 * If the nth element would be NULL, return NULL.
 */
DNode* DLinkedList::advance(DNode* p, int n){ 
    DNode* item = p;
    int change  = n / abs(n);
    if(item == NULL) return NULL;
    for(int i = 0; i != n; i+=change){
        item = (n > 0) ? item->next : item->prev;
        if(item == NULL) return NULL;
    }
    return item;
}
/* Add a to end of list. First check head and tail as they are
 * special cases, otherwise replace the tail.
 */
void   DLinkedList::append(DNode* p){ // add a to end of list
    if(head == NULL){
        head = p;
    }
    if(tail != NULL){
        tail->next = p;
        p->prev = tail;
    }
    tail = p;
    tail->next = NULL;
}
/* Iterate through list from given node */
void   DLinkedList::printAll(DNode* p){
    while(p){
        std::cout << p->value;
        if(p = p->next) std::cout << ", ";
    }
    std:: cout << "\n";
}

/* Getters and setters */
DNode* DLinkedList::getTail(){return tail;}
DNode* DLinkedList::setTail(DNode* p){tail = p;}
DNode* DLinkedList::getHead(){return head;}
DNode* DLinkedList::setHead(DNode* p){head = p;}
