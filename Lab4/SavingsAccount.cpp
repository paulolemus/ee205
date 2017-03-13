/* File: SavingsAccount.cpp
 * Name: Paulo Lemus
 * Date: 2/8/2017
 */

#include <iostream>
#include <string>
#include "BasicAccount.h"
#include "SavingsAccount.h"


/* Constructors
*/
SavingsAccount::SavingsAccount() : ba(){
    withdrawals = 0;
}
SavingsAccount::SavingsAccount(long int accountNum, std::string name, float balance) : ba(accountNum, name, balance){
    withdrawals = 0;
}
SavingsAccount::SavingsAccount(const BasicAccount& ba) : ba(ba){
    withdrawals = 0;
}
SavingsAccount::SavingsAccount(const SavingsAccount& sa) : ba(sa.ba) {
    this->withdrawals = sa.withdrawals;
}


// Getters
long int    SavingsAccount::getAccountNum() const{return ba.getAccountNum();}
std::string SavingsAccount::getName() const{return ba.getName();}
float       SavingsAccount::getBalance() const{return ba.getBalance();}

// Setters
void SavingsAccount::setAccountNum(long int accountNum){
    ba.setAccountNum(accountNum);    
}
void SavingsAccount::setName(std::string name){
    ba.setName(name);
}
void SavingsAccount::setBalance(float balance){
    ba.setBalance(balance);
}

// Operator Overloads
void SavingsAccount::operator=(const SavingsAccount& sa){
    this->ba = sa.ba;
    this->withdrawals = sa.withdrawals;
}
bool SavingsAccount::operator==(const SavingsAccount& sa){
    if(this->ba == sa.ba && this->withdrawals == sa.withdrawals){
        return true;
    }
    else return false;
}
std::ostream& operator<<(std::ostream& output, const SavingsAccount& sa){
    output << sa.ba;
    output << "Withdrawals:\t" << sa.withdrawals << std::endl;
    return output;
}

// Withdraw
float SavingsAccount::withdraw(float amount){
    int valid = ba.withdraw(amount);
    if(valid >= 0) withdrawals++;
    if(withdrawals > 2) ba.setBalance(ba.getBalance() - 3);
    return valid;
}

// Deposit
void SavingsAccount::deposit(float amount){
    ba.deposit(amount);
}

// Monthly check
void SavingsAccount::monthlyCheck(){
    if(ba.getBalance() < 100){
        ba.setBalance(ba.getBalance() - 10);
    }
}

/*Test driver
 *
int main(){

    long int id = 12345;
    std::string name = "RICH";
    float balance = 500;

    // Confirm that BasicAccount still works.
    BasicAccount ba1;
    BasicAccount ba2(id, name, balance);
    ba1.setName("ZOE");
    std::cout << ba1 << std:: endl << ba2;

    // Test SavingsAccount class
    SavingsAccount sa1;
    SavingsAccount sa2(ba2);    // SA should have same info as ba2
    SavingsAccount sa3(9876, "TOM", 1000);

    std::cout << sa1 << std::endl << sa2 << std::endl << sa3;

    // Test withdraw and deposit
    sa3.withdraw(100);
    sa3.deposit(1000);
    std::cout << sa3;

    // Test op overload
    sa3.setName("EQUAL SUCCESS");
    sa1 = sa3;
    sa1.withdraw(40);
    std::cout << sa1;

    // Test charges
    std::cout << std::endl << std::endl;
    SavingsAccount sa4(10000, "CHARGES", 200);
    std::cout << sa4 << std::endl;
    sa4.withdraw(50);
    std::cout << sa4 << std::endl;
    sa4.withdraw(50);
    std::cout << sa4 << std::endl;
    sa4.withdraw(50);
    std::cout << sa4 << std::endl;
    sa4.monthlyCheck();
    std::cout << sa4 << std::endl;

    return 0;
}
*/
