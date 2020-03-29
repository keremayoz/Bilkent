/**
 * Title: Heaps and AVL Trees
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 3
 * Description: Analyzes the performances of the array based and pointer based implementations of the bst
 * Also it analyzes the different types of number insertions to the given bst. Pointer based implementation is used there.
 */

#ifndef analysis_h
#define analysis_h

#include <stdio.h>
#include "AVLTree.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
using namespace std;

class Analysis {
public:
    //Functions
    void heightAnalysis();
    
    //Helper functions
    void performance(int size, int &height, int &height2, int &height3);
};


#endif /* analysis_h */
