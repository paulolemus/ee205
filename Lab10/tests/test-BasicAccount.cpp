#include <gtest/gtest.h>
#include <string>
#include "../BasicAccount.h"

TEST(BasicAccount, default_constructor) {
    BasicAccount ba;
    ASSERT_TRUE(true);
}

TEST(BasicAccount, default_w_getters) {
    BasicAccount ba;
    
    long int id = -1;
    std::string name = "";
    double balance = 0;

    ASSERT_EQ(ba.getId(), id);
    ASSERT_EQ(ba.getName(), name);
    ASSERT_EQ(ba.getBalance(), balance);
}

TEST(BasicAccount, setters_n_getters) {
    BasicAccount ba;
    
    long int id      = 100;
    std::string name = "John";
    double balance   = 200;

    ba.setId(id);
    ba.setName(name);
    ba.setBalance(balance);

    ASSERT_EQ(ba.getId(), id);
    ASSERT_EQ(ba.getName(), name);
    ASSERT_EQ(ba.getBalance(), balance);
}

TEST(BasicAccount, individual_contructor_n_getters) {
    
    long int id      = 100;
    std::string name = "John";
    double balance   = 200;

    BasicAccount ba(id, name, balance);

    ASSERT_EQ(ba.getId(), id);
    ASSERT_EQ(ba.getName(), name);
    ASSERT_EQ(ba.getBalance(), balance);
}

TEST(BasicAccount, copy_constuct) {
    
    long int id      = 10005;
    std::string name = "Mary";
    double balance   = 100.45;

    BasicAccount ba(id, name, balance);
    BasicAccount copy(ba);


    ASSERT_EQ(copy.getId(), id);
    ASSERT_EQ(copy.getName(), name);
    ASSERT_EQ(copy.getBalance(), balance);
}

TEST(BasicAccount, op_equal_n_compare) {
    
    long int id      = 101245;
    std::string name = "Ruth";
    double balance   = 50.25;

    BasicAccount ba(id, name, balance);
    BasicAccount copy = ba;


    ASSERT_EQ(copy.getId(), id);
    ASSERT_EQ(copy.getName(), name);
    ASSERT_EQ(copy.getBalance(), balance);
    ASSERT_TRUE(ba == copy);
}


TEST(BasicAccount, withdraw) {
    
    long int id      = 3;
    std::string name = "Elanor";
    double balance   = 100;
    double result    = 95;

    BasicAccount ba(id, name, balance);
    ASSERT_TRUE( ba.withdraw(5) );

    ASSERT_EQ(ba.getId(),      id);
    ASSERT_EQ(ba.getName(),    name);
    ASSERT_EQ(ba.getBalance(), result);

    ASSERT_FALSE( ba.withdraw(95.01) );
}

TEST(BasicAccount, deposit) {
    BasicAccount ba(100, "Pete", 20);

    ASSERT_TRUE( ba.deposit(100) );
    ASSERT_EQ(ba.getBalance(), 120.0);

    ASSERT_FALSE( ba.deposit(-10) );
    ASSERT_EQ(ba.getBalance(), 120.0);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
