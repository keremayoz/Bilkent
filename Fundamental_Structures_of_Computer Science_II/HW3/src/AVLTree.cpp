/**
 * Title: Heaps and AVL Trees
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 3
 * Class that implements the constructors, destructor, insert, getHeight and also the helper functions of AVLTree.h
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include "AVLTree.h"
using namespace std;

//Constructor for AVL Tree
AVLTree::AVLTree() {
    root = NULL;
}

//Destructor for AVL Tree
AVLTree::~AVLTree() {
    deleteTree(root);
}

//Copy Constructor for AVL Tree
AVLTree::AVLTree(const AVLTree &copied) {
    if (copied.root != NULL) {
        root = copyTree(copied.root);
    }
    else
        root = NULL;
}

//Insert function that calls recursive helper function
void AVLTree::insert(int val) {
    insert(root,val);
}

/*Helper insert function to add a new element to the AVL Tree
 Algorithm:
    1-)  Insert the element as same as the binary search tree insertion
    2-)  Check the heights of both subtree's to determine which type of insertion is done
    3-)  case1: outside insertion to right subtree of right child           -->> rotateLeft
    4-)  case2: inside insertion to left subtree of right child             -->> rotateRightLeft
    5-)  case3: outside insertion to left subtree of left child             -->> rotateRight
    6-)  case4: //Case 4: inside insertion to right subtree of left child   -->> rotateLeftRight
 */
void AVLTree::insert(Node *&root, int val) {
    //Insert new item as same as the binary search tree
    if (root == NULL) {
        root = new Node(val);
    }
    else {
        if (val > root->item)
            if (root->right == NULL)
                root->right = new Node(val);
            else
                insert(root->right, val);
        else
            if (root->left == NULL)
                root->left = new Node(val);
            else
                insert(root->left, val);
        
        //Calculate the heights of the both of the subtrees
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        //Right subtree is taller in that cases
        if (rightHeight - leftHeight > 1)
            //Case 1: outside insertion to right subtree of right child
            if (val > root->right->item)
                singleRotateLeft(root);
            //Case 2: inside insertion to left subtree of right child
            else
                doubleRotateRightLeft(root);
        
        //Left subtree is taller in that cases
        else if (leftHeight - rightHeight > 1)
            //Case 3: outside insertion to left subtree of left child
            if (val < root->left->item)
                singleRotateRight(root);
            //Case 4: inside insertion to right subtree of left child
            else
                doubleRotateLeftRight(root);
        else
            return;
    }
}

//Returns the height by using the helper function
int AVLTree::getHeight() {
    return getHeight(root);
}

//Helper function for destructor
void AVLTree::deleteTree(Node *root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

//Helper function for copy construtor
Node* AVLTree::copyTree(Node *root) {
    if (root == NULL)
        return NULL;
    Node *neww = new Node(root->item);
    neww->left = copyTree(root->left);
    neww->right = copyTree(root->right);
    return neww;
}

//Helper function for getHeight, recursively calculates the height
int AVLTree::getHeight(Node *root) {
    if (root == NULL)
        return 0;
    return std::max(getHeight(root->left), getHeight(root->right)) + 1;
}


/***************************************************************
 * SINGLE LEFT ROTATE                                          *
 * ------------------                                          *
 *          k3                               k2                *
 *         /  \                            /    \              *
 *        T1   k2     Left Rotate(k3)     k3     k1            *
 *            /  \   - - - - - - - ->    /  \   /  \           *
 *           T2  k1                     T1  T2 T3  T4          *
 *              /  \                                           *
 *             T3  T4                                          *
 ***************************************************************/
void AVLTree::singleRotateLeft(Node *&parent) {
    Node *temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    parent = temp;
}

/***************************************************************
 * SINGLE RIGHT ROTATE                                         *
 * ------------------                                          *
 *          k3                                      k2         *
 *         /  \                                   /    \       *
 *        k2   T4      Right Rotate (k3)         k1     k3     *
 *       /  \          - - - - - - - - ->       /  \   /  \    *
 *     k1   T3                                 T1  T2 T3  T4   *
 *    /  \                                                     *
 *   T1   T2                                                   *
 ***************************************************************/
void AVLTree::singleRotateRight(Node *&parent) {
    Node *temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    parent = temp;
}

/*********************************************************************************************
 * DOUBTLE LEFT-RIGHT ROTATE                                                                 *
 * -------------------------                                                                 *
 *        k3                                 k3                                   k1         *
 *       /  \                               /  \                                /    \       *
 *      k2  T4      Left Rotate (k2)       k1  T4    Right Rotate(k3)          k2     k3     *
 *     /  \         - - - - - - - - ->    /  \       - - - - - - - ->         /  \   /  \    *
 *    T1   k1                            k2  T3                              T1  T2 T3  T4   *
 *        /  \                          /  \                                                 *
 *       T2   T3                       T1  T2                                                *
 *********************************************************************************************/
void AVLTree::doubleRotateLeftRight(Node *&parent) {
    singleRotateLeft(parent->left);
    singleRotateRight(parent);
}

/*********************************************************************************************
 * DOUBTLE RIGHT-LEFT ROTATE                                                                 *
 * -------------------------                                                                 *
 *         k3                                k3                                   k1         *
 *        /  \                              /  \                                /    \       *
 *       T1   k2     Right Rotate (k2)     T1   k1       Left Rotate(k3)       k3     k2     *
 *           /  \    - - - - - - - - ->        /  \      - - - - - - - ->     /  \   /  \    *
 *          k1  T4                            T2   k2                        T1  T2 T3  T4   *
 *         /  \                                   /  \                                       *
 *        T2  T3                                 T3   T4                                     *
 *********************************************************************************************/
void AVLTree::doubleRotateRightLeft(Node *&parent) {
    singleRotateRight(parent->right);
    singleRotateLeft(parent);
}
