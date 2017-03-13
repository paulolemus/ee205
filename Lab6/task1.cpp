/* File: task1.cpp
 * Name: Paulo Lemus
 * Date: 2/16/2017
 */

/* Task 1 is to demonstrate the usage of the STL vector.
 * In this file I will demonstrate usage of a vector of ints, 
 * as well as a vector of vectors.
 *
 * Status: FINISHED
 */

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(const vector<T>& v);

int main(){

    vector<int> v1;
    vector<int> v2(4);
    vector<vector<int>> vv;

    // Task 1, create vector with values 10, 20, 30, 40
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    printVector(v1);

    // Create a "matrix" of values
    for(int i = 1; i <= 10; i++){
        vector<int> temp;
        for(int j = 1; j <= 10; j++) temp.push_back(i * j);
        vv.push_back(temp);
    }

    // Print entire "matrix"
    for(int i = 0; i < vv.size(); i++){
        printVector(vv[i]);
    }
    return 0;
}

template <typename T>
void printVector(const vector<T>& v){
    for(int i = 0; i < v.size(); i++){
        cout << "Index " << i << ": " << v[i] << endl;
    }
    cout << endl;
}
