/* File: readline.cpp
 * Name: Paulo Lemus
 * Date: 2/15/2017
 */

/* This is a program that assigns grades on a curve.
 * This program takes in a file with multiple students, 
 * it them stores the rawSumGrade of each student in grades vector.
 * Using the raw final grade from each student, it calculates the average, 
 * standard deviation, and final grade for the class.
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

    ifstream file("multistudents.txt");
    string line;
    vector<float> grades;
    float average;          // The average of all the grades
    float stdDev;           // Standard deviation

    /* Read in a line, calculate its total grade, store in grades
     */
    while(getline(file, line)){
        float sum = 0;
        vector<float> studentGrades;
        istringstream iss(line);

        copy(istream_iterator<float>(iss), 
                istream_iterator<float>(), 
                back_inserter(studentGrades));
        for(int j = 0; j < studentGrades.size(); j++){
            sum += studentGrades[j];
        }
        grades.push_back(sum);
        cout << sum << endl;
    }
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


