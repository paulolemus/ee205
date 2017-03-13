/*
 * EE 205 Lab 2
 *
 * File: task1.cpp
 * Name: Paulo Lemus
 * Date: 1/18/2017
 *
 * Learn the size of various data types.
 */

#include <iostream>
using namespace std;

struct Empty{
};

struct Base{
    int a;
};

struct Derived : public Base{
    int b;
};

struct Bit{
    unsigned bit : 1;
};


int main(){

    Empty e;
    Derived d;
    Bit bit;
    Base& b = d;

    int      i1 = 0x12345678;
    int      i2 = -1;
    char      c = 'a';
    float     f = 22.625;
    double   db = 1.2;
    const int N = 10;
    int a[N];

    // TODO: CODE TO INITIALIZE a[]
    for(int i = 0; i < N; i++){
        a[i] = i1;
    }
    
    int*    p1 = &i1;
    int*    p2 = &i2;
    float*  p3 = &f;
    double* p4 = &db;
    char*   p5 = &c;

    cout << "Datatype \t size in bytes\n";
    cout << "___________________________\n";
    cout << "integer \t\t\t" << sizeof(int) << endl;

    // FILL CODE TO FIND SIZE OF ALL OTHER PRIMITIVE DATA TYPES
    cout << "float  \t\t\t\t" << sizeof(float)  << endl;
    cout << "double \t\t\t\t" << sizeof(double) << endl;
    cout << "char   \t\t\t\t" << sizeof(char)   << endl;

    cout << "array of 10 int\t\t\t" << sizeof(int[10]) << endl;
    cout << "array of 10 int(2)\t\t" << sizeof(a) << endl;
    cout << "length of array of 10 int\t" << (sizeof(a) / sizeof(*a)) << endl;
    cout << "length of array of 10 int (2)\t" << (sizeof(a) / sizeof(a[0])) << endl;
    cout << "pointer \t\t\t" << sizeof(&e) << endl;

    cout << "size of function: " << "void() is not a function, it is a type, and it means nothing is returned" << endl;
    cout << "size of incomplete type: " << "the size of an array depends on how many units are allocated, int[] hasn't been given a length" << endl;
    cout << "Size of bit field: " << "Bitfields are not supported by sizeof. Use a macro to tell" << endl; // sizeof(bit.bit)

    cout << "Empty class \t\t\t" << sizeof(e) << endl;
    cout << "Derived \t\t\t" << sizeof(d) << endl;
    cout << "Derived through Base \t\t" << sizeof(b) << endl;

    return 0;
}

