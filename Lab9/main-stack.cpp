/*
 *
 *
 */

#include <iostream>
#include "stack-array.h"

int main(){

    EE::stack<int> stk(5);

    std::cout << stk.capacity() << std::endl;
    std::cout << stk.size()     << std::endl;

    return 0;
}
