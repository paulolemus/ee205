/* File: curved.cpp
 * Name: Paulo Lemus
 * Date: 2/15/2017
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "curved.h"


float calcAverage(std::vector<float>& v){
    // Take in an array and pass back the average of array
    float average = 0;
    for(int i = 0; i < v.size(); i++){
        average += v[i];
    }
    average = (float)average / (float)v.size();
    return average;
}

// Function that takes in an array and average and calculated the standard deviation to return
float stdDeviation(std::vector<float>& v, float average){
    float stdDev = 0;

    for(int i = 0; i < v.size(); i++){
        float temp = v[i] - average;
        temp = temp * temp;
        stdDev += temp;
    }
    stdDev = stdDev / (float)v.size();
    stdDev = sqrt(stdDev);
    return stdDev;
}

// Function that prints all grades on curve using stdDeviation and standard
void printGrades(std::vector<float>& v, float average, float stdDev){

    for(int i = 0; i < v.size(); i++){
        char letterGrade;

        if(v[i] < average - 1.5f * stdDev) letterGrade = 'F';
        else if(v[i] >= average - 1.5f * stdDev && v[i] < average - 0.5f * stdDev) letterGrade = 'D';
        else if(v[i] >= average - 0.5f * stdDev && v[i] < average + 0.5f * stdDev) letterGrade = 'C';
        else if(v[i] >= average + 0.5f * stdDev && v[i] < average + 1.5f * stdDev) letterGrade = 'B';
        else if(v[i] >= average + 1.5f * stdDev) letterGrade = 'A';
        

        std::cout << "Index " << i << ": " << "Grade " << v[i] << " = " << letterGrade << std::endl;
    }

}
