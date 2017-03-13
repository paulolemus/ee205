/* File: swappointersvalues.cpp
 * Name: Paulo Lemus
 * Date: 1/31/2017
 */

/* A program that swaps the values of two integers by reference.
 * Currently finished.
 */

#include <iostream>
using namespace std;

void swapPointerValues(int* a, int* b);

int main(){

    int a, b;
    
    cout << "Enter two integers" << endl;
    cin >> a >> b;
    cout << "\noriginal a: " << a << endl;
    cout << "original b: " << b << endl;

    swapPointerValues(&a, &b);
    
    cout << "\na: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}

void swapPointerValues(int* a, int* b){

    /* a function that takes in two pointers
     * and swaps the values the pointers point to
     */

    int temp;       // used to hold one of the pointer values
    
    temp = *a;      // saves *a in temp
    *a = *b;        // swaps *b to *a
    *b = temp;      // gives *b to *a

}
