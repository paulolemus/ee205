/* File: bank.cpp
 * Name: Paulo Lemus
 * Date: 3/19/2017
 */

/* This is a test program that will create
 * 3 Basic and 3 Savings accounts and test all
 * of their functionality. 
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include "BasicAccount.h"
#include "SavingsAccount.h"
using namespace std;


int main(){

    srand(time(NULL));
    long int id = rand() % 10000;

    vector<BasicAccount>   ba(3);
    vector<SavingsAccount> sa(3);

    cout << "INITIALIZATION" << endl;
    ba[0].setName("Alice");
    ba[1].setName("Bob");
    ba[2].setName("Charlie");
    ba[0].setBalance((double)(rand() % 5000));
    ba[1].setBalance((double)(rand() % 5000));
    ba[2].setBalance((double)(rand() % 5000));
    for(unsigned int i = 0; i < ba.size(); i++){
        ba[i].setId(id);
        cout << ba[i];
        id++;
    }
    sa[0].setName("Xing");
    sa[1].setName("Yi");
    sa[2].setName("Zed");
    sa[0].setBalance((double)(rand() % 5000));
    sa[1].setBalance((double)(rand() % 5000));
    sa[2].setBalance((double)(rand() % 5000));
    for(unsigned int i = 0; i < ba.size(); i++){
        sa[i].setId(id);
        cout << sa[i];
        id++;
    }


    // Test setters, withdraw, monthcheck
    ba[0].setBalance(200);
    sa[0].setBalance(200);
    ba[0].setName("SET/DRAW");
    sa[0].setName("SET/DRAW");
    ba[0].withdraw(100);
    ba[0].withdraw(33);
    sa[0].withdraw(90);
    sa[0].withdraw(10);
    sa[0].withdraw(10);
    sa[0].monthlyCheck();
    cout << "\nSET/WITHDR/MONTHCHK" << endl;
    cout << ba[0] << sa[0] << endl;

    // Test deposit
    ba[0].setBalance(100);
    sa[0].setBalance(100);
    ba[0].deposit(10);
    sa[0].deposit(200);
    cout << "\nDEPOSITCHECK" << endl;
    cout << ba[0] << sa[0];

    // Test Constructor
    BasicAccount ba1;
    BasicAccount ba2(99999, "BA2", 0.99);
    BasicAccount ba3(ba2);
    SavingsAccount sa1;
    SavingsAccount sa2(8888, "SA2", 1234);
    SavingsAccount sa3(ba3);
    SavingsAccount sa4(sa2);
    cout << "\nTEST CONSTRUCTORS" << endl;
    cout << ba1 << ba2 << ba3 << sa1 << sa2 << sa3 << sa4 << endl;

    // Test OP OVERLOADS
    cout << "\nOP OVERLOADS" << endl;
    ba1 = ba3;
    sa1 = sa4;
    if(ba1 == ba3) cout << "BASIC SUCCESS" << endl;
    else cout << "BASIC FAIL" << endl;
    if(sa1 == sa4) cout << "SAVING SUCCESS" << endl;
    else cout << "SAVING FAIL" << endl;



    return 0;
}
