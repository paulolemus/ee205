/* File: SavingsAccount.h
 * Name: Paulo Lemus
 * Date: 3/19/2017
 */

#ifndef EE_HW10_SAVINGSACCOUNT_H_
#define EE_HW10_SAVINGSACCOUNT_H_

#include "BasicAccount.h"
#include <iostream>
#include <string>

///////////////////////////////////
//        DECLARATIONS           //
///////////////////////////////////


class SavingsAccount : public BasicAccount {

    // private variables
    int withdrawals;

public:
    // Constructors
    SavingsAccount();
    SavingsAccount(long int id, std::string name, float balance);
    SavingsAccount(const BasicAccount& ba);
    SavingsAccount(const SavingsAccount& sa);

    int getWithdrawals() const;

    void         operator=  (const SavingsAccount& sa);
    bool         operator== (const SavingsAccount& sa);
    virtual bool operator== (const BasicAccount& ba);
    friend std::ostream& operator<< (std::ostream& out, const SavingsAccount& sa);

    virtual bool withdraw(double amount);

    void monthlyCheck();
};

//////////////////////////////////
//        IMPLEMENTATIONS       //
//////////////////////////////////

SavingsAccount::SavingsAccount() : 
    BasicAccount(), 
    withdrawals(0) {}

SavingsAccount::SavingsAccount(long int id, std::string name, float balance) : 
    BasicAccount(id, name, balance), 
    withdrawals(0) {}

SavingsAccount::SavingsAccount(const BasicAccount& ba) :
    BasicAccount(ba),
    withdrawals(0) {}

SavingsAccount::SavingsAccount(const SavingsAccount& sa) :
    BasicAccount(sa),
    withdrawals(0) {}

int SavingsAccount::getWithdrawals() const { return withdrawals; }

void SavingsAccount::operator= (const SavingsAccount& sa) {
    id          = sa.id;
    name        = sa.name;
    balance     = sa.balance;
    withdrawals = sa.withdrawals;
}

bool SavingsAccount::operator== (const SavingsAccount& sa) {
    return (id          == sa.id      &&
            name        == sa.name    &&
            balance     == sa.balance &&
            withdrawals == sa.withdrawals);
}

bool SavingsAccount::operator== (const BasicAccount& ba) {
    return false;
}

std::ostream& operator<< (std::ostream& out, const SavingsAccount& sa) {
    out << "ID:\t\t"        << sa.id          << std::endl;
    out << "Name:\t\t"      << sa.name        << std::endl;
    out << "Balance:\t"     << sa.balance     << std::endl;
    out << "Withdrawals:\t" << sa.withdrawals << std::endl;
}

bool SavingsAccount::withdraw(double amount) {
    if(amount  <  0 ||
       balance <= 0 ||
       amount > balance) return false;

    balance -= amount;
    withdrawals++;
    if(withdrawals > 2) balance -= 3.0;
    return true;
}

void SavingsAccount::monthlyCheck() {
    if(balance < 100) balance -= 10;
}


#endif
