/**
 * Title: Binary Search Trees
 * Author: Kerem Ayoz
 * ID: 21501569
 * Section: 1
 * Assignment: 2
 * Description: Pointer base binary search tree
 * Functions for insertion to the tree, validation of the tree, getting height of the tree and finding the median of the tree.
 */

#include "PbBinaryNode.h"

class PbBST {
public:
	//Constructors and destructor
	PbBST();
	PbBST(const PbBST & copied);
	~PbBST();

	//Member functions
	void insert(int val); 
	int getHeight();
	bool isValidBST();
	int medianOfBST();

	//Helper functions
	int countNodes(PbBinaryNode * root);
	void inorderMedianFind(PbBinaryNode *root, int &counter, int nodeCount, int &median);
	bool isValidBST(PbBinaryNode * root);
	int getHeight(PbBinaryNode * root);
	void insertToTree(int val, PbBinaryNode * root);
	void deleteTree(PbBinaryNode * root);
	PbBinaryNode* copyTree(PbBinaryNode * root);

	//Data members
	PbBinaryNode *root;

};

