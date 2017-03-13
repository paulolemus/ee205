/* File: singlylinked.cpp
 * Name: Paulo Lemus
 * Date: 2/19/2017
 */


/* This file contains the implementation for a SinglyLinkedList
 * and its SNode.
 */

#include <iostream>
#include "singlylinked.h"

SNode::SNode(int value, SNode* n) :value(value), next(n){}
std::ostream& operator<<(std::ostream& output, const SNode& sn){
    output << sn.value;
    return output;
}

SLinkedList::SLinkedList(){
    head = NULL;
    tail = NULL;
}
SNode* SLinkedList::insert(SNode* n, SNode* p){ 
    // insert n before p, return n pointer, assuming p is in the list

    SNode* previous = NULL;
    SNode* current  = head;
    // iterate through list looking for p, save previous node
    while(current){
        if( current == p) break;
        previous = current;
        current  = current->next;
    }
    if(current == head){ // headcase
        n->next = p; 
        head = n;
    }
    else{
        previous->next = n;
        n->next = current;
    }
    return n;
}
SNode* SLinkedList::add(SNode* p, SNode* n){ // add n after p, return n pointer
    SNode* after = p->next;
    if(after == NULL){
        p->next = n;
        return n;
    }
    p->next = n;
    n->next = after;
    return n;
}
SNode* SLinkedList::erase(SNode* p){ // erase node p, assuming p is in list
    SNode* previous = NULL;
    SNode* current  = head;
    while(current){
        if(current == p) break;
        previous = current;
        current = current->next;
    }
    if(current == head){
        head = head->next;
        previous = current;
    }
    else if(current == tail){
        tail = previous;
        previous->next = NULL;
    }
    else{ 
        previous->next = current->next;
    }
    return previous;
}
SNode* SLinkedList::find(SNode* b, int s){ // from b to null, return node with s
    SNode* curr = b;
    while(curr){
        if(curr->value == s) return curr;
        if(curr == tail) break;
        curr = curr->next;
    }
    return NULL;
}
SNode* SLinkedList::find(int s){ // Seach whole list for s
    SNode* curr = head;
    while(curr){
        if(curr->value == s) return curr;
        if(curr == tail) break;
        curr = curr->next;
    }
    return NULL;
}
SNode* SLinkedList::advance(SNode* p, int n){ // given p, return the element n ahead
    SNode* item = p;
    if(item == NULL || n < 0) return NULL;
    for(int i = 0; i < n; i++){
        item = item->next;
        if(item == NULL) return NULL;
    }
    return item;
}
void   SLinkedList::append(SNode* p){ // add a to end of list
    if(head == NULL){
        head = p;
    }
    if(tail != NULL){
        tail->next = p;
    }
    tail = p;
    tail->next = NULL;
}
void   SLinkedList::printAll(SNode* p){
    while(p){
        std::cout << p->value;
        if(p = p->next) std::cout << ", ";
    }
    std:: cout << "\n";
}

/* Getters / Setters */

SNode* SLinkedList::getTail(){return tail;}
SNode* SLinkedList::setTail(SNode* p){tail = p;}
SNode* SLinkedList::getHead(){return head;}
SNode* SLinkedList::setHead(SNode* p){head = p;}
