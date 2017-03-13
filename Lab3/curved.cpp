/* File: curved.cpp
 * Name: Paulo Lemus
 * Date: 1/26/2017
 */

/* This is a program that assigns grades on a curve.
 * This program will ask how many numbers they want to read in.
 * This program will read in an array of scores using cin
 * 
 * *FINISHED
 */

#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

float calcAverage(float* array, int size){
    // Take in an array and pass back the average of array
    float average = 0;
    for(int i = 0; i < size; i++){
        average += array[i];
    }
    average = (float)average / (float)size;
    return average;
}

// Function that takes in an array and average and calculated the standard deviation to return
float stdDeviation(float* array, int arraySize, float average){
    float stdDev = 0;

    for(int i = 0; i < arraySize; i++){
        float temp = array[i] - average;
        temp = temp * temp;
        stdDev += temp;
    }
    stdDev = stdDev / (float)arraySize;
    stdDev = sqrt(stdDev);
    return stdDev;
}

// Function that prints all grades on curve using stdDeviation and standard
void printGrades(float* array, int arraySize, float average, float stdDev){

    for(int i = 0; i < arraySize; i++){
        char letterGrade;

        if(array[i] < average - 1.5f * stdDev) letterGrade = 'F';
        else if(array[i] >= average - 1.5f * stdDev && array[i] < average - 0.5f * stdDev) letterGrade = 'D';
        else if(array[i] >= average - 0.5f * stdDev && array[i] < average + 0.5f * stdDev) letterGrade = 'C';
        else if(array[i] >= average + 0.5f * stdDev && array[i] < average + 1.5f * stdDev) letterGrade = 'B';
        else if(array[i] >= average + 1.5f * stdDev) letterGrade = 'A';
        

        cout << "Index " << i << ": " << "Grade " << array[i] << " = " << letterGrade << endl;
    }

}

int main(){

    int arraySize;          // the number of grades to hold
    float* gradeArray;      // the array of grades inputted
    float tempGrade;        // to hold temporary values
    float average;          // The average of all the grades
    float stdDev;           // Standard deviation

    cout << "Enter the number of grades: ";
    cin >> arraySize;
    gradeArray = new float[arraySize];
    


    // Get all the grades in from cin
    try{
        cout << "\n\nEnter the grades in order, separated by spaces\n\n";
        for(int i = 0; i < arraySize; i++){
            cin >> tempGrade;
            gradeArray[i] = tempGrade;
        }
    }
    catch(...){ // int& e
        cout << "\n\nFailed to init gradeArray\n\n";
        exit(1);
    }


    // calculate the average
    average = calcAverage(gradeArray, arraySize);
    cout << "\naverage: " << average << endl;

    // calculate standard deviation
    stdDev = stdDeviation(gradeArray, arraySize, average);
    cout << "Standard Deviation: " << stdDev << "\n\n";

    printGrades(gradeArray, arraySize, average, stdDev);


    delete[] gradeArray;
    return 0;
}


