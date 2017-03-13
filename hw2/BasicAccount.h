/* File: BasicAccount.h
 * Name: Paulo Lemus
 * Date: 2/2/2017
 */

#ifndef HW2_BASICACCOUNT_H_
#define HW2_BASICACCOUNT_H_
#include <string>


class BasicAccount{

    // Private variables
    long int accountNum;
    std::string name;
    float balance;

public:
    /* Constructors:
     *
     * default, pass individual, and copy
     */
    BasicAccount();
    BasicAccount(long int accountNum, std::string name, float balance);
    BasicAccount(const BasicAccount& ba);
    
    // Getters
    long int getAccountNum() const;
    std::string getName() const;
    float getBalance() const;

    // Setters
    void setAccountNum(long int accountNum);
    void setName(std::string name);
    void setBalance(float balance);

    /* Operator Overloads
     *
     * = - assign the contents of one ba to another ba
     * == - compare each private variable.
     * << - Print each private variable.
     * NOTE: I am considering "<<" to be pretty print.
     */
    void operator=(const BasicAccount& ba);
    bool operator==(const BasicAccount& ba);
    bool operator!=(const BasicAccount& ba);
    friend std::ostream& operator<<(std::ostream &output, const BasicAccount& ba);

    /* Withdraw Function 
     * This function will return the money requested
     * UNLESS there is not enough money to do so. Then
     * it will return 0.
     */
    float withdraw(float amount);

    /* Deposit Function
     * This function will deposit the money entered.
     */
    void deposit(float amount);
};

#endif
