/**
 * Title: Binary Search Trees
 * Author: Kerem Ayoz
 * ID: 21501569
 * Section: 1
 * Assignment: 2
 * Description: Node class for array based implementation of the binary search tree
 */

#include <iostream>

class AbBinaryNode {
private:

	//Constructors and destructor
	AbBinaryNode();
	AbBinaryNode(const AbBinaryNode& copied);
	~AbBinaryNode();	

	//Variables
	int item;
	int leftChildPtr;
	int rightChildPtr;

	friend class AbBST;
};
