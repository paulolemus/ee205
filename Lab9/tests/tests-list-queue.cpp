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

TEST(ListQueue, enqueuendequeue) {
    ee::list::queue<int> que(5);
    
    que.enqueue(0);
    ASSERT_FALSE( que.isEmpty() );
    ASSERT_EQ   ( que.size(), 1 );

    que.enqueue(1);
    ASSERT_FALSE( que.isFull() );
    ASSERT_EQ   ( que.size(), 2 );

    que.enqueue(2);
    ASSERT_FALSE( que.isFull() );
    ASSERT_EQ   ( que.size(), 3 );

    ASSERT_TRUE ( que.enqueue(3) );
    ASSERT_FALSE( que.isFull() );
    ASSERT_EQ   ( que.size(), 4 );

    que.enqueue(4);
    ASSERT_TRUE( que.isFull() );
    ASSERT_EQ  ( que.size(), 5 );
    ASSERT_EQ  ( que.size(), que.capacity() );

    ASSERT_FALSE( que.enqueue(5) );
    
    ASSERT_EQ(que.dequeue(), 0);
    ASSERT_FALSE(que.isFull());

    ASSERT_EQ(que.dequeue(), 1);
    ASSERT_EQ(que.dequeue(), 2);
    ASSERT_EQ(que.dequeue(), 3);
    ASSERT_EQ(que.dequeue(), 4);
    ASSERT_TRUE( que.isEmpty());

}

TEST(ListQueue, limits) {
    ee::list::queue<int> que(3);
    ASSERT_TRUE(que.isEmpty());
    ASSERT_FALSE(que.isFull());

    ASSERT_THROW(que.dequeue(), std::runtime_error);
    
    que.enqueue(0);
    que.enqueue(1);
    que.enqueue(2);

    ASSERT_EQ(que.peek(), 0);

    ASSERT_EQ(que.dequeue(), 0);
    ASSERT_EQ(que.dequeue(), 1);
    ASSERT_EQ(que.dequeue(), 2);
    ASSERT_THROW(que.peek(), std::runtime_error);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
