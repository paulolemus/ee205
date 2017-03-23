/* File: Factory.h
 * Name: Paulo Lemus
 * Date: 3/20/2017
 */

#ifndef EE_LAB10_FACTORY_H_
#define EE_LAB10_FACTORY_H_

#include <iostream>
#include "Employee.h"

/* Status: Finished */

class Factory : public Employee {

protected:
    double pay;
    int    sales;

public:
    Factory(double pay);
    Factory(double pay, int sales);
    Factory(
        long int id,
        std::string name,
        std::string address,
        std::string phone,
        std::string email,
        std::string department,
        std::string title,
        double pay,
        int    sales
        );

    void setPay(double pay);
    void setSales(int sales);
    double getPay();
    int    getSales();

    virtual double monthlySalary();
    virtual void   update();
};

Factory::Factory(double pay) : pay(pay), sales(0) {}
Factory::Factory(double pay, int sales) :
    pay(pay), sales(sales) {}
Factory::Factory(
    long int id,
    std::string name,
    std::string address,
    std::string phone,
    std::string email,
    std::string department,
    std::string title,
    double pay,
    int    sales
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
    pay(pay),
    sales(sales) {}

void   Factory::setPay(double pay)  { this->pay = pay; }
void   Factory::setSales(int sales) { this->sales = sales; }
double Factory::getPay()   { return pay; }
int    Factory::getSales() { return sales; }

double Factory::monthlySalary() { 
    double temp = sales;
    sales = 0;
    return temp * pay; 
}
void   Factory::update() {
   
    std::cout << "Current sales: " << sales << std::endl;
    std::cout << "Enter updated amount of sales: ";
    while( !(std::cin >> sales) || sales < 0 ) {
        std::cout << "Please enter a valid number of sales: ";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
    std::cout << "number of sales is now " << sales << std::endl;
    
    std::cout << "Current pay for " << id << ": " << pay << std::endl;
    std::cout << "Enter updated wage per sale: ";
    while( !(std::cin >> pay) || pay < 0 ) {
        std::cout << "Please enter a valid wage per sale: ";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
    std::cout << "Wage per sale is now " << pay << std::endl;
}

#endif
