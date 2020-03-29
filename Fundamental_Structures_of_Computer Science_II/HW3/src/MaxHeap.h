/**
 * Title: Heaps and AVL Trees
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 3
 * Header file for the max heap implementation
 * It contains function signatures and data members
 */

#ifndef MaxHeap_h
#define MaxHeap_h

class MaxHeap {
public:
    MaxHeap(); // Constructor
    ~MaxHeap(); // Destructor
    MaxHeap(const MaxHeap &copied); // Copy Construtor
    
    void insert(int val); // inserts an element into heap
    int getMax(); // retrieves maximum element
    int removeMax(); // retrieves and removes the maximum element
    int getSize(); // returns the number of elements in heap
    
    //Helper functions
    void heapRebuild(int root);
    bool heapIsEmpty() const ;
    
    //Data Members
    int *heap; // Dynamic array to hold elements
    int size; // Size of the heap
    int elementCount; // # of elements
};

#endif /* MaxHeap_h */
