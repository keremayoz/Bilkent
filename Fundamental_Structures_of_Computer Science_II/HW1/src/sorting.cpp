/**
 * Title: Algorithm Efficiency and Sorting * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 1
 * Description: description of your code */

#include <stdio.h>
#include <iostream>
#include "sorting.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void swap (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void partition(int *theArray, int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
    int pivot = theArray[last];
    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown
    
    // move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last; ++firstUnknown) {
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot
        
        // move item from unknown to proper region
        compCount++;
        if (theArray[firstUnknown] < pivot) {
            ++lastS1;  moveCount+=3;
            swap(theArray[firstUnknown], theArray[lastS1]);
        }
    }
    // place pivot in proper position and mark its location
    swap(theArray[first], theArray[lastS1]); moveCount+=3;
    pivotIndex = lastS1;
}

void quicksort(int *theArray, int first, int last, int &comp, int &move) {
    int pivotIndex;
    
    if (first < last) {
        
        // create the partition: S1, pivot, S2
        partition(theArray, first, last, pivotIndex, comp, move);
        
        // sort regions S1 and S2
        quicksort(theArray, first, pivotIndex-1, comp, move);
        quicksort(theArray, pivotIndex+1, last, comp, move);
    }
}



void merge(int *theArray, int first, int mid, int last, int &comp, int &move) {
    int tempArray[1100000]; 	// temporary array
    int first1 = first; 	// beginning of first subarray
    int last1 = mid; 		// end of first subarray
    int first2 = mid + 1;	// beginning of second subarray
    int last2 = last;		// end of second subarray
    int index = first1; // next available location in tempArray

    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        if (theArray[first1] < theArray[first2]) {
            tempArray[index] = theArray[first1];
            ++first1; comp++; move++;
        }
        else {
            tempArray[index] = theArray[first2];
            ++first2; move++; comp++;
        }
    }
    for (; first1 <= last1; ++first1, ++index) {
        tempArray[index] = theArray[first1];
        move++;
    }
    for (; first2 <= last2; ++first2, ++index) {
        tempArray[index] = theArray[first2];
        move++;
    }
    for (index = first; index <= last; ++index) {
        theArray[index] = tempArray[index];
        move++;
    }
}



void mergesort(int *theArray, int first, int last, int &comp, int &move) {
    if (first < last) {
        
        int mid = (first + last)/2; 	// index of midpoint
        
        mergesort(theArray, first, mid, comp, move);

        mergesort(theArray, mid+1, last, comp, move);
        // merge the two halves
        merge(theArray, first, mid, last, comp, move);
    }
}

void insertionSort(int *arr, int size, int &compCount, int &moveCount) {
    for (int unsorted = 1; unsorted < size; ++unsorted) {
        int nextItem = arr[unsorted];
        int loc = unsorted;
        
        for (  ;(loc > 0) && (arr[loc-1] > nextItem); --loc) {
            arr[loc] = arr[loc-1];
            moveCount++; compCount++;
        }
        compCount++;
        arr[loc] = nextItem; moveCount++;
    }
}

void mergeSort(int *arr, int size, int &compCount, int &moveCount) {
    mergesort(arr, 0, size - 1, compCount, moveCount);
}

void quickSort(int *arr, int size, int &compCount, int &moveCount) {
    quicksort(arr, 0, size-1, compCount, moveCount);
}

void performanceRandom(int size, int &comp1,
                       int &move1, int &comp2, int &move2, int &comp3, int &move3,
                       double &duration1, double &duration2, double &duration3) {
    int arr1[size];
    int arr2[size];
    int arr3[size];
    
    for (int i = 0; i < size; i++) {
        arr1[i] = rand();
        arr2[i] = rand();
        arr3[i] = rand();
    }
    
    clock_t start1, start2, start3;

    start1 = clock();
    insertionSort(arr1, size, comp1, move1);
    duration1 = (clock() - start1) / (double) CLOCKS_PER_SEC;
    
    start2 = clock();
    mergeSort(arr2, size, comp2, move2);
    duration2 = (clock() - start2) / (double) CLOCKS_PER_SEC;
    
    start3 = clock();
    quickSort(arr3, size, comp3, move3);
    duration3 = (clock() - start3) / (double) CLOCKS_PER_SEC;
}

void performanceAscending(int size, int &comp1,
                          int &move1, int &comp2, int &move2, int &comp3, int &move3,
                          double &duration1, double &duration2, double &duration3) {
    int arr1[size];
    int arr2[size];
    int arr3[size];
    
    for (int i = 0; i < size; i++) {
        arr1[i] = i;
        arr2[i] = i;
        arr3[i] = i;
    }
    
    clock_t start1, start2, start3;
    
    start1 = clock();
    insertionSort(arr1, size, comp1, move1);
    duration1 = (clock() - start1) / (double) CLOCKS_PER_SEC;
    
    start2 = clock();
    mergeSort(arr2, size, comp2, move2);
    duration2 = (clock() - start2) / (double) CLOCKS_PER_SEC;
    
    start3 = clock();
    quickSort(arr3, size, comp3, move3);
    duration3 = (clock() - start3) / (double) CLOCKS_PER_SEC;
}

void performanceDescending(int size, int &comp1,
                           int &move1, int &comp2, int &move2, int &comp3, int &move3,
                           double &duration1, double &duration2, double &duration3) {
    int arr1[size];
    int arr2[size];
    int arr3[size];
    
    for (int i = 0; i < size; i++) {
        arr1[i] = size - i;
        arr2[i] = size - i;
        arr3[i] = size - i;
    }
    
    clock_t start1, start2, start3;
    
    start1 = clock();
    insertionSort(arr1, size, comp1, move1);
    duration1 = (clock() - start1) / (double) CLOCKS_PER_SEC;
    
    start2 = clock();
    mergeSort(arr2, size, comp2, move2);
    duration2 = (clock() - start2) / (double) CLOCKS_PER_SEC;
    
    start3 = clock();
    quickSort(arr3, size, comp3, move3);
    duration3 = (clock() - start3) / (double) CLOCKS_PER_SEC;
}

void performanceAnalysis() {
    //Initialising variables
    int comp1,move1,comp2,move2,comp3,move3;
    double duration1, duration2, duration3;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    /* RANDOM INTEGER ARRAY */
    cout << "Part b1 - Performance analysis of random integers array" << endl;
    comp1 = 0; move1 = 0;comp2 = 0;move2 = 0;comp3 = 0;move3 = 0;duration1 = 0; duration2 = 0; duration3 = 0;
    //For 1000 elements
    cout << "----------------------------------------------------------" << endl;
    cout << "Array size: 1000  /   Elapsed Time   compCount   moveCount" << endl;
    performanceRandom(1000, comp1,move1,comp2,move2,comp3,move3,duration1,duration2,duration3);
    cout << "Insertion Sort         " << duration1 << "      " << comp1 << "     " << move1 << endl;
    cout << "Merge Sort             " << duration2 << "       " << comp2 << "   " << move2 << endl;
    cout << "Quick Sort             " << duration3 << "       " << comp3 << "   " << move3 << endl;
    
    comp1 = 0; move1 = 0;comp2 = 0;move2 = 0;comp3 = 0;move3 = 0;duration1 = 0; duration2 = 0; duration3 = 0;
    
    //For 5000 elements
    cout << "----------------------------------------------------------" << endl;
    cout << "Array size: 5000  /   Elapsed Time   compCount   moveCount" << endl;
    performanceRandom(5000, comp1,move1,comp2,move2,comp3,move3,duration1,duration2,duration3);
    cout << "Insertion Sort         " << duration1 << "      " << comp1 << "     " << move1 << endl;
    cout << "Merge Sort             " << duration2 << "       " << comp2 << "   " << move2 << endl;
    cout << "Quick Sort             " << duration3 << "       " << comp3 << "   " << move3 << endl;
    
    comp1 = 0; move1 = 0;comp2 = 0;move2 = 0;comp3 = 0;move3 = 0;duration1 = 0; duration2 = 0; duration3 = 0;
    
    //For 10000 elements
    cout << "----------------------------------------------------------" << endl;
    cout << "Array size: 10000  /   Elapsed Time   compCount   moveCount" << endl;
    performanceRandom(10000, comp1,move1,comp2,move2,comp3,move3,duration1,duration2,duration3);
    cout << "Insertion Sort         " << duration1 << "      " << comp1 << "     " << move1 << endl;
    cout << "Merge Sort             " << duration2 << "       " << comp2 << "   " << move2 << endl;
    cout << "Quick Sort             " << duration3 << "       " << comp3 << "   " << move3 << endl;
    
    comp1 = 0; move1 = 0;comp2 = 0;move2 = 0;comp3 = 0;move3 = 0;duration1 = 0; duration2 = 0; duration3 = 0;
    
    //For 15000 elements
    cout << "----------------------------------------------------------" << endl;
    cout << "Array size: 15000  /   Elapsed Time   compCount   moveCount" << endl;
    performanceRandom(15000, comp1,move1,comp2,move2,comp3,move3,duration1,duration2,duration3);
    cout << "Insertion Sort         " << duration1 << "      " << comp1 << "     " << move1 << endl;
    cout << "Merge Sort             " << duration2 << "       " << comp2 << "   " << move2 << endl;
    cout << "Quick Sort             " << duration3 << "       " << comp3 << "   " << move3 << endl;
    
    comp1 = 0; move1 = 0;comp2 = 0;move2 = 0;comp3 = 0;move3 = 0;duration1 = 0; duration2 = 0; duration3 = 0;
    
    //For 20000 elements
    cout << "----------------------------------------------------------" << endl;
    cout << "Array size: 20000  /   Elapsed Time   compCount   moveCount" << endl;
    performanceRandom(20000, comp1,move1,comp2,move2,comp3,move3,duration1,duration2,duration3);
    cout << "Insertion Sort         " << duration1 << "      " << comp1 << "     " << move1 << endl;
    cout << "Merge Sort             " << duration2 << "       " << comp2 << "   " << move2 << endl;
    cout << "Quick Sort             " << duration3 << "       " << comp3 << "   " << move3 << endl;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    /* ASCENDING INTEGER ARRAY */
    cout << endl << endl << "Part b2 - Performance analysis of ascending integers array" << endl;
    comp1 = 0; move1 = 0;comp2 = 0;move2 = 0;comp3 = 0;move3 = 0;duration1 = 0; duration2 = 0; duration3 = 0;
    //For 1000 elements
    cout << "----------------------------------------------------------" << endl;
    cout << "Array size: 1000  /   Elapsed Time   compCount   moveCount" << endl;
    performanceAscending(1000, comp1,move1,comp2,move2,comp3,move3,duration1,duration2,duration3);
    cout << "Insertion Sort         " << duration1 << "      " << comp1 << "     " << move1 << endl;
    cout << "Merge Sort             " << duration2 << "       " << comp2 << "   " << move2 << endl;
    cout << "Quick Sort             " << duration3 << "       " << comp3 << "   " << move3 << endl;
    
    comp1 = 0; move1 = 0;comp2 = 0;move2 = 0;comp3 = 0;move3 = 0;duration1 = 0; duration2 = 0; duration3 = 0;
    
    //For 5000 elements
    cout << "----------------------------------------------------------" << endl;
    cout << "Array size: 5000  /   Elapsed Time   compCount   moveCount" << endl;
    performanceAscending(5000, comp1,move1,comp2,move2,comp3,move3,duration1,duration2,duration3);
    cout << "Insertion Sort         " << duration1 << "      " << comp1 << "     " << move1 << endl;
    cout << "Merge Sort             " << duration2 << "       " << comp2 << "   " << move2 << endl;
    cout << "Quick Sort             " << duration3 << "       " << comp3 << "   " << move3 << endl;
    
    comp1 = 0; move1 = 0;comp2 = 0;move2 = 0;comp3 = 0;move3 = 0;duration1 = 0; duration2 = 0; duration3 = 0;
    
    //For 10000 elements
    cout << "----------------------------------------------------------" << endl;
    cout << "Array size: 10000  /   Elapsed Time   compCount   moveCount" << endl;
    performanceAscending(10000, comp1,move1,comp2,move2,comp3,move3,duration1,duration2,duration3);
    cout << "Insertion Sort         " << duration1 << "      " << comp1 << "     " << move1 << endl;
    cout << "Merge Sort             " << duration2 << "       " << comp2 << "   " << move2 << endl;
    cout << "Quick Sort             " << duration3 << "       " << comp3 << "   " << move3 << endl;
    
    comp1 = 0; move1 = 0;comp2 = 0;move2 = 0;comp3 = 0;move3 = 0;duration1 = 0; duration2 = 0; duration3 = 0;
    
    //For 15000 elements
    cout << "----------------------------------------------------------" << endl;
    cout << "Array size: 15000  /   Elapsed Time   compCount   moveCount" << endl;
    performanceAscending(15000, comp1,move1,comp2,move2,comp3,move3,duration1,duration2,duration3);
    cout << "Insertion Sort         " << duration1 << "      " << comp1 << "     " << move1 << endl;
    cout << "Merge Sort             " << duration2 << "       " << comp2 << "   " << move2 << endl;
    cout << "Quick Sort             " << duration3 << "       " << comp3 << "   " << move3 << endl;
    
    comp1 = 0; move1 = 0;comp2 = 0;move2 = 0;comp3 = 0;move3 = 0;duration1 = 0; duration2 = 0; duration3 = 0;
    
    //For 20000 elements
    cout << "----------------------------------------------------------" << endl;
    cout << "Array size: 20000  /   Elapsed Time   compCount   moveCount" << endl;
    performanceAscending(20000, comp1,move1,comp2,move2,comp3,move3,duration1,duration2,duration3);
    cout << "Insertion Sort         " << duration1 << "      " << comp1 << "     " << move1 << endl;
    cout << "Merge Sort             " << duration2 << "       " << comp2 << "   " << move2 << endl;
    cout << "Quick Sort             " << duration3 << "       " << comp3 << "   " << move3 << endl;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /* DESCENDING INTEGER ARRAY */
    cout << endl << endl << "Part b3 - Performance analysis of descending integers array" << endl;
    comp1 = 0; move1 = 0;comp2 = 0;move2 = 0;comp3 = 0;move3 = 0;duration1 = 0; duration2 = 0; duration3 = 0;
    //For 1000 elements
    cout << "----------------------------------------------------------" << endl;
    cout << "Array size: 1000  /   Elapsed Time   compCount   moveCount" << endl;
    performanceDescending(1000, comp1,move1,comp2,move2,comp3,move3,duration1,duration2,duration3);
    cout << "Insertion Sort         " << duration1 << "      " << comp1 << "     " << move1 << endl;
    cout << "Merge Sort             " << duration2 << "       " << comp2 << "   " << move2 << endl;
    cout << "Quick Sort             " << duration3 << "       " << comp3 << "   " << move3 << endl;
    
    comp1 = 0; move1 = 0;comp2 = 0;move2 = 0;comp3 = 0;move3 = 0;duration1 = 0; duration2 = 0; duration3 = 0;
    
    //For 5000 elements
    cout << "----------------------------------------------------------" << endl;
    cout << "Array size: 5000  /   Elapsed Time   compCount   moveCount" << endl;
    performanceDescending(5000, comp1,move1,comp2,move2,comp3,move3,duration1,duration2,duration3);
    cout << "Insertion Sort         " << duration1 << "      " << comp1 << "     " << move1 << endl;
    cout << "Merge Sort             " << duration2 << "       " << comp2 << "   " << move2 << endl;
    cout << "Quick Sort             " << duration3 << "       " << comp3 << "   " << move3 << endl;
    
    comp1 = 0; move1 = 0;comp2 = 0;move2 = 0;comp3 = 0;move3 = 0;duration1 = 0; duration2 = 0; duration3 = 0;
    
    //For 10000 elements
    cout << "----------------------------------------------------------" << endl;
    cout << "Array size: 10000  /   Elapsed Time   compCount   moveCount" << endl;
    performanceDescending(10000, comp1,move1,comp2,move2,comp3,move3,duration1,duration2,duration3);
    cout << "Insertion Sort         " << duration1 << "      " << comp1 << "     " << move1 << endl;
    cout << "Merge Sort             " << duration2 << "       " << comp2 << "   " << move2 << endl;
    cout << "Quick Sort             " << duration3 << "       " << comp3 << "   " << move3 << endl;
    
    comp1 = 0; move1 = 0;comp2 = 0;move2 = 0;comp3 = 0;move3 = 0;duration1 = 0; duration2 = 0; duration3 = 0;
    
    //For 15000 elements
    cout << "----------------------------------------------------------" << endl;
    cout << "Array size: 15000  /   Elapsed Time   compCount   moveCount" << endl;
    performanceDescending(15000, comp1,move1,comp2,move2,comp3,move3,duration1,duration2,duration3);
    cout << "Insertion Sort         " << duration1 << "      " << comp1 << "     " << move1 << endl;
    cout << "Merge Sort             " << duration2 << "       " << comp2 << "   " << move2 << endl;
    cout << "Quick Sort             " << duration3 << "       " << comp3 << "   " << move3 << endl;
    
    comp1 = 0; move1 = 0;comp2 = 0;move2 = 0;comp3 = 0;move3 = 0;duration1 = 0; duration2 = 0; duration3 = 0;
    
    //For 20000 elements
    cout << "----------------------------------------------------------" << endl;
    cout << "Array size: 20000  /   Elapsed Time   compCount   moveCount" << endl;
    performanceDescending(20000, comp1,move1,comp2,move2,comp3,move3,duration1,duration2,duration3);
    cout << "Insertion Sort         " << duration1 << "      " << comp1 << "     " << move1 << endl;
    cout << "Merge Sort             " << duration2 << "       " << comp2 << "   " << move2 << endl;
    cout << "Quick Sort             " << duration3 << "       " << comp3 << "   " << move3 << endl;
    
}


