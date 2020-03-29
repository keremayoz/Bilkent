//
//  main.cpp
//  HW-2
//
//  Created by Kerem Ayöz on 24.04.2017.
//  Copyright © 2017 Kerem Ayöz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>


using namespace std;


int recursiveFib(int n){
    // Precondition: n is a positive integer
    // Postcondition: Returns the nth Fib. number
    
    if ( n <= 2 )
        return 1;
    else
        return recursiveFib(n-1) + recursiveFib(n-2);
}

int iterativeFib(int n){
    // Initialize base cases:
    int previous = 1; 		// initially fib(1)
    int current = 1;  		// initially fib(2)
    int next = 1;     		// result when n is 1 or 2
    
    // compute next Fibonacci values when n >= 3
    for (int i = 3; i <= n; ++i){
        // current is fib(i-1)
        // previous is fib(i-2)
        next = current + previous; // fib(i)
        
        previous = current; 	// get ready for the
        current = next;		// next iteration
    }
    return next;
}

int main() {
    
    double duration,c;
   
    //To give output to notepad file
    ofstream out;
    out.open("coutput.txt");
    //Algorithm 1: iterative solution
    if (out.is_open()) {
       for (int i = 1; i < 100000; i+=1) {
           std::chrono::time_point< std::chrono::system_clock > startTime;
           std::chrono::duration< double, milli > elapsedTime;
           //Store the starting time
           startTime = std::chrono::system_clock::now();
           c = iterativeFib(i);
           //Compute the number of seconds that passed since the starting time
           elapsedTime = std::chrono::system_clock::now() - startTime;
           out << elapsedTime.count() << endl;
       }
    }
    //Algorithm 2: recursive solution
    if (out.is_open()) {
        for (int i = 1; i < 55; i+=1) {
            std::chrono::time_point< std::chrono::system_clock > startTime;
            std::chrono::duration< double, milli > elapsedTime;
            //Store the starting time
            startTime = std::chrono::system_clock::now();
            c = recursiveFib(i);
            //Compute the number of seconds that passed since the starting time
            elapsedTime = std::chrono::system_clock::now() - startTime;
            out << elapsedTime.count() << endl;
        }
   }
    return 0;
}
