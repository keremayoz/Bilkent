/**
 * Title: Heaps and AVL Trees
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 3
 * Description: description of your code */


#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "QuickMedian.h"
#include "AVLTree.h"
#include "analysis.h"
using namespace std;

int main() {
    
    //Max-Heap
    MaxHeap max;
    max.insert(40);
    max.insert(50);
    max.insert(45);
    max.insert(30);
    max.insert(60);
    max.insert(55);
    max.insert(20);
    max.insert(35);
    max.insert(10);
    max.insert(25);
    cout << "The maximum value is: " << max.getMax() << endl;
    cout << "The size is: " << max.getSize() << endl << endl;
    
    //Min-Heap
    MinHeap min;
    min.insert(40);
    min.insert(50);
    min.insert(45);
    min.insert(30);
    min.insert(60);
    min.insert(55);
    min.insert(20);
    min.insert(35);
    min.insert(10);
    min.insert(25);
    cout << "The minimum value is: " << min.getMin() << endl;
    cout << "The size is: " << min.getSize() << endl << endl;
    
    //Quick Median
    QuickMedian k;
    k.insert(10);
    k.insert(40);
    k.insert(30);
    k.insert(50);
    k.insert(70);
    k.insert(60);
    k.insert(20);
    k.insert(90);
    k.insert(100);
    k.insert(110);
    k.insert(0);
    k.insert(25);
    k.insert(123);
    k.insert(11);
    k.insert(200);
    cout << "Median is : " << k.getMedian() << endl << endl;
    
    //AVL Tree
    Analysis analysis;
    analysis.heightAnalysis();
    return 0;
}

