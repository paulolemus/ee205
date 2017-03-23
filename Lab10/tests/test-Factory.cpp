#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include "../Factory.h"

TEST(Factory, pay_constructor) {
    Factory ad(8.50);
    ASSERT_TRUE(true);
}

TEST(Factory, pay_sales_constructor) {
    double pay   = 8.50;
    int    sales = 10;
    Factory ad(pay, sales);
    ASSERT_EQ( ad.getPay(), pay );
    ASSERT_EQ( ad.getSales(), sales );
}

TEST(Factory, setters_n_getters) {

    long int id            = 100;
    std::string name       = "John";
    std::string address    = "91-1000B Kapokalani St";
    std::string phone      = "808-123-4567";
    std::string email      = "johndoe@gaggle.com";
    std::string department = "Gag";
    std::string title      = "Fun specialist";
    double      pay        = 100;
    int         sales      = 10;

    Factory ad(0);

    ad.setId(id);
    ad.setName(name);
    ad.setAddress(address);
    ad.setPhone(phone);
    ad.setEmail(email);
    ad.setDepartment(department);
    ad.setTitle(title);
    ad.setPay(pay);
    ad.setSales(sales);

    ASSERT_EQ(ad.getId(),         id);
    ASSERT_EQ(ad.getName(),       name);
    ASSERT_EQ(ad.getAddress(),    address);
    ASSERT_EQ(ad.getPhone(),      phone);
    ASSERT_EQ(ad.getEmail(),      email);
    ASSERT_EQ(ad.getDepartment(), department);
    ASSERT_EQ(ad.getTitle(),      title);
    ASSERT_EQ(ad.getPay(),        pay);
    ASSERT_EQ(ad.getSales(),      sales);
}

TEST(Factory, init_constructor) {

    long int    id         = 100;
    std::string name       = "John";
    std::string address    = "91-1000B Kapokalani St";
    std::string phone      = "808-123-4567";
    std::string email      = "johndoe@gaggle.com";
    std::string department = "Gag";
    std::string title      = "Fun specialist";
    double      pay        = 8.50;
    int         sales      = 14;

    Factory ad(id, name, address, phone, email, 
             department, title, pay, sales);

    ASSERT_EQ(ad.getId(),         id);
    ASSERT_EQ(ad.getName(),       name);
    ASSERT_EQ(ad.getAddress(),    address);
    ASSERT_EQ(ad.getPhone(),      phone);
    ASSERT_EQ(ad.getEmail(),      email);
    ASSERT_EQ(ad.getDepartment(), department);
    ASSERT_EQ(ad.getTitle(),      title);
    ASSERT_EQ(ad.getPay(),        pay);
    ASSERT_EQ(ad.getSales(),      sales);
}

TEST(Factory, monthlySalary) {
    double pay = 8.50;
    int sales  = 10;
    Factory ad(pay, sales);
    ASSERT_EQ(ad.monthlySalary(), pay * sales);
    ASSERT_EQ(ad.getSales(), 0);
}

TEST(Factory, print_info) {

    long int    id         = 100;
    std::string name       = "John";
    std::string address    = "91-1000B Kapokalani St";
    std::string phone      = "808-123-4567";
    std::string email      = "johndoe@gaggle.com";
    std::string department = "Gag";
    std::string title      = "Fun specialist";
    double      pay        = 8.50;
    int         sales      = 7;

    Factory ad(id, name, address, phone, email, 
             department, title, pay, sales);

    ad.printInfo();
    ASSERT_TRUE(true);
}

TEST(Factory, update_valid) {
    std::stringstream ss("100\n8.50");
    std::stringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::streambuf* cinbuf  = std::cin.rdbuf();

    std::cin.rdbuf( ss.rdbuf() );
    std::cout.rdbuf( out.rdbuf() );

    Factory ad(10);
    ad.update();
    ASSERT_EQ(ad.monthlySalary(), 100 * 8.50);
    ASSERT_EQ(ad.getSales(), 0);
    std::cout.rdbuf( coutbuf );
    std::cin.rdbuf( cinbuf );
}

TEST(Factory, update_invalid_then_valid) {
    std::stringstream ss("invalid\n100\n8.50\n");
    std::stringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::streambuf* cinbuf  = std::cin.rdbuf();
    std::cin.rdbuf( ss.rdbuf() );
    std::cout.rdbuf( out.rdbuf() );

    Factory ad(10);
    ad.update();
    ASSERT_EQ(ad.monthlySalary(), 100 * 8.50);
    ASSERT_EQ(ad.getSales(), 0);
    std::cout.rdbuf( coutbuf );
    std::cin.rdbuf( cinbuf );
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
