#ifndef BANKACCOUNT_H       // Check if header was already included
#define BANKACCOUNT_H

struct BankAccount{
    long int id;
    char     name[37];
    float    balance;
};

// Functions to alter BA state
void BA_withdraw_money(struct BankAccount* ptr, int amount);
void BA_deposit_money(struct BankAccount* ptr, int amount);


struct SavingsBankAccount{
    BankAccount bankAccount;
    int         withdrawals;
};

// Functions to alter SBA state
void SBA_withdraw_money(struct SavingsBankAccount*  ptr, int amount);
void SBA_deposit_money(struct SavingsBankAccount* ptr, int amount);
void SBA_set_balance(struct SavingsBankAccount* ptr, float amount);
void SBA_set_name(struct SavingsBankAccount* ptr, const char* string);
void SBA_set_id(struct SavingsBankAccount* ptr, int number);

// Functions that do not alter SBA state
long int SBA_get_id(struct SavingsBankAccount* ptr);
const char* SBA_get_name(struct SavingsBankAccount* ptr);
float SBA_get_balance(struct SavingsBankAccount* ptr);

#endif // BANKACCOUNT_H
