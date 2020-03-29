/**
 * Title: Heaps and AVL Trees
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 3
 * Header file for the AVL Tree implementation
 * It contains constructors, destructor, insert and getHeight functions.
 */

#ifndef AVLTree_h
#define AVLTree_h
#include <stdio.h>
#include <iostream>

struct Node {
    int item;
    Node *left;
    Node *right;
    Node(int val) {
        item = val;
        left = NULL;
        right = NULL;
    }
};

class AVLTree {
public:
    //Constructors and destructor
    AVLTree();
    ~AVLTree();
    AVLTree(const AVLTree &copied);
    
    //Functions
    void insert(int val); // inserts an element into the tree
    int getHeight(); // returns the height of the tree
    
//private:
    //Helper functions
    void insert(Node *&root, int val);
    void deleteTree(Node *root);
    Node* copyTree(Node *root);
    int getHeight(Node *root);
    void insertToTree(int val, Node *root, Node *inserted);
    void isBalanced(Node *root, int val);
    
    //Rotation functions
    void singleRotateLeft(Node *&root);
    void singleRotateRight(Node *&root);
    void doubleRotateLeftRight(Node *&root);
    void doubleRotateRightLeft(Node *&root);
    
    //Data Members
    Node *root;
};

#endif /* AVLTree_h */
