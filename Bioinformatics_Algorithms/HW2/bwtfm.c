#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

char* concat(const char *s1, const char *s2) {
    char *resun = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(resun, s1);
    strcat(resun, s2);
    return resun;
}

char * readFastaString(char *fileName) {
    char * string = "";

	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
 
	fp = fopen(fileName, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
 
	int state = 0;
	while ((read = getline(&line, &len, fp)) != -1) {
		if (line[read - 1] == '\n')
			line[read - 1] = 0;
        	string = concat(string, line);
	}
	fclose(fp);
	if (line)
		free(line);
	return string;
}

typedef struct suffixElement {
    char *text;  
    int index; 
}suffix;  


int stringComparator(const void *a, const void *b ) {
	return strcmp((*(const suffix*)a).text, (*(const suffix*)b).text);
}

int characterComparator (const void * a, const void * b) {
	return (*(char*)a - *(char*)b);
}

int integerComparator( const void* a, const void* b) {
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     return int_a - int_b;
}

  
int* suffixArray(char *str, int size) { 
	suffix* allSuffixes = malloc(size * sizeof(suffix));

    for (int i = 0; i < size; i++) { 
        allSuffixes[i].index = i; 
        allSuffixes[i].text = str+i; 
    }

  	qsort(allSuffixes, size, sizeof(suffix), stringComparator);

    int* suffixArr = malloc(size * sizeof(int)); 
    for (int i = 0; i < size; i++) 
        suffixArr[i] = allSuffixes[i].index; 

    return  suffixArr; 
}

char* burrowsWheeler(char* str, int *sa, int size) {
	char* bwt = malloc(size * sizeof(char));
	for (int i = 0; i < size; i++)
		if (sa[i] == 0)
			bwt[i] = '$';
		else
			bwt[i] = str[sa[i]-1];
	return bwt;
}

int* rankTable(char* str, int size) {
	qsort(str, size, sizeof(char),characterComparator);
	int counts[4];
	for (int i = 0; i < 4; i++)
		counts[i] = 0;
	for (int i = 1; i < size; i++)
		counts[((str[i]/3)-1)%4]++;

	int* ranks = malloc(4*sizeof(int));
	ranks[0] = 1;					 // A
	ranks[1] = ranks[0] + counts[0]; // C
	ranks[2] = ranks[1] + counts[1]; // G
	ranks[3] = ranks[2] + counts[2]; // T

	return ranks;
}

int** occurenceTable(char* bwt, int size) {
    int** occurence = malloc(size*sizeof(int*));

    for (int i=0; i < size; i++) 
         occurence[i] = (int *)malloc(4 * sizeof(int)); 
  	
  	// Initialize first row
	for (int j = 0; j < 4; j++) 
		occurence[0][j] = 0;

	occurence[0][((bwt[0]/3)-1)%4]++;

	for (int i = 1; i < size; i++){
		memcpy(occurence[i], occurence[i-1], 4 * sizeof(int));
		if (bwt[i] != '$')
			occurence[i][((bwt[i]/3)-1)%4]++;
	}
	// Magical touch
	occurence[0][((bwt[0]/3)-1)%4]--;
	return occurence;
}

void bwtSearch(int* ranks, int** occurence, char* bwt, int* sa, char* P, int m, int n) {
	clock_t begin = clock();

	int bstart = 1;
	int bend = n-1;

	// Right to left from pattern
	for (int i = m-1; i >= 0; i--) {
		int ind = ((P[i]/3)-1)%4;
		bstart = ranks[ind] + occurence[bstart-1][ind];
		bend = ranks[ind] + occurence[bend][ind] - 1;
		if (bstart > bend) {
			printf("Pattern P is not found in T\n");
			return;
		}
	}
	int positions[bend-bstart+1];
	printf("Pattern P found in T %d times at positions:\n", bend-bstart+1);
	
	for (int i = 0; i <= bend-bstart; i++)
		positions[i] = sa[bstart+i];
	qsort(positions, bend-bstart+1, sizeof(int), integerComparator);
	for (int i = 0; i <= bend-bstart; i++)
		printf("pos %d:  %d\n",i+1, positions[i]);

	clock_t end = clock();
	printf("Search completed in %f seconds.\n", (float)(end - begin) / CLOCKS_PER_SEC);

}


void main(int argc, char **argv) {
    if (strcmp(argv[1],"--index") == 0) {
    	
    	// Read text
		char* T = readFastaString("test.fa");
		int n = strlen(T);

		// Concat $
		char* dollar = "$";
		int size = n+1;
		char* T$ = concat(T, dollar);

    	int* sa = suffixArray(T$, size);
	  	char* bwt = burrowsWheeler(T$, sa, size);
	  	int* ranks = rankTable(T$,size);
	  	int** occurence = occurenceTable(bwt, size);

	  	// Write
	  	FILE *f = fopen(concat(argv[2],".bwt"), "wb");
		fwrite(bwt, 1, sizeof(char)*size, f);
		fclose(f);

		f = fopen(concat(argv[2],".fm"), "w");
		fwrite(sa, 1, sizeof(int)*size, f);
		fwrite(ranks, 1, sizeof(int)*4, f);
		for (int i = 0; i < size; i++)
			fwrite(occurence[i], 1, sizeof(int)*4, f);
		fclose(f);

    }
    else if (strcmp(argv[1],"--search") == 0) {
    	
    	// Read pattern
		char* P = readFastaString(argv[4]);
		int m = strlen(P);

		// Read
	  	char* bwt = readFastaString(concat(argv[2],".bwt"));
	  	int n = strlen(bwt);

		int* sa = malloc(sizeof(int)*n);
	  	int* ranks = malloc(sizeof(int)*4);
    	int** occurence = malloc(n*sizeof(int*));
    	for (int i=0; i < n; i++) 
        	occurence[i] = (int *)malloc(4 * sizeof(int)); 

		FILE* f = fopen(concat(argv[2],".fm"), "r");
		fread(sa, 1, sizeof(int)*n, f);
		fread(ranks, 1, sizeof(int)*4, f);
		for (int i = 0; i < n; i++)
			fread(occurence[i], 1, sizeof(int)*4, f);
		fclose(f);

		// Search
  		bwtSearch(ranks,occurence,bwt,sa, P, m, n);
    }
}