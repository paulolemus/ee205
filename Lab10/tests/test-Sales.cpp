#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include "../Sales.h"

TEST(Sales, salary_constructor) {
    Sales ad(65000);
    ASSERT_TRUE(true);
}

TEST(Sales, salary_commission_constructor) {
    double salary = 65000;
    double commission = 4000;
    Sales ad(salary, commission);
    ASSERT_EQ( ad.getSalary(), salary );
    ASSERT_EQ( ad.getCommission(), commission );
}

TEST(Sales, setters_n_getters) {

    long int id            = 100;
    std::string name       = "John";
    std::string address    = "91-1000B Kapokalani St";
    std::string phone      = "808-123-4567";
    std::string email      = "johndoe@gaggle.com";
    std::string department = "Gag";
    std::string title      = "Fun specialist";
    double      salary     = 65000;
    double      commission = 4000;

    Sales ad(0);

    ad.setId(id);
    ad.setName(name);
    ad.setAddress(address);
    ad.setPhone(phone);
    ad.setEmail(email);
    ad.setDepartment(department);
    ad.setTitle(title);
    ad.setSalary(salary);
    ad.setCommission(commission);
    
    
    ASSERT_EQ(ad.getId(),         id);
    ASSERT_EQ(ad.getName(),       name);
    ASSERT_EQ(ad.getAddress(),    address);
    ASSERT_EQ(ad.getPhone(),      phone);
    ASSERT_EQ(ad.getEmail(),      email);
    ASSERT_EQ(ad.getDepartment(), department);
    ASSERT_EQ(ad.getTitle(),      title);
    ASSERT_EQ(ad.getSalary(),     salary);
    ASSERT_EQ(ad.getCommission(),  commission);
}

TEST(Sales, init_constructor) {

    double      salary     = 65000;
    long int    id         = 100;
    std::string name       = "John";
    std::string address    = "91-1000B Kapokalani St";
    std::string phone      = "808-123-4567";
    std::string email      = "johndoe@gaggle.com";
    std::string department = "Gag";
    std::string title      = "Fun specialist";
    double      commission = 400;

    Sales ad(id, name, address, phone, email, 
             department, title, salary, commission);

    ASSERT_EQ(ad.getId(),         id);
    ASSERT_EQ(ad.getName(),       name);
    ASSERT_EQ(ad.getAddress(),    address);
    ASSERT_EQ(ad.getPhone(),      phone);
    ASSERT_EQ(ad.getEmail(),      email);
    ASSERT_EQ(ad.getDepartment(), department);
    ASSERT_EQ(ad.getTitle(),      title);
    ASSERT_EQ(ad.getSalary(),     salary);
    ASSERT_EQ(ad.getCommission(), commission);
}

TEST(Sales, monthlySalary) {
    double salary     = 65000;
    double commission = 400;;
    Sales ad(salary, commission);
    ASSERT_EQ(ad.monthlySalary(), salary / 12 + commission);
    ASSERT_EQ(ad.getCommission(), 0.0);
}

TEST(Sales, print_info) {

    long int    id         = 100;
    std::string name       = "John";
    std::string address    = "91-1000B Kapokalani St";
    std::string phone      = "808-123-4567";
    std::string email      = "johndoe@gaggle.com";
    std::string department = "Gag";
    std::string title      = "Fun specialist";

    Sales ad(id, name, address, phone, email, 
             department, title, 0, 0);

    ad.printInfo();
    ASSERT_TRUE(true);
}

TEST(Sales, update_valid) {
    std::stringstream ss("y\n40000\ny\n150\n");
    std::stringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::streambuf* cinbuf  = std::cin.rdbuf();

    std::cin.rdbuf( ss.rdbuf() );
    std::cout.rdbuf( out.rdbuf() );

    double salary = 54000;
    double commission = 540;

    Sales ad(salary, commission);
    ASSERT_EQ(ad.getSalary(),     salary);
    ASSERT_EQ(ad.getCommission(), commission);

    ad.update();
    ASSERT_EQ(ad.getSalary(), 40000);
    ASSERT_EQ(ad.getCommission(), 150);

    ASSERT_EQ(ad.monthlySalary(), 40000.0 / 12 + 150);
    ASSERT_EQ(ad.getCommission(), 0.0);

    std::cout.rdbuf( coutbuf );
    std::cin.rdbuf( cinbuf );
}

TEST(Sales, update_invalid_then_valid) {
    std::stringstream ss("y\ninvalidhere\n40000\ny\ninvalid\n150\n");
    std::stringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::streambuf* cinbuf  = std::cin.rdbuf();

    std::cin.rdbuf( ss.rdbuf() );
    std::cout.rdbuf( out.rdbuf() );

    double salary = 54000;
    double commission = 540;

    Sales ad(salary, commission);
    ASSERT_EQ(ad.getSalary(),     salary);
    ASSERT_EQ(ad.getCommission(), commission);

    ad.update();
    ASSERT_EQ(ad.getSalary(), 40000);
    ASSERT_EQ(ad.getCommission(), 150);

    ASSERT_EQ(ad.monthlySalary(), 40000.0 / 12 + 150);
    ASSERT_EQ(ad.getCommission(), 0.0);

    std::cout.rdbuf( coutbuf );
    std::cin.rdbuf( cinbuf );
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
