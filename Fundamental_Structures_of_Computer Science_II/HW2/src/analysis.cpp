/**
 * Title: Binary Search Trees
 * Author: Kerem Ayoz
 * ID: 21501569
 * Section: 1
 * Assignment: 2
 * Description: Implemented the functions in analysis.h
 */

#include "analysis.h"

void Analysis:: performanceAnalysis() {
    cout << "Part e - Performance analysis of BST implementations" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Array Size Array Based Pointer Based" << endl;
    cout << "----------------------------------------------------------" << endl;
    double duration1, duration2;
    for (int i = 2000; i < 20001; i+=2000) {
        performance(i, duration1, duration2);
        cout << i << "    " << duration2 << " ms    " << duration1 << " ms"<< endl;
    }
}

//Helper function for pbbst and abbst analysis
void Analysis::performance(int size, double &duration1, double &duration2) {
    PbBST pTree;
    AbBST aTree;
    
    double start1 = clock();
    for (int i = 0; i < size; i++) {
        int k = rand();
        pTree.insert(k);
    }
    duration1 = (clock() - start1) / (double) CLOCKS_PER_SEC;
    
    double start2 = clock();
    for (int i = 0; i < size; i++) {
        int l = rand();
        aTree.insert(l);
    }
    duration2 = (clock() - start2) / (double) CLOCKS_PER_SEC;
}


void Analysis::heightAnalysis() {
    cout << "Part f - Analysis of BST height" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Array Size Random Numbers Ascending Numbers" << endl;
    cout << "----------------------------------------------------------" << endl;
    int height1, height2;
    for (int i = 2000; i < 20001; i+=2000) {
        performance(i, height1, height2);
        cout << i << "    " << height1 << "     " << height2 << " "<< endl;
    }

}

//Helper function for height performance
void Analysis::performance(int size, int &height, int &height2) {
    PbBST pTree;
    PbBST pTree2;
    
    for (int i = 0; i < size; i++) {
        int k = rand();
        pTree.insert(k);
    }
    height = pTree.getHeight();
    
    for (int i = 0; i < size; i++) {
        pTree2.insert(i);
    }
    height2 = pTree2.getHeight();
}
