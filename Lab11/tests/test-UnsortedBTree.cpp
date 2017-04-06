#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <sstream>
#include "UnsortedBinaryTree.h"

TEST(UnsortedBinaryTree, constuctor) {

    BinaryTree<int> tree;
    ASSERT_TRUE(true);
}

TEST(UnsortedBinaryTree, insert_base_ends) {

    BinaryTree<int> tree;
    tree.insert(1);
    ASSERT_TRUE(true);
}

TEST(UnsortedBinaryTree, empty_print) {
    
    std::string check = "empty\n";

    std::stringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::cout.rdbuf( out.rdbuf() );
    std::string capture;

    BinaryTree<int> tree;
    tree.print();

    capture = out.str();

    ASSERT_EQ(capture, check);
    std::cout.rdbuf( coutbuf );
}


TEST(UnsortedBinaryTree, print_tree) {
    
    std::string check = "node 10, right->12 \n";
    check += "node 12, left->11 right->14 \n";
    check += "node 11, \n";
    check += "node 14, \n";

    std::stringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::cout.rdbuf( out.rdbuf() );
    std::string capture;

    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(12);
    tree.insert(11);
    tree.insert(14);
    tree.print();

    capture = out.str();

    ASSERT_EQ(capture, check);

    std::cout.rdbuf( coutbuf );
}

TEST(UnsortedBinaryTree, insert_multiple_ends) {

    BinaryTree<int> tree;
    tree.insert(10);
    ASSERT_TRUE(true);
    tree.insert(11);
    ASSERT_TRUE(true);
    tree.insert(12);
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
    tree.insert(50);
    ASSERT_TRUE(true);
    tree.insert(12);
    ASSERT_TRUE(true);
}

TEST(UnsortedBinaryTree, find_empty) {
    
    BinaryTree<int> tree;
    auto ptr = tree.find(10);
    ASSERT_EQ(ptr, nullptr);
}

TEST(UnsortedBinaryTree, find) {

    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(11);
    tree.insert(12);
    tree.insert(9);
    tree.insert(8);
    tree.insert(3);
    tree.insert(5);
    tree.insert(30);
    tree.insert(50);
    tree.insert(12);

    auto ptr = tree.find(8);
    ASSERT_EQ(ptr->data, 8);
    ptr = tree.find(12);
    ASSERT_EQ(ptr->data, 12);
    ptr = tree.find(30);
    ASSERT_EQ(ptr->data, 30);
    ptr = tree.find(3);
    ASSERT_EQ(ptr->data, 3);
    ptr = tree.find(10);
    ASSERT_EQ(ptr->data, 10);
    ptr = tree.find(1000);
    ASSERT_EQ(ptr, nullptr);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
