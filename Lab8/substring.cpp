/* File: substring.cpp
 * Name: Paulo Lemus
 * Date: 3/2/2017
 */

/* This is a program that will find all occurences
 * in another string. The index of the staring index
 * will be printed, as well as the number of times the
 * substring has been found in the superstring.
 *
 * Status: FINISHED
 */

#include <iostream>
#include <vector>
#include <string>

/* Searches super for sub, returns indices from super
 * where there are matches
 */
std::vector<int> findSubstring(const std::string& super, 
                               const std::string& sub);

/* Gets user input, returns false if user entered EOF */
bool getUserInput(std::string& super, std::string& sub);

/* Simply takes a list of indices and prints them */
template <typename T>
void printResults(const std::vector<T>& index);

/* Test cases, can be found below */
void testCases();


int main(){

    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "Welcome to the sub-string searcher!\n\n";
    std::cout << "This program will search for a string within another, and";
    std::cout << " return each index at which the sub-string was found.\n\n";

    testCases();

    while(true){
        std::string superString;
        std::string subString;
        std::vector<int> index;
        int count;

        if(!getUserInput(superString, subString)) {
            std::cout << "\nGoodbye!\n\n";
            return 0;
        }

        index = findSubstring(superString, subString);
        printResults(index);
    }
    return 0;
}

/* findSubstring:
 * 1. Return null list if super is greater than sub (0 matches)
 * 2. Check each index of the super if it matches the first char from sub.
 * 3. If there is a match, then grab the substring from super the same
 *    size as the sub string.
 * 4. Compare sub and this super-partition. If equal, save the index.
 * 5. Return list of indices.
 */
std::vector<int> findSubstring(const std::string& super, 
                               const std::string& sub){
    std::vector<int> index;

    if(super.size() < sub.size()) return index;

    std::string partStr;
    for(int i = 0; i < super.size() - sub.size() + 1; ++i){
       if(super[i] == sub[0]){
           partStr = super.substr(i, sub.size());
           if(partStr == sub) index.push_back(i);
       }
    }
    return index;
}

/* getUserInput:
 * 1. Save a line from stdin to string.
 * 2. If user entered Ctrl-D (EOF), return false. 
 *    Otherwisee return true.
 * 3. Repeat 1 and 2.
 */
bool getUserInput(std::string& super, std::string& sub){

    std::cout << "\nEnter a string to search from: ";
    std::getline(std::cin, super);
    if(std::cin.eof()) {std::cout << std::endl; return false;}
    std::cout << "Enter a string to search for: ";
    std::getline(std::cin, sub);
    if(std::cin.eof()) {std::cout << std::endl; return false;}
    return true;
}

/* printResults:
 * 1. Verify that the list has a size. If 0, print so.
 * 2. If there were any indices found:
 *    Iterate through the list printing each element.
 */
template <typename T>
void printResults(const std::vector<T>& index){

    int count = index.size();
    if(count == 0){
        std::cout << "\nI found no matching string.\n";
    } else{
        std::cout << "I found " << count << " matches.\n";
        std::cout << "Indices: ";

        for(int i = 0; i < index.size(); i++){
            std::cout << index[i] << " ";
        }
        std::cout << std::endl;
    }
}

void testCases(){
    
    std::string super1 = "abababa";
    std::string sub1   = "aba";
    std::string super2 = "same-sized-test";
    std::string sub2   = "same-sized-test";
    std::string super3 = "this testcase is a very good test for testing tests";
    std::string sub3   = "test";

    std::cout << "TESTCASES BEGIN:" << std::endl;
    std::cout << super1 << std::endl;
    std::cout << sub1   << std::endl;
    printResults(findSubstring(super1, sub1));
    std::cout << std::endl;
    std::cout << super2 << std::endl;
    std::cout << sub2   << std::endl;
    printResults(findSubstring(super2, sub2));
    std::cout << std::endl;
    std::cout << super3 << std::endl;
    std::cout << sub3   << std::endl;
    printResults(findSubstring(super3, sub3));
    std::cout << "TESTCASES END" << std::endl;
}


