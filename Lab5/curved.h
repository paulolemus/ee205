/* File: curved.h
 * Name: Paulo Lemus
 * Date: 2/15/2017
 */

#ifndef EE_CURVED_H_
#define EE_CURVED_H_

// function that, given an array, will return the array's average
float calcAverage(std::vector<float>& v);

// Function that takes in an array and average and calculated the standard deviation to return
float stdDeviation(std::vector<float>& v, float average);

// Function that prints all grades on curve using stdDeviation and standard
void printGrades(std::vector<float>& v, float average, float stdDev);
#endif
