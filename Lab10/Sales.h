/* File: Sales.h
 * Name: Paulo Lemus
 * Date: 3/20/2017
 */

#ifndef EE_LAB10_SALES_H_
#define EE_LAB10_SALES_H_

#include <iostream>
#include <string>
#include "Employee.h"

/* Status: Finished */

class Sales : public Employee {

protected:
    double salary;
    double commission;

public:
    Sales(double salary);
    Sales(double salary, double commission);
    Sales(
        long int id,
        std::string name,
        std::string address,
        std::string phone,
        std::string email,
        std::string department,
        std::string title,
        double salary,
        double commission
        );

    void   setSalary(double salary);
    void   setCommission(double commission);
    double getSalary();
    double getCommission();

    virtual double monthlySalary();
    virtual void   update();
};

Sales::Sales(double salary) : salary(salary), commission(0.0) {}
Sales::Sales(double salary, double commission) :
    salary(salary), commission(commission) {}
Sales::Sales(
    long int id,
    std::string name,
    std::string address,
    std::string phone,
    std::string email,
    std::string department,
    std::string title,
    double salary,
    double commission
    ) :
    Employee(
        id,
        name, 
        address, 
        phone, 
        email, 
        department, 
        title
    ), 
    salary(salary),
    commission(commission) {}

void   Sales::setSalary(double salary)  { this->salary = salary; }
void   Sales::setCommission(double commission) { this->commission = commission; }
double Sales::getSalary()     { return salary; }
double Sales::getCommission() { return commission; }

double Sales::monthlySalary() { 
    double temp_commission = commission;
    commission = 0;
    return salary / 12 + temp_commission;
}
void   Sales::update() {
    
    std::string choice;

    std::cout << "Current salary: " << salary << std::endl;
    std::cout << "Would you like to change salary? ";

    std::cin >> choice;

    if(choice[0] == 'y' || choice [0] == 'Y') {
        
        std::cout << "Please enter a new salary: ";
        while( !(std::cin >> salary) || salary < 0 ) {
            std::cout << "Please enter a new salary: ";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        std::cout << "New salary: " << salary << std::endl;
        while(std::cin.get() != '\n');
    }

    std::cout << "Current commission is $" << commission << std::endl;
    std::cout << "Would you like to make changes to commission? ";
    std::cin >> choice;

    if(choice[0] == 'y' || choice [0] == 'Y') {

        std::cout << "Please enter new commission total: ";
        while( !(std::cin >> commission) || commission < 0 ) {
            std::cout << "Please enter a valid commission total: ";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        std::cout << "New commission total is " << commission << std::endl;
    }
}

#endif
