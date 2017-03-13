/* EE 205 Lab 2
 *
 * Name: Paulo Lemus
 * File: Bank.cpp
 * Date: 1/19/2017
 *
 * Create a bank account struct with account number, name, balance.
 * Create 3 basic account customers: alice, bob, charlie. 
 * Store them in an aarray of structs
 *
 */

#include <cstdlib>
#include <iostream>
#include <ctime>        // for time()
#include <limits>      // for numeric_limits
#include <cstring>
#include <string>

#include <map>

#define BASIC_MAX   3
#define SAVINGS_MAX 3
using namespace std;

struct BankAccount{
    public:
        // Setters
        void setAccountNumber(long int accountNumber){
            this->accountNumber = accountNumber;
        }
        void setName(char name[]){
            strcpy(this->name, name);
        }
        void setBalance(float balance){
            this->balance = balance;
        }
        void setPin(int pin){
            this->pin = pin;
        }
        void addBalance(float addition){
            balance += addition;
        }
        void checkBounds(){};
        // Getters
        long int getAccountNumber(){
            return this->accountNumber;
        }
        string getName(){
            return string(this->name);
        }
        float getBalance(){
            return this->balance;
        }
        // Print functions
        void printName(){
            cout << "\nName:           " << this->name << endl;
        }
        void printAccountNumber(){
            cout << "\nAccount Number: " << this->accountNumber << endl;
        }
        void printBalance(){
            cout << "\nBalance:        " << this->balance << endl;
        }

    protected:
        long int accountNumber;
        int pin;
        char name[37];
        float balance;
};

struct BasicAccount : public BankAccount{
    public:
         
    private:
        
};

struct SavingsAccount : public BankAccount{
    public:
        SavingsAccount(){
            withdrawals = 0;
        }
        void initAccount(long int number, char name[], float balance){
            setAccountNumber(number);
            setName(name);
            setBalance(balance);
        }

        void addBalance(float addition){
            balance += addition;
            withdrawals++;
        }

        void checkBounds(){
            if(withdrawals > 2) balance -= 3;
            if(balance < 100) balance -= 10;
            if(balance < 0) balance = 0;
        }

    private:
        int withdrawals;

};

void depositMoney(BankAccount* ba){
    float value;
    cout << "Enter amount to deposit: ";
    cin >> value;

    ba->addBalance(value);
    ba->checkBounds();
    ba->printBalance();
    cout << "Press ENTER to finish";

    cin.clear();
    cin.ignore(10000, '\n');
    getchar();
}

void withdrawMoney(BankAccount* ba){
    float value;
    //get value and verify here
    cout << "Enter amount to draw: ";
    cin >> value;
    
    ba->addBalance(value);
    ba->checkBounds();
    ba->printBalance();

    cin.clear();
    cin.ignore(10000, '\n');
    getchar();
}

void initBasicAccounts(BasicAccount* ba){
    for(int i = 0; i < BASIC_MAX; i++, ba++){
        char name[37];
        float balance;
        int newAccountNumber = rand();

        cout << "\nSetting account number: " << newAccountNumber << endl;
        cout << "Enter name:             ";
        cin >> name;
        cout << "Enter balance:         $";
        cin >> balance;

        ba->setName(name);
        ba->setAccountNumber(newAccountNumber);
        ba->setBalance(balance);

        cout << "\n\n---------------------------------------------------------------" << endl;
        cout << "--------            SUMMARY              ----------------------" << endl;
        ba->printAccountNumber();
        ba->printName();
        ba->printBalance();
        cout << "---------------------------------------------------------------\n\n";
    }
}


// Global variable for the endlessly incrementing account numbers
int newAccountNumber;

int main(){

    srand(time(NULL));
    newAccountNumber = rand();
    
    BasicAccount   basicAccounts[BASIC_MAX];
    SavingsAccount savingsAccounts[SAVINGS_MAX];
   
   initBasicAccounts(basicAccounts);
   /*
    // Initialize Basic accounts
    for(int i = 0; i < BASIC_MAX; i++){
        // Variables used to assign name and balance
        char name[37];
        float balance;
        
        cout << "\nSetting account number: " << newAccountNumber << endl;
        cout << "Enter name:             ";
        cin >> name;
        cout << "Enter balance:         $";
        cin >> balance;

        basicAccounts[i].setName(name);
        basicAccounts[i].setAccountNumber(newAccountNumber);
        basicAccounts[i].setBalance(balance);
        newAccountNumber++;

        cout << "\n\n---------------------------------------------------------------" << endl;
        cout << "--------            SUMMARY              ----------------------" << endl;
        basicAccounts[i].printAccountNumber();
        basicAccounts[i].printName();
        basicAccounts[i].printBalance();
        cout << "---------------------------------------------------------------\n\n";
    }
    */
    cout << "INITIALIZE SAVINGS ACCOUNTS\n" << endl;
    cin.clear();
    cin.ignore(10000, '\n');

    // initialize savings accounts
    for(int i = 0; i < SAVINGS_MAX; i++){
        char name[37];
        float balance;

        cout << "Setting account number: " << newAccountNumber << endl;
        cout << "Enter name:             ";
        cin >> name;
        cout << "Enter balance:         $";
        cin >> balance;

        savingsAccounts[i].initAccount(newAccountNumber, name, balance);
        newAccountNumber++;

        cout << "\n\n-------------------------------------------------------------" << endl;
        cout << "--------           SUMMARY              -------------------------" << endl;
        savingsAccounts[i].printAccountNumber();
        savingsAccounts[i].printName();
        savingsAccounts[i].printBalance();
        cout << "-----------------------------------------------------------------\n\n";
    }

    cout << "Press ENTER to continue..." << endl;
    cin.clear();
    cin.ignore(10000, '\n');
    getchar();

    /* Loop waiting for input.
     * User can:
     *
     * Withdraw money
     * Deposit money
     * Shut down bank with a secret code
     */

    enum Options {DEFAULT, DEPOSIT, WITHDRAW, EXIT};
    map<string, Options> enumMap;
    enumMap["d"]        = DEPOSIT;
    enumMap["w"]        = WITHDRAW;
    enumMap["password"] = EXIT;
    
    bool running = true;
    while(running){
        
        cin.clear();
        cin.ignore(10000, '\n');

        string userChoice;
        Options option;

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "                   ################" << endl;
        cout << "                   #     MENU     #" << endl;
        cout << "                   ################" << endl;
        cout << "        (w)ithdraw                 (d)eposit" << endl;
        cout << " \n\n\n\n\n\n\n";

        cin >> userChoice;
        try{
            option = enumMap[userChoice];
        } catch(const exception& e){
            option = DEFAULT;
            cout << "ENTERED THE CATCH BLOCK";
        }

        BankAccount* baptr;

        switch(option){
            case DEPOSIT:
                // FUNCTION TO DEPOSIT
                baptr = &basicAccounts[1];
                //bankAccount = findAccount(basicAccounts, savingsAccounts);
                depositMoney(baptr);
                break;
            case WITHDRAW:
                // FUNCTION TO WITHDRAW
                baptr = &savingsAccounts[0];
                //bankAccount = findAccount(basicAccounts, savingsAccounts);
                withdrawMoney(baptr);
                break;
            case EXIT:
                running = false;
                break;
            case DEFAULT:
                cout << "Invalid selection, press ENTER to try again";
                getchar();
                break;
            default:
                cout << "Invalid selection, press ENTER to try again";
                getchar();
                break;
        }
    
    }


    return 0;
}
