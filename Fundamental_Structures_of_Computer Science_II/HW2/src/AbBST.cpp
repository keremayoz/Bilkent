/**
 * Title: Binary Search Trees
 * Author: Kerem Ayoz
 * ID: 21501569
 * Section: 1
 * Assignment: 2
 * Description: Implemented functions of AbBST.h
 */

#include "AbBST.h"
#include <iostream>
#include <algorithm>

using namespace std;

AbBST::AbBST() {
	arraySize = 2;
	tree = new AbBinaryNode[arraySize];
}

AbBST::AbBST(const AbBST& copied) {
	arraySize = copied.arraySize;
	for (int i = 0; i < arraySize; i++)
		tree[i] = copied.tree[i];
}

AbBST::~AbBST() {
	delete[]tree;
}

void AbBST::insert(int val) {
	//Size is not enough
	if (tree[arraySize - 1].item != 0) {
		AbBinaryNode *temp = new AbBinaryNode[arraySize*2];
		for (int i = 0; i < arraySize; i++)
			temp[i] = tree[i];
		delete []tree;
		tree = temp;
		arraySize *= 2;
	}
	//Insert new item to the end of the list and store index in ind
	int ind;
	for (ind = 0; ind < arraySize; ind++)
		if (tree[ind].item == 0) {
			tree[ind].item = val;
			break;
		}
	//Manipulate the related parent's pointers, which means it finds where new element should be inserted
	insertPos(val,ind,0);
}

int AbBST::getHeight() {
	return getHeight(0); //Root is always 0 because we will not remove any element
}

//Recursively calculate the height
int AbBST::getHeight(int root) {
	if (root == -1)
		return 0;
	return max(getHeight(tree[root].leftChildPtr), getHeight(tree[root].rightChildPtr)) + 1;
}

//Helper method for insertion
void AbBST::insertPos(int val, int ind, int root) {
	if (val < tree[root].item) {
		if (tree[root].leftChildPtr == -1)
			tree[root].leftChildPtr = ind;
		else
			insertPos(val, ind, tree[root].leftChildPtr);
	}
	else if (val > tree[root].item) {
		if (tree[root].rightChildPtr == -1)
			tree[root].rightChildPtr = ind;
		else
			insertPos(val, ind, tree[root].rightChildPtr);
	}
	
}
