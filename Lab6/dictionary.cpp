/* File: dictionary.cpp
 * Name: Paulo Lemus
 * Date: 2/21/2017
 */

/* A dictionary program that will ask a user to enter a number,
 * and then ask if the user wants to insert it or delete it.
 */


#include <iostream>
#include "singlylinked.h"
using namespace std;

void insert(SLinkedList& list, int value);
void remove(SLinkedList& list, int value);

int main(){

    SLinkedList list;
    int value  = -1;
    int choice = -1;

    cout << "Beginning dictionary program...\n\n";

    while(true){
        cout << "Enter an int: ";
        cin >> value;
        cout << "What would you like to do?" << endl;
        cout << "1-Insert, 2-Delete, 3-Print list, 0-Quit" << endl;
        cin >> choice;

        if(choice == 0) break;
        else if(choice == 1) insert(list, value);
        else if(choice == 2) remove(list, value);
        else if(choice == 3) list.printAll(list.getHead());
        else cout << "Invalid choice. Try again." << endl;
    }
    cout << "\nGoodbye!\n\n";
    return 0;
}


void insert(SLinkedList& list, int value){
    SNode* node = new SNode(value);
    SNode* curr = list.getHead();

    while(curr && curr->value < value) curr = list.advance(curr, 1);
    if(curr) list.insert(node, curr);
    else     list.append(node);
}

void remove(SLinkedList& list, int value){
    SNode* curr = list.find(list.getHead(), value);
    if(curr) list.erase(curr);
    else     cout << "Element not found." << endl;
}
