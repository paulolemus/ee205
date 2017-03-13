/* File: readfromfile.cpp
 * Name: Paulo Lemus
 * Date: 2/15/2017
 */

/* This is a program that assigns grades on a curve.
 * It reads a single line from file and calculates the average, 
 * standard deviation, and final grade for the course.
 * 
 * *FINISHED
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include "curved.h"
using namespace std;

int main(){

    ifstream file("onestudent.txt");
    string line;
    vector<float> grades;
    float tempGrade;        // to hold temporary values
    float average;          // The average of all the grades
    float stdDev;           // Standard deviation

    // Read one line from text and store in grades
    getline(file, line);
    istringstream iss(line);
    copy(istream_iterator<float>(iss), 
         istream_iterator<float>(), 
         back_inserter(grades));
    file.close();

    // calculate average/stdDev
    average = calcAverage(grades);
    stdDev = stdDeviation(grades, average);

    // clean print
    cout << "Average: " << average << endl;
    cout << "stdDev: " << stdDev << endl;
    printGrades(grades, average, stdDev);
    return 0;
}


