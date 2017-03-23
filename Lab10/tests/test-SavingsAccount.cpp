#include <gtest/gtest.h>
#include <string>
#include "../SavingsAccount.h"

TEST(SavingsAccount, default_constructor) {
    SavingsAccount sa;
    ASSERT_TRUE(true);
}

TEST(SavingsAccount, default_w_getters) {
    SavingsAccount sa;
    
    long int id = -1;
    std::string name = "";
    double balance = 0;

    ASSERT_EQ(sa.getId(),      id);
    ASSERT_EQ(sa.getName(),    name);
    ASSERT_EQ(sa.getBalance(), balance);
    ASSERT_EQ(sa.getWithdrawals(), 0);
}

TEST(SavingsAccount, setters_n_getters) {
    SavingsAccount sa;
    
    long int id      = 100;
    std::string name = "John";
    double balance   = 200;

    sa.setId(id);
    sa.setName(name);
    sa.setBalance(balance);

    ASSERT_EQ(sa.getId(),      id);
    ASSERT_EQ(sa.getName(),    name);
    ASSERT_EQ(sa.getBalance(), balance);
    ASSERT_EQ(sa.getWithdrawals(), 0);
}

TEST(SavingsAccount, individual_constructor_n_getters) {
    
    long int id      = 100;
    std::string name = "John";
    double balance   = 200;

    SavingsAccount sa(id, name, balance);

    ASSERT_EQ(sa.getId(), id);
    ASSERT_EQ(sa.getName(), name);
    ASSERT_EQ(sa.getBalance(), balance);
    ASSERT_EQ(sa.getWithdrawals(), 0);
}

TEST(SavingsAccount, copy_constuct) {
    
    long int id      = 10005;
    std::string name = "Mary";
    double balance   = 100.45;

    SavingsAccount sa(id, name, balance);
    SavingsAccount copy(sa);

    ASSERT_EQ(sa.getId(),      id);
    ASSERT_EQ(sa.getName(),    name);
    ASSERT_EQ((int)sa.getBalance(), (int)balance);
    ASSERT_EQ(sa.getWithdrawals(), 0);

    ASSERT_EQ(copy.getId(),      id);
    ASSERT_EQ(copy.getName(),    name);
    ASSERT_EQ((int)copy.getBalance(), (int)balance);
    ASSERT_EQ(copy.getWithdrawals(), 0);
}

TEST(SavingsAccount, op_equal_n_compare) {
    
    long int id      = 101245;
    std::string name = "Ruth";
    double balance   = 50.25;

    SavingsAccount sa(id, name, balance);
    SavingsAccount copy = sa;


    ASSERT_EQ(copy.getId(),      id);
    ASSERT_EQ(copy.getName(),    name);
    ASSERT_EQ(copy.getBalance(), balance);
    ASSERT_EQ(sa.getWithdrawals(), 0);
    ASSERT_TRUE(sa == copy);
}


TEST(SavingsAccount, withdraw) {
    
    long int id      = 3;
    std::string name = "Elanor";
    double balance   = 100;
    double result    = 95;

    SavingsAccount sa(id, name, balance);
    ASSERT_TRUE( sa.withdraw(5) );

    ASSERT_EQ(sa.getId(),      id);
    ASSERT_EQ(sa.getName(),    name);
    ASSERT_EQ(sa.getBalance(), result);

    ASSERT_FALSE( sa.withdraw(95.01) );
}

TEST(SavingsAccount, withdraw_bound) {
    SavingsAccount sa(1234, "Rigby", 100);

    ASSERT_TRUE( sa.withdraw(1) );
    ASSERT_EQ(sa.getBalance(), 99.0);
    
    ASSERT_TRUE( sa.withdraw(1) );
    ASSERT_EQ(sa.getBalance(), 98.0);
    
    ASSERT_TRUE( sa.withdraw(1) );
    ASSERT_EQ(sa.getBalance(), 94.0);
    
    ASSERT_TRUE( sa.withdraw(1) );
    ASSERT_EQ(sa.getBalance(), 90.0);
    
    ASSERT_FALSE( sa.withdraw(100) );
    ASSERT_EQ(sa.getBalance(), 90.0);
}

TEST(SavingsAccount, deposit) {
    SavingsAccount sa(100, "Pete", 20);

    ASSERT_TRUE( sa.deposit(100) );
    ASSERT_EQ(sa.getBalance(), 120.0);

    ASSERT_FALSE( sa.deposit(-10) );
    ASSERT_EQ(sa.getBalance(), 120.0);
}

TEST(SavingsAccount, monthly_check) {
    SavingsAccount sa(100, "Pete", 20);

    sa.monthlyCheck();
    ASSERT_EQ(sa.getBalance(), 10.0);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
