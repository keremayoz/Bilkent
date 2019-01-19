#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <sys/syscall.h>
#include <sys/wait.h> 
#include <sys/types.h>
#include <sys/time.h>

//Global data structure
int **data;

//Min and max
double min_val;
double max_val;

// Bin count
int bin_count;

// Size
int n;

// File names
char **files;

// Bin width
double w;

// Thread function.
void *worker(void *arg) {

	// Get the index of thread in thread workers array created in main.
	int t_id = *((int *)arg);

	// Find the counts of numbers in each bin.
	FILE *fp;
	char buf[1000];
	fp =fopen(files[t_id],"r");
	
	while (1) {
    	int ret = fscanf(fp, "%s", buf);
        if(ret == 1) 
			data[t_id][(int)((atof(buf) - min_val) / w)] += 1;
        else if(ret == EOF)
            break;
	}

	fclose(fp);
	pthread_exit(0);
}

int main(int argc, char const *argv[]) {

	struct timeval t0;
	struct timeval t1;
  	gettimeofday(&t0, 0);
  	
	// Initialize the parameters.
	min_val = atoi(argv[1]);
	max_val = atoi(argv[2]);
	bin_count = atoi(argv[3]);
	n = atoi(argv[4]);
	w = ceil((max_val-min_val) / (bin_count*1.0));
    files = (char **)malloc(n * sizeof(char *)); 
    for (int i=0; i<n; i++) 
         files[i] = (char *)malloc(50 * sizeof(char)); 
	for (int i = 0; i < n; i++) {
		strcpy(files[i],argv[5+i]);
	}

	// Thread array to store the threads.
	pthread_t workers[n];
	
  	// Each row represents the bins and its counts for each thread, n rows for n threads, bin_count columns for each thread's bins
    data = (int **)malloc(n * sizeof(int *)); 
    for (int i=0; i<n; i++) 
         data[i] = (int *)malloc(bin_count * sizeof(int)); 

    // Used that array for passing index of the thread to the worker function
  	int indexes[n];

  	// Create the threads
	for(int i=0;i<n;i++)  {
		indexes[i] = i;
		(void) pthread_create(&workers[i], NULL, worker, &indexes[i]);
    } 
	
	// Wait for threads to be completed
	for (int i = 0; i < n; i++)
		(void) pthread_join(workers[i], NULL);

	// Parent's turn to generate output file from the global data array
	char outfile[50];
	strcpy(outfile, argv[n+5]);

	FILE *f = fopen(outfile, "w");
	if (f == NULL) {
	    printf("Error opening file!\n");
	    exit(1);
	}

	for (int i = 0; i < bin_count; ++i) {
		int total = 0;
		for (int j = 0; j < n; ++j) 
			total += data[j][i];
		fprintf(f, "%d:%d\n",i+1,total);
	}
	fclose(f);

	// Calculate the running time
	gettimeofday(&t1, 0);
	//double elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
	//printf("Time elapsed for multiprocess: %f seconds\n", elapsed/100000.0);
	return 0;
}