
/* File: bankwithlist.cpp
 * Name: Paulo L, Jessie G, Matthew Y
 * Date: 02/24/17
 * Team: Sandwich
 */

#include <iostream>
#include <string>
#include "BasicAccount.h"
#include "singlylinked.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

/* This functions adds an account to the list sorted by ID. */
template <typename T>
SNode<T>* addNewAccount(SLinkedList<T>& list, BasicAccount& ba);
/* Return a pointer to a node with the matching id or name */
template <typename T>
SNode<T>* searchById(SLinkedList<T>& list, long int id);
template <typename T>
SNode<T>* searchByName(SLinkedList<T>& list, string name);
/* Add or remove money from a BasicAccount in the given node */
template <typename T>
void depositOrWithdraw(SNode<T>* ptr);

/* Case functions */
template <typename T>
void caseAddCustomer(SLinkedList<T>& list);
template <typename T>
void caseDeleteCustomer(SLinkedList<T>& list);
template <typename T>
SNode<T>* caseFindCustomer(SLinkedList<T>& list);
void printGUI();

int main(){

    // Class to manage linkedList data structure
    SLinkedList<BasicAccount> list;

    // Initial test cases
    BasicAccount ba1(11123, "Bob", 1034.55);
    BasicAccount ba2(11124, "Charlie", 500);
    BasicAccount ba3(11122, "Alice", 20000);
    addNewAccount(list, ba1);
    addNewAccount(list, ba2);
    addNewAccount(list, ba3);

    /* Main while loop that handles user input and selects
     * the appropriate function to call via a switch statement.
     */
    while(true){
        int choice;
        char c;
        SNode<BasicAccount>* acctPtr = NULL;

        // Clean introduction
        printGUI();
        cin >> choice;

        switch(choice){
            case 1:
                caseAddCustomer(list);
                break;
            case 2:
                acctPtr = caseFindCustomer(list);
                if(acctPtr != NULL) depositOrWithdraw(acctPtr);
                break;
            case 3:
                caseDeleteCustomer(list);
                break;
            case 4:
                cout << endl;
                list.printAll();
                break;
            case 5:
                cout << "\n\nGoodbye!\n\n";
                return 0;
        }
        // Input error guards
        if(cin.fail()) cout << "\nAn invalid command was entered\n";
        cout << "\nPress Enter to continue";
        cin.clear();
        while((c = cin.get()) != '\n' && c != EOF); // One to clear current input
        while((c = cin.get()) != '\n' && c != EOF); // One to wait for enter
    }
    return 0;
}


/* User interface */
void printGUI(){

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\tWelcome to Sandwich Banking Services.\n\n";
    cout << "What operation would you like to perform?\n";
    cout << "1 - Add new Account\n";
    cout << "2 - Find an existing customer\n";
    cout << "3 - Delete an existing customer\n";
    cout << "4 - Print all bank account information\n";
    cout << "5 - Burn everything and shutdown\n";
}


/* Add a new account to the list. This first checks
 * if the account is available by ID.
 * If it is, it adds it, otherwise it indicates the
 * account id is taken.
 */
template <typename T>
void caseAddCustomer(SLinkedList<T>& list){

    long int id;
    string   name;
    float    balance;
    SNode<BasicAccount>* ptr;

    cout << "\nTo create a new account, provide the following:\n";
    cout << "Account id\t: ";
    cin >> id;
    cout << "Account name\t: ";
    cin >> name;
    cout << "Account balance\t: ";
    cin >>balance;
    if(cin.fail()) return;
    BasicAccount ba(id, name, balance);
    ptr = addNewAccount(list, ba);
    if(ptr == NULL){
        cout << "\nFailed to add account. ID already exists.\n";
    }
    else{
        cout << "\nAccount successfully added.\n";
        cout << ptr->data;
    }
}


/* Delete an existing customer:
 * This block allows the user to first search
 * through the list of accounts using name or ID,
 * then displays the account information before
 * requesting confirmation if this is the account
 * to delete. If it is, it is deleted. Otherwise,
 * no action is taken.
 */
template <typename T>
void caseDeleteCustomer(SLinkedList<T>& list){

    string   confirm;
    string   nameOrId;
    string   searchStr;
    long int searchInt;
    SNode<BasicAccount>* ptr;

    cout << "\n\nWould you like to delete by id or name? ";
    cin >> nameOrId;

    // search by name or id, exit if there was any invalid input
    if(nameOrId == "id"){
        cout << "\nEnter id: ";
        cin >> searchInt;
        if(cin.fail()) return;
        ptr = searchById(list, searchInt);
    }
    else if(nameOrId == "name"){
        cout << "\nEnter name: ";
        cin >> searchStr;
        ptr = searchByName(list, searchStr);
    }
    else{
        cout << "\nInvalid command\n";
        return;
    }
    if(ptr == NULL){
        cout << "\nCould not locate account.\n";
        return;
    }
    // Account was found, procede and ask for confirmation
    cout << "Found account. Details below:\n\n";
    cout << ptr->data;
    cout << "\nAre you sure you want to delete the account? ";
    cin >> confirm;

    if(confirm[0] == 'y' || confirm[0] == 'Y'){
        list.erase(ptr);
        cout << "\nAccount deleted.\n\n";
    }
    else cout << "\nNo action taken.\n\n";
}


/* Find an existing account by name or ID.
 * This choice allows the user to select
 * the desired method of searching, then prompts
 * user to enter a name or id to searh by.
 * If a valid account is found, it also prompts user
 * if he/she would like to deposit or withdraw money.
 */
template <typename T>
SNode<T>* caseFindCustomer(SLinkedList<T>& list){

    string   nameOrId;
    string   searchStr;
    long int searchInt;
    SNode<BasicAccount>* ptr;

    cout << "\n\nWould you like to search by id or name? ";
    cin >> nameOrId;

    if(nameOrId == "id"){
        cout << "\nEnter id: ";
        cin >> searchInt;
        if(cin.fail()) return NULL;
        ptr = searchById(list, searchInt);
    }
    else if(nameOrId == "name"){
        cout << "\nEnter name: ";
        cin >> searchStr;
        ptr = searchByName(list, searchStr);
    }
    else{
        cout << "\nInvalid command\n";
        return NULL;
    }
    if(ptr == NULL){
        cout << "\nCould not locate account.\n";
        return NULL;
    }
    cout << "Found account. Details below:\n\n";
    cout << ptr->data;
    return ptr;
}


/* AddNewAccount:
 * This functions adds an account to the list
 * sorted by ID number. It searches for an id that
 * is greater than it, and inserts a new node before it.
 * If there are none or if list is empty, it appends the node.
 */
template <typename T>
SNode<T>* addNewAccount(SLinkedList<T>& list, BasicAccount& ba){
    SNode<T>* ptr = list.getHead();
    if(ptr == NULL){
        ptr = list.append(ba);
        return ptr;
    }
    while(ptr && ptr->data.getAccountNum() < ba.getAccountNum()){
        ptr = list.advance(ptr, 1);
    }
    if(ptr && ptr->data.getAccountNum() == ba.getAccountNum()) return NULL;
    if(ptr == NULL){
        ptr = list.append(ba);
        return ptr;
    }
    ptr = list.insert(ba, ptr);
    return ptr;
}


/* SearchById && SearchByName:
 * These functions operate very similarly.
 * They first check if the head is null.
 * Otherwise, they iterate through each node comparing
 * the given string or id to the node name or id.
 * If there is a match, a ptr to the node is returned.
 * Otherwise, NULL is returned.
 */
template <typename T>
SNode<T>* searchById(SLinkedList<T>& list, long int id){
    SNode<T>* ptr = list.getHead();
    while(ptr && ptr->data.getAccountNum() != id){
        ptr = list.advance(ptr, 1);
    }
    return ptr;
}
template <typename T>
SNode<T>* searchByName(SLinkedList<T>& list, string name){
    SNode<T>* ptr = list.getHead();
    while(ptr && ptr->data.getName() != name){
        ptr = list.advance(ptr, 1);
    }
    return ptr;
}


/* depositOrWithdraw:
 * Prompts user to withdraw or deposit money into an
 * account given via pointer to node.
 */
template <typename T>
void depositOrWithdraw(SNode<T>* ptr){
    int choice;
    float amount;

    cout << "\nWould you like to withdraw or deposit from this account?\n";
    cout << "1 - Withdraw\n";
    cout << "2 - Deposit\n";
    cout << "3 - Take no action\n";
    cin >> choice;

    if(choice == 1){
        int check;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        check = ptr->data.withdraw(amount);
        if(check == -1) cout << "Insufficient funds\n";
        else if(check == -2) cout << "An unknown error has occured\n";
        else{
            cout << "New balance: " << ptr->data.getBalance() << endl;
        }
    }
    else if(choice == 2){
        cout << "Enter amount to deposit: ";
        cin >> amount;
        ptr->data.deposit(amount);
        cout << "\nNew balance: " << ptr->data.getBalance() << endl;
    }
    else{
        cout << "\nNo action taken\n";
    }
}
