/**
 * Title: Binary Search Trees
 * Author: Kerem Ayoz
 * ID: 21501569
 * Section: 1
 * Assignment: 2
 * Description: Main function for testing the classes
 * Insertion, validation of tree, finding median operation are tested. 
 * Performance analysis of different bst implementations are done here.
 * Also performance analysis of different number insertions are done here.
 */

#include <iostream>
using namespace std;
#include "analysis.h"

int main() {
	PbBST pTree;

	//Insertion
	pTree.insert(40);
	pTree.insert(50);
	pTree.insert(45);
	pTree.insert(30);
	pTree.insert(60);
	pTree.insert(55);
    pTree.insert(20);
    pTree.insert(35);
    pTree.insert(10);
    pTree.insert(25);

	//Validation
    cout << "The tree is (1: valid, 0: not valid) : " << pTree.isValidBST() << endl << endl;

	//Finding median
    cout << "The median is: " << pTree.medianOfBST() << endl << endl;

	//Performance analysis
    Analysis an;
    an.performanceAnalysis();
    cout << endl;
    an.heightAnalysis();
    
	return 0;
}
