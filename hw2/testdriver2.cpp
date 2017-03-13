/* File: testdriver2.cpp
 * Name: Paulo Lemus
 * Date: 2/24/2017
 */

/* A test driver that attempts to use a list
 * of BankAccounts.
 *
 * Expected Outcome:
 * It will print the information from two BasicAccounts:
 * 1. ID: 500, Name: Alice, Balance: 400
 * 2. ID: 10000, Name: Tom, Balance: 0
 *
 * Next it will print the same list, however Tom's
 * balance will be 1234.
 *
 * Did output match expectations? Yes
 */

#include <iostream>
#include "singlylinked.h"
#include "BasicAccount.h"
using std::cin;
using std::cout;
using std::endl;

int main(){

    SLinkedList<BasicAccount> list;

    BasicAccount ba0;
    ba0.setAccountNum(500);
    ba0.setName("Alice");
    ba0.setBalance(400);
    BasicAccount ba1;
    ba1.setAccountNum(10000);
    ba1.setName("Tom");
    
    list.append(ba0);
    list.append(ba1);

    list.printAll();

    /* Here is an example of how to use the find
     * function and how to use it to interact with
     * a bankAccount in the list.
     * Kind of dumb right now, I know.
     */
    list.find(ba1)->data.setBalance(1234);
    list.printAll();

    cout << "Success!" << endl;
    return 0;
}
