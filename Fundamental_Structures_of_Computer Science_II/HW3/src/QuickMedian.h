/**
 * Title: Heaps and AVL Trees
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 3
 * Header file for the quick median implementation
 * It contains function signatures and data members
 */

#ifndef QuickMedian_h
#define QuickMedian_h
#include "MaxHeap.h"
#include "MinHeap.h"

class QuickMedian {
public: 
    QuickMedian(); // Constructor
    ~QuickMedian(); // Destructor
    QuickMedian(const QuickMedian &copied); // Copy Constructor
    
    void insert(int val); // inserts an element into QuickMedian
    double getMedian(); // returns the median of elements

    //Data Members
    MaxHeap max; // Max heap
    MinHeap min; // Min heap
    int elementCount; // # of elements
};

#endif /* QuickMedian_h */
