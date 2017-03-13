/* File: SavingsAccount.h
 * Name: Paulo Lemus
 * Date: 2/8/2017
 */

#ifndef SAVINGSACCOUNT_H_
#define SAVINGSACCOUNT_H_

class SavingsAccount{

    // Private variables
    BasicAccount ba;
    int withdrawals;

public:
    /* Constructors
     *
     * All constructors init balance->0 and accountNum->-1, as indication it hasn't been asssigned.
     * There are two copy constructors, for copying either a basic or savings account info.
     */
    SavingsAccount();
    SavingsAccount(long int accountNum, std::string name, float balance);
    SavingsAccount(const BasicAccount& ba);
    SavingsAccount(const SavingsAccount& ba);


    // Getters - standard stuff
    long int getAccountNum() const;
    std::string getName() const;
    float getBalance() const;

    // Setters - standard stuff
    void setAccountNum(long int accountNum);
    void setName(std::string name);
    void setBalance(float balance);
    
    /* Operator Overloads
     *
     * These overloads actually use the overloads from BasicAccount.
     * For example, "=" first uses BasicAccount overload to copy sa.ba to this->ba,
     * then it copies sa.withdrawals to this->withdrawals
     */
    void operator=(const SavingsAccount& sa);
    bool operator==(const SavingsAccount& sa);
    friend std::ostream& operator<<(std::ostream& output, const SavingsAccount& sa);

    /* Withdraw
     *
     * This function also takes care of removing $3 if user withdrew more than
     * 2 times. This will allow the balance to become negative.
     * However, user will never be able to withdraw more than they have.
     */
    float withdraw(float amount);

    /* Deposit
     *
     * This just calls BasicAccount deposit.
     * It will only allow users to deposit a positive 
     * amount of money.
     * It does nothing for negative numbers and 0.
     */
    void deposit(float amount);

    /* Monthly Check
     *
     * Calling this simply checks if balance is under 100.
     * If it is, it removes $10. This can cause balance to 
     * become negative.
     */
    void monthlyCheck();
};

#endif
