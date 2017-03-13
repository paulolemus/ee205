/* File: swapvalues.cpp
 * Name: Paulo Lemus
 * Date: 1/31/2017
 */

/* A program to demonstrate that you cannot swap by value
 * using a function because you are swaping copies,
 * not the actual variables passed into the function.
 *
 * *FINISHED
 */

#include <iostream>
using namespace std;

void swapValues(int a, int b);

int main(){

    int a, b;
    cout << "Enter values for a and b: ";
    cin >> a >> b;
    cout << "\nOriginal a: " << a << endl;
    cout << "Original b: " << b << endl;

    swapValues(a, b);       // Pass by value

    cout << "New a: " << a << endl;
    cout << "New b: " << b << endl;

    cout << "\nThe values of original and new are the same because the swapped items in the swap function were passed by value not reference." << endl;

    return 0;
}

void swapValues(int a, int b){

    int temp;
    temp = a;
    a = b;
    b = temp;

    cout << "Function a: " << a << endl;
    cout << "Function b: " << b << endl;
}
