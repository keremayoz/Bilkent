/**
 * Title: Binary Search Trees
 * Author: Kerem Ayoz
 * ID: 21501569
 * Section: 1
 * Assignment: 2
 * Description: Implemented the functions in AbBinaryNode.h
 */

#include "AbBinaryNode.h"

AbBinaryNode::AbBinaryNode() {
	item = 0;
	leftChildPtr = -1;
	rightChildPtr = -1;
}

AbBinaryNode::AbBinaryNode(const AbBinaryNode& copied) {
	item = copied.item;
	leftChildPtr = copied.leftChildPtr;
	rightChildPtr = copied.rightChildPtr;
}

AbBinaryNode::~AbBinaryNode() {

}
