/* File: singlylinked.h
 * Name: Paulo Lemus
 * Date: 2/19/2017
 * Mod : 3/3/2017
 */

#ifndef EE_SINGLYLINKED_H_
#define EE_SINGLYLINKED_H_

#include <iostream>
// using namespace std;
/* This file contains code for a singly linked list.
*/

/////////////////////////////////////////////////////
///             CLASS DECLARATIONS                ///
/////////////////////////////////////////////////////

template <typename T>
struct SNode{
    T         data;
    SNode<T>* next;

    SNode(const T& data, SNode<T>* next = NULL);
    //friend std::ostream& operator<<(std::ostream& output, const SNode<T>* p);
};

template <typename T>
class SLinkedList{
    SNode<T>* head;
    SNode<T>* tail;

    public:
    SLinkedList();
    SNode<T>* insert(const T& data, SNode<T>* p); // insert acc before p, return acc*
    SNode<T>* add(const T& data, SNode<T>* p);    // add acc after p, return n pointer
    SNode<T>* erase(SNode<T>* p);                 // erase using given ptr
    SNode<T>* erase(const T& data);               // erase by data
    SNode<T>* find(const T& data, SNode<T>* p);   // from p to null, return node with s
    SNode<T>* find(const T& data);                // seach whole list for s
    SNode<T>* advance(SNode<T>* p, int n);        // return node n ahead of p in list
    SNode<T>* append(const T& data);              // add a to end of list
    void      printAll(SNode<T>* p);
    void      printAll();

    SNode<T>* getTail();
    SNode<T>* setTail(SNode<T>* p);
    SNode<T>* getHead();
    SNode<T>* setHead(SNode<T>* p);

};

/////////////////////////////////////////////////////
///              FUNC DEFINITIONS                 ///
/////////////////////////////////////////////////////

// Constructor
template <typename T>
SNode<T>::SNode(const T& data, SNode<T>* next):data(data), next(next){}

/* << Overload
 * Used in printing out a node's data using a pointer to data.
 *
template <typename T>
std::ostream& operator<<(std::ostream& out, const SNode<T>* p){
    out << p->value;
    return out;
}
*/

// Constructor
template <typename T>
SLinkedList<T>::SLinkedList(){
    head = NULL;
    tail = NULL;
}
/* Insert:
 * This function first checks two cases, nullptr and head.
 * If neither, then it iterates through list until it finds
 * p, or the list ends.
 * If it finds p, it inserts a new node before it. Otherwise,
 * function returns NULL.
 */
template <typename T>
SNode<T>* SLinkedList<T>::insert(const T& data, SNode<T>* p){
    SNode<T>* previous = NULL;
    SNode<T>* current  = head;

    if(p == head){
        SNode<T>* node = new SNode<T>(data);
        node->next = head;
        head       = node;
        return node;
    }
    while(current && current != p){
        previous = current;
        current = current->next;
    }
    if(current == NULL) return NULL;
    SNode<T>* node = new SNode<T>(data);
    previous->next = node;
    node->next = current;
    return node;
}

/* Add:
 * Add new node with data after p, return pointer to node
 * First, guard against null ptr. Otherwise,
 * Check the next node. If it is null, p->next = new node.
 * Otherwise, add the new node between p and after.
 */
template <typename T>
SNode<T>* SLinkedList<T>::add(const T& data, SNode<T>* p){
    if(!p) return NULL;
    SNode<T>* after = p->next;

    SNode<T>* node = new SNode<T>(data);
    if(after == NULL){
        p->next = node;
        return node;
    }
    p->next = node;
    node->next = after;
    return node;
}

/* Erase:
 * Erase using a ptr given to the node to erase
 *
 * 1. Search for the node provided via pointer.
 *    Save a pointer to the previous node.
 * 2. When the node is found, we use the previous node's
 *    pointer to point across the node to delete.
 * 3. Delete the given node.

 * 4. Return a pointer to the previous node.
 */
template <typename T>
SNode<T>* SLinkedList<T>::erase(SNode<T>* p){
    SNode<T>* prev = NULL;
    SNode<T>* curr = head;
    while(curr && curr != p){
        prev = curr;
        curr = curr->next;
    }
    if(curr == head){
        head = head->next;
        delete p;
        return head;
    }
    if(curr == tail){
        tail = prev;
        tail->next = NULL;
        delete p;
        return tail;
    }
    prev->next = curr->next;
    delete p;
    return prev;
}
template <typename T>
SNode<T>* SLinkedList<T>::erase(const T& data){
    SNode<T>* prev = NULL;
    SNode<T>* curr = head;
    while(curr && curr->data != data){
        prev = curr;
        curr = curr->next;
    }
    if(curr == head){
        head = head->next;
        delete curr;
        return head;
    }
    if(curr == tail){
        tail = prev;
        tail->next = NULL;
        delete curr;
        return tail;
    }
    prev->next = curr->next;
    delete curr;
    return prev;
}

/* Find:
 * from p to null, return node with data
 * Search through list, comparing each node's
 * data with the data given to the function.
 * If there is a match, return the pointer to the 
 * node, otherwise return null.
 */
template <typename T>
SNode<T>* SLinkedList<T>::find(const T& data, SNode<T>* p){
    while(p != NULL && p->data != data){
        p = p->next;
    }
    return p;
}
template <typename T>
SNode<T>* SLinkedList<T>::find(const T& data){
    SNode<T>* p = head;
    while(p != NULL && p->data != data){
        p = p->next;
    }
    return p;
}


/* Advance:
 * Return ptr to node n links ahead of p
 * If p is null or if there arent n links,
 * return null. Otherwise return valid ptr.
 */
template <typename T>
SNode<T>* SLinkedList<T>::advance(SNode<T>* p, int n){
    if(!p) return NULL;
    for(int i = 0; i < n; i++){
        p = p->next;
        if(!p) return NULL;
    }
    return p;
}

/* Append:
 * This adds a new node to the end of the list
 * 1. Check headcase, simply make a new node as head.
 * 2. If the node after head is null, make the next the
 *    new node and set it equal to the tail.
 * 3. If the tail is not null, make a new node after the
 *    tail and point the tail to it.
 */
template <typename T>
SNode<T>* SLinkedList<T>::append(const T& data){
    SNode<T>* node = new SNode<T>(data);
    if(head == NULL){
        head = node;
        return node;
    }
    if(head->next == NULL){
        head->next = node;
        tail = node;
        return node;
    }
    if(tail != NULL) tail->next = node;
    tail = node;
    return node;
}

/* PrintAll:
 * Simply prints the data from each node,
 * starting from given or head.
 */
template <typename T>
void SLinkedList<T>::printAll(SNode<T>* p){
    if(p == NULL) std::cout << "Nothing to print!" << std::endl;
    while(p != NULL){
        std::cout << p->data << std::endl;
        p = p->next;
    }
}
template <typename T>
void SLinkedList<T>::printAll(){
    SNode<T>* p = head;
    if(p == NULL) std::cout << "Nothing to print!" << std::endl;
    while(p != NULL){
        std::cout << p->data << std::endl;
        p = p->next;
    }
}
/* Getters / Setters */
template <typename T>
SNode<T>* SLinkedList<T>::getTail(){return tail;}
template <typename T>
SNode<T>* SLinkedList<T>::setTail(SNode<T>* p){this->tail = p; return tail;}
template <typename T>
SNode<T>* SLinkedList<T>::getHead(){ return head;}
template <typename T>
SNode<T>* SLinkedList<T>::setHead(SNode<T>* p){this->head = p; return head;}

#endif
