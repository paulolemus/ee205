/* File: BasicAccount.h
 * Name: Paulo Lemus
 * Date: 3/19/2017
 */

#ifndef EE_LAB10_BASICACCOUNT_H_
#define EE_LAB10_BASICACCOUNT_H_

#include <iostream>
#include <string>

/////////////////////////////////
//        DECLARATIONS         //
/////////////////////////////////

class BasicAccount {

protected:    
    long int id;
    std::string name;
    double balance;

public:
    // Constructors
    //      -- basic, individual copy, copy
    BasicAccount();
    BasicAccount(long int id, std::string name, double balance);
    BasicAccount(const BasicAccount& ba);

    // Getters
    long int    getId()      const;
    std::string getName()    const;
    double      getBalance() const;

    // Setters
    void setId(long int id);
    void setName(std::string name);
    void setBalance(double balance);

    // Overloads
    virtual void operator=  (const BasicAccount& ba);
    virtual bool operator== (const BasicAccount& ba);
    friend std::ostream& operator<< (std::ostream& out, const BasicAccount& ba);

    /* Withdraw Function
     * This function will return true if the amount was
     * successfully withdrew. Otherwise, it throws error
     * or returns false;
     */
    virtual bool withdraw(double amount);

    /* Deposit Function
     * This function deposits the entered amount into this account.
     * It returns true if the deposit was successful. 0 Otherwise.
     */
    virtual bool deposit(double amount);
};


/////////////////////////////////
//       IMPLEMENTATIONS       //
/////////////////////////////////

BasicAccount::BasicAccount() : 
    id(-1), 
    name(""), 
    balance(0) {}

BasicAccount::BasicAccount(
    long int id,
    std::string name, 
    double balance
    ) :
    id(id),
    name(name),
    balance(balance) {}

BasicAccount::BasicAccount(const BasicAccount& ba) :
    id( ba.getId() ),
    name( ba.getName() ),
    balance( ba.getBalance() ) {}

// Getters
long int    BasicAccount::getId() const { return id; }
std::string BasicAccount::getName() const { return name; }
double      BasicAccount::getBalance() const { return balance; }

// Setters
void BasicAccount::setId(long int id) { this->id = id; }
void BasicAccount::setName(std::string name) { this->name = name; }
void BasicAccount::setBalance(double balance) { this->balance = balance; }

// Operator overloads
void BasicAccount::operator= (const BasicAccount& ba) {
    this->id      = ba.id;
    this->name    = ba.name;
    this->balance = ba.balance;
}
bool BasicAccount::operator== (const BasicAccount& ba) {
    return (id      == ba.id   &&
            name    == ba.name &&
            balance == ba.balance);
}
std::ostream& operator<< (std::ostream& out, const BasicAccount& ba) {
    out << "ID:\t"      << ba.id      << std::endl;
    out << "Name:\t"    << ba.name    << std::endl;
    out << "Balance:\t" << ba.balance << std::endl;
}

// Withdraw
bool BasicAccount::withdraw(double amount) {
    if(amount  <  0 ||
       balance <= 0 ||
       amount > balance) return false;

    balance -= amount;
    return true;
}

// Deposit
bool BasicAccount::deposit(double amount) {
    if(amount >= 0) {
        balance += amount;
        return true;
    } else {
        return false;
    }
}


#endif
