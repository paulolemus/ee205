#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include "../Admin.h"

TEST(Admin, default_constructor) {
    Admin ad(65000);
    ASSERT_TRUE(true);
}

TEST(Admin, setters_n_getters) {
    Admin ad(65000);

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

TEST(Admin, init_constructor) {

    double      salary     = 65000;
    long int    id         = 100;
    std::string name       = "John";
    std::string address    = "91-1000B Kapokalani St";
    std::string phone      = "808-123-4567";
    std::string email      = "johndoe@gaggle.com";
    std::string department = "Gag";
    std::string title      = "Fun specialist";

    Admin ad(id, name, address, phone, email, 
             department, title, salary);

    ASSERT_EQ(ad.getId(),         id);
    ASSERT_EQ(ad.getName(),       name);
    ASSERT_EQ(ad.getAddress(),    address);
    ASSERT_EQ(ad.getPhone(),      phone);
    ASSERT_EQ(ad.getEmail(),      email);
    ASSERT_EQ(ad.getDepartment(), department);
    ASSERT_EQ(ad.getTitle(),      title);
    ASSERT_EQ(ad.getSalary(),     salary);
}

TEST(Admin, fixedSalary) {
    double salary = 65000;
    Admin ad(salary);
    ASSERT_EQ(ad.monthlySalary(), salary / 12);
}

TEST(Admin, fixedSalary_getter_setter) {
    double salary = 65000;
    Admin ad(salary);
    ASSERT_EQ(ad.monthlySalary(), salary / 12);
    ASSERT_EQ(ad.getSalary(), salary);
    salary = 70000;
    ad.setSalary(salary);
    ASSERT_EQ(ad.getSalary(), salary);
}

TEST(Admin, print_info) {

    long int    id         = 100;
    std::string name       = "John";
    std::string address    = "91-1000B Kapokalani St";
    std::string phone      = "808-123-4567";
    std::string email      = "johndoe@gaggle.com";
    std::string department = "Gag";
    std::string title      = "Fun specialist";

    Admin ad(id, name, address, phone, email, 
             department, title, 0);

    ad.printInfo();
    ASSERT_TRUE(true);
}

TEST(Admin, update) {
    Admin ad(50000);
    ad.update();
    ASSERT_TRUE(true);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
