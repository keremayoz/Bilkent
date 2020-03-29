/**
 * Title: Binary Search Trees
 * Author: Kerem Ayoz
 * ID: 21501569
 * Section: 1
 * Assignment: 2
 * Description: Analyzes the performances of the array based and pointer based implementations of the bst
 * Also it analyzes the different types of number insertions to the given bst. Pointer based implementation is used there.
 */

#include <stdio.h>
#include "PbBST.h"
#include "AbBST.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h> 
using namespace std;

class Analysis {
public:
	//Functions
    void performanceAnalysis();
    void heightAnalysis();
	
	//Helper functions
	void performance(int size, double &duration1, double &duration2);
	void performance(int size, int &height, int &height2);
};
