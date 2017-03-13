/* File: swapreferences.cpp
 * Name: Paulo Lemus
 * Date: 2/1/2017
 */

/* A program that passes two ints by reference to a swap function.
 * * FINISHED
 */

#include <iostream>
using namespace std;

/* This function swaps the references for two ints.
 * The values for each int should be in the same memory location,
 * however the references are swapped so printing a prints whatever was at
 * b's memory location and vice versa
 */
void swapByReference(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;
}

int main(){

    int a;
    int b;

    cout << "Enter a value for a and b: ";
    cin >> a >> b;
    cout << "\nOriginal a: " << a << endl;
    cout << "Original b: " << b << endl;

    swapByReference(a, b);

    cout << "New a: " << a << endl;
    cout << "New b: " << b << endl;
    
    return 0;
}
