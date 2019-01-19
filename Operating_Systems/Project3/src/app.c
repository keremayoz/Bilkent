#include<stdio.h>
#include<stdlib.h>

#include <time.h> 
 
int *heap_arr;


void delay(int number_of_seconds)  { 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
} 

int fibonacci(int n) {
  if (n == 0 || n == 1)
    return n;
  else {
    int f1 = fibonacci(n-1);
    int f2 = fibonacci(n-2);
    return f1 + f2;
  }
}


int main() {

// Observe Heap Size 
  while(1) {
   	printf("Allocating!\n");
   	heap_arr = malloc(sizeof(int)*12800);
   	delay(7000); 
   	printf("De-allocating!\n");
   	//free(heap_arr);
   	delay(7000); 
   }
/*
   // Observe Stack Size
	int i = 0;
	int total = 0;
	for (i = 1; i <= 100; i++) {
		total += fibonacci(10*i);
		printf("Total: %d\n", total);
	}
*/
   return 0;
}