#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>

// Comparison functions to sort array when its needed
int asc (const void * item1, const void * item2)  {
    int f = *((int*)item1);
    int s = *((int*)item2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int desc (const void * item1, const void * item2)  {
    int f = *((int*)item1);
    int s = *((int*)item2);
    if (f > s) return  -1;
    if (f < s) return 1;
    return 0;
}

int remove_all(int arr[], int *size, int element) {
	int i = 0;
	for (i = 0; i < *size; i++) {
		if (arr[i] == element) {
			int j;
			for (j = i; j < *size; j++)
				arr[j] = arr[j+1];
			(*size)--;
		}
			
	}
	return *size;
}

int* remove_duplicates(int arr[], int *size) {
	int i,j,k;
	for(i=0;i<(*size);++i) {
		for(j=i+1;j<(*size);) {
			
			if(arr[i]==arr[j]) {
				for(k=j;k<(*size)-1;++k)
					arr[k]=arr[k+1];
				--(*size);
			}
			else
				++j;
		}
	}
	return arr;
}

// Global Variables
int requests[1000];
int size = 1000;
int i;
const int min_pos = 0;
const int max_pos = 4999;

void generate_random_input() {
	srand(time(NULL));
	for(i=0; i<size; i++){
		requests[i] = rand() % 5000;
	}
}

int fcfs(int requests[], int head_pos) {
	int disk_movement = 0;
	int temp_size = size;
	int *req = remove_duplicates(requests, &temp_size);
	for (i = 0; i < temp_size; i++) {
		disk_movement += abs(req[i] - head_pos);
		head_pos = req[i]; 
	}
	return disk_movement;
}

int sstf(int requests[], int head_pos) {
	int disk_movement = 0;
	int temp_size = size;
	while (temp_size > 0) {
		int min_dist = INT_MAX;
		int closest_i = -1;
		for (i = 0; i < temp_size; i++) {
			if (abs(head_pos-requests[i]) < min_dist) {
				min_dist = abs(head_pos-requests[i]);
				closest_i = i;
			}
		}
		disk_movement += abs(requests[closest_i] - head_pos);
		head_pos = requests[closest_i]; 
		remove_all(requests, &temp_size, requests[closest_i]);
	}
	
	return disk_movement;
}

int scan(int requests[], int head_pos) {
	int disk_movement = 0;
	qsort (requests, size, sizeof(int), asc);
	int s = size;
	for(i = 0; i < size; i++) {
		if (head_pos <= requests[i]) {
			s = i;
			break;
		}
	}
	int small[s];
	int large[size-s];
	for (i = 0; i < s; i++) 
		small[i] = requests[s-i-1];
	for (i = 0; i < size-s; i++) 
		large[i] = requests[s+i];
	
	qsort (small, s, sizeof(int), desc);
	qsort (large, size-s, sizeof(int), asc);

	for (i = 0; i < size-s; i++) {
		disk_movement += abs(large[i] - head_pos);
		head_pos = large[i]; 
	}

	disk_movement += abs(max_pos-head_pos);
	head_pos = max_pos;

	for (i = 0; i < s; i++) {
		disk_movement += abs(small[i] - head_pos);
		head_pos = small[i]; 
	}

	return disk_movement;
}

int c_scan(int requests[], int head_pos) {
	int disk_movement = 0;
	
	qsort (requests, size, sizeof(int), asc);
	int s = size;
	for(i = 0; i < size; i++) {
		if (head_pos <= requests[i]) {
			s = i;
			break;
		}
	}
	int small[s];
	int large[size-s];
	for (i = 0; i < s; i++) 
		small[i] = requests[s-i-1];
	for (i = 0; i < size-s; i++) 
		large[i] = requests[s+i];
	
	qsort (small, s, sizeof(int), asc);
	qsort (large, size-s, sizeof(int), asc);

	for (i = 0; i < size-s; i++) {
		disk_movement += abs(large[i] - head_pos);
		head_pos = large[i]; 
	}

	disk_movement += abs(max_pos-head_pos);
	head_pos = max_pos;

	disk_movement += abs(min_pos-head_pos);
	head_pos = min_pos;

	for (i = 0; i < s; i++) {
		disk_movement += abs(small[i] - head_pos);
		head_pos = small[i]; 
	}

	return disk_movement;
}

int look(int requests[], int head_pos) {
	int disk_movement = 0;

	qsort (requests, size, sizeof(int), asc);
	int s = size;
	for(i = 0; i < size; i++) {
		if (head_pos <= requests[i]) {
			s = i;
			break;
		}
	}
	int small[s];
	int large[size-s];
	for (i = 0; i < s; i++) 
		small[i] = requests[s-i-1];
	for (i = 0; i < size-s; i++) 
		large[i] = requests[s+i];
	
	qsort (small, s, sizeof(int), desc);
	qsort (large, size-s, sizeof(int), asc);

	for (i = 0; i < size-s; i++) {
		disk_movement += abs(large[i] - head_pos);
		head_pos = large[i]; 
	}

	for (i = 0; i < s; i++) {
		disk_movement += abs(small[i] - head_pos);
		head_pos = small[i]; 
	}

	return disk_movement;
}

int c_look(int requests[], int head_pos) {
	int disk_movement = 0;
	qsort (requests, size, sizeof(int), asc);
	int s = size;
	for(i = 0; i < size; i++) {
		if (head_pos <= requests[i]) {
			s = i;
			break;
		}
	}
	int small[s];
	int large[size-s];
	for (i = 0; i < s; i++) 
		small[i] = requests[s-i-1];
	for (i = 0; i < size-s; i++) 
		large[i] = requests[s+i];
	
	qsort (small, s, sizeof(int), asc);
	qsort (large, size-s, sizeof(int), asc);

	for (i = 0; i < size-s; i++) {
		disk_movement += abs(large[i] - head_pos);
		head_pos = large[i]; 
	}

	for (i = 0; i < s; i++) {
		disk_movement += abs(small[i] - head_pos);
		head_pos = small[i]; 
	}

	return disk_movement;
}

void test() {
	int fcfs_data[100];
	int sstf_data[100];
	int scan_data[100];
	int cscan_data[100];
	int look_data[100];
	int clook_data[100];

	int k = 0;
	for (k=0; k<100; k++) {
		generate_random_input();
		int head_pos = rand() % 5000;

		fcfs_data[k] = fcfs(requests, head_pos);
	    scan_data[k] =  scan(requests, head_pos);
	 	cscan_data[k] = c_scan(requests, head_pos);
	    look_data[k] = look(requests, head_pos);
	    clook_data[k] = c_look(requests, head_pos);
	    sstf_data[k] = sstf(requests, head_pos);
	}

	float sum1 = 0.0;
    float sum2 = 0.0;
    float sum3 = 0.0;
    float sum4 = 0.0;
    float sum5 = 0.0;
    float sum6 = 0.0;
    
	float std1 = 0.0;
    float std2 = 0.0;
    float std3 = 0.0;
    float std4 = 0.0;
    float std5 = 0.0;
    float std6 = 0.0;

    for(i=0; i<100; ++i)
    {
        sum1 += fcfs_data[i];
        sum2 += scan_data[i];
        sum3 += cscan_data[i];
        sum4 += look_data[i];
        sum5 += clook_data[i];
        sum6 += sstf_data[i];

    }

    for(i=0; i<100; ++i)
    {
        std1 += pow(fcfs_data[i] - (sum1/100), 2);
        std2 += pow(scan_data[i] - (sum2/100), 2);
        std3 += pow(cscan_data[i] - (sum3/100), 2);
        std4 += pow(look_data[i] - (sum4/100), 2);
        std5 += pow(clook_data[i] - (sum5/100), 2);
        std6 += pow(sstf_data[i] - (sum6/100), 2);

    }

	printf("Mean fcfs: %f\n", sum1/100);
	printf("Mean sstf: %f\n", sum2/100);
	printf("Mean scan: %f\n", sum3/100);
	printf("Mean c_scan: %f\n", sum4/100);
	printf("Mean look: %f\n", sum5/100);
	printf("Mean c_look: %f\n", sum6/100);
	printf("\n");
	printf("Std fcfs: %f\n", sqrt(std1/100));
	printf("Std sstf: %f\n", sqrt(std6/100));
	printf("Std scan: %f\n", sqrt(std2/100));
	printf("Std c_scan: %f\n", sqrt(std3/100));
	printf("Std look: %f\n", sqrt(std4/100));
	printf("Std c_look: %f\n", sqrt(std5/100));
}

int main(int argc, char const *argv[]) {
	
	// Read parameters
	const int head_pos = atoi(argv[1]);

	if (argv[2]) {
		const char *input_file = argv[2];

	    FILE *file;
		file = fopen(input_file, "r");
		int n1, n2;
		if (file== NULL){
	        printf("Error! file cannot be opened");
	        exit(1);         
	    }
	    while(fscanf(file,"%d %d",&n1,&n2)!=EOF){
			requests[i++] = n2;
		}
    	fclose(file);
	}
	else {
		generate_random_input();
	}

	int fcfs_c = fcfs(requests, head_pos);
    int scan_c=  scan(requests, head_pos);
 	int c_scan_c = c_scan(requests, head_pos);
    int look_c = look(requests, head_pos);
    int c_look_c = c_look(requests, head_pos);
    int sstf_c = sstf(requests, head_pos);

   
    // Print the results of algorithms
    printf("FCFS: %d\n", fcfs_c);
    printf("SSTF: %d\n", sstf_c);
    printf("SCAN: %d\n", scan_c);
 	printf("C-SCAN: %d\n", c_scan_c);
    printf("LOOK: %d\n", look_c);
    printf("C-LOOK: %d\n", c_look_c);
	
	//test();
    // Exit
	return 0;
}
