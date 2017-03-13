/* File: swappointers.cpp
 * Name: Paulo Lemus
 * Date: 1/31/2017
 */

/* A function that takes in two pointers, and swaps the pointers.
 * This means that one pointer points to what the other pointer points to.
 *
 * * FINISHED
 */

#include <iostream>
using namespace std;

void swapPointers(int*& a, int*& b);


int main(){

    int a;
    int b;

    int* aptr = &a;
    int* bptr = &b;
    
    cout << "Enter two integers to swap: ";
    cin >> a >> b;
    cout << "\nOriginal a: " << *aptr << endl;
    cout << "Original b: " << *bptr << endl;

    // pass in pointers to a and b, swap pointers
    swapPointers(aptr, bptr);

    cout << "New a: " << *aptr << endl;
    cout << "New b: " << *bptr << endl;

    return 0;
}

/* This function swaps the addresses that two pointers are pointing to.
 * The pointers are passed into the function by reference.
 */
void swapPointers(int*& a, int*& b){

    int* temp = a;
    a = b;
    b = temp;
}
