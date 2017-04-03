#include <iostream>

int ackerman(int m, int n);

int main() {

    int m, n;
    int result;

    std::cout << "Enter a value for m: ";
    std::cin >> m;
    std::cout << "Enter a value for n: ";
    std::cin >> n;
    
    
    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||\n";
    std::cout << "Beginning initial A(" << m << ", " << n << ") call:\n";
    result = ackerman(m, n);
    std::cout << "ACKERMAN FINAL RESULT = " << result << "\n\n";

    return 0;
}

int ackerman(int m, int n) {
    if( m == 0) {
        std::cout << "m = " << m << ", n = " << n << ", returning n + 1\n";
        return n + 1;
    }
    else if( m > 0 && n == 0) {
        std::cout << "m = " << m << ", n = " << n << ", ";
        std::cout << "Calling A(" << m - 1 << ", 1)\n";
        return ackerman(m - 1, 1);
    }
    else if( m > 0 && n > 0) {
        std::cout << "m = " << m << ", n = " << n << ", ";
        std::cout << "Calling A(" << m - 1 << ", A(" << m << ", " << n << "-1) )\n";
        return ackerman( m - 1, ackerman( m, n-1 ) );
    }
}
