/**
 * Title: Heaps and AVL Trees
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 3
 * Class that implements a Quick Median data structure.
 * It uses both min heap and max heap to store the values.
 * Complexity of the insertion operation is O(logn), getting median is O(1).
 * Constructors, insert and getMedian functions are implemented.
 */

#include <stdio.h>
#include "QuickMedian.h"

//Constructor of QuickMedian
QuickMedian::QuickMedian() {
    elementCount = 0;
}

//Destructor of QUickMedian
QuickMedian::~QuickMedian() {
}

//Copy constructor of QuickMedian, only uses the heap's copy constructors
QuickMedian::QuickMedian(const QuickMedian &copied) {
    max = MaxHeap(copied.max);
    min = MinHeap(copied.min);
}

/*Inserts new data to QuickMedian
 Algorithm:
 1-) Insert the first 2 elements, bigger one goes to max-heap, smaller goes to min-heap
 2-) If the value of the next inserted element is less than the max-heap's root, insert it into the max-heap
 3-) Else insert the new element into the min heap
 4-) After the insertion we need to balance the heaps
    4.1- Remove the root of the bigger sized heap
    4.2- And add that element to the other heap
 Note: (With that algorithm we guarantee that heap with more element's root is the median)
*/
void QuickMedian::insert(int val) {
    //Insert first 2 elements
    if (elementCount == 0)
        min.insert(val);
    
    else if (elementCount == 1) {
        if (min.getMin() > val) {
            int temp = min.removeMin();
            min.insert(val);
            max.insert(temp);
        }
        else
            max.insert(val);
    }
    //Inserting 3th or more element to the QuickMedian
    else {
        //Insert to max if it is less than the maxHeap's root
        if (val < max.getMax())
            max.insert(val);
        //Insert to min if it is greater than the minHeap's root
        else
            min.insert(val);
    
       //Balance the heaps
       if (min.getSize() + 1 < max.getSize()) {
            int temp = max.removeMax();
            min.insert(temp);
        }
       else if (min.getSize() > max.getSize() + 1){
           int temp = min.removeMin();
           max.insert(temp);
       }
    }
    ++elementCount;
}

/*Returns the median
 Algorithm:
 1-) Remember that with that algorithm in the insertion, we have guaranteed that heap with more element's root is the median
 2-) Determine which heap has the more elements, return its root as median
 */
double QuickMedian::getMedian() {
    if (min.getSize() == max.getSize())
        return (min.getMin() + max.getMax()) / 2;
    else if (min.getSize() > max.getSize()) 
        return min.getMin();
    else
        return max.getMax();
}
