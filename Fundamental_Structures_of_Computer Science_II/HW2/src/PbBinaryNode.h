/**
 * Title: Binary Search Trees
 * Author: Kerem Ayoz
 * ID: 21501569
 * Section: 1
 * Assignment: 2
 * Description: Node class for the pointer based implementation of binary search tree
 */

#include <iostream>

class PbBinaryNode {
private:

	//Constructors and destructor
	PbBinaryNode();
	PbBinaryNode(int item);
	PbBinaryNode(const PbBinaryNode& copied);
	~PbBinaryNode();

	//Variables
	int item;
	PbBinaryNode *leftChildPtr;
	PbBinaryNode *rightChildPtr;

	friend class PbBST;
};
