/**
 * Title: Heaps and AVL Trees
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 3
 * Description: Implemented the functions in analysis.h
 */

#include <stdio.h>
#include "analysis.h"

void Analysis::heightAnalysis() {
    cout << "Part e - Height analysis of AVL trees" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Array Size || Random Numbers | Ascending Numbers | Descending Numbers" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    int height1, height2, height3;
    for (int i = 1000; i < 20001; i+=1000) {
        performance(i, height1, height2, height3);
        cout << i << "               " << height1 << "                 " << height2 << "                " << height3 << endl;
    }
    
}

//Helper function for height performance
void Analysis::performance(int size, int &height, int &height2, int &height3) {
    AVLTree pTree;
    AVLTree pTree2;
    AVLTree pTree3;
    
    for (int i = 0; i < size; i++) {
        int k = rand();
        pTree.insert(k);
    }
    height = pTree.getHeight();
    
    for (int i = 0; i < size; i++) {
        pTree2.insert(i);
    }
    height2 = pTree2.getHeight();
    
    for (int i = size; i > 0; i--) {
        pTree3.insert(i);
    }
    height3 = pTree3.getHeight();
}
