/**
 * Title: Heaps and AVL Trees
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 3
 * Class that implements a min heap data structure.
 * Any given node's value is always less than its children.
 * Constructors, insert, getSize and getMin functions are implemented.
 */

#include <stdio.h>
#include <iostream>
#include "MinHeap.h"

//Constructor for the MinHeap
MinHeap::MinHeap() {
    heap = new int[1];
    size = 1;
    elementCount = 0;
}

//Destructor for the MaxHeap
MinHeap::~MinHeap() {
    delete []heap;
}

//Copy Constructor for the MaxHeap
MinHeap::MinHeap(const MinHeap &copied) {
    //If size of the copied is 0, delete the heap
    if (copied.size == 0) {
        delete []heap;
        heap =  NULL;
        size = 0;
        elementCount = 0;
    }
    //If sizes are not equal, delete the old one and assign the new size and element count
    else {
        if (copied.size != size) {
            delete []heap;
            size = copied.size;
            elementCount = copied.elementCount;
        }
        //Copy elements one-by-one
        for (int i = 0; i < elementCount; i++)
            heap[i] = copied.heap[i];
    }
}

/*Inserts element to the heap
 Algorithm:
 1-) Check the dynamic array, if it is full double the size
 2-) Insert element into the last available position into the array
 3-) Start from the inserted element, trickle up if it is necessary to obey the rule of min heap
 4-) Increment the elementCount
 */
void MinHeap::insert(int val) {
    //If heap is full, double the size and deep copy the items
    if (elementCount == size) {
        int *temp = new int[size*2];
        for (int i = 0; i < size; i++) {
            temp[i] = heap[i];
        }
        delete []heap;
        heap = NULL;
        heap = temp;
        size *= 2; //Double the size
    }
    //Insert the item
    heap[elementCount] = val;
    //Trickle up the element
    int place = elementCount;
    int parent = (place - 1)/2;
    while ( (place >= 0) && (heap[place] < heap[parent]) ) {
        int temp = heap[parent];
        heap[parent] = heap[place];
        heap[place] = temp;
        
        place = parent;
        parent = (place - 1)/2;
    }
    ++elementCount;
}

//Returns the minimum element, which is simply the root of the min-heap
int MinHeap::getMin() {
    return heap[0];
}

/*Removes the min, which means delete the root from the min-heap
 Algorithm:
 1-) If heap is not empty, assign the root as the rightmost leaf of the heap
 2-) Call heapRebuild function from the root because root is changed know
 */
int MinHeap::removeMin() {
    int min = -1;
    if (!heapIsEmpty()) {
        min = heap[0];
        heap[0] = heap[--elementCount];
        heapRebuild(0);
    }
    return min;
}

//Returns the # of elements, stored in the elementCount
int MinHeap::getSize() {
    return elementCount;
}

/*HeapRebuild function
 Algorithm:
 1-) Find the smaller child of the root, if any
 2-) If root’s item is larger than smaller child, swap values
 3-) Call function recursively, this time the child as a parameter
 */
void MinHeap::heapRebuild(int root) {
    int child = 2 * root + 2;     // index of root's left child, if any
    if ( child < size ) {
        // root is not a leaf so that it has a left child
        int leftChild = child - 1;     // index of a right child, if any
        // If root has left child, find smaller child
        if ( (leftChild< size) &&
            (heap[leftChild] < heap[child]) )
            child = leftChild;     // index of larger child
        
        // If root’s item is smaller than larger child, swap values
        if ( heap[root] > heap[child] ) {
            int temp = heap[root];
            heap[root] = heap[child];
            heap[child] = temp;
            
            // transform the new subtree into a heap
            heapRebuild(child);
        }
    }
}

//Checks whether the heap is empty or not
bool MinHeap::heapIsEmpty() const {
    return (size == 0);
}

