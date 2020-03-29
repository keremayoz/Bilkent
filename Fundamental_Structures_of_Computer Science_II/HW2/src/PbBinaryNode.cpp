/**
 * Title: Binary Search Trees
 * Author: Kerem Ayoz
 * ID: 21501569
 * Section: 1
 * Assignment: 2
 * Description: Implemented the functions in PbBinaryNode.h
 */

#include "PbBinaryNode.h"

PbBinaryNode::PbBinaryNode() {
	item = 0;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}

PbBinaryNode::PbBinaryNode(int item) {
	this->item = item;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}

PbBinaryNode::PbBinaryNode(const PbBinaryNode & copied) {

}

PbBinaryNode::~PbBinaryNode() {

}
