/* File: primes.cpp
 * Name: Paulo Lemus
 * Date: 1/26/2017
 */

/* This program will promp user for input, and then find all primes between 
 * 2 and n.
 *
 * USE SIEVE OF ERATOSTHENES
 * * FINISHED
 */


#include <cmath>
#include <iostream>
using namespace std;

// Function that ensures the input is valid
void getInput(int* n){

    cout << "\n\nThis program will find all the primes between 2 and n, inclusive.\n";
    
    do{
        cout << "\nEnter n: ";
        cin >> *n;

        cin.clear();
        cin.ignore(100, '\n');
    } while(cin.fail() || *n < 2);
}

// Function that sets all primes from 2 to n
void setPrimes(bool* list, int maxNum){

    // set all values to true
    for(int i = 0; i < maxNum-1; i++) list[i] = true;


    int bound = (int)ceil(sqrt(maxNum));

    // Main loop to set primes
    for(int i = 2; i <= bound; i++){
        if(list[i-2]){
            for(int j = i*i; j <= maxNum; j += i){
                list[j-2] = false;
            }
        }
    }
}

// Function to print all the prime indices on the list
void printPrimes(bool* list, int maxNum){

    cout << "\nList of primes from 2 to " << maxNum << ":\n\n";
    
    for(int i = 0; i < maxNum-1; i++){
        if(list[i]){
            cout << i + 2 << endl;
        }
    }
}


int main(){

    int maxNum;                  // number to calculate primes up to
    bool* list;                  // trues will be primes while false is not prime.

    getInput(&maxNum);           // Get a valid input from user

    try{
        list = new bool[maxNum-1];   // Init list to correct size
    }
    catch(...){
        cout << "Caught an error: memory allocation. Exiting" << endl;
        exit(1);
    }

    setPrimes(list, maxNum);     // Sets all prime indices to true, others to false
    printPrimes(list, maxNum);   // Just loops through and prints the true indices
    

    delete[] list;
    return 0;
}
