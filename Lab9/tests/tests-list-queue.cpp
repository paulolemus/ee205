#include <gtest/gtest.h>
#include <exception>
#include "../queue-list.h"

TEST(ListQueue, basic) {
    ee::list::queue<int> que(5);
    ASSERT_EQ( que.capacity(), 5 );
    ASSERT_EQ( que.size(), 0 );
}

TEST(ListQueue, empty) {
    ee::list::queue<int> que(5);
    ASSERT_TRUE( que.isEmpty() );
    ASSERT_FALSE( que.isFull() );
}

TEST(ListQueue, pushnpop) {
    ee::list::queue<int> que(5);
    
    que.push(0);
    ASSERT_FALSE( que.isEmpty() );
    ASSERT_EQ   ( que.size(), 1 );

    que.push(1);
    ASSERT_FALSE( que.isFull() );
    ASSERT_EQ   ( que.size(), 2 );

    que.push(2);
    ASSERT_FALSE( que.isFull() );
    ASSERT_EQ   ( que.size(), 3 );

    ASSERT_TRUE ( que.push(3) );
    ASSERT_FALSE( que.isFull() );
    ASSERT_EQ   ( que.size(), 4 );

    que.push(4);
    ASSERT_TRUE( que.isFull() );
    ASSERT_EQ  ( que.size(), 5 );
    ASSERT_EQ  ( que.size(), que.capacity() );

    ASSERT_FALSE( que.push(5) );
    
    ASSERT_EQ(que.pop(), 0);
    ASSERT_FALSE(que.isFull());

    ASSERT_EQ(que.pop(), 1);
    ASSERT_EQ(que.pop(), 2);
    ASSERT_EQ(que.pop(), 3);
    ASSERT_EQ(que.pop(), 4);
    ASSERT_TRUE( que.isEmpty());

}

TEST(ListQueue, limits) {
    ee::list::queue<int> que(3);
    ASSERT_TRUE(que.isEmpty());
    ASSERT_FALSE(que.isFull());

    ASSERT_THROW(que.pop(), std::runtime_error);
    
    que.push(0);
    que.push(1);
    que.push(2);

    ASSERT_EQ(que.peek(), 0);

    ASSERT_EQ(que.pop(), 0);
    ASSERT_EQ(que.pop(), 1);
    ASSERT_EQ(que.pop(), 2);
    ASSERT_THROW(que.peek(), std::runtime_error);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
