/**
 * Title: Heaps and AVL Trees
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 3
 * Header file for the min heap implementation
 * It contains function signatures and data members
 */

#ifndef MinHeap_h
#define MinHeap_h

class MinHeap {
public:
    MinHeap(); // Constructor
    ~MinHeap(); // Destructor
    MinHeap(const MinHeap &copied); // Copy Constructor

    void insert(int val); // inserts an element into heap
    int getMin(); // retrieves maximum element
    int removeMin(); // retrieves and removes the maximum element
    int getSize(); // returns the number of elements in heap
    
    //Helper functions
    void heapRebuild(int root);
    bool heapIsEmpty() const ;
    
    //Data Members
    int *heap; // Dynamic array to hold elements
    int size; // Size of the heap
    int elementCount; // # of elements
};

#endif /* MinHeap_h */

