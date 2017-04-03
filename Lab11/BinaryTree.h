/* File: BinaryTree.h
 * Name: Paulo Lemus
 * Date: 3/23/2017
 */

#ifndef EE_LAB11_BINARYTREE_H_
#define EE_LAB11_BINARYTREE_H_

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
    void insert(const T& data);
};

template <typename T>
Node<T>::Node(const T& data) : 
    data(data), 
    left(nullptr), 
    right(nullptr) {}

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}
template <typename T>
void BinaryTree<T>::insert(const T& data) {
    if(root == nullptr) {
        root = new Node<T>(data);
    }
    else {
        // TODO: Finish this
    }
}   

#endif
