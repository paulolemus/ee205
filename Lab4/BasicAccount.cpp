/* File: BasicAccount.cpp
 * Name: Paulo Lemus
 * Date: 2/2/2017
 */

/* The cpp file for BasicAccount class. It has a main for testing.
 */

#include <iostream>
#include <string>
#include "BasicAccount.h"

// Constructors
BasicAccount::BasicAccount(){
    balance = 0;
    accountNum = -1;
}
BasicAccount::BasicAccount(long int accountNum, std::string name, float balance){
    this->accountNum = accountNum;
    this->balance    = balance;
    this->name       = name;
}
BasicAccount::BasicAccount(const BasicAccount& ba){
    this->accountNum = ba.accountNum;
    this->balance    = ba.balance;
    this->name       = ba.name;
}


// Getters
long int    BasicAccount::getAccountNum() const {return accountNum;};
std::string BasicAccount::getName() const {return name;}
float       BasicAccount::getBalance() const {return balance;}


// Setters
void BasicAccount::setAccountNum(long int accountNum){
    this->accountNum = accountNum;
}
void BasicAccount::setName(std::string name){
    this->name = name;
}
void BasicAccount::setBalance(float balance){
    this->balance = balance;
}


// Withdraw and Deposit
float BasicAccount::withdraw(float amount){
    if(balance > 0 && balance > 0 && amount > 0 && balance >= amount){
        balance -= amount;
        return amount;
    }
    else if(balance < amount){
        return -1;
    }
    else return -2;
}
void BasicAccount::deposit(float amount){
    if(amount > 0){
        balance += amount;
    }
}

// Operator overloads
void BasicAccount::operator=(const BasicAccount& ba){
    this->accountNum = ba.accountNum;
    this->name = ba.name;
    this->balance = ba.balance;
}

bool BasicAccount::operator==(const BasicAccount& ba){
    if(this->accountNum == ba.accountNum &&
       this->name       == ba.name &&
       this->balance    == ba.balance){
        return true;
    }
    else return false;
}

std::ostream& operator<<(std::ostream &output, const BasicAccount& ba){
    output << "Account Number:\t" << ba.accountNum << std::endl;
    output << "Name:\t\t" << ba.name << std::endl;
    output << "Balance:\t" << ba.balance << std::endl;
    return output;
}

/* Test Driver
 *
int main(){

    long int accountNum = 100;
    std::string name    = "TOMMY";
    float balance       = 435.45f;

    BasicAccount ba1;
    BasicAccount ba2(accountNum, name, balance);
    BasicAccount ba3(ba2);
    ba1.setName("TEST NAME 1");
    ba2.setName("Test ane 2");
    ba2.setBalance(5001.4f);

    std::cout << "ba1 balance: " << ba1.getBalance() << std::endl;
    std::cout << "ba2 balance: " << ba2.getBalance() << std::endl;
    std::cout << "ba3 balance: " << ba3.getBalance() << std::endl;
    std::cout << "ba1 name: "    << ba1.getName() << std::endl;
    std::cout << "ba2 name: "    << ba2.getName() << std::endl;
    std::cout << "ba3 name: "    << ba3.getName() << std::endl;

    std::cout << std::endl;
    std::cout << ba1;
    std::cout << ba2;
    std::cout << ba3;

    ba1 = ba3;
    std::cout << ba1;

    if(ba1 == ba3) std::cout << "WORKS!"  << std::endl;
    else           std::cout << "FAILED!" << std::endl;

    if(ba1 == ba2) std::cout << "ba1 and 2 are equal?" << std::endl;
    else           std::cout << "ba1 and 2 are NOT EQUAL!" << std::endl;

    ba2.withdraw(4000);
    std::cout << ba2;

    return 0;
}
*/
