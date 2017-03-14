#include <gtest/gtest.h>
#include "../stack-list.h"

TEST(ListStack, basic) {
    ee::list::stack<int> stk(5);
    ASSERT_EQ( stk.capacity(), 5 );
    ASSERT_EQ( stk.size(), 0 );
}

TEST(ListStack, empty) {
    ee::list::stack<int> stk(5);
    ASSERT_TRUE( stk.isEmpty() );
    ASSERT_FALSE( stk.isFull() );
}

TEST(ListStack, pushnpop) {
    ee::list::stack<int> stk(5);
    
    stk.push(0);
    ASSERT_FALSE( stk.isEmpty() );
    ASSERT_EQ   ( stk.size(), 1 );

    stk.push(1);
    ASSERT_FALSE( stk.isFull() );
    ASSERT_EQ   ( stk.size(), 2 );

    stk.push(2);
    ASSERT_FALSE( stk.isFull() );
    ASSERT_EQ   ( stk.size(), 3 );

    ASSERT_TRUE ( stk.push(3) );
    ASSERT_FALSE( stk.isFull() );
    ASSERT_EQ   ( stk.size(), 4 );

    stk.push(4);
    ASSERT_TRUE( stk.isFull() );
    ASSERT_EQ  ( stk.size(), 5 );
    ASSERT_EQ  ( stk.size(), stk.capacity() );

    ASSERT_FALSE( stk.push(5) );

    ASSERT_EQ( stk.pop(), 4);
    ASSERT_EQ( stk.pop(), 3);
    ASSERT_EQ( stk.pop(), 2);
    ASSERT_EQ( stk.pop(), 1);
    ASSERT_EQ( stk.pop(), 0);
    ASSERT_TRUE( stk.isEmpty() );
    
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
