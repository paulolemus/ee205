/* File: Employee.h
 * Name: Paulo Lemus
 * Date: 2/16/2017
 */

#ifndef EE_LAB10_EMPLOYEE_H_
#define EE_LAB10_EMPLOYEE_H_

#include <ostream>
#include <string>


class Employee {

protected:
    long int        id;
    std::string     name;
    std::string     address;
    std::string     phone;
    std::string     email;
    std::string     department;
    std::string     title;

public:
    Employee();
    Employee(
        long int id,
        std::string name,
        std::string address,
        std::string phone,
        std::string email,
        std::string department,
        std::string title
        );

    // Setters
    void setId( long int id );
    void setName( std::string name );
    void setAddress( std::string address );
    void setPhone( std::string phone );
    void setEmail( std::string email );
    void setDepartment( std::string department );
    void setTitle( std::string title );

    // Getters
    long int    getId();
    std::string getName();
    std::string getAddress();
    std::string getPhone();
    std::string getEmail();
    std::string getDepartment();
    std::string getTitle();

    virtual void printInfo();
    
    virtual double monthlySalary() = 0;
    virtual void   update()        = 0;

};

Employee::Employee() {}
Employee::Employee(
    long int id,
    std::string name,
    std::string address,
    std::string phone,
    std::string email,
    std::string department,
    std::string title
    ) : 
    id(id),
    name(name),
    address(address),
    phone(phone),
    email(email),
    department(department),
    title(title) {}

// Setters
void Employee::setId( long int id )              { this->id = id; }
void Employee::setName( std::string name )       { this->name = name; }
void Employee::setAddress( std::string address ) { this->address = address; }
void Employee::setPhone( std::string phone )     { this->phone = phone; }
void Employee::setEmail( std::string email )     { this->email = email; }
void Employee::setDepartment( std::string department ) { this->department = department; }
void Employee::setTitle( std::string title )     { this->title = title; }

// Getters
long int    Employee::getId()         { return id; }
std::string Employee::getName()       { return name; }
std::string Employee::getAddress()    { return address; }
std::string Employee::getPhone()      { return phone; }
std::string Employee::getEmail()      { return email; }
std::string Employee::getDepartment() { return department; }
std::string Employee::getTitle()      { return title; }

void Employee::printInfo() {
    std::cout << "ID:\t\t"       << id         << std::endl;
    std::cout << "Name:\t\t"     << name       << std::endl;
    std::cout << "Address:\t"    << address    << std::endl;
    std::cout << "Phone:\t\t"    << phone      << std::endl;
    std::cout << "Email:\t\t"    << email      << std::endl;
    std::cout << "Department:\t" << department << std::endl;
    std::cout << "Title:\t\t"      << title      << std::endl;
}

#endif
