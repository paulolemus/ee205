/* File: BinaryTree.h
 * Name: Paulo Lemus
 * Date: 3/23/2017
 */

#ifndef EE_LAB11_BINARYTREE_H_
#define EE_LAB11_BINARYTREE_H_



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


    // private recursive assistance functions
    void insert_r_assist(const T& data, Node<T>*& ptrptr);

public:
    BinaryTree();

    void insert  (const T& data);
    void insert_r(const T& data);
};

////////////////////////
//   IMPLEMENTATION   //
////////////////////////

template <typename T>
Node<T>::Node(const T& data) : 
    data(data), 
    left(nullptr), 
    right(nullptr) {}

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

// Iterative implementation of insert
template <typename T>
void BinaryTree<T>::insert(const T& data) {
    
    // Base case, no root
    if(root == nullptr) {
        root = new Node<T>(data);
    }

    // If the data is in root, do nothing
    else if(root->data == data);

    // otherwise traverse tree to insert
    else {

        // Decide which side of tree data should be on
        bool inserted = false;
        Node<T>* ptr  = root;
        if(data > ptr->data) ptr = ptr->right;
        else                 ptr = ptr->left;

        // Do a check to see if current node is null
        if(ptr == nullptr) {
            ptr = new Node<T>(data);
            inserted = true;
        }

        while(!inserted) {

            // place left if possible
            if(ptr->left == nullptr) {
                ptr->left = new Node<T>(data);
                inserted = true;
            }
            // otherwise, place right if possible
            else if(ptr->right == nullptr) {
                ptr->right = new Node<T>(data);
                inserted = true;
            }
            // Otherwise, move to child node with an open slot
            else {
                if(!ptr->left->left || !ptr->left->right)
                    ptr = ptr->left;
                else if(!ptr->right->left || !ptr->right->right)
                    ptr = ptr->right;
                else ptr = ptr->left;
            }

        } // while
    } // else
} // insert

// Recursive implementation of insert
template <typename T>
void BinaryTree<T>::insert_r(const T& data) {

    if(root == nullptr) root = new Node<T>(data);
    else if(data == root->data);
    else if(data > root->data) insert_r_assist(data, root->right);
    else                       insert_r_assist(data, root->left);
}
template <typename T>
void BinaryTree<T>::insert_r_assist(const T& data, Node<T>*& root) {

    // If we have reached a nullptr, we have not found the data
    // so add a new node with the data
    if(root == nullptr) root = new Node<T>(data);

    // Do nothing if the data exists in tree
    else if(data == root->data);

    // Move to right node if data is greater that current node data
    else if(data > root->data) insert_r_assist(data, root->right);

    // Otherwise move to the left
    else insert_r_assist(data, root->left);
}

#endif
