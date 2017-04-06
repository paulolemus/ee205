#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
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

TEST(BinaryTree, get_null_root) {

    BinaryTree<int> tree;
    ASSERT_EQ(tree.getRoot(), nullptr);
}

TEST(BinaryTree, get_valid_root) {

    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(7);
    ASSERT_EQ(tree.getRoot()->data, 10);
}

TEST(BinaryTree, find_null) {

    BinaryTree<int> tree;
    ASSERT_EQ(tree.find(10), nullptr);
}

TEST(BinaryTree, find_valid) {

    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(8);
    tree.insert(5);
    tree.insert(1);
    tree.insert(4);
    ASSERT_EQ(tree.find(1)->data, 1);
    ASSERT_EQ(tree.find(10)->data, 10);
    ASSERT_EQ(tree.find(30)->data, 30);
    ASSERT_EQ(tree.find(8)->data, 8);
    ASSERT_EQ(tree.find(4)->data, 4);
    ASSERT_EQ(tree.find(5)->data, 5);
    ASSERT_EQ(tree.find(20)->data, 20);
    ASSERT_EQ(tree.find(100), nullptr);
}

TEST(BinaryTree, post_order_check) {

    std::stringstream ss("1 5 9 8 30 20 10 \n");
    std::stringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::cout.rdbuf( out.rdbuf() );


    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(8);
    tree.insert(9);
    tree.insert(5);
    tree.insert(1);
    tree.postorder();

    ASSERT_EQ(ss.str(), out.str());
    std::cout.rdbuf( coutbuf );
}

TEST(BinaryTree, in_order_check) {

    std::stringstream ss("1 5 8 9 10 20 30 \n");
    std::stringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::cout.rdbuf( out.rdbuf() );


    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(8);
    tree.insert(9);
    tree.insert(5);
    tree.insert(1);
    tree.inorder();

    ASSERT_EQ(ss.str(), out.str());
    std::cout.rdbuf( coutbuf );
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
