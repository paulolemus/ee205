#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include "../Management.h"

TEST(Management, default_constructor) {
    Management ad(65000);
    ASSERT_TRUE(true);
}

TEST(Management, bonus_constructor) {
    double bonus = 100;
    Management ad(65000, bonus);
    ASSERT_EQ( ad.getBonus(), bonus );
}

TEST(Management, setters_n_getters) {
    Management ad(65000);

    long int id            = 100;
    std::string name       = "John";
    std::string address    = "91-1000B Kapokalani St";
    std::string phone      = "808-123-4567";
    std::string email      = "johndoe@gaggle.com";
    std::string department = "Gag";
    std::string title      = "Fun specialist";
    double      bonus      = 100;

    ad.setId(id);
    ad.setName(name);
    ad.setAddress(address);
    ad.setPhone(phone);
    ad.setEmail(email);
    ad.setDepartment(department);
    ad.setTitle(title);
    ad.setBonus(bonus);

    ASSERT_EQ(ad.getId(),         id);
    ASSERT_EQ(ad.getName(),       name);
    ASSERT_EQ(ad.getAddress(),    address);
    ASSERT_EQ(ad.getPhone(),      phone);
    ASSERT_EQ(ad.getEmail(),      email);
    ASSERT_EQ(ad.getDepartment(), department);
    ASSERT_EQ(ad.getTitle(),      title);
    ASSERT_EQ(ad.getSalary(),     65000);
    ASSERT_EQ(ad.getBonus(),      bonus);
}

TEST(Management, init_constructor) {

    double      salary     = 65000;
    long int    id         = 100;
    std::string name       = "John";
    std::string address    = "91-1000B Kapokalani St";
    std::string phone      = "808-123-4567";
    std::string email      = "johndoe@gaggle.com";
    std::string department = "Gag";
    std::string title      = "Fun specialist";
    double      bonus      = 400;

    Management ad(id, name, address, phone, email, 
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

TEST(Management, fixedSalary) {
    double salary = 65000;
    double bonus  = 300;
    Management ad(salary, bonus);
    ASSERT_EQ(ad.monthlySalary(), salary / 12 + bonus);
}

TEST(Management, fixedSalary_getter_setter) {
    double salary = 65000;
    Management ad(salary);
    ASSERT_EQ(ad.monthlySalary(), salary / 12);
    ASSERT_EQ(ad.getSalary(), salary);
    salary = 70000;
    ad.setSalary(salary);
    ASSERT_EQ(ad.getSalary(), salary);
}

TEST(Management, print_info) {

    long int    id         = 100;
    std::string name       = "John";
    std::string address    = "91-1000B Kapokalani St";
    std::string phone      = "808-123-4567";
    std::string email      = "johndoe@gaggle.com";
    std::string department = "Gag";
    std::string title      = "Fun specialist";

    Management ad(id, name, address, phone, email, 
             department, title, 0, 0);

    ad.printInfo();
    ASSERT_TRUE(true);
}

TEST(Management, update_valid) {
    std::stringstream ss("100\n");
    std::stringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::streambuf* cinbuf  = std::cin.rdbuf();

    std::cin.rdbuf( ss.rdbuf() );
    std::cout.rdbuf( out.rdbuf() );

    Management ad(50000);
    ad.update();
    ASSERT_EQ(ad.monthlySalary(), 50000.0 / 12 + 100);
    ASSERT_TRUE(true);
    std::cout.rdbuf( coutbuf );
    std::cin.rdbuf( cinbuf );
}

TEST(Management, update_invalid_then_valid) {
    std::stringstream ss("invalid\n100\n");
    std::stringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::streambuf* cinbuf  = std::cin.rdbuf();
    std::cin.rdbuf( ss.rdbuf() );
    std::cout.rdbuf( out.rdbuf() );

    Management ad(50000);
    ad.update();
    ASSERT_EQ(ad.monthlySalary(), 50000.0 / 12 + 100);
    ASSERT_TRUE(true);
    std::cout.rdbuf( coutbuf );
    std::cin.rdbuf( cinbuf );
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
