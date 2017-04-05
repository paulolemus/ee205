#include <gtest/gtest.h>
#include "BinaryTree.h"

TEST(BinaryTree, constuctor) {

    BinaryTree<int> tree;
    ASSERT_TRUE(true);
}

TEST(BinaryTree, insert_base_ends) {

    BinaryTree<int> tree;
    tree.insert(1);
    ASSERT_TRUE(true);
}

TEST(BinaryTree, insert_multiple_ends) {

    BinaryTree<int> tree;
    tree.insert(10);
    ASSERT_TRUE(true);
    tree.insert(11);
    ASSERT_TRUE(true);
    tree.insert(9);
    ASSERT_TRUE(true);
    tree.insert(8);
    ASSERT_TRUE(true);
    tree.insert(3);
    ASSERT_TRUE(true);
    tree.insert(5);
    ASSERT_TRUE(true);
    tree.insert(30);
    ASSERT_TRUE(true);
}

TEST(BinaryTree, insert_r_base_ends) {
    BinaryTree<int> tree;
    tree.insert_r(1);
    ASSERT_TRUE(true);
}

TEST(BinaryTree, insert_r_multiple_ends) {

    BinaryTree<int> tree;
    tree.insert_r(10);
    ASSERT_TRUE(true);
    tree.insert_r(11);
    ASSERT_TRUE(true);
    tree.insert_r(9);
    ASSERT_TRUE(true);
    tree.insert_r(8);
    ASSERT_TRUE(true);
    tree.insert_r(3);
    ASSERT_TRUE(true);
    tree.insert_r(5);
    ASSERT_TRUE(true);
    tree.insert_r(30);
    ASSERT_TRUE(true);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
