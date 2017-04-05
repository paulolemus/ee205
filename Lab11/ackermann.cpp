/* File: ackermann.cpp
 * Name: Paulo lemus
 * Date: 4/3/2017
 */

/* A program that calculates the output of the ackermann 
 * function. This program prints out the trace for the
 * function with the given input m and n.
 *
 * Status: Finished
 */

#include <iostream>

int ackermann(int m, int n);

int main() {

    int m, n;
    int result;

    // Getting user input
    std::cout << "Enter a value for m: ";
    std::cin >> m;
    std::cout << "Enter a value for n: ";
    std::cin >> n;
    
    // calculate and print the results of ackermann functions
    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||\n";
    std::cout << "Beginning initial A(" << m << ", " << n << ") call:\n";
    result = ackermann(m, n);
    std::cout << "ACKERMAN FINAL RESULT = " << result << "\n\n";

    return 0;
}

//           | n + 1                  if m = 0
// A(m, n) = { A(m - 1, 1)            if m > 0 and n = 0
//           | A(m - 1, A(m, n - 1))  if m > 0 and n > 0
int ackermann(int m, int n) {
    if( m == 0) {
        std::cout << "m = " << m << ", n = " << n << ", returning n + 1\n";
        return n + 1;
    }
    else if( m > 0 && n == 0) {
        std::cout << "m = " << m << ", n = " << n << ", ";
        std::cout << "Calling A(" << m - 1 << ", 1)\n";
        return ackermann(m - 1, 1);
    }
    else if( m > 0 && n > 0) {
        std::cout << "m = " << m << ", n = " << n << ", ";
        std::cout << "Calling A(" << m - 1 << ", A(" << m << ", " << n << "-1) )\n";
        return ackermann( m - 1, ackermann( m, n-1 ) );
    }
}
