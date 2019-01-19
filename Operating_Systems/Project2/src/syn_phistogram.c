#include <stdio.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <sys/syscall.h>
#include <sys/wait.h> 
#include <sys/types.h>
#include <sys/time.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h> 
#include <sys/ipc.h>
#include <semaphore.h>


double *shared_data;
sem_t *childwait;

void create_intermediate(const char *file_name, double min_val, double max_val, int bin_count) {

	double w = (max_val-min_val) / bin_count;
	int bins[bin_count];
	double num;

	for (int i = 0; i < bin_count; i++)
		bins[i] = 0;

	FILE *file;
	file = fopen(file_name, "r");
	
	if (file== NULL){
        printf("Error! file cannot be opened");
        exit(1);         
    }
    while(fscanf(file,"%lf",&num)!=EOF){
		if(num==max_val)
			++bins[bin_count-1];
		
		int i,j;
		for(i=0,j=1; i<=bin_count-1 && j<=bin_count; i++,j++)
			if((num>=min_val+i*w) && (num<min_val+j*w))
				++bins[i];

	}

	fclose(file);
    sem_wait(childwait);

	for (int i = 0; i < bin_count; i++)
		shared_data[i] = bins[i];

	exit(0);
}

int main(int argc, char const *argv[]) {

	double min_val = atof(argv[1]);
	double max_val = atof(argv[2]);

	int bin_count = atoi(argv[3]);
	
	int n = atoi(argv[4]);

	pid_t ids[n];

    int combined_bins[bin_count];
    for (int i = 0; i < bin_count; i++)
		combined_bins[i] = 0;

	const int SIZE = bin_count * sizeof(double); 

    double shm_fd; 
    void* ptr; 
    shm_fd = shm_open("shm", O_CREAT | O_RDWR, 0666); 
    ftruncate(shm_fd, SIZE); 
    ptr = (double *)mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0); 
  	shared_data = (double*)ptr;

  	childwait = sem_open("childwait", O_RDWR | O_CREAT, 0660, 1);

	for(int i=0;i<n;i++)  {
		ids[i] = fork();

		if (ids[i] == 0) 
			create_intermediate(argv[5+i], min_val, max_val, bin_count);
		
    }

    for(int i=0;i<n;i++)  {
		wait(NULL);
		for (int j = 0; j < bin_count; j++)
			combined_bins[j] += shared_data[j];
		sem_post(childwait); 

    }


	FILE *f = fopen(argv[n+5], "w");
	if (f == NULL) {
	    printf("Error opening file!\n");
	    exit(1);
	}

	for (int i = 0; i < bin_count; ++i) 
		fprintf(f, "%d: %d\n",i+1,combined_bins[i]);

	fclose(f);

	shm_unlink("shm");
	sem_destroy(childwait);  
	return 0;
	
}