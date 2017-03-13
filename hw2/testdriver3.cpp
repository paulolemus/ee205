/* File: testdriver3.cpp
 * Name: Jessie G
 * Date: 2/24/2017
 */

/* Test case:
 * Output exactly matches expectations.
 */

#include <iostream>
#include "singlylinked.h"
#include "BasicAccount.h"
using std::cin;
using std::cout;
using std::endl;


int main(){

    SLinkedList<BasicAccount> list; //creates a list of type BasicAccount

    BasicAccount ba0; //constructs a basic acct class ba0
    ba0.setAccountNum(500);
    ba0.setName("Alice");
    ba0.setBalance(400);

    BasicAccount ba1; 
    ba1.setAccountNum(10000);
    ba1.setName("Tom");
    ba1.setBalance(1234);
    
    BasicAccount ba2; 
    ba2.setAccountNum(15000);
    ba2.setName("Jerry");
    ba2.setBalance(888);
    
    BasicAccount ba3; 
    ba3.setAccountNum(20000);
    ba3.setName("Bob");
    ba3.setBalance(999);
    
    list.append(ba0);
    list.append(ba1);
    list.append(ba2);
    list.append(ba3);

    cout << "-----printing all after appending all" << endl; 
    list.printAll();

    // list.find(ba1)->data.setBalance(1234);
    float a = list.find(ba1)->data.getAccountNum();
    float b = list.find(ba1)->data.getBalance();
    cout << "--ba1's account is: "<< a << endl; 
    cout << "--ba1's balance is: "<< b << endl; 
    cout << "----printing from ba2"<< endl; 
    list.printAll(list.find(ba2));


    cout << "----erasing ba0 and printing all" << endl;
    list.erase(ba0);
    list.printAll();

    cout << "Success!" << endl;
    return 0;
}
