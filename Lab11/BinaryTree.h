/* File: BinaryTree.h
 * Name: Paulo Lemus
 * Date: 3/23/2017
 */

#ifndef EE_LAB11_BINARYTREE_H_
#define EE_LAB11_BINARYTREE_H_

#include <iostream>

/* This file contains a sorted binary tree data structure.
 * It makes use of recursion to insert, print, find, etc,
 * however it cannot fufill the lab requirements of two
 * complete unsorted binary trees separated by a root.
 * This is a more traditional binary tree and is probably
 * what I was supposed to do (?).
 *
 * Instead of placing functions for the tree in treeprint,
 * treeinsert, and treefind, I wrote them all in this one file
 * for cleanliness.
 */

////////////////////////
//    DECLARATIONS    //
////////////////////////

template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(const T& data);
};


template <typename T>
class BinaryTree {

    Node<T>* root;

public:
    BinaryTree();

    Node<T>* getRoot();
    void     insert (const T& data);
    void     insert (const T& data, Node<T>* node);
    Node<T>* find   (const T& data);
    Node<T>* find   (const T& data, Node<T>* node);
    void     inorder();
    void     inorder(Node<T>* node);
    void     postorder();
    void     postorder(Node<T>* node);
};

////////////////////////
//   IMPLEMENTATION   //
////////////////////////

// NODE
template <typename T>
Node<T>::Node(const T& data) : 
    data(data), 
    left(nullptr), 
    right(nullptr) {}


// BINARY TREE
template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
Node<T>* BinaryTree<T>::getRoot() { return root; }

/* Iterative implementation of insert
 * This function is mainly used to begin the recursive
 * insert function found directly beneath this one.
 */
template <typename T>
void BinaryTree<T>::insert(const T& data) {
    if(root == nullptr)  {
        root = new Node<T>(data);
    }
    else {
        insert(data, root);
    }
} // insert

/* This function is given a non-null ptr from insert.
 * It moves left or right depending on if the data is
 * greater or less than the current node.
 * It finally inserts it when it encounters a nullptr
 */
template <typename T>
void BinaryTree<T>::insert(const T& data, Node<T>* node) {
    
    if(node == nullptr);
    else if(data == node->data);
    else if(data > node->data) {
        if(node->right == nullptr) node->right = new Node<T>(data);
        else insert(data, node->right);
    }   
    else {
        if(node->left == nullptr) node->left = new Node<T>(data);
        else insert(data, node->left);
    }
}

/* Just used to call the recursive find function
 */
template <typename T>
Node<T>* BinaryTree<T>::find(const T& data) {
    return find(data, root);
}

/* This function traverses the tree until it finds either a 
 * nullptr leaf or if it finds a node with the data, upon which
 * it returns it.
 */
template <typename T>
Node<T>* BinaryTree<T>::find(const T& data, Node<T>* node) {

    if(node == nullptr) return nullptr;
    else if(data == node->data) return node;
    else if(data > node->data)  return find(data, node->right);
    else                        return find(data, node->left);
}

/* Used to call recursive function
 */
template <typename T>
void BinaryTree<T>::inorder() { 
    inorder(root);
    std::cout << std::endl;
}
/* Inorder algorithm:
 * Traverse left subtree
 * visit current node
 * traverse right subtree
 */
template <typename T>
void BinaryTree<T>::inorder(Node<T>* node) {

    if(node != nullptr) {
        if(node->left != nullptr) inorder(node->left);
        std::cout << node->data << " ";
        if(node->right != nullptr) inorder(node->right);
    }
}

/* Used to call recursive function
 */
template <typename T>
void BinaryTree<T>::postorder() {
    postorder(root);
    std::cout <<std::endl;
}
/* Postorder algorithm:
 * traverse left subtree
 * traverse right subtree
 * visit current node
 */
template <typename T>
void BinaryTree<T>::postorder(Node<T>* node) {
    if(node != nullptr) {
        if(node->left != nullptr)  postorder(node->left);
        if(node->right != nullptr) postorder(node->right);
        std::cout << node->data << " ";
    }
}

#endif

