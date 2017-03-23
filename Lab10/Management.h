/* File: Management.h
 * Name: Paulo Lemus
 * Date: 3/20/2017
 */

#ifndef EE_LAB10_MANAGEMENT_H_
#define EE_LAB10_MANAGEMENT_H_

#include <iostream>
#include "Employee.h"

/* Status: Finished */

class Management : public Employee {

protected:
    double fixedSalary;
    double regBonus;

public:
    Management(double salary);
    Management(double salary, double regBonus);
    Management(
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

Management::Management(double salary) : fixedSalary(salary), regBonus(0.0) {}
Management::Management(double salary, double regBonus) :
    fixedSalary(salary), regBonus(regBonus) {}
Management::Management(
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
    regBonus(bonus) {}

void   Management::setSalary(double salary) { fixedSalary = salary; }
void   Management::setBonus(double bonus)   { regBonus = bonus; }
double Management::getSalary() { return fixedSalary; }
double Management::getBonus()  { return regBonus; }

double Management::monthlySalary() { return fixedSalary / 12 + regBonus; }
void   Management::update() {

    std::cout << "Enter Management employee bonus: ";
    while( !(std::cin >> regBonus) || regBonus < 0 ) {
        std::cout << "Please enter a valid bonus amount: " << std::endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
    std::cout << "Bonus is now " << regBonus << std::endl;
}

#endif
