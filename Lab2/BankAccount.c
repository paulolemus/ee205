#include "BankAccount.h"
#include <stdio.h>
#include <cstring>

/* All of the functions used to interact with the BankAccount and
 * SavingsBankAccount structs.
 * 
 * A question, If we have a class BankAccount, and we derive 
 * two classs from it, Savings and Checkings, can we use 
 * BankAccount* ptr to refer to BankAccount, Savings, and Checkings safely?
 */

// Functions that alter BA state
void BA_withdraw_money(struct BankAccount* ptr, int amount){
    ptr->balance = ptr->balance - amount;
    
    if(ptr->balance < 0){
        ptr->balance = 0;
        printf("\n Insufficient funds\n\n");
    }
}
void BA_deposit_money(struct BankAccount* ptr, int amount){
    ptr->balance = ptr->balance + amount;
}

// Functions that alter SBA state
void SBA_withdraw_money(struct SavingsBankAccount* ptr, int amount){
    ptr->bankAccount.balance -= amount;
    ptr->withdrawals++;
    if(ptr->withdrawals > 2) ptr->bankAccount.balance -= 3;
    if(ptr->bankAccount.balance < 100) ptr->bankAccount.balance -= 10;
}
void SBA_deposit_money(struct SavingsBankAccount* ptr, int amount){
    ptr->bankAccount.balance += amount;
}
void SBA_set_balance(struct SavingsBankAccount* ptr, float amount){
    ptr->bankAccount.balance = amount;
}
void SBA_set_name(struct SavingsBankAccount* ptr, const char* string){
    strcpy(ptr->bankAccount.name, string);
}
void SBA_set_id(struct SavingsBankAccount* ptr, int number){
    ptr->bankAccount.id = number;
}

// Functions that do not alter SBA state
long int SBA_get_id(struct SavingsBankAccount* ptr){
    return ptr->bankAccount.id;
}
const char* SBA_get_name(struct SavingsBankAccount* ptr){
    return ptr->bankAccount.name;
}
float SBA_get_balance(struct SavingsBankAccount* ptr){
    return ptr->bankAccount.balance;
}


