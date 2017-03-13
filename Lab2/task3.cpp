/* EE 205 Lab 2
 * 
 * File: task3.cpp
 * Name: Paulo Lemus
 * Date: 1/18/2017
 *
 * Find out the numberic limitations of your system.
 */

#include <iostream>
#include <climits>
using namespace std;

int main(){

    int n;
    n = 2;

    for(int i = 1; i < 20; i++){
        cout << n << endl;
        n *= 10;
    }
    cout << "\n\n";
    n = INT_MAX - 3;
    cout << "max int is: " << INT_MAX << endl;

    for(int i = 0; i < 10; i++){
        cout << n << endl;
        n++;
    }

    cout << "If you pass the limit for a type, it will overflow.\nThat is why it suddenly becomes negative after passing the limit, due to the way numbers are added and stored" << endl;

    return 0;
}
