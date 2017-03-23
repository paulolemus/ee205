/* File: Technical.h
 * Name: Paulo Lemus
 * Date: 3/20/2017
 */

#ifndef EE_LAB10_TECHNICAL_H_
#define EE_LAB10_TECHNICAL_H_

#include <iostream>
#include <string>
#include "Employee.h"

/* Status:  */

class Technical : public Employee {

protected:
    double fixedSalary;
    double bonus;

public:
    Technical(double salary);
    Technical(
        long int id,
        std::string name,
        std::string address,
        std::string phone,
        std::string email,
        std::string department,
        std::string title,
        double salary,
        double bonus
        );

    void setSalary(double salary);
    void setBonus(double bonus);
    double getSalary();
    double getBonus();

    virtual double monthlySalary();
    virtual void   update();
};

Technical::Technical(double salary) : fixedSalary(salary), bonus(0.0) {}
Technical::Technical(
    long int id,
    std::string name,
    std::string address,
    std::string phone,
    std::string email,
    std::string department,
    std::string title,
    double salary,
    double bonus
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
    fixedSalary(salary),
    bonus(bonus) {}

void   Technical::setSalary(double salary) { fixedSalary = salary; }
void   Technical::setBonus(double bonus)   { this->bonus = bonus; }
double Technical::getSalary() { return fixedSalary; }
double Technical::getBonus()  { return bonus; }

double Technical::monthlySalary() { 
    double temp_bonus = bonus;
    bonus = 0;
    return fixedSalary / 12 + temp_bonus; 
}
void   Technical::update() {
    
    std::string choice;
    std::cout << "Salary: " << fixedSalary <<std::endl;
    std::cout << "Current bonus: " << bonus << std::endl;

    std::cout << "Would you like to make changes to the bonus? ";
    std::cin >> choice;

    if(choice[0] == 'y' || choice[0] == 'Y'){
        std::cout << "Enter new bonus amount: ";
        while( !(std::cin >> bonus) || bonus < 0 ) {
            std::cout << "Please enter a valid bonus amount: ";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        std::cout << "Updated bonus amount is " << bonus << std::endl;
    }
}

#endif
