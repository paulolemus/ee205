#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <sstream>
#include "../Technical.h"

TEST(Technical, default_constructor) {
    Technical ad(65000);
    ASSERT_TRUE(true);
}

TEST(Technical, setters_n_getters) {
    Technical ad(65000);

    long int id            = 100;
    std::string name       = "John";
    std::string address    = "91-1000B Kapokalani St";
    std::string phone      = "808-123-4567";
    std::string email      = "johndoe@gaggle.com";
    std::string department = "Gag";
    std::string title      = "Fun specialist";

    ad.setId(id);
    ad.setName(name);
    ad.setAddress(address);
    ad.setPhone(phone);
    ad.setEmail(email);
    ad.setDepartment(department);
    ad.setTitle(title);

    ASSERT_EQ(ad.getId(), id);
    ASSERT_EQ(ad.getName(), name);
    ASSERT_EQ(ad.getAddress(), address);
    ASSERT_EQ(ad.getPhone(), phone);
    ASSERT_EQ(ad.getEmail(), email);
    ASSERT_EQ(ad.getDepartment(), department);
    ASSERT_EQ(ad.getTitle(), title);
    ASSERT_EQ(ad.getSalary(), 65000);
}

TEST(Technical, init_constructor) {

    double      salary     = 65000;
    double      bonus      = 3000;
    long int    id         = 100;
    std::string name       = "John";
    std::string address    = "91-1000B Kapokalani St";
    std::string phone      = "808-123-4567";
    std::string email      = "johndoe@gaggle.com";
    std::string department = "Gag";
    std::string title      = "Fun specialist";

    Technical ad(id, name, address, phone, email, 
             department, title, salary, bonus);

    ASSERT_EQ(ad.getId(),         id);
    ASSERT_EQ(ad.getName(),       name);
    ASSERT_EQ(ad.getAddress(),    address);
    ASSERT_EQ(ad.getPhone(),      phone);
    ASSERT_EQ(ad.getEmail(),      email);
    ASSERT_EQ(ad.getDepartment(), department);
    ASSERT_EQ(ad.getTitle(),      title);
    ASSERT_EQ(ad.getSalary(),     salary);
    ASSERT_EQ(ad.getBonus(),      bonus);
}

TEST(Technical, fixedSalary) {
    double salary = 65000;
    double bonus  = 3000;
    Technical ad(salary);
    ad.setBonus(bonus);
    ASSERT_EQ(ad.monthlySalary(), salary / 12 + bonus);
    ASSERT_EQ(ad.getBonus(), 0);
}

TEST(Technical, print_info) {

    long int    id         = 100;
    std::string name       = "John";
    std::string address    = "91-1000B Kapokalani St";
    std::string phone      = "808-123-4567";
    std::string email      = "johndoe@gaggle.com";
    std::string department = "Gag";
    std::string title      = "Fun specialist";

    Technical ad(id, name, address, phone, email, 
             department, title, 0, 0);

    ad.printInfo();
    ASSERT_TRUE(true);
}

TEST(Technical, update_valid) {

    std::streambuf* coutbuf = std::cout.rdbuf();
    std::streambuf* cinbuf  = std::cin.rdbuf();
    std::stringstream in("y\n500\n");
    std::stringstream out;
    std::cout.rdbuf( out.rdbuf() );
    std::cin.rdbuf ( in.rdbuf() );

    Technical ad(50000);
    ad.setBonus(100);
    ad.update();
    ASSERT_EQ(ad.getBonus(), 500);
    ASSERT_EQ(ad.monthlySalary(), 50000.0 / 12 + 500);

    std::cin.rdbuf( cinbuf );
    std::cout.rdbuf ( coutbuf );
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
