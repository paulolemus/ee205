/* File: addlargenumbers.cpp
 * Name: Paulo Lemus
 * Date: 2/1/2017
 */

/* this program will allow the user to add two very large numbers that
 * are larger than that allowed from any primitive data type.
 * It can be considered a decimal version of a binary full adder.
 * 
 * Input: A large number provided by the user.
 * -Decide how many blocks we need to allocate and allocate the block array using malloc.
 * -Use try catch.
 *
 *  Algorithm:
 *  1. get user input for number 1.
 *  2. determine how many digits it has
 *  3. group them starting from front into 5 digit segments
 *  4. do the same with other number
 *  5. for each grouping, add them up and get the carry if any and proceed like this
 *  6. print them in order
 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* This function takes a number as a string and converts it into
 * an array of 5 digit long ints. It starts from the end and works towards
 * the start of the number.
 */
void parseBigNumber(const string& s_BigNum, int* bigNum, int numGroups, int numLength){

    for(int i = numGroups; i > 0; i--){
        string numPortion;
        numLength -= 5;

        if(numLength >= 0){
            numPortion = s_BigNum.substr(numLength, 5);
        }
        else{
            numLength += 5;
            numPortion = s_BigNum.substr(0, numLength);
        }
        bigNum[i-1] = stoi(numPortion);
    }
}

/* This function adds two large numbers and stores the result in an
 * array of ints. It adds them by index, starting from the last index of each iten
 * and moving towards index 0.
 */
void addBigNumbers(int* bigSum, int* bigNum1, int* bigNum2, int groupsSum, int groups1, int groups2){

    int limit = 100000; // If there are more than 5 digits, it over flows.
    int carry = 0;
    bool num1Valid = true;
    bool num2Valid = true;
    groups1--;
    groups2--;

    
    for(int i = groupsSum-1; i >= 0; i--){

        int value1 = 0;
        int value2 = 0;

        if(groups1 < 0) num1Valid = false;
        if(groups2 < 0) num2Valid = false;

        if(num1Valid) value1 = bigNum1[groups1];
        if(num2Valid) value2 = bigNum2[groups2];

        bigSum[i] = value1 + value2 + carry;
        
        if(bigSum[i] > limit && i != 0){
            bigSum[i] -= limit;
            carry = 1;
        }
        else{
            carry = 0;
        }

        groups1--;
        groups2--;
    }
}

/* Function used to print big numbers in the correct format.
 * You may try to print a number manually, but if there are any
 * consecutive 0's in the number, they may be removed due to how
 * they are stored as ints.
 *
 * Ex: 00011 = 11
 */
void printBigNumber(int* bigNum, int numGroups){
    
    for(int i = 0; i < numGroups; i++){
        
        int value = bigNum[i];

        if(i != 0){
            if     (value < 10)    cout << "0000";
            else if(value < 100)   cout << "000";
            else if(value < 1000)  cout << "00";
            else if(value < 10000) cout << "0";
        }
        
        cout << bigNum[i];
    }
}


int main(){

    int numLength1;         // the number of digits in the number
    int numLength2;
    int numGroups1;         // the number of indices the array requires
    int numGroups2;
    int numGroupsSum;
    string s_BigNum1;       // the big number saved as a string
    string s_BigNum2;
    int* bigNum1;           // the arrays used to hold large numbers
    int* bigNum2;
    int* bigSum;

    // get user input and save as string.
    cout << "\nEnter your first Big Number:" << endl;
    cin >> s_BigNum1;
    cout << "\nEnter second Big Number:" << endl;
    cin >> s_BigNum2;

    // save the number of characters in each string number
    numLength1 = s_BigNum1.length();
    numLength2 = s_BigNum2.length();

    // Calculate the number of indices each string will need 
    // in its array
    numGroups1 = ceil((float)numLength1 / 5.0f);
    numGroups2 = ceil((float)numLength2 / 5.0f);

    // Calculate the number of indices the sum will need,
    // Also allocate space for each number
    numGroupsSum = numGroups1 > numGroups2 ? numGroups1 : numGroups2;
    bigNum1 = new int[numGroups1];
    bigNum2 = new int[numGroups2];
    bigSum  = new int[numGroupsSum];

    // Converts each string into an array of ints
    // representing the number.
    parseBigNumber(s_BigNum1, bigNum1, numGroups1, numLength1);
    parseBigNumber(s_BigNum2, bigNum2, numGroups2, numLength2);

    // Adds two big numbers using their array forms, saves to int array
    addBigNumbers(bigSum, bigNum1, bigNum2, numGroupsSum, numGroups1, numGroups2); 
    
    // Print big numbers in form:
    // num1 + num2 = sum
    cout << endl;
    printBigNumber(bigNum1, numGroups1);
    cout << " + ";
    printBigNumber(bigNum2, numGroups2);
    cout << "\n=\n";
    printBigNumber(bigSum, numGroupsSum);
    cout << endl;

    delete[] bigNum1;
    delete[] bigNum2;
    delete[] bigSum;

    return 0;
}


