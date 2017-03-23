/* File: Company.h
 * Name: Paulo Lemus
 * Date: 3/23/2017
 */

/* This is a file that you can use for simple testing of the class functions. */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"
#include "Admin.h"
#include "Management.h"
#include "Sales.h"
#include "Factory.h"
#include "Technical.h"

// Used only to create initial sample employees
void populate(std::vector<Employee*>& employees, long int nextId);

int main() {
    // Used to get initial employee ID number
    srand( time(NULL) );
    long int nextId = rand() % 500;

    std::vector<Employee*> employees;

    populate(employees, nextId);


    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "Welcome to Poodle's poorly funded payroll experience." << std::endl;
    std::cout << "This program will allow you to update an employee's payroll information.\n";
    std::cout << "You can then calculate the amount to pay each employee.\n" << std::endl;

    bool running = true;
    while( running ) {

        char select;
        std::cout << "l: display info for all employees" << std::endl;
        std::cout << "i: find and update employee by ID" << std::endl;
        std::cout << "u: Update all employees payroll information" << std::endl;
        std::cout << "c: Calculate the monthly salary for each employee" << std::endl;
        std::cout << "q: Sell the company at daily garage sale" << std::endl;
        std::cout << ">> ";

        std::cin >> select;
        std::cout << std::endl;
        while(std::cin.get() != '\n');

        long int idSelect;
        switch(select) {

            // Simply prints the basic information for each employee
            case 'l':
                for(unsigned int i = 0; i < employees.size(); ++i) {
                    employees[i]->printInfo();
                    std::cout << std::endl;
                }
                break;

            // Searches for any employees with same ID, allows you to edit their payroll. 
            case 'i':
                std::cout << "Enter id number. Make sure its a number or I'll break.";
                std::cout << "\n>> ";
                while( !(std::cin >> idSelect) ) {
                    std::cout << "Enter a valid ID.\n>> ";
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                }
                for(unsigned int i = 0; i < employees.size(); ++i) {
                    if(employees[i]->getId() == idSelect) {
                        employees[i]->printInfo();
                        employees[i]->update();
                    }
                }
                std::cout << std::endl;
                break;

            // Updates ALL employee payrolls. You want to do this before calculating 
            // monthly salary.
            case 'u':
                for(unsigned int i = 0; i < employees.size(); ++i) {
                    std::cout << "Now Editing: " << std::endl;
                    employees[i]->printInfo();
                    employees[i]->update();
                    std::cout << std::endl;
                }
                std::cout << std::endl;
                break;

            // Calculate the monthly salary for each employee taking into account
            // any bonuses or commission they have earned for the month
            case 'c':
                for(unsigned int i = 0; i < employees.size(); ++i) {
                    std::cout << "Employee " << employees[i]->getId();
                    std::cout << ": $" << employees[i]->monthlySalary() << std::endl;
                }
                std::cout << std::endl;
                break;

            // Quit the program
            case 'q':
                running = false;
                break;
            default:
                while(std::cin.get() != '\n');
                break;
        }
    } // while

    std::cout << "\nPoodle INC. sold at garage sale for $23." << std::endl;
    return 0;
}

/* Just populates the vector with each kind of employee */
void populate(std::vector<Employee*>& employees, long int nextId) {

    Employee* emp = new Admin(nextId, 
            "Admin dude",
            "Rain Rd",
            "808-111-1234",
            "John@poodle.io",
            "Sandwich Development",
            "Sandwich Artisan",
            120000);
    employees.push_back(emp);
    nextId++;

    emp = new Factory(nextId,
            "Factory dude",
            "6969 Square Street",
            "808-345-5678",
            "Franku@poodle.io",
            "Water Crafters",
            "Water Crafts-it (gender neutral)",
            10,
            0);
    employees.push_back(emp);
    nextId++;

    emp = new Management(nextId,
            "Manage bro",
            "6969 Circle Street",
            "808-345-5679",
            "Pepe@poodle.io",
            "Bossmen",
            "Da Boss",
            200000,
            10500);
    employees.push_back(emp);
    nextId++;


    emp = new Technical(nextId,
            "Tech gurl",
            "6969 Parabola Street",
            "808-123-3456",
            "TeamMisty@poodle.io",
            "Government Hackers",
            "HackerGirl (tm)",
            150000,
            13);
    employees.push_back(emp);
    nextId++;


    emp = new Sales(nextId,
            "Retail guy",
            "6969 Reuleaux Triangle Street",
            "808-956-8883",
            "AlwaysBelieve@poodle.io",
            "Sales",
            "Butcher",
            13000,
            300);
    employees.push_back(emp);
    nextId++;
}





