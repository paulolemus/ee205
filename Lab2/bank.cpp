/* File: main.cpp
 * Name: Paulo Lemus
 * Date: 1/25/2017
 */

/* This is a bank account program. This will create 3 bank accounts
 * and 3 savings accounts and initialize them. It will also allow users to
 * withdraw and/or deposit money.
 */

#include <cstring>
#include <cassert>
#include <iostream>
#include "BankAccount.h"

#define BASIC_MAX   3
#define SAVINGS_MAX 3

using namespace std;


int main(){

    // Seed and initialize the random number to start the IDs
    srand(time(NULL));
    int newId = rand();

    // Create objects on heap
    BankAccount* alice   = new BankAccount;
    BankAccount* bob     = new BankAccount;
    BankAccount* charlie = new BankAccount;
    
    SavingsBankAccount* xing     = new SavingsBankAccount;
    SavingsBankAccount* yu       = new SavingsBankAccount;
    SavingsBankAccount* ziggypop = new SavingsBankAccount;
    
    // Initialize id, name, and balance for all 6 accounts
    alice->id   = newId++;
    bob->id     = newId++;
    charlie->id = newId++;
   
    strcpy(alice->name, "Alice");
    strcpy(bob->name, "Bob");
    strcpy(charlie->name, "Charlie");

    alice->balance   = 100;
    bob->balance     = 160;
    charlie->balance = 35600.50;

    SBA_set_id(xing, newId++);
    SBA_set_id(yu, newId++);
    SBA_set_id(ziggypop, newId++);

    SBA_set_name(xing, "Xing");
    SBA_set_name(yu, "Yu");
    SBA_set_name(ziggypop, "ZiggyPop");

    SBA_set_balance(xing, 500);
    SBA_set_balance(yu, 1000);
    SBA_set_balance(ziggypop, 105.43);

    // Assert some values to ensure that functions are working correctly
    assert(bob->id == (alice->id + 1));
    assert(SBA_get_id(xing) + 1 == SBA_get_id(yu));
    assert(SBA_get_balance(xing) == 500);

    // make use of withdraw and deposit
    BA_withdraw_money(alice, 10);
    BA_deposit_money(bob, 20);
    SBA_withdraw_money(xing, 450);
    SBA_deposit_money(yu, 100);

    // More tests to check previous functions
    assert(alice->balance == 90);
    assert(bob->balance   == 180);
    assert(SBA_get_balance(xing) == 40);
    assert(SBA_get_balance(yu)   == 1100);

    // Last set of functions and test
    SBA_withdraw_money(xing, 1);
    SBA_withdraw_money(xing, 1);
    assert(SBA_get_balance(xing) == 15);

    return 0;
}
