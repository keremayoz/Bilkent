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

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct node{
	double data;
 	struct node * next;
}Node;

void add(Node** head, double new_item) {
 	Node* new_node = (Node *)(malloc(sizeof(Node)));
	new_node->data = new_item;
	new_node->next = NULL;

	if ((*head) == NULL) {
		*head = new_node;
	}
		
	else {
		Node * cur = *head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new_node;
	}
}

double retrieve(Node** head) {
	Node * retrieved = *head;
	*head = (*head)->next;
	double num = retrieved->data;
	free(retrieved);
	return num;
}

void print_all(Node** head) {
	Node * cur = *head;
	while(cur != NULL) {
		printf("%f\n", cur->data);
		cur = cur->next;
	}
}

int size(Node **head) {
	int size = 0;
	Node *cur = *head;
	while (cur != NULL) {
		cur = cur->next;
		size++;
	}
	return size;
}

Node * head = NULL;
pthread_mutex_t mutex;
pthread_cond_t cond;

double min_val;
double max_val;
int bin_count;
int n;
double w;
int b;


int finished_count;
pthread_mutex_t mutex2;

void *worker(void *arg) {
	char *file_name = ((char *)arg);
	double send[b];
	for (int i = 0; i < b; i++)
		send[i] = 0;
	  
	FILE *file;
	file = fopen(file_name, "r");

    int count = 0;
    double num;

    while(fscanf(file,"%lf",&num)!=EOF){
		if (count == b) {
    		pthread_mutex_lock(&mutex);
    		for (int i = 0; i < count; i++) 
				add(&head, send[i]); 
			pthread_cond_signal (&cond);
    		pthread_mutex_unlock(&mutex);
    		
    		count = 0;
    	}
    	
    	send[count++] = num;
	}

	pthread_mutex_lock(&mutex);
	for (int i = 0; i < count; i++) 
		add(&head, send[i]);
	pthread_cond_signal (&cond);

	finished_count++;

	pthread_mutex_unlock(&mutex);
	fclose(file);
	pthread_exit(0);
}

int main(int argc, char *argv[]) {
  	
	min_val = atof(argv[1]);
	max_val = atof(argv[2]);
	bin_count = atoi(argv[3]);
	n = atoi(argv[4]);
	w = (max_val-min_val) / bin_count;
	b = atoi(argv[6+n]);

	finished_count = 0;
	pthread_cond_init(&cond,NULL);

	pthread_t workers[n];
  	int indexes[n];
  	pthread_mutex_init(&mutex, NULL);
  	int combined_bins[bin_count];
  	for (int i = 0; i < bin_count; i++)
  		combined_bins[i] = 0;
  	
	for(int i=0;i<n;i++)  {
		indexes[i] = i;
		char *file_name = argv[5+indexes[i]];
		(void) pthread_create(&workers[i], NULL, worker, file_name);
    }
  	  	
  	while (1) {
	  	
		pthread_mutex_lock(&mutex);
		
		if (finished_count == n && size(&head) == 0)
			break;
	
  		//while (size(&head) == 0)
    	//	pthread_cond_wait (&cond, &mutex);    	

		int retrieve_count = MIN(size(&head),b);
		for (int i = 0; i < retrieve_count;i++) {
			double num = retrieve(&head);
			if(num==max_val)
				++combined_bins[bin_count-1];
			
			int i,j;
			for(i=0,j=1; i<=bin_count-1 && j<=bin_count; i++,j++)
				if((num>=min_val+i*w) && (num<min_val+j*w))
					++combined_bins[i];
		}
		pthread_mutex_unlock(&mutex);
	
  	}

	for (int i = 0; i < n; i++) {
		(void) pthread_join(workers[i], NULL);
	}

	FILE *f = fopen(argv[n+5], "w");
	if (f == NULL) {
	    printf("Error opening file!\n");
	    exit(1);
	}

	for (int i = 0; i < bin_count; ++i)
		fprintf(f, "%d: %d\n",i+1,combined_bins[i]);


	fclose(f);

	pthread_mutex_destroy(&mutex);

	return 0;
}