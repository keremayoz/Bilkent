/**
 * Title: Binary Search Trees
 * Author: Kerem Ayoz
 * ID: 21501569
 * Section: 1
 * Assignment: 2
 * Description: Array based implementation of binary search tree
 */

#include "AbBinaryNode.h"
#include <iostream>

class AbBST {
public:
	//Constructors and destructor
	AbBST();
	AbBST(const AbBST& copied);
	~AbBST();

	//Methods
	void insert(int val); 
	int getHeight();

	//Helper functions
	void insertPos(int value, int ind, int root);
	int getHeight(int root);

	//Variables
	AbBinaryNode *tree;
	int arraySize;
};

