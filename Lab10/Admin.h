/* File: Admin.h
 * Name: Paulo Lemus
 * Date: 3/20/2017
 */

#ifndef EE_LAB10_ADMIN_H_
#define EE_LAB10_ADMIN_H_

#include <iostream>
#include "Employee.h"

/* Status: finished */

class Admin : public Employee {

protected:
    double fixedSalary;

public:
    Admin(double salary);
    Admin(
        long int id,
        std::string name,
        std::string address,
        std::string phone,
        std::string email,
        std::string department,
        std::string title,
        double salary
        );

    void setSalary(double salary);
    double getSalary();

    virtual double monthlySalary();
    virtual void   update();
};

Admin::Admin(double salary) : fixedSalary(salary) {}
Admin::Admin(
    long int id,
    std::string name,
    std::string address,
    std::string phone,
    std::string email,
    std::string department,
    std::string title,
    double salary
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
    fixedSalary(salary) {}

void   Admin::setSalary(double salary) { fixedSalary = salary; }
double Admin::getSalary() { return fixedSalary; }

double Admin::monthlySalary() { return fixedSalary / 12; }
void   Admin::update() {
    std::cout << "Admins have a fixed salary, cannot be changed." << std::endl;
}

#endif
