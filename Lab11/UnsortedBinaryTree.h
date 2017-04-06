/* File: BinaryTree.h
 * Name: Paulo Lemus
 * Date: 3/23/2017
 */

/* Here is code for a datastructure that follows the
 * requirements for data structure in the assignment
 * exactly, besides splitting up the code into different
 * .cpp files.
 *
 * This BinaryTree puts all values greater than the root
 * on the right subtree and all smaller values in the 
 * left subtree. The left and right subtrees are unsorted
 * complete binary trees, populated by using a vector, 
 * parents are found at i / 2.
 */

#ifndef EE_LAB11_BINARYTREE_H_
#define EE_LAB11_BINARYTREE_H_

#include <iostream>
#include <vector>

////////////////////////
//    DECLARATIONS    //
////////////////////////

// A Node struct used to create the linked binary
// tree structure
template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(const T& data);
};


// A Complete Tree used to maintain proper links for the
// left and right subtrees of the root
template <typename T>
class CompleteBTree {
    std::vector<Node<T>*> treeVec;

public:
    CompleteBTree();
    void     insert(Node<T>* ptr);
    Node<T>* find  (const T& data);
};


// The primary BinaryTree structure that is used
template <typename T>
class BinaryTree {

    Node<T>* root;
    CompleteBTree<T> leftTree;
    CompleteBTree<T> rightTree;


public:
    BinaryTree();
    void     insert(const T& data);
    Node<T>* find  (const T& data);
    void     print ();
    void     print (const Node<T>* node);
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

// COMPLETE BINARY TREE
template <typename T>
CompleteBTree<T>::CompleteBTree() {}

// This function adds a node to one of the unordered
// binary subtrees and is in charge of settings a new
// node's parent to point to it.
template <typename T>
void CompleteBTree<T>::insert(Node<T>* ptr) {
    treeVec.push_back(ptr);

    
    // If the node has a parent
    if((treeVec.size() / 2) > 0) {

        // update parent's left pointer
        if(treeVec.size() % 2 == 0) {
            treeVec[treeVec.size() / 2 - 1]->left = treeVec[treeVec.size() - 1];
        }
        // update parent's right pointer
        else {
            treeVec[treeVec.size() / 2 - 1]->right = treeVec[treeVec.size() - 1];
        }
    }
}

// Returns pointer to a node with the data
template <typename T>
Node<T>* CompleteBTree<T>::find(const T& data) {
    for(Node<T>* ptr : treeVec) {
        if(ptr != nullptr && ptr->data == data) return ptr;
    }
    // If a pointer was not found in the array, return null;
    return nullptr;
}


// BINARY TREE
template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

// Iterative implementation of insert
template <typename T>
void BinaryTree<T>::insert(const T& data) {
 
    Node<T>* newNode = new Node<T>(data);

    // Base case, no root
    if(root == nullptr) {
        root = newNode;
    }

    // If the data is in root, do nothing
    else if(root->data == data) delete newNode;

    else if(data > root->data) {
        if(root->right == nullptr) root->right = newNode;
        rightTree.insert(newNode);
    }
    
    else {
        if(root->left == nullptr) root->left = newNode;
        leftTree.insert(newNode);
    }
} // insert

template <typename T>
Node<T>* BinaryTree<T>::find(const T& data) {
    if(root == nullptr)         return nullptr;
    else if(data == root->data) return root;
    else if(data > root->data)  return rightTree.find(data);
    else                        return leftTree.find(data);
}

template <typename T>
void BinaryTree<T>::print() {
    print(root);
}

template <typename T>
void BinaryTree<T>::print(const Node<T>* node) {

    if(node != nullptr) {
        std::cout << "node " << node->data << ", ";

        if(node->left != nullptr) 
            std::cout << "left->" << node->left->data << " ";
        if(node->right != nullptr) 
            std::cout << "right->" << node->right->data << " ";

        std::cout << std::endl;

        if(node->left  != nullptr) print(node->left);
        if(node->right != nullptr) print(node->right);
    }
    else std::cout << "empty\n";
}


#endif
