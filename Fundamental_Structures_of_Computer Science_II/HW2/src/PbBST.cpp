/**
 * Title: Binary Search Trees
 * Author: Kerem Ayoz
 * ID: 21501569
 * Section: 1
 * Assignment: 2
 * Description: Implemented the functions of pointer based binary search tree
 */

#include "PbBST.h"
#include <algorithm>
using namespace std;

PbBST::PbBST() {
	root = NULL;
}

PbBST::PbBST(const PbBST & copied) {
	if (copied.root != NULL) {
		root = copyTree(copied.root);
	}
	else
		root = NULL;
}

PbBST::~PbBST() {
	deleteTree(root);
}

void PbBST::insert(int val) {
	if (root == NULL)
		root = new PbBinaryNode(val);
	else 
		insertToTree(val,root);
}

int PbBST::getHeight() {
	return getHeight(root);
}

bool PbBST::isValidBST() {
	return isValidBST(root);
}

int PbBST::medianOfBST() {
	//Checking the number of elements, whether it is odd or even
    int medianIndex = countNodes(root);
    if (medianIndex % 2 == 1)
        medianIndex = medianIndex / 2 + 1;
    else
        medianIndex /= 2;
    int c = 0;
    int median;
	//Finding median by inorder traversing
    inorderMedianFind(root, c, medianIndex, median);
    return median;
}


//Median helper method, it traverse inorderly and returns the nodeCount th element, median. 
void PbBST::inorderMedianFind(PbBinaryNode *root, int &counter, int nodeCount, int &median) {
    if (root != NULL) {
        inorderMedianFind(root->leftChildPtr, counter, nodeCount, median);
        counter++;
        if (counter == nodeCount)
            median = root->item;
        inorderMedianFind(root->rightChildPtr, counter, nodeCount, median);
    }
}


//Counts the nodes in tree
int PbBST::countNodes(PbBinaryNode *root) {
	if (root == NULL)
		return 0;
	return 1 + countNodes(root->rightChildPtr) + countNodes(root->leftChildPtr);
}


//Helper function for isValid
bool PbBST::isValidBST(PbBinaryNode *root) {
	if (root == NULL)
		return true;
	else {
		if ((root->leftChildPtr != NULL && root->item < root->leftChildPtr->item) || (root->rightChildPtr != NULL && root->item > root->rightChildPtr->item))
			return false;
		else
			return isValidBST(root->leftChildPtr) && isValidBST(root->rightChildPtr);
	}
}

//Helper function for getHeight
int PbBST::getHeight(PbBinaryNode *root) {
	if (root == NULL)
		return 0;
	return max(getHeight(root->leftChildPtr), getHeight(root->rightChildPtr)) + 1;
}

//Helper function for insert
void PbBST::insertToTree(int val, PbBinaryNode *root) {
	if (root != NULL) {
		//To the left
		if (val < root->item) {
			if (root->leftChildPtr == NULL)
				root->leftChildPtr = new PbBinaryNode(val);
			else
				insertToTree(val, root->leftChildPtr);
		}
		//To the right
		if (val > root->item) {
			if (root->rightChildPtr == NULL)
				root->rightChildPtr = new PbBinaryNode(val);
			else
				insertToTree(val, root->rightChildPtr);
		}
	}
}

//Helper function for destructor
void PbBST::deleteTree(PbBinaryNode *root) {
	if (root != NULL) {
		deleteTree(root->leftChildPtr);
		deleteTree(root->rightChildPtr);
		delete root;
	}
}

//Helper function for copy construtor
PbBinaryNode* PbBST::copyTree(PbBinaryNode *root) {
	if (root == NULL)
		return NULL;
	PbBinaryNode *neww = new PbBinaryNode();
	neww->item = root->item;
	neww->leftChildPtr = copyTree(root->leftChildPtr);
	neww->rightChildPtr = copyTree(root->rightChildPtr);
	return neww;
}
